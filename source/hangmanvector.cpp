// Daniel Kostuj, 2017
// Use of this source code is governed by the license that can be
// found in the LICENSE file.
#include "GrabBag.h"
#include "hangmanvector.h"
#include <algorithm>
#include <iostream>
#include <random>
#include <iterator>
#include <fstream>
#include <cctype>
#include <ctime>
#include <sstream>

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

bool HangmanVector::WordContains(const char &c) {
    return any_of(vec.begin(), vec.end(), [this, c](HangmanChar &hangC) { return hangC.isCorrect(c); });
}

string HangmanVector::reveal() {
    stringstream ss;
    for (auto it = vec.begin(); it != vec.end(); ++it)
		ss << it->reveal();
	return ss.str();
}

string HangmanVector::toString() {
    stringstream str;
	for (auto it = vec.begin(); it != vec.end(); ++it)
		str << it->toString();
	return str.str();
}
    

