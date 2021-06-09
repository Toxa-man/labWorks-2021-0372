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
integer::~integer () {}

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
/**
* Overload multiplication operator.
*/
integer integer::operator* (integer b){
  //Get the equivalence class of b.
  std::vector<unsigned> b_equiv_class= b.GetEquivClass();

  integer c(
    this->m_duple[0]*b_equiv_class[0]+this->m_duple[1]*b_equiv_class[1],
    this->m_duple[0]*b_equiv_class[1]+this->m_duple[0]*b_equiv_class[1]
  );
  return c;
}
/**
* Overload equal operator.
*/
bool integer::operator== (integer b){
  //Get the equivalence class of b.
  std::vector<unsigned> b_equiv_class= b.GetEquivClass();

  integer c(
    this->m_duple[0] + b_equiv_class[1],
    this->m_duple[1] + b_equiv_class[0]
  );

  std::vector<unsigned> c_equiv_class=c.GetEquivClass();

  if(c_equiv_class[0] == c_equiv_class[1]){

    std::cout << "Equivalence classes are equal" << '\n';
    return 1;
  }
  else{
    std::cout << "Equivalence classes are not equal" << '\n';
    return 0;
  }
}
/**
* Overload different operator.
*/
bool integer::operator!= (integer b){
  //Get the equivalence class of b.
  std::vector<unsigned> b_equiv_class= b.GetEquivClass();

  integer c(
    this->m_duple[0] + b_equiv_class[1],
    this->m_duple[1] + b_equiv_class[0]
  );

  std::vector<unsigned> c_equiv_class=c.GetEquivClass();

  if(c_equiv_class[0] != c_equiv_class[1]){

    std::cout << "Equivalence classes are different" << '\n';
    return 1;
  }
  else{
    std::cout << "Equivalence classes are not different" << '\n';
    return 0;
  }
}
/**
* Overload bigger or equal operator.
*/
bool integer::operator>= (integer b){
  //Get the equivalence class of b.
  std::vector<unsigned> b_equiv_class= b.GetEquivClass();

  integer c(
    this->m_duple[0] + b_equiv_class[1],
    this->m_duple[1] + b_equiv_class[0]
  );

  std::vector<unsigned> c_equiv_class=c.GetEquivClass();

  if(c_equiv_class[0] >= c_equiv_class[1]){

    std::cout << "Equivalence class A are bigger or the same that B" << '\n';
    return 1;
  }
  else{
    std::cout << "Equivalence class B are bigger than A" << '\n';
    return 0;
  }
}
/**
* Overload smaller or equal operator.
*/
bool integer::operator<= (integer b){
  //Get the equivalence class of b.
  std::vector<unsigned> b_equiv_class= b.GetEquivClass();

  integer c(
    this->m_duple[0] + b_equiv_class[1],
    this->m_duple[1] + b_equiv_class[0]
  );

  std::vector<unsigned> c_equiv_class=c.GetEquivClass();

  if(c_equiv_class[0] <= c_equiv_class[1]){

    std::cout << "Equivalence class A are smaller or the same that B" << '\n';
    return 1;
  }
  else{
    std::cout << "Equivalence class B are smaller than A" << '\n';
    return 0;
  }
}
/**
* Overload bigger than operator.
*/
bool integer::operator< (integer b){
  //Get the equivalence class of b.
  std::vector<unsigned> b_equiv_class= b.GetEquivClass();

  integer c(
    this->m_duple[0] + b_equiv_class[1],
    this->m_duple[1] + b_equiv_class[0]
  );

  std::vector<unsigned> c_equiv_class=c.GetEquivClass();

  if(c_equiv_class[0] < c_equiv_class[1]){
      std::cout << "A < B:True" << '\n';
    return 1;
  }
  else{
    std::cout << "A < B:False" << '\n';
    return 0;
  }
}
/**
* Overload smaller than operator.
*/
bool integer::operator> (integer b){
  //Get the equivalence class of b.
  std::vector<unsigned> b_equiv_class= b.GetEquivClass();

  integer c(
    this->m_duple[0] + b_equiv_class[1],
    this->m_duple[1] + b_equiv_class[0]
  );

  std::vector<unsigned> c_equiv_class=c.GetEquivClass();

  if(c_equiv_class[0] > c_equiv_class[1]){
    std::cout << "A > B:True" << '\n';
    return 1;
  }
  else{
    std::cout << "A > B:False" << '\n';
    return 0;
  }
}
//
// integer.cpp ends here.
//
