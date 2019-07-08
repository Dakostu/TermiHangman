// Daniel Kostuj, 2017
// Use of this source code is governed by the license that can be
// found in the LICENSE file.

#include "hangmanchar.h"
using namespace std;

HangmanChar::HangmanChar(const char c) {
	letter = c;
	guessed = false;
}

const char HangmanChar::reveal() { return letter; }

bool HangmanChar::isCorrect(const char &p) { 
    return (tolower(p) == letter || toupper(p) == letter) 
                ? guessed = true : false;
}

bool HangmanChar::isGuessed() { return guessed; }
		
string HangmanChar::toString() {
    return (guessed) ? string(1,letter) : "_";
}
 
