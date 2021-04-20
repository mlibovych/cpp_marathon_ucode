#pragma once

#include <iostream>
#include <initializer_list>
#include <tuple>
#include <utility>

namespace CBL {
template <class T>
class BasicString {
public:
    using iterator = T*;
    static const size_t npos = -1ul;

    BasicString();
    BasicString(const BasicString<T>& str);
    BasicString(const BasicString<T>& str, size_t pos, size_t len = npos);
    explicit BasicString(const T* str);
    BasicString(const T* str, size_t n);
    BasicString(size_t n, T c);
    BasicString(iterator first, iterator last);
    virtual~BasicString();
    // iterators
    iterator begin() const;
    iterator end() const;
    // capacity
    size_t length() const;
    // element access
    T& operator[](size_t index) const;
    T& at(size_t index) const;
    T& back() const;
    T& front() const;
    // modifiers
    BasicString<T>& operator=(const BasicString<T>& str);
    BasicString<T>& operator=(const T* str);
    BasicString<T>& operator=(const T c);
    BasicString<T>& operator+=(const BasicString<T>& str);
    BasicString<T>& operator+=(const T* str);
    BasicString<T>& operator+=(const T c);
    void append(const BasicString<T>& str);
    void append(const T* str);
    void append(const T* str, size_t n);
    void append(size_t n, T c);
    void append(iterator first, iterator last);
    void swap(BasicString<T>& str);
    // string operations
    const T* c_str() const;
    virtual int compare(const BasicString<T>& str) const;
    virtual int compare(const T* str) const;
protected:
    size_t m_size{0};
    T* m_buffer{nullptr};
};

template <class T>
BasicString<T>::BasicString() {
    m_buffer = new T[1];
    m_buffer[0] = '\0';
};

template <class T>
BasicString<T>::BasicString(const BasicString<T>& str) {
    m_size = str.m_size;
    m_buffer = new T[m_size + 1];
    std::copy(str.begin(), str.end(), m_buffer);
    m_buffer[m_size] = '\0';
};

template <class T>
BasicString<T>::BasicString(const BasicString<T>& str, size_t pos, size_t len) {
    if (pos >= str.length()) {
        throw std::out_of_range("BasicString");
    }
    m_size = len != npos ? std::min(str.m_size - pos, len) : str.m_size - pos;
    m_buffer = new T[m_size + 1];
    std::copy(str.m_buffer + pos, str.m_buffer + m_size + pos, m_buffer);
    m_buffer[m_size] = '\0';
};

template <class T>
BasicString<T>::BasicString(const T* str) {
    m_size = std::char_traits<T>::length(str);
    m_buffer = new T[m_size + 1];
    std::copy(str, str + m_size, m_buffer);
    m_buffer[m_size] = '\0';
};

template <class T>
BasicString<T>::BasicString(const T* str, size_t n) {
    m_size = n;
    m_buffer = new T[m_size + 1];
    std::copy(str, str + m_size, m_buffer);
    m_buffer[m_size] = '\0';
};

template <class T>
BasicString<T>::BasicString(size_t n, T c) {
    m_size = n;
    m_buffer = new T[m_size + 1];
    std::fill(begin(), end(),c);
    m_buffer[m_size] = '\0';
}
template <class T>
BasicString<T>::BasicString(iterator first, iterator last) {
    m_size = last - first;
    m_buffer = new T[m_size + 1];
    std::copy(first, last, m_buffer);
    m_buffer[m_size] = '\0';
}

template <typename T>
BasicString<T>::~BasicString() {
    delete[] m_buffer;
}

// iterators

template <typename T>
typename BasicString<T>::iterator BasicString<T>::begin() const {
    return m_buffer;
}

template <typename T>
typename BasicString<T>::iterator BasicString<T>::end() const {
    return m_buffer + m_size;
}

// capacity

template <typename T>
size_t BasicString<T>::length() const {
    return m_size;
};

// element access

template <typename T>
T& BasicString<T>::operator[](size_t index) const {
    return m_buffer[index];
}

template <typename T>
T& BasicString<T>::at(size_t index) const {
    if (index > m_size) {
        throw std::out_of_range("BasicString");
    }
    return m_buffer[index];
}

template <typename T>
T& BasicString<T>::back() const {
    return m_buffer[m_size - 1];
}

template <typename T>
T& BasicString<T>::front() const {
    return m_buffer[0];
}

// modifiers

template <typename T>
BasicString<T>& BasicString<T>::operator=(const BasicString<T>& str) {
    m_size = str.length();
    std::copy(str.begin(), str.end(), begin());
    m_buffer[m_size] = '\0';
    return *this;
}

template <typename T>
BasicString<T>& BasicString<T>::operator=(const T* str) {
    return operator=(BasicString<T>(str));
}

template <typename T>
BasicString<T>& BasicString<T>::operator=(const T c) {
    return operator=(BasicString<T>(1, c));
}

template <typename T>
BasicString<T>& BasicString<T>::operator+=(const BasicString<T>& str) {
    std::copy(str.begin(), str.end(), end());
    m_size += str.length();
    m_buffer[m_size] = '\0';
    return *this;
}

template <typename T>
BasicString<T>& BasicString<T>::operator+=(const T* str) {
    return operator+=(BasicString<T>(str));
}

template <typename T>
BasicString<T>& BasicString<T>::operator+=(const T c) {
    return operator+=(BasicString<T>(1, c));
}

template <typename T>
void BasicString<T>::append(const BasicString<T>& str) {
    T* new_string = new T[m_size + str.length() + 1];
    new_string[m_size + str.m_size] = '\0';
    std::copy(begin(), end(), new_string);
    std::copy(str.begin(), str.end(), new_string + m_size);
    m_size += str.length();
    delete[] m_buffer;
    m_buffer = new_string;
}

template <typename T>
void BasicString<T>::append(const T* str) {
    append(BasicString<T>{str});
}

template <typename T>
void BasicString<T>::append(const T* str, size_t n) {
    append(BasicString<T>{str, n});
}

template <typename T>
void BasicString<T>::append(size_t n, T c) {
    append(BasicString<T>{n, c});
}

template <typename T>
void BasicString<T>::append(iterator first, iterator last) {
    append(BasicString<T>{first, last});
}

template <typename T>
void BasicString<T>::swap(BasicString<T>& str) {
    std::swap(this->m_size, str.m_size);
    std::swap(this->m_buffer, str.m_buffer);
}

// string operations

template <typename T>
const T* BasicString<T>::c_str() const {
    return m_buffer;
}

template <typename T>
int BasicString<T>::compare(const BasicString<T>& str) const {
    size_t lhs = m_size;
    size_t rhs = str.m_size;
    int result = std::char_traits<T>::compare(m_buffer, str.m_buffer, std::min(lhs, rhs));
    if (result != 0) {
        return result;
    }
    if (lhs < rhs) {
        return -1;
    }
    if (lhs > rhs) {
        return 1;
    }
    return 0;
}

template <typename T>
int BasicString<T>::compare(const T* str) const {
    return compare(BasicString{str});
}

} // end namespace CBL

