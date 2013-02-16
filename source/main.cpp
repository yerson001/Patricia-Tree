/************************************************************************************************************/
/*
*     Name                : Andreas Basurto
*     Date                : 04/22/12
*     File                : main.cpp
*     Program Description : http://www.ecst.csuchico.edu/~melody/courses/Fall2007CSCI311/Patricia_tree.htm
*/
/************************************************************************************************************/

#include <iostream>
#include <fstream>  // for ifstream and ofstream
#include <cctype>   // for toupper
using namespace std;

#include "Patricia_Tree.h"

int main(int argc, char *argv[])
{
    if (argc == 3) // if proper number of arguments 
    {
        ifstream infile(argv[1], ios::in);

        if (!infile)
        {
            cerr << "Error: could not open input file <" << argv[1] << ">" << endl;
            return 1; 
        }

        ofstream ofile(argv[2], ios::out);

        if (!ofile)
        {
            cerr << "Error: could not open output file <" << argv[2] << ">" << endl;
            return 1; 
        }

        char command = 'Z';
        int  value   = 0;
        int  junk    = 0;

        // instantiate Patricia tree structure
        Patricia_Tree pat_tree(junk);

        while (infile >> command)
        {   
            // if commands are lowercase; turn to uppercase
            // I = Insert value 
            // S = Search for value
            // D = Delete value
            // P = Print values in a modified inorder traversal
            command = toupper(static_cast<char>(command));
            
            if (command == 'I')
            {
                infile >> value; // read in value to insert
                if (value > 9999)
                {
                    cerr << endl << "Value {" << value << "} must be <= 9999. Ending program!" << endl << endl;
                    ofile << endl << "Value {" << value << "} must be <= 9999. Ending program!" << endl << endl;
                    return 1;
                }
                ofile << command << " " << value << endl;
                cout << command << " " << value << endl;
                pat_tree.insert(value, ofile);
            }

            if (command == 'D')
            {
                infile >> value; // read in value to delete
                if (value > 9999)
                {
                    cerr << endl << "Value {" << value << "} must be <= 9999. Ending program!" << endl << endl;
                    ofile << endl << "Value {" << value << "} must be <= 9999. Ending program!" << endl << endl;
                    return 1;
                }
                ofile << command << " " << value << endl;
                cout << command << " " << value << endl;
                pat_tree.remove(value, ofile);
            }

            if (command == 'S')
            {
                infile >> value; // read in value to search for
                if (value > 9999)
                {
                    cerr << endl << "Value {" << value << "} must be <= 9999. Ending program!" << endl << endl;
                    ofile << endl << "Value {" << value << "} must be <= 9999. Ending program!" << endl << endl;
                    return 1;
                }
                ofile << command << " " << value << endl;
                cout << command << " " << value << endl;
                pat_tree.lookup(value, ofile);
            }

            if (command == 'P')
            {
                ofile << command << endl;
                cout << command << endl;
                pat_tree.inOrderPrint(ofile);
            }
        }
    }   
    return 0;
}