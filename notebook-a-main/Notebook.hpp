
#pragma once
#include <string>
#include <string.h>
#include <iostream>
#include "Direction.hpp"
#include "Notebook.hpp"


namespace ariel{
    class Notebook{
        public:
            static void write( int page, int row,  int column, Direction d, const std:: string &s );
            static std::string read( int page, int row,  int column, Direction d,  int length);
            static void erase ( int page, int row,  int column, Direction d,  int length );            
            static void show( int page);

        };

    }



