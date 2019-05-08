#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <cctype>
#include <time.h>
using namespace std;

//function to print various messages depending on function
void PrintMsg(string msg, bool printTop = true, bool printLower = true)
{
  if(printTop) //prints top of game 'screen'
  {
    cout << " = = = = = = = = = = = = = = = = = = = =" << endl;
  cout << "|";
  }
  else
  {
    cout << "|";
  }
  bool front = true;
  for(int i = msg.length(); i < 40; i++)
  {
    if (front)
    {
      msg = " " + msg;
    }
    else
    {
      msg = msg + " ";
    }
    front = !front; //to set false to true and vice versa to successfully print message
  }
  cout << msg.c_str(); //character string from message

  if (printLower) //prints bottom of game 'screen'
  {
    cout << "|" << endl;
    cout << " = = = = = = = = = = = = = = = = = = = =";  
  }
  else 
  {
    cout << "|";
    cout << endl;
  }
}

//prototypes
string enterWord(string); //future use
int enterWord (int); //future use
void wordOutput(); //future use
string StartGameMenu(string); //""
void gameMenu(); //Menu for the start of the game
void guessesLeft8(); //hangman function
void PrintOkLetters(string); //prints letters used
bool PrintWordCheckWin (string, string); //prints word as guessed thus far + checks to see if player has won
void clearScreen(); //will ask if user wants to clear screen
void printLetters(string, char, char); //prints out letters
string randomWord(string); //chooses word from words.txt
void drawNoose(int); //an attempt at drawing a hangman
void playAgain(); //asks user if they want to play again
void screenClear(); //clears screen with line breaks
int attemptsLeft(string, string); //guesses allowed, to work with drawNoose

//global vars
int WRONG_GUESSES = 8; 
int count = 0;
int wrong = 0; //incorrect guesses

int main()
{
  srand(time(0));
  //variables
  char yesNo; //to hold yes/no binary choices
  int choice; //to hold switch choices
    
  string s;
  //int guessCount = 0;
  //int numLetters; //to hold number of letters in a word
  //string theWord; //to hold user's word choice
  string wordToGuess; //word from pre-set word file
  string guesses; //holds the letter user guesses
  //string used = ""; //letters guessed already
  bool win = false;
    //string userGuess; // to hold word guesses from user
  int tries = 0;
  gameMenu();
  wordToGuess = randomWord("words.txt");
  
  //drawNoose(8);
  do
  {
   screenClear();
   //tries=0
   PrintMsg("HANGMAN");
   cout << endl;
   //clearScreen();
   drawNoose(tries);
   PrintOkLetters(guesses);
   PrintMsg("Guess the word!");
   win = PrintWordCheckWin(wordToGuess, guesses);
  
  if (win)
    break;

  char fromUser;
  cout << ">";
  cin >> fromUser;
  if(guesses.find(fromUser) == string::npos)
    guesses += fromUser; //will add char from user's guesses to list by checking if it is already in the list or not

  tries = attemptsLeft(wordToGuess, guesses);

  } while(tries < 10);
  cout << endl;

  //************************************************
  //To include at a later time w/ user-entered words
  //************************************************

  /*wordToGuess = randomWord("words.txt");
  theWord = enterWord(theWord);
  numLetters = enterWord(count);
  cout << "Your word has been saved! Begin game?" << endl << endl;
  StartGameMenu(theWord);
*/

 cout << endl;
  
if (win)
{
  cout << " = = = = = = = = = = = = = = = = = = = =" << endl;
  PrintMsg("YOU WON!");
  //cout << " = = = = = = = = = = = = = = = = = = = =" << endl;
  playAgain();
}
else
{
  cout << " = = = = = = = = = = = = = = = = = = = =" << endl;
     cout << setw(40) << "GAME OVER!" << endl;
      cout << " = = = = = = = = = = = = = = = = = = = =" << endl << endl;
    playAgain();
}
getchar();

}


// * * * * * * * * * * * * * * * * * * * *
//                FUNCTIONS
// * * * * * * * * * * * * * * * * * * * *

