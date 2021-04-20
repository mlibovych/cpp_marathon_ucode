#pragma once

#include "CBLBasicString.h"

namespace CBL {
class String : public BasicString<char> {
public:
    using BasicString<char>::BasicString;
    using BasicString<char>::operator=;
    using BasicString<char>::operator+=;
    using BasicString<char>::operator[];

    
    String(const char* str) : BasicString(str) {

    }

    size_t find(const String& str, size_t pos = 0) const {
        if (pos >= m_size || pos + str.m_size > m_size)
            return CBL::BasicString<char>::npos;
        auto iter = std::search(begin() + pos, end(), str.m_buffer, str.m_buffer + str.m_size);
        if (iter == end()) {
            return CBL::BasicString<char>::npos;
        }
        return iter - begin();
    }

    size_t find(const char* str, size_t pos = 0) const {
        String new_string(str);
        return find(new_string, pos);
    }

    size_t find(char c, size_t pos = 0) const {
        String new_str(1, c);
        return find(new_str, pos);
    }

    size_t rfind(const String& str, size_t pos = 0) const {
        auto it = pos > m_size ? end() - str.m_size : begin() + pos;
        for (auto temp = begin() - 1; it != temp; --it) {
            if (std::char_traits<char>::compare(str.c_str(), it, str.length()) == 0) {
                return std::distance(begin(), it);
            }
        }
        return CBL::BasicString<char>::npos;
    }

    size_t rfind(const char* str, size_t pos = 0) const {
        String new_string(str);
        return rfind(new_string, pos);
    }

    size_t rfind(char c, size_t pos = 0) const {
        String new_str(1, c);
        return rfind(new_str, pos);
    }
};
} // end namespace CBL
