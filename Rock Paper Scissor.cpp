#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

enum Selection {
    NONE,
    ROCK,
    PAPER,
    SCISSORS
};

enum Result {
    DRAW,
    WON,
    LOST,
    ERROR
};

//String to integer to convert user's input to integer
int StringToInteger(string NumberAsString) {

  int NumberAsInteger=0;

  for (int i = 0; i < NumberAsString.size(); i++)

  NumberAsInteger = NumberAsInteger * 10 + (NumberAsString[i] - '0');

	return NumberAsInteger;
}


// Figure out what the selection is from the specified integer
Selection GetSelectionForInteger(int inputInteger) {
  if( inputInteger == 1 )
	{
  return ROCK;
	}
	else if( inputInteger == 2 )
	{
	return PAPER;
	}
	else if( inputInteger == 3 )
	{
	return SCISSORS;
	}
	else
	{
	return NONE;
	}
	}

// Returns a random number between min and max, inclusive of both
int GetRandomNumber(int min=0, int max=3) {

  int random;
  int s=min+max;

  srand((int)time(0));

  random = (rand() % s) + 1 ;

  return random;

}


// Returns the selection for the AI according to a certain strategy
Selection GetAISelection() {
        int ai_selection;
	ai_selection=GetRandomNumber();
	if(ai_selection == 1)
	{
	return ROCK;
	}
	else if(ai_selection == 2)
	{
	return PAPER;
	}
	else if(ai_selection == 3)
	{
	return SCISSORS;
	}
	else
	{
	return NONE;
	}
}


// Compares the user's selection to the AI's selection,
// and determines the result of the round. If the user beats
// the AI it is considered a WIN, etc.
Result GetResult(Selection userSelection, Selection aiSelection) {
  if( userSelection == aiSelection )
	{
	return DRAW;
	}
	else if (userSelection == 3 && aiSelection == 2)
        {
	return 	WON;
	}
	else if (userSelection == 2 && aiSelection == 1)
	{
	return WON;
	}
	else if (userSelection == 1 && aiSelection == 2)
	{
	return LOST;
	}
	else if (userSelection == 1 && aiSelection == 3)
	{
	return WON;
	}
	else if (userSelection == 2 && aiSelection == 3)
	{
	return LOST;
	}
	else if (userSelection == 3 && aiSelection == 1)
	{
	return LOST;
	}
	else
	{
	return ERROR;
	}
}



// Display the instructions of what number corresponds to which selection
void ShowInitalUI(int roundNum) {
    cout << "\nRound #" << roundNum << ":\n";
    cout << "\nEnter the number associated with the option below to select your move:";
    cout << "\n1. Rock";
    cout << "\n2. Paper";
    cout << "\n3. Scissors";
    cout << "\n\nQ. Quit the game";
    cout << "\n> ";
}

// Displays the appropriate string for each Selection
void DisplaySelection(Selection a_nSelection) {
        if( a_nSelection == 1 )
	{
	cout<<"ROCK";
	}
	else if( a_nSelection == 2 )
	{
	cout<<"PAPER";
	}
	else if( a_nSelection == 3 )
	{
	cout<<"SCISSORS";
	}
	else
	{
	cout<<"Wrong Selection";
	}

}


// Displays an appropriate string for each Result
void DisplayResult(Result result) {
  if(result == WON)
	{
 	cout<<"\n\n YOU have WON this round";
	}
	else if(result == LOST)
	{
  	cout<<"\n\n The COMPUTER has WON this round";
	}
	else if(result == DRAW)
	{
 	 cout<<"\n\n This round is a DRAW";
	}
	else
	{
 	cout<<"\n\n Oops! Something has gone wrong!";
  	}
}

//Functions END


//MAIN Begins
int main(int argc, const char * argv[]) {

    // Init variables
    int roundNum = 1;

    Selection playerSelection = NONE;
    Selection aiSelection     = NONE;

    // Start game

    cout << "\nWelcome to a game of Rock, Paper, Scissors!\n";
    //Show Basic information about the game.

    ShowInitalUI(roundNum);

    // Gets player input
    string input;
    getline(cin,input);
    int temp;   //temp used to store the converted integer
    temp=StringToInteger(input); //StringToInteger User Defined funtion

    int playerInputInt;
    playerInputInt=temp;

    //Get selection for the interger supplied
    playerSelection = GetSelectionForInteger(playerInputInt);

    // Show selected option
    cout<<"\nYou have Selected: ";
    DisplaySelection(playerSelection);

    // Let the AI make a selection
    aiSelection = GetAISelection();


    // Show option selected by AI
    cout<<"\nThe Computer has Selected: ";
    DisplaySelection(aiSelection);

    // Display final result
    Result result = GetResult(playerSelection, aiSelection);

    //Display Results
    DisplayResult(result);

    cout<<"\n";

    cout << "\nThank you for playing! \n";

    return 0;

}
