#include <iostream>
#include <cstring>

using T = int;
class List {
public:
	List();
	List(unsigned size);
	List(unsigned size, const T& val);
	List(const List& list);
	void destructor();
	void pop_front();
	void push_back(const T& value);
	void push_front(T value);
	bool insert(unsigned pos, const T& val);
	bool contains(const T& val);
	void removeAt(unsigned index);
	int get_size() { return nsize; };
	void resize(unsigned re_size);
	T& operator[](unsigned index);
	int find(const T& value);
	List& operator=(const List& list);
private:
	class Node
	{
	public:
		Node* next;
		T value;

		Node(T value = T(), Node* next = nullptr)
		{
			this->value = value;
			this->next = next;
		}
	};
	Node* head;
	int nsize;
};

List::List() {
	nsize = 0;
	head = nullptr;
}

List::List(unsigned size) 
{
	nsize = size;
	if (nsize > 0) 
	{
		head = new Node{ 0, nullptr };
		Node* temporary_perm = head;
		for (int i = 0; i < nsize - 1; i++)
		{
			temporary_perm->next = new Node{ 0, nullptr};
			temporary_perm = temporary_perm->next;
		}
	}
}

List::List(unsigned size, const T& val)
{
	nsize = size;
	if (nsize > 0)
	{
		head = new Node{ val, nullptr };
		Node* temporary_perm = head;
		for (int i = 0; i < nsize - 1; i++)
		{
			temporary_perm->next = new Node{ val, nullptr };
			temporary_perm = temporary_perm->next;
		}
	}
}

List::List(const List& list)
{
	Node* temporary_perm = list.head;
	nsize = 0;
	for (int i = 0; i < list.nsize; i++)
	{
		insert(i, temporary_perm->value);
		temporary_perm = temporary_perm->next;
	}

}
void List::push_back(const T& value)
{
	if (head == nullptr)
	{
		head = new Node(value);
	}
	else
	{
		Node* temporary_perm = this->head;
		while (temporary_perm->next != nullptr)
		{
			temporary_perm = temporary_perm->next;
		}
		temporary_perm->next = new Node(value);
	}
	nsize++;
}


T& List::operator[](unsigned index)
{
	int counter = 0;
	Node* temporary_perm = this->head;
	while (temporary_perm != nullptr)
	{
		if (counter == index) {
			return temporary_perm->value;
		}
		temporary_perm = temporary_perm->next;
		counter++;
	}
}

void List::destructor()
{
	while (nsize > 0)
	{
		Node* temporary_perm = head;
		head = head->next;
		delete temporary_perm;
		nsize--;
	}
}


int List::find(const T& val)
{
	Node* temporary_perm = head;
	for (int i = 0; i < nsize; i++)
	{
		if (temporary_perm->value == val)
			return i;
		temporary_perm = temporary_perm->next;
	}
	return -1;
}

List& List::operator=(const List& list)
{
	Node* temporary_perm = list.head;
	resize(0);
	for (int i = 0; i < list.nsize; i++)
	{
		insert(i, temporary_perm->value);
		temporary_perm = temporary_perm->next;
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
			temporary_perm = temporary_perm->next;
		}
		temporary_perm->next = new Node(pos, temporary_perm->next);
		nsize++;
		return true;
	}
	else {
		return false;
	}
}

void List::push_front(T value)
{
	head = new Node(value, head);
	nsize++;
}

void List::pop_front()
{
	Node* temporary_perm = head;
	head = head->next;
	delete temporary_perm;
	nsize--;
}

void List::resize(unsigned re_size)
{
	if (re_size > nsize)
	{
		for (unsigned i = nsize; i < re_size; i++) {
			push_back(0);
		}
	}
	else 
		if (re_size < nsize)
			for (unsigned i = nsize; i > re_size; i--) {
				removeAt(nsize - 1);
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
			temporary_perm = temporary_perm->next;
		}
		Node* toDelete = temporary_perm->next;
		temporary_perm->next = toDelete->next;
		delete toDelete;
		nsize--;
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
	// TEST 1
	std::cout << " test 1 : Default constructor" << std::endl;
	List l1;
	std::cout << std::endl;
	// TEST 2
	std::cout << " test 2 : Related List with four elements" << std::endl;
	List l2{ 4 };
	print(l2);
	// TEST 3
	std::cout << " test 3 : Related List with five elements equal to six" << std::endl;
	List l3{ 5,6 };
	print(l3);
	// TEST 4
	std::cout << " test 4 : Number of elements" << std::endl;
	std::cout << l3.get_size() << std::endl;
	// TEST 5
	std::cout << " test 5 : Method resize" << std::endl;
	l3.resize(6);
	print(l3);
	//TEST 6
	std::cout << " test 6 : Method insert" << std::endl;
	std::cout << "Average:" << l3.insert(4, 3) << std::endl;
	print(l3);
	//TEST 7
	std::cout << " test 7 : Method push_back" << std::endl;
	l3.push_back(14);
	print(l3);
	//TEST 8
	std::cout << " test 8 : Method contains" << std::endl;
	std::cout << "Average:" << l3.contains(0) << std::endl;
	//TEST 9
	std::cout << " test 9 : operator" << std::endl;
	std::cout << "Average:" << l3.operator[](4) << std::endl;
	//TEST 10
	std::cout << " test 10 : Method find" << std::endl;
	std::cout << l3.find(4) << std::endl;
	//TEST 11
	std::cout << " test 11" << std::endl;
	l2.operator=(l3);
	print(l3);
	//TEST 12
	std::cout << " test 12 : Method destructor" << std::endl;
	l3.destructor();
	l2.destructor();
	l1.destructor();
	print(l3);
	print(l2);
	print(l1);
}
