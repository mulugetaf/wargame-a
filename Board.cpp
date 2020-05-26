#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include "Soldier.hpp"
#include "FootCommander.hpp"
#include "Board.hpp"
#include "SniperCommander.hpp"
#include "ParamedicCommander.hpp"

using namespace WarGame;
using namespace std;
Soldier *&WarGame::Board::operator[](std::pair<int, int> location)
{

    if (location.first < 0 || location.second < 0)
    {
        throw std::invalid_argument("ilgeal number");
    }

    return board[(int)location.first][(int)location.second];
};
Soldier *WarGame::Board::operator[](std::pair<int, int> location) const
{
    int f_index = (int)location.first;
    int s_index = (int)location.second;
    return board[(int)location.first][(int)location.second];
};
void Board::move(uint player_number, std::pair<int, int> source, WarGame::Board::MoveDIR direction)
{

    int f_index = (int)source.first;
    int s_index = (int)source.second;
    std::pair<int, int> p;
    Soldier *s = board[source.first][source.second];
    if (s == nullptr)
        throw std::invalid_argument("no soldier in the source");
    if (s->player_number != player_number)
        throw std::invalid_argument("the soldier belong to other player");
    //Exception
    if (direction == Up)
    {
        if (f_index == board.size() - 1)
            throw std::out_of_range("out of range");
        if (board[f_index + 1][s_index] != nullptr)
            throw std::out_of_range("there is other playe in the location");

        if (dynamic_cast<Paramedic *>(s))
        {
            p.first = s->distance(board, f_index, s_index, s->player_number).first;
            p.second = s->distance(board, f_index, s_index, s->player_number).second;
            s->Full_attack(*s, board, p);
            checkNnull();
        }
        else
        {
            p.first = s->distance(board, f_index, s_index, s->player_number).first;
            p.second = s->distance(board, f_index, s_index, s->player_number).second;
            s->Full_attack(*s, board, p);
            checkNnull();
        }
        board[source.first + 1][source.second] = board[source.first][source.second];
        board[source.first][source.second] = nullptr;
    }

    if (direction == Down)
    {
        if (f_index == 0)
            throw std::out_of_range("out of range");
        if (board[f_index - 1][s_index] != nullptr)
            throw std::out_of_range("there is other playe in the location");
        if (dynamic_cast<Paramedic *>(s))
        {
            p.first = s->distance(board, f_index, s_index, s->player_number).first;
            p.second = s->distance(board, f_index, s_index, s->player_number).second;
            s->Full_attack(*s, board, p);
            checkNnull();
        }
        else
        {
            p.first = s->distance(board, f_index, s_index, s->player_number).first;
            p.second = s->distance(board, f_index, s_index, s->player_number).second;
            s->Full_attack(*s, board, p);
            checkNnull();
        }

        board[source.first - 1][source.second] = board[source.first][source.second];
        board[source.first][source.second] = nullptr;
    }
    if (direction == Right)
    {
        if (s_index == board.size() - 1)
            throw std::out_of_range("out of range");
        if (board[f_index][s_index + 1] != nullptr)
            throw std::out_of_range("there is other playe in the location");
        if (dynamic_cast<Paramedic *>(s))
        {
            p.first = s->distance(board, f_index, s_index, s->player_number).first;
            p.second = s->distance(board, f_index, s_index, s->player_number).second;
            s->Full_attack(*s, board, p);
            checkNnull();
        }
        else
        {
            p.first = s->distance(board, f_index, s_index, s->player_number).first;
            p.second = s->distance(board, f_index, s_index, s->player_number).second;
            s->Full_attack(*s, board, p);
            checkNnull();
        }
        board[source.first][source.second + 1] = board[source.first][source.second];
        board[source.first][source.second] = nullptr;
    }
    if (direction == Left)
    {
        if (s_index == 0)
            throw std::out_of_range("out of range");
        if (board[f_index][s_index - 1] != nullptr)
            throw std::out_of_range("there is other playe in the location");

        if (dynamic_cast<Paramedic *>(s))
        {
            p.first = s->distance(board, f_index, s_index, s->player_number).first;
            p.second = s->distance(board, f_index, s_index, s->player_number).second;
            s->Full_attack(*s, board, p);
            checkNnull();
        }
        else
        {
            p.first = s->distance(board, f_index, s_index, s->player_number).first;
            p.second = s->distance(board, f_index, s_index, s->player_number).second;
            s->Full_attack(*s, board, p);
            checkNnull();
        }
        board[source.first][source.second - 1] = board[source.first][source.second];
        board[source.first][source.second] = nullptr;
    }
}
bool Board::has_soldiers(uint player_number) const
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            Soldier *s = (*this)[{i, j}];
            if (s != nullptr && (s->player_number) == player_number)
                return true;
        }
    }
    return false;
};
void WarGame::Board::print()
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {

            if (board[i][j] == nullptr)
                cout << "---   ";
            else
                cout << board[i][j]->player_health << "   ";
        }
        cout << endl;
        cout << endl;
    }
};
void WarGame::Board::checkNnull()
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {

            if (((board[i][j] != nullptr) && (board[i][j]->player_health == 0)))
            {
                board[i][j] = nullptr;
            }
        }
    }
};
uint WarGame::Board::get_numRows()
{
    return board.size();
};
uint WarGame::Board::get_numCols()
{
    return board[0].size();
};

