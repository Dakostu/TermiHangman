// Daniel Kostuj, 2017
// Use of this source code is governed by the license that can be
// found in the LICENSE file.

#include "GrabBag.h"
#include "hangmanvector.h"
#include "settostring.h"
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;
    
int main(int argc, char** argv) {        
    if (argc == 1) {
        cout << "Need a filename as an argument" << endl;
        return 1;
    }
    
    // save words from file into a GrabBag
    ifstream fin(argv[1]);
    GrabBag<string> words;
    string currentWord;
    while (fin >> currentWord)
        words.insert(currentWord);
    if (!words.size()) {
        cerr << "File is empty." << endl;
        exit(1);
    }
    
    
    int tries = 12;
    string response = "";
    HangmanVector wordToGuess(words.grab());
    
    // This set displays all letters that have been already entered
    set<char> enteredTries;
    
    while (!wordToGuess.isGuessed()) {
        
        printf("\033c"); // clear terminal screen at every new try        
        
        cout << "*** TERMI-HANGMAN ***" << endl;
        cout << response << endl; 
        cout << wordToGuess.toString() << endl;
        cout << "Enter the letter(s) you're guessing.\tRemaining tries: " 
        << tries << "\t" << setToString(enteredTries) << endl;
        
        char input;
        cin >> input;
        
                
        if (wordToGuess.wordContains(input))
            response = "Correct!";
        else {
            response = "Ouch!";
            --tries;
        }
        cout << endl;
        
        enteredTries.emplace(toupper(input));

        if (!tries) {
            cout << "--- YOU DIED ---" << endl;
            cout << "The word was:"<< endl;
            cout << wordToGuess.reveal() << endl;
            return 0;
        }
        
        if (wordToGuess.isGuessed()) {
            cout << "--- YOU WON! ---" << endl;
            cout << "--- " << wordToGuess.reveal() << " ---" << endl;
            return 0;
        }
        
    }
    return 0;
}


    




