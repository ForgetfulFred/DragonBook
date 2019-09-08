#include "global.h"
error(m) /* generates all error messages */
	char *m;
{
	fprint(stderr, "line %d: %s\n", lineno, m);
	exit(1); /* unsuccessful termination */
}