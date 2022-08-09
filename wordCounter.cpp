//
// This program calculates number of characters and words from user input.
// Author: jameserv
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes.
int countLetters(string);
int countWords(string);
char validateEntry(char);

int main()
{
    // Variables.
    string userInput = "\0";
    char yesNo = '\0';

    // Runs statements, then asks user if the would like to run again.
    do
    {
        // Gets data.
        cout << "Enter a word or a phrase with single spaces between words: ";
        getline(cin, userInput);

        // Outputs data.
        cout << endl << "Number of Characters: " << userInput.length() << endl;
        cout << "Number of Letters: " << countLetters(userInput) << endl;
        cout << "Number of Words: " << countWords(userInput) << endl << endl;

        // Asks to run again.
        cout << "Would you like to run again? (Y or N) ";
        cin >> yesNo;

        cin.ignore();

    } while (validateEntry(yesNo) == 'Y');
    
    return 0;
}

// Counts letters in user entry, then returns the count.
int countLetters(string userInput)
{
    int letterCounter = 0;

    // Loops based on size of user input.
    for (int i = 0; i < userInput.size(); i++)
        // Increments counter based on ASCII values for letters.
        if ((userInput[i] >= 65 && userInput[i] <= 90) || (userInput[i] >= 97 && userInput[i] <= 122))
            letterCounter++;
   
    return letterCounter;
}

// Counts words in user entry, then returns the count.
int countWords(string userInput)
{
    int wordCounter = 0;

    // Loops based on size of user input.
    for (int i = 0; i < userInput.size(); i++)

        // Increments counter based on spaces and newline characters.
        if (userInput[i] == ' ' || userInput[i] == '\n')
            wordCounter++;

    wordCounter += 1;
    return wordCounter;
}

// Validates user entry for re-running program.
char validateEntry (char yesNo)
{
    // Checks if the user submitted a proper entry. If not, it asks for a valid entry.
    while (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N')
    {
        cout << "ERROR. Invalid entry. Please try again." << endl;
        cin >> yesNo;
    }
    
    // Returns the valid entry.
    return toupper(yesNo);
}
