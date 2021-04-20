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

    template <class T, class U = T>
    bool Modify(T& obj, U&& new_value) {
        if (obj == new_value)
            return false;
        obj = std::forward<T>(new_value);
        return true;
    }

   template <class Collection, class T>
    void RemoveAll(Collection& c, const T& value) {
        c.erase(std::remove(c.begin(), c.end(), value), c.end());
    }

    template <class Collection, class Pred>
    void RemoveAllIf(Collection& c, Pred&& predicate) {
        c.erase(std::remove_if(c.begin(), c.end(), std::forward<Pred>(predicate)),
                    c.end());
    }

        template <class Collection, class T>
    auto Find(Collection& c, const T& value) {
        return std::find(c.begin(), c.end(), value);
    }

    template <class Collection, class Pred>
    auto FindIf(Collection& c, Pred&& predicate) {
        return std::find_if(c.begin(), c.end(), std::forward<Pred>(predicate));
    }

    template <class Collection, class T>
    bool Contains(const Collection& c, const T& value) {
        if (std::find(c.begin(), c.end(), value) != c.end())
            return true;
        return false;
    }

    template <class Collection, class Pred>
    bool ContainsIf(const Collection& c, Pred&& predicate) {
        if (std::find_if(c.begin(), c.end(), std::forward<Pred>(predicate)) != c.end())
            return true;
        return false;
    }

    template <class Collection, class Pred>
    int CountIf(const Collection& c, Pred&& predicate) {
        return std::count_if(c.begin(), c.end(), std::forward<Pred>(predicate));
    }

    template <class Collection, class Comp>
    void Sort(Collection& c, Comp&& comparator) {
        std::sort(c.begin(), c.end(), std::forward<Comp>(comparator));
    }

    template <class Collection>
    void Sort(Collection& c) {
        std::sort(c.begin(), c.end());
    }

    template <class Collection>
    void Unique(Collection& c) {
        c.erase(std::unique(c.begin(), c.end()), c.end());
    }

    template <class Collection, class Pred>
    void Unique(Collection& c, Pred&& predicate) {
        c.erase(std::unique(c.begin(), c.end(), std::forward<Pred>(predicate)),
                   c.end());
    }

        template <class Collection, class Pred>
    void ForEach(Collection& c, Pred&& predicate) {
        std::for_each(c.begin(), c.end(), std::forward<Pred>(predicate));
    }

    template <class Collection, class T>
    int IndexOf(const Collection& c, const T& value) {
        auto it = Find(c, value);

        if (it != c.end()) {
            return std::distance(c.begin(), it);
        }
        return -1;
    }

    template <class Collection, class Pred>
    int IndexOfIf(const Collection& c, Pred&& predicate) {
        auto it = FindIf(c, predicate);
        if (it != c.end()) {
            return std::distance(c.begin(), it);
        }
        return -1;
    }
}

