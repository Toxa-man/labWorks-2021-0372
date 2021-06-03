#include <iostream>
using T = int;

struct Node {
    T value;
    Node* next;
};

class List {
    Node* head;
    int count = 0;
    
    public:

    List() {
        head->value = 0;
        head->next = nullptr;
    }

    List(unsigned size) {
        count = 1;
        Node* tmp = new Node;
        head = tmp;
        for (int i = 0; i < size - 1; i++) {
            tmp->value = 0;
            tmp->next = new Node;
            tmp = tmp->next;
            count++;
        }
        tmp->value = 0;
        tmp->next = nullptr;
    }

    List(unsigned size, T val) {
        count = 1;
        Node* tmp = new Node;
        head = tmp;
        for (unsigned i = 0; i < size - 1; i++) {
            tmp->next = new Node;
            tmp->value = val;
            tmp = tmp->next;
            count++;
        }
        tmp->value = val;
        tmp->next = nullptr;
    }

    ~List() {
        Node* tmp = head;
        Node* next;
        for (int i = 0; i < count; i++) {
            next = tmp->next;
            delete tmp;
            tmp = next;
        }
    }

    unsigned size() {
        return count;
    }

    void resize(unsigned size) {
        unsigned new_count = 0;
        Node* tmp = head;
        if (size > count) {
            new_count++;
            for (int i = 0; i < count - 1; i++) {
                tmp = tmp->next;
                new_count++;
            }
            for (int i = 0; i < (size-count); i++) {
                tmp->next = new Node;
                new_count++;
                tmp = tmp->next;
                tmp->value = 0;
            }
            tmp->next = nullptr;
        } else if (size < count) {
            for (int i = 0; i < size; i++) {
            tmp = tmp->next;
            new_count++;
            }
            Node* to_delete = tmp;
            while (to_delete != nullptr) {
                Node* next = to_delete->next;
                delete to_delete;
                to_delete = next;
                if (next->next == nullptr) {
                    delete to_delete;
                    break;
                } else {
                next = next->next;
                }
            }
        }
        count = new_count;
    }

    void push_back(T val) {
        Node* tmp = head;
        for (int i = 0; i < count - 1; i++) {
            tmp = tmp->next;
        }
            Node* next = tmp->next;
            Node* insert = new Node;
            tmp->next = insert;
            insert->value = val;
            insert->next = nullptr;
            count++;
    }

    bool insert(unsigned pos, T val) {
        if (pos < 0 || pos >= count + 1) {
            return false;
        } else if (pos == count) {
            push_back(val);
            return true;
        } else {
            Node* tmp = head;
            if (pos == 0) {
                Node* n = new Node;
                n->next = tmp;
                n->value = val;
                head = n;
                count++;
            } else {
                for (int i = 0; i < pos - 1; i++) {
                    tmp = tmp->next;
                }
                Node* next = tmp->next;
                Node* insert = new Node;
                tmp->next = insert;
                insert->value = val;
                insert->next = next;
                count++;
                }
            return true;
        }
    }

    bool contains(T val) {
        Node* tmp = head;
        for (int i = 0; i <= count; i++) {
            if (tmp->value == val) return true;
            tmp = tmp->next;
        }
        return false;
    }

    int find(T val) {
        Node* tmp = head;
        for (int i = 0; i < count; i++) {
            if (tmp->value == val) {
                return i;
            }
            tmp = tmp->next;
        }
        return -1;
    }

    T& operator[](unsigned index) {
        if (index < 0 || index > count) {
            throw std::runtime_error("Out of range");
        }
        Node* tmp = head;
        for (int i = 0; i < index; i++) {
            tmp = tmp->next;
        }
        return tmp->value;
    }
    
    List& operator =(const List& al) {
        resize(0);
        count = al.count;
        Node* tmp = new Node; 
        head = tmp;
        tmp->value = al.head->value;
        Node* val = al.head->next;
        while (val){
            tmp->next = new Node;
            tmp = tmp->next;
            tmp->value = val->value;
            val = val->next;
        }
        tmp->next = nullptr;
        return *this;
    }

    List(const List& al) {
        head = nullptr;
        *this = al;
    }


 };


 



int main() {
    List l(3,3);
    l.resize(6);
    l.push_back(1);
    std::cout << l.size() << " " << l.contains(3);
    std::cout << l[0];
    // l.push_back(2);
    // std::cout << l.size() << " ";
    // l.insert(4, 1);
    // std::cout << l.contains(1) << " ";
    // l.print();
    //std::cout << l.find(0);
    return 0;
}
