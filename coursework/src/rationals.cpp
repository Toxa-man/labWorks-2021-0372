#include "rationals.hpp"

/**
* Constructor of the class rationals creating the equivalence class.
* The main idea is that work with a kind of fraction, where the first
* element is the numerator and the second is the denominator
*/
rationals::rationals (int a, int b) {
  // Create (0, 0)
  this->m_duple[0] = a;
  this->m_duple[1] = b;
}

/**
* Overload add operator.
*/
rationals rationals::operator+ (rationals b) {
  // Get the equivalence class of b.
  std::vector<int> b_equiv_class = b.GetEquivClass();

  rationals c(
    (this->m_duple[0] * b_equiv_class[1])+(this->m_duple[1] * b_equiv_class[0]),
    this->m_duple[1] * b_equiv_class[1]
  );

  return c;

}

/**
* Overload minus operator.
*/
rationals rationals::operator- (rationals b) {
  // Get the equivalence class of b.
  std::vector<int> b_equiv_class = b.GetEquivClass();

  rationals c(
    (this->m_duple[0] * b_equiv_class[1])-(this->m_duple[1] * b_equiv_class[0]),
    this->m_duple[1] * b_equiv_class[1]
  );

  return c;

}
/**
* Overload multiplication operator.
*/
rationals rationals::operator* (rationals b){
  //Get the equivalence class of b.
  std::vector<int> b_equiv_class= b.GetEquivClass();

  rationals c(
    this->m_duple[0] * b_equiv_class[0],
    this->m_duple[1] * b_equiv_class[1]
  );
  return c;
}
/**
* Overload division operator.
*/
rationals rationals::operator/ (rationals b){
  //Get the equivalence class of b.
  std::vector<int> b_equiv_class= b.GetEquivClass();

  rationals c(
    this->m_duple[0] * b_equiv_class[1],
    this->m_duple[1] * b_equiv_class[0]
  );
  return c;
}
/**
* Overload equal operator.
*/
bool rationals::operator== (rationals b){
  //Get the equivalence class of b.
  std::vector<int> b_equiv_class= b.GetEquivClass();

  rationals c(
    this->m_duple[0] * b_equiv_class[1],
    this->m_duple[1] * b_equiv_class[0]
  );

  std::vector<int> c_equiv_class=c.GetEquivClass();

  if(c_equiv_class[0] == c_equiv_class[1]){

    std::cout << "Fractions are equal" << '\n';
    return 1;
  }
  else{
    std::cout << "Fractions are not equal" << '\n';
    return 0;
  }
}
/**
* Overload different operator.
*/
bool rationals::operator!= (rationals b){
  //Get the equivalence class of b.
  std::vector<int> b_equiv_class= b.GetEquivClass();

  rationals c(
    this->m_duple[0] * b_equiv_class[1],
    this->m_duple[1] * b_equiv_class[0]
  );

  std::vector<int> c_equiv_class=c.GetEquivClass();

  if(c_equiv_class[0] != c_equiv_class[1]){

    std::cout << "Fractions are different" << '\n';
    return 1;
  }
  else{
    std::cout << "Fractions are not different" << '\n';
    return 0;
  }
}
/**
* Overload bigger or equal operator.
*/
bool rationals::operator>= (rationals b){
  //Get the equivalence class of b.
  std::vector<int> b_equiv_class= b.GetEquivClass();

  rationals c(
    this->m_duple[0] * b_equiv_class[1],
    this->m_duple[1] * b_equiv_class[0]
  );

  std::vector<int> c_equiv_class=c.GetEquivClass();

  if(c_equiv_class[0] >= c_equiv_class[1]){

    std::cout << "Fraction A are bigger or the same that B" << '\n';
    return 1;
  }
  else{
    std::cout << "Fraction B are bigger than A" << '\n';
    return 0;
  }
}
/**
* Overload smaller or equal operator.
*/
bool rationals::operator<= (rationals b){
  //Get the equivalence class of b.
  std::vector<int> b_equiv_class= b.GetEquivClass();

  rationals c(
    this->m_duple[0] * b_equiv_class[1],
    this->m_duple[1] * b_equiv_class[0]
  );

  std::vector<int> c_equiv_class=c.GetEquivClass();

  if(c_equiv_class[0] <= c_equiv_class[1]){

    std::cout << "Fraction A are smaller or the same that B" << '\n';
    return 1;
  }
  else{
    std::cout << "Fraction B are smaller than A" << '\n';
    return 0;
  }
}
/**
* Overload bigger than operator.
*/
bool rationals::operator< (rationals b){
  //Get the equivalence class of b.
  std::vector<int> b_equiv_class= b.GetEquivClass();

  rationals c(
    this->m_duple[0] * b_equiv_class[1],
    this->m_duple[1] * b_equiv_class[0]
  );

  std::vector<int> c_equiv_class=c.GetEquivClass();

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
bool rationals::operator> (rationals b){
  //Get the equivalence class of b.
  std::vector<int> b_equiv_class= b.GetEquivClass();

  rationals c(
    this->m_duple[0] * b_equiv_class[1],
    this->m_duple[1] * b_equiv_class[0]
  );

  std::vector<int> c_equiv_class=c.GetEquivClass();

  if(c_equiv_class[0] > c_equiv_class[1]){
    std::cout << "A > B:True" << '\n';
    return 1;
  }
  else{
    std::cout << "A > B:False" << '\n';
    return 0;
  }
}
/**
* Desctructor of the iteger class.
*/
rationals::~rationals () {}
//
// rationals.cpp ends here.
//
