#define CATCH_CONFIG_MAIN
#include "../source/hangmanchar.h"
#include "../source/hangmanvector.h"
#include "catch.hpp"

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

TEST_CASE("HangmanVector is properly instantiated", "[hangmanvector]") {
    
    HangmanVector vec("test");
    REQUIRE(vec.isGuessed() == false);
    REQUIRE(vec.toString() == "____");
    REQUIRE(vec.reveal() == "test");
}

TEST_CASE("HangmanVector is properly instantiated with only English letters", "[hangmanvector]") {
    
    HangmanVector vec("D`a^niö'l");
    REQUIRE(vec.isGuessed() == false);
    REQUIRE(vec.toString() == "_____");
    REQUIRE(vec.reveal() == "Danil");
}

TEST_CASE("HangmanVector is properly guessed", "[hangmanvector]") {
    
    HangmanVector vec("test");
    REQUIRE(vec.isGuessed() == false);
    REQUIRE(vec.toString() == "____");
    REQUIRE(vec.wordContains('b') == false);
    REQUIRE(vec.isGuessed() == false);
    REQUIRE(vec.toString() == "____");
    REQUIRE(vec.wordContains('t') == true);
    REQUIRE(vec.isGuessed() == false);
    REQUIRE(vec.toString() == "t__t");
    REQUIRE(vec.wordContains('t') == true);
    REQUIRE(vec.wordContains('e') == true);
    REQUIRE(vec.wordContains('s') == true);
    REQUIRE(vec.isGuessed() == true);
    REQUIRE(vec.toString() == "test");
}

