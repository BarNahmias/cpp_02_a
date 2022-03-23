#include <iostream>
#include <string>
#include <string.h>
#include "Notebook.hpp"
#include "Direction.hpp"
using namespace std;


    namespace ariel{

        void Notebook::write( int page, int row,  int column, Direction d, const std::string &s )
        {
            cout << "writing on notebook" << endl;  
        }

        string Notebook::read( int page, int row,  int column, Direction d,  int length)
        {
            return "reading\n";
        }

        void  Notebook:: erase ( int page, int row,  int column, Direction d,  int length )         
        {
            cout << "erasing on notebook" << endl;
        }

        void Notebook::show( int page)
        {
            cout << "current notebook" << endl;  
        }
    }