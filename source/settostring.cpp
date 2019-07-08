// Daniel Kostuj, 2017
// Use of this source code is governed by the license that can be
// found in the LICENSE file.

#include "settostring.h"
#include <sstream>

using namespace std;

string setToString(set<char> s) {
    stringstream str;
    typename set<char>::iterator sIt;
    for (sIt = s.begin(); sIt != s.end(); ++sIt)
            str << " " << *sIt;
    
    return str.str();
}
 
