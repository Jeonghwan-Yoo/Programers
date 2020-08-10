#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(string s) 
{
    int answer = s.size();
    for (int i = 1; i <= (s.size() >> 1); ++i)
    {
        string prev(s.begin(), s.begin() + i);
        string newStr;
        int cnt = 1;
        int j;
        for (j = i; j < s.size(); j += i)
        {
            string tmp = s.substr(j, i);
            if (prev == tmp)
                ++cnt;
            else
            {
                if (cnt == 1)
                    newStr += prev;
                else
                    newStr += to_string(cnt) + prev;
                prev = tmp;
                cnt = 1;
            }
        }
        if (cnt == 1)
            newStr += prev;
        else
            newStr += to_string(cnt) + prev;
        if (answer > newStr.size())
            answer = newStr.size();
    }
    return answer;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string in;
    getline(cin, in);
    int ret = solution(in);
    cout << ret;

    return 0;
}