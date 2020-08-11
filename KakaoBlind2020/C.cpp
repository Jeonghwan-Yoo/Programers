#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool Check(vector<vector<int> > const &board, vector<vector<int> > const &lock, int M, int x, int y)
{
    for (int i = y; i < y + M; ++i)
        for (int j = x; j < x + M; ++j)
            if (board[i][j] + lock[i - y][j - x] != 1)
                return false;
    return true;
}

void Rotate(vector<vector<int> > &lock, int M)
{
    vector<vector<int> > tmp(lock);

    for (int i = 0; i < M; ++i)
        for (int j = 0; j < M; ++j)
            lock[j][M - i - 1] = tmp[i][j];
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;

    int N = (int)key.size();
    int M = (int)lock.size();
    vector<vector<int> > board(N + (M << 1), vector<int>(N + (M << 1)));
    for (int i = M; i < N + M; ++i)
        for (int j = M; j < N + M; ++j)
            board[i][j] = key[i - M][j - M];

    for (int dir = 0; dir < 4; ++dir)
    {
        for (int i = 0; i <= N + M; ++i)
            for (int j = 0; j <= N + M; ++j)
                if (Check(board, lock, M, j, i) == true)
                    return true;
        Rotate(lock, M);
    }

    return answer;
}