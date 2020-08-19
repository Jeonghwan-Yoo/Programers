#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    vector<string> uidSet;
    vector<int> typeSet;
    vector<string> messageSet;
    messageSet.emplace_back("님이 들어왔습니다.");
    messageSet.emplace_back("님이 나갔습니다.");

    unordered_map<string, string> uidToName;
    for (int i = 0; i < (int)record.size(); ++i)
    {
        stringstream ss(record[i]);
        string uid, name;
        if (record[i][0] == 'E')
        {
            ss >> uid;
            ss >> uid;
            ss >> name;
            uidToName[uid] = name;
            uidSet.emplace_back(uid);
            typeSet.emplace_back(0);
        }
        else if (record[i][0] == 'L')
        {
            ss >> uid;
            ss >> uid;
            uidSet.emplace_back(uid);
            typeSet.emplace_back(1);
        }
        else
        {
            ss >> uid;
            ss >> uid;
            ss >> name;
            uidToName[uid] = name;
        }
    }
    
    for (int i = 0; i < (int)uidSet.size(); ++i)
        answer.emplace_back(uidToName[uidSet[i]] + messageSet[typeSet[i]]);
    
    return answer;
}