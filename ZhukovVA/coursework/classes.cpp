#include "additions.h"	//Additional functions including libs
#include "classes.h"

//Instructions for random functions.
std::random_device dev;
std::mt19937 rng(dev());

/// <summary>
/// Default constructor of the AES class.
/// </summary>
/// <param name="sKey">Key in string format</param>
/// <param name="length">Length of the generated key to encrypt data</param>
void AES::SetParams(std::string sKey, int length) {
    sKey += std::string(length - sKey.length(), '*');
    key = new byte[length];
    keyLength = length;
    memcpy(key, sKey.c_str(), length);
}

/// <summary>
/// Encrypts text data with AES ECB algorithm.
/// </summary>
/// <param name="plain">Original plain text to cipher</param>
/// <returns>Ciphered text</returns>
void AES::encrypt(std::string& plain, std::string& cipher) {
    CryptoPP::ECB_Mode<CryptoPP::AES>::Encryption ecbEncryption;
    ecbEncryption.SetKey(key, keyLength);

    try
    {
        CryptoPP::StringSource(plain, true,
            new CryptoPP::StreamTransformationFilter(ecbEncryption,
                new CryptoPP::StringSink(cipher)
            )
        );
    }
    catch (CryptoPP::Exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

/// <summary>
/// Decrypts AES ECB ciphered text.
/// </summary>
/// <param name="cipher">Ciphered text</param>
/// <returns>Recovered text</returns>
void AES::decrypt(std::string& cipher, std::string& recovered) {
    try
    {
        CryptoPP::ECB_Mode< CryptoPP::AES >::Decryption ecbDecryption;
        ecbDecryption.SetKey(key, keyLength);

        CryptoPP::StringSource(cipher, true,
            new CryptoPP::StreamTransformationFilter(ecbDecryption,
                new CryptoPP::StringSink(recovered)
            )
        );
    }
    catch (CryptoPP::Exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

/// <summary>
/// Decodes AES ECB ciphered text so it can be read.
/// </summary>
/// <param name="cipher">Ciphered text</param>
/// <returns>Decoded ciphered text</returns>
std::string AES::decode_cipher(std::string& cipher) {
    std::string encoded;
    CryptoPP::StringSource(cipher, true,
        new CryptoPP::HexEncoder(
            new CryptoPP::StringSink(encoded)
        )
    );
    return encoded;
}

/// <summary>
/// Default constructor of the domain class.
/// </summary>
/// <param name="a">Parameter a of the curve</param>
/// <param name="b">Parameter b of the curve</param>
/// <param name="p">Modulus to create a finite field</param>
void Domain::SetParams(int a, int b, int p, int cf) {
    curve = { a, b };
    modulo = p;
    max_cofactor = cf;
    cofactor = 0;
    cardinality = modulo + 1;
    for (int x = 0; x < modulo; x++) {
        cardinality += legendre_symbol(power(x, 3, modulo) + (curve.a * x) % modulo + curve.b % modulo, modulo);
    }
}

/// <summary>
/// Generates public and private keys from base point that are used in assymetric cryptography to secure transmissiion between participants.
/// </summary>
void User::generate_keys() {
    if (domain->base_point.is_inf()) {
        std::cout << "Base Point is not set!\n";
        return;
    }
    std::uniform_int_distribution<std::mt19937::result_type> random(1, domain->cardinality / domain->cofactor - 1);

    private_key = random(rng);
    public_key = domain->scalar_mult(domain->base_point, private_key);
}

/// <summary>
/// Sets a base point manually.
/// </summary>
/// <param name="x">X-coordinate</param>
/// <param name="y">Y-coordinate</param>
/// <param name="cf">Cofactor</param>
bool Domain::set_basepoint(int x, int y, int cf) {
    Point point{ x, y };

    if (is_on_curve(point) && !point.is_inf() && isPrime(cardinality / cf)) {
        base_point = point;
        cofactor = cf;
        return 1;
    } else {
        return 0;
    }
}

/// <summary>
/// Experimental brute force algorithm to find random point on the curve that could represent a base point.
/// </summary>
bool Domain::generate_basepoint() {
    int y, x, i, flag = 1;
    std::uniform_int_distribution<std::mt19937::result_type> random(0, modulo/2 - 1);
    x = random(rng);

    do {
        y = mod(power(x, 3, modulo) + (curve.a * x) % modulo + curve.b % modulo, modulo);
        i = random(rng);
        for (; i < modulo/2 + 1; i++) {
            if (power(i, 2, modulo) == y) {
                base_point = { x, i };
                break;
            }
        }
        cofactor = find_cofactor(base_point);
        if (cofactor <= max_cofactor) {
            if (isPrime(cardinality / cofactor)) {
                flag = 0;
                break;
            }
        }

        x++;
    } while (x < modulo);
    if (base_point.is_inf() || cofactor == cardinality || flag) {
        cofactor = 0;
        base_point = { 0, 0 };
        return 0;
    }
    else {
        return 1;
    }
}

/// <summary>
/// Checks whether a point is on the curve. If it is not in the elliptic curve group, then returns false.
/// </summary>
/// <param name="point">Point to check location</param>
/// <returns>True/False</returns>
bool Domain::is_on_curve(Point& point) {
    int y;
    if (point.is_inf()) {
        return true;
    }
    y = pow(point[1], 2) - pow(point[0], 3) - curve.a * point[0] - curve.b;

    return mod(y, modulo) == 0;
}

/// <summary>
/// Points addition implementation.
/// </summary>
/// <param name="point1">First point</param>
/// <param name="point2">Second point</param>
/// <returns>Point representing sum of the given points</returns>
Point Domain::add_points(Point& point1, Point& point2) {
    int slope;
    Point result{ 0, 0 }; //Point at infinity by default

    //Process 0 + point2 = point2 and point1 + 0 = point1
    if (point1.is_inf()) {
        return point2;
    }
    else if (point2.is_inf()) {
        return point1;
    }

    //Process point + (-point) = 0
    if (point1[0] == point2[0] && point1[1] != point2[1]) {
        return result;
    }

    //Process other types of points
    if (point1[0] == point2[0]) {
        //Process points with y = 0
        if (point1[1] == 0) return result;
        slope = (3 * power(point1[0], 2, modulo) + curve.a) * inverse_of(2 * point1[1], modulo);
    }
    else {
        slope = (point1[1] - point2[1]) * inverse_of((point1[0] - point2[0]), modulo);
    }

    slope = mod(slope, modulo);
    result[0] = mod(power(slope, 2, modulo) - point1[0] - point2[0], modulo);
    result[1] = -point1[1] - slope * (result[0] - point1[0]);
    result[1] = mod(result[1], modulo);

    return result;
}

/// <summary>
/// Multiplies a point by a scalar with double and add algorithm.
/// </summary>
/// <param name="point">Point to multiply</param>
/// <param name="n">Positive integer scalar</param>
/// <returns></returns>
Point Domain::scalar_mult(Point& point, int n) {
    Point result{ 0, 0 };
    Point addend = point;

    //Process point at infinity and scalars multiple of the field module
    if (mod(n, modulo) == 0 || point.is_inf()) {
        return result;
    }

    while (n) {
        if (n & 1) {
            result = add_points(result, addend);
        }
        addend = add_points(addend, addend);
        n >>= 1;
    }

    return result;
}

/// <summary>
/// Computes an order of the cyclic subgroup generated by a point. Then divides elliptic curve cardinality by this value obtaining a cofactor of the subgroup.
/// </summary>
/// <param name="point">Point on the curve</param>
/// <returns>Cofactor of the subgroup generated by the point</returns>
int Domain::find_cofactor(Point& point) {
    for (int i = 1; i < cardinality / 2 + 1; i++) {
        if (cardinality % i == 0) {
            if (scalar_mult(point, i).is_inf()) {
                return cardinality / i;
            }
        }
    }

    return 1;
}

/// <summary>
/// Creates a shared key that is used in simmetric cryptography to encrypt and decrypt data and is hidden from other members.
/// </summary>
/// <param name="pub_key">The other participant's public key</param>
void User::create_shared_key(Point pub_key) {
    shared_key = domain->scalar_mult(pub_key, private_key);
}

/// <summary>
/// Creates signature that is used by the signatory to sign sending data.
/// </summary>
/// <param name="msg">Text to sign</param>
void User::create_signature(std::string& msg) {
    if (private_key == 0) {
        return;
    }

    int order = domain->cardinality / domain->cofactor;
    int k, hashMod = mod_hash(msg, order);
    Point P;
    std::uniform_int_distribution<std::mt19937::result_type> random(1, order - 1);

    while (true) {
        k = random(rng);
        P = domain->scalar_mult(domain->base_point, k);
        signature.r = mod(P[0], order);
        if (signature.r == 0) {
            continue;
        }

        signature.s = mod((hashMod + signature.r * (private_key % order)) * inverse_of(k, order), order);
        if (signature.s == 0) {
            continue;
        }
        break;
    }
}

/// <summary>
/// Validates given text by its signature and public key that are created by the other participant.
/// </summary>
/// <param name="pub_key">Public key of the other participant</param>
/// <param name="msg">Text to validate</param>
/// <param name="recovered">Recovered text (without signing)</param>
bool User::check_signature(Point& pub_key, std::string& signedText, std::string& recovered) {
    //int length = hex_to_int(signedText[signedText.size() - 1]);
    int s = 0, r = 0, n = 0;
    for (int i = signedText.size() - 2; i > signedText.size() - 10; i--) {
        s += pow(16, n) * hex_to_int(std::toupper(signedText[i]));
        r += pow(16, n++) * hex_to_int(std::toupper(signedText[i - 8]));
    }
    recovered = signedText.substr(0, signedText.size() - 17);

    int order = domain->cardinality / domain->cofactor;
    int u1 = mod(mod_hash(recovered, order) * inverse_of(s, order), order);
    int u2 = mod(r * inverse_of(s, order), order);
    Point P1 = domain->scalar_mult(domain->base_point, u1);
    Point P2 = domain->scalar_mult(pub_key, u2);
    Point P = domain->add_points(P1, P2);

    if (mod(P[0], order) == r) {
        return 1;
    }	else {
        return 0;
    }
}

/// <summary>
/// Signs a text following the algorithm:
/// 1. Convert r and s values to hex-strings filled with zeroes;
/// 2. Append to the text obtained hex-strings following the length in bits of both ones.
/// 3. Return signed text.
/// </summary>
/// <param name="text">Text to sign</param>
/// <param name="signedText">Signed text to return</param>
void User::sign_message(std::string& text, std::string& signedText, int r = -1, int s = -1) {
    if (r == -1 && s == -1) {
        r = signature.r;
        s = signature.s;
    }
    std::string rHex = dec_to_hex(r), sHex = dec_to_hex(s);
    rHex = std::string(8 - rHex.size(), '0') + rHex;
    sHex = std::string(8 - sHex.size(), '0') + sHex;
    signedText = text + rHex + sHex + '8';
}