template <class T>
CBL::BasicString<T> operator+(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    CBL::BasicString<T> res = lhs;
    res += rhs;
    return res;
}

template <class T>
CBL::BasicString<T> operator+(const T* lhs, const CBL::BasicString<T>& rhs) {
    return operator+(CBL::BasicString<T>{lhs}, rhs);
}

template <class T>
CBL::BasicString<T> operator+(const CBL::BasicString<T>& lhs, const T* rhs) {
    return operator+(lhs, CBL::BasicString<T>{rhs});
}

template <class T>
CBL::BasicString<T> operator+(const CBL::BasicString<T>& lhs, const T rhs) {
    return operator+(lhs, CBL::BasicString<T>{1, rhs});
}

template <class T>
CBL::BasicString<T> operator+(const T lhs, const CBL::BasicString<T>& rhs) {
    return operator+(CBL::BasicString<T>{1, lhs}, rhs);
}

template <class T>
bool operator==(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    if (lhs.length() != rhs.length()) {
        return false;
    }
    return std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    return 1;
}

template <class T>
bool operator==(const T* lhs, const CBL::BasicString<T>& rhs) {
    return operator==(CBL::BasicString<T>{lhs}, rhs);
}

template <class T>
bool operator==(const CBL::BasicString<T>& lhs, const T* rhs) {
    return operator==(lhs, CBL::BasicString<T>{rhs});
}

template <class T>
bool operator!=(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return !(lhs == rhs);
}

template <class T>
bool operator!=(const T* lhs, const CBL::BasicString<T>& rhs) {
    return !(lhs == rhs);
}

template <class T>
bool operator!=(const CBL::BasicString<T>& lhs, const T* rhs) {
    return !(lhs == rhs);
}

template <class T>
bool operator<(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T>
bool operator<(const T* lhs, const CBL::BasicString<T>& rhs) {
    return CBL::BasicString<T>{lhs} < rhs;
}

template <class T>
bool operator<(const CBL::BasicString<T>& lhs, const T* rhs) {
    return CBL::BasicString<T>{lhs} < rhs;
}

template <class T>
bool operator<=(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return (lhs < rhs) || (lhs == rhs);
}

template <class T>
bool operator<=(const T* lhs, const CBL::BasicString<T>& rhs) {
    return (lhs < rhs) || (lhs == rhs);
}

template <class T>
bool operator<=(const CBL::BasicString<T>& lhs, const T* rhs) {
    return (lhs < rhs) || (lhs == rhs);
}

template <class T>
bool operator>(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return !(lhs <= rhs);
}

template <class T>
bool operator>(const T* lhs, const CBL::BasicString<T>& rhs) {
    return !(lhs <= rhs);
}
template <class T>
bool operator>(const CBL::BasicString<T>& lhs, const T* rhs) {
    return !(lhs <= rhs);
}

template <class T>
bool operator>=(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return !(lhs < rhs);
}
template <class T>
bool operator>=(const T* lhs, const CBL::BasicString<T>& rhs) {
    return !(lhs < rhs);
}

template <class T>
bool operator>=(const CBL::BasicString<T>& lhs, const T* rhs){
    return !(lhs < rhs);
}

template <class T>
std::ostream& operator<<(std::ostream& os, CBL::BasicString<T>& str) {
    for (size_t i = 0; i < str.length(); i++) {
        os << str[i];
    }
    return os;
}