#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> number(N);
	for (int i = 0; i < N; i++) {
		cin >> number[i];
	}

	sort(number.begin(), number.end());

	for (auto& it : number)
		cout << it << "\n";
}