#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int GetPriority(char Operator, int InStack) {
	int Priority = -1;

	switch (Operator) {
	case '(':
		if (InStack)
			Priority = 3;
		else
			Priority = 0;
		break;

	case '*': case '/':
		Priority = 1;
		break;

	case '+': case '-':
		Priority = 2;
		break;
	}

	return Priority;
}

int IsPrior(char OperatorInStack, char OperatorInToken) {
	return (GetPriority(OperatorInStack, 1) > GetPriority(OperatorInToken, 0));
}

int main(void)
{
	string sentence;

	getline(cin, sentence);

	stack<char> oper;
	string postfix = "";

	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] >= 'A' && sentence[i] <= 'Z')
			postfix += sentence[i];
		else if (sentence[i] == ')') {
			while (!oper.empty()) {
				if (oper.top() == '(') {
					oper.pop();
					break;
				}
				else {
					postfix += oper.top();
					oper.pop();
				}
			}
		}
		else {
			while (!oper.empty() && !IsPrior(oper.top(), sentence[i])) {
				if (oper.top() != '(')
					postfix += oper.top();

				oper.pop();
			}

			oper.push(sentence[i]);
		}
	}

	while (!oper.empty()) {
		if (oper.top() != '(')
			postfix += oper.top();

		oper.pop();
	}

	cout << postfix;
}