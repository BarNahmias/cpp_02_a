#include "doctest.h"
#include <iostream>
#include "Notebook.hpp"
#include "Direction.hpp"

#include <string>
#include <algorithm>
using namespace ariel;
using namespace std;





 ariel::Notebook notebook;

// negative page , row or colunm  iput:

TEST_CASE("Bad input") {

    CHECK_THROWS(notebook.write(-9, 5, 2 ,Direction::Vertical, "A snowball effec"));
    CHECK_THROWS(notebook.write( 9, 3, 101,Direction::Vertical , "A perfect storm"));
    CHECK_THROWS(notebook.write( 9, 2, -12 ,Direction::Horizontal, "A storm in a teacup"));
    CHECK_THROWS(notebook.write( -9, -12, 2,Direction::Horizontal , "Actions speak louder than words"));
    CHECK_THROWS(notebook.write( -9, -12, -2 ,Direction::Vertical, "A picture is worth 1000 words"));
    CHECK_THROWS(notebook.write( 3, 42, 2,Direction::Vertical , "Add insult to injury"));

}

// Exception in row length 

TEST_CASE("Bad input") {

    CHECK_THROWS(notebook.write(0, 0, 99 ,Direction::Horizontal, "A bird in the hand is worth two in the bush"));
    CHECK_THROWS(notebook.write( 9, 3, 101,Direction::Horizontal , "Againt the clock"));
    CHECK_THROWS(notebook.write( 9, 2, 95 ,Direction::Horizontal, "All In The Same Boat"));
    CHECK_THROWS(notebook.write( 1, 11, 93,Direction::Horizontal , "Barking up the wrong tree"));
    CHECK_THROWS(notebook.write(99, 99, 0 ,Direction::Horizontal, "But doesn't redeclaring the function defeat the purpose of inheritance? I want a super class to define all the necessary functions that many sub classes declare. I don't want to repeat the decleration again! Also, wouldn't your fix hide the A::test function?"));

}
// Invalid character
 

TEST_CASE("Bad input-") {

    CHECK_THROWS(notebook.write(0, 0, 99 ,Direction::Horizontal, "~"));
    CHECK_THROWS(notebook.write( 9, 3, 33,Direction::Horizontal , "Againt~the clock"));
    CHECK_THROWS(notebook.write( 9, 2, 44 ,Direction::Horizontal, "All In The Same Boat~~"));
}

// not firs time write

TEST_CASE("not firs time write") {

    notebook.write(0, 0, 0 ,Direction::Horizontal, "Actions speak louder than words");
    CHECK_THROWS(notebook.write(0, 0, 0 ,Direction::Horizontal, "Actions speak louder than words"));
    notebook.write(9, 3,33 ,Direction::Horizontal, "Add insult")
    CHECK_THROWS(notebook.write( 9, 3, 33,Direction::Horizontal , "Add insult to injury"));



// Position error 


TEST_CASE("Bad input") {
    CHECK_THROWS(notebook.read(-9, 5, 2,Direction::Vertical , 1));
    CHECK_THROWS(notebook.read( 9, 3, 101,Direction::Vertical , 10));
    CHECK_THROWS(notebook.read( 9, 2, -12,Direction::Vertical , 12));
    CHECK_THROWS(notebook.read( -9, -12, 2,Direction::Vertical , 2));
    CHECK_THROWS(notebook.read( -9, -12, -2,Direction::Vertical ,22));
    CHECK_THROWS(notebook.read( -9, -12, -2,Direction::Vertical ,-22));
    CHECK_THROWS(notebook.read(0, 0, 0 ,Direction::Vertical, 19));


}



TEST_CASE("Good input") {
    notebook.write(0, 0, 20 ,Direction::Horizontal, "A bird in the hand is worth two in the bush");
	CHECK(notebook.read(0, 0, 28 ,Direction::Horizontal ,6)=="A bird ");
    notebook.write( 9, 3, 10,Direction::Horizontal , "Againt the clock");
	CHECK(notebook.read(9, 3, 10,Direction::Horizontal ,20)=="Againt the clock_______");
    notebook.write( 1, 11, 33,Direction::Horizontal , "Barking up the wrong tree");
    CHECK(notebook.read(1, 11, 30,Direction::Horizontal, 25)=="___Barking up the wrong t");
    CHECK(notebook.read(0, 1000, 99 ,Direction::Vertical, 22)=="erfcv bgf dsa wer tr q");

}
// Position error 


TEST_CASE("Good ouput") {
    notebook.write( 1, 11, 33,Direction::Vertical , "Barking up the wrong tree");
	CHECK(notebook.read( 1, 11, 33 ,Direction::Vertical, 3) =="Bark");
	CHECK(notebook.read(1, 11, 33 ,Direction::Vertical, 11) =="Barking u___");
}



 

// check input of erase function 


TEST_CASE("Bad input") {
    CHECK_THROWS(notebook.erase(-9, 5, 2,Direction::Vertical , 1));
    CHECK_THROWS(notebook.erase( 9, 3, 101,Direction::Vertical , 0));
    CHECK_THROWS(notebook.erase( -9, -12, 2,Direction::Vertical ,0));
    CHECK_THROWS(notebook.erase( -9, -12, -2,Direction::Vertical ,22));
    CHECK_THROWS(notebook.erase( -9, -12, -2,Direction::Vertical ,-22));


}

TEST_CASE("Good input") {
    notebook.write(0, 0, 20 ,Direction::Horizontal, "A bird in the hand is worth two in the bush");
	notebook.erase(0, 0, 59 ,Direction::Horizontal,4);
    CHECK(notebook.read(0, 0, 20 ,Direction::Horizontal ,43)=="A bird in the hand is worth two in the ~~~~");
    notebook.write( 9, 3, 10,Direction::Horizontal , "Againt the clock");
    notebook.erase(9, 3, 10 ,Direction::Horizontal,4);
	CHECK(notebook.read(9, 3, 10,Direction::Horizontal ,8)=="~~~~nt t");
}

