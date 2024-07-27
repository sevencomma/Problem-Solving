#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
	stack<char> stick;
	string parenthesis; 
	int answer = 0;

	getline(cin, parenthesis);

	int length = parenthesis.length(); 

	for (int i = 0; i < length; i++) {
		if (parenthesis[i] == '(') {
			stick.push('(');

			if (parenthesis[i + 1] == ')') {	// 레이저
				stick.pop();
				answer += stick.size();
				i++;
			}
		}
		else {
			stick.pop();
			answer++;
		}
	}

	cout << answer;
}