#include <string>
#include <vector>
#include <regex>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string word, vector<string> pages) {
    int answer = 0;
    
    int n = (int)pages.size();
    vector<int> basic(n);
    vector<int> external(n);
    vector<double> link(n);
    vector<double> matching(n);
    
    unordered_map<string, int> um;
    
    regex reUrl("content=\"https://(.+?)\"\/>");
    regex reLink("<a href=\"https://(.+?)\">");    
    
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    
    for (int i = 0; i < n; ++i)
    {
        transform(pages[i].begin(), pages[i].end(), pages[i].begin(), ::tolower);
        int l = pages[i].find("<head>");
        int r = pages[i].find("</head>");
        for (auto j = sregex_iterator(pages[i].begin() + l, pages[i].begin() + r, reUrl); j != sregex_iterator(); ++j)
            um[j->str(1)] = i;
        
        l = pages[i].find("<body>");
        r = pages[i].find("</body>");

        int pos = pages[i].find(word, l + 1);
        while (pos != string::npos && pos < r)
        {
            if (!isalpha(pages[i][pos - 1]) && !isalpha(pages[i][pos + (int)word.size()]))
                ++basic[i];
            
            pos = pages[i].find(word, pos + 1);
        }
        
        for (auto j = sregex_iterator(pages[i].begin() + l, pages[i].begin() + r, reLink); j != sregex_iterator(); ++j)
            ++external[i];
    }
    
    for (int i = 0; i < n; ++i)
    {
        int l = pages[i].find("<body>");
        int r = pages[i].find("</body>");
        for (auto j = sregex_iterator(pages[i].begin() + l, pages[i].begin() + r, reLink); j != sregex_iterator(); ++j)
            if (um.count(j->str(1)))
                link[um[j->str(1)]] += (double)basic[i] / external[i];
    }
    
    double maxVal = 0.0;
    for (int i = 0; i < n; ++i)
    {
        matching[i] = basic[i] + link[i];
        if (maxVal < matching[i])
        {
            maxVal = matching[i];
            answer = i;
        }
    }
    
    return answer;
}