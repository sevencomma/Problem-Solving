#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<int> su1;
    vector<int> su2; 
    vector<int> su3;

    for (int i = 0; i < answers.size(); i++) {
        su1.push_back(i % 5 + 1);
        
        if (i % 2 == 0)
            su2.push_back(2);
        else {
            if (i % 8 == 1)
                su2.push_back(1);
            else if (i % 8 == 3)
                su2.push_back(3); 
            else if (i % 8 == 5)
                su2.push_back(4);
            else if (i % 8 == 7)
                su2.push_back(5); 
        }

        if (i % 10 == 0 || i % 10 == 1)
            su3.push_back(3);
        else if (i % 10 == 2 || i % 10 == 3)
            su3.push_back(1);
        else if (i % 10 == 4 || i % 10 == 5)
            su3.push_back(2);
        else if (i % 10 == 6 || i % 10 == 7)
            su3.push_back(4);
        else if (i % 10 == 8 || i % 10 == 9)
            su3.push_back(5);
    }

    int count1 = 0;
    int count2 = 0;
    int count3 = 0;

    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == su1[i])
            count1++;
        if (answers[i] == su2[i])
            count2++;
        if (answers[i] == su3[i])
            count3++;
    }

    if (count1 > count2) {
        if (count1 > count3)
            answer.push_back(1);
        else if (count1 < count3)
            answer.push_back(3);
        else {
            answer.push_back(1);
            answer.push_back(3);
        }
    }
    else if (count1 < count2) {
        if (count2 > count3)
            answer.push_back(2);
        else if (count2 < count3)
            answer.push_back(3);
        else {
            answer.push_back(2);
            answer.push_back(3);
        }
    }
    else {
        if (count1 > count3) {
            answer.push_back(1);
            answer.push_back(2);
        }
        else if (count1 < count3)
            answer.push_back(3);
        else {
            answer.push_back(1);
            answer.push_back(2);
            answer.push_back(3);
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}