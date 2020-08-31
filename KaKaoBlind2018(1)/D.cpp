#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    int sz = (int)timetable.size();
    vector<int> table(sz);
    for (int i = 0; i < sz; ++i)
        table[i] = stoi(timetable[i].substr(0, 2)) * 60 + stoi(timetable[i].substr(3, 2));
    
    sort(table.begin(), table.end());
    
    queue<int> q;
    for (int i = 0; i < sz; ++i)
        q.emplace(table[i]);
    
    int shuttle = 60 * 9;
    int maxArrival = 0;
    for (int i = 0; i < n; ++i)
    {
        int cnt = 0;
        int last = 0;
        for (int j = 0; j < m; ++j)
        {
            if (q.empty() || q.front() > shuttle)
            {
                maxArrival = shuttle;
                break;
            }
            else
            {
                last = q.front();
                q.pop();
                ++cnt;
            }
        }
        if (cnt == m)
            maxArrival = last - 1;
        shuttle += t;
    }
    char tmp[6];
    sprintf(tmp, "%02d:%02d", maxArrival / 60, maxArrival % 60);
    answer = tmp;
    
    return answer;
}