#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";

    int N = cards1.size();
    int M = cards2.size();

    int G = goal.size();
    int k = 0;

    for (int i = 0, j = 0; i + j < N + M; ) {
        if (goal[k] == cards1[i]) {
            i++;
        }
        else if (goal[k] == cards2[j]) {
            j++;
        }
        else {
            answer = "No";
            break;
        }
        k++;
        if (k == G)
            break;
    }

    return answer;
}