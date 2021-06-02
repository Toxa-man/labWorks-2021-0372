#ifndef INTERGER_HPP
#define INTERGER_HPP

#include <iostream>
#include <vector>

class integer {
private:
  std::vector<unsigned> m_duple = std::vector<unsigned>(2, 0); // (a, b)

public:
  /**
  * The default contructor of the class integer.
  */
  integer () { };
  integer (unsigned a, unsigned b);
  virtual ~integer ();

  // Getters.
  std::vector<unsigned> GetEquivClass() { return this->m_duple; };

  integer operator+ (integer b);
  integer operator- (integer b);
  integer operator* (integer b);
  bool operator== (integer b);
  bool operator!= (integer b);
  bool operator>= (integer b);
  bool operator<= (integer b);
  bool operator< (integer b);
  bool operator> (integer b);
};

#endif // INTERGER_HPP
