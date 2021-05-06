#include <iostream>

using T = int;

struct Node {        
    T value;
    Node* next;
};

class List
{
private:
    Node* head = nullptr;
    int size_now;
public:
    List() {             
        size_now = 0;
        head = nullptr; 
    }
    ~List() {
        resize(0);
    }
    List(unsigned size) {
        size_now = size;
        head = new Node{ 0 };
        Node* current = head;   
        for (int i = 0; i < size_now; i++) {
            current->next = new Node{ 0 };   
            current = current->next;
        }
    }
    List(unsigned size, const T& val) {
        size_now = size;
        head = new Node{ val };
        Node* current = head;  
        for (int i = 0; i < size_now; i++) {
            current->next = new Node{ val };  
            current = current->next;
        }
    }
    void push_back(const T& val);
    void resize(unsigned size);
    unsigned size();
    void print();
    bool insert(unsigned pos, const T& val);
    bool contains(const T& val);
    int find(const T& val);
    T& operator [](unsigned index);
    List& operator=(const List& clist); 
    List(const List& clist);
};

List::List(const List& clist) {                        
    Node* current = clist.head;
    for (int i = 0; i < clist.size_now; i++) {
        push_back(current->value);
        current = current->next;
    }
}
void List::resize(unsigned size)
{
    if (size_now == 0 && size != 0)
        head = new Node();
    Node* current = head;
    if (size > size_now) {
        for (int i = 0; i < size - 1; i++) {
            if (size_now == 0 || (i >= size_now - 1))
            {
                current->next = new Node{ 0 };
            }
            current = current->next;
        }
    }
    else {    
        for (int i = 0; i < size_now - size; i++) {
            current = head->next;
            delete head;
            head = current;
        }
    }
    size_now = size;
}

void List::push_back(const T& val)
{
    if (head == nullptr) { 
        head = new Node{ val };
    }
    else {                 
        Node* current = this->head;
        while (current->next != nullptr)
            current = current->next;
        current->next = new Node{ val };
    }
    size_now++;
}

unsigned List::size() {
    return size_now;
}

bool List::insert(unsigned pos, const T& val) {
    if (pos > size_now || pos < 0)
        return false;
    if (pos == 0) {
        head = new Node{ val, head };
        size_now++;
        return true;
    }
    if (pos == size_now) {
        push_back(val);
        return true;
    }
    else {
        Node* last = this->head;       
        for (int i = 0; i < pos - 1;i++)   
        {
            last = last->next;
        }
        Node* newElement = new Node{ val, last->next }; 
        last->next = newElement;  
        size_now++;
        return true;
    }
}

bool List::contains(const T& val) {
    Node* current = head;
    for (int i = 0; i < size_now; i++) {
        if (current->value == val)
            return true;
        current = current->next;
    }
    return false;
}

int List::find(const T& val)
{
    Node* current = head;
    for (int i = 0; i < size_now; i++) {
        if (current->value == val) {
            return i;
        }
        current = current->next;
    }
    return -1;
}

T& List::operator [](unsigned index) {
    if (index < 0 || index >= size_now) {
        std::cout << "wrong type";
        system("Pause");                   
    }
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->value;
}

List& List::operator=(const List& clist) {   
    Node* current = clist.head;
    while (current != nullptr) {
        push_back(current->value);
        current = current->next;
    }
    return *this;
}

void List::print() {
    Node* current = head;
    for (int i = 0; i < size_now; i++) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << '\n';
}

int main() {
    List li1{ 9 };
    li1.print();
    li1.push_back(55);
    li1.print();
    std::cout << "Size li1: " << li1.size() << std::endl;

    List li2{ 7,5 };
    li2.print();
    li2.resize(12);
    li2.print();
    std::cout << "Size li2: " << li2.size() << std::endl;
    li2.insert(12, 151);
    li2.print();
    std::cout << "Size li2 new: " << li2.size() << std::endl;
    std::cout << li2.operator[](11) << std::endl;
    std::cout << li2.operator[](12) << std::endl;

    List li3;
    li3.push_back(3);
    li3.push_back(5);
    li3.push_back(7);
    li3.print();
    std::cout << "First go " << li3.find(4) << std::endl;
    std::cout << "First go " << li3.find(7) << std::endl;
    std::cout << "Size li3: " << li3.size() << std::endl;
    std::cout << li3.contains(4) << std::endl;
    std::cout << li3.contains(7) << std::endl;   

    List li4;
    li4 = li3;
    li4.print();

    return 0;
}
