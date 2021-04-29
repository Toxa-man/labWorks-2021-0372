#include <iostream>

using T = int;

struct Node {
    int value = 0;
    Node* next = nullptr;
};

class List {
private:
    unsigned int old_size = 0;
    Node* head = nullptr;
public:

    List (int unsigned size = 0, const T& val = 0) {
        resize(size);

        Node* ptr = head;

        for (int i = 0; i < old_size; i++) {
            ptr->value = val;
            ptr = ptr->next;
        }
    }

    List (List& m_list) {
        resize(m_list.size());
        Node* ptr = head;
        old_size = m_list.size();

        for (int i = 0; i < old_size; i++) {
            ptr->value = m_list[i];
            ptr = ptr->next;
        }
    }

    unsigned int size();
    void resize(int unsigned size);
    bool insert(int unsigned pos, const T& val);
    void push_back(const T& val);
    bool contains(const T& val);
    int& operator [](int unsigned index);
    void operator = (List& m_list);
    int find(const T& val);
    void print();

    ~List() {
        Node* ptr = head;

        for (int i = 0; i < old_size; i++) {
            ptr = head->next;
            delete head;
            head = ptr;
        }
    }
};

unsigned int List::size() {
    return old_size;
}

void List::resize(int unsigned new_size) {
    if (old_size == 0)
        head = new Node;

    Node* ptr = head;

    if (new_size < old_size) {
        Node* tmp = nullptr;

        for (int i = 0; i < old_size; i++) {
            if (i >= new_size) {
                tmp = ptr->next;
                delete ptr;
                ptr = tmp;
            }
            else
                ptr = ptr->next;
        }

    } else if (new_size > old_size) {

        if (new_size != 1) {
            for (int i = 0; i < new_size; i++) {
                if (i+1 >= old_size) {

                    if ((old_size+1 == new_size && i+1 != new_size) || i+1 != new_size)
                        ptr->next = new Node;

                }
                ptr = ptr->next;
            }
        }
    }

    old_size = new_size;
}

bool List::insert(int unsigned pos, const T& val) {
    Node* ptr = head;
    Node* tmp = nullptr;
    int j = 0;
    bool flag = false;

    if (pos > old_size+1 || pos < 0)
        return flag;
    else {
        while (j != pos-1) {
            ptr = ptr->next;
            j++;
        }
        tmp = ptr->next;
        ptr->next = new Node;
        ptr = ptr->next;
        ptr->value = val;
        ptr->next = tmp;

        old_size++;

        return !flag;
    }
}

void List::push_back(const T& val) {
    Node* ptr = head;

    for (int i = 0; i < old_size-1; i++)
        ptr = ptr->next;

    ptr->next = new Node;
    ptr = ptr->next;
    ptr->value = val;

    old_size++;
}

bool List::contains(const T& val) {
    Node* ptr = head;

    for (int i = 0; i < old_size; i++) {
        if (ptr->value == val)
            return true;
        else
            ptr = ptr->next;
    }

    return false;
}

T& List::operator [] (int unsigned index) {
    Node* ptr = head;
    int j = 0;

    while (j < index) {
        ptr = ptr->next;
        j++;
    }

    return ptr->value;
}

void List::operator=(List& m_list) {
    resize(m_list.size());
    Node* ptr = head;

    for (int i = 0; i < old_size; i++) {
        ptr->value = m_list[i];
        ptr = ptr->next;
    }

}

int List::find(const T& val) {
    Node* ptr = head;

    for (int i = 0; i < old_size; i++) {
        if (ptr->value == val)
            return i;
        else
            ptr = ptr->next;
    }

    return -1;
}

void List::print() {
    Node* ptr = head;

    std::cout << "Our list:" << std::endl;
    for (int i = 0; i < old_size; i++) {
        std::cout << i+1 << ':' << '\t' << ptr->value << std::endl;
        ptr = ptr->next;
    }

    std::cout << "Size: " << old_size << std::endl;
}


int main() {

    List list1;

    return 0;
}