/*void guessesLeft8()
{
  char guesses;
  cout << " = = = = = = = = = = = = = = = = = = = = " << endl;
  cout << "|" << setw(40) << "|" << endl;
  cout << "|" << setw(15) << "Guesses Left: " << (WRONG_GUESSES - wrong) << setw(17) << "+----+" << setw(7) << "|" << endl;
  cout << "|" << setw(33) << "|    |" << setw(7) << "|" << endl;
  cout << "|" << setw(33) << "|" << setw(7) << "|" << endl;
  cout << "|" << setw(33) << "|" << setw(7) << "|" << endl;
  cout << "|" << setw(33) << "|" << setw(7) << "|" << endl;
  cout << "|" << setw(33) << "|" << setw(7) << "|" << endl;
  cout << "|" << setw(37) << "=========" << setw(3) << "|" << endl;
  cout << "|" << setw(40) << "|" << endl;
  cout << " = = = = = = = = = = = = = = = = = = = = " << endl;
  cout << "Word: ";
  wordOutput();
  
}*/
  
string enterWord(string theWord)
{
  //function to ask the user to enter the word they would like to use
  cout << "Please type a word to use and press Enter: " << endl;
  getline(cin, theWord); //should hopefully be just one word
  //theWord = toupper(theWord); //make uppercase since secret word in uppercase
  for (int i = 0; theWord[i]; i++)
  {
    count++;
  }
  return theWord;
}

int enterWord(int count)
{
  string theWord;
  //function to ask the user to enter the word they would like to use
  cout << "Please confirm word and press Enter: " << endl;
  getline(cin, theWord);
  
  cout << endl;
  for (int i = 0; theWord[i]; i++)
  {
    count++;
  }
  return count;
}

//function for future use (provides blank spaces for user-entered words)
void wordOutput ()
{
    int c = count;
  do
  {
    cout << "_ ";
    c--;
  } while (c > 0);
  cout << endl;
}

void screenClear()
{
   for (int n = 0; n < 50; n++)
      cout << endl;
}

void clearScreen()
{
  char yesNo;
  
  cout << "Would you like to clear the screen and start the game? (y/n)" << endl;
  cin >> yesNo;
  cout << endl;
  if (yesNo == 'y' || yesNo == 'Y')
    {
     for (int n = 0; n < 50; n++)
      cout << endl;
    }
  else if (yesNo == 'n' || yesNo == 'N')
  {
    cout << "Are you sure? If you do not clear the screen, the other player will be able to see your chosen word..." << endl;
    cout << "Clear screen? (y/n)" << endl;
    cin >> yesNo;
    if (yesNo == 'y' || yesNo == 'Y')
    {
     for (int n = 0; n < 50; n++)
      cout << endl;
    }
    else if (yesNo == 'n' || yesNo == 'N')
    {
      cout << "(Starting game. . .)" << endl;
    }
  }
  else 
  {
    cout << "Invalid input... Please enter yes or no..." << endl;
    clearScreen();
  }
  cout << endl;
  }
  
  /*void StartGameMenu()
  {
    string userWord = theWord;
    int choice;
    char yesNo;
    cout << "| * * * || * * * * * || * * * * * || * * * |" << endl;
    cout << "| " << setw(20) << "1. Exit Program" << setw(15) << "2. Start Game" << setw(7) << "|" << endl;
    cout << "|" << setw(32) << "3. Enter Different Word" << setw(11) << "|" << endl;
    cout << "| * * * || * * * * * || * * * * * || * * * |" << endl << endl;

  cin >> choice;
  switch (choice)
  {
    case 1: 
      cout << "Are you sure? (y/n)" << endl;
      cin >> yesNo;
      if (yesNo == 'y')
      {
        cout << "Exiting program . . .";
        exit(0);
      }
      else if (yesNo == 'n')
      {
        cout << endl << "Returning to previous menu. . ." << endl << endl;
        StartGameMenu(theWord);
      }
      else
      cout << "Invalid entry. Please type 'y' or 'n' and press Enter/Return. Returning you to previous menu. . . " << endl;
      StartGameMenu(theWord);
      break;
      case 2:
        cout << "Starting your Game. One moment please. . ." << endl << endl;
        clearScreen();
        break;
      case 3:
        cout << endl << "Your current word is: " << userWord << "." << endl;
        cout << "Would you like to choose a different word? (y/n)" << endl;
        cin >> yesNo;
        if (yesNo == 'y')
        {
          enterWord(theWord);
        }
        else if (yesNo == 'n')
        {
          cout << endl << "If you are happy with your word, please select '2' from the previous menu." << endl;
          cout << "Returning to previous menu. . ." << endl << endl;
          StartGameMenu(theWord);
        }
        else
        {
          StartGameMenu(theWord);
        }
        break;
        default: 
        cout << "An error has occurred! Exit program and try again." << endl;
        exit(0);
        break;
  }
  }*/

