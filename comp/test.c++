#include <iostream>
#include <stdlib.h>
using namespace std;

int* hadamard_enc(int msg);
int hadamard_dec(int* msg);

int main() {
	cout << "X: ";

	int x;
	cin >> x;
	
	int* code = hadamard_enc(x);

	code[0] |= 1024;
	code[1] |= 64;

	int dec = hadamard_dec(code);

	cout << dec << endl;
}


int* hadamard_enc(int msg) {
	static int enc[8] = {};

	for (int ct = 0; ct < 256; ct++) {
		int i = ct + 256;
		// multiply corresponding bits
		int a = i & msg;
		// sum (mod 2)
		a ^= a >> 4;
		a ^= a >> 2;
		a ^= a >> 1;
		a &= 1;
		// store in enc array
		enc[ct / 16] += a << (15 - ct % 16);
	}

	return enc;
}

int hadamard_dec(int* msg) {
	int x = 0;

	for (int i = 0; i < 8; i++) {
		int j = rand() % 256;
		int k;
		for (k = 0; k < 256; k++) {
			if ((j ^ k) == 1 << i) break;
		}
		int c = (msg[j/16] >> (j%16)) & 1;
		int d = (msg[k/16] >> (k%16)) & 1;
		
		x += (c ^ d) << i;
	}
	
	cout << endl;

	return x;
}
