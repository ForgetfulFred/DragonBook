int state = 0, start = 0;
int lexical_value;
	/* to "return" second component of token */

int fail()
{
	forward = token_beginning;
	switch (start) {
		case 0:	start = 9; break;
		case 9: start = 12; break;
		case 12: start = 20; break;
		case 20: start = 25; break;
		case 25: recover(); break;
		default: /* compiler error */
	}
	return start;
}