#include <bits/stdc++.h>
using namespace std;

int N;

int main(void) {
	cin >> N;
	if (N % 2 == 0) {
		cout << "I LOVE CBNU";
		return 0;
	}

	for (int i = 0; i < N; i++)
		cout << '*';
	cout << '\n';
	for (int i = 0; i < N / 2; i++)
		cout << ' ';
	cout << '*';
	cout << '\n';
	for (int i = N / 2 - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++)
			cout << ' ';
		cout << '*';

		for (int j = 0; j < (N / 2 - i) * 2 - 1; j++)
			cout << ' ';
		cout << '*';
		cout << '\n';
	}
}