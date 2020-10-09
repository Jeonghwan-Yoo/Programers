#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    unordered_map<string, int> dict;
    for (char c = 'A'; c <= 'Z'; ++c)
    {
        string s;
        s = c;
        dict[s] = c - 'A' + 1;
    }
    
    int num = 27;
    int n = (int)msg.size();
    string tmp;
    for (int i = 0; i < n; ++i)
    {
        tmp += msg[i];
        if (dict.count(tmp) == 0)
        {
            dict[tmp] = num;
            tmp.pop_back();
            answer.emplace_back(dict[tmp]);
            ++num;
            tmp.clear();
            tmp += msg[i];
        }
    }
    answer.emplace_back(dict[tmp]);
    
    return answer;
}