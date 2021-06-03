#include <iostream>


using T = int;

struct Node{
    T value = 0;
    Node * next = nullptr;
};

class List{
private:
    int list_size = 0;
    Node * head = nullptr;
public:
    List(unsigned size = 0, const T &val = 0){   //default constructor
        resize(size);
        if (val != 0 && size != 0){
            Node * ptr = head;
            for (int i = 0; i < list_size; i++){
                ptr->value = val;
                ptr = ptr->next;
            }
        }
    };

    List(List &new_list){
        resize(new_list.size());
        Node* ptr = head;
        list_size = new_list.size();

        for (int i = 0; i < list_size; i++) {
            ptr->value = new_list[i];
            ptr = ptr->next;
        }
    };

    ~List(){   //If we equate the list size to 0, the list is deleted accordingly
        resize(0);
    };

    unsigned size() const;
    void resize(unsigned size);
    bool insert(unsigned pos, const T &val);
    void  push_back(const T &val);
    bool contains(const T &val);
    T &operator [] (int unsigned index);
    void operator = (List &object);
    int find(const T &value);
};

unsigned List::size() const {  // return size of list
    return list_size;
}

void List::resize(unsigned new_size) {  //equates the size of the list to size
    if (list_size == 0 && new_size != 0)
        head = new Node();
    Node * ptr = head;
    if (new_size > list_size) {
        for (int i = 0; i < new_size - 1; i++) {
            if (list_size == 0 || (i >= list_size - 1)){ // creating new Node, if current size less than new
                ptr->next = new Node;
            }
            ptr = ptr->next;
        }
    } else {  // deleting Nodes ( head ), if new size less than current
        for (int i = 0; i < list_size - new_size; i++) {
            ptr = head->next;
            delete head;
            head = ptr;
        }
    }
    list_size = new_size;
}

bool List::insert(unsigned int pos, const T &val) {  //inserts val at the pos position
    if (pos >= list_size)
        return false;
    Node * ptr = head;
    Node * so;
    if (pos > 0)
        for (int i = 0; i < list_size; i++) {
            if (pos == i + 1) {
                so = ptr->next;
                ptr->next = new Node;
                ptr->next->value = val;
                ptr->next->next = so;
                break;
            }
            ptr = ptr->next;
        }
    else {
        ptr = new Node;
        ptr->value = val;
        ptr->next = head;
        head = ptr;
    }
    list_size++;
    return true;  //returns true, if success of the operation
}

void List::push_back(const T &val) {  //adds val to the end of the list
    Node * ptr= head;
    while (ptr->next) {
        ptr = ptr->next;
    }
    ptr->next = new Node;
    ptr->next->value = val;
    list_size++;
}

bool List::contains(const T &val) { //returns true if val is present in the list and false otherwise
    if (this->find(val) == -1)
        return false;
    return true;
}

T &List::operator [] (int unsigned index) {  // accessing an element with the index index.
    Node* ptr = head;
    int j = 0;

    while (j < index) {
        ptr = ptr->next;
        j++;
    }

    return ptr->value;
}

void List::operator = (List &object_list) {
    resize(object_list.size());
    Node* ptr = head;

    for (int i = 0; i < list_size; i++) {
        ptr->value = object_list[i];
        ptr = ptr->next;
    }

}

int List::find(const T &value) { //returns the index of the first occurrence of val in the list, or -1 if it is not present
    Node * ptr = head;
    int i = 0;
    while (ptr){
        if (ptr->value == value)  //the index was found, we output the place of occurrence
            return i;
        ptr = ptr->next;
        i++;
    }
    return -1; //the index is missing, we return -1
}

void print(List &list){
    if (list.size()>0) {
        std::cout << "List:" << std::endl;
        for (int i = 0; i < list.size(); i++)
            std::cout << i + 1 << ". " << list[i] << std::endl;
    }
    else
        std::cout << "The list is empty" << std::endl;
}


int main() {

    List list_one;
    print(list_one);

    return 0;
}