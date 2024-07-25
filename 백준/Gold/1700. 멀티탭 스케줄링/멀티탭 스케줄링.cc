#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

/*
* 플러그가 채워지지 않았다면 뺄 필요없음
* 이미 해당 번호가 꼽혀 있으면 꼽을 필요없고 뺄 필요도 없음
* 해당 번호가 없고 플러그가 채워져 있다면 우선순위가 낮은 하나를 빼고 꼽아야 함.
* 
* 만약 그 뒤에 나오는 똑같은 개수로 나온다면 일찍 나올 수록 우선순위가 높음.
* 1 ~ 100(= K) 각각에 대하여 몇 번 째에 나오는지를 큐에 저장.
* 
* 현재 i번째 인덱스라고 했을 때, 지금 플러그에 꼽혀있는 번호 모두의 큐의 front 값을 비교해서
* (만약 큐가 비어있다면 바로 뽑아버림)
* 최댓값의 플러그를 뽑는다. --> 현 시점 가장 의미없는 플러그
* 그리고 현재 i번째로 추가하는 번호를 추가하고, 그 번호를 큐에서 pop();
*/
int main(void)
{
	int N, K;
	int num;
	int count = 0;

	cin >> N >> K;

	queue<int> plug_plan[101];	// 1 ~ K 만 사용
	vector<int> sequence;

	set<int> plug;	// N 개만 사용

	for (int i = 1; i <= K; i++) {
		cin >> num;
		
		plug_plan[num].push(i);
		sequence.push_back(num);
	}

	for (int i = 0; i < K; i++) {
		//sequence[i];
		if (plug.size() < N) {
			plug.insert(sequence[i]);
			plug_plan[sequence[i]].pop();
		}
		else {
			bool check_already_have = false;

			for (const auto& number : plug) {
				if (sequence[i] == number) { 
					check_already_have = true;
					plug_plan[sequence[i]].pop();
					break;
				}
			}

			if (check_already_have)
				continue;

			int max = 0;
			auto temp = plug.begin();

			for (auto it = plug.begin(); it != plug.end(); it++) { 
				if (plug_plan[*it].empty()) {
					temp = it;
					break;
				}

				if (max < plug_plan[*it].front()) {
					max = plug_plan[*it].front();
					temp = it;
				}
			}
			plug.erase(temp);
			plug.insert(sequence[i]);
			plug_plan[sequence[i]].pop();
			count++;
		}
	}

	cout << count << endl;
}