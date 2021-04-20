#include "ThreadPool.h"

ThreadPool::ThreadPool(size_t threads) {
    for (size_t i = 0; i < threads; i++) {
        m_workerThreads.emplace_back(std::thread(&ThreadPool::run, this));
    }
}

ThreadPool::~ThreadPool() {
    m_isRunning = false;
    m_condVar.notify_all();
    for (decltype(auto) thread : m_workerThreads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
}

void ThreadPool::run() {
    std::packaged_task<void()> task;

    while(true) {
        std::unique_lock<std::mutex> lock(m_queueMutex);

        m_condVar.wait(lock, [this]() {
            return !m_isRunning || !m_taskQueue.empty();
        });
        if (!m_isRunning && m_taskQueue.empty()) {
            return;
        }
        task = std::move(m_taskQueue.front());
        m_taskQueue.pop();
        task();
    }
}
