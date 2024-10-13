#include <iostream>
using namespace std;

int main(void) {
	int N, F;
	cin >> N >> F;
	N /= 100;
	N *= 100;
	for (int i = 0; i < 100; i++) {
		if (N % F == 0) {
			printf("%.2d", N % 100);
			break;
		}
		N++;
	}
}