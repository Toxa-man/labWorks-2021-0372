#include <iostream>
#include <string>

using T = int;
struct Node {
	T value;
	Node* next;
};

class List {
public:
	List();
	List(unsigned size);
	List(unsigned size, const T& val);
	List(const List& l);
	T& operator [](unsigned index);
	List& operator=(const List& l);
	~List();

	void print();
	unsigned size();
	void resize(unsigned size);
	bool insert(unsigned pos, const T& val);
	void push_back(const T& val);
	bool contains(const T& val);
	int find(const T& val);

private:
	Node* head;
	unsigned list_size;
};

//Default contructor
List::List() : head(nullptr), list_size(0) {}

//Default constructor with size setting
List::List(unsigned size) : list_size(size) {
	if (list_size > 0) {
		head = new Node{ 0, nullptr };
		Node* ptr = head;
		for (int i = 0; i < list_size - 1; i++) {
			ptr->next = new Node{ 0, nullptr };
			ptr = ptr->next;
		}
	}
}

//Default constructor with filling
List::List(unsigned size, const T& val) : list_size(size) {
	if (list_size > 0) {
		head = new Node{ val, nullptr };
		Node* ptr = head;
		for (int i = 0; i < list_size - 1; i++) {
			ptr->next = new Node{ val, nullptr };
			ptr = ptr->next;
		}
	}
}

//Copy constructor
List::List(const List& l) {
	Node* ptr = l.head;
	list_size = 0;
	for (int i = 0; i < l.list_size; i++) {
		insert(i, ptr->value);
		ptr = ptr->next;
	}
}

//Destructor
List::~List() {
	resize(0);
}

//Get size of the list
unsigned List::size() {
	return list_size;
}

//Resize the list
void List::resize(unsigned size) {
	if (list_size < size) {
		//Create first element if list is empty
		if (list_size == 0) {
			head = new Node{ 0, nullptr };
			list_size++;
		}

		Node* ptr = head;
		for (int i = 1; i < list_size; i++) {
			ptr = ptr->next;
		}
		for (int i = list_size; i < size; i++) {
			ptr->next = new Node{ 0, nullptr };
			ptr = ptr->next;
		}
		list_size = size;
	} else if (list_size > size) {
		Node* ptr = head;
		Node* nextPtr = nullptr;
		for (int i = 0; i < size; i++) {
			ptr = ptr->next;
		}
		for (int i = size; i < list_size; i++) {
			nextPtr = ptr->next;
			delete ptr;
			ptr = nextPtr;
		}
		list_size = size;
	}
}

//Print all elements
void List::print() {
	Node* ptr = head;
	for (int i = 0; i < list_size; i++) {
		std::cout << ptr->value << " ";
		ptr = ptr->next;
	}
	std::cout << '\n';
}

//Brackets operator
T& List::operator [](unsigned index) {
	if (index < 0 || index >= list_size) {
		std::cout << "Error: Index is out of range." << std::endl;
		system("pause");
		exit(1);
	} else {
		Node* ptr = head;
		for (int i = 0; i < index; i++) {
			ptr = ptr->next;
		}
		return ptr->value;
	}
}

//Check whether an elements is in the list
bool List::contains(const T& val) {
	Node* ptr = head;
	for (int i = 0; i < list_size; i++) {
		if (ptr->value == val) {
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}

//Find an element or return -1
int List::find(const T& val) {
	Node* ptr = head;
	for (int i = 0; i < list_size; i++) {
		if (ptr->value == val) {
			return i;
		}
		ptr = ptr->next;
	}
	return -1;
}

//Insert an element with size incrementation
bool List::insert(unsigned pos, const T& val) {
	if (pos < 0 || pos > list_size) {
		return false;
	}	else {
		Node* ptr = head;
		Node* nextPtr = nullptr;
		Node* newEl = new Node{ val, nullptr };

		for (int i = 1; i < pos; i++) {
			ptr = ptr->next;
		}

		if (pos == 0) {
			head = newEl;
			head->next = ptr;
		}	else {
			nextPtr = ptr->next;
			ptr->next = newEl;
			newEl->next = nextPtr;
		}

		list_size++;
		return true;
	}
}

//Add an element at the end
void List::push_back(const T& val) {
	insert(list_size, val);
}

//Assigment operator
List& List::operator=(const List& l) {
	Node* ptr = l.head;
	resize(0);
	for (int i = 0; i < l.list_size; i++) {
		insert(i, ptr->value);
		ptr = ptr->next;
	}
	return *this;
}

int main() {
	List l1;
	List l2{ 5 };
	List l3{ 7, 2 };

	std::cout << "--- List 1 ---\n";
	l1.resize(5);
	for (int i = 0; i < l1.size(); i++) {
		l1[i] = i + 1;
	}
	l1.print();

	std::cout << "\n--- List 2 ---\n";
	l2.print();
	l2.insert(4, 25);
	l2.insert(0, 7);
	l2.push_back(54);
	l2.print();

	std::cout << "\n--- List 3 ---\n";
	l3.print();
	l3.resize(3);
	l3[0] = 6;
	l3[2] = -6;
	std::cout << "Second element is " << l3[1] << '\n';
	l3.print();

	std::cout << "\n--- Assigment ---\n";
	l1 = l2;
	l1.print();
	l2.print();
	if (l2.contains(25)) {
		std::cout << "Index of the 25 value is " << l2.find(25) << '\n';
	}

	std::cout << "\n--- Copy ---\n";
	List l4 = l1;
	l4.print();
	l4.resize(0);

	return 0;
}