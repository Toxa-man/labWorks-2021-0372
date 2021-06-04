#include <iostream>
#include <Windows.h>

using T = int;

struct Node {
    T value = 0;
    Node* next = nullptr;
};

class List{
private:
    Node* head = nullptr;
    int list_razmer = 0;
public:
    List(unsigned razmer = 0, const T& val = 0) {
        resize(razmer);
        if (val != 0 && razmer != 0) {
            Node* ptr = head;
            for (int i = 0; i < list_razmer; i++) {
                ptr->value = val;
                ptr = ptr->next;
            }
        }
    };
    List(List& copy) {
        head = new Node();
        Node* m = head;
        for (int i = 0; i < copy.list_razmer - 1; i++) {
            m->next = new Node;
            Node* m = head;
            m->value = copy[i];
            m = m->next;
        }
        m->value = copy[-1];
        list_razmer = copy.list_razmer;
    };
    ~List() {
        resize(0);
    };
    unsigned razmer() const;
    void resize(unsigned razmer);
    void push_back(const T&val);
    bool contains(const T& val);
    bool insert(unsigned pos, const T &val);
    T& operator[](int index);
    int find(const T& val);
    void operator = (List const &obj);
};

unsigned List::razmer() const {
    return list_razmer;
}

T& List::operator[](int index) {
    if (index >= list_razmer || (index < 0 - list_razmer && index < 0)) {
        throw - 1;
        if (index < 0) {
            index = list_razmer + index;
    }
        Node* m = head;
        for (int i = 0; i < list_razmer; i++) {
            if (i == index) {
                return m->value;
            }
            else {
                m = m->next;
            }
        }
    }
}

void List::resize(unsigned new_razmer) {
    if (list_razmer == 0 && new_razmer != 0) {
        head = new Node();
    }
    Node * m = head;
    if (new_razmer > list_razmer) {
        for (int i = 0; i < new_razmer - 1; i++) {
            if (list_razmer == 0 || i >= list_razmer - 1) {
                m->next = new Node;
            }
            m = m->next;
        }
    }
    else {
        for (int i = 0; i < list_razmer - new_razmer; i++) {
            m = head->next;
            delete head;
            head = m;
        }
    }
    list_razmer = new_razmer;
}

void List::push_back(const T& val) {
    Node* m = head;
    while (m->next) {
        m = m->next;
    }
    m->next = new Node;
    m->next->value = val;
    list_razmer++;
}

int List::find(const T &val) {
    Node * m = head;
    int i = 0;
    while (m) {
        if (m->value == val) {
            return i;
        }
        m = m->next;
        i++;
    }
    return -1;
}

bool List::contains(const T& val) {
    if (this->find(val) == -1) {
        return 1;
    }
    return 0;
}

bool List::insert(unsigned int pos, const T& val) {
    if (pos >= list_razmer) {
        return 1;
    }
    Node* m = head;
    Node* g;
    if (pos > 0) 
        for (int i = 0; i < list_razmer; i++) {
            if (pos == i + 1) {
                g = m->next;
                m->next = new Node;
                m->next->value = val;
                m->next->next = g;
                break;
            }
            m = m->next;
        }
    else {
        m = new Node;
        m->value = val;
        m->next = head;
        head = m;
    }
    list_razmer++;
    return 0;
    }


void print(List &list) {
    for (int i = 0; i < list.razmer(); i++) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}

void List::operator  =(const List &obj) {
    resize(0);
    resize(obj.list_razmer);
    Node* self = head;
    Node* other = obj.head;
    for (int i = 0; i < list_razmer; i++) {
        self->value = other->value;
        self = self->next;
        other = other->next;
    }
}

void Screen() {
    int k = 0;
    std::cin >> k;
    std::cout << "Список 1 " << std::endl << std::endl;
    List list1(1);
    print(list1);
    list1.push_back(k);
    list1[0] = -k;
    print(list1);
    std::cout << "Номер индекса = " << k << ": " << list1.find(k) << std::endl;
    if (list1.contains(k)) {
        std::cout << "Список 1 содержит в себе " << k << std::endl;
    }
    else {
        std::cout << "Список 1 не содержит в себе " << k << std::endl;
    }
    std::cout << std::endl << "Список 2" << std::endl << std::endl;
    List list2 = list1;
    std::cout << "Последний элемент: " << list2[-1] << std::endl;
    if (list2.insert(1, 4)) {
        std::cout << "Перестановка с 1 на 4 выполнена успешно" << std::endl;
    }
    else {
        std::cout << "Перестановка провалена";
    }
    list2.insert(2, 3);
    print(list2);
    std::cout << std::endl << "Список 2: " << std::endl << std::endl;
    List list3(3, 5);
    print(list3);
    std::cout << list3[-2] << std::endl;
    list3 = list2;
    print(list3);
    std::cout << list3[-4] << std::endl;
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Screen();
}
