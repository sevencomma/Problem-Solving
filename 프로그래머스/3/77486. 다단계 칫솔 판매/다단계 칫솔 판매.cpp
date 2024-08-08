#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;

    unordered_map<string, vector<int>> profit;
    unordered_map<string, int> divide_profit;

    for (int i = 0; i < seller.size(); i++) {
        profit[seller[i]].push_back(amount[i] * 100);
    }

    unordered_map<string, string> connected_path;

    for (int i = 0; i < enroll.size(); i++) {
        connected_path[enroll[i]] = referral[i];
    }

    for (int i = enroll.size() - 1; i >= 0; i--) {
        string sub = enroll[i];
        string parent = connected_path[sub];

        if (profit[sub].empty())
            continue;
        
        while (!profit[sub].empty()) {
            int temp_money = profit[sub].back();
            divide_profit[sub] += temp_money - temp_money / 10;

            if (temp_money >= 10)
                profit[parent].push_back(temp_money / 10);

            profit[sub].pop_back();
        }
    }
    
    for (int i = 0; i < enroll.size(); i++) {
        answer.push_back(divide_profit[enroll[i]]);
    }

    return answer;
}