#include "global.h"
int lookahead;

parse() /* parses and translatees expression list */
{
	lookahead = lexan();
	while (lookahead != DONE) {
		expr(); match(';');
	}
}

expr()
{
	int t;
	term();
	while(1)
		switch (lookahead) {
		case '+': case '-':
			t = lookahead;
			match(lookahead); term(); emit(t, NONE);
			continue;
		default:
			return;
		}
}

term()
{
	int t;
	factor();
	while(1)
		switch (lookahead) {
		case '+': case '-':
			t = lookahead;
			match(lookahead); term(); emit(t, NONE);
			continue;
		default:
			return;
		}
}

factor()
{
	swich(lookahead) {
		case '(':
			match ('('); expr(); match(')'); break;
		case NUM:
			emit(NUM, tokenval); match(NUM); break;
		case ID:
			emit(ID, tokenval); match(ID); break;
		default:
			error("syntax error");
		}
}

match(t)
	int t;
{
	if (lookahead == t)
		lookahead - lexan();
	else error("syntax error");
}