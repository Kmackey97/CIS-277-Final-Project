#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <character.h>
#include <character.cpp>

#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_UP 72
#define KEY_DOWN 80

#ifdef CHARACTER_H
#define <character.h>
#include <character.h>
#endif
#include <character.cpp>
#ifdef CHARACTER_H
#define <character.cpp>
#endif
using namespace std;
//will have to include character.h and character.cpp at some point, probably...

extern string playerName;
extern string playerLevel;
extern string health;

//prototypes
void anyKey(); //asks user to press enter to continue, skips line
void downOne(); // " " " " doesn't skip line
void ExitShip(); // starts exit sequence for leaving the ship
void longClear(); //clears screen by 50 lines
void shortClear(); // clears half the screen
void KeyFix(); 
char LeaveCockpit(char); //starts the sequence leading char out of cockpit
int sittingNumCount(int); //starts counting sittingNum iterations inside LeaveCockpit function
void exploreCockpit();
void clearScreen(); //gives user option to clear screen
//checkObed();
void mapPicture();
void characterFuncs();

//global variable
int obedience = 0;
int dissent = 0;

int main() 
{

string pName;
string pLevel;
string hp;


int c = 0;
while (1)
{
  c = 0;

  switch ((c = cin.get()))
  {
    case KEY_UP:
      cout << "* * * * * * * * * * * * * * * * * *" << endl;
      cout << setw(30) << "INVENTORY" << setw(30) << endl;
      cout << "* * * * * * * * * * * * * * * * * *" << endl;
      //array here?
      //Inventory
      break;
    case KEY_DOWN:
        cout << "* * * * * * * * * * * * * * * * * *" << endl;
        cout << setw(20) << "PLAYER INFO" << setw(20) << endl << endl;
        cout << "Player Name: " << playerName << endl;
        cout << "Health: " << health << endl;
        cout << "Level: " << playerLevel << endl;
        
        break;
      //status player info
    case KEY_RIGHT:
      cout << "RIGHT" << endl;
      break;
    //location
    case KEY_LEFT: 
      cout << "LEFT" << endl;
      break;
    //actions?
  }
}

//* * * * * * * * * * * * *
//VARIABLES
//* * * * * * * * * * * * *
string dm = "\n"; //delete later if unused
string filler = " "; //delete later if unused
char userInput; //used for Y/N choices
int userSelect; //used for switch choices
int sittingNum = 0; //used for funcs involving first branch of choices
//int obedience = 0; //this should be part of a class eventually; used to determine what's heard


//Rewrite here??

// * * * * * * * * * * * * * * * * * * * * * * * * *
//            Begin story/main function
// * * * * * * * * * * * * * * * * * * * * * * * * *
mapPicture();

cout << "[Systems failing. . .]" << endl;
anyKey();
cout << "[Systems failing. . .]" << endl;
anyKey();
cout << "[Syste7z)r#oms fai_l@c^g%&;#0" << endl;
anyKey();
cout << "[SYSTEM FAILURE.]" << endl;
anyKey();
cout << "[. . .]" << endl;
anyKey();
cout << "[Rerouting power]" << endl;
anyKey();
cout << "[. . .]" << endl;
anyKey();
//shortClear();
cout << "Systems check? (Y / N)" << endl;
cin >> userInput;
cout << endl;
if (userInput == 'y' || userInput == 'Y')
{
   cout << "> PROPULSION: offline" << endl;
   cin.ignore();
   downOne();
   cout << "> SHIELDS: offline" << endl;
   downOne();
   cout << "> EMERGENCY BEACON: offline" << endl;
   downOne();
   cout << "> MAIN COMPUTER: minimal functionality" << endl;
   downOne();
   cout << "> AIR RECYCLING: offline" << endl;
   downOne();
   cout << "> LIFE SUPPORT: minimal functionality" << endl;
   downOne();
   cout << " ** Recommend immediate evacuation **" << endl;
   //anyKey();
}
else if (userInput == 'n' || userInput == 'N')
{
  while (userInput == 'n' || userInput == 'N')
  {
    cout << "Systems check? (Y/N)" << endl;
    cin >> userInput;
    cout << endl;
    //repeated function. change?
    
if (userInput == 'y' || userInput == 'Y')
{
   cout << "> PROPULSION: offline" << endl;
   cin.ignore();
   downOne();
   cout << "> SHIELDS: offline" << endl;
   downOne();
   cout << "> EMERGENCY BEACON: offline" << endl;
   downOne();
   cout << "> MAIN COMPUTER: minimal functionality" << endl;
   downOne();
   cout << "> AIR RECYCLING: offline" << endl;
   downOne();
   cout << "> LIFE SUPPORT: minimal functionality" << endl;
   downOne();
   cout << "-- END OF REPORT --" << endl;
   downOne();
   cout << " ** Recommend immediate evacuation **" << endl;
   //anyKey();
}
//end repeated function
  }
}
else
{
  cout << "Invalid command. . . " << endl;
  anyKey();
  cout << "Systems failing. . ." << endl;
  anyKey();
}

//clear screen function here, but only if top placement

cout << endl << "The screen keeps cycling through the same list. You realize \nsitting there staring at it accomplishes nothing, beyond \nmaking your eyes hurt." << endl;
cout << endl << "You feel like it would be a bad idea to continue sitting." << endl;
//cout << string(50, '\n');
anyKey();
cout << "Clear screen and look around? (Y/N)" << endl;
cin >> userInput;
cout << endl;

// * * * * * * * * * * * * * * * * * * * * * * *
//            FUNCTION ONE: FIRST BRANCH
//                  OF DECISIONS
// * * * * * * * * * * * * * * * * * * * * * * *
LeaveCockpit(userInput);
// includes functions for leaving cockpit intitially


//this should be changed based on previous decision. Maybe a bool check to see what previous decisions were? Look up something.
cout << "Your ears burn and you find yourself feeling unsettled." << endl;
anyKey();
cout << "You need to go." << endl;
anyKey();
cout << ">> Evacuate?" << endl;
cin >> userInput;
if (userInput == 'y' || userInput == 'Y')
{
  // more stuff here
  cout << "You exit the ship after an undesignated period of time stumbling through hallways." << endl;
  anyKey();

}
else if (userInput == 'n' || userInput == 'N')
{
  cout << "(You choose to stay.)" << endl;
  anyKey();
  cout << "You feel sick. Something tells you that it's time to go." << endl;
}
cout << "(You choose to evacuate)" << endl;
anyKey();
ExitShip();

//he l p

return 0;
}
















