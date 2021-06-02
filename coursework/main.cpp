#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "integer.hpp"

int main(int argc, char const *argv[]) {
  srand (time(NULL));

  integer A(rand()% 5+1, rand()% 5+1); // (a, b)
  integer B(rand()% 5+1, rand()% 5+1); // (c, d)
  integer C = A + B;
  integer D = A - B;
  bool E = A == B;
  bool F = A != B;
  bool G = A >= B;
  bool H = A <= B;
  bool I = A > B;
  bool J = A < B;

  std::vector<unsigned> A_equiv_class = A.GetEquivClass();
  std::vector<unsigned> B_equiv_class = B.GetEquivClass();
  std::vector<unsigned> C_equiv_class = C.GetEquivClass();
  std::vector<unsigned> D_equiv_class = D.GetEquivClass();


  std::cout
  << "A: (" << A_equiv_class[0] << ", " << A_equiv_class[1] << ")" << '\n'
  << "B: (" << B_equiv_class[0] << ", " << B_equiv_class[1] << ")" << '\n'
  << "C: (" << C_equiv_class[0] << ", " << C_equiv_class[1] << ")" << '\n'
  << "D: (" << D_equiv_class[0] << ", " << D_equiv_class[1] << ")" << '\n';
  return 0;
}
