#include <iostream>
#include <ctime>

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
    T& operator [] (int index);
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
    if (old_size == 0 && new_size != 0)
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
        for (int i = 0; i < new_size; i++) {
            if (i+1 >= old_size && i+1 != new_size)
                    ptr->next = new Node;
            ptr = ptr->next;
        }
    }
    old_size = new_size;
}

bool List::insert(int unsigned pos, const T& val = 0) {
    if (pos > old_size+1 || pos < 0)
        return false;
    Node* ptr = head;
    Node* tmp = nullptr;
    int j = 0;
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
    return true;
}

void List::push_back(const T& val) {
/*    Node* ptr = head;
    for (int i = 0; i < old_size-1; i++)
        ptr = ptr->next;
    ptr->next = new Node;
    ptr = ptr->next;
    ptr->value = val;
    old_size++;*/
    insert(old_size,val);
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

T &List::operator [] (int index) {
    Node* ptr = head;
    int j = 0;
    index = index % int(old_size);
    if (index < 0)
        index += int(old_size);
    while (j < index) {
        ptr = ptr->next;
        j++;
    }
    return ptr->value;
}

void List::operator = (List& m_list) {
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
        std::cout << i << ':' << '\t' << ptr->value << std::endl;
        ptr = ptr->next;
    }
    std::cout << "Size: " << old_size << std::endl;
}


void  my_test() {
    int a = rand() % 100;
    std:: cout << "a = " << a << std::endl;

    std::cout << "\nThe first List: \n\n";
    List list1(5,7);
    list1.print();
    list1.resize(1);
    list1.print();
    list1.push_back(a);
    list1[0] = -a;
    list1.print();
    if (list1.contains(a))
        std::cout << "list contains " << a << '\n';
    else
        std::cout << "list does not contain " << a << '\n';

    std::cout << "\nThe second List: \n\n";
    List list2;
    list2.print();
    list2 = list1;
    list2.print();
    list2.resize(list1.size()+1);
    list2.print();
    if (list2.insert(2, 5))
        std::cout << "Successful insert 5 in pos 2" << '\n';
    else
        std::cout << "Insert failed" << '\n';
    list2.print();
    list2.insert(4, 3);
    list2.print();

    std::cout << "\nThe third List: \n\n";
    List list3 = list2;
    list3.print();
    std::cout << "The index of the element = " << a << " is ";
    if (list3.find(a) == -1)
        std::cout << "not found" << std::endl;
    else
        std::cout << list3.find(a) << std::endl;
    std::cout << "The index of the element = " << a+3 << " is ";
    if (list3.find(a+3) == -1)
        std::cout << "not found" << std::endl;
    else
        std::cout << list3.find(a+3) << std::endl;
    std::cout << "Last element: " << list2[-1] << '\n';
    std::cout << list3[55] << '\n';
    std::cout << list3[-13] << '\n';
}


int main() {
    srand(time(0));
    my_test();

    return 0;
}