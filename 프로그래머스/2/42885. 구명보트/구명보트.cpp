#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> people, int limit) {
    int weight[241] = { 0, }, res = 0;
    for (auto& it : people)
        weight[it]++;
    sort(people.begin(), people.end());
    for (int i = 0; i < people.size(); i++) {
        if (weight[people[i]] == 0)
            continue;
        res++;
        weight[people[i]]--;
        if (people[i] * 2 > limit)
            continue;
        int diff = limit - people[i];
        
        while (weight[diff] == 0 && diff >= people[i])
            diff--;
        if (weight[diff] > 0)
            weight[diff]--;
    }
    return res;
}