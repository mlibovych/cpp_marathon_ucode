#include "Worker.h"

Worker::~Worker() {
    joinThread();
}

void Worker::joinThread() {
    if (m_thread) {
        m_thread->join();
        delete m_thread;
        m_thread = nullptr;
    } 
}
