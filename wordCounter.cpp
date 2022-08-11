//
// wordCounter.cpp
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

int main() {
    string userInput = "\0";
    char yesNo = '\0';

    do {
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

int countLetters(string userInput) {
    int letterCounter = 0;

    for (int i = 0; i < userInput.size(); i++) {
        // Increments counter based on ASCII values for letters.
        if ((userInput[i] >= 65 && userInput[i] <= 90) || (userInput[i] >= 97 && userInput[i] <= 122)) {
            letterCounter++;
        }
    }

    return letterCounter;
}

int countWords(string userInput) {
    int wordCounter = 0;

    for (int i = 0; i < userInput.size(); i++) {
        // Increments counter based on spaces and newline characters.
        if (userInput[i] == ' ' || userInput[i] == '\n') {
            wordCounter++;
        }
    }

    wordCounter += 1;
    return wordCounter;
}

// Validates user entry for re-running program.
char validateEntry (char yesNo) {
    while (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N') {
        cout << "ERROR. Invalid entry. Please try again." << endl;
        cin >> yesNo;
    }
    
    char validEntry = toupper(yesNo);
    return validEntry;
}
