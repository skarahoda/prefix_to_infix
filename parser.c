#include<stdio.h>
#include"scanner.h"

token match(char *** output, int * arg_size)
{
	int size = *arg_size;
	token next;
	int token_size=1;
	char * token_val;
	token matched;
	
	
	next = nextToken(&token_val, &token_size);
	switch (next)
	{
	case tOP:
		// output of "("
		size++;
		(*output) = realloc((*output),sizeof(char*)*size);
		(*output)[size-1] = malloc(sizeof(char)*2);
		sprintf((*output)[size-1],"(");
		
		//E1
		matched = match(output, &size);
		if(matched == invalid || matched == eof)
		{
			return invalid;
		}
		
		//output of operator
		size++;
		(*output) = realloc((*output),sizeof(char*)*size);
		(*output)[size-1] = malloc(sizeof(char)*token_size+2);
		sprintf((*output)[size-1]," %s ",token_val);
		
		//E2
		matched = match(output, &size);
		if(matched == invalid || matched == eof)
		{
			return invalid;
		}
		// output of ")"
		size++;
		(*output) = realloc((*output),sizeof(char*)*size);
		(*output)[size-1] = malloc(sizeof(char)*2);
		sprintf((*output)[size-1],")");
		
		*arg_size = size;
		return expression;
	case tVAR:
	case tNUM:
		size++;
		(*output) = realloc((*output),sizeof(char*)*size);
		(*output)[size-1] = malloc(sizeof(char)*token_size);
		sprintf((*output)[size-1],"%s",token_val);
		
		*arg_size = size;
		return expression;
	case eof:
		return eof;
	case invalid:
	default:
		return invalid;
	}
}

int main()
{
	int size = 0;
	char ** output = NULL;
	char * dummy = NULL;
	int i = 0;
	token t = match(&output, &size);
	switch (t)
	{
	case eof:
		break;
	case expression:
		t = nextToken(&dummy, &i);
		if( t == eof)
		{
			for(i=0; i<size; i++)
			{
				printf("%s",output[i]);
			}
			printf("\n");
			break;
		}
	default:
		printf("Invalid input\n");
	}
	return 0;
}
