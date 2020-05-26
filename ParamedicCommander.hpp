#pragma once
#include "Paramedic.hpp"
namespace WarGame
{
	class ParamedicCommander : public Paramedic
	{
	public:
	// int full_health = 200;
		ParamedicCommander(uint p_n) : Paramedic(p_n){player_number = p_n;
														player_health = 200;
														player_damge = 100;
														full_health = 200;						};
		void Basic_attack(Soldier &other, vector<vector<Soldier *>> board, pair<int, int> p);
		void Full_attack(Soldier &other, vector<vector<Soldier *>> board, pair<int, int> p);
		// You have to write this class
	};
}; // namespace WarGame
