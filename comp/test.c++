#include <iostream>
using namespace std;

unsigned char* hadamard(unsigned char msg);

int main() {
	unsigned char* code = hadamard('A');

	for (int i = 0; i < 7; i++) {
		cout << +((int) code[i]) << endl;
	}
}


unsigned char* hadamard(unsigned char msg) {
	static unsigned char enc[7] = {};

	for (unsigned char ct = 0; ct < 64; ct++) {
		unsigned char i = ct + 64;
		// multiply corresponding bits
		unsigned char a = i & msg;
		// sum (mod 2)
		a ^= a >> 8;
		a ^= a >> 4;
		a ^= a >> 2;
		a ^= a >> 1;
		a &= 1;
		// store in enc array
		enc[ct / 8] += a << (7 - ct % 8);
	}

	return enc;
}
