#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for (int i = 0; i < n; ++i)
    {
        int val = arr1[i] | arr2[i];
        string s;
        for (int j = 0; j < n; ++j)
        {
            if (val & 1)
                s += '#';
            else
                s += ' ';
            val >>= 1;
        }
        reverse(s.begin(), s.end());
        answer.emplace_back(s);
    }
    
    return answer;
}