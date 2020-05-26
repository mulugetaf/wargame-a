#pragma once
#include "Soldier.hpp"
namespace WarGame
{
	class Paramedic : public Soldier
	{
	public:
		//const int full_health = 100;
		Paramedic(uint p_n) : Soldier(p_n, 100, 100,100){};
		void Basic_attack(Soldier &other, vector<vector<Soldier *>> board, pair<int, int> p);
		void Full_attack(Soldier &other, vector<vector<Soldier *>> board, pair<int, int> p);
		std::pair<uint,uint> distance(vector<vector<Soldier*>> board,int i,int j,int s) ;
		
		// You have to write this class
	};
} // namespace WarGame
