/*lib.h
* Group 4, Spring 2016, CS 202
* J. Aarhus, A. Eckert, J. Murphy, C. Navio,
* 4-12-2016
* This is the Header file for our library (-> random functions).
*/

#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

#include "character.h"
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

double randNum(); // used for creating critical damage for combat system
int randSkillGen();
Character * setClass(); // used to create playe starting class
Character * npcFactory(char c, int charisma, int dexterity, int health, int intelligence, int strength); // used to create npc takes a char and makes a object of that class
Character * npcRandFactory(char c);
void fight(Character* P, Character * M);
void printCharAbilities(Character *uChar);
void levelUp(Character * user);
bool skillCheck(char c,Character * user,int numCheck);
bool winFightArena(Character * user,int numEnemies);
string intChance(Character * user); // takes a user and a returns a string low mid high chance
string rollHolderReader(vector<double> &myVec); // reads a vector and returns low mid high depending on contents
bool coinFlipDeath(Character * user,int inHealth);//  takes a user and then the initial health of the character
#endif // LIB_H_INCLUDED
