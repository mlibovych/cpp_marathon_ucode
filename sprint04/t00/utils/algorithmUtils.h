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
}
