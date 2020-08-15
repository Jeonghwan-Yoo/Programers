#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    int n = (int)gems.size();
    unordered_set<string> type;
    for (int i = 0; i < n; ++i)
        type.insert(gems[i]);
    int sz = (int)type.size();
    
    int l = 0;
    int r = 0;
    unordered_map<string, int> own;
    answer.emplace_back(0);
    answer.emplace_back(n + 1);
    while (l < n)
    {
        if (r < n && (int)own.size() < sz && answer[1] - answer[0] > r - l)
        {
            ++own[gems[r]];
            ++r;
        }
        else
        {
            --own[gems[l]];
            if (own[gems[l]] == 0)
                own.erase(gems[l]);
            ++l;
        }
        if ((int)own.size() == sz && answer[1] - answer[0] > r - l)
        {
            answer[0] = l;
            answer[1] = r;
        }
    }
    ++answer[0];
    
    return answer;
}