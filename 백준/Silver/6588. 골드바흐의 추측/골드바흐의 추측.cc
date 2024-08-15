#include <iostream>
#include <vector>

using namespace std;

int prime[1000001] = { 0, };

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	prime[0] = 1;
	prime[1] = 1;
	prime[2] = 0;

	for (int i = 2; i * i <= 1000000; i++) {
		if (prime[i])
			continue;

		for (int j = i * i; j <= 1000000; j += i)
			prime[j] = 1;
	}

	vector<int> prime_sequence;

	for (int i = 0; i < 1000001; i++) {
		if (prime[i] == 0)
			prime_sequence.push_back(i);
	}

	int num;

	cin >> num;

	while (num != 0) {
		for (int i = 0; i < prime_sequence.size(); i++) {
			if (prime[num - prime_sequence[i]] == 0) {
				cout << num << " = " << prime_sequence[i] << " + " << num - prime_sequence[i] << "\n";
				break;
			}
		}

		cin >> num;
	}

}