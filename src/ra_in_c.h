#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// parser
typedef enum {
    TK_RESERVED, // Symbol
    TK_NUM,      // Integer
    TK_EOF,      // End of File
} TokenKind;

// Token struct
typedef struct Token Token;
struct Token {
    TokenKind kind; // Token type
    Token *next;    // next input token
    int val;        // value when TK_NUM
    char *str;      // mark text
};
extern Token *token;
extern char *user_input;
void error(char *fmt, ...);
void error_at(char *loc, char *fmt, ...);
bool consume(char op);
void expect(char op);
int expect_number(void);
bool at_eof();
Token *new_token(TokenKind kind, Token *cur, char *str);
Token *tokenize(char *p);