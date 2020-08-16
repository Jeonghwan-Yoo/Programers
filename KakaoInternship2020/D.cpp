#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

#define INF 375000

int constexpr dx[4] = { 0, 1, 0, -1 };
int constexpr dy[4] = { -1, 0, 1, 0 };

struct Road
{
    int x, y;
    int d;
    Road(int x, int y, int d) : x(x), y(y), d(d) {}
};

int solution(vector<vector<int>> board) {
    int answer = INF;
    
    int n = (int)board.size();
    vector<vector<vector<int> > > dp(n, vector<vector<int> >(n, vector<int>(4)));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < 4; ++k)
                dp[i][j][k] = INF;
    
    queue<Road> q;
    for (int i = 0; i < 4; ++i)
    {
        q.emplace(0, 0, i);
        dp[0][0][i] = 0;
    }
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().d;
        int c = dp[y][x][d];
        q.pop();
        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nd = dir;
            int nc = c + (d == dir ? 100 : 600);
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            
            if (dp[ny][nx][nd] > nc && board[ny][nx] == 0)
            {
                dp[ny][nx][nd] = nc;
                if (ny != n - 1 || nx != n - 1)
                    q.emplace(nx, ny, nd);
            }
        }
    }
    for (int i = 0; i < 4; ++i)
        answer = min(answer, dp[n - 1][n - 1][i]);
    
    return answer;
}