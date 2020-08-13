#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int constexpr dx[4] = { 0, 1, 0, -1 };
int constexpr dy[4] = { -1, 0, 1, 0 };

enum Dir
{
    Up = 0,
    Right = 1,
};

struct Robot
{
    int x, y, d;
    Robot(int x, int y, int d) : x(x), y(y), d(d) {}
};

int visited[101][101][2];

void Move(vector<Robot> &v, Robot const &cur)
{
    for (int dir = 0; dir < 4; ++dir)
        v.emplace_back(cur.x + dx[dir], cur.y + dy[dir], cur.d);
}

void Rotate(vector<Robot> &v, Robot const &cur, vector<vector<int> > const &board)
{
    int n = (int)board.size();
    if (cur.d == Dir::Right)
    {
        if (cur.y - 1 >= 0 && board[cur.y - 1][cur.x + 1] == 0)
            v.emplace_back(cur.x, cur.y, Dir::Up);
        if (cur.y + 1 < n && board[cur.y + 1][cur.x + 1] == 0)
            v.emplace_back(cur.x, cur.y + 1, Dir::Up);
        if (cur.y - 1 >= 0 && board[cur.y - 1][cur.x] == 0)
            v.emplace_back(cur.x + 1, cur.y, Dir::Up);
        if (cur.y + 1 < n && board[cur.y + 1][cur.x] == 0)
            v.emplace_back(cur.x + 1, cur.y + 1, Dir::Up);
    }
    else
    {
        if (cur.x - 1 >= 0 && board[cur.y][cur.x - 1] == 0)
            v.emplace_back(cur.x - 1, cur.y - 1, Dir::Right);
        if (cur.x + 1 < n && board[cur.y][cur.x + 1] == 0)
            v.emplace_back(cur.x, cur.y - 1, Dir::Right);
        if (cur.x - 1 >= 0 && board[cur.y - 1][cur.x - 1] == 0)
            v.emplace_back(cur.x - 1, cur.y, Dir::Right);
        if (cur.x + 1 < n && board[cur.y - 1][cur.x + 1] == 0)
            v.emplace_back(cur.x, cur.y, Dir::Right);
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;

    int n = (int)board.size();
    Robot robot(0, 0, Dir::Right);
    queue<pair<Robot, int> > q;
    q.emplace(robot, 0);
    visited[0][0][Dir::Right] = true;
    while (!q.empty())
    {
        Robot cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        vector<Robot> nxt;
        Move(nxt, cur);
        Rotate(nxt, cur, board);
        for (int i = 0; i < (int)nxt.size(); ++i)
        {
            if (nxt[i].x < 0 || nxt[i].x + dx[nxt[i].d] >= n || nxt[i].y + dy[nxt[i].d] < 0 || nxt[i].y >= n)
                continue;
            if (visited[nxt[i].y][nxt[i].x][nxt[i].d] == true)
                continue;
            visited[nxt[i].y][nxt[i].x][nxt[i].d] = true;
            if (board[nxt[i].y][nxt[i].x] == 0 && board[nxt[i].y + dy[nxt[i].d]][nxt[i].x + dx[nxt[i].d]] == 0)
            {
                if ((nxt[i].x == n - 1 && nxt[i].y == n - 1) || (nxt[i].x + dx[nxt[i].d] == n - 1 && nxt[i].y + dy[nxt[i].d] == n - 1))
                {
                    answer = cnt + 1;
                    break;
                }
                q.emplace(nxt[i], cnt + 1);
            }
        }
        if (answer != 0)
            break;
    }

    return answer;
}