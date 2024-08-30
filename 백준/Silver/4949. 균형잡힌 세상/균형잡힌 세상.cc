#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
	while (1) {
		string sentence;
		getline(cin, sentence);

		if (sentence == ".")
			break;

		stack<char> stack;
		bool is_balance = true;
		
		for (int i = 0; i < sentence.length(); i++) {
			if (sentence[i] == '(' || sentence[i] == '[')
				stack.push(sentence[i]);
			else if (sentence[i] == ')' || sentence[i] == ']') {
				if (stack.empty()) {
					is_balance = false;
					break;
				}
				else
					if ((sentence[i] == ')' && stack.top() == '(') || (sentence[i] == ']' && stack.top() == '['))
						stack.pop();
					else
						stack.push(sentence[i]);
			}
		}
		
		if (!stack.empty())
			is_balance = false;

		string ans = is_balance ? "yes" : "no";
		cout << ans << endl;
	}
}