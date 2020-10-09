#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string toString = "0123456789ABCDEF";

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    int maxNum = t * m;
    string s;
    s += '0';
    for (int i = 1; (int)s.size() < maxNum; ++i)
    {
        string tmp;
        int cur = i;
        while (cur)
        {
            tmp += toString[cur % n];
            cur /= n;
        }
        reverse(tmp.begin(), tmp.end());
        s += tmp;
    }
    for (int i = 0; i < t; ++i)
        answer += s[(m * i) + (p - 1)];
    
    return answer;
}