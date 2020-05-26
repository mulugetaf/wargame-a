#pragma once
#include "Soldier.hpp"
#include <iostream>
namespace WarGame {
	class FootSoldier : public Soldier{
		public:
		//int full_health = 100;
		FootSoldier(uint p_n) : Soldier(p_n,100,10,100){};
		void Basic_attack(Soldier& other,vector<vector<Soldier *>> board,pair<int,int> p) ;
		void Full_attack(Soldier& other,vector<vector<Soldier *>> board,pair<int,int> p) ;
		// You have to write this class 
	};
}
