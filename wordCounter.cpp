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

struct UserInput {
    string phrase;
    char yesNo;
};

int main() {
    UserInput user;
    do {
        // Gets data.
        cout << "Enter a word or a phrase with single spaces between words: ";
        getline(cin, user.phrase);

        // Outputs data.
        cout << endl << "Number of Characters: " << user.phrase.length() << endl;
        cout << "Number of Letters: " << countLetters(user.phrase) << endl;
        cout << "Number of Words: " << countWords(user.phrase) << endl << endl;

        // Asks to run again.
        cout << "Would you like to run again? (Y or N) ";
        cin >> user.yesNo;

        cin.ignore();

    } while (validateEntry(user.yesNo) == 'Y');
    
    return 0;
}

int countLetters(string phrase) {
    int letterCounter = 0;

    for (int i = 0; i < phrase.size(); i++) {
        // Increments counter based on ASCII values for letters.
        if ((phrase[i] >= 65 && phrase[i] <= 90) || (phrase[i] >= 97 && phrase[i] <= 122)) {
            letterCounter++;
        }
    }

    return letterCounter;
}

int countWords(string phrase) {
    int wordCounter = 0;

    for (int i = 0; i < phrase.size(); i++) {
        // Increments counter based on spaces and newline characters.
        if (phrase[i] == ' ' || phrase[i] == '\n') {
            wordCounter++;
        }
    }

    wordCounter += 1;
    return wordCounter;
}

// Validates user entry for re-running program.
char validateEntry (char yesNo) {
    while (toupper(yesNo) != 'Y' && toupper(yesNo) != 'N') {
        cout << "ERROR: Invalid entry. Please try again." << endl;
        cin >> yesNo;
    }
    
    char validEntry = toupper(yesNo);
    return validEntry;
}
