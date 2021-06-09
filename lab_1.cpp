#include <iostream>
#include <cstring>


using T = int;
class List {
public:
	List(); 
	List(unsigned size); 
	List(unsigned size, const T& val);
	List(const List& list);
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
			temporary_perm->next = new Node{ 0, nullptr };
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

List::~List() {
	resize(0);
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
	setlocale(0, "rus");
	// Тест 1
	std::cout << " Тест 1: дефолтный конструктор" << std::endl;
	List l1;
	std::cout << std::endl;
	// Тест 2
	std::cout << " Тест 2: заполним список дефолтными значениями" << std::endl;
	List l2{ 4 };
	print(l2);
	// Tест 3
	std::cout << " Тест 3: заполним список 5-ю элементами, равными 6-ти" << std::endl;
	List l3{ 5,6 };
	print(l3);
	// Тест 4
	std::cout << " Тест 4: кол-во элементов в списке" << std::endl;
	std::cout << l3.get_size() << std::endl;
	// Тест 5
	std::cout << " Тест 5: метод resize " << std::endl;
	l3.resize(6);
	print(l3);
	//Тест 6
	std::cout << " Тест 6: добавим число 4 на 4 позицию в списке " << std::endl;
	std::cout << "Успех:" << l3.insert(4, 4) << std::endl;
	print(l3);
	//Тест 7
	std::cout << " Тест 7: вставим в конец списка число 14" << std::endl;
	l3.push_back(14);
	print(l3);
	//Тест 8
	std::cout << " Тест 8: если число 0 присутсвует в списке - успех " << std::endl;
	std::cout << "Успех:" << l3.contains(0) << std::endl;
	//Тест 9
	std::cout << " Тест 9: вывод 6-го числа в списке " << std::endl;
	std::cout << "Число:" << l3.operator[](6) << std::endl;
	//Тест 10
	std::cout << " Тест 10: вывод индекса заданного числа(14) в списке" << std::endl;
	std::cout << " Индекс числа:";
	std::cout << l3.find(14) << std::endl;
	//Тест 11
	std::cout << " Тест 11: вывод обработанного списка: " << std::endl;
	l2.operator=(l3);
	print(l3);
	//Тест 12
	std::cout << " Тест 12: очистка списка" << std::endl;
	l3.resize(0); 
	l2.resize(0);
	l1.resize(0);
	print(l3);
	print(l2);
	print(l1);
}
