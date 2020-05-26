
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include "FootSoldier.hpp"

void WarGame::FootSoldier::Full_attack(WarGame::Soldier &other, std::vector<std::vector<WarGame::Soldier *>> board, std::pair<int, int> p)
{
    Basic_attack(other, board, p);
}
void WarGame::FootSoldier::Basic_attack(WarGame::Soldier &other, std::vector<std::vector<WarGame::Soldier *>> board, std::pair<int, int> p)
{
    int i = (int)p.first;
    int j = (int)p.second;
   // cout << "attacker demage : " << other.player_damge << " attacked : " << i << "," << j << endl;
      if (board[i][j]->player_health <= 10)
    {
        board[i][j]->player_health = 0;
    }
    else
    {
        board[i][j]->player_health =
            board[i][j]->player_health - other.player_damge;
    }
}
