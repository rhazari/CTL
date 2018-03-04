#pragma once

#include <iostream>
#include <cstddef>
#include <iterator>
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

    class iterator
    {
    public:
        using value_type = T;
        using reference = T&;
        using pointer = T*;
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        iterator(ListNode<T>* ptr) : _ptr(ptr) { }

        iterator operator++() {
            assert(_ptr != nullptr && "Out-of-bounds iterator increment!");
            _ptr = _ptr->m_next;
            return *this;
        }

        iterator operator++(int junk) {
            assert(_ptr != nullptr && "Out-of-bounds iterator increment!");
            iterator temp(*this);
            _ptr = _ptr->m_next;
            return temp;
        }

        reference operator*() {
            assert(_ptr != nullptr && "Invalid iterator dereference!");
            return _ptr->m_data;
        }

        pointer operator->() {
            assert(_ptr != nullptr && "Invalid iterator dereference!");
            return _ptr->m_data;
        }

        bool operator==(const iterator& rhs) const {
            return _ptr == rhs._ptr;
        }

        bool operator!=(const iterator& rhs) const {
            return _ptr != rhs._ptr;
        }
    private:
        ListNode<T>* _ptr;
    };

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

    iterator begin();

    iterator end();
};

#include "List_impl.h"