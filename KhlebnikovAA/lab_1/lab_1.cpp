#include <iostream>
#include <cstring>

using T = int;

class List {
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
	int Node_size;
public:
	List();
	List(unsigned size);
	List(unsigned size, const T& val);
	int get_size();
	void resize(unsigned size);
	void push_back(const T& value);
	void delete_back(unsigned index);
	void delete_front();
	bool insert(unsigned pos, const T& val);
	void push_front(T value);
	bool contains(const T& val);
	int find(const T& val);
	T& operator[](unsigned index);
	void destructor();
	List& operator=(const List& list);
};

List::List(){
	Node_size = 0;
	head = nullptr;
}

List::List(unsigned size){
	Node_size = size;
	if (size > 1) {
		head = new Node{ 0, nullptr };
		Node* temporary_perm = head;
		for (int i = 0; i < Node_size - 1; i++)
		{
			temporary_perm->next = new Node{ 0, nullptr };
			temporary_perm = temporary_perm->next;
		}
	}
}

List::List(unsigned size, const T& val){
	Node_size = size;
	if (Node_size > 1) {
		head = new Node{val, nullptr};
		Node* temporary_perm = head;
		for (int i = 0; i < Node_size - 1; i++) {
			temporary_perm->next = new Node{ 0, nullptr };
			temporary_perm = temporary_perm->next;
		}
	}
}

int List::get_size() { return Node_size; };

void List::resize(unsigned size)
{
	if (size > Node_size) {
		for (int i = Node_size; i < size; i++) {
			push_back(0);
		}
	}
	else
		if (size < Node_size)
			for (unsigned i = Node_size; i > size; i--) {
				delete_back(Node_size - 1);
			}
}

void List::push_back(const T& value){
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
	Node_size++;
}

void List::delete_back(unsigned index){
	if (index == 0)
	{
		delete_front();
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
		Node_size--;
	}
}

void List::delete_front()
{
	Node* temporary_perm = head;
	head = head->next;
	delete temporary_perm;
	Node_size--;
}

bool List::insert(unsigned pos, const T& val){
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
		Node_size++;
		return true;
	}
	else {
		return false;
	}
}

void List::push_front(T value){
	head = new Node(value, head);
	Node_size++;
}

bool List::contains(const T& val)
{
	if (this->find(val) == -1) {
		return false;
	}
	return true;
}

int List::find(const T& val){
	Node* temporary_perm = head;
	for (int i = 0; i < Node_size; i++)
	{
		if (temporary_perm->value == val)
			return i;
		temporary_perm = temporary_perm->next;
	}
	return -1;
}

T& List::operator[](unsigned index) {
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

void List::destructor(){
	while (Node_size > 0)
	{
		Node* temporary_perm = head;
		head = head->next;
		delete temporary_perm;
		Node_size--;
	}
}

List& List::operator=(const List& list){
	Node* temporary_perm = list.head;
	resize(0);
	for (int i = 0; i < list.Node_size; i++)
	{
		insert(i, temporary_perm->value);
		temporary_perm = temporary_perm->next;
	}
	return *this;
}

void print(List& List){
	for (int i = 0; i < List.get_size(); i++)
	{
		std::cout << List[i] << std::endl;
	}
}

int main() {	
	setlocale(LC_ALL, "rus");
	std::cout << " Тест 1: конструктор по умолчанию" << std::endl;
	List l1;
	std::cout << std::endl;
	std::cout << " Тест 2: Связанный список с четырьмя элементами" << std::endl;
	List l2{ 4 };
	print(l2);
	std::cout << " Тест 3: Связанный список с пятью элементами, равным шести" << std::endl;
	List l3{ 5,6 };
	print(l3);
	std::cout << " Тест 4: Количество элементов" << std::endl;
	std::cout << l3.get_size() << std::endl;
	std::cout << " Тест 5: метод изменения размера" << std::endl;
	l3.resize(6);
	print(l3);
	std::cout << " Тест 6: Вставка метода" << std::endl;
	std::cout << "Вставить в позицию тройку в четвертую позицию:" << l3.insert(4, 3) << std::endl;
	print(l3);
	std::cout << " Тест 7 : Метод push_back" << std::endl;
	l3.push_back(14);
	print(l3);
	std::cout << " Тест 8 : Метод contains" << std::endl;
	std::cout << "Результат:" << l3.contains(0) << std::endl;
	std::cout << " Тест 9 : operator" << std::endl;
	std::cout << "Результат:" << l3.operator[](4) << std::endl;
	std::cout << " Тест 10 : Метод find" << std::endl;
	std::cout << l3.find(4) << std::endl;
	std::cout << " Тест 11" << std::endl;
	l2.operator=(l3);
	print(l3);
	std::cout << " Тест 12 : Метод destructor" << std::endl;
	l3.destructor();
	l2.destructor();
	l1.destructor();
	print(l3);
	print(l2);
	print(l1);
}