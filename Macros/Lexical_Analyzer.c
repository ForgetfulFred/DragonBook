token nexttoken()
{	while(1) {
		switch (state) {
		case 0:	c = nextchar();
			/* c is lookahead character */
			if (c==blank || c==tab || c==newline) {
				state = 0;
				lexeme_beginning++;
					/* advance beginning of lexeme */
			}
			else if (c == '<') state = 1;
			else if (c == '=') state = 5;
			else if (c == '>') state = 6;
			else state = fail();
			break;
			.../* cases 1-8 here */
		case 9:	c = nextchar();
			if (isletter(c)) state = 10;
			else state = fail();
			break;
		case 10:	c = nextchar();
			if (isletter(c)) state = 10;
			else if (isdigit(c)) state = 10;
			else state = 11;
			break;
		case 11:	retract(1); install_id();
			return ( gettoken() );
			.../* cases 12-24 here */
		case 25:	c = nextchar();
			if (isdiget(c)) state = 26;
			else state = fail();
			break;
		case 26:	c = nextchar();
			if (isdigit(c)) state = 26;
			else state = 27;
			break;
		case 27:	retract(1); install_num();
			return ( NUM );
		}
	}
}