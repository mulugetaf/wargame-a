
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include "Sniper.hpp"
void WarGame::Sniper::Full_attack(WarGame::Soldier &other, std::vector<std::vector<WarGame::Soldier *>> board, std::pair<int, int> p)
{
    Basic_attack(other, board, p);
}
void WarGame::Sniper::Basic_attack(WarGame::Soldier &other, std::vector<std::vector<WarGame::Soldier *>> board, std::pair<int, int> p)
{
    int imax = p.first, jmax = p.second;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if ((board[i][j] != nullptr) && (board[i][j]->player_number != other.player_number))
            {
                if ((board[i][j]->player_health > board[imax][jmax]->player_health)&&(board[i][j]->player_health >0))
                {
                    imax = i;
                    jmax = j;
                }
            }
        }
    }
   // cout<<"attacker demage : "<<other.player_damge<<" attacked : "<< imax<<","<<jmax<<endl;

    if (board[imax][jmax]->player_health <= 50)
    {
        board[imax][jmax]->player_health = 0;
    }
    else
    {
        board[imax][jmax]->player_health =
            board[imax][jmax]->player_health - other.player_damge;
    }
}