#include <iostream>

using namespace std;

int main(void)
{
	int num;
	while (cin >> num) {

		if (num == -1)
			break;

		int number = 1;
		int k = 1;

		while (1) {
			if ((number) % num == 0) {
				cout << k << endl;
				break;
			}
			k++;
			number = number * 10 + 1;
			number %= num;
		}
	}
}