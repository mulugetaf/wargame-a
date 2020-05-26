#pragma once
#include "FootSoldier.hpp"
#include <iostream>
namespace WarGame {
	class FootCommander : public FootSoldier{
		public:
		//int full_health = 150;
		FootCommander(uint p_n) : FootSoldier(p_n){player_number = p_n;
													player_health = 150;
													player_damge = 20;
													full_health = 150;	
																		};
		void Basic_attack(Soldier& other,vector<vector<Soldier *>> board,pair<int,int> p) ;
		void Full_attack(Soldier& other,vector<vector<Soldier *>> board,pair<int,int> p) ;
		// You have to write this class 
	};
}
