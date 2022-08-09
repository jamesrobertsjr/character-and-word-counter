//
// This program calculates number of characters and words from user input.
// Author: jameserv
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int countLetters(string);
int countWords(string);
char validateEntry(char);

int main()
{
    string userInput = "\0";
    char yesNo = '\0';

    do
    {
        cout << "Enter a word or a phrase with single spaces between words: ";
        getline(cin, userInput);

        cout << "Number of Characters: " << userInput.length() << endl;
        cout << "Number of Letters: " << countLetters(userInput) << endl;
        cout << "Number of Words: " << countWords(userInput) << endl;

        cout << "Would you like to run again? (Y or N) ";
        cin >> yesNo;

        cin.ignore();

    } while (validateEntry(yesNo) == 'Y');
    
    return 0;
}

int countLetters(string userInput)
{
    int letterCounter = 0;

    for (int i = 0; i < userInput.size(); i++)
        if ((userInput[i] >= 65 && userInput[i] <= 90) || (userInput[i] >= 97 && userInput[i] <= 122))
            letterCounter++;
   
    return letterCounter;
}

int countWords(string userInput)
{
    int wordCounter = 0;

    for (int i = 0; i < userInput.size(); i++)
        if (userInput[i] == ' ' || userInput[i] == '\n')
            wordCounter++;

    wordCounter += 1;
    return wordCounter;
}

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
