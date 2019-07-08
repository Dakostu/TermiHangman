// Daniel Kostuj, 2017
// Use of this source code is governed by the license that can be
// found in the LICENSE file.

#ifndef HANGMANCHAR_H
#define HANGMANCHAR_H

#include <string>

class HangmanChar {
	char letter;
	bool guessed;
	
	public:
    HangmanChar(const char c);
	const char reveal();
	bool isCorrect(const char &p);
    bool isGuessed();
	std::string toString();
    bool operator==(const char &c);
};

#endif
