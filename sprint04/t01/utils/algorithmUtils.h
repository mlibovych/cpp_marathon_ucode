#pragma once

#include <utility>
#include <algorithm>

namespace Utils
{
    template <typename T>
    bool IsInRange(const T& val, const T& from, const T& to) {
        if (val >= from && val <= to)
            return true;
        return false;
    }

    template <typename T>
    bool IsInRange(const T& val, const std::pair<const T&, const T&>& minmax) {
        if (val >= minmax.first && val <= minmax.second)
            return true;
        return false;
    }

    template <typename T>
    bool IsInsideRange(const T& val, const T& from, const T& to) {
        if (val > from && val < to)
            return true;
        return false;
    }

    template <typename T>
    bool IsInsideRange(const T& val, const std::pair<const T&, const T&>& minmax) {
        if (val > minmax.first && val < minmax.second)
            return true;
        return false;
    }

    template <class T>
    const auto& Min(const T& arg1) {
        return arg1;
    }

    template <class T>
    const auto& Min(const T& arg1, const T& arg2) {
        return std::min(arg1, arg2);
    }

    template <class T, class...Args>
    const auto& Min(const T& arg, const Args&... args) {
        return std::min(arg, Min(args...));
    }

    template <class T>
    const auto& Max(const T& arg1) {
        return arg1;
    }

    template <class T>
    const auto& Max(const T& arg1, const T& arg2) {
        return std::max(arg1, arg2);
    }

    template <class T, class...Args>
    const auto& Max(const T& arg, const Args&... args) {
        return std::max(arg, Max(args...));
    }

    template <class Collection>
    auto MaxElement(const Collection& c) {
        return std::max_element(c.begin(), c.end());
    }

    template <class Collection>
    auto MinElement(const Collection& c) {
        return std::min_element(c.begin(), c.end());
    }

    template <class Collection, class Comp>
    auto MaxElement(const Collection& c, Comp&& comparator) {
        return std::max_element(c.begin(), c.end(), std::forward<Comp>(comparator));
    }

    template <class Collection, class Comp>
    auto MinElement(const Collection& c, Comp&& comparator) {
        return std::min_element(c.begin(), c.end(), std::forward<Comp>(comparator));
    }
}
