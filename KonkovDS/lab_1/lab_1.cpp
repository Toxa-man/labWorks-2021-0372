#include <iostream>

using T = int;

struct node {
    T value;
    node* next;
};

class list {
private:
    node* head;
    unsigned int size_val;

public:
    list(); // дефолтный конструктор
    ~list(); //destructor
    list(const list& clist); //copy-constructor
    list(unsigned size); //создаёт список размером size и заполняет его дефолтными значениями, т.е. T()
    list(unsigned size, const T& val); //создаёт список размером size и заполняет его значением val

    unsigned size() const; //возвращает размер списока
    void resize(unsigned size); // приравнивает размера списока к size; если новый размер больше старого - новые элементы заполнить нулями
    bool insert(unsigned pos, const T& val); //вставляет val в позицию pos; возвращает true | false в зависимости от успеха операции
    void push_back(const T& val); //добавляет val в конец списока
    bool contains(const T& val); //возвращает true если val присуствует в списоке и false в противном случае
    T& operator [] (unsigned index); // обращение к элементу с индексом index. При этом должно быть возможно как читать значение, так и изменять его
    list& operator=(const list& clist); // assignment operator
    int find(const T& val); //возвращает индекс первого вхождения val в список или -1 в случае его отсутствия
    void print(); // вывод
};

list::list() {
    size_val = 0;
    head = nullptr;
}

list::~list() {
    resize(0);
}

list::list(const list& clist) {
    node* current = clist.head;
    for (int i = 0; i < clist.size_val; i++) {
        push_back(current->value);
        current = current->next;
    }
}

list::list(unsigned size) {
    size_val = size;
    head = new node{ 0,nullptr };
    node* current = head;
    for (int i = 0; i < size_val; i++) {
        current->next = new node{ 0,nullptr };
        current = current->next;
    }
}

list::list(unsigned size, const T& val) {
    size_val = size;
    head = new node{ val,nullptr };
    node* current = head;
    for (int i = 0; i < size_val; i++) {
        current->next = new node{ val,nullptr };
        current = current->next;
    }
}

unsigned list::size() const {
    return size_val;
}

void list::resize(unsigned size) {
    if (size == 0) {
        size_val = 0;
        head = new node{ 0,nullptr };
    }
    else if (size_val > size) {
        node* next = nullptr;
        node* current = head;
        for (int i = 0; i < size; i++)
            current = current->next;
        for (int i = size; i < size_val; i++) {
            next = current->next;
            delete current;
            current = next;
        }
    }
    else if (size_val < size) {
        node* current = head;
        for (int i = 1; i < size_val; i++)
            current = current->next;
        for (int i = size_val; i < size; i++) {
            push_back(0);
        }
    }
    size_val = size;
}

bool list::insert(unsigned pos, const T& val) {
    if (pos > size_val || pos < 0)
        return false;
    if (pos == 0) {
        head = new node{ val, head };
        size_val++;
    }
    else {
        node* previous = this->head;
        for (int i = 0; i < pos - 1; i++)
            previous = previous->next;
        previous->next = new node{ val, previous->next };
        size_val++;
    }
    return true;
}

void list::push_back(const T& val) {
    if (head == nullptr)
        head = new node{ val, nullptr };
    else {
        node* current = head;
        for (int i = 0; i < size_val - 1; i++)
            current = current->next;
        current->next = new node{ val,nullptr };
    }
    size_val++;
}

bool list::contains(const T& val) {
    node* current = head;
    while (current->next != nullptr) {
        if (current->value == val)
            return true;
        current = current->next;
    }
    return false;
}


T& list::operator[](unsigned index) {
    int counter = 0;
    if (index < size_val) {
        node* current = head;
        while (current->next != nullptr) {
            if (counter == index)
                return current->value;
            current = current->next;
            counter++;
        }
    }
    else {
        std::cout << "wrong input" << std::endl;
        system("pause");
    }
}

list& list::operator=(const list& clist) {
    node* current = clist.head;
    while (current != nullptr) {
        push_back(current->value);
        current = current->next;
    }
    return *this;
}

int list::find(const T& val) {
    node* current = head;
    int index = 0;
    while (current->next != nullptr) {
        if (current->value == val)
            return index;
        index++;
        current = current->next;
    }
    return -1;
}

void list::print() {
    node* current = head;
    for (int i = 0; i < size_val; i++) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << '\n';
}

int main() {
   list l1{ 5 };
    l1.print();
    l1.push_back(12);
    l1.print();
    std::cout << "size of first list " << l1.size() << std::endl;

    list l2{ 6,3 };
    l2.print();
    l2.resize(12);
    l2.print();
    l2.insert(7, 111);
    l2.print();
    l2.resize(8);
    l2.print();

    list l3 = l2;
    l3.print();
    l3.print();
    std::cout << l3.operator[](5) << std::endl;
    std::cout << l3.contains(111) << std::endl;
    std::cout << l3.contains(11111) << std::endl;
    std::cout << l3.find(3) << std::endl;
    std::cout << l3.find(6) << std::endl;

    list l4;
    l4.push_back(2);
    l4.push_back(9);
    l4.push_back(9);
    l4.print();
    std::cout << "size of fourth list " << l4.size() << std::endl;

    list l5;
    l5 = l4;
    l5.print();

    return 0;
}
