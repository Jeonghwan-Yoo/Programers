#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Trie
{
    Trie *node[26];
    int cnt;
    int terminal;
    Trie() : terminal(0), cnt(0)
    {
        for (int i = 0; i < 26; ++i)
            node[i] = nullptr;
    }
    ~Trie()
    {
        for (int i = 0; i < 26; ++i)
            if (node[i] != nullptr)
                delete node[i];
    }
    void Insert(string const &s)
    {
        Trie *cur = this;
        for (int i = 0; i < (int)s.size(); ++i)
        {
            int alpha = s[i] - 'a';
            if (cur->node[alpha] == nullptr)
                cur->node[alpha] = new Trie();
            ++cur->cnt;
            cur = cur->node[alpha];
        }
        cur->terminal = 1;
    }
    int Find(string const &s)
    {
        Trie *cur = this;
        for (int i = 0; i < (int)s.size(); ++i)
        {
            if (s[i] == '?')
                return cur->cnt;
            
            int alpha = s[i] - 'a';
            if (cur->node[alpha] == nullptr)
                return 0;
            cur = cur->node[alpha];
        }
        return cur->terminal;
    }
};

Trie *trie[10001];
Trie *rtrie[10001];

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    
    for (int i = 0; i < (int)words.size(); ++i)
    {
        int n = (int)words[i].size();
        if (trie[n] == nullptr)
        {
            trie[n] = new Trie();
            rtrie[n] = new Trie();
        }
        trie[n]->Insert(words[i]);
        reverse(words[i].begin(), words[i].end());
        rtrie[n]->Insert(words[i]);
    }
    
    for (int i = 0; i < (int)queries.size(); ++i)
    {
        int n = (int)queries[i].size();
        if (trie[n] == nullptr)
            answer.emplace_back(0);
        else if (queries[i][0] == '?')
        {
            reverse(queries[i].begin(), queries[i].end());
            answer.emplace_back(rtrie[n]->Find(queries[i]));
        }
        else
            answer.emplace_back(trie[n]->Find(queries[i]));
    }
    
    for (int i = 0; i < 10001; ++i)
    {
        if (trie[i] != nullptr)
        {
            delete trie[i];
            delete rtrie[i];
        }
    }
    
    return answer;
}

// #include <string>
// #include <vector>
// #include <algorithm>
// #include <iostream>

// using namespace std;

// bool Cmp(string const &a, string const &b)
// {
//     if ((int)a.size() == (int)b.size())
//         return a < b;
//     return (int)a.size() < (int)b.size();
// }

// int FindBetween(vector<string> const &words, string &queries)
// {
//     int pos = 0;
//     while (pos < (int)queries.size() && queries[pos] != '?')
//         ++pos;

//     for (int i = pos; i < (int)queries.size(); ++i)
//         queries[i] = 'a';
//     auto l = lower_bound(words.begin(), words.end(), queries, Cmp);
    
//     for (int i = pos; i < (int)queries.size(); ++i)
//         queries[i] = 'z';
//     auto r = upper_bound(words.begin(), words.end(), queries, Cmp);
    
//     return r - l;
// }

// vector<int> solution(vector<string> words, vector<string> queries) {
//     vector<int> answer;
    
//     vector<string> rwords(words);
//     for (int i = 0; i < (int)rwords.size(); ++i)
//         reverse(rwords[i].begin(), rwords[i].end());
    
//     sort(words.begin(), words.end(), Cmp);
//     sort(rwords.begin(), rwords.end(), Cmp);
    
//     for (int i = 0; i < (int)queries.size(); ++i)
//     {
//         if (queries[i][0] == '?')
//         {
//             reverse(queries[i].begin(), queries[i].end());
//             answer.emplace_back(FindBetween(rwords, queries[i]));
//         }
//         else
//             answer.emplace_back(FindBetween(words, queries[i]));
//     }
    
//     return answer;
// }