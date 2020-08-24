#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    int cnt[200001] = { 0, };
    int sz = (int)stages.size();
    for (int i = 0; i < sz; ++i)
        --cnt[stages[i]];
    
    vector<pair<double, int> > failure; 
    int left = sz;
    for (int i = 1; i <= N; ++i)
    {
        failure.emplace_back((double)cnt[i] / left, i);
        left += cnt[i];
    }
    sort(failure.begin(), failure.end());
    for (int i = 0; i < (int)failure.size(); ++i)
        answer.emplace_back(failure[i].second);
    
    return answer;
}