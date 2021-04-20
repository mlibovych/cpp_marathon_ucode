/* template for app/src/Worker.h */
#pragma once

#include <thread>
#include <vector>
#include <utility>

class Worker {
public:
	Worker() = default;
	Worker(const Worker& other) = delete;
	Worker(Worker&& other) = delete;
	~Worker();

	template <typename Function, class... Args>
	void startNewThread(Function&& func, Args&&... args);

	void joinAllThreads();

private:
   	std::vector<std::thread> m_workerThreads;
};

template <typename Function, class... Args>
void Worker::startNewThread(Function&& func, Args&&... args) {
	m_workerThreads.emplace_back(func, std::forward<Args>(args)...);
}

// You can add more content, but DON'T remove/edit
