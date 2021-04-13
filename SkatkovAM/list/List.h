//
// Created by alex on 3/19/21.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

#include <iostream>

template<typename T>
class List {
    struct Node {
        T m_value = {};
        Node *m_next = nullptr;
        Node *m_prev = nullptr;

        Node() {
            std::cout << "New ";
            std::cout.flush();
        }
        Node(const T& init)
            :m_value(init) {
            std::cout << "New ";
            std::cout.flush();
        }

        ~Node() {
            std::cout << "Del ";
            std::cout.flush();
        }
    };


    uint m_size = 0;
    Node *m_head = nullptr;
    Node *m_last = nullptr;
public:

    struct iterator {
    private:
        Node *ptr = nullptr;
    public:
        iterator(Node *ptr_) {
            ptr = ptr_;
        }

        iterator operator++() {
            if (ptr == nullptr) {
                return nullptr;
            }
            ptr = ptr->m_next;
            return *this;
        }

        iterator operator++(int) {
            if (ptr == nullptr) {
                return nullptr;
            }
            auto temp = *this;
            ptr = ptr->m_next;
            return temp;
        }

        T &operator--() {
            if (ptr == nullptr) {
                return nullptr;
            }
            ptr = ptr->m_prev;
            return *this;
        };

        T &operator--(int) {
            if (ptr == nullptr) {
                return nullptr;
            }
            auto temp = *this;
            ptr = ptr->m_prev;
            return temp;
        };

        T &operator*() {
            return ptr->m_value;
        }

        const T &operator*() const {
            return ptr->m_value;
        }

        Node *get() const {
            return ptr;
        }

        bool operator== (const iterator &other) const {
            return (other.ptr == ptr);
        }

        bool operator!= (const iterator &other) const {
            return (other.ptr != ptr);
        }

        bool operator> (const iterator &other) const {
            return (ptr > other.ptr);
        }

        bool operator>= (const iterator &other) const {
            return (ptr >= other.ptr);
        }

        bool operator< (const iterator &other) const {
            return (ptr < other.ptr);
        }

        bool operator<= (const iterator &other) const {
            return (ptr <= other.ptr);
        }
    };

    explicit List(uint size = 0) {
        resize(size);
    }

    List(uint size,const T& def);

    List(const List<T> &);

    List(List<T> &&other);

    List<T> &operator=(const List<T> &);

    List<T> &operator=(List<T> &&);

    Node& operator[] (uint i);

    const Node& operator[] (uint i) const;

    ~List() {
        resize(0);
    }

    iterator first() {
        return iterator(m_head);
    }


    const iterator first() const {
        return iterator(m_head);

    }

    iterator last() {
        return iterator(m_last);
    }

    const iterator last() const {
        return iterator(m_last);
    }

    void resize(uint);

};
template<typename T>
List<T>::List(uint size,const T& def)
                :m_size(size){
        Node *newNodes = new Node(def);
            m_head = newNodes;
        Node *iter = newNodes;
        for (int i = 0; i < size-1; i++) {
            iter->m_next = new Node(def);
            iter->m_next->m_prev = iter;
            iter = iter->m_next;
        }
        m_last = iter; // =)
}

template<typename T>
List<T>::List(const List<T> &other) {
    resize(other.m_size);
    iterator it = first();
    iterator otherIt = other.first();
    for (int i; i < m_size; i++) {
        *it = *otherIt;
        it++;
        otherIt++;
    }
}

template<typename T>
List<T>::List(List<T> &&other) {
    m_size = other.m_size;
    m_head = other.m_head;
    other.m_head = nullptr;
    other.m_size = 0;
    m_last = other.m_last;
    other.m_last = nullptr;
}

template<typename T>
List<T> &List<T>::operator=(const List<T> &other) {
    if(&other == this) {
        return *this;
    }
    resize(other.m_size);
    iterator it = first();
    iterator otherIt = other.first();

    for (int i = 0; i < m_size; i++) {
        *it = *otherIt;
        ++it;
        ++otherIt;
    }
    return *this;
}

template<typename T>
List<T> &List<T>::operator=(List<T> &&other) {
    if(&other == this) {
        return *this;
    }
    resize(other.m_size);
    m_head = other.m_head;
    other.m_head = nullptr;
    other.m_last = nullptr;
    other.m_size = 0;
    return *this;
}
template<typename T>
typename List<T>::Node& List<T>::operator[] (uint i) {
    List<T>::iterator it = first();
    for(uint j=0;j<i;j++){
        ++it;
    }
    return *it;
}
template<typename T>
const typename List<T>::Node& List<T>::operator[] (uint i) const {
    return (*this)[i];
}

template<typename T>
void List<T>::resize(uint newSize) {
    if (m_size == newSize) {
        return;
    }
    if (newSize > m_size) {
        Node *newNodes = new Node();
        if (m_head == nullptr) {
            m_head = newNodes;
        } else {
            m_last->m_next = newNodes;
            newNodes->m_prev = m_last;
        }
        Node *iter = newNodes;
        for (int i = 0; i < newSize - m_size - 1; i++) {
            iter->m_next = new Node();
            iter->m_next->m_prev = iter;
            iter = iter->m_next;
        }
        m_last = iter; // =)
        m_size = newSize;
        return;
    }
    if (newSize < m_size) {
        Node *iter = m_last;
        for (int i = 0; i < m_size - newSize; i++) {
            Node *nextToDel = iter->m_prev;
            delete iter;
            iter = nextToDel;
        }
        if (newSize == 0) {
            m_head = nullptr;
            m_last = nullptr;
            m_size = 0;
            return;
        }
        m_last = iter;
        m_last->m_next = nullptr; // =)
        m_size = newSize;
        return;
    }
}


#endif //LIST_LIST_H
