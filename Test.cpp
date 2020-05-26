#include <stdbool.h>
#include "doctest.h"
#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include "DemoGame.hpp"
#include "Soldier.hpp"
#include "FootCommander.hpp"
#include "SniperCommander.hpp"
#include "ParamedicCommander.hpp"
using namespace WarGame;
using namespace std;

TEST_CASE("Test for move function")
{

    Board board1(8, 8);

    // Add soldiers for player 1:
    assert(!board1.has_soldiers(1));
    board1[{0, 1}] = new Sniper(1);
    board1[{0, 3}] = new SniperCommander(1);
    board1[{0, 5}] = new Paramedic(1);
    board1[{2, 1}] = new ParamedicCommander(1);
    board1[{2, 3}] = new ParamedicCommander(1);
    board1[{2, 5}] = new FootSoldier(1);
    assert(board1.has_soldiers(1));
    // Add soldiers for player 2:
    assert(!board1.has_soldiers(2));
    board1[{5, 1}] = new Sniper(2);
    board1[{5, 3}] = new SniperCommander(2);
    board1[{5, 5}] = new ParamedicCommander(2);
    board1[{7, 1}] = new Paramedic(2);
    board1[{7, 3}] = new SniperCommander(2);
    board1[{7, 5}] = new ParamedicCommander(2);
    assert(board1.has_soldiers(2));
    // cout << "before" << endl;
    // board1.print();
    // board1.move(1, {0, 1}, Board::MoveDIR::Up);
    // board1.move(1, {0, 3}, Board::MoveDIR::Up);
    // board1.move(1, {0, 5}, Board::MoveDIR::Up);
    // board1.move(1, {2, 1}, Board::MoveDIR::Up);
    // board1.move(1, {2, 3}, Board::MoveDIR::Up);
    // board1.move(1, {2, 5}, Board::MoveDIR::Up);

    // cout << "After" << endl;
    // board1.print();
    // board1.move(2, {5, 1}, Board::MoveDIR::Up);
    // board1.move(2, {5, 3}, Board::MoveDIR::Up);
    // board1.move(2, {7, 1}, Board::MoveDIR::Up);
    // cout << "After Heal" << endl;
    // board1.print();
    /*check if given index is out of bound
    up & down
    */
    CHECK_NOTHROW(board1.move(1, {2, 1}, Board::MoveDIR::Up));
    CHECK_NOTHROW(board1.move(1, {2, 3}, Board::MoveDIR::Up));
    CHECK_NOTHROW(board1.move(1, {2, 5}, Board::MoveDIR::Up));
    CHECK_NOTHROW(board1.move(2, {5, 1}, Board::MoveDIR::Up));
    CHECK_NOTHROW(board1.move(2, {5, 3}, Board::MoveDIR::Up));
    CHECK_NOTHROW(board1.move(2, {5, 5}, Board::MoveDIR::Up));

    CHECK_THROWS(board1.move(1, {0, 1}, Board::MoveDIR::Down));
    CHECK_THROWS(board1.move(1, {0, 3}, Board::MoveDIR::Down));
    CHECK_THROWS(board1.move(1, {0, 5}, Board::MoveDIR::Down));
    CHECK_THROWS(board1.move(2, {7, 1}, Board::MoveDIR::Down));
    CHECK_THROWS(board1.move(2, {7, 3}, Board::MoveDIR::Down));
    CHECK_THROWS(board1.move(2, {7, 5}, Board::MoveDIR::Down));

    CHECK_THROWS(board1.move(2, {7, 1}, Board::MoveDIR::Up));
    CHECK_THROWS(board1.move(2, {7, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board1.move(2, {7, 5}, Board::MoveDIR::Up));
    /*check if given index is null pointer
    */
    CHECK_THROWS(board1.move(1, {0, 0}, Board::MoveDIR::Up));
    CHECK_THROWS(board1.move(1, {0, 4}, Board::MoveDIR::Left));
    CHECK_THROWS(board1.move(1, {0, 6}, Board::MoveDIR::Down));
    CHECK_THROWS(board1.move(2, {7, 0}, Board::MoveDIR::Right));
    CHECK_THROWS(board1.move(2, {7, 4}, Board::MoveDIR::Up));
    CHECK_THROWS(board1.move(2, {7, 6}, Board::MoveDIR::Down));
    /*
    check if the soldier in the source
            belong to other player
    */
    CHECK_THROWS(board1.move(2, {0, 1}, Board::MoveDIR::Up));
    CHECK_THROWS(board1.move(2, {0, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board1.move(2, {0, 5}, Board::MoveDIR::Up));
    CHECK_THROWS(board1.move(1, {7, 1}, Board::MoveDIR::Down));
    CHECK_THROWS(board1.move(1, {7, 3}, Board::MoveDIR::Down));
    CHECK_THROWS(board1.move(1, {7, 5}, Board::MoveDIR::Down));

    CHECK_NOTHROW(board1.move(1, {0, 1}, Board::MoveDIR::Up));
    CHECK_NOTHROW(board1.move(1, {0, 3}, Board::MoveDIR::Up));
    CHECK_NOTHROW(board1.move(1, {0, 5}, Board::MoveDIR::Up));
    Board board2(8, 8);
    // Add soldiers for player 1:
    assert(!board2.has_soldiers(1));
    board2[{0, 0}] = new FootSoldier(1);
    board2[{1, 0}] = new ParamedicCommander(1);
    board2[{2, 0}] = new Sniper(1);
    board2[{0, 7}] = new FootCommander(1);
    board2[{1, 7}] = new FootSoldier(1);
    board2[{2, 7}] = new Sniper(1);
    assert(board2.has_soldiers(1));
    // Add soldiers for player 2:
    assert(!board2.has_soldiers(2));
    board2[{5, 0}] = new FootSoldier(2);
    board2[{6, 0}] = new FootCommander(2);
    board2[{7, 0}] = new FootSoldier(2);
    board2[{5, 7}] = new Paramedic(2);
    board2[{6, 7}] = new FootCommander(2);
    board2[{7, 7}] = new Sniper(2);
    assert(board2.has_soldiers(2));
    /*check if given index is out of bound
    Right & Left down
    */
    CHECK_THROWS(board2.move(2, {7, 0}, Board::MoveDIR::Up));
    CHECK_THROWS(board2.move(2, {6, 0}, Board::MoveDIR::Up));
    CHECK_THROWS(board2.move(1, {0, 0}, Board::MoveDIR::Down));
    CHECK_THROWS(board2.move(1, {1, 0}, Board::MoveDIR::Left));

    CHECK_THROWS(board2.move(1, {0, 0}, Board::MoveDIR::Left));
    CHECK_THROWS(board2.move(1, {1, 0}, Board::MoveDIR::Up));
    CHECK_THROWS(board2.move(1, {2, 0}, Board::MoveDIR::Left));

    CHECK_NOTHROW(board2.move(1, {0, 0}, Board::MoveDIR::Right));
    CHECK_NOTHROW(board2.move(1, {1, 0}, Board::MoveDIR::Down));
    CHECK_NOTHROW(board2.move(1, {2, 0}, Board::MoveDIR::Down));

    CHECK_THROWS(board2.move(2, {5, 0}, Board::MoveDIR::Left));
    CHECK_THROWS(board2.move(2, {6, 0}, Board::MoveDIR::Left));
    CHECK_THROWS(board2.move(2, {7, 0}, Board::MoveDIR::Left));
    CHECK_THROWS(board2.move(1, {0, 7}, Board::MoveDIR::Right));
    CHECK_THROWS(board2.move(1, {1, 7}, Board::MoveDIR::Right));
    CHECK_THROWS(board2.move(1, {2, 7}, Board::MoveDIR::Right));
    CHECK_THROWS(board2.move(2, {5, 7}, Board::MoveDIR::Right));
    CHECK_THROWS(board2.move(2, {6, 7}, Board::MoveDIR::Right));
    CHECK_THROWS(board2.move(2, {7, 7}, Board::MoveDIR::Right));
    /*
    check for null pointer (no soldier in the source)
    */
    CHECK_THROWS(board2.move(1, {0, 1}, Board::MoveDIR::Down));
    CHECK_THROWS(board2.move(1, {1, 1}, Board::MoveDIR::Left));
    CHECK_THROWS(board2.move(1, {1, 2}, Board::MoveDIR::Up));
    CHECK_THROWS(board2.move(2, {2, 2}, Board::MoveDIR::Left));
    CHECK_THROWS(board2.move(2, {6, 6}, Board::MoveDIR::Right));
    CHECK_THROWS(board2.move(2, {7, 2}, Board::MoveDIR::Down));
    /*
    check if there is anyother soldier in location
    */
    CHECK_THROWS(board2.move(1, {0, 0}, Board::MoveDIR::Up));
    CHECK_THROWS(board2.move(1, {1, 0}, Board::MoveDIR::Down));
    CHECK_THROWS(board2.move(1, {0, 7}, Board::MoveDIR::Up));
    CHECK_THROWS(board2.move(1, {1, 7}, Board::MoveDIR::Up));

    CHECK_THROWS(board2.move(2, {7, 0}, Board::MoveDIR::Up));
    CHECK_THROWS(board2.move(2, {6, 0}, Board::MoveDIR::Up));
    CHECK_THROWS(board2.move(2, {6, 7}, Board::MoveDIR::Up));
    CHECK_THROWS(board2.move(2, {7, 7}, Board::MoveDIR::Up));

    CHECK_THROWS(board2.move(1, {1, 0}, Board::MoveDIR::Down));
    CHECK_THROWS(board2.move(1, {2, 0}, Board::MoveDIR::Down));
    CHECK_THROWS(board2.move(1, {1, 7}, Board::MoveDIR::Down));
    CHECK_THROWS(board2.move(1, {2, 7}, Board::MoveDIR::Down));

    CHECK_THROWS(board2.move(2, {5, 0}, Board::MoveDIR::Up));
    CHECK_THROWS(board2.move(1, {6, 0}, Board::MoveDIR::Down));
    CHECK_THROWS(board2.move(1, {5, 7}, Board::MoveDIR::Down));
    CHECK_THROWS(board2.move(1, {6, 7}, Board::MoveDIR::Down));
    /*delete allafter using*/
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            Soldier *soldier1 = board1[{i, j}];
            Soldier *soldier2 = board2[{i, j}];
            if (soldier1)
                delete soldier1;
            if (soldier2)
                delete soldier2;
        }
    }
}
TEST_CASE("Test for game-board during initialization.")
{
}
TEST_CASE("Test for attack function.")
{
    Board board1(10, 10);
    // Add soldiers for player 1:
    assert(!board1.has_soldiers(1));
    board1[{0, 1}] = new Sniper(1);
    board1[{2, 1}] = new SniperCommander(1);
    board1[{0, 3}] = new ParamedicCommander(1);
    board1[{2, 3}] = new ParamedicCommander(1);
    board1[{0, 5}] = new FootCommander(1);
    board1[{2, 5}] = new FootSoldier(1);
    board1[{0, 7}] = new SniperCommander(1);
    board1[{2, 7}] = new Paramedic(1);
    assert(board1.has_soldiers(1));
    // Add soldiers for player 2:
    assert(!board1.has_soldiers(2));
    board1[{7, 1}] = new Sniper(2);
    board1[{9, 1}] = new SniperCommander(2);
    board1[{7, 3}] = new ParamedicCommander(2);
    board1[{9, 3}] = new ParamedicCommander(2);
    board1[{7, 5}] = new FootCommander(2);
    board1[{9, 5}] = new FootSoldier(2);
    board1[{7, 7}] = new Sniper(2);
    board1[{9, 7}] = new Paramedic(2);
    assert(board1.has_soldiers(2));
    // cout << "Game _ Start" << endl;
    // cout << "__________________________________" << endl;
    // board1.print();
    // cout << "__________________________________" << endl;

    /*soldiers special power
*FootSoldier: initial health points=100, damage per activity=10.
*FootCommander: initial health points=150, damage per activity=20.
*Sniper: initial health points=100, damage per activity=50.
*SniperCommander: initial health points=120, damage per activity=100.
*Paramedic: initial health points=100, health per activity=full.
*ParamedicCommander: initial health points=200, health per activity=full.
    */
    //befor attack

    CHECK(board1[{7, 1}]->player_health == 100);
    CHECK(board1[{9, 1}]->player_health == 120);
    CHECK(board1[{7, 3}]->player_health == 200);
    CHECK(board1[{9, 3}]->player_health == 200);
    CHECK(board1[{7, 5}]->player_health == 150);
    CHECK(board1[{9, 5}]->player_health == 100);
    CHECK(board1[{7, 7}]->player_health == 100);
    CHECK(board1[{9, 7}]->player_health == 100);
    /*player1 sniper is attack 
    after attack board[7][3] health is now 150
    */

    board1.move(1, {0, 1}, Board::MoveDIR::Up);
    CHECK(board1[{7, 3}]->player_health == 150);
    CHECK(board1[{9, 3}]->player_health == 200);
    CHECK(board1[{7, 1}]->player_health == 100);
    CHECK(board1[{9, 1}]->player_health == 120);
    CHECK(board1[{9, 7}]->player_health == 100);

    // cout << "__________________________________" << endl;
    // board1.print();
    // cout << "__________________________________" << endl;

    /*player2 paramedicCommander is  attack 
    after attack  player2 soldiers health is full
    */
    board1.move(2, {7, 3}, Board::MoveDIR::Down);
    CHECK(board1[{9, 3}]->player_health == 200);
    CHECK(board1[{7, 1}]->player_health == 100);
    CHECK(board1[{9, 1}]->player_health == 120);
    CHECK(board1[{9, 7}]->player_health == 100);

    // cout << "__________________________________" << endl;
    // board1.print();
    // cout << "__________________________________" << endl;

    /*player1 FootCommander  is attack 
            footcommander & footsoldier attack
    after attack board[6][3] health is now 170
    */
    board1.move(1, {0, 5}, Board::MoveDIR::Up);
    CHECK(board1[{6, 3}]->player_health == 120);
    CHECK(board1[{7, 1}]->player_health == 100);
    CHECK(board1[{7, 5}]->player_health == 150);
    CHECK(board1[{7, 7}]->player_health == 100);
    CHECK(board1[{9, 7}]->player_health == 100);
    // cout << "__________________________________" << endl;
    // board1.print();
    // cout << "__________________________________" << endl;

    /*player2 FootSoldier is attack 
    after attack board[2][5] health is now 90
    */
    board1.move(2, {9, 5}, Board::MoveDIR::Down);
    CHECK(board1[{2, 5}]->player_health == 90);
    CHECK(board1[{1, 1}]->player_health == 100);
    CHECK(board1[{2, 3}]->player_health == 200);
    CHECK(board1[{1, 5}]->player_health == 150);
    CHECK(board1[{2, 7}]->player_health == 100);
    // cout << "__________________________________" << endl;
    // board1.print();
    // cout << "__________________________________" << endl;
    /*player1 paramedic  is attack 
    after attack board[2][5] health is now 100
    */
    board1.move(1, {2, 7}, Board::MoveDIR::Up);
    CHECK(board1[{2, 5}]->player_health == 100);
    CHECK(board1[{1, 1}]->player_health == 100);
    CHECK(board1[{2, 3}]->player_health == 200);
    CHECK(board1[{1, 5}]->player_health == 150);

    // cout << "__________________________________" << endl;
    // board1.print();
    // cout << "__________________________________" << endl;

    /*player2 FootSoldierCommander is attack 
    after attack board[3][7] health is now 70
    */
    board1.move(2, {7, 5}, Board::MoveDIR::Down);
    CHECK(board1[{3, 7}]->player_health == 70);
    CHECK(board1[{1, 1}]->player_health == 100);
    CHECK(board1[{2, 3}]->player_health == 200);
    CHECK(board1[{1, 5}]->player_health == 150);

    // cout << "__________________________________" << endl;
    // board1.print();
    // cout << "__________________________________" << endl;
    /*player1 sniperCommander  is attack 
    after attack board[6][3](player2 paramedicCommande)  is dead
    and board[6][5] health is now 50
    */
    board1.move(1, {2, 1}, Board::MoveDIR::Up);

    CHECK((board1[{6, 3}] == nullptr));
    CHECK(board1[{6, 5}]->player_health == 50);
    CHECK(board1[{1, 1}]->player_health == 100);
    CHECK(board1[{2, 3}]->player_health == 200);
    CHECK(board1[{1, 5}]->player_health == 150);

    // cout << "__________________________________" << endl;
    // board1.print();
    // cout << "__________________________________" << endl;
    /*player2 SniperCommander is attack 
    after attack board[3][1] & board[3][7]  is dead
    */
    board1.move(2, {9, 1}, Board::MoveDIR::Right);
    CHECK(board1[{3, 1}] == nullptr);
    CHECK(board1[{3, 1}] == nullptr);
    CHECK(board1[{1, 1}]->player_health == 100);
    CHECK(board1[{2, 3}]->player_health == 200);
    CHECK(board1[{1, 5}]->player_health == 150);

    board1.move(1, {1, 5}, Board::MoveDIR::Left);
    board1.move(2, {9, 2}, Board::MoveDIR::Down);
    board1.move(1, {0, 7}, Board::MoveDIR::Up);
    board1.move(2, {9, 7}, Board::MoveDIR::Down);
    board1.move(1, {1, 7}, Board::MoveDIR::Up);
    board1.move(2, {8, 7}, Board::MoveDIR::Down);
    CHECK(board1.has_soldiers(1) == true);
    CHECK(board1.has_soldiers(2) == true);
    board1.move(1, {1, 4}, Board::MoveDIR::Up);
    board1.move(2, {8, 2}, Board::MoveDIR::Left);
    board1.move(1, {1, 1}, Board::MoveDIR::Left);
    board1.move(2, {8, 1}, Board::MoveDIR::Left);
    board1.move(1, {1, 0}, Board::MoveDIR::Up);
    board1.move(2, {8, 0}, Board::MoveDIR::Down);
    board1.move(1, {2, 7}, Board::MoveDIR::Up);
    board1.move(2, {8, 5}, Board::MoveDIR::Right);
    board1.move(1, {3, 7}, Board::MoveDIR::Up);
    CHECK(board1.has_soldiers(1) == true);
    CHECK(board1.has_soldiers(2) == true);
    board1.move(2, {7, 0}, Board::MoveDIR::Down);
    board1.move(1, {4, 7}, Board::MoveDIR::Up);
    board1.move(2, {6, 0}, Board::MoveDIR::Down);
    board1.move(1, {5, 7}, Board::MoveDIR::Left);
    board1.move(2, {5, 0}, Board::MoveDIR::Right);
    board1.move(1, {5, 6}, Board::MoveDIR::Left);

    /*after n iteration test for play function
    */
    CHECK(board1.has_soldiers(1) == true);
    CHECK(board1.has_soldiers(2) == false);
    /*delete all after using*/
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            Soldier *soldier = board1[{i, j}];

            if (soldier)
                delete soldier;
        }
    }
}
