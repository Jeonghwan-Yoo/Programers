#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int constexpr sz[8] = { 1, 2, 6, 24, 120, 720, 5040, 40320 };

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 0;

    int szWeak = (int)weak.size();
    for (int i = 0; i < szWeak; ++i)
        weak.emplace_back(weak[i] + n);

    vector<int> group;
    bool flag = false;
    for (int i = (int)dist.size() - 1; i >= 0; --i)
    {
        group.emplace_back(dist[i]);
        for (int j = 0; j < sz[(int)group.size() - 1]; ++j)
        {
            for (int k = 0; k < szWeak; ++k)
            {
                int pos = k;
                for (int l = 0; l < (int)group.size(); ++l)
                {
                    pos = upper_bound(weak.begin(), weak.end(), weak[pos] + group[l]) - weak.begin();
                    if (pos - k >= szWeak)
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag == true)
                    break;
            }
            if (flag == true)
                break;

            next_permutation(group.begin(), group.end());
        }
        if (flag == true)
            break;
    }
    if (flag == true)
        answer = (int)group.size();
    else
        answer = -1;

    return answer;
}
