// Lexical Analyzer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

/* Global declarations */
int charClass;
string lexeme;
char nextChar;
int token;
int nextToken;
ifstream in_fp;







/* Function declarations */
void addChar();
void getChar();
void getNonBlank();
int lex();
int lookup(char ch);

/* Character classes */
#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99

/* Token codes */
#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20






#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26

/* lookup - a function to lookup operators and parentheses */
int lookup(char ch) {
    switch (ch) {
    case '(':
        addChar(); nextToken = LEFT_PAREN; break;
    case ')':
        addChar(); nextToken = RIGHT_PAREN; break;
    case '+':
        addChar(); nextToken = ADD_OP; break;






    case '-':
        addChar(); nextToken = SUB_OP; break;
    case '*':
        addChar(); nextToken = MULT_OP; break;
    case '/':
        addChar(); nextToken = DIV_OP; break;
    default:
        addChar(); nextToken = EOF; break;
    }
    return nextToken;
}

/* addChar - a function to add nextChar to lexeme */
void addChar() {
    lexeme += nextChar;
}





/* getChar - a function to get the next character and determine its class */
void getChar() {
    if (cin.get(nextChar)) {
        if (isalpha(nextChar))
            charClass = LETTER;
        else if (isdigit(nextChar))
            charClass = DIGIT;
        else
            charClass = UNKNOWN;
    }
    else {
        charClass = EOF;
    }
}

/* getNonBlank - a function to skip whitespace */






void getNonBlank() {
    while (isspace(nextChar))
        getChar();
}

/* lex - a lexical analyzer */
int lex() {
    lexeme = "";
    getNonBlank();
    switch (charClass) {
    case LETTER:
        addChar();
        getChar();
        while (charClass == LETTER || charClass == DIGIT) {
            addChar();
            getChar();






        }
        nextToken = IDENT;
        break;
    case DIGIT:
        addChar();
        getChar();
        while (charClass == DIGIT) {
            addChar();
            getChar();
        }
        nextToken = INT_LIT;
        break;
    case UNKNOWN:
        lookup(nextChar);
        getChar();
        break;






    case EOF:
        nextToken = EOF;
        lexeme = "EOF";
        break;
    }
    cout << "Next token is: " << nextToken << ", Next lexeme is " << lexeme << endl;
    return nextToken;
}

/* Main driver */
int main() {
    cout << "Enter an expression (CTRL+D to end input):" << endl;
    getChar();
    do {






        lex();
    } while (nextToken != EOF);
    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
