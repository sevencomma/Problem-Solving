#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> person;

    for (int i = 0; i < participant.size(); i++) {
        if (person.find(participant[i]) != person.end()) {
            person[participant[i]]++;
        }
        else {
            person[participant[i]] = 1;
        }
    }

    for (int i = 0; i < completion.size(); i++) {
        if (person[completion[i]] == 1) {
            person.erase(completion[i]);
        }
        else
            person[completion[i]]--;
    }
    
    auto it = person.begin();
    answer = it->first;

    return answer; 
}