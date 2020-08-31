#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    unordered_map<string, int> cache;
    int n = (int)cities.size();
    for (int i = 0; i < n; ++i)
    {
        for (auto &c : cities[i])
            c = tolower(c);
        
        if (cache.count(cities[i]))
        {
            ++answer;
            cache[cities[i]] = i;
        }
        else
        {
            answer += 5;
            if (cacheSize != 0 && (int)cache.size() >= cacheSize)
            {
                string minKey;
                int minVal = n;
                for (auto &c : cache)
                {
                    if (minVal > c.second)
                    {
                        minVal = c.second;
                        minKey = c.first;
                    }
                }
                cache.erase(minKey);
            }
            if ((int)cache.size() < cacheSize)
                cache[cities[i]] = i;
        }
    }
    
    return answer;
}