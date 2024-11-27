#include <bits/stdc++.h>
using namespace std;

vector<string> split(string src, string delimeter) {
    vector<string> ret;
    long long pos = 0;
    string token = "";
    
    while ((pos = src.find(delimeter)) != string::npos) {
        token = src.substr(0, pos);
        ret.push_back(token);
        src.erase(0, pos + delimeter.length());
    }
    ret.push_back(src);
    return ret;
}

bool compare(vector<string>& a, vector<string>& b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<string> answer;
    s = s.substr(1);
    s = s.substr(0, s.length() - 1);
    vector<string> seq = split(s, "},");
    for (auto& it : seq)
        it.erase(0, 1);
    seq[seq.size() - 1].erase(seq[seq.size() - 1].length() - 1);
    vector<vector<string>> A(seq.size());
    
    for (int i = 0; i < seq.size(); i++)
        A[i] = split(seq[i], ",");
    
    sort(A.begin(), A.end(), compare);
 
    for (auto & it : A) {
        map<string, int> cnt;
        for (auto& it2 : it)
            cnt[it2]++;
        
        for (auto& it3 : answer)
            cnt[it3]--;
        
        string C;
        for (auto& it4 : cnt)
            if (it4.second == 1)
                C = it4.first;
        answer.push_back(C);
    }
    vector<int> res;
    for (auto & it : answer)
        res.push_back(stoi(it));
    return res;
}