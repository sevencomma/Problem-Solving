#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    

    while (1) {
        answer++;

        if (a % 2 == 1 && a + 1 == b) {
            break;
        }
     
        a = (a + 1) / 2;
        b = (b + 1) / 2;
    }

    return answer;
}