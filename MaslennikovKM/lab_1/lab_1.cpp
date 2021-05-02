#include <iostream>
#include <string>
using namespace std;

using T = int;
struct Node {
	T value;
	Node* next;
};
class List {
	private:
		Node* head;
		unsigned l_size;
	public:
		List();
		List(unsigned size);
		List(unsigned size, const T& val);
		List(const List& list);
		unsigned size() {
			return l_size;
		}
		void resize(unsigned size);
		bool contains(const T& val);
		int find(const T& val);
		void pop_front();
		void removeAt(unsigned index);
		void pop_back();
		void clear();
	    ~List();
		T& operator[](unsigned index);
		List& operator=(const List& list);
		bool insert(unsigned pos, const T& val);
		void push_front(const T& val);
		void push_back(const T& val);
		void print();
};



List::List()
{
	head = nullptr;
	l_size = 0;
}

List::List(unsigned size)
{
	l_size = size;
	if (l_size > 0) {
		head = new Node{ 0, nullptr };
		Node* current = head;
		for (int i = 0; i < l_size-1; i++) {
			current->next = new Node{ 0, nullptr };
			current = current->next;
		}
	}
}

List::List(unsigned size, const T& val)
{
	l_size = size;
	if (l_size > 0) {
		head = new Node{ val, nullptr };
		Node* current = head;
		for (int i = 0; i < l_size-1; i++) {
			current->next = new Node{ val, nullptr };
			current = current->next;
		}
	}
}

List::List(const List& list)
{
	Node* current = list.head;
	l_size = 0;
	for (int i = 0; i < list.l_size; i++) {
		insert(i, current->value);
		current = current->next;
	}
}

void List::resize(unsigned size)
{
	if (size > l_size) {
		for (int i = l_size; i < size; i++) {
			push_back(0);
		}
	}
	else if (size < l_size) {
		for (int i = l_size; i > size; i--) {
			pop_back();
		}
	}
}

bool List::contains(const T& val)
{
	Node* current = head;
	for(int i = 0; i < l_size; i++) {
		if (current->value == val) {
			return true;
		}
		current = current->next;
	}
	return false;
}

int List::find(const T& val)
{
	Node* current = head;
	for (int i = 0; i < l_size; i++) {
		if (current->value == val) {
			return i;
		}
		current = current->next;
	}
	return -1;
}

void List::pop_front()
{
	Node* temp = head;
	head = head->next;
	delete temp;
	l_size--;
}

void List::removeAt(unsigned index)
{
	if (index == 0) {
		pop_front();
	}
	else {
		Node* previous = head;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->next;
		}
		Node* temp_delete = previous->next;
		previous->next = temp_delete->next;
		delete temp_delete;
		l_size--;
	}
}

void List::pop_back()
{
	removeAt(l_size - 1);
}

void List::clear()
{
	while (l_size != 0) {
		pop_front();
	}
}

List::~List()
{
	clear();
}

T& List::operator[](unsigned index)
{
	int count = 0;
	Node* current = head;
	while (current !=nullptr) {
		if (count == index) {
			return current->value;
		}
		current = current->next;
		count++;
	}
}

List& List::operator=(const List& list)
{
	Node* current = list.head;
	resize(0);
	for (int i = 0; i < list.l_size; i++) {
		insert(i, current->value);
		current = current->next;
	}
	return *this;
}

bool List::insert(unsigned pos, const T& val)
{
	if (pos == 0) {
		push_front(val);
		return true;
	}
	else if (pos <= size()) { 
		Node* previous = head;
		for (int i = 0; i < pos - 1; i++) {
			previous = previous->next;
		}
		Node* New_Node = new Node{ val, previous->next };
		previous->next = New_Node;
		l_size++;
		return true;
	}
	else {
		return false;
	}
	
}

void List::push_front(const T& val)
{
	head = new Node{val, head};
	l_size++;
}

void List::push_back(const T& val)
{
	if (head == nullptr) {
		head = new Node{ val, nullptr };
	}
	else {
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = new Node{ val, nullptr };
	}
	l_size++;
}

void List::print()
{
	Node* current = head;
	for (int i = 0; i < l_size; i++) {
		cout << current->value << endl;
		current = current->next;
	}
}

int main() {
	List test_0;
	List test_1{3};
	List test_2{ 5, 10 };

	cout << "////// Test 0 //////" << endl;
	test_0.resize(4);
	test_0.print();
	cout << endl;

	cout << "////// Test 1 //////" << endl;
	test_1.print();
	test_1.resize(6);
	test_1.push_back(43);
	cout << endl;
	cout << "////// List after resize and push_back: //////" << endl;
	test_1.print();
	cout << endl;

	cout << "////// Test 2 //////" << endl;
	test_2.print();
	cout << "Size list = " << test_2.size() << endl;
	test_2.resize(4);
	test_2[2] = 13;
	cout << "Insert 8 in list: ";
	if (test_2.insert(3, 8) == 1) {
		cout << "True" << endl;
	}
	else {
		cout << "False " << endl;
	}
	cout << "////// List after all operations: //////" << endl;
	test_2.print();
	cout << endl;

	cout << "List contains 7: ";
	if (test_2.contains(7) == 1) {
		cout << "True" << endl;
	}
	else {
		cout << "False " << endl;
	}
	cout << endl;

	cout << "Find 16: " << test_2.find(16) << endl;

	cout << "////// Copy //////" << endl;
	List test_3 = test_2;
	test_3.print();
	cout << endl;
	test_2.print();
	cout << endl;
	
	cout << "////// Assigment //////" << endl;
	test_1.print();
	cout << endl;
	test_2.print();
	test_1 = test_2;
	cout << endl;
	test_1.print();
	return 0;
}
