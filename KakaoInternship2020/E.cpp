#include <string>
#include <vector>

using namespace std;

vector<int> adj[200001];
bool visited[200001];
int required[200001];
int hang[200001];

void Dfs(int src)
{
    if (visited[src] == true)
        return;

    if (visited[required[src]] == false)
    {
        hang[required[src]] = src;
        return;
    }

    visited[src] = true;
    Dfs(hang[src]);
    for (auto &a : adj[src])
        Dfs(a);
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;

    for (auto &p : path)
    {
        adj[p[0]].emplace_back(p[1]);
        adj[p[1]].emplace_back(p[0]);
    }

    for (auto &o : order)
        required[o[1]] = o[0];

    if (required[0] != 0)
        return false;

    visited[0] = true;
    for (auto &a : adj[0])
        Dfs(a);

    for (int i = 0; i < n; ++i)
        if (visited[i] == false)
            return false;

    return answer;
}

// #include <string>
// #include <vector>
// #include <queue>
// #include <iostream>

// using namespace std;

// vector<int> children[200001];
// vector<int> adj[200001];
// int visited[200001];
// int finished[200001];

// bool HasCycle(int src)
// {
//     bool ret = false;
//     visited[src] = true;
//     for (auto &c : children[src])
//     {
//         if (visited[c] == false)
//             ret |= HasCycle(c);
//         else if (finished[c] == false)
//             return true;
//     }
    
//     finished[src] = true;
//     return ret;
// }

// bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
//     bool answer = true;
    
//     for (auto &p : path)
//     {
//         adj[p[0]].emplace_back(p[1]);
//         adj[p[1]].emplace_back(p[0]);
//     }
//     queue<int> q;
//     q.emplace(0);
//     visited[0] = true;
//     while (!q.empty())
//     {
//         int u = q.front();
//         q.pop();
//         for (auto &a : adj[u])
//         {
//             if (visited[a] == false)
//             {
//                 visited[a] = true;
//                 children[u].emplace_back(a);
//                 q.emplace(a);
//             }
//         }
//     }
//     for (auto &o : order)
//         children[o[0]].emplace_back(o[1]);
    
//     for (int i = 0; i < n; ++i)
//         visited[i] = false;
    
//     for (int i = 0; i < n; ++i)
//         if (visited[i] == false)
//             if (HasCycle(i) == true)
//                 return false;
    
//     return answer;
// }