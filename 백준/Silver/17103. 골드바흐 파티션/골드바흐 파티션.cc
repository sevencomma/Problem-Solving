#include <iostream>
#include <vector>

using namespace std;

int prime_number[1000001] = { 0, };

int main()
{
	prime_number[0] = -1;
	prime_number[1] = -1;

	for (int i = 2; i * i <= (1000000); i++) {
		if (prime_number[i] == 0) {
			for (int j = i * 2; j <= 1000000; j += i)
				prime_number[j] = -1;
		}
	}

	vector<int> prime;

	for (int i = 2; i <= 1000000; i++) {
		if (prime_number[i] == 0) {
			prime.push_back(i);
		}
	}

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N;
		int count = 0;

		cin >> N;

		for (int j = 0; j < prime.size(); j++) {
			if (prime[j] > N / 2)
				break;

			if (prime_number[N - prime[j]] == 0) {
				count++;
			}
		}
		cout << count << "\n";
	}
}