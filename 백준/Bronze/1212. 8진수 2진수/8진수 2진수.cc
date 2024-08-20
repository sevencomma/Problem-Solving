#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string sentence;

	getline(cin, sentence);

	if (sentence[0] >= '4') {
		cout << (sentence[0] - '0') / 4 << ((sentence[0] - '0') % 4) / 2;
	}
	else if (sentence[0] >= '2') {
		cout << (sentence[0] - '0') / 2;
	}
	cout << (sentence[0] - '0') % 2;

	for (int i = 1; i < sentence.length(); i++) {
		cout << (sentence[i] - '0') / 4 << ((sentence[i] - '0') % 4) / 2 << (sentence[i] - '0') % 2;
	}
}