#include <string>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    
    int n = (int)dartResult.size();
    int game[3] = { 0, };
    int pos = 0;
    string num;
    for (int i = 0; i < n; ++i)
    {
        if (dartResult[i] == '#')
            game[pos - 1] *= -1;
        else if (dartResult[i] == '*')
        {
            game[pos - 1] <<= 1;
            if (pos - 2 >= 0)
                game[pos - 2] <<= 1;
        }
        else if (dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T')
        {
            game[pos] = stoi(num);
            if (dartResult[i] == 'D') 
                game[pos] *= game[pos];
            else if (dartResult[i] == 'T')
                game[pos] *= game[pos] * game[pos];
            num.clear();
            ++pos;
        }
        else
            num += dartResult[i];
    }
    answer = game[0] + game[1] + game[2];
    
    return answer;
}