//pyramids
void PrintOkLetters(string taken)
{
  PrintMsg("Available Letters");
  cout << endl;
  printLetters(taken, 'A', 'M');
  cout << endl;
  printLetters(taken, 'N', 'Z');
}

//checks to see if what's been entered is in the string chosen and checks for win bool
bool PrintWordCheckWin (string word, string guessed)
{
  bool won = true;
  string c;
  for (int i = 0; i < word.length(); i++)
  {
    if(guessed.find(word[i]) == string::npos)
    {
      won = false;
      c += "_ ";
    }
    else
    {
      c += word[i];
      c += " ";
    }
  }
  PrintMsg(c, false);
  return won;
}
//random word chooser
string randomWord(string path)
{
  int lineCount = 0;
  string word;
  //vector to hold words
  vector<string> words;
  ifstream reader(path);
  if (reader.is_open())
  {
    while (getline(reader, word))
    words.push_back(word);

    int randomLine = rand() % words.size();

    word = words.at(randomLine);
  }
  return word;
}

int attemptsLeft(string word, string guessed)
{
  int wrong = 0;
  for (int i = 0; i < guessed.length(); i++)
  {
    if(word.find(guessed[i]) == string::npos)
        wrong++;
      return wrong;
  }
return wrong;
}

void drawNoose(int guessCount = 0)
{
  if (guessCount >= 1)
    PrintMsg(" | ", false, false);
  else
    PrintMsg("", false, false);

  if (guessCount >= 2)
    PrintMsg(" | ", false, false);
  else
    PrintMsg("", false, false);
    
  if (guessCount >= 3)
    PrintMsg(" O ", false, false);
  else
    PrintMsg("", false, false);

  if (guessCount == 4)
    PrintMsg(" | ", false, false);

  if (guessCount == 5)
    PrintMsg("/| ", false, false);
 
  if (guessCount >= 6)
    PrintMsg("/|\\", false, false);
  else
    PrintMsg("", false, false);

  if (guessCount == 7)
    PrintMsg("/", false, false);
  
  if (guessCount >= 8)
    PrintMsg("/ \\", false, false);
  else
    PrintMsg("", false, false);
  //else
    //PrintMsg("", false, false)     
}

void playAgain()
{
  char yesNo;

  cout << "> Would you like to play again? (y/n)" << endl;
  cin >> yesNo;
  if (yesNo == 'y' || yesNo == 'Y')
  {
    cout << "Returning to main menu!" << endl;
    main(); //idk if this will work
  }
  else if (yesNo == 'n' || yesNo == 'N')
  {
    cout << "Thanks for playing!" << endl;
    cout << "Exiting program. . ." << endl;
    exit(0);
  }
  else
  {
    cout << "Invalid input! Please enter 'Y' for yes or 'N' for no..." << endl;
    playAgain();
  }
}

void printLetters(string input, char from, char to)
{
  string s;
  for(char i = from; i <= to; i++)
  {
    //ascii characters to loop through
    if (input.find(i) == string::npos)
      {
        s += i;
        s += "  ";
      }
    else
      s += "  ";
  PrintMsg(s, false, false);
}
}

