#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

bool CheckPillar(int x, int y, vector<vector<int> > &pillar, vector<vector<int> > &beam)
{
    if (y == 0 || pillar[y - 1][x] == 1 || beam[y][x - 1] == 1 || beam[y][x] == 1)
        return true;
    return false;
}

bool CheckBeam(int x, int y, vector<vector<int> > &pillar, vector<vector<int> > &beam)
{
    if (pillar[y - 1][x] == 1 || pillar[y - 1][x + 1] == 1 || (beam[y][x - 1] == 1 && beam[y][x + 1] == 1))
        return true;
    return false;
}

void Insert(int x, int y, int type, vector<vector<int> > &pillar, vector<vector<int> > &beam, set<vector<int> > &build)
{
    if (type == 0)
    {
        if (CheckPillar(x, y, pillar, beam) == false)
            return;
        pillar[y][x] = 1;
    }
    else
    {
        if (CheckBeam(x, y, pillar, beam) == false)
            return;
        beam[y][x] = 1;
    }
    build.insert({ x, y, type });
}

void Delete(int x, int y, int type, vector<vector<int> > &pillar, vector<vector<int> > &beam, set<vector<int> > &build)
{
    if (type == 0)
    {
        pillar[y][x] = 0;
        if (pillar[y + 1][x] == 1 && CheckPillar(x, y + 1, pillar, beam) == false)
        {
            pillar[y][x] = 1;
            return;
        }
        else if (beam[y + 1][x - 1] == 1 && CheckBeam(x - 1, y + 1, pillar, beam) == false)
        {
            pillar[y][x] = 1;
            return;
        }
        else if (beam[y + 1][x] == 1 && CheckBeam(x, y + 1, pillar, beam) == false)
        {
            pillar[y][x] = 1;
            return;
        }
    }
    else
    {
        beam[y][x] = 0;
        if (pillar[y][x] == 1 && CheckPillar(x, y, pillar, beam) == false)
        {
            beam[y][x] = 1;
            return;
        }
        else if (pillar[y][x + 1] == 1 && CheckPillar(x + 1, y, pillar, beam) == false)
        {
            beam[y][x] = 1;
            return;
        }
        if (beam[y][x - 1] == 1 && CheckBeam(x - 1, y, pillar, beam) == false)
        {
            beam[y][x] = 1;
            return;
        }
        if (beam[y][x + 1] == 1 && CheckBeam(x + 1, y, pillar, beam) == false)
        {
            beam[y][x] = 1;
            return;
        }
    }
    build.erase({ x, y, type });
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    set<vector<int> > build;    
    vector<vector<int> > beam(n + 1, vector<int>(n + 1));
    vector<vector<int> > pillar(n + 1, vector<int>(n + 1));
    for (auto &b : build_frame)
    {
        if (b[3] == 1)
            Insert(b[0], b[1], b[2], pillar, beam, build);
        else
            Delete(b[0], b[1], b[2], pillar, beam, build);
    }
    for (auto &b : build)
        answer.push_back(b);
    
    return answer;
}