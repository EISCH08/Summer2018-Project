
#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>
#include <cmath>
#include <array>
using namespace std;

struct Stats //struct of stat values
{
	int hp; //max hp
	int hpCur; //current HP
	int attack;
	int defense;
	int spAttack;
	int spDefense;
	int speed;
	int hpB;
	int attackB;
	int defenseB;
	int spAttackB;
	int spDefenseB;
	int speedB;
	int exp;
	int level;
	string expGrowth;
	int expB;
};


struct IVs //the individual gains of each stat IVs
{
	int hp;
	int attack;
	int defense;
	int spAttack;
	int spDefense;
	int speed;
};

struct Move
{
	int id;
	string nameInternal; //name not in battle
	string nameDisplay; //name in battle
	int functionCode; //hex digit
	int power; //damage of move
	string type; //type of move
	int category; //0 = physical; 1 = special; 2 = status
	int accuracy;
	int pp;
	int ppCur;
	int addEffectChance;
	int target; //0 = single target, 1 = self, 2 = nothing
	int priority; //0 - 6
	int level;
	string flag; //other effects the move has;
	string descr; //description of the move
};
struct LevelUp
{
	bool evolve;
	Move lvlUpMoves[25];
};

class Pokemon //creates the pokemon object
{
public:
	int dexID;
	string name;
	string nameInternal;
	string type1;
	string type2;
	string pokedex;
	Stats stats;
	IVs ivs;
	int numMoves;
	int learnMoveLvl[25];
	string learnMoveMove[25];
	Move moves[4];
	string evolveLvl;
	string evolveType;
	string evolution;
	LevelUp lvlUP;
	string status; //FAINTED, SLEEP, BURNED ...
	void SetDefValues();
	void SetStats();
	void SetExp(int slow[], int medFast[], int medSlow[], int fast[]);
	//void SetBaseValues(string name, string type, int level, int hp, int attack, int Ndefense,int spAttack, int spDefense, int speed, string expCap);
	void SetIVs();
	void SetExp();
	void AssignMoves(Move moveList[]);
	void PrintPokemonInfo();

};
class Global
{
public:
	Move moveList[560];
	Pokemon pokedex[151];
	int fast[100];
	int medFast[100];
	int medSlow[100];
	int slow[100];
	int verySlow[100];
	void SetExpRanges();
	Global();
	//~Global();
};
class Trainer
{
public:
	string name;
	Pokemon party[6];
	int money;
	int trainerID;
	string badges[8];
	int gender; //0 for male, 1 for female
	string trainerClass;
	Trainer();
	void PrintTrainerInfo();
	int NumberOfPokemon();
};

Trainer::Trainer()
{
	name = "Red"; //default name given
	money = 0;
	trainerID = rand() % 65535 + 1; //sets a trainer id between 0 - 65535;
	for(int i= 0; i<8; i++)
	{
		badges[i] = "NULL";
		if(i<6)
		{
		Pokemon nullPoke;
		nullPoke.nameInternal = "NULL";
		party[i] = nullPoke;	
		}
		
	}
	trainerClass = "USER";
	int gender = 0; //defaults to male
}

void Trainer::PrintTrainerInfo()
{
	cout<<"Trainer Name: "<<name<<endl;
	cout<<"Trainer ID: "<<trainerID<<endl;
	cout<<"Party Pokemon: " <<endl;
	int index =0;
	while(party[index].nameInternal!="NULL")
	{
		cout<<party[index].nameInternal<<" Lv"<<party[index].stats.level<<endl;
		index++;
	}
	cout<<"Money: "<<money<<endl;
}

int Trainer::NumberOfPokemon()
{
	int index =0;
	while(party[index].nameInternal!="NULL")
	{
		index++;
	}
	return index;
}






void Pokemon::SetIVs() //assigns IV values
{
	ivs.hp = (rand() % 31);
	ivs.attack = (rand() % 31);
	ivs.defense = (rand() % 31);
	ivs.spAttack = (rand() % 31);
	ivs.spDefense = (rand() % 31);
	ivs.speed = (rand() % 31);
}

