#include <iostream>
using namespace std;
int parity(int n, int *arr) {
	int p = 0;
	for (int i = 0; i < n; i++) {
		if (i != (1 << p) - 1) {
			p++;
		}
		else {
			p++;
			i += (1 << p) - 2;
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if ((i & (1 << p - 1)) == 0) {
			sum ^= arr[i];
		}
	}
	return sum;
}
void encode(int *data, int n, int *encoded) {
	int r = 0;
	while ((1 << r) < n + r + 1) {
		r++;
	}
	int j = 0;
	for (int i = 0; i < n + r; i++) {
		if ((i & (i + 1)) == 0) {
			encoded[i] = 0;
		}
		else {
			encoded[i] = data[j];
			j++;
		}
	}
	for (int i = 0; i < r; i++) {
		int p = parity(n + r, encoded);
		encoded[(1 << i) - 1] = p;
	}
}
bool decode(int *data, int n, int *received) {
	int r = 0;
	while ((1 << r) < n + r + 1) {
		r++;
	}
	int error = 0;
	for (int i = 0; i < r; i++) {
		int p = parity(n + r, received);
		if (p != received[(1 << i) - 1]) {
			error += (1 << i) - 1;
		}
	}
	if (error != 0) {
		received[error - 1] ^= 1;
	}
	int j = 0;
	for (int i = 0; i < n + r; i++) {
		if ((i & (i + 1)) != 0) {
			data[j] = received[i];
			j++;
		}
	}
	return error == 0;
}
int main() {
	int n = 4;
	int r = 3; 
	int data[n] = {1, 0, 1, 1}; 
	int encoded[n + r] = {0}; 

