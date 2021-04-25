#include <iostream>

using T = int;

struct Node{
    T value = 0;
    Node * next = nullptr;
};


class List{
private:
    Node * head = nullptr;
    int list_size = 0;
public:
    List(unsigned size = 0, const T &val = 0){
        // Constructor that can gets 'size' or/and 'val' values
        resize(size);
        if (val != 0 && size != 0){
            Node * ptr = head;
            for (int i = 0; i < list_size; i++){
                ptr->value = val;
                ptr = ptr->next;
            }
        }
    };
    List(List &copy){
        // If constructor gets List object doing copy
        head = new Node();
        Node * m = head;
        for (int i = 0; i < copy.list_size - 1; i++) {
            m->next = new Node;  // Creating new Node, if current size less than new
            m->value = copy[i];
            m = m->next;
        }
        m->value = copy[-1];
        list_size = copy.list_size;
    };
    ~List(){
        resize(0);
    };
    unsigned size() const;
    void resize(unsigned size);
    bool insert(unsigned pos, const T &val);
    void  push_back(const T &val);
    bool contains(const T &val);
    int find(const T &val);
    T &operator [] (int index);
    void operator = (List const &obj);
};

void List::resize(unsigned new_size) {
    if (list_size == 0 && new_size != 0)
        head = new Node();
    Node * m = head;
    if (new_size > list_size) {
        for (int i = 0; i < new_size - 1; i++) {
            if (list_size == 0 || (i >= list_size - 1)){
                m->next = new Node;  // Creating new Node, if current size less than new
            }
            m = m->next;
        }
    } else {
        // Deleting Nodes from "head", if new size less than current
        for (int i = 0; i < list_size - new_size; i++) {
            m = head->next;
            delete head;
            head = m;
        }
    }
    list_size = new_size;
}

unsigned List::size() const {
    return list_size;
}

T &List::operator [] (int index) {
    if (index >= list_size || (index < 0 - list_size && index < 0))
        throw -1;
    if (index < 0) // Feature to get value from end of list (with negative index)
        index = list_size + index;
    Node * m = head;
    for (int i = 0; i < list_size; i++) {
        if (i == index)
            return m->value;
        else
            m = m->next;
    }
}

void List::operator = (const List &obj) {
    resize(0);  // Deleting old list
    resize(obj.list_size);  // Creating new
    Node * self = head;
    Node * other = obj.head;
    for (int i = 0; i < list_size; i++){
        self->value = other->value;
        self = self->next;
        other = other->next;
    }
}

int List::find(const T &val) {
    Node * m = head;
    int i = 0;
    while (m){
        if (m->value == val)
            return i;
        m = m->next;
        i++;
    }
    return -1;
}

bool List::contains(const T &val) {
    if (this->find(val) == -1)
        return false;
    return true;
}

bool List::insert(unsigned int pos, const T &val) {
    if (pos >= list_size)
        return false;
    Node * m = head;
    Node * g;
    if (pos > 0)
        for (int i = 0; i < list_size; i++) {
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
    list_size++;
    return true;
}

void List::push_back(const T &val) {
    Node * m = head;
    while (m->next) {
        m = m->next;
    }
    m->next = new Node;
    m->next->value = val;
    list_size++;
}


void print(List &list){
    for (int i = 0; i < list.size(); i++)
        std::cout << list[i] << " ";
    std::cout << '\n';
}


void test(){
    // Testing main features
    int a;
    std::cin >> a;

    std::cout << "list1: \n\n";
    List list1(1);
    print(list1);
    list1.push_back(a);
    list1[0] = -a;
    print(list1);
    std::cout << "Index elem = " << a << ": " << list1.find(a) << '\n';
    if (list1.contains(a))
        std::cout << "list1 contains " << a << '\n';
    else
        std::cout << "list1 not contains " << a << '\n';

    std::cout << "\nlist2: \n\n";
    List list2 = list1;
    std::cout << "Last elem: " << list2[-1] << '\n';
    if (list2.insert(1, 4))
        std::cout << "Successful insert 4 in pos 1" << '\n';
    else
        std::cout << "Insert failed" << '\n';
    list2.insert(2, 3);
    print(list2);

    std::cout << "\nlist2: \n\n";
    List list3(3, 5);
    print(list3);
    std::cout << list3[-2] << '\n';
    list3 = list2;
    print(list3);
    std::cout << list3[-4] << '\n';


}


int main() {
    test();

    return 0;
}
