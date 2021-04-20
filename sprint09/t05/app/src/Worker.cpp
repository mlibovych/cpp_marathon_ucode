#include "Worker.h"

void Worker::start() {
    if (!isRunning()) {
        m_isRunning = true;
        m_worker = std::thread(&Worker::run, this);
    }
}

void Worker::stop() {
    m_isRunning = false;
}

void Worker::join() {
    if (m_worker.joinable()) {
        m_worker.join();
    }
}

bool Worker::isRunning() const {
    return m_isRunning;
}
 