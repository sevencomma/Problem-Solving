#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, int> word_count;

    int len = words.size(); 

    char last_alphabet; 
    int word_size = words[0].length();

    last_alphabet = words[0][word_size - 1];
    word_count[words[0]]++;

    int i;
    for (i = 1; i < len; i++) {
        if (word_count[words[i]] == 1)
            break;
        else
            word_count[words[i]]++;

        int word_size = words[i].length();

        if (last_alphabet != words[i][0]) {
            break;
        }

        last_alphabet = words[i][word_size - 1];
    }

    if (i == len)
        answer = { 0, 0 };
    else
        answer = { i % n + 1, i / n + 1 };

    return answer;
}