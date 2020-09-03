#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    int n = (int)board.size();
    while (1)
    {
        bool changed = false;
        for (int y = 0; y < n; ++y)
        {
            for (int x = 0; x < n; ++x)
            {
                if (x + 1 < n && y + 2 < n)
                {
                    if (board[y][x] != 0)
                    {
                        int num = board[y][x];
                        if (board[y + 1][x] == num && board[y + 2][x] == num && board[y + 2][x + 1] == num)
                        {
                            bool flag = true;
                            for (int i = y + 1; i >= 0; --i)
                            {
                                if (board[i][x + 1])
                                {
                                    flag = false;
                                    break;
                                }
                            }
                            if (flag)
                            {
                                ++answer;
                                board[y][x] = board[y + 1][x] = board[y + 2][x] = board[y + 2][x + 1] = 0;
                                changed = true;
                                continue;
                            }
                        }
                    }
                    if (board[y][x + 1] != 0)
                    {
                        int num = board[y][x + 1];
                        if (board[y + 1][x + 1] == num && board[y + 2][x] == num && board[y + 2][x + 1] == num)
                        {
                            bool flag = true;
                            for (int i = y + 1; i >= 0; --i)
                            {
                                if (board[i][x])
                                {
                                    flag = false;
                                    break;
                                }
                            }
                            if (flag)
                            {
                                ++answer;
                                board[y][x + 1] = board[y + 1][x + 1] = board[y + 2][x] = board[y + 2][x + 1] = 0;
                                changed = true;
                                continue;
                            }
                        }
                    }
                }
                if (x + 2 < n && y + 1 < n)
                {
                    if (board[y][x] != 0)
                    {
                        int num = board[y][x];
                        if (board[y + 1][x] == num && board[y + 1][x + 1] == num && board[y + 1][x + 2] == num)
                        {
                            bool flag = true;
                            for (int i = y; i >= 0; --i)
                            {
                                if (board[i][x + 1] || board[i][x + 2])
                                {
                                    flag = false;
                                    break;
                                }
                            }
                            if (flag)
                            {
                                ++answer;
                                board[y][x] = board[y + 1][x] = board[y + 1][x + 1] = board[y + 1][x + 2] = 0;
                                changed = true;
                                continue;
                            }
                        }
                    }
                    if (board[y][x + 1] != 0)
                    {
                        int num = board[y][x + 1];
                        if (board[y + 1][x] == num && board[y + 1][x + 1] == num && board[y + 1][x + 2] == num)
                        {
                            bool flag = true;
                            for (int i = y; i >= 0; --i)
                            {
                                if (board[i][x] || board[i][x + 2])
                                {
                                    flag = false;
                                    break;
                                }
                            }
                            if (flag)
                            {
                                ++answer;
                                board[y][x + 1] = board[y + 1][x] = board[y + 1][x + 1] = board[y + 1][x + 2] = 0;
                                changed = true;
                                continue;
                            }
                        }
                    }
                    if (board[y][x + 2] != 0)
                    {
                        int num = board[y][x + 2];
                        if (board[y + 1][x] == num && board[y + 1][x + 1] == num && board[y + 1][x + 2] == num)
                        {
                            bool flag = true;
                            for (int i = y; i >= 0; --i)
                            {
                                if (board[i][x] || board[i][x + 1])
                                {
                                    flag = false;
                                    break;
                                }
                            }
                            if (flag)
                            {
                                ++answer;
                                board[y][x + 2] = board[y + 1][x] = board[y + 1][x + 1] = board[y + 1][x + 2] = 0;
                                changed = true;
                                continue;
                            }
                        }
                    }
                }
            }
        }
        if (changed == false)
            break;
    }
    
    return answer;
}