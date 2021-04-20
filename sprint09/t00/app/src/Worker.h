/* template for app/src/Worker.h */
#pragma once
#include <utility>
#include <thread>

class Worker {
public:
	Worker() = default;
	Worker(const Worker& other) = delete;
	Worker(Worker&& other) = delete;
	~Worker();

	template <typename Function, class... Args>
	void startWorker(Function&& func, Args&&... args);

void joinThread();

private:
   	std::thread* m_thread{nullptr};
};

template <typename Function, class... Args>
void Worker::startWorker(Function&& func, Args&&... args) {
	joinThread();
	m_thread = new std::thread(func, std::forward<Args>(args)...);
}

// You can add more content, but DON'T remove/edit
