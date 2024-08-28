#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	unordered_map<int, vector<int>> graph;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (auto ita : graph) {

		for (auto itb : graph[ita.first]) {
			if (itb == ita.first)
				continue;

			for (auto itc : graph[itb]) {
				if (itc == ita.first || itc == itb)
					continue;

				for (auto itd : graph[itc]) {
					if (itd == ita.first || itd == itb || itd == itc)
						continue;

					for (auto ite : graph[itd]) {
						if (ite == ita.first || ite == itb || ite == itc || ite == itd)
							continue;

						cout << 1;
						return 0;
					}
				}
			}
		}
	}

	cout << 0;
}