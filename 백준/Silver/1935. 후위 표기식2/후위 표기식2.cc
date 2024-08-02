#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
	int N;
	string sentence;
	double result;

	cin >> N;
	cin.ignore();

	getline(cin, sentence);
	
	vector<int> operand(N);

	for (int i = 0; i < N; i++) {
		cin >> operand[i];
	}

	stack<double> numerator;

	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] >= 'A' && sentence[i] <= 'Z') {
			numerator.push(operand[sentence[i] - 'A']);
		}
		else {
			double num1, num2;
			num2 = numerator.top();
			numerator.pop();
			num1 = numerator.top();
			numerator.pop();

			if (sentence[i] == '+') {
				numerator.push(num1 + num2);
			}
			else if (sentence[i] == '-') {
				numerator.push(num1 - num2);
			}
			else if (sentence[i] == '*') {
				numerator.push(num1 * num2);
			}
			else if (sentence[i] == '/') {
				numerator.push(num1 / num2);
			}
		}
	}

	result = numerator.top();
	printf("%.2f", result);
}