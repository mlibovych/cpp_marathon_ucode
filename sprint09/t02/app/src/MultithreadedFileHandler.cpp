#include <iostream>
#include <fstream>

#include "MultithreadedFileHandler.h"

void MultithreadedFileHandler::processFile() {
    std::unique_lock<std::mutex> locker(m_mutex);
    
    m_condVar.wait(locker, [this]() {
            return this->m_fileLoaded;
        }
    );
    std::cout << m_file << std::endl;
    m_fileLoaded = false;
}

void MultithreadedFileHandler::loadFile(const std::string& fileName) {
    std::unique_lock<std::mutex> locker(m_mutex);
    std::ifstream in(fileName);
    std::string line;

    if (in.is_open()) {
        m_file = "";
        while (std::getline(in, line)) {
            m_file += line + "\n";
        }
        m_fileLoaded = true;
        m_condVar.notify_one();
    }
}


