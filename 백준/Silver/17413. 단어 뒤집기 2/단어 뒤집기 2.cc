#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

int main(void)
{
	stack<char> reversed;
	queue<char> original;

	string sentence;

	getline(cin, sentence);

	int length = sentence.length();

	int i = 0;
	char ch;

	string answer = "";

	for (i = 0; i < length; i++) {

		if (sentence[i] == '<') {
			while (sentence[i] != '>') {
				original.push(sentence[i]);
				i++;
			}
			original.push(sentence[i]); 

			while (!original.empty()) {
				answer += original.front();
				original.pop();
			}
		}
		else {
			while (i < length && sentence[i] != ' ' && sentence[i] != '<') {
				reversed.push(sentence[i]);
				i++;
			}

			while (!reversed.empty()) {
				answer += reversed.top();
				reversed.pop();
			}
			
			if (sentence[i] == ' ')
				answer += sentence[i];
			else if (sentence[i] == '<')
				i--;
		}
	}

	cout << answer;
}