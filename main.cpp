//
// This program calculates number of characters and words from user input.
// Author: jameserv
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int countWords();

int main()
{
    string userInput;

    cout << "Enter a word or phrase:\n";
    getline(cin, userInput);

    cout << "Number of Characters: " << userInput.length() << endl;
    return 0;
}