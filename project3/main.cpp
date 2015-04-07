//
//  main.cpp
//  project3
//
//  Created by Mina Morcos on 3/26/15.
//  Copyright (c) 2015 Mina Morcos. All rights reserved.
//

#include <fstream>
#include <map>
#include "p2lex.h"

//Parse tree is a binary tree
    //list of statements represented by PTree statement list
    //left child is a statement: right child is a statement list
//read token, if print get expr & ;
//if set see if id then expr & ; if not then not stmt & error
//id, int, or " "
//traverse tree and parse

class PTree {
    PTree *left;
    PTree *right;
    
public:
    PTree(PTree *left, PTree *right = 0) {
        this->left = left;
        this->right = right;
    }
    
    
};

class PTreeStmtList : public PTree { //constructs itself by constructing its parents
public:
    PTreeStmtList(PTree *s1, PTree *s2 = 0) : PTree(s1, s2) {}
};
class PTreePrint: public PTree {};
class PTreeSet: public PTree {};
class PTreePlus: public PTree {};
class PTreeMinus: public PTree{}; 

//function for each PTree
//first 2 done for us
// the comments above each are the definition for each function
extern PTree *Program(istream *br);
extern PTree *StmtList(istream *br);
extern PTree *Stmt(istream *br);
extern PTree *Expr(istream *br);
extern PTree *Term(istream *br);
extern PTree *Primary(istream *br);

// Program ::= StmtList
PTree *Program(istream *br)
{
    return StmtList(br);
}

// StmtList ::= Stmt | Stmt StmtList
PTree *StmtList(istream *br)
{
    PTree *stmt;
    
    stmt = Stmt(br); //find statement
    
    if( stmt ) //if it's there return a statement list
        return new PTreeStmtList( stmt, StmtList(br) );
    return 0;
}

PTree *Stmt(istream *br)
{
    PTree * expr;
    expr = Expr (br);
    if ( expr)
    {
    //    string::find(ID);
    }
    
    return 0;
}

PTree *Expr(istream *br)
{
    return 0;
}

PTree *Term(istream *br)
{
    return 0;
}

PTree *Primary(istream *br)
{
    return 0;
}


void
usage(char *progname, string msg)
{
    cerr << "Error: " << msg << endl;
    cerr << "Usage is: " << progname << " [filename]" << endl;
    cerr << " specifying filename reads from that file; no filename reads standard input" << endl;
}


int
main(int argc, char *argv[])
{
    
    //bool debug = false; //uncomment this later
    
    istream *br;
    ifstream infile;
    
    if( argc == 1 )
        br = &cin;
    else if( argc == 2 ) {
        infile.open(argv[1]);
        if( infile.is_open() )
            br = &infile;
        else {
            usage(argv[0], "Cannot open " + string(argv[1]));
            return 1;
        }
    }
    else {
        usage(argv[0], "More than one file name was given");
        return 1;
    }
    return 0;
}
