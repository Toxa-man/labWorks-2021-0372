#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "integer.hpp"
#include "rationals.hpp"

void im_integers ();

void im_rationals ();

int main(int argc, char const *argv[]) {
  srand (time(NULL));

  im_integers ();

  im_rationals ();

  return 0;
}
void im_integers (){
// Here starts the implementation of the class integer with the use of random
// numbers

  integer A(rand()% 10+1, rand()% 10+1); // (a, b)
  integer B(rand()% 10+1, rand()% 10+1); // (c, d)
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
}

void im_rationals (){
// Here starts the implementation of the class rationals with the use of random
// numbers

  rationals AA(rand()% 10+1, rand()% 10+1); // (a, b)
  rationals BB(rand()% 10+1, rand()% 10+1); // (c, d)
  rationals CC = AA + BB;
  rationals DD = AA - BB;
  rationals EE = AA * BB;
  rationals FF = AA / BB;
  bool GG = AA == BB;
  bool HH = AA != BB;
  bool II = AA >= BB;
  bool JJ = AA <= BB;
  bool KK = AA > BB;
  bool LL = AA < BB;

  std::vector<int> AA_equiv_class = AA.GetEquivClass();
  std::vector<int> BB_equiv_class = BB.GetEquivClass();
  std::vector<int> CC_equiv_class = CC.GetEquivClass();
  std::vector<int> DD_equiv_class = DD.GetEquivClass();
  std::vector<int> EE_equiv_class = EE.GetEquivClass();
  std::vector<int> FF_equiv_class = FF.GetEquivClass();


  std::cout
  << "AA: (" << AA_equiv_class[0] << ", " << AA_equiv_class[1] << ")" << '\n'
  << "BB: (" << BB_equiv_class[0] << ", " << BB_equiv_class[1] << ")" << '\n'
  << "CC: (" << CC_equiv_class[0] << ", " << CC_equiv_class[1] << ")" << '\n'
  << "DD: (" << DD_equiv_class[0] << ", " << DD_equiv_class[1] << ")" << '\n'
  << "EE: (" << EE_equiv_class[0] << ", " << EE_equiv_class[1] << ")" << '\n'
  << "FF: (" << FF_equiv_class[0] << ", " << FF_equiv_class[1] << ")" << '\n';
  }
