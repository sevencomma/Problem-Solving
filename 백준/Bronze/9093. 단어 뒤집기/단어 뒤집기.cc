#include <iostream>
#include <string>
#include <cctype>
#include <stack>

using namespace std;

int main()
{
	stack<char> stack; 
	string sentence;
	int N;

	cin >> N; 
	cin.ignore();
	char ch;
	int len; 
	char temp; 
	int word_len;

	for (int i = 0; i < N; i++) {
		char result[1024];
		int k = 0;
		getline(cin, sentence);

		len = sentence.length();

		for (int j = 0; j < len + 1; j++) {
			if (isalpha(sentence[j]))
				stack.push(sentence[j]);
			else {
				word_len = stack.size();
				for (int t = 0; t < word_len; t++) {
					ch = stack.top();
					stack.pop();
					result[k++] = ch;
				}
				result[k++] = ' ';
			}
		}

		for (int j = 0; j < k-1; j++)
			cout << result[j];
		cout << endl;
	}
}