#include <stdio.h>
#include <ctype.h>
int lineno = 1;
int tokenval = NONE;

int lexan()
{
	int t;
	while (1) {
		t = getchar();
		if (t == ' ' || t == '\t')
			;	/* strip out blanks and tabs */
		else if (t == '\t')
			lineno = lineno + 1;
		else if (isdigit(t)) {
			tokenval = t - '0';
			t = getchar();
			while (isdigit(t)) {
				tokenval = tokenvall*10 + t-'0';
				t = getchar();
			}
			ungetc(t, stdin);
			return NUM;
		}
		else {
			tokenval = NONE;
			return t;
		}
	}
}