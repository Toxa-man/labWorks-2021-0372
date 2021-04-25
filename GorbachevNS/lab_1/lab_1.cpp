#include <iostream>

using T = int;

class List {
public:

    List(const List& list);

    List(unsigned size = 0, const T& data = T());

    ~List();////

    void clear();

    void pop_back();

    void pop_front();

    void push_back(const T& data);

    void push_front(const T& data);

    bool insert(const T& date, unsigned index);

    bool contains(const T& val);

    void removeAt(unsigned index);

    int get_size() { return size; }

    void resize(unsigned n_size);

    T& operator[](unsigned index);

    List& operator=(const List& list);

    int find(const T& val);
private:
    //элемент Списка
    class Node {
    public:
        Node* pNext;
        T data;
        //конструктор страницы
        Node(T data = T(), Node* pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
        }
    };
    Node* head;// начало списка
    int size;//размер списка
};

void print(List& list)
{
    std::cout << "Melons in the List\n";
    for (int i = 0; i < list.get_size(); i++) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl << "____________________" << std::endl;
}

void test() {
    List list_1(3, 3);
    List list_2(5);
    List list_3;
    std::cout << "Output of the source data\n";
    std::cout << "List_1\nsize " << list_1.get_size() << std::endl;
    print(list_1);
    std::cout << "List_2\nsize " << list_2.get_size() << std::endl;
    print(list_2);
    std::cout << "List_3\nsize " << list_3.get_size() << std::endl;
    print(list_3);
    std::cout << "Changing the List_1 size\n\n";
    list_1.resize(5);
    print(list_1);
    list_1.resize(2);
    print(list_1);
    std::cout << "Applying the method insert(List_2)\n\n";
    list_2.insert(1, 2);
    print(list_2);
    std::cout << "Applying the method push_bac (List_2)\n\n";
    list_2.push_back(2);
    print(list_2);
    std::cout << "Applying the method contains(1) (List_2)\n";
    std::cout << std::boolalpha << list_2.contains(1) << "\n";
    std::cout << "Applying the operator [] (List_2)\noutput of the last element\n";
    std::cout << list_2[list_2.get_size() - 1] << "\n";
    std::cout << "Applying the method find(2) (List_2)\n";
    std::cout << list_2.find(2) << "\n";
    std::cout << "Applying the operator = ( list_2 = list_1)\n";
    list_2 = list_1;
    std::cout << "output List_2\n";
    print(list_2);
    std::cout << "Applying  copy ( list_4(list_3))\n";
    List list_4(list_3);
    print(list_4);
}

int main()
{
    test();
}
// конструктор
List::List(unsigned size , const T& data )
{
    if (data != 0 && size != 0) {
        for (int i = 0; i < size; i++) {

            push_back(data);
        }
    }
    else {
        resize(size);
    }
}
//copy
List::List(const List& list) {
    resize(0);
    Node* current = list.head;
    for (int i = 0; i < list.size; i++) {
        insert(current->data, i);
        current = current->pNext;
    }
}
// Диструктор
List::~List()
{
    clear();
}
//Очистка элементов списков
void List::clear()
{
    while (size)
    {
        pop_front();
    }
}
// удаление первого элемнта
void List::pop_front()
{
    Node* temp = head;
    head = head->pNext;
    delete temp;
    size--;
}
//Добвление в конец списка
void List::push_back(const T& data)
{

    if (head == nullptr) {

        head = new Node(data);

    }
    else {
        Node* current = this->head;
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node(data);
    }
    size++;
}
//Добвление в начало списка
void List::push_front(const T& data)
{
    head = new Node(data, head);
    size++;

}
// Добавление по идексу
bool List::insert(const T& data, unsigned index)
{

    if (index == 0)
    {
        push_front(data);
    }
    else if (index <= get_size())
    {
        Node* previous = this->head;

        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }

        previous->pNext = new Node(data, previous->pNext);

        size++;
        return true;
    }
    else {
        return false;
    }

}

bool List::contains(const T& data)
{
    if (this->find(data) == -1) {
        return false;
    }
    return true;
}
// удаление элемнта по идексу
void List::removeAt(unsigned index)
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        Node* previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }


        Node* toDelete = previous->pNext;

        previous->pNext = toDelete->pNext;

        delete toDelete;

        size--;
    }

}
// удаление последнего элемнта
void List::pop_back()
{
    removeAt(size - 1);
}
//изменение размера
void List::resize(unsigned n_size)
{
    if (n_size > size) {
        for (unsigned i = size; i < n_size; i++) {
            push_back(0);
        }
    }
    else if (n_size < size) {
        for (unsigned i = size; i > n_size; i--) {
            pop_back();
        }
    }
}

int List::find(const T& data)
{
    Node* temp = head;
    int i = 0;
    while (temp) {
        if (temp->data == data) {
            return i;
        }
        temp = temp->pNext;
        i++;
    }
    return -1;
}
// Обращение к элементу списка
T& List::operator[](unsigned index)
{
    int counter = 0;
    Node* current = this->head;
    while (current != nullptr)
    {
        if (counter == index) {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }

}
// оператор присваивания
List& List::operator=(const List& list) {
    Node* current = list.head;
    resize(0);
    for (int i = 0; i < list.size; i++) {
        insert(current->data, i);
        current = current->pNext;
    }
    return *this;
}
