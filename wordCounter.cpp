//
// wordCounter.cpp
// Author: jameserv
//

#include <iostream>
#include <iomanip>
#include <string>

// Function prototypes.
int countLetters(std::string);
int countWords(std::string);
char validateEntry(char);

struct UserInput {
    std::string phrase;
    char yesNo;
};

int main() {
    UserInput user;
    do {
        // Gets data.
        std::cout << "Enter a word or a phrase with single spaces between words: ";
        std::getline(std::cin, user.phrase);

        // Outputs data.
        std::cout << std::endl << "Number of Characters: " << user.phrase.length() << std::endl;
        std::cout << "Number of Letters: " << countLetters(user.phrase) << std::endl;
        std::cout << "Number of Words: " << countWords(user.phrase) << std::endl << std::endl;

        // Asks to run again.
        std::cout << "Would you like to run again? (Y or N) ";
        std::cin >> user.yesNo;

        std::cin.ignore();
    } while (validateEntry(user.yesNo) == 'Y');
    return 0;
}

int countLetters(std::string phrase) {
    int letterCounter = 0;

    for (int i = 0; i < phrase.size(); i++) {
        // Increments counter based on ASCII values for letters.
        if ((phrase[i] >= 65 && phrase[i] <= 90) || (phrase[i] >= 97 && phrase[i] <= 122)) {
            letterCounter++;
        }
    }
    return letterCounter;
}

int countWords(std::string phrase) {
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
        std::cout << "ERROR: Invalid entry. Please try again." << std::endl;
        std::cin >> yesNo;
    }
    char validEntry = toupper(yesNo);
    return validEntry;
}
