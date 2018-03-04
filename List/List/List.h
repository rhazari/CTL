#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class List {
private:
    template <typename T>
    struct ListNode {
        T m_data;

        ListNode<T> *m_next, *m_prev;

        ListNode<T>(T&& data, ListNode<T>* next, ListNode<T>* prev) :
            m_data(std::move(data)), m_next(next), m_prev(prev) {}

        ListNode<T>(const T& data, ListNode<T>* next, ListNode<T>* prev) :
            m_data(data), m_next(next), m_prev(prev) {}

        ListNode<T>(const ListNode<T>& node) : 
            m_data(node.m_data), m_next(node->m_next), m_prev(node->m_prev) {}
        
        ListNode<T>& operator=(const ListNode<T>& node) = delete;
    };

    int count = 0;

    ListNode<T> *m_head;
    ListNode<T> *m_tail;

public:

    List<T>();

    //List<T>(const List<T>& list);

    //List<T>& operator=(List<T> list);

    ~List<T>();

    void push_back(T&& data);

    /*void push_back(const T& data);*/

    void push_front(T&& data);

    /*void push_front(const T& data);*/

    void pop_front();

    void pop_back();

    void print();

    /* Iterators */
    using iterator = T* ;
    using const_iterator = const T*;

    const_iterator begin() const;
    iterator begin();

    const_iterator end() const;
    iterator end();

    const_iterator rbegin() const;
    iterator rbegin();

    const_iterator rend() const;
    iterator rend();

    /* Capacity */
    size_t size() const;
    bool empty() const;

    /* Element Access */
    T& front();
    const T& front() const;

    T& back();
    const T& back() const;

    T& at(const size_t index);
    const T& at(const size_t index) const;

    T& operator[](const size_t index);
    const T& operator[](const size_t index) const;
};

#include "List_impl.h"