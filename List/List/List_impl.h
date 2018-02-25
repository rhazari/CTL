#pragma once
#include "List.h"

template <typename T>
inline List<T>::~List() {
    ListNode<T> *curr = m_head;
    while (m_head) {
        m_head = m_head->next;
        delete curr;
        curr = m_head;
    }
}

template <typename T>
inline void List<T>::insertToTail(T val) {
    ListNode<T>* newNode = new ListNode<T>(val);
    if (nullptr == m_tail) {
        newNode->next = m_tail;
        m_tail = newNode;
        m_head = newNode;
        return;
    }
    m_tail->next = newNode;
    m_tail = m_tail->next;
}

template <typename T>
inline void List<T>::insertToHead(T val) {
    ListNode<T> *newNode = new ListNode<T>(val);
    newNode->next = m_head;
    m_head = newNode;
    if (m_head->next == nullptr)
        m_tail = newNode;
}

template <typename T>
inline void List<T>::print() {

}