void Pokemon::SetStats()
{
	int level = stats.level;
	stats.attack = floor(floor((2 * stats.attackB + ivs.attack)*level/100 +5));
	stats.defense = floor(floor((2 * stats.defenseB + ivs.defense)*level/100 +5));
	stats.spAttack = floor(floor((2 * stats.spAttackB + ivs.spAttack)*level/100 +5));
	stats.spDefense = floor(floor((2 * stats.spDefenseB + ivs.spDefense)*level/100 +5));
	stats.speed = floor(floor((2 * stats.speedB + ivs.speed)*level/100 +5));
	stats.hp = floor((2 * stats.hpB + ivs.hp)*level/100 +level + 10);
	stats.hpCur = stats.hp;
	stats.expB = 0;
}
void Pokemon::PrintPokemonInfo() //prints out pokemon information
{
	cout<<"Name: "<<name <<endl;
	cout <<"Type: "<<type1<<endl;
	cout<<"Level: "<<stats.level <<endl;
	cout <<"HP: "<<stats.hp<<endl;
	cout<<"Attack: "<<stats.attack <<endl;
	cout<<"Defense: "<<stats.defense <<endl;
	cout <<"Sp.Attack: "<<stats.spAttack <<endl;
	cout<<"Sp.Defense: "<<stats.spDefense <<endl;
	cout<<"Speed: " <<stats.speed <<endl;
	// cout <<"HP: "<<stats.hpB<<endl;
	// cout<<"Attack: "<<stats.attackB <<endl;
	// cout<<"Defense: "<<stats.defenseB <<endl;
	// cout <<"Sp.Attack: "<<stats.spAttackB <<endl;
	// cout<<"Sp.Defense: "<<stats.spDefenseB <<endl;
	// cout<<"Speed: " <<stats.speedB <<endl;
	// cout <<"HP IV: "<<ivs.hp<<endl;
	// cout<<"Attack IV: "<<ivs.attack <<endl;
	// cout<<"Defense IV: "<<ivs.defense <<endl;
	// cout <<"Sp.Attack IV: "<<ivs.spAttack <<endl;
	// cout<<"Sp.Defense IV: "<<ivs.spDefense <<endl;
	// cout<<"Speed IV: " <<ivs.speed <<endl;
	cout<<"Move 1: " <<moves[0].nameInternal<<endl;
	cout<<"Move 2: " <<moves[1].nameInternal<<endl;
	cout<<"Move 3: " <<moves[2].nameInternal<<endl;
	cout<<"Move 4: " <<moves[3].nameInternal<<endl;
	// cout<<"Exp Growth: "<<stats.expGrowth<<endl;
	// cout<<"Base Exp: " <<stats.expB<<endl;
	// cout<<"Current Exp: " <<stats.exp<<endl;

}

Move FindMove(Move moveList[], string moveName)
{
	int i = 0;
	while(moveList[i].nameInternal != moveName && i<559)
	{
		i++;
	}
	Move move = moveList[i];
	return move;

}

void Pokemon::AssignMoves(Move moveList[])//assigns moves to pokemon based on 4 most recently learned moves
{
	int level = stats.level;

	int levelIndex = 0;

	while(level >= learnMoveLvl[levelIndex] && learnMoveLvl[levelIndex] >= learnMoveLvl[levelIndex-1]) //finds which index the level limit reaches
	{
		levelIndex++;
	}
	if(levelIndex<4)
		{
			int track = levelIndex;
			while(track<4)
			{
				Move emptyMove;
				moves[track] = emptyMove;
				track++;
			}	
		}
		numMoves = 0;
	while(levelIndex >=0 && numMoves <4)
	{

		Move move = FindMove(moveList,learnMoveMove[levelIndex-1]);
		
		moves[numMoves] = move;
		levelIndex--;
		numMoves++;
	}



}

void Pokemon::SetExp(int slow[], int medFast[], int medSlow[], int fast[])
{
	if(stats.expGrowth == "Fast")
	{
		stats.exp = fast[stats.level - 1];
	}
	if(stats.expGrowth == "Slow")
	{
		stats.exp = slow[stats.level - 1];
	}
	if(stats.expGrowth == "Parabolic")
	{
		
		stats.exp = medSlow[stats.level - 1];
	}
	if(stats.expGrowth == "Medium")
	{
		stats.exp = medFast[stats.level - 1];
	}
}

void Global::SetExpRanges()
{
	for(int i =1; i<=100; i++)
	{
		slow[i-1] = (5*pow(i,3))/4;
		fast[i-1] = (4*pow(i,3))/5;
		medFast[i-1] = pow(i,3);
		medSlow[i-1] = ((1.2*pow(i,3)) - (15 * pow(i,2)) + 100*i - 140);
	}
}
Global::Global()
{
	SetExpRanges();
	
}
