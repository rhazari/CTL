#pragma once
#include "List.h"

template <typename T>
inline List<T>::List():
    m_head(nullptr), m_tail(nullptr)
{}

template <typename T>
inline List<T>::~List() {
    ListNode<T> *curr = m_head;
    while (m_head) {
        m_head = m_head->m_next;
        delete curr;
        curr = m_head;
    }
}

template <typename T>
inline T& List<T>::front() {
    if (nullptr == m_head)
        throw std::runtime_error("List is empty");
    return m_head->m_data;
}

template <typename T>
inline const T& List<T>::front() const {
    if (nullptr == m_head)
        throw std::runtime_error("List is empty");
    return m_head->m_data;
}

template <typename T>
inline T& List<T>::back() {
    if (nullptr == m_tail)
        throw std::runtime_error("List is empty");
    return m_tail->m_data;
}

template <typename T>
inline const T& List<T>::back() const {
    if (nullptr == m_tail)
        throw std::runtime_error("List is empty");
    return m_tail->m_data;
}


template <typename T>
inline void List<T>::push_back(T&& val) {
    ListNode<T>* newNode = new ListNode<T>(std::move(val), nullptr, m_tail);
    if (m_head == nullptr)
        m_head = newNode;
    if (m_tail != nullptr)
        m_tail->m_next = newNode;
    m_tail = newNode;
    ++count;
}

template <typename T>
inline void List<T>::push_front(T&& val) {
    ListNode<T> *newNode = new ListNode<T>(std::move(val), m_head, nullptr);
    if (m_tail == nullptr)
        m_tail = newNode;
    if (m_head != newNode)
        m_head->m_prev = newNode;
    m_head = newNode;
    ++count;
}

template <typename T>
inline void List<T>::pop_front() {
    if (nullptr == m_head)
        throw std::runtime_error("Empty List");
    ListNode<T> *temp = m_head;
    m_head = m_head->m_next;
    if (m_head != nullptr)
        m_head->m_prev = nullptr;
    --count;
    delete temp;
}

template <typename T>
inline void List<T>::pop_back() {
    if (nullptr == m_tail)
        throw std::runtime_error("Empty List");
    ListNode<T> *temp = m_tail;
    m_tail = m_tail->m_prev;
    if (m_tail != nullptr)
        m_tail->m_next = nullptr;
    --count;
    delete temp;
}

template <typename T>
inline T& List<T>::at(const size_t index) {
    if (index >= count)
        throw std::runtime_error("Index out of bounds");
    size_t id = 0;
    ListNode<T>* ptr = m_head;
    while (ptr) {
        if (id == index)
            return ptr->m_data;
        ptr = ptr->m_next;
        ++id;
    }
}

template <typename T>
inline const T& List<T>::at(const size_t index) const {
    if (index >= count)
        throw std::runtime_error("Index out of bounds");
    size_t id = 0;
    ListNode<T>* ptr = m_head;
    while (ptr) {
        if (id == index)
            return ptr->m_data;
        ptr = ptr->m_next;
        ++id;
    }
}

template <typename T>
inline T& List<T>::operator[] (const size_t index) {
    if (index >= count)
        throw std::runtime_error("Index out of bounds");
    size_t id = 0;
    ListNode<T>* ptr = m_head;
    while (ptr) {
        if (id == index)
            return ptr->m_data;
        ptr = ptr->m_next;
        ++id;
    }
}

template <typename T>
inline const T& List<T>::operator[] (const size_t index) const {
    if (index >= count)
        throw std::runtime_error("Index out of bounds");
    size_t id = 0;
    ListNode<T>* ptr = m_head;
    while (ptr) {
        if (id == index)
            return ptr->m_data;
        ptr = ptr->m_next;
        ++id;
    }
}

template <typename T>
inline typename List<T>::iterator List<T>::begin() {
    return iterator(m_head);
}

template <typename T>
inline typename List<T>::iterator List<T>::end() {
    return iterator(m_tail);
}

template <typename T>
inline bool List<T>::empty() const {
    if (nullptr == m_head && nullptr == m_tail)
        return true;
    return false;
}

template <typename T>
inline size_t List<T>::size() const {
    return count;
}

template <typename T>
void inline List<T>::print() {
    ListNode<T> *ptr = m_head;
    while (ptr) {
        std::cout << ptr->m_data << " ";
        ptr = ptr->m_next;
    }
    std::cout << "\n";
}