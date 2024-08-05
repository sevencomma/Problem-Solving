#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<char> orders_ch[20];

    for (int i = 0; i < orders.size(); i++) {
        for (int j = 0; j < orders[i].length(); j++) {
            orders_ch[i].push_back(orders[i][j]);
        }

        sort(orders_ch[i].begin(), orders_ch[i].end());
    }

    for (int i = 0; i < course.size(); i++) {
        map<string, int> orders_count;
        
        for (int j = 0; j < orders.size(); j++) {
            if (orders_ch[j].size() < course[i])
                continue;

            vector<int> subArray(orders_ch[j].size(), 1);

            for (int c = 0; c < course[i]; c++) {
                subArray[c] = 0;
            }
            do {
                string temp = "";
                for (int k = 0; k < orders_ch[j].size(); k++)
                    if (subArray[k] == 0)
                        temp += orders_ch[j][k];
                if (temp.length() >= 2)
                    orders_count[temp]++;
            } while (next_permutation(subArray.begin(), subArray.end()));
        }
        
        vector<string> max_count;
        int max_value = 1;

        for (const auto& pair : orders_count) {
            if (pair.second > max_value) {
                max_value = pair.second;
                max_count.clear();
                max_count.push_back(pair.first);
            }
            else if (pair.second == max_value && max_value != 1)
                max_count.push_back(pair.first);
        }
        
        for (const auto& it : max_count) {
            answer.push_back(it);
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}