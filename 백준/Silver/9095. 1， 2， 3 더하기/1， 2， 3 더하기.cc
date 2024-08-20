#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	vector<long long int> methods(11);

	methods[0] = 0;
	methods[1] = 1;
	methods[2] = 2;
	methods[3] = 1 + 1 + 2;

	for (int i = 4; i < 11; i++) {
		methods[i] = methods[i - 3] + methods[i - 2] + methods[i - 1];
	}
	
	int n;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << methods[n] << "\n";
	}
}