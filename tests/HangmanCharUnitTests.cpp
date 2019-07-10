#define CATCH_CONFIG_MAIN
#include "../source/hangmanchar.h"
#include "catch.hpp"
#include <string>


TEST_CASE("HangmanChar is properly instantiated", "[hangmanchar]") {
    
    HangmanChar myChar('h');
    REQUIRE(myChar.isGuessed() == false);
    REQUIRE(myChar.toString() == "_");
    REQUIRE(myChar.reveal() == 'h');
    
}

TEST_CASE("HangmanChar is properly guessed", "[hangmanchar]") {
    
    HangmanChar myChar('a');
    
    REQUIRE(myChar.isCorrect('b') == false);
    REQUIRE(myChar.isGuessed() == false);
    REQUIRE((myChar == 'a') == true);
    REQUIRE(myChar.isGuessed() == true);
    REQUIRE(myChar.toString() == "a");
}
