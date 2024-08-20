#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector<long long int> methods(1001);

	methods[0] = 0;
	methods[1] = 1;
	methods[2] = 2;
	
	for (int i = 3; i <= 1000; i++) {
		methods[i] = (methods[i - 1] + methods[i - 2]) % 10007;
	}
	
	cout << methods[n];
}