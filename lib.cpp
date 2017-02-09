/*lib.cpp
* Group 4, Spring 2016, CS 202
* J. Aarhus, A. Eckert, J. Murphy, C. Navio,
* 4-12-2016
* This is the source file for our library (-> random functions).
*/
#include <random>
#include <stdio.h>
#include "lib.h"
#include "character.h"

double randNum() // fighter random number
{

    double response;
    int ranChance = rand() % 21; // random number 0-20
    if(ranChance <= 4)
    {
        response = .5;
        return response;
    }
    else if (ranChance >= 5 && ranChance <= 17)
    {
        response = 1;
        return response;
    }
    else
	{
		response = 1.5;// change multiplier for balance issues
		return response;
	}
}

int randSkillGen()
{
    int skillNum;
    int ranChance = rand()%21; // random number 0-20
    if(ranChance <= 4)
    {
        skillNum = 3;
        return skillNum;
    }
    else if (ranChance >= 5 && ranChance <= 14)
    {
        skillNum = 4;
        return skillNum;
    }
    else if (ranChance >= 14 && ranChance <= 18)
	{
		skillNum = 6;
		return skillNum;
	}
	else
    {
        skillNum = 8;
        return skillNum;
    }
}
Character * npcRandFactory(char c)
{

    int charisma, dexterity, health, intelligence, strength;
    charisma = randSkillGen();
    dexterity = randSkillGen();
    intelligence = randSkillGen();
    strength = randSkillGen();
    int r;
    int high = 51; // set highest possible and lowest possible health values for game balance
    int low = 15;
    do{
        r = rand();
        } while (r < ((unsigned int)(RAND_MAX) + 1) % (high + 1 - low));
        health = r%(high + 1 - low) + low; // set health to random number in range

	char res = c;
	if(res == 'g')
		{
			Guard * newGuard = new Guard(charisma, dexterity, health, intelligence, strength); // make a new guard and return the object
			return newGuard;
		}
		if(res == 'b')
		{
			Bandit * newBandit = new Bandit(charisma,dexterity,health, intelligence, strength);
			return newBandit;
		}
		if(res == 'p')
		{
			Patrol * newPatrol = new Patrol(); // town patrol with standard health and will have always the same stats
			return newPatrol;
		}
		else
		{
			return 0; //if you dont put a proper character that you pass to create an object
			// its going to return nothing so make sure to input a lower case of correct type.
		}

}
Character * npcFactory(char c,int charisma,int dexterity,int health,int intelligence,int strength) //
{
	// caller is responsible to deletes
	// takes a character and builds a NPC of that type and returns it
	// to add more simply add a if statement and follow guard and bandit code
	char res = c;
		if(res == 'g')
		{
			Guard * newGuard = new Guard(charisma, dexterity, health, intelligence, strength); // make a new guard and return the object
			return newGuard;
		}
		if(res == 'b')
		{
			Bandit * newBandit = new Bandit(charisma,dexterity,health, intelligence, strength);
			return newBandit;
		}
		if(res == 'p')
		{
			Patrol * newPatrol = new Patrol(); // town patrol with standard health and will have always the same stats
			return newPatrol;
		}
		else
		{
			return 0; //if you dont put a proper character that you pass to create an object
			// its going to return nothing so make sure to input a lower case of correct type.
		}
}
Character * setClass()
{
	// this can be changed to whatever on prompting the user
	cout << "What class would you like to choose?" << endl;
	cout << "type" << endl;
	// tabs to line up the choices for aesthic
	cout << "B        " << "\t" << "F      " << "\t" << "M   " << "\t" << "R     " << endl;
	cout << "Barbarian" << "\t" << "Fighter" << "\t" << "Monk" << "\t" << "Ranger" << endl;
	char response;
	cin >> response;
	// get character upper or lower case of selected class run through the switch and create
	// an object according to the class they picked and return the address of it.
	switch (response)
	{
	case 'B':
	case 'b':
	{
		cout << "You picked Barbarian! " << endl << endl;
		Barbarian * userB = new Barbarian(); // make a Barbarian object and return the address for the object.
		return userB;

	}
	case 'F':
	case 'f':
	{
		cout << "You picked Fighter! " << endl << endl;
		Fighter *userF = new Fighter(); // make a Fighter object and return the address for the object.
		return userF;
	}
	case 'M':
	case 'm':
	{
		cout << "You picked Monk! " << endl << endl;
		Monk *userM = new Monk(); // make a Monk object and return the address for the object.
		return userM;
	}
	case 'R':
	case 'r':
	{
		cout << "You picked Ranger! " << endl << endl;
		Ranger *userR = new Ranger(); // make a Ranger object and return the address for the object.
		return userR;
	}
	default:
	{
		cout << "Please enter a valid response to pick a class" << endl;
		setClass(); // if the user didnt pick a valid response in the switch loop then lets send him back
					// to the top and have them reselect intill they do pick a valid one.
	}
	}
	return 0;
}

void printCharAbilities(Character *uChar)
{
	cout << "Charisma = " << "\t" << uChar->abil_.getCharisma() << endl;
	cout << "Dexterity = " << "\t" << uChar->abil_.getDexterity() << endl;
	cout << "Health = " << "\t" << uChar->abil_.getHealth() << endl;
	cout << "Intelligence = " << "\t" << uChar->abil_.getIntelligence() << endl;
	cout << "Strength = " << "\t" << uChar->abil_.getStrength() << endl << endl;
}

