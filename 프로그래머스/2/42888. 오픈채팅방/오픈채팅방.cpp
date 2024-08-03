#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std; 

/*
* ["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]
* 
* ["Prodo님이 들어왔습니다.", "Ryan님이 들어왔습니다.", "Prodo님이 나갔습니다.", "Prodo님이 들어왔습니다."]
*/

vector<string> solution(vector<string> record) { 
    vector<string> answer; 
    
    vector<pair<string, int>> in_out_record;  // 1 : in , 0 : out 
    unordered_map<string, string> id_nickname;

    for (int i = 0; i < record.size(); i++) {
        string command = "";
        string user_id = "";
        string nickname = "";

        int j;
        for (j = 0; j < record[i].length(); j++) {
            if (record[i][j] == ' ')
                break;
            command += record[i][j];
        } j++;
        for (j; j < record[i].length(); j++) {
            if (record[i][j] == ' ')
                break;
            user_id += record[i][j];
        } j++;
        for (j; j < record[i].length(); j++) {
            if (record[i][j] == '\n') 
                break;
            nickname += record[i][j];
        }

        if (command == "Enter") {
            in_out_record.push_back({user_id, 1});
            id_nickname[user_id] = nickname;
        }
        else if (command == "Leave") {
            in_out_record.push_back({ user_id, 0 });
        }
        else { // command == "Change"
            id_nickname[user_id] = nickname;
        }
    }

    for (const auto& pair: in_out_record) {
        string sentence = id_nickname[pair.first];

        if (pair.second) {
            sentence += "님이 들어왔습니다.";
        }
        else {
            sentence += "님이 나갔습니다.";
        }

        answer.push_back(sentence);
    }

    return answer;
}