#include <string>
#include <vector>
#include <regex>
#include <algorithm>
#include <iostream>

using namespace std;

string sharpToLower(string const &s)
{
    int n = (int)s.size();
    string ret;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '#')
            ret.back() += 'a' - 'A';
        else
            ret += s[i];
    }
    
    return ret;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    
    m = sharpToLower(m);
    
    int maxTime = 0;
    int n = (int)musicinfos.size();
    for (int i = 0; i < n; ++i)
    {
        string musicinfo = musicinfos[i];
        int startTime = stoi(musicinfo.substr(0, 2)) * 60 + stoi(musicinfo.substr(3, 2));
        int endTime = stoi(musicinfo.substr(6, 2)) * 60 + stoi(musicinfo.substr(9, 2));
        int diffTime = endTime - startTime;
        int comma = musicinfo.find(",", 12);
        string title = musicinfo.substr(12, comma - 12);
        string info = sharpToLower(musicinfo.substr(comma + 1));
        int szInfo = (int)info.size();
        if (szInfo < diffTime)
        {
            for (int j = szInfo; j < diffTime; ++j)
                info += info[j % szInfo];
        }
        else
            info = info.substr(0, diffTime);

        if (info.find(m) != string::npos && maxTime < diffTime)
        {
            answer = title;
            maxTime = diffTime;
        }
    }
    if (answer.empty())
        answer = "(None)";
    
    return answer;
}

// #include <string>
// #include <vector>
// #include <regex>
// #include <algorithm>
// #include <iostream>

// using namespace std;

// string sharpToLower(string const &s)
// {
//     int n = (int)s.size();
//     string ret;
//     for (int i = 0; i < n; ++i)
//     {
//         if (s[i] == '#')
//             ret.back() += 'a' - 'A';
//         else
//             ret += s[i];
//     }
    
//     return ret;
// }

// string solution(string m, vector<string> musicinfos) {
//     string answer = "";
    
//     m = sharpToLower(m);
    
//     int maxTime = 0;
//     int n = (int)musicinfos.size();
//     regex re("(.+):(.+),(.+):(.+),(.+),(.+)");
//     for (int i = 0; i < n; ++i)
//     {
//         smatch match;
//         if (regex_search(musicinfos[i], match, re))
//         {
//             int startTime = stoi(match.str(1)) * 60 + stoi(match.str(2));
//             int endTime = stoi(match.str(3)) * 60 + stoi(match.str(4));
//             int diffTime = endTime - startTime;
//             string title = match.str(5);
//             string info = sharpToLower(match.str(6));
//             int szInfo = (int)info.size();
//             if (szInfo < diffTime)
//             {
//                 for (int j = szInfo; j < diffTime; ++j)
//                     info += info[j % szInfo];
//             }
//             else
//                 info = info.substr(0, diffTime);
            
//             if (info.find(m) != string::npos && maxTime < diffTime)
//             {
//                 answer = title;
//                 maxTime = diffTime;
//             }
//         }
//     }
//     if (answer.empty())
//         answer = "(None)";
    
//     return answer;
// }