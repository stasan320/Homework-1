#include <iostream>
#include <vector>
#include <cmath>
#include "func.h"

int main() {
	long long prime[2], OpenKey[2], PrivateKey[2], fun, enc;

	for (int i = 0; i < 2; i++) prime[i] = GenNum();

	std::cout << "Num #1: " << prime[0] << std::endl;
	std::cout << "Num #2: " << prime[1] << std::endl;


	fun = (prime[0] - 1) * (prime[1] - 1);
	OpenKey[0] = Degree(fun);
	OpenKey[1] = prime[0] * prime[1];

	PrivateKey[0] = Num(fun, OpenKey[0]);
	PrivateKey[1] = prime[0] * prime[1];

	enc = Encrypt(PrivateKey[0], OpenKey[0], OpenKey[1]);
	std::cout << "Your encrypt number: " << enc << std::endl;
	std::cout << "Your decrypt number: " << Decrypt(enc, PrivateKey[0], PrivateKey[1]);

	return 0;
}
