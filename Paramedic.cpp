#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <cstdio>
#include "Paramedic.hpp"

using namespace std;

void WarGame::Paramedic::Full_attack(WarGame::Soldier &other, std::vector<std::vector<WarGame::Soldier *>> board, std::pair<int, int> p)
{
    int i = (int)p.first;
    int j = (int)p.second;
    Basic_attack(*board[i][j], board, p);
}
void WarGame::Paramedic::Basic_attack(WarGame::Soldier &other, std::vector<std::vector<WarGame::Soldier *>> board, std::pair<int, int> p)
{
    
    int i = (int)p.first;
    int j = (int)p.second;
    // cout << "attacker heal full : "<< " Healed : " << i << "," << j << endl;
    if (board[i][j]->player_health <= 0)
    {
        board[i][j] = 0;
    }
    else
    {
        board[i][j]->player_health = board[i][j]->full_health;
    }
}
std::pair<uint, uint> WarGame::Paramedic::distance(vector<vector<Soldier *>> board, int f_index, int s_index, int s)
{
    std::pair<int, int> ans;
    double min = 100.0;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (((i == f_index) && (j != s_index)) || ((i != f_index) && (j == s_index)))
            {
                if ((board[i][j] != nullptr) && (board[i][j]->player_number == s))
                {
                    double p1 = pow(i - f_index, 2);
                    double p2 = pow(j - s_index, 2);
                    double first_sq = sqrt(p1 + p2);
                    if ((min == first_sq) && (board[i][j]->full_health != board[i][j]->player_health))
                    {
                        min = first_sq;
                        ans.first = i;
                        ans.second = j;
                    }
                    else if (first_sq < min)
                    {
                        min = first_sq;
                        ans.first = i;
                        ans.second = j;
                    }
                }
            }
        }
    }

    return ans;
}