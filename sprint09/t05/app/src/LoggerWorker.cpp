#include "LoggerWorker.h"

LoggerWorker::~LoggerWorker() {
    stop();
    m_condVar.notify_one();
    join();
    m_logFileStream.close();
}

LoggerWorker& LoggerWorker::getLogger() {
    if (!m_logger) {
        m_logger =  std::shared_ptr<LoggerWorker>(new LoggerWorker);
    }
    return *m_logger;
}

void LoggerWorker::log(Log::LogLevel level, const std::string& logMessage) {
    std::unique_lock<std::mutex> lock(m_runMutex);
    
    m_logQueue.push({logMessage, level});
    m_condVar.notify_one();
}

LoggerWorker::LoggerWorker() {
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    std::string fileName = std::to_string(aTime->tm_mday) + "_" + std::to_string(aTime->tm_mon + 1) + "_" +
        std::to_string(aTime->tm_year + 1900) + "T" + std::to_string(aTime->tm_hour) + "_" +
        std::to_string(aTime->tm_min) + "_" + std::to_string(aTime->tm_sec) + ".txt";

    m_logFileStream = std::ofstream(fileName);
    start();
}

void LoggerWorker::run() {
    while (true) {
        std::unique_lock<std::mutex> lock(m_runMutex);

        m_condVar.wait(lock, [this]() {
            return !this->isRunning() || !this->m_logQueue.empty();
            }
        );

        if (!isRunning() || m_logQueue.empty()) {
            return;
        }

        auto el = m_logQueue.front();
        time_t theTime = time(NULL);
        struct tm *aTime = localtime(&theTime);
        std::string data = "[" + std::to_string(aTime->tm_mday) + ":" + std::to_string(aTime->tm_mon + 1) + ":" +
            std::to_string(aTime->tm_year + 1900) + "T" + std::to_string(aTime->tm_hour) + ":" +
            std::to_string(aTime->tm_min) + ":" + std::to_string(aTime->tm_sec) + "] [";
        switch (el.logLevel) {
            case Log::LogLevel::Debug:
                data += "Debug";
                break;
            case Log::LogLevel::Info:
                data += "Info";
                break;
            case Log::LogLevel::Warning:
                data += "Warning";
                break;
            default:
                break;
        }
        data += "] " + el.message;
        m_logFileStream << data << std::endl;
        m_logQueue.pop();
    }
}