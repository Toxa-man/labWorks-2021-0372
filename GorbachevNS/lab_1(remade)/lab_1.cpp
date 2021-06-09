#include <iostream>

using T = int;

struct Node
{
    Node* pnext=nullptr;
    T m_data=T();
};

 class List {
private:
    unsigned m_size=0;
    Node* head=nullptr;
public:
    List(const List& list);
    List(unsigned size = 0, const T& data = T());
    ~List();
    void push_back(const T& data);
    bool insert(const T& date, unsigned index);
    bool contains(const T& val);
    int get_size() { return m_size; }
    void resize(unsigned n_size);
    T& operator[](unsigned index);
    List& operator=(const List& list);
   int find(const T& val);

    void print();
};

int main()
{
    List lst_1(1,7); List lst_2(3,5);
    lst_1 = lst_2; 
    lst_1.push_back(2);
    std::cout << lst_1.get_size();
    lst_1.print();
}

List::List(const List& list)
{
    *this = list;
}

List::List(unsigned size, const T& data)
{
    if (size != 0) {
        resize(size);
 }
    if (size != 0 && data != T()) {
        Node* temp=head;
        for (unsigned i = 0; i < size; i++) {
            temp->m_data = data;
            temp = temp->pnext;
        }
    }
}

List::~List()
{
    resize(0);
}

void List::push_back(const T& data)
{
    if (head == nullptr) {
        head = new Node;
    }
    else {
        Node* temp = head;
        for (unsigned i = 0; i < m_size-1; i++) {
            temp = temp->pnext;
        }
        temp->pnext = new Node;
        temp->pnext->m_data = data;
    }
    m_size++;
}

bool List::insert(const T& date, unsigned index)
{
    if (index > m_size) {
        return false;
    }
    if (index == 0) {
        Node* temp = new Node;
        temp->pnext=head;
        head = temp;
        head->m_data = date;
        m_size++;
        return true;
    }
    else {
        Node* current = head;
        for (unsigned i = 0; i < index-1; i++) {
            current = current->pnext;
        }
        Node* toDelete = current->pnext;
        current->pnext = new Node;
        current->pnext->pnext = toDelete;
        current->pnext->m_data = date;
        m_size++;
        return true;
    }
}

void List::resize(unsigned n_size)
{
    if (m_size == 0 && n_size!=0) {
        head = new Node;
        m_size++;
    }
    Node* temp=head;
    Node* current;
    if (n_size < m_size) {
        for (unsigned i = 0; i < m_size; i++) {
            if (i < n_size) {
                temp = temp->pnext;
            }
            if (i >= n_size) {
                current = temp->pnext;
                delete temp;
                temp = current;
            }
        }
    }
    if (n_size > m_size) {
        for (unsigned i = 1; i < n_size; i++) {
            if (i >= m_size) {
                temp->pnext = new Node;
            }  
            temp = temp->pnext;
         }
    }
    m_size = n_size;
}

T& List::operator[](unsigned index)
{
    if (index == 0) {
        return head->m_data;
}
    if (index <= m_size) {
        Node* temp = head;
        for (unsigned i = 0; i < index; i++) {
            temp = temp->pnext;
        }
        return temp->m_data;
    }
}

void List::print()
{
    Node* temp=head;
    for (int i = 0; i < get_size(); i++) {
        std::cout << temp->m_data<<" ";
        temp = temp->pnext;
    }
    std::cout <<"\n";
}

List& List::operator=(const List& list)
{
    if (this != &list) {
        resize(list.m_size);
        Node* current = head;
        Node* temp = list.head;
        for (unsigned i = 0; i < m_size; i++) {
            current->m_data = temp->m_data;
            current = current->pnext;
            temp = temp->pnext;
        }
   }
    return *this;
}

int List::find(const T& data)
{
    Node* temp = head;
    for (int i=0;i<m_size;i++) {

        if (temp->m_data == data) {
            return i;
        }
        temp = temp->pnext;
    }
    return -1;
}

bool List::contains(const T& data)
{
    if (find(data) == -1) {
        return false;
    }
    return true;
}
