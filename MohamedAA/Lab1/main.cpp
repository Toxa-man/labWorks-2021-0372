#include <iostream>
#include <cstring>
using namespace std;
using T = int;

class List {
private:
	class Node
	{
	public:
		Node* pnext;
		T data;
	};
	Node* head;
	int size;
public:
	List();
	List(unsigned size);
	List(unsigned size, const T& val);
	List(const List& list);
	void destructor();
	void pop_front();
	void push_back(const T& data);
	void push_front(T value);
	bool insert(unsigned pos, const T& val);
	bool contains(const T& val);
	void removeAt(unsigned index);
	int get_size() { return size; };
	void resize(unsigned re_size);
	T& operator[](unsigned index);
	int find(const T& value);
	List& operator=(const List& list);

};

List::List() {
	size = 0;
	head = nullptr;
}

List::List(unsigned size)
{
	size = size;
	if (size > 0)
	{
		head = new Node{ 0, nullptr };
		Node* temporary_perm = head;
		for (int i = 0; i < size - 1; i++)
		{
			temporary_perm->pnext = new Node{ 0, nullptr };
			temporary_perm = temporary_perm->pnext;
		}
	}
}

List::List(unsigned size, const T& val)
{
	size = size;
	if (size > 0)
	{
		head = new Node{ val, nullptr };
		Node* temporary_perm = head;
		for (int i = 0; i < size - 1; i++)
		{
			temporary_perm->pnext = new Node{ val, nullptr };
			temporary_perm = temporary_perm->pnext;
		}
	}
}

List::List(const List& list)
{
	Node* temporary_perm = list.head;
	size = 0;
	for (int i = 0; i < list.size; i++)
	{
		insert(i, temporary_perm->data);
		temporary_perm = temporary_perm->pnext;
	}

}
void List::push_back(const T& data)
{
	if (head == nullptr)
	{
		head = new Node(data);
	}
	else
	{
		Node* temporary_perm = this->head;
		while (temporary_perm->pnext != nullptr)
		{
			temporary_perm = temporary_perm->pnext;
		}
		temporary_perm->pnext = new Node(data);
	}
	size++;
}


T& List::operator[](unsigned index)
{
	int counter = 0;
	Node* temporary_perm = this->head;
	while (temporary_perm != nullptr)
	{
		if (counter == index) {
			return temporary_perm->data;
		}
		temporary_perm = temporary_perm->pnext;
		counter++;
	}
}

void List::destructor()
{
	while (size > 0)
	{
		Node* temporary_perm = head;
		head = head->pnext;
		delete temporary_perm;
		size--;
	}
}


int List::find(const T& val)
{
	Node* temporary_perm = head;
	for (int i = 0; i < size; i++)
	{
		if (temporary_perm->data == val)
			return i;
		temporary_perm = temporary_perm->pnext;
	}
	return -1;
}

List& List::operator=(const List& list)
{
	Node* temporary_perm = list.head;
	resize(0);
	for (int i = 0; i < list.size; i++)
	{
		insert(i, temporary_perm->data);
		temporary_perm = temporary_perm->pnext;
	}
	return *this;
}


bool List::contains(const T& val)
{
	if (this->find(val) == -1) {
		return false;
	}
	return true;
}

bool List::insert(unsigned pos, const T& val)
{
	if (pos == 0)
	{
		push_front(val);
	}
	else if (pos <= get_size())
	{
		Node* temporary_perm = this->head;

		for (int i = 0; i < pos - 1; i++)
		{
			temporary_perm = temporary_perm->pnext;
		}
		temporary_perm->pnext = new Node(pos, temporary_perm->pnext);
		size++;
		return true;
	}
	else {
		return false;
	}
}

void List::push_front(T data)
{
	head = new Node(data, head);
	size++;
}

void List::pop_front()
{
	Node* temporary_perm = head;
	head = head->pnext;
	delete temporary_perm;
	size--;
}

void List::resize(unsigned re_size)
{
	if (re_size > size)
	{
		for (unsigned i = size; i < re_size; i++) {
			push_back(0);
		}
	}
	else
		if (re_size < size)
			for (unsigned i = size; i > re_size; i--) {
				removeAt(size - 1);
			}
}

void List::removeAt(unsigned index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node* temporary_perm = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			temporary_perm = temporary_perm->pnext;
		}
		Node* toDelete = temporary_perm->pnext;
		temporary_perm->pnext = toDelete->pnext;
		delete toDelete;
		size--;
	}

}

void print(List& List)
{
	for (int i = 0; i < List.get_size(); i++)
	{
		std::cout << List[i] << std::endl;
	}
}

int main()
{
cout << " test 1 : Default constructor" << endl;
	List l1;
	std::cout << std::endl;
	cout << " test 2 : Related List with four elements" << endl;
	List l2{ 4 };
	print(l2);
	cout << " test 3 : Related List with five elements equal to six" << endl;
	List l3{ 5,6 };
	print(l3);
	cout << " test 4 : Number of elements" << endl;
	cout << l3.get_size() << std::endl;
	std::cout << " test 5 : Method resize" << endl;
	l3.resize(6);
	print(l3);
	cout << " test 6 : Method insert" << endl;
	cout << "Average:" << l3.insert(4, 3) << endl;
	print(l3);
	cout << " test 7 : Method push_back" << endl;
	l3.push_back(14);
	print(l3);
	cout << " test 8 : Method contains" << endl;
	cout << "Average:" << l3.contains(0) << endl;
	cout << " test 9 : operator" << endl;
	cout << "Average:" << l3.operator[](4) << endl;
	cout << " test 10 : Method find" << endl;
	cout << l3.find(4) << endl;
	std::cout << " test 11" << endl;
	l2.operator=(l3);
	print(l3);
	std::cout << " test 12 : Method destructor" << std::endl;
	l3.destructor();
	l2.destructor();
	l1.destructor();
	print(l3);
	print(l2);
	print(l1);
}

