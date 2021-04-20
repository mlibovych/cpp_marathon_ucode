#include "Worker.h"

Worker::~Worker() {
    joinAllThreads();
}

void Worker::joinAllThreads() {
    for (auto& t : m_workerThreads) {
        if (t.joinable()) {
            t.join();
        }
    }
}
