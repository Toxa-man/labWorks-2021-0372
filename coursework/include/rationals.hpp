#ifndef RATIONALS_HPP
#define RATIONALS_HPP
/*
* This class creates a new type of data <<fractions>> or rational numbers,
* Can add, dimiss, multiply and divide fractions as needed, the program Can
* understand this operators and does the operation without simplify the numbers
*/
#include <iostream>
#include <vector>

class rationals {
private:
  std::vector<int> m_duple = std::vector<int>(2, 0); // (a, b)

public:
  /**
  * The default contructor of the class rationals.
  */
  rationals () { };
  rationals (int a, int b);
  virtual ~rationals ();

  // Getters.
  std::vector<int> GetEquivClass() { return this->m_duple; };

  rationals operator+ (rationals b);
  rationals operator- (rationals b);
  rationals operator* (rationals b);
  rationals operator/ (rationals b);
  bool operator== (rationals b);
  bool operator!= (rationals b);
  bool operator>= (rationals b);
  bool operator<= (rationals b);
  bool operator< (rationals b);
  bool operator> (rationals b);
};

#endif // RATIONALS_HPP
