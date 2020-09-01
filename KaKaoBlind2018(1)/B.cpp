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

// #include <string>
// #include <regex>
// #include <iostream>

// using namespace std;

// int solution(string dartResult) {
//     int answer = 0;
    
//     int game[3] = { 0, };
//     regex re("([0-9]+)(S|D|T)(\\*|#*)");
//     int pos = 0;
//     for (auto i = sregex_iterator(dartResult.begin(), dartResult.end(), re); i != sregex_iterator(); ++i)
//     {
//         game[pos] = stoi(i->str(1));
//         if (i->str(2) == "D")
//             game[pos] *= game[pos];
//         else if (i->str(2) == "T")
//             game[pos] *= game[pos] * game[pos];
        
//         if (i->str(3) == "*")
//         {
//             game[pos] <<= 1;
//             if (pos - 1 >= 0)
//                 game[pos - 1] <<= 1;
//         }
//         else if (i->str(3) == "#")
//             game[pos] *= -1;
        
//         ++pos;
//     }
//     answer += game[0] + game[1] + game[2];
    
//     return answer;
// }