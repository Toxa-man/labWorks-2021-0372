#include <iostream>
#include <string>

using T = int;

struct Node {
	T value;
	Node* next;
};

class List {
	Node* head;
	T size_of_list;


public:
	List();
	List(unsigned size);
	List(unsigned size, const T& val);

	unsigned size();
	void resize(unsigned size);
	bool insert(unsigned pos, const T& val);
	void push_back(const T& val);
	bool contains(const T& val);
	T& operator [](unsigned index);
	int find(const T& val);
	void print();
	~List();

};


List::List() : head(nullptr) {
	size_of_list = 0;

}


List::List(unsigned size) {
	size_of_list = size;
	if (size_of_list > 0) {
		head = new Node{ 0, nullptr };
		Node* tmp = head;
		for (int i = 0; i <= size_of_list; i++) {
			tmp->next = new Node{ 0, nullptr };
			tmp = tmp->next;
		}
	}
}


List::List(unsigned size, const T& val) {
	size_of_list = size;
	if (size_of_list > 0) {
		head = new Node{ val, nullptr };
		Node* tmp = head;
		for (int i = 0; i <= size_of_list; i++) {
			tmp->next = new Node{ val, nullptr };
			tmp = tmp->next;
		}
	}
}


unsigned List::size() {
	return size_of_list;
}


void List::resize(unsigned new_size) {
	if (size_of_list < new_size) {

		if (size_of_list == 0) {
			head = new Node{ 0, nullptr };
			size_of_list++;
		}

		Node* tmp = head;
		for (int i = 1; i < size_of_list; i++) {
			tmp = tmp->next;
		}
		for (int i = size_of_list; i < new_size; i++) {
			tmp->next = new Node{ 0, nullptr };
			tmp = tmp->next;
		}
		size_of_list = new_size;
	}


	else if (size_of_list > new_size) {
		Node* tmp = head;
		Node* next_tmp = nullptr;
		for (int i = 0; i < new_size; i++) {
			tmp = tmp->next;
		}
		for (int i = new_size; i < size_of_list; i++) {
			next_tmp = tmp->next;
			delete tmp;
			tmp = next_tmp;
		}
		size_of_list = new_size;
	}
}


bool List::insert(unsigned pos, const T& val) {
	if (pos < 0 || pos > size_of_list) {
		return false;
	}
	else {
		Node* tmp = head;
		Node* next_tmp = nullptr;
		Node* insert_val = new Node{ val, nullptr };

		for (int i = 1; i < pos; i++) {
			tmp = tmp->next;
		}

		if (pos == 0) {
			head = insert_val;
			head->next = tmp;
		}
		else {
			next_tmp = tmp->next;
			tmp->next = insert_val;
			insert_val->next = next_tmp;
		}

		size_of_list++;
		return true;
	}
}


void List::push_back(const T& val) {
	insert(size_of_list, val);
}


int List::find(const T& val) {
	Node* tmp = head;
	T inx = -1;
	for (int i = 0; i < size_of_list; i++) {
		if (tmp->value == val) {
			inx = i;
		}
		tmp = tmp->next;
	}
	return inx;
}


bool List::contains(const T& val) {
	if (this->find(val) == -1)
		return false;
	return true;
}

void List::print() {
	Node* tmp = head;
	for (int i = 0; i < size_of_list; i++) {
		std::cout << tmp->value << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;
}


T& List::operator[](unsigned index) {
	if (index < 0 || index > size_of_list) {
		throw std::runtime_error("Error: Index is out of range.");
	}
	Node* tmp = head;
	for (int i = 0; i < index; i++) {
		tmp = tmp->next;
	}
	return tmp->value;
}


List::~List() {
	resize(0);
}




int main() {
	std::cout << "creates a list of size (size) and fills it with default values\n";
	List list1{ 6 };
	list1.print();

	std::cout << "\ncreates a list of size (size) and fills it with (Val) \n";
	List list2{ 4,3 };
	list2.print();

	std::cout << "\nreturns the size of the list \n";
	list1.print();
	std::cout << "size = " << list1.size() << std::endl;

	std::cout << "\nresize the size of the list\n";
	list2.resize(10);
	list2.print();

	std::cout << "\nnserts (val) at position (pos) returns true | false depending on the success of the operation\n";
	std::cout << list2.insert(6, 10) << std::endl;
	list2.print();

	std::cout << "\nadd (val) to the end of the list \n";
	list2.push_back(1);
	list2.print();

	std::cout << "\nreturns true if (val) is present in the list and false otherwise\n";
	list2.print();
	if (list2.contains(10)) {
		std::cout << "true" << std::endl;
	}
	else
	{
		std::cout << "false" << std::endl;
	}

	std::cout << "\naccess to the element with index and change it\n";
	std::cout << "list2[0] : " << list2[0] << std::endl;
	list2[0] = 10;
	std::cout << "list2[0] = 10  " << std::endl;
	std::cout << "list2[0] : " << list2[0] << std::endl;

	std::cout << "\nreturns the index of the last occurrence of (val) in the list or -1 if it is absent\n";
	list2.print();
	std::cout << list2.find(10) << std::endl;

	list1.~List();
	list2.~List();

	return 0;
}