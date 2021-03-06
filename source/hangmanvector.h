// Daniel Kostuj, 2017
// Use of this source code is governed by the license that can be
// found in the LICENSE file.

#ifndef HANGMANVECTOR_H
#define HANGMANVECTOR_H

#include "hangmanchar.h"
#include <vector>

class HangmanVector {
    std::vector<HangmanChar> vec;
    
    public:
    HangmanVector(const std::string &word);
    bool isGuessed();    
    bool wordContains(const char &c);
    std::string reveal();
    std::string toString();    
};

#endif
