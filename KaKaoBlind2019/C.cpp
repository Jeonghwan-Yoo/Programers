#include <string>
#include <vector>

using namespace std;

int R, C;
vector<vector<int> > keys;

void Check(vector<int> &select, vector<vector<string> > &relation)
{
    for (int i = 0; i < (int)keys.size(); ++i)
    {
        bool flag = false;
        for (int j = 0; j < (int)keys[i].size(); ++j)
            if (select[j] == 0 && keys[i][j] == 1)
                flag = true;
        if (flag == false)
            return;
    }
    
    vector<string> vs;
    for (int i = 0; i < R; ++i)
    {
        string s = "";
        for (int j = 0; j < C; ++j)
            if (select[j] == 1)
                s += relation[i][j] + " ";
        
        for (int j = 0; j < (int)vs.size(); ++j)
            if (vs[j] == s)
                return;
        
        vs.emplace_back(s);
    }
    if ((int)vs.size() == R)
        keys.emplace_back(select);
}

void Select(int idx, int left, vector<int> &select, vector<vector<string> > &relation)
{
    if (left == 0)
    {
        Check(select, relation);
        return;
    }
    if (idx >= C)
        return;
    
    select[idx] = 1;
    Select(idx + 1, left - 1, select, relation);
    select[idx] = 0;
    Select(idx + 1, left, select, relation);
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    
    R = (int)relation.size();
    C = (int)relation[0].size();
    for (int i = 1; i <= C; ++i)
    {
        vector<int> select(C);
        Select(0, i, select, relation);
    }
    
    answer = (int)keys.size();
    
    return answer;
}

// #include <string>
// #include <vector>
// #include <unordered_set>

// using namespace std;

// bool Check(vector<int> &keys, int cur)
// {
//     for (auto &k : keys)
//         if ((k & cur) == k)
//             return false;
//     return true;
// }

// int solution(vector<vector<string>> relation) {
//     int answer = 0;
    
//     int R = (int)relation.size();
//     int C = (int)relation[0].size();
//     vector<int> keys;
//     for (int i = 1; i < (1 << C); ++i)
//     {
//         if (Check(keys, i) == false)
//             continue;
//         unordered_set<string> us;
//         for (int j = 0; j < R; ++j)
//         {
//             string s = "";
//             for (int k = 0; k < C; ++k)
//                 if (i & (1 << k))
//                     s += relation[j][k] + " ";
//             us.insert(s);
//         }
//         if ((int)us.size() == R)
//             keys.emplace_back(i);
//     }
//     answer = (int)keys.size();
    
//     return answer;
// }