/*Lab 1 Arevalo Parra Carlos Andres*/
#ifndef NODES_HPP
#define NODES_HPP

using T=int;

class nodes {
public:
  T data;
  nodes *next;
};

#endif // NODES_HPP
#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>

using T=int;

class list {
private:
  unsigned m_size;
  nodes *m_head;

public:
  //The all methods that includes the class
  list ();
  list (unsigned size);
  list (unsigned size, const T &val);
  virtual ~list ();
  unsigned size ();
  void resize (unsigned  nsize);
  T operator[] (unsigned index);
  void push_back(const T& val);
  bool contains(const T& val);
  int find(const T& val);
};

#endif // LIST_HPP
using T=int;

list::list () { }

list::list (unsigned size): m_size(size) {

  m_head = new nodes();

  // The m_head and the rest of elements of the list are initialized is the
  // size is greater than 0.
  if (size > 0) {

    // Set the value for m_head.
    m_head->data = T();

    // Set the m_head as the previous node.
    nodes *prev_node = m_head;

    // Fill the other elements of the list.
    for (unsigned i = 1; i < size; i++) {
      // Create the node.
      nodes *next_node = new nodes();

      // Initialize the node.
      next_node->data = T();

      // Connect the previous node with the next.
      prev_node->next = next_node;

      // Update the previous node.
      prev_node = next_node;
    }
    prev_node->next = nullptr;

  } else {
    m_head->next = nullptr;
  }

}

list::~list () { }

unsigned list::size () {
  // Go to the private object
  return m_size;
}

T list::operator[] (unsigned index) {
  nodes *asked_node = m_head;

  for (unsigned i = 0; i < index; i++) {
    asked_node = asked_node->next;
  }

  return asked_node->data;

}
void list::push_back(const T& val){

  nodes* m = m_head;

while (m->next) {

    m = m->next;
}

m->next = new nodes;

m->next->data = val;

m_size++;

}

void list::resize(int unsigned n_size) {

nodes* ptr = m_head;
//In this if statememt the program adds space for new elements
if (n_size < m_size) {

  nodes* tmp = nullptr;

  for (unsigned int i = 0; i < m_size; i++) {

    if (i >= n_size) {

      tmp = ptr-> next;

      delete ptr;

      ptr = tmp;

    }
    else{
      ptr = ptr->next;
    }
    }
  }// In this if stament choose how to resize the list with less elements
  else if (n_size > m_size) {

      for (unsigned int i = 0; i < n_size; i++) {

            if (i+1 >= m_size && i+1 != n_size)

            ptr->next = new nodes;

            ptr = ptr->next;
        }
    }
    m_size = n_size;
}
bool list::contains(const T& val) {

    nodes* ptr = m_head;

    for (unsigned int i = 0; i < m_size; i++) {

        if (ptr->data == val){

            return true;}
        else{
            ptr = ptr->next;}
    }
    return false;
}


int list::find(const T& val) {

    nodes* ptr = m_head;
//this cicle is for look for the position of the value we want
    for (unsigned int i = 0; i < m_size; i++) {


        if (ptr-> data == val){

            return i;}
        else{

            ptr = ptr->next;}
    }
    return -1;
}

int main(int argc, char const *argv[]) {

  list a = list(5);//example for a 5 elements size of the list

  std::cout << a[4] << '\n';

  std::cout << "Size: " << a.size() << '\n';

  return 0;
}
