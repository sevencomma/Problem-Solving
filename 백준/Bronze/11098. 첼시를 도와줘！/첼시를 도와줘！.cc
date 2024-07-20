#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;
	int P;
	int i, j;
	string result_name[100];

	cin >> N;

	for (i = 0; i < N; i++) {
		int C[100];
		string name[100];
		int maxIndex = 0; 
		cin >> P;

		for (j = 0; j < P; j++) {
			cin >> C[j] >> name[j]; 
		}

		for (j = 0; j < P; j++) {
			if (C[maxIndex] < C[j]) 
				maxIndex = j;  
		}
		result_name[i] = name[maxIndex];
	}

	for (i = 0; i < N; i++)
		cout << result_name[i] << endl;
}