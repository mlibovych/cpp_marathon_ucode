#pragma once

#include "CBLBasicString.h"

namespace CBL {
class WString : public BasicString<wchar_t> {
public:
    using BasicString<wchar_t>::BasicString;
    using BasicString<wchar_t>::operator=;
    using BasicString<wchar_t>::operator+=;
    using BasicString<wchar_t>::operator[];

    WString(const wchar_t* str) : BasicString(str) {

    }

    size_t find(const WString& str, size_t pos = 0) const {
        if (pos >= m_size || pos + str.m_size > m_size)
            return CBL::BasicString<wchar_t>::npos;
        auto iter = std::search(begin() + pos, end(), str.m_buffer, str.m_buffer + str.m_size);
        if (iter == end()) {
            return CBL::BasicString<wchar_t>::npos;
        }
        return iter - begin();
    }

    size_t find(const wchar_t* str, size_t pos = 0) const {
        WString new_string(str);
        return find(new_string, pos);
    }

    size_t find(wchar_t c, size_t pos = 0) const {
        WString new_str(1, c);
        return find(new_str, pos);
    }

    size_t rfind(const WString& str, size_t pos = 0) const {
        auto it = pos > m_size ? end() - str.m_size : begin() + pos;
        for (auto temp = begin() - 1; it != temp; --it) {
            if (std::char_traits<wchar_t>::compare(str.c_str(), it, str.length()) == 0) {
                return std::distance(begin(), it);
            }
        }
        return CBL::BasicString<wchar_t>::npos;
    }

    size_t rfind(const wchar_t* str, size_t pos = 0) const {
        WString new_string(str);
        return rfind(new_string, pos);
    }

    size_t rfind(wchar_t c, size_t pos = 0) const {
        WString new_str(1, c);
        return rfind(new_str, pos);
    }
};
} // end namespace CBL

std::wostream& operator<<(std::wostream& os, CBL::WString& str) {
    for (size_t i = 0; i < str.length(); i++) {
        os << str[i];
    }
    return os;
}

// bool operator==(const CBL::WString& lhs, const CBL::WString& rhs) {
//     if (lhs.length() != rhs.length()) {
//         return false;
//     }
//     return std::equal(lhs.begin() + 4, lhs.end() + 4, rhs.begin(), rhs.end());
//     return 1;
// }

// template <class T>
// bool operator==(const T* lhs, const CBL::WString& rhs) {
//     return operator==(CBL::WString{lhs}, rhs);
// }

// template <class T>
// bool operator==(const CBL::WString& lhs, const T* rhs) {
//     return operator==(lhs, CBL::WString{rhs});
// }
