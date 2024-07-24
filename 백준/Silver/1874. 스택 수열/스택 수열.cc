#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string>
#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

int main(void)
{
	int N;
	int k = -1;
	cin >> N;
	stack<int> number;
	vector<int> sequence(N+1);

	string answer = "";

	scanf("%d", &sequence[++k]);

	for (int i = 1; i <= N; i++) { 
		number.push(i); 
		answer += "+";

		
		while (!number.empty() && number.top() == sequence[k]) {
			number.pop();
			answer += "-";
			if (k+1 == N)
				break;
			scanf("%d", &sequence[++k]);
		}

	}
	if (k + 1 != N)
		cout << "NO" << endl;
	else {
		for (int i = 0; i < answer.length(); i++)
			printf("%c\n", answer[i]);
	}

}