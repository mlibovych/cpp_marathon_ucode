#pragma once

#include <thread>
#include <vector>
#include <utility>
#include <future>


class AsyncWorker {
public:
    AsyncWorker() = default;
    AsyncWorker(const AsyncWorker& other) = delete;
	AsyncWorker(AsyncWorker&& other) = delete;
    ~AsyncWorker() = default;

    template <typename Function, class... Args>
    auto startAsync(Function&& func, Args&&... args);
};

template <typename Function, class... Args>
auto AsyncWorker::startAsync(Function&& func, Args&&... args) {
    auto res = std::async(func, std::forward<Args>(args)...);

    return res;
}