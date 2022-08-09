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

int main()
{
    string userInput;

    cout << "Enter a word or a phrase with single spaces between words: ";
    getline(cin, userInput);
    
    cout << "Number of Characters: " << userInput.length() << endl;
    cout << "Number of Letters: " << countLetters(userInput) << endl;
    cout << "Number of Words: " << countWords(userInput) << endl;
    return 0;
}

int countLetters(string userInput)
{
    int letterCounter = 0;

    for (int i = 0; i < userInput.size(); i++)
        if (userInput[i] != ' ' && userInput[i] != '\n')
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
