#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct FAILURE {
    int index;
    double rate;
};

bool compare(FAILURE a, FAILURE b)
{
    if (a.rate == b.rate)
        return a.index < b.index;
    return a.rate > b.rate;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> count;
    count.assign(N + 2, 0);

    for (int i = 0; i < stages.size(); i++) {
        count[stages[i]] += 1;
    }

    vector<int> part_sum;
    part_sum.assign(N + 2, 0);

    part_sum[N + 1] = count[N + 1];
    for (int i = N; i > 0; i--) {
        part_sum[i] = part_sum[i + 1] + count[i];
    }

    vector<FAILURE> failure_rate(N);
    failure_rate.assign(N, {0,0});

    for (int i = 1; i < N + 1; i++) {
        failure_rate[i - 1].index = i;
        if (part_sum[i] == 0)
            failure_rate[i - 1].rate = 0;
        else
            failure_rate[i - 1].rate = (double)count[i] / (double)part_sum[i];
    }

    sort(failure_rate.begin(), failure_rate.end(), compare);

    for (int i = 0; i < N; i++) {
        answer.push_back(failure_rate[i].index);
    }

    return answer;
}