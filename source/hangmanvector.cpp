// Daniel Kostuj, 2017
// Use of this source code is governed by the license that can be
// found in the LICENSE file.
#include "hangmanvector.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>

using namespace std;

HangmanVector::HangmanVector(string file) {	
    // save words from file into a vector
	ifstream fin(file);
    vector<string> words;
    string currentWord;
    while (fin >> currentWord)
        words.push_back(currentWord);
    if (!words.size()) {
        cerr << "File is empty." << endl;
        exit(1);
    }
    
    srand(time(0));
    currentWord = words.at(rand()%words.size());
    
    // Read only letters from the English alphabet
    for (int i = 0; i < currentWord.length(); ++i)
	    if (currentWord[i] >= 'A' && currentWord[i] <= 'Z'	
            || currentWord[i] >= 'a' && currentWord[i] <= 'z')
		       vec.push_back(HangmanChar(currentWord[i]));	
        
    if (!vec.size()) {
        cerr << "No usable words found." << endl;
        exit(1);
    }
    
}


bool HangmanVector::isGuessed() {
    for (it = vec.begin(); it != vec.end(); ++it)
        if (it->isGuessed() == false)
             return false;
         
    return true;    
}

bool HangmanVector::WordContains(const char c) {
    bool contains = false;
    for (it = vec.begin();
        it != vec.end(); ++it) 
            if (it->isCorrect(c))
                 contains = true;
        
    return contains;
        
}

string HangmanVector::reveal() {
    stringstream ss;
    for (it = vec.begin(); it != vec.end(); ++it)
		ss << it->reveal();
	return ss.str();
    
}

string HangmanVector::toString() {
    stringstream str;
	for (it = vec.begin(); it != vec.end(); ++it)
		str << it->toString();
	return str.str();
}
    

