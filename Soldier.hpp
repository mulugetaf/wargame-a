#pragma once
#include <vector>
using namespace std;
namespace WarGame {
	class Soldier {
		public:
		uint player_number;
		uint player_health;
		uint player_damge;
		uint full_health;
		virtual std::pair<uint,uint> distance(vector<vector<Soldier*>> board,int i,int j,int s);
		virtual void Basic_attack(Soldier& other,vector<vector<Soldier *>> board,pair<int,int> p){} ;
		virtual void Full_attack(Soldier& other,vector<vector<Soldier *>> board,pair<int,int> p){} ;
		Soldier(uint p_n ,uint p_h,uint p_d ,uint f_h):player_number(p_n),player_health(p_h),player_damge(p_d),full_health(f_h){};
		// You have to write this class 
	};
};
