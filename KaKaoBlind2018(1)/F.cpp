#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int constexpr dx[3] = { 1, 1, 0 };
int constexpr dy[3] = { 0, 1, 1 };

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while (1)
    {
        vector<pair<int, int> > willErase;
        for (int i = 0; i < m - 1; ++i)
        {
            for (int j = 0; j < n - 1; ++j)
            {
                if (board[i][j])
                {
                    int cnt = 1;
                    for (int dir = 0; dir < 3; ++dir)
                        if (board[i][j] == board[i + dy[dir]][j + dx[dir]])
                            ++cnt;
                    if (cnt == 4)
                        willErase.emplace_back(j, i);
                }
            }
        }

        if (willErase.empty())
            break;

        for (int i = 0; i < (int)willErase.size(); ++i)
        {
            int x = willErase[i].first;
            int y = willErase[i].second;
            if (board[y][x])
            {
                board[y][x] = 0;
                ++answer;
            }
            for (int dir = 0; dir < 3; ++dir)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (board[ny][nx])
                {
                    board[ny][nx] = 0;
                    ++answer;
                }
            }
        }

        for (int j = 0; j < n; ++j)
        {
            for (int l = m - 1, r = m - 1; l >= 0; --l)
            {
                if (!board[l][j])
                    continue;
                
                swap(board[l][j], board[r][j]);
                --r;
            }
        }
    }

    return answer;
}