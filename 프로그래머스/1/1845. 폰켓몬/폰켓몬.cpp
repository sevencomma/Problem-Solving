#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    map<int, int> poketmon;

    for (auto i : nums) {
        poketmon[i]++;
    }

    int answer = nums.size() / 2 > poketmon.size() ? poketmon.size() : nums.size() / 2;    

    return answer;
}