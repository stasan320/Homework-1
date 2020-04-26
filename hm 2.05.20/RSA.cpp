#include <iostream>
#include <cmath>

#include "func.h"

int main() {
	long long prime[2], OpenKey[2], PrivateKey[2];
	long long fun, enc, dec;

	for (int i = 0; i < 2; i++) prime[i] = GenNum();

	fun = (prime[0] - 1) * (prime[1] - 1);
	OpenKey[0] = Degree(fun);
	OpenKey[1] = prime[0] * prime[1];

	PrivateKey[0] = Num(fun, OpenKey[0]);
	PrivateKey[1] = prime[0] * prime[1];

	enc = Encrypt(fun, OpenKey[0], OpenKey[1]);
	std::cout << enc << std::endl;
	dec = Decrypt(enc, PrivateKey[0], PrivateKey[1]);
	std::cout << dec << std::endl;

	return 0;
}
