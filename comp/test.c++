#include <iostream>
#include <stdlib.h>
using namespace std;

int* hadamard_enc(int msg, int* enc);
int hadamard_dec(int* msg);

int main() {
	cout << "X: ";

	int x;
	cin >> x;
	
	int a = x;
	int b = x >> 4;
	int c = x >> 8;
	int d = x >> 16;

	int a_enc[1];
	int b_enc[1];	
	int c_enc[1];
	int d_enc[1];

	hadamard_enc(a, a_enc);
	hadamard_enc(b, b_enc);
	hadamard_enc(c, c_enc);
	hadamard_enc(d, d_enc);

	int a_dec = hadamard_dec(a_enc);
	int b_dec = hadamard_dec(b_enc);
	int c_dec = hadamard_dec(c_enc);
	int d_dec = hadamard_dec(d_enc);

	cout << a_enc[0] << endl;
	cout << b_enc[0] << endl;
	cout << c_enc[0] << endl;
	cout << d_enc[0] << endl;
	cout << a_dec << endl;
	cout << b_dec << endl;
	cout << c_dec << endl;
	cout << d_dec << endl;

	int dec = a_dec & (b_dec << 4) & (c_dec << 8) & (d_dec << 16);

	cout << dec << endl;
}


int* hadamard_enc(int msg, int* enc) {
	msg &= 15; // mask

	for (int ct = 0; ct < 16; ct++) {
		int i = ct + 16;
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

	for (int i = 0; i < 4; i++) {
		int j = rand() % 16;
		int k;
		for (k = 0; k < 16; k++) {
			if ((j ^ k) == 1 << i) break;
		}
		int c = (msg[j/16] >> (j%16)) & 1;
		int d = (msg[k/16] >> (k%16)) & 1;
		
		x += (c ^ d) << i;
	}

	return x;
}
