#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    unordered_map<string, int> check_list;

    int count = 0;
    
    for (int s = 0; s < number.size(); s++) {
        count += number[s];
    }

    for (int i = 0; i <= discount.size() - count; i++) {

        for (int k = 0; k < want.size(); k++) {
            check_list[want[k]] = number[k];
        }

        int j;
        for (j = 0; j < count; j++) {
            if ((check_list.find(discount[i+j]) == check_list.end()) || (check_list[discount[i+j]] <= 0))
                break;
            check_list[discount[i+j]]--;
        }

        if (j == count) {
            answer++;
        }
    }

    return answer; 
}