#pragma once
#include <string>
#include "sha.h"

/// <summary>
/// Class implementation of AES cryptography.
/// </summary>
class AES {
public:
  void SetParams(std::string, int);
  ~AES() {
    delete[] key;
  }

  void encrypt(std::string&, std::string&);
  void decrypt(std::string&, std::string&);
  std::string decode_cipher(std::string&);

private:
  byte* key;
  int keyLength;
};

/// <summary>
/// Class that describes points on elliptic curves.
/// </summary>
struct Point {
  Point() : x(0), y(0) {};
  Point(int x, int y) : x(x), y(y) {}

  bool is_inf() const {
    return (x == 0 && y == 0);
  }

  int operator[](const int i) const {
    return (i == 0) ? x : y;
  }

  int& operator[](const int i) {
    return (i == 0) ? x : y;
  }

private:
  int x, y;
};

/// <summary>
/// General class that describes everything related to elliptic curves on finite fields.
/// </summary>
struct Domain {
  void SetParams(int, int, int, int);

  Point add_points(Point&, Point&);
  bool is_on_curve(Point&);
  Point scalar_mult(Point&, int);
  int find_cofactor(Point&);
  bool generate_basepoint();
  bool set_basepoint(int, int, int);

  struct Curve {
    int a, b;
  };
  Curve curve;
  Point base_point;
  int modulo;
  int cardinality;
  int cofactor;
  int max_cofactor;
};

class User {
public:
  Point public_key = { 0, 0 };
  Domain* domain = nullptr;

  User(std::string n, Domain* d) {
    name = n;
    domain = d;
  }
  void generate_keys();
  void create_shared_key(Point);
  void sign_message(std::string&, std::string&, int ,int);
  void create_signature(std::string&);
  bool check_signature(Point&, std::string&, std::string&);
  int get_privatekey() const {
      return private_key;
  }
  void get_signature(int& r, int& s) const {
    r = signature.r;
    s = signature.s;
  }
  Point get_sharedkey() const {
    return shared_key;
  }

private:
  struct Signature {
    int r, s;
  };

  std::string name;
  int private_key = 0;
  Point shared_key = { 0, 0 };
  Signature signature = { 0, 0 };
};
