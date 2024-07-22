#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class price_dot {
public:
    int index;
    int price;
};

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), -1);

    stack<price_dot> price_dot;  

    for (int i = 0; i < prices.size(); i++) {
        if (price_dot.empty() || price_dot.top().price <= prices[i]) {
            price_dot.push({ i, prices[i] });
        }
        else {
            while (!price_dot.empty() && price_dot.top().price > prices[i]) {
                answer[price_dot.top().index] = i - price_dot.top().index;
                price_dot.pop();
            }
            price_dot.push({ i, prices[i] });
        }
    }
   
    for (int i = 0; i < answer.size(); i++) {
        if (answer[i] == -1)
            answer[i] = prices.size() - 1 - i;
    }

    return answer;
}