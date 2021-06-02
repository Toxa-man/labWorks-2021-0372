#include <iostream>
#include "integer.hpp"

int main(int argc, char const *argv[]) {
  integer A(1, 2); // (a, b)
  integer B(3, 9); // (c, d)
  integer C = A + B;
  integer D = A - B;

  std::vector<unsigned> A_equiv_class = A.GetEquivClass();
  std::vector<unsigned> B_equiv_class = B.GetEquivClass();
  std::vector<unsigned> C_equiv_class = C.GetEquivClass();
  std::vector<unsigned> D_equiv_class = D.GetEquivClass();

  std::cout
  << "A: (" << A_equiv_class[0] << ", " << A_equiv_class[1] << ")" << '\n'
  << "B: (" << B_equiv_class[0] << ", " << B_equiv_class[1] << ")" << '\n'
  << "C: (" << C_equiv_class[0] << ", " << C_equiv_class[1] << ")" << '\n'
  << "D: (" << D_equiv_class[0] << ", " << D_equiv_class[1] << ")" << '\n';

  int a = -1;
  int b = -3;

  std::cout << "a: " << a << "\nb: " << b << "\na+b: " << a+b << '\n';

  return 0;
}
