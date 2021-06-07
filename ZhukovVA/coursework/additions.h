#include <math.h>
#include <iostream>
#include <random>
#include <time.h>
#include <sstream>
#include <Windows.h>
#include "aes.h"
#include "modes.h"
#include "hex.h"
#include "sha.h"
#pragma once

unsigned mod(int value, unsigned divisor);
int power(int a, int b, int k);
int legendre_symbol(int a, int p);
void ext_ea(int arg1, int arg2, int& x_new, int& y_new, int& gcd);
int inverse_of(int value, int p);
bool isPrime(int num);

std::string dec_to_hex(int);
inline int hex_to_int(char c);
void create_hash(std::string& text, std::string& digest);
std::string decode_hash(std::string& hash);
int mod_hash(std::string& msg, int modulo);
