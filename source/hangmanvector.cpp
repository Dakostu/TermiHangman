// Daniel Kostuj, 2017
// Use of this source code is governed by the license that can be
// found in the LICENSE file.
#include "GrabBag.h"
#include "hangmanvector.h"
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

HangmanVector::HangmanVector(string file) {	
    // save words from file into a GrabBag
	ifstream fin(file);
    GrabBag<string> words;
    string currentWord;
    while (fin >> currentWord)
        words.insert(currentWord);
    if (!words.size()) {
        cerr << "File is empty." << endl;
        exit(1);
    }
    
    currentWord = words.grab();
    
    // Read only letters from the English alphabet
    copy_if(currentWord.begin(), currentWord.end(), back_inserter(vec), [this](const char c) { 
        return isalpha(c);
    });
        
    if (!vec.size()) {
        cerr << "No usable words found." << endl;
        exit(1);
    }
}


bool HangmanVector::isGuessed() {
    return (all_of(vec.begin(), vec.end(), [this](HangmanChar &hangC) { return hangC.isGuessed(); }));
}

bool HangmanVector::WordContains(const char &checkChar) {
    auto wordContainsChar = false;    
    for_each(vec.begin(), vec.end(), [this, checkChar, &wordContainsChar](HangmanChar &hangC) { 
        if (hangC == checkChar) { wordContainsChar = true;}         
    });
    return wordContainsChar;
}

string HangmanVector::reveal() {
    string revealedWord;
    transform(vec.begin(), vec.end(), back_inserter(revealedWord), [this](HangmanChar &c) {
        return c.reveal();
    });
    return revealedWord;
}

string HangmanVector::toString() {
    string vectorString;
    transform(vec.begin(), vec.end(), back_inserter(vectorString), [this](HangmanChar c) {
        return c.toString();
    });
    return vectorString;
}
    

