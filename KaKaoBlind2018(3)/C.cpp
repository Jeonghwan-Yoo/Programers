#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    multimap<pair<string, int>, string> newFiles;
    int n = (int)files.size();
    for (int i = 0; i < n; ++i)
    {
        string head;
        int pos = 0;
        while (!isdigit(files[i][pos]))
        {
            head += tolower(files[i][pos]);
            ++pos;
        }
        string num;
        while (isdigit(files[i][pos]))
        {
            if (!num.empty() || ('1' <= files[i][pos] && files[i][pos] <= '9'))
                num += files[i][pos];
            ++pos;
        }
        if (num.empty())
            num += "0";
        newFiles.insert(make_pair(make_pair(head, stoi(num)), files[i]));
    }
    for (auto &i : newFiles)
        answer.emplace_back(i.second);
    
    return answer;
}

// #include <string>
// #include <vector>
// #include <algorithm>
// #include <iostream>

// using namespace std;

// bool Comp(string a, string b)
// {
//     transform(a.begin(), a.end(), a.begin(), ::tolower);
//     transform(b.begin(), b.end(), b.begin(), ::tolower);
//     string headA, headB;
//     int posA = 0;
//     int posB = 0;
//     while (!isdigit(a[posA]))
//     {
//         headA += a[posA];
//         ++posA;
//     }
//     while (!isdigit(b[posB]))
//     {
//         headB += b[posB];
//         ++posB;
//     }
//     if (headA != headB)
//         return headA < headB;
    
//     string numA, numB;
//     while (isdigit(a[posA]))
//     {
//         if ((int)numA.size() > 0 || '1' <= a[posA] && a[posA] <= '9')
//             numA += a[posA];
//         ++posA;
//     }
//     while (isdigit(b[posB]))
//     {
//         if ((int)numB.size() > 0 || '1' <= b[posB] && b[posB] <= '9')
//             numB += b[posB];
//         ++posB;
//     }
//     if (numA.empty())
//         numA += "0";
//     if (numB.empty())
//         numB += "0";
//     int numberA = stoi(numA);
//     int numberB = stoi(numB);
//     if (numberA != numberB)
//         return numberA < numberB;
    
//     return 0;
// }

// vector<string> solution(vector<string> files) {
//     vector<string> answer;
    
//     int n = (int)files.size();
//     stable_sort(files.begin(), files.end(), Comp);
//     for (int i = 0; i < n; ++i)
//         answer.emplace_back(files[i]);
    
//     return answer;
// }