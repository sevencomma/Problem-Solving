#include <string>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> left_days;

    double days_cal;

    for (int i = 0; i < progresses.size(); i++) {
        days_cal = (double)(100 - progresses[i]) / speeds[i];

        left_days.push(ceil(days_cal));
    }

    int day1;
    int day2;

    while (!left_days.empty()) {
        day1 = left_days.front();
        left_days.pop();

        int count = 1;
        while (!left_days.empty() && day1 >= left_days.front()) {
            left_days.pop();
            count++;
        }

        answer.push_back(count);
    }

    return answer;
}