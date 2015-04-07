//
//  p2lex.h
//  project3
//
//  Created by Mina Morcos on 3/26/15.
//  Copyright (c) 2015 Mina Morcos. All rights reserved.
//

// header file for program 2 (and beyond)
// lexical analyzer

#include <iostream>
#include <string>
using namespace std;

enum Token {
    ID,		// an identifier
    
    INT,		// an integer constant
    STRING,		// a string enclosed in ""
    
    PLUS,		// the + operator
    MINUS,		// the - operator
    STAR,		// the * operator
    SLASH,		// the / operator
    
    SET,		// the set keyword
    PRINT,		// the print keyword
    
    SC,		// the semicolon
    
    DONE,		// end of file or some error condition was reached
};

extern Token getToken(istream *br, string& lexeme);
extern bool pushbackToken(Token t, string lexeme);
