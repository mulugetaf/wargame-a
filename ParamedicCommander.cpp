#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include "ParamedicCommander.hpp"

void WarGame::ParamedicCommander::Full_attack(WarGame::Soldier &other, std::vector<std::vector<WarGame::Soldier *>> board, std::pair<int, int> p)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (((board[i][j] != nullptr) && (board[i][j]->player_number == other.player_number)))
            {
                if ((dynamic_cast<Paramedic *>(board[i][j])))
                {
                    Basic_attack(*board[i][j], board, p);
                }
            }
        }
    }
}
void WarGame::ParamedicCommander::Basic_attack(WarGame::Soldier &other, std::vector<std::vector<WarGame::Soldier *>> board, std::pair<int, int> p)
{
    int i = (int)p.first;
    int j = (int)p.second;
    //cout << "attacker heal full : "<< " Healed : " << i << "," << j << endl;
    if (board[i][j]->player_health <= 0)
    {
        board[i][j] = 0;
    }
    else
    {
        board[i][j]->player_health = board[i][j]->full_health;
    }
}