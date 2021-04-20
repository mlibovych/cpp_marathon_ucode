#include "Log.h"
#include "LoggerWorker.h"

Log Log::createLog(LogLevel level) {
    return Log(level);
}

Log::Log(LogLevel level) : m_logLevel(level) {}

Log::~Log() {
    LoggerWorker::getLogger().log(m_logLevel, m_inputStream.str());
}