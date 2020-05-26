#pragma once
#include "Soldier.hpp"
namespace WarGame {
	class Sniper : public Soldier{
		public:
		 int full_health = 100;
		Sniper(uint p_n) : Soldier(p_n,100,50,100){};
		void Basic_attack(Soldier& other,vector<vector<Soldier *>> board,pair<int,int> p) ;
		void Full_attack(Soldier& other,vector<vector<Soldier *>> board,pair<int,int> p) ;
		// You have to write this class 
	};
}
