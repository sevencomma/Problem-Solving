#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	while (1) {
		vector<int> ch_count(4, 0);

		string sentence;

		getline(cin, sentence);

		if (sentence == "")
			break;

		for (int i = 0; i < sentence.length(); i++) {
			if (sentence[i] >= 'a' && sentence[i] <= 'z')
				ch_count[0]++;
			else if (sentence[i] >= 'A' && sentence[i] <= 'Z')
				ch_count[1]++; 
			else if (sentence[i] >= '0' && sentence[i] <= '9')
				ch_count[2]++;
			else if (sentence[i] == ' ')
				ch_count[3]++;
		}

		cout << ch_count[0] << " " << ch_count[1] << " " << ch_count[2] << " " << ch_count[3] << endl;
	}
}