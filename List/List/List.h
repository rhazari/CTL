#pragma once

#include <iostream>

template <typename T>
class List {
private:
    template <typename T>
    struct ListNode {
        T m_data;

        ListNode<T> *next;

        ListNode<T>(const T& data) : 
            m_data(data), next(nullptr) {}

        ListNode<T>(const ListNode<T>& node) : 
            m_data(node.m_data), next(nullptr) {}
        
        ListNode<T>& operator=(const ListNode<T>& node) = delete;
    };

    ListNode<T> *m_head;
    ListNode<T> *m_tail;

public:
    List<T>() : 
        m_head(nullptr), m_tail(nullptr) {}

    ~List<T>();

    void insertToTail(T data);

    void insertToHead(T data);

    void print();
};

#include "List_impl.h"