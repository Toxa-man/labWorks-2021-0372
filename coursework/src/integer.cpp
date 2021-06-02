#include "integer.hpp"

/**
* Constructor of the class integer creating the equivalence class.
* @param a first element of the equivalence class.
* @param b second element of the equivalence class.
*/
integer::integer (unsigned a, unsigned b) {
  // Create (0, 0)
  this->m_duple[0] = a;
  this->m_duple[1] = b;
}

/**
* Desctructor of the iteger class.
*/
integer::~integer () { std::cout << "Chao" << '\n'; }

/**
* Overload add operator.
*/
integer integer::operator+ (integer b) {
  // Get the equivalence class of b.
  std::vector<unsigned> b_equiv_class = b.GetEquivClass();

  integer c(
    this->m_duple[0] + b_equiv_class[0],
    this->m_duple[1] + b_equiv_class[1]
  );

  return c;

}

/**
* Overload add operator.
*/
integer integer::operator- (integer b) {
  // Get the equivalence class of b.
  std::vector<unsigned> b_equiv_class = b.GetEquivClass();

  integer c(
    this->m_duple[0] + b_equiv_class[1],
    this->m_duple[1] + b_equiv_class[0]
  );

  return c;

}


//
// integer.cpp ends here.
//
