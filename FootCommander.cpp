#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include "FootCommander.hpp"
void WarGame::FootCommander::Full_attack(WarGame::Soldier &other, std::vector<std::vector<WarGame::Soldier *>> board, std::pair<int, int> p)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (((board[i][j] != nullptr) && (board[i][j]->player_number == other.player_number)))
            {
                if ((dynamic_cast<FootSoldier *>(board[i][j])))
                {
                    std::pair<int, int> n = distance(board, i, j, other.player_number);
                    Basic_attack(*board[i][j], board, n);
                }
            }
        }
    }
}
void WarGame::FootCommander::Basic_attack(WarGame::Soldier &other, std::vector<std::vector<WarGame::Soldier *>> board, std::pair<int, int> p)
{
    int i = (int)p.first;
    int j = (int)p.second;
    //cout << "attacker demage : " << other.player_damge << " attacked : " << i << "," << j << endl;
    if (board[i][j]->player_health <= 20)
    {
        board[i][j]->player_health = 0;
    }
    else
    {
        board[i][j]->player_health =
            board[i][j]->player_health - other.player_damge;
    }
}