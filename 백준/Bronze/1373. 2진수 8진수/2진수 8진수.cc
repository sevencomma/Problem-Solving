#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	string sentence;

	getline(cin, sentence);

	if (sentence[0] == '0') {
		cout << '0';
		return 0;
	}

	int offset;
	if (sentence.length() % 3 == 0)
		offset = 0;
	else if (sentence.length() % 3 == 1)
		offset = 1;
	else
		offset = 2;

	int num = 0;
	for (int i = 0; i < offset; i++) {
		num += (sentence[i] - '0') * pow(2, offset - i - 1);
	}
	if (num != 0)
		cout << char(num + '0');

	for (int i = offset; i < sentence.length(); i = i + 3) {
		num = 0;
		num += (sentence[i] - '0') * pow(2, 2);
		num += (sentence[i+1] - '0') * pow(2, 1);
		num += (sentence[i+2] - '0') * pow(2, 0);

		cout << char(num + '0');
	}
}