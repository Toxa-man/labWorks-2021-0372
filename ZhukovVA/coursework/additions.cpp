#include "additions.h"

//Properly working modulo function.
unsigned mod(int value, unsigned divisor) {
	int modulo = value % (int)divisor;
	if (modulo < 0) {
		modulo += divisor;
	}
	return modulo;
}

//Optimised implementation of the modular exponentiation.
int power(int a, int b, int k) {
	int result = 1;
	while (b--) {
		result *= a;
		result = mod(result, k);
	}
	return result;
}

//Returns a Legendre symbol.
int legendre_symbol(int a, int p) {
	int r = power(a, round((p - 1) / 2), p);
	if (r) {
		return r == 1 ? 1 : -1;
	}
	return 0;
}

//Solves equations like arg1*x + arg2*y = gcd(a, b)
void ext_ea(int arg1, int arg2, int& x_new, int& y_new, int& gcd) {
	int old_arg1;
	std::pair<int, int> x(1, 0), y(0, 1);

	while (arg2) {
		old_arg1 = arg1;
		arg1 = arg2;
		arg2 = mod(old_arg1, arg2);
		x = std::make_pair(x.second, x.first - x.second * (old_arg1 / arg1));
		y = std::make_pair(y.second, y.first - y.second * (old_arg1 / arg1));
	}

	x_new = x.first, y_new = y.first, gcd = arg1;
}

//Returns a modular inverse of a number.
int inverse_of(int value, int p) {
	int x, y, gcd;
	if (value == 0) exit(1);

	ext_ea(value, p, x, y, gcd);

	if (gcd != 1 || mod((value * x), p) != gcd) {
		exit(1);
	}

	return mod(x, p);
}

//Creates a hash from text.
void create_hash(std::string& text, std::string& digest) {
  CryptoPP::SHA1 hash;
  hash.Update((const byte*)text.data(), text.size());
  digest.resize(hash.DigestSize()/2);
  hash.TruncatedFinal((byte*)&digest[0], digest.size());
}

//Decodes a hash so it can be read.
std::string decode_hash(std::string& hash) {
  std::string decoded;
  CryptoPP::HexEncoder encoder(new CryptoPP::StringSink(decoded));
  CryptoPP::StringSource(hash, true, new CryptoPP::Redirector(encoder));
  return decoded;
}

//Converts a hexadecimal character to decimal integer.
inline int hex_to_int(char c) {
  return (c >= 'A') ? (c - 'A' + 10) : (c - '0');
}

//Converts a decimal integer to string of hexadecimal symbols.
std::string dec_to_hex(int dec) {
	std::stringstream ss;
	ss << std::hex << dec;
	std::string res(ss.str());
	return res;
}

//Returns modulo hash.
int mod_hash(std::string& msg, int modulo) {
  int hashMod = 0;
  std::string hash, dHash;
  create_hash(msg, hash);
  dHash = decode_hash(hash);
    
  for (int i = 0; i < dHash.size(); i++) {
    hashMod += power(16, i, modulo) * hex_to_int(dHash[dHash.size() - i - 1]);
  }

  return hashMod%modulo;
}

//Checks whether a number is prime or not.
bool isPrime(int num) {
  if (num <= 3) {
    return num > 1;
  }
  else if (num % 2 == 0 || num % 3 == 0) {
    return false;
  }
  else {
    for (int i = 5; i * i <= num; i += 6) {
      if (num % i == 0 || num % (i + 2) == 0) {
        return false;
      }
    }
    return true;
  }
}
