#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool CheckU(string const &p, string &u, string &v)
{
    bool check = true;
    int cnt = 0;
    for (int i = 0; i < (int)p.size(); ++i)
    {
        if (p[i] == '(')
            ++cnt;
        else
            --cnt;
        if (cnt < 0)
            check = false;
        u += p[i];
        if (cnt == 0)
            break;
    }

    for (int i = (int)u.size(); i < (int)p.size(); ++i)
        v += p[i];

    return check;
}

string solution(string p) {
    string answer;
    if (p.empty())
        return "";

    string u, v;
    bool check = CheckU(p, u, v);
    if (check == true)
    {
        u += solution(v);
        answer += u;
    }
    else
    {
        string s;
        s += "(";
        s += solution(v);
        s += ")";
        for (int i = 1; i < (int)u.size() - 1; ++i)
            s += !(u[i] - '(') + '(';
        answer += s;
    }

    return answer;
}