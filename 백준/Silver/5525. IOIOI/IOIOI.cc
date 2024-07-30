#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;

	cin >> N >> M;
	
	string pstr = "";
	for (int i = 0; i < N; i++) {
		pstr += "IO";
	}
	pstr += "I";

	vector<char> sentence(M);

	for (int i = 0; i < M; i++) {
		cin >> sentence[i];
	}

	int length = pstr.length();
	int count = 0;
	for (int i = 0; i <= M - length; i++) {
		int k = 0; 
		int j = i;
		while (pstr[k] == sentence[j]) {
			k++;
			j++;
			
			if (k == length) {
				count++;
				break;
			}
		}
	}
	cout << count;
}