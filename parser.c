#include<stdio.h>
#include"scanner.h"

void match(token current)
{
	token next;
	char * token_val;
	next = nextToken(&token_val);
	switch (current)
	{
	case expression:
		switch (next)
		{
		case tOP:
			printf("( ");
			match(expression);
			printf(" %s ",token_val);
			match(expression);
			printf(" )");
			return;
		case tVAR:
		case tNUM:
			printf("%s",token_val);
		default:
			return; 
		}
	default:
		return; 
	}
}

int main()
{
	match(expression);
	printf("\n");
	return 0;
}
