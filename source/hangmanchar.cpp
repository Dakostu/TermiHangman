// Daniel Kostuj, 2017
// Use of this source code is governed by the license that can be
// found in the LICENSE file.

#include "hangmanchar.h"
#include <sstream>
using namespace std;

HangmanChar::HangmanChar(const char c) {
	letter = c;
	guessed = false;
}

char HangmanChar::reveal() { return letter; }

bool HangmanChar::isCorrect(const char p) { 
	if (tolower(p) == letter || toupper(p) == letter) 
		return guessed = true;
	else
		return false;
}

bool HangmanChar::isGuessed() { return guessed; }
		
string HangmanChar::toString() {
    stringstream str;
    
    if (guessed)
        str << letter;        
    else
        str << "_";        
    
    return str.str();
}
 