void fight(Character* P, Character* M)
{
	int initPlHealth = P->abil_.getHealth();
	cout << M->getName() << " attacks you!" << endl;
	while(M->abil_.getHealth()>0 && P->abil_.getHealth()>0)
	{
		M->attack(P);
		cout << endl;
		getchar();
		//show health diagram with update function
		P->attack(M);
		cout << endl;
		getchar();
		//show health diagram with update function
	}

	//here again we have issues with the abilities
	if(P->abil_.getHealth()<=0)
	{
        cout << M->getName() << " wins" << endl;
		if(coinFlipDeath(P, initPlHealth) == 1)
		{
			fight(P, M);
		}
	}
	else
	{
        cout << "You win" << endl << endl;
		P->abil_.setHealth(initPlHealth);
	}
}
// level up class
void levelUp(Character * user)
{
    cout << "What skill would you like to level up? " << endl;
    cout << "\n";
    cout << "\t" << " TSype " << endl;
    cout << "C        " << "D         " << "H      " << "I            " << "S        " << endl;
    cout << "Charisma " << "Dexterity " << "Health " << "Intelligence " << "Strength " << endl;
    char r;
    cin >> r;
    switch(r)
    {
        case 'C':
        case 'c':
        {
            int stat = user->abil_.getCharisma(); // get the users charisma and put it to stat and then
            user->abil_.setCharisma(stat+1); // increase it from stat with whatever value to balance
            break;
        }
        case 'D':
        case 'd':
        {
            int stat = user->abil_.getDexterity();
            user->abil_.setDexterity(stat+1);
            break;
        }
        case 'H':
        case 'h':
        {
            int stat = user->abil_.getHealth();
            user->abil_.setHealth(stat+5) ;
            break;
        }
        case 'I':
        case 'i':
        {
            int stat = user->abil_.getIntelligence();
            user->abil_.setIntelligence(stat+1);
            break;
        }
        case 'S':
        case 's':
        {
           int stat = user->abil_.getStrength();
           user->abil_.setStrength(stat+1);
           break;
        }
        default:
            {
                levelUp(user); // send them back in the loop if they didnt pick a valid option
            }

    }
}
bool skillCheck(char c,Character * user,int numCheck) // pass the char of the skill you would like to test along with the user and a number to check to pass the skill test
{ // passSkillCheck('c',user,5,4) will check to see if the character has charisma higher than 5
    char res = tolower(c);
    switch(res)
    {
    case 'c':
        {
            return user->abil_.getCharisma() > numCheck;
        }
    case 'd':
        {
            return user->abil_.getDexterity() > numCheck;
        }
    case 'i':
        {
            return user->abil_.getIntelligence() > numCheck;
        }
    case 's':
        {
            return user->abil_.getStrength() > numCheck;
        }
    default:
        {
            return false;
        }
    }
}
bool winFightArena(Character * user,int numEnemies)
{
    for(int i=0; i< numEnemies; ++i)
       {
        	Character * opp = npcRandFactory('b');
        	cout << "you are fighting a " << opp->getName() << " with " << endl;
        	printCharAbilities(opp); // create opp character and print ablities for the user to see stats
        	cout << "\n" << endl;
        	fight(user,opp); // fight is user and then mob
        	levelUp(user); // level up takes a Character * user
        	cout << "Your new abilities are: " << endl;
        	printCharAbilities(user);
       }
       return 1; // returns true if the fighter wins , if the player loses it wont reach here as in the fight function if the player loses it quits the game
}

 // if you have less than 4 int you get one roll to get a high number or mid or low
    // if you have more than 4 you get a roll and then one roll for every level up you have on 4
    // so if you have 6 you get one roll for just starting and then you get one for 5 and 6 level
    // this then ships off the vector with its contentes of the dice rolls and then sends it to roll reader
    // which inturns takes a double filled vector and sees if they are any high rolls then mid rolls then low rolls
string intChance(Character * user) // takes a user and sees if the person can pass it if not it returns a string saying low mid high int roll
{

    int intStat = user->abil_.getIntelligence();
    vector<double> rollHolder;
    double roll;
    if(intStat < 4)
    {
        rollHolder.push_back(randNum());
    }
    if(intStat >= 4)
    {
        for (int i = 0; i<intStat-3; ++i)
        {
        roll = randNum();
        rollHolder.push_back(roll);

        }
    }
   return rollHolderReader(rollHolder);
}
// this works as the reader of the vector and finds it contents
string rollHolderReader(vector<double> &myVec)
{
    // see if there are any numbers stored as a high value if there is then they passed the high int chance
    // if they dont pass see if they passed the mid int chance
    // then check the low int chance
    for(int i = 0; i<myVec.size(); ++i)
    {
        double checkVal = myVec[i];
        if(checkVal == 1.5)
        {
            return "high";
        }
    }
    for(int i = 0; i<myVec.size(); ++i)
    {
        double checkVal = myVec[i];
        if(checkVal == 1)
        {
            return "mid";
        }
    }
    for(int i = 0; i<myVec.size(); ++i)
    {
        double checkVal = myVec[i];
        if(checkVal == .5)
        {
            return "low";
        }
    }
    return "low";
}

bool coinFlipDeath(Character * user,int inHealth)
{
	getchar();
    cout << "You are given a second chance, time to seize it! " << endl;
    cout << "The 3 fates decide if you live or die" << endl;
    int chance = rand()%2;

   	if(chance == 1)
    {
    	getchar();
        cout << "The fates have decided to give you another chance in life! "<< endl;
        cout << "You are resurrected and must fight again! " << endl;
        user->abil_.setHealth(inHealth);
        return 1;
    }
    else
    {
    	getchar();
        cout << "The Fates have decided against you, you have been casted out! "  << endl;
        cout << "\t" <<"GAME OVER" << endl;
        exit(1);
    }
}