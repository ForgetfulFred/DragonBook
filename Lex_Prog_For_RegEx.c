%{
	/* definitions of manifest constants LT LE, EQ, NE, GT, GE, IF, THEN, ELSE,  ID, NUMER, RELOP */
%}

/* regular defiitions */
delim	[ \t\n]
ws	{delim}+
letter	[A-Za-z]
digit	[0-9]
id	{letter}({letter}|{digit})*
number	{digit}+(\.{digit}+)?(E[+\-]?{digit}+)?

%%
{ws}	{/* no action and no return */}
if	{return(IF);}
then	{return(THEN);}
else	{return(ELSE);}
{id}	{yylval = install_id(); return(ID);}
{number}	{yylval = install_num(); return(NUMBER);}
"<"	{yylval = LT; return (RELOP);}
"<="	{yylval = LE; return (RELOP);}
"="	{yylval = EQ; return (RELOP);}
"<>"	{yylval = NE; return (RELOP);}
">"	{yylval = GT; return(RELOP);}
">="	{yylval = GE; return(RELOP);}

%%
install_id() {
	/* procedure to install the lexeme, whose first char is pointed to by yytext and whose length is yyleng, into the symbol table and return a ponter thereto */
}
install_num() {
	/* similar procedure to install a leseme that is a number */
}