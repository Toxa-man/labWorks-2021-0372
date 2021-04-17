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
        Node *get()  {
            return ptr;
        }

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



        bool operator== (const iterator &other) const {
            return (other.ptr == ptr);
        }

        bool operator!= (const iterator &other) const {
            return (other.ptr != ptr);
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

    T& operator[] (uint i);

    const T& operator[] (uint i) const;

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

    bool insert(uint pos, const T& val);

    void push_back(const T& val);
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
T& List<T>::operator[] (uint i) {
    List<T>::iterator it = first();
    for(uint j=0;j<i;j++){
        ++it;
    }
    return (it.get()->m_value);
}

template<typename T>
const T& List<T>::operator[] (uint i) const {
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
        m_last->m_next = nullptr;
        m_size = newSize;
        return;
    }
}

template<typename T>
bool List<T>::insert(uint pos, const T& val) {
    if(m_size < pos + 1){
        return false;
    }
    if(m_size == 0) {
        resize(1);
        operator[](0) = val;
        return true;
    }
    if(pos+1==m_size) {
        Node* new_node = new Node(val);
        new_node->m_prev = m_last;
        m_last->m_next = new_node;
        m_last = new_node;
        ++m_size;
        return true;
    }
    if(pos == 0) {
        Node* newNode = new Node(val);
        m_head->m_prev = newNode;
        newNode->m_next = m_head;
        m_head = newNode;
        ++m_size;
        return true;
    }
    Node* before_new = first().get();
    for(int i = 0;i<pos-1;i++){
        before_new = before_new->m_next;
    }
    auto after_new = before_new->m_next;
    Node* new_Node = new Node(val);
    before_new->m_next = new_Node;
    new_Node->m_prev = before_new;
    after_new->m_prev = new_Node;
    new_Node->m_next = after_new;
    ++m_size;
    return true;
}

template<typename T>
void List<T>::push_back(const T& val) {
    insert(m_size-1, val);
}

#endif //LIST_LIST_H
