#include <string>
#include <vector>
#include <stdexcept>
#include <math.h>
#include <iostream>
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"

using namespace WarGame;
using namespace std;
std::pair<uint, uint> WarGame::Soldier::distance(vector<vector<Soldier *>> board, int f_index, int s_index, int s)
{
    std::pair<int, int> ans;
    int min = 100;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if ((board[i][j] != nullptr) && (board[i][j]->player_number != s))
            {
                if (board[i][j]->player_health > 0)
                {
                    if (sqrt(pow(i - f_index, 2) + pow(j - s_index, 2)) <= min)
                    {
                        min = sqrt(pow(i - f_index, 2) + pow(j - s_index, 2));
                        ans.first = i;
                        ans.second = j;
                    }
                }
            }
        }
    }

    return ans;
}
