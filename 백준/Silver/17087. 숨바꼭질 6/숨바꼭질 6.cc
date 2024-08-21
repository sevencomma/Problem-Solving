#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

int main(void)
{
	int n, s;
	cin >> n >> s;

	vector<int> brothers(n);

	for (int i = 0; i < n; i++) {
		cin >> brothers[i];
	}

	if (n == 1) {
		cout << abs(brothers[0] - s);
		return 0;
	}

	vector<int> distances(n);
	for (int i = 0; i < n; i++) {
		distances[i] = abs(s - brothers[i]);
	}

	sort(distances.begin(), distances.end());

	int D = gcd(distances[1], distances[0]);

	for (int i = 2; i < distances.size(); i++) {
		D = gcd(distances[i], D);
	}
	cout << D;
}