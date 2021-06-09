#include <iostream>

using namespace std;
using T = int;

template<typename T>
class List
{
public:
	List();
	~List();

	List(unsigned size);
	List(unsigned size, const T& val);
	void resize(unsigned reSize);
	bool contains(const T& val);
	void pop_front();
	void clear();
	void push_back(T val);
	int find(const T& val);
	int GetSize() {	return Size;};
	void push_front(T val);
	bool insert(T val, unsigned pos);
	void pop_back();
	void removeAt(int index);
	T& operator[](unsigned index);

private:

	template<typename T>
	class Node
	{
	public:
		Node* pnext;
		T val;
		Node(T val = T(), Node* pnext = nullptr)
		{
			this->val = val;
			this->pnext = pnext;
		}
	};

	int Size;
	Node<T>* head;
};

template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
List<T>::List(unsigned size)
{
	Size = size;
	if (Size > 0)
	{
		head = new Node<T>{ 0, nullptr };
		Node<T>* temp = head;
		for (int i = 0; i < Size - 1; i++)
		{
			temp->pnext = new Node<T>{ 0, nullptr };
			temp = temp->pnext;
		}
	}
}

template<typename T>
List<T>::List(unsigned size, const T& val)
{
	Size = size;
	if (Size > 0)
	{
		head = new Node<T>{ val, nullptr };
		Node<T>* temp = head;
		for (int i = 0; i < Size - 1; i++)
		{
			temp->pnext = new Node<T>{ val, nullptr };
			temp = temp->pnext;
		}
	}
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->pnext;

	delete temp;
	Size--;
}

template<typename T>
void List<T>::resize(unsigned size)
{
	if (size > Size)
	{
		for (unsigned i = Size; i < size; i++) {
			push_back(0);
		}
	}
	else
		if (size < Size)
			for (unsigned i = Size; i > size; i--) {
				removeAt(Size - 1);
			}
}

template<typename T>
int List<T>::find(const T& val)
{
	Node<T>* temp = head;
	for (int i = 0; i < Size; i++)
	{
		if (temp->val == val)
			return i;
		temp = temp->pnext;
	}
	return -1;
}


template<typename T>
T& List<T>::operator[](unsigned index)
{
	int counter = 0;
	Node<T>* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->val;
		}
		current = current->pnext;
		counter++;
	}
}

template<typename T>
void List<T>::push_front(T val)
{
	head = new Node<T>(val, head);
	Size++;
}

template<typename T>
void List<T>::push_back(T val)
{
	if (head == nullptr)
	{
		head = new Node<T>(val);
	}
	else
	{
		Node<T>* current = this->head;

		while (current->pnext != nullptr)
		{
			current = current->pnext;
		}
		current->pnext = new Node<T>(val);
	}

	Size++;
}

template<typename T>
bool List<T>::contains(const T& val)
{
	if (this->find(val) == -1) {
		return false;
	}
	return true;
}

template<typename T>
bool List<T>::insert(T val, unsigned pos)
{
	if (pos == 0)
	{
		push_front(val);
	}
	else if (pos <= GetSize())
	{
		Node<T>* prev = this->head;

		for (int i = 0; i < pos - 1; i++)
		{
			prev = prev->pnext;
		}

		Node<T>* newNode = new Node<T>(val, prev->pnext);

		prev->pnext = newNode;

		Size++;

		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* prev = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			prev = prev->pnext;
		}

		Node<T>* toDelete = prev->pnext;

		prev->pnext = toDelete->pnext;

		delete toDelete;
		Size--;
	}
}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}

void printOut(List<int>& List)
{
	for (int i = 0; i < List.GetSize(); i++)
	{
		cout << List[i] << " ";
	}
	cout << endl;
}

int main() {
	List<int> list{10}; // 10 default value
	printOut(list);
	list.clear();
	List<int> list1{15, 7}; //list size 15 with val equal 7
	printOut(list1);
	list1.resize(6); //resize
	printOut(list1);
	cout << list1.GetSize() << endl; //list size
	list1.insert(4, 5); //resize
	printOut(list1);
	list1.push_back(1); //pushback
	printOut(list1);
	cout << list1.contains(0) << endl; //contains
	cout << list1.operator[](2) << endl; //operator
	cout << list1.find(7) << endl; //find
	return 0;
}