void gameMenu()
{
   int menuChoice;
char choiceYN;
  while (menuChoice > 0)
  {
    cout << setw(76) << "* * * | * * * * * | * * * * * | * * * * * | * * * * * | * * * * * | * * *" << endl;
cout << setw(5) << " * " << setw(72) << " * " << endl;
cout << setw(5) << " * " << setw(39) << " Welcome! " << setw(33) << " * " << endl;
cout << setw(5) << " * " << setw(72) << " * " << endl;
cout << setw(5) << " * " << setw(62) << "To get started, choose an option from the menu (0-4): " << setw(10) << " * " << endl;
cout << setw(5) << " * " << setw(72) << " * " << endl;
cout << setw(5) << " * " << setw(31) << "(1) New Game" << setw(20) << "(2) Quit Program" << setw(21) << " * " << endl;
cout << setw(5) << " * " << setw(38) << "(3) About" << setw(23) << setw(34) << " * " << endl;
//cout << setw(5) << " * " << setw(30) << "5.) Codex" << setw(22) << "6.) Player Info" << setw(20) << " * " << endl;
//cout << setw(5) << " * " << setw(40) << "7.) Levelling" << setw(32) << " * " << endl;
cout << setw(5) << " * " << setw(72) << " * " << endl;
cout << setw(5) << " * " << setw(72) << " * " << endl;
cout << setw(76) << "* * * | * * * * * | * * * * * | * * * * * | * * * * * | * * * * * | * * *" << endl;
cin >> menuChoice;
cout << endl << endl << endl;
switch (menuChoice)
{
case 1:
cout << setw(74) << "* * | * * * * * | * * * * * | * * * * * | * * * * * | * * * * * | * *" << endl;
cout << setw(7) << " * " << setw(40) << " | NEW GAME | " << setw(28) << " * " << endl;
cout << setw(74) << "* * | * * * * * | * * * * * | * * * * * | * * * * * | * * * * * | * *" << endl << endl;
//cout << " * " << setw(76) << " * " << endl;
//cout << " * " << setw(75) << " * " << endl;
cout <</* " * " << */ setw(57) << " > Would you like to start a new game? ( Y / N )" << endl;
cin >> choiceYN;
cout << endl;
if (choiceYN == 'Y' || choiceYN == 'y')
{
//FUNCTION FOR NEW GAME START HERE 
return;
}
else if (choiceYN == 'n' || choiceYN == 'N')
{
cout << "Returning to Main Menu. . ." << endl;
cout << string(50, '\n');
//startUpMenu();
}
break;
case 2:
cout << setw(73) << "* | * * * * * | * * * * | * * * * * * * | * * * * * | * * * * * | *" << endl;
cout << setw(7) << " *" << setw(41) << "  | QUIT  PROGRAM | " << setw(26) << " * " << endl;
cout << setw(74) << " * | * * * * * | * * * * | * * * * * * * | * * * * * | * * * * * | * " << endl << endl;
cout << setw(57) << "> Would you like to quit the program? ( Y / N )" << endl;
cin >> choiceYN;
cout << endl;
if (choiceYN == 'Y' || choiceYN == 'y')
{
cout << "Exiting program. . ." << endl;
exit(0);
}
else if (choiceYN == 'n' || choiceYN == 'N')
{
cout << "Returning to Main Menu. . ." << endl;
cout << string(50, '\n');
//startUpMenu();
}
break;
case 3:
cout << setw(73) << "* | * * * * * | * * * * * | * * * | * * * * * | * * * * * | *" << endl;
cout << setw(13) << " *" << setw(35) << "  | ABOUT | " << setw(26) << " * " << endl;
cout << setw(74) << " * | * * * * * | * * * * * | * * * | * * * * * | * * * * * | * " << endl << endl;
cout << "This is a fairly basic hangman game with a few pre-programmed words." << endl;
cout << "To start, return to the main menu and select New Game! Then, enter \nan UPPERCASE letter to guess. The two Word Pyramids are the letters \nyou can choose from. Once you've guessed a letter, it will disappear \nfrom the pyramid! Try to guess in as few choices as possible." << endl << endl;
break;
default: cout << "Invalid selection! Returning to menu..." << endl;
gameMenu();
break;
}
  }
}