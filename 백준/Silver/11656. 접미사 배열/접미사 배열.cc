#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<string> suffix;
	string sentence;

	cin >> sentence;

	int len = sentence.length();

	for (int i = 0; i < len; i++) {
		suffix.push_back(sentence);

		sentence = sentence.substr(1);
	}

	sort(suffix.begin(), suffix.end());

	for (const auto& it : suffix) {
		cout << it << endl;
	}
}