#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	stack<int> stack;

	for (int i = 0; i < N; i++) {
		int cmd, answer;
		cin >> cmd;

		switch (cmd) {
		case 1:
			int x; cin >> x;
			stack.push(x);
			break;
		case 2:
			if (stack.empty())
				answer = -1;
			else {
				answer = stack.top();
				stack.pop();
			}
			cout << answer << "\n";
			break;
		case 3:
			cout << stack.size() << "\n";
			break;
		case 4:
			if (stack.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
			break;
		case 5:
			if (!stack.empty())
				answer = stack.top();
			else
				answer = -1;
			cout << answer << "\n";
			break;
		}
	}
}