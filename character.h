#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;
//class system

class character
{
  public: 
  character();
    
  //local attributes
  int health;
  int totalHealth;
  int stamina;
  int totalStamina;
  int playerLevel;
  int experience;
  int obedienceLvl;
  int posX;
  int posY;
  int requiredXP;
  bool isAlive();

  //strings for player
  string playerName;
  string playerClass;
  string playerWeapon;
  string playerGender;

  //functions for player
  void useHealthPack();
  void checkStats();
  string setPlayerName(string playerName);
  string setPlayerInfo (string playerGender, string playerClass, string playerWeapon);
  void checkInventory();
  
  //Class Data
  
  //Melee
  
  //Space Magic
  
  //Ranger
  
  //fighting functions and variables!
    
  };

void useHealthPack()
{
  int HealthPackNum = 3;
  //for the purpose of the game, with the inventory not created, only allow 3 Health Packs at game start. 

}

/*string setPlayerInfo (string playerGender, string playerClass, string playerWeapon)
{
  //variables

  //

}

string setPlayerName (string playerName)
{
  cout << "You look down ";
}*/