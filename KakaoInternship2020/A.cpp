#include <string>
#include <vector>
#include <cmath>

using namespace std;

pair<int, int> constexpr phone[10] = { { 3, 1 }, { 0, 0 }, { 0, 1 }, { 0, 2 }, 
                                                 { 1, 0 }, { 1, 1 }, { 1, 2 },
                                                 { 2, 0 }, { 2, 1 }, { 2, 2 }, };

string solution(vector<int> numbers, string hand) {
    string answer = "";

    pair<int, int> l = { 3, 0 };
    pair<int, int> r = { 3, 2 };
    for (int i = 0; i < (int)numbers.size(); ++i)
    {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            answer += "L";
            l = phone[numbers[i]];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            answer += "R";
            r = phone[numbers[i]];
        }
        else
        {
            int y = phone[numbers[i]].first;
            int x = phone[numbers[i]].second;
            int lDist = abs(l.first - y) + abs(l.second - x);
            int rDist = abs(r.first - y) + abs(r.second - x);
            if (lDist < rDist || (lDist == rDist && hand == "left"))
            {
                answer += "L";
                l = { y, x };
            }
            else if (lDist > rDist || (lDist == rDist && hand == "right"))
            {
                answer += "R";
                r = { y, x };
            }
        }
    }

    return answer;
}