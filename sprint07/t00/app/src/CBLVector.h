#pragma once

#include <iostream>
#include <initializer_list>
#include <tuple>
#include <utility>

namespace CBL {
template<class T>
class Vector {
public:
    using iterator= T*;

    Vector();
    explicit Vector(size_t size);
    Vector(size_t size, const T& value);
    Vector(iterator first, iterator last);
    Vector(const std::initializer_list<T>& lst);
    Vector(const Vector<T>& other);
    ~Vector();

    Vector<T>& operator=(const Vector<T>& other);
    bool operator==(const Vector<T>& other) const;
    bool operator!=(const Vector<T>& other) const;
    bool operator<(const Vector<T>& other) const;
    bool operator>(const Vector<T>& other) const;
    bool operator<=(const Vector<T>& other) const;
    bool operator>=(const Vector<T>& other) const;

    // iterators
    iterator begin() const;
    iterator end() const;

    // capacity
    size_t size() const;
    size_t capacity() const;
    bool isEmpty() const;
    void resize(size_t size, const T& value = T());
    void reserve(size_t size);

    // element access
    T& operator[](size_t index) const;
    T& at(size_t index) const;
    T* data() const;

    // modifiers
    void push_back(const T& value);
    void pop_back();
    iterator insert(iterator pos, const T& value);
    iterator erase(iterator pos);
    iterator erase(iterator first, iterator last);
    void clear();
private:
    size_t m_size{0};
    size_t m_capacity{0};
    T* m_buffer{nullptr};
};

template <typename T>
Vector<T>::Vector() {}

template <typename T>
Vector<T>::Vector(size_t size) : m_size(size), m_capacity(size), m_buffer(new T[size]) {
    for (size_t i = 0; i < size; ++i) {
        m_buffer[i] = T();
    }
}

template <typename T>
Vector<T>::Vector(iterator first, iterator last) : Vector(last - first){
    int count = 0;
    while (first != last) {
        m_buffer[count++] = *(first++);
    }
}

template <typename T>
Vector<T>::Vector(size_t size, const T& value) : Vector(size) {
    for (size_t i = 0; i < size; ++i) {
        m_buffer[i] = value;
    }
}

template <typename T>
Vector<T>::Vector(const std::initializer_list<T>& lst) : Vector(lst.size()) {
    size_t count = 0;

    for (auto &element : lst) {
        m_buffer[count++] = element;
    }
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other) : Vector(other.capacity()) {
    m_size = other.size();
    std::copy(other.begin(), other.end(), begin());
}

template <typename T>
Vector<T>::~Vector() {
    delete[] m_buffer;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::begin() const {
    return m_buffer;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::end() const  {
    return m_buffer + m_size;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if (this == &other) {
        return *this;
    }
    m_capacity = std::max(m_capacity, other.capacity());
    m_size = other.size();
    delete[] m_buffer;
    m_buffer = new T[m_capacity];
    std::copy(other.begin(), other.end(), begin());
    return *this;
}

template <typename T>
bool Vector<T>::operator==(const Vector<T>& other) const {
    return std::equal(begin(), end(), other.begin(), other.end());
}

template <typename T>
bool Vector<T>::operator!=(const Vector<T>& other) const {
    return !std::equal(begin(), end(), other.begin(), other.end());
}

template <typename T>
bool Vector<T>::operator<(const Vector<T>& other) const {
    return std::lexicographical_compare(begin(), end(), other.begin(), other.end(), [](T lhs, T rhs) {
        return lhs < rhs;
    });
}

template <typename T>
bool Vector<T>::operator>(const Vector<T>& other) const {
    return std::lexicographical_compare(begin(), end(), other.begin(), other.end(), [](T lhs, T rhs) {
        return lhs > rhs;
    });
}

template <typename T>
bool Vector<T>::operator<=(const Vector<T>& other) const {
    return std::lexicographical_compare(begin(), end(), other.begin(), other.end(), [](T lhs, T rhs) {
        return lhs <= rhs;
    });
}

template <typename T>
bool Vector<T>::operator>=(const Vector<T>& other) const {
    return std::lexicographical_compare(begin(), end(), other.begin(), other.end(), [](T lhs, T rhs) {
        return lhs >= rhs;
    });
}

template <typename T>
size_t Vector<T>::size() const {
    return m_size;
}

template <typename T>
size_t Vector<T>::capacity() const {
    return m_capacity;
}

template <typename T>
bool Vector<T>::isEmpty() const {
    return m_size == 0;
}

template <typename T>
void Vector<T>::resize(size_t size, const T& value) {
    size_t new_size = std::min(size, m_size);
    T* new_buffer = new T[size];

    std::copy(begin(), begin() + new_size, new_buffer);
    delete[] m_buffer;
    m_buffer = new_buffer;
    if (size > m_size) {
        for (size_t i = m_size; i < size; ++i) {
            m_buffer[i] = value;
        }
    }
    if (size > m_capacity) {
        m_capacity = std::max(m_capacity * 2, size);
    }
    m_size = size;
}

template <typename T>
void Vector<T>::reserve(size_t size) {
    if (capacity() < size) {
        size_t new_cap = size;
        T* new_buffer = new T[new_cap];
        std::move(begin(), end(), new_buffer);
        delete[] m_buffer;
        m_buffer = new_buffer;
        m_capacity = new_cap;
    }
}

template <typename T>
T& Vector<T>::operator[](size_t index) const {
    return m_buffer[index];
}

template <typename T>
T& Vector<T>::at(size_t index) const {
    if (index >= size()) {
        throw std::out_of_range("Vector");
    }
    return m_buffer[index];
}

template <typename T>
T* Vector<T>::data() const {
    return m_buffer;
}

template <typename T>
void Vector<T>::push_back(const T& value) {
    if (m_size >= m_capacity) {
		if (!m_capacity) {
			++m_capacity;
		}
		m_capacity *= 2;
		T* tmp = new T[m_capacity];
		std::copy(begin(), end(), tmp);
		delete[] m_buffer;
		m_buffer = tmp;
	}
	m_buffer[m_size++] = value;
}

template <typename T>
void Vector<T>::pop_back() {
    if (m_size) {
        resize(--m_size);
    }
}

template <typename T>
typename Vector<T>::iterator Vector<T>::insert(iterator pos, const T& value) {
    size_t new_size = 0;
    size_t dis = std::distance(begin(), pos);

    new_size = pos <= end() ? m_size + 1 : dis + 1;
    if (m_capacity <  new_size) {
        m_capacity *= 2;
        T* new_buffer = new T[m_capacity];
        std::move(begin(), end(), new_buffer);
        delete[] m_buffer;
        m_buffer = new_buffer;
    }
    for (size_t i = end() - begin(); i > dis; i--) {
        m_buffer[i] = m_buffer[i - 1];
    }
    m_size = new_size;
    m_buffer[dis] = value;
    return m_buffer + dis;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::erase(iterator pos) {
    std::move(pos + 1, end(), pos);
    --m_size;
    return pos;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::erase(iterator first, iterator last) {
    std::move(last, end(), first);
    m_size -= std::distance(first, last);
    return first;
}

template <typename T>
void Vector<T>::clear() {
    delete[] m_buffer;
    m_buffer = nullptr;
    m_size = 0;
}

} // end namespace CBL
