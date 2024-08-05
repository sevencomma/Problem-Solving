#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    
    unordered_map<string, vector<string>> reporter;
    unordered_set<string> report_record;

    for (int i = 0; i < report.size(); i++) {
        report_record.insert(report[i]);
    }

    for (const auto it: report_record) {
        int pos = it.find(" ");

        string user1 = it.substr(0, pos);
        string user2 = it.substr(pos + 1);

        reporter[user2].push_back(user1);
    }

    unordered_map<string, int> report_count;

    for (int i = 0; i < id_list.size(); i++) {
        report_count[id_list[i]] = 0;
    }

    for (const auto it : reporter) {
        if (it.second.size() >= k) {
            for (int j = 0; j < it.second.size(); j++) {
                report_count[it.second[j]]++;
            }
        }
    }

    for (int i = 0; i < id_list.size(); i++) {
        answer[i] = report_count[id_list[i]];
    }

    return answer;
}