// ---------------------------------------
// Function to prompt user to exit cockpit, housed in OTHER FUNCTION
// ---------------------------------------
void ExitShip()
{
char userInput;

while (userInput != 'n' || userInput != 'N') 
{
   cout << "(You choose to stay)" << endl;
   anyKey();
   cout << "Systems are still failing..." << endl;
   anyKey();
   cout << "Evacuate cockpit?" << endl;
   ExitShip();
}
}; 

// ---------------------------------------
// Function for linebreak
// ---------------------------------------
void anyKey()
{
   string dm;
   cout << "- Press enter to continue -" << endl;
   getchar();
   return;
}  

// ---------------------------------------
// Function for linebreak without an extra endl
// ---------------------------------------
void downOne()
{
  cout << "- Press enter to continue -";
  getchar();
  return;
}
  
// ---------------------------------------
// Will clear screen
// ---------------------------------------
void longClear()
{
  for (int i = 0; i < 25; i++)
  {
    cout << endl;
  }
}

// ---------------------------------------
// Will clear half the screen
// ---------------------------------------
void shortClear()
{
  for (int i = 0; i < 5; i++)
  {
    cout << endl;
  }
}

// ---------------------------------------
// This function is to start the Leave The
// Ship sequence. Will be the first major
// decision the character has to make
// Will augment obedience and dissent levels
// ---------------------------------------
char LeaveCockpit (char userInput)
{
 int sittingNum; 

if (userInput == 'y' || userInput == 'Y')
{
clearScreen();
}
else if (userInput == 'n' || 'N')
{
  int sittingNum = 0;
  while (sittingNum >= 0 && sittingNum < 2)
  {
    cout << "You feel like it would be a bad idea to continue sitting." << endl;
    cout << ">> Move? (Y/N)" << endl;
    sittingNum = sittingNumCount(sittingNum);
    //code below from sittingNumCount
    /*cin >> userInput;
      if (userInput == 'n' || userInput == 'N')
      {
        sittingNum++;
        return sittingNum++;
      }*/
  }
  if (sittingNum >= 2)
  {
    sittingNum = 2;
   while (sittingNum >= 2 && sittingNum < 4)
   {
    cout << "Your eyes water from the smoke. Something tells you it's a bad idea to stay here." << endl;
    cout << ">> Move? (Y/N)" << endl;
    sittingNum = sittingNumCount(sittingNum);
    dissent++;
    cout << "[Dissent has increased by 1]" << endl;
   }
  }
  if (sittingNum >= 4)
  {
    sittingNum = 4;
    while (sittingNum >= 4 && sittingNum < 6)
    {
    cout << "Sweat starts to sting your eyes. Something Tells you it's a bad idea to stay." << endl;
    cout << ">> Move? (Y/N)" << endl;
    sittingNum = sittingNumCount(sittingNum);
    dissent++;
    cout << "Dissent has increased by 1]" << endl;
    }
  }
  if (sittingNum >= 6)
  {
    sittingNum = 6;
    while (sittingNum >= 6 && sittingNum < 8)
    {
    cout << "It's a bad idea to stay. [LEAVE.]" << endl;
    downOne();
    cout << "(You stand, unbidden.)" << endl << endl;
    cout << ">> Move? (Y/N)" << endl;
    sittingNum = sittingNumCount(sittingNum);
    dissent++;
    dissent++;
    cout << "[Dissent has increased by 2]" << endl;
    }
  }
  if (sittingNum == 8)
  {
    cout << "[GET OUT.]" << endl;
    cin.ignore();
    anyKey();
    cout << "(You leave the room immediately. Your stomach ache ceases abruptly," << endl; 
    downOne();
    cout << "Your eyes stop watering. You head into the corridor outside the cockpit." << endl;
    obedience++;
    cout << "[Obedience increased by 1]" << endl;
    for (int i = 0; i < 2; i++)
    {
      obedience++;
    }
    anyKey();
  }
}
else 
{
  cout << "Invalid selection, please enter a valid choice (Y/N):" << endl;
  LeaveCockpit(userInput);
}
//return userInput;
return sittingNum;
}

// ---------------------------------------
// This function is nested within LeaveShip
// It is to keep track of the number of sittingNum
// times the loop has cycled through. Impacts
// player choices
// ---------------------------------------
int sittingNumCount (int sittingNum)
{
    char userInput;
    
    cin >> userInput;
      if (userInput == 'y' || userInput == 'Y')
      {
        clearScreen();
      }
      if (userInput == 'n' || userInput == 'N')
      {
        sittingNum++;
      }
      return sittingNum;
}

// ---------------------------------------
// Function to clear screen and begin exploring
// cockpit, potentially.
// ---------------------------------------
void clearScreen()
{
char userInput;
cout << "(You clear the screen and look around)." << endl;
anyKey();
cin.ignore();
cout << "You're strapped into the command chair of a one-person craft. \n";
cout << "The ship lists heavily forward, the only thing keeping you strapped \nin to the chair is the safety restraints." << endl;
anyKey();

cout << "Smoke is heavy in the air. It's becoming difficult to breathe. The protective cockpit canopy in front \nof you is broken. Branches and strips of splintered white wood poke through. It is impassable." << endl;
downOne();

cout << endl << "You glance down at the remains of your uniform. There are no distinguishing marks left on it." << endl;
anyKey();
cout << "> Try to look closer at uniform? (Y/N)" << endl;
cin >> userInput;
if (userInput == 'n' || userInput == 'N')
{
  cout << "You feel like that's maybe not so important right now." << endl;
}
else if (userInput == 'y' || userInput == 'Y')
{
  cout << "(You try to look closer at the uniform you're wearing.)" << endl;
  anyKey();
  cin.ignore();
  cout << "You squint, but your eyes are watering from the smoke. It's hard to focus." << endl;
  cout << "You decide it might be better to look later, if you can find a reflective surface somewhere." << endl;
}
else 
{
  cout << "Your head swims in confusion at the choices. You decide you'll think about it later." << endl;
} 
anyKey();
cout << endl << "You feel the heat from beyond the cockpit rising." << endl;

//function to explore
exploreCockpit();
}

// ---------------------------------------
// This function should trigger the second
// branch of decisions the player can make
// that will impact the short story.
// Will effect inventory
// Nested in clearScreen()
// ---------------------------------------
void exploreCockpit()
{
  longClear();
  longClear();
  char userInput;
  
  //checkObed();
  
  cout << ">> Explore the cockpit? (Y / N)" << endl;
  cin >> userInput;
  int userSelect;
  cout << endl;
  
  //player choices begin
  if (userInput == 'y' || userInput == 'Y')
  {
     //+ means an attribute increased, display somehow
    cout << "+ [Dissent has increased by 1.]" << endl;
    dissent++;
	  cout << "You look around, but the cockpit is small. The only points of notice are: \n\n (1) the command chair, (2) a flaming console, and (3) the canopy." << endl;
	  cout << "(Select 1-3 to explore)" << endl;
    anyKey();
  cin >> userSelect;
  //switch statement here for exploring immediate environ. This part goes here so the player can learn how to select locations.
  switch(userSelect)
  {
    case 1:
    cout << ">> Look at command chair? (Y/N)" << endl;
    cin >> userInput;
    if (userInput == 'y' || userInput == 'Y')
    {
      cout << "You just came from there. It's listing forward, now completely unusable. The armrest panels are shattered and flickering dangerously. \n It's even smoking a bit. (You decide not to inspect it closer.)" << endl;
      //exit function
    }
    else if (userInput == 'n' || userInput == 'N')
    {
      cout << "(You decide not to inspect it closer.)" << endl;
      //function here
    }
    else
    {
      cout << "You are indecisive, but you must select (Y)es or (N)o." << endl;
      cin >> userInput;
      // this might not work correctly...
    }
    break;
    case 2:
    cout << ">> Look at the flaming console? ... The one thats on fire?" << endl;
    cin >> userInput;
    if (userInput == 'y' || userInput == 'Y')
    {
      cout << "The console is on -fire-. You aren't wearing protective gear, beyond your lightly-toasted uniform." << endl;
      anyKey();
      cout << "> Leave? (Y/N)" << endl;
      cin >> userInput;
      if (userInput == 'y' || userInput == 'Y')
      {
        cout << "(You decide to ignore the console.)" << endl;
        anyKey();
        cout << "Probably a good idea, since it's on fire." << endl;
        downOne();
        cout << "You make your way towards the door." << endl;
        //where does this send out to?
      }
      cout << "It would probably be a bad idea to get closer..." << endl;
      anyKey();
      cout << ">> Get closer?" << endl;
      cin >> userInput;
      if (userInput == 'y' || userInput == 'Y')
      {
        cout << endl;
	      cout << "Nothing really to see here, except..." << endl;
	      anyKey();
	      cout << "Except?" << endl;
      	anyKey();
	      cout << "... What's that under the console?" << endl;
	      anyKey();
      	cout << ">> Examine? (Y/N)" << endl; 
        cin >> userInput;
        	if (userInput == 'y' || userInput == 'Y')
      	    {
		          cout << "(You look under the console)" << endl;
		          anyKey();
		          cout << "+ You receive PACKED SUPPLIES." << endl;
		          anyKey();
		          cout << "You don't remember packing these, but... there are no other life signs aboard." << endl;
		          anyKey();
		          cout << "You must have put these here... right?" << endl;
		          anyKey();
		          cout << ". . ." << endl;
		          anyKey();
		    //class for inventory option
	    	//press [i] to open inventory
	    	//some kind of int for inventory save file
	          }
	         else if (userInput == 'n' || userInput == 'N')
	         {
	           cout << "(You decide to ignore the console.)" << endl;
	           anyKey();
	           cout << "Probably a good idea, since it's on fire." << endl;
	         }
      }
      else
      {
        cout << "(You decide to ignore the console.)" << endl;
        anyKey();
        cout << "Probably a good idea, since it's on fire..." << endl;
      }
    }
    break;
    case 3: 
    cout << ">> Inspect the broken canopy?" << endl;
    cin >> userInput;
    if (userInput == 'y' || userInput == 'Y')
    {
      cout << "Upon closer inspection, it's nothing but glass and pointy trees." << endl;
      anyKey();
      cout << "You're not wearing shoes, so you don't feel like it would be a good idea to check that out." << endl;
      anyKey();
      cout << "[Good choice.]" << endl;
      anyKey();
    }
    break;
    default: cout << "(You feel disoriented and confused by the choices presented.)" << endl;
    anyKey();
    cout << "(You opt to ignore the options in front of you and focus elsewhere.)" << endl;
  }
}
else
{ //this is where the skip would stop
   cout << "You smell the ship burning." << endl;
   anyKey();
   cout << ">> Evacuate? (Y/N)" << endl;
   ExitShip();
}
}

//checkObed()
//{
  
//}

//undeclared function
void insideTheShip ()
{
  //this needs to be grandfathered into the older function
  cout << "You open the door of the cockpit. Something ";
  if (obedience >= 2)
  {
    cout << "Tells ";
  }
  else if (obedience < 2)
  {
    cout << "tells ";
  }
  cout << "you that you've been here before. \nYou aren't sure what to think." << endl;
  anyKey();
  cout << "The ship is still burning. That same ";
  if (obedience >= 2)
  {
    cout << "Feeling ";
  }
  else if (obedience < 2)
  {
    cout << "feeling ";
  }
  cout << "you keep having seems to urge you to leave. However, \nyou can make out doors on either side of the corridor that might \nhold supplies." << endl;

  cout << ">> Investigate?" << endl;
  //map function
}

void mapPicture()
{
  cout << "====================" << endl;
  cout << "|" << setw(30) << "|" << endl;
}

