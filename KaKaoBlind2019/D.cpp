#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    
    vector<int> sorted(food_times);
    sorted.emplace_back(0);
    sort(sorted.begin(), sorted.end());
    int n = (int)sorted.size();
    int num = n - 1;
    
    vector<pair<int, int> > tmp;
    for (int i = 1; i < n; ++i)
    {
        long long sum = (long long)(sorted[i] - sorted[i - 1]) * num;
        if (sum <= k)
        {
            k -= sum;
            --num;
        }
        else
        {
            for (int j = 0; j < (int)food_times.size(); ++j)
                if (food_times[j] >= sorted[i])
                    tmp.emplace_back(food_times[j], j);
            answer = tmp[k % (int)tmp.size()].second + 1;
            break;
        }
    }
    if (tmp.empty())
        answer = -1;
    
    return answer;
}