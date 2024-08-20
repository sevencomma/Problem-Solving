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
	methods[2] = 3;
	methods[3] = 3 + 1 + 1;
	
	for (int i = 3; i <= 1000; i++) {
		methods[i] = (methods[i - 1] + 2 * methods[i - 2]) % 10007; 
	}
	
	cout << methods[n];
}