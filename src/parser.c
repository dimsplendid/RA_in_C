/* File    : parser.c
 * Dscrpt. : parser of RA_in_C, 
 * Author  : dimsplendid (most copy from https://www.sigbus.info/compilerbook)
 * Date    : 2020/04/17
*/
#include "ra_in_c.h"
// handle error function
// using the same argument with printf
void error(char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
    exit(1);
}
char *user_input;
void error_at(char *loc, char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);

    int pos = loc - user_input;
    fprintf(stderr, "%s\n", user_input);
    fprintf(stderr, "%*s", pos, ""); // print 'pos' spaces
    fprintf(stderr, "^ ");
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
    exit(1);
}
// When next token is expected character, read
// next token and keep going.
// return true, otherwise return false.
Token *token;
bool consume(char op) {
    if (token->kind != TK_RESERVED || token->str[0] != op)
        return false;
    token = token->next;
    return true;
}

// When next token is expected character, read
// next token and keep going.
// Otherwise, warn and exit.
void expect(char op) {
    if (token->kind != TK_RESERVED || token->str[0] != op)
        error("It's not '%c'", op);
    token = token->next;
}

// When next token is number, read and
// keep going. Return the value.
// Otherwise, warn and exit.
int expect_number(void) {
    if (token->kind != TK_NUM)
        error_at(token->str, "Not a number");
    int val = token->val;
    token = token->next;
    return val;
}

bool at_eof() {
    return token->kind == TK_EOF;
}

// Construct a new token and link to cur.
Token *new_token(TokenKind kind, Token *cur, char *str) {
    Token *tok = calloc(1, sizeof(Token));
    tok->kind = kind;
    tok->str = str;
    cur->next = tok;
    return tok;
}

// Parser string p and return token linkage
Token *tokenize(char *p) {
    Token head;
    head.next = NULL;
    Token *cur = &head;

    while (*p) {
        // skip space
        if (isspace(*p)) {
            p++;
            continue;
        }

        if (isdigit(*p)) {
            cur = new_token(TK_NUM, cur, p);
            cur->val = strtol(p, &p, 10);
            continue;
        }

        error("Tokenize fail!");
    }

    new_token(TK_EOF, cur, p);
    return head.next;
}