#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define MUL 65536

int solution(string str1, string str2) {
    int answer = 0;
    
    int n1 = (int)str1.size();
    int n2 = (int)str2.size();
    vector<int> hash1(26 * 26);
    vector<int> hash2(26 * 26);
    for (int i = 0; i < n1; ++i)
        if (str1[i] >= 'A' && str1[i] <= 'Z')
            str1[i] = str1[i] - 'A' + 'a';
    for (int i = 0; i < n2; ++i)
        if (str2[i] >= 'A' && str2[i] <= 'Z')
            str2[i] = str2[i] - 'A' + 'a';
    
    for (int i = 0; i < n1 - 1; ++i)
        if (isalpha(str1[i]) && isalpha(str1[i + 1]))
            ++hash1[(str1[i] - 'a') * 26 + (str1[i + 1] - 'a')];
    for (int i = 0; i < n2 - 1; ++i)
        if (isalpha(str2[i]) && isalpha(str2[i + 1]))
            ++hash2[(str2[i] - 'a') * 26 + (str2[i + 1] - 'a')];
    
    int uni = 0;
    int inter = 0;
    for (int i = 0; i < 26 * 26; ++i)
    {
        uni += max(hash1[i], hash2[i]);
        inter += min(hash1[i], hash2[i]);
    }

    if (uni == 0 && inter == 0)
        answer = MUL;
    else
        answer = (double)inter / uni * MUL;
    
    return answer;
}