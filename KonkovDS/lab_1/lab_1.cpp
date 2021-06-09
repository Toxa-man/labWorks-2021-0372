#include <iostream>

using T = int;

struct node {
	T value;
	node* next;
};

class list {
private:
	node* head;
	unsigned int listsize;

public:
	list(); // дефолтный конструктор //destructor
	list(const list& clist); //copy-constructor
	list(unsigned size); //создаёт список размером size и заполняет его дефолтными значениями, т.е. T()
	list(unsigned size, const T& val); //создаёт список размером size и заполняет его значением val

	void destructor(); //destructor
	unsigned size() const; //возвращает размер списока
	void resize(unsigned size); // приравнивает размера списока к size; если новый размер больше старого - новые элементы заполнить нулями
	void removeAt(unsigned index);
	bool insert(unsigned pos, const T& val); //вставляет val в позицию pos; возвращает true | false в зависимости от успеха операции
	void push_back(const T& val); //добавляет val в конец списока
	void pop_front();//удаляет первый элемент списка
	bool contains(const T& val); //возвращает true если val присуствует в списоке и false в противном случае
	T& operator [] (unsigned index); // обращение к элементу с индексом index. При этом должно быть возможно как читать значение, так и изменять его
	list& operator=(const list& clist); // assignment operator
	int find(const T& val); //возвращает индекс первого вхождения val в список или -1 в случае его отсутствия
};

list::list() {
	listsize = 0;
	head = nullptr;
}

list::list(const list& clist) {
	node* current = clist.head;
	for (int i = 0; i < clist.listsize; i++) {
		push_back(current->value);
		current = current->next;
	}
}

list::list(unsigned size) {
	listsize = size;
	head = new node{ 0,nullptr };
	node* current = head;
	for (int i = 0; i < listsize; i++) {
		current->next = new node{ 0,nullptr };
		current = current->next;
	}
}

list::list(unsigned size, const T& val) {
	listsize = size;
	head = new node{ val,nullptr };
	node* current = head;
	for (int i = 0; i < listsize; i++) {
		current->next = new node{ val,nullptr };
		current = current->next;
	}
}

void list::destructor()
{
	while (listsize > 0)
	{
		pop_front();
	}
}

unsigned list::size() const {
	return listsize;
}


void list::resize(unsigned size)
{
	if (size > listsize)
	{
		for (unsigned i = listsize; i < size; i++) {
			push_back(0);
		}
	}
	else
		if (size < listsize)
			for (unsigned i = listsize; i > size; i--) {
				removeAt(listsize - 1);
			}
}
void list::removeAt(unsigned index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		node* temp = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			temp = temp->next;
		}
		node* Delete = temp->next;
		temp->next = Delete->next;
		delete Delete;
		listsize--;
	}

}

bool list::insert(unsigned pos, const T& val) {
	if (pos > listsize || pos < 0)
		return false;
	if (pos == 0) {
		head = new node{ val, head };
		listsize++;
	}
	else {
		node* previous = this->head;
		for (int i = 0; i < pos - 1; i++)
			previous = previous->next;
		previous->next = new node{ val, previous->next };
		listsize++;
	}
	return true;
}

void list::push_back(const T& val) {
	if (head == nullptr)
		head = new node{ val, nullptr };
	else {
		node* current = head;
		for (int i = 0; i < listsize - 1; i++)
			current = current->next;
		current->next = new node{ val,nullptr };
	}
	listsize++;
}

void list::pop_front()
{
	node* temporary_perm = head;
	head = head->next;
	delete temporary_perm;
	listsize--;
}

bool list::contains(const T& val) {
	node* current = head;
	while (current->next != nullptr) {
		if (current->value == val)
			return true;
		current = current->next;
	}
	return false;
}


T& list::operator[](unsigned index) {
	int counter = 0;
	if (index < listsize) {
		node* current = head;
		while (current->next != nullptr) {
			if (counter == index)
				return current->value;
			current = current->next;
			counter++;
		}
	}
	else {
		std::cout << "wrong input" << std::endl;
		system("pause");
	}
}

list& list::operator=(const list& clist) {
	resize(0);
	node* current = clist.head;
	for (int i = 0; i < clist.listsize; i++) {
		push_back(current->value);
		current = current->next;
	}
	return *this;
}

int list::find(const T& val) {
	node* current = head;
	int index = 0;
	while (current->next != nullptr) {
		if (current->value == val)
			return index;
		index++;
		current = current->next;
	}
	return -1;
}

void print(list& list);

int main() {
	// TEST 1
	std::cout << " test 1 : Default constructor" << std::endl;
	list l1;
	std::cout << std::endl;
	// TEST 2
	std::cout << " test 2 : Related List with four elements" << std::endl;
	list l2{ 4 };
	print(l2);
	// TEST 3
	std::cout << " test 3 : Related List with five elements equal to six" << std::endl;
	list l3{ 5,6 };
	print(l3);
	// TEST 4
	std::cout << " test 4 : Number of elements" << std::endl;
	std::cout << l3.size() << std::endl;
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
	/*TEST 11
	std::cout << " test 11" << std::endl;
	l2.operator=(l3);
	print(l3);*/
	//TEST 12
	std::cout << " test 12 : Method destructor" << std::endl;
	l3.destructor();
	l2.destructor();
	l1.destructor();
	print(l3);
	print(l2);
	print(l1);

	return 0;
}
void print(list& list)
{
	for (int i = 0; i < list.size(); i++)
	{
		std::cout << list[i] << std::endl;
	}
}
