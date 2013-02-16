/************************************************************************************************************/
/*
*     Name                : Andreas Basurto
*     Date                : 04/22/12
*     File                : Patricia_Tree.h
*     Program Description : http://www.ecst.csuchico.edu/~melody/courses/Fall2007CSCI311/Patricia_tree.htm
*/
/************************************************************************************************************/

#ifndef PATRICIA_TREE_H
#define PATRICIA_TREE_H

#include <iostream>
#include <fstream>  // for ifstream and ofstream
using namespace std;

class Patricia_Tree
{
    public:
        Patricia_Tree(int junk);                        // constructor (ONE argument)
        
        bool insert(int value, ostream &ofile);         // insert function to be called from main
        bool lookup(int value, ostream &ofile);         // search function to be called from main       
        bool remove(int value, ostream &ofile);         // remove/delete function to be called from main        
        void inOrderPrint(ostream &ofile);              // print function to be called from main  
        int  getNodeCount() {return m_node_count;}      // function to determine total nodes in tree

    private:
        class Node // Patricia Trie's node class
        {
            public:
                Node()          // constructor (FOUR arguments)
                    {m_left = NULL; 
                    m_right = NULL; 
                    m_bit_check = 0;
                    m_value = 0;}

            Node *m_left;       // zero_ptr
            Node *m_right;      // one_ptr
            int m_bit_check;    // bit_check
            int m_value;        // variable to store integer value
        };
        
        Node *m_root;           // the root pointer to begin with
        Node *m_dummy;          // dummy node
        int m_node_count;       // count of total nodes in tree 

        bool getBitAtPos(int value, int position);                              // function to determine a 0 or 1 at given bit position  
        int  getFirstDiffBitPos(int value1, int value2);                        // function to determine first differing MSB    
        Node *insert(int value, int &returnedBitCheck);                         // first function called by public insert (node count = 0)
        bool insert(Node *root, int value, int &returnedBitCheck);              // second function called by public insert (node count > 1)
        bool lookup(Node *root, int value);                                     // function called by public search
        bool remove(Node *root, int value);                                     // function called by public remove
        void inOrderPrint(Node *root, int previous_bit_check, ostream &ofile);  // function called by public inOrderPrint
        void recursiveDelete(Node *root);                                       // function to be called by destructor
};
#endif

