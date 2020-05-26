#pragma once
#include "Sniper.hpp"
namespace WarGame {
	class SniperCommander : public Sniper{
		public:
		  //int full_health = 120;
		SniperCommander(uint p_n) : Sniper(p_n){
			player_number = p_n;
			player_health=120;
			player_damge=100;
			full_health = 120;};
		void Basic_attack(Soldier& other,vector<vector<Soldier *>> board,pair<int,int> p) ;
		void Full_attack(Soldier& other,vector<vector<Soldier *>> board,pair<int,int> p) ;
		// You have to write this class 
	};
}
