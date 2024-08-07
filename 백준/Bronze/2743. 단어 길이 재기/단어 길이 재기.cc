#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string sentence;

	getline(cin, sentence);

	cout << sentence.length();
}