#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
	int A, B, M;

	cin >> A >> B >> M;

	vector<int> A_number(25);
	for (int i = 0; i < M; i++) {
		cin >> A_number[i];
	}

	int num = 0;
	for (int i = M - 1; i >= 0; i--) {
		num += pow(A, M - i - 1) * A_number[i];
	}

	vector<int> B_number;

	while (num != 0) {
		B_number.push_back(num % B);
		num /= B;
	}

	for (int i = B_number.size() - 1; i >= 0; i--) {
		cout << B_number[i] << " ";
	}
}