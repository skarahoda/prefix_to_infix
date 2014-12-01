#include "scanner.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

token nextToken(char ** value, int * arg_size)
{
	char c;
	int size = 1;
	
	c = getc(stdin);
	while( c == '\n' || c == '\t' || c == ' ' || c == EOF) 
	{
		if( c == EOF )
		{
			return eof;
		}
		c = getc(stdin);
	}
	if( c == '+' || c == '-')
	{
		(*value) = (char *) malloc(sizeof(char)*2);
		(*value)[0] = c;
		(*value)[1] = '\0';
		*arg_size = size;
		return tOP;
	}
	if( c >= '1' && c <='9')
	{
		size++;
		(*value) = (char *) malloc(sizeof(char)*(size));
		(*value)[0] = c;
		(*value)[1] = '\0';
		c = getc(stdin);
		while( c != '\n' && c != '\t' && c != ' ' && c != EOF )
		{
			if( c >= '0' && c <='9')
			{
				size++;
				(*value) = (char *) realloc((*value), sizeof(char)*size);
				(*value)[size-2] = c;
				(*value)[size-1] = '\0';
				c = getc(stdin);
			}
			else
			{
				return invalid;
			}
		}
		*arg_size = size;
		return tNUM;
	}
	if( ( c >= 'a' && c <='z')
		|| ( c >= 'A' && c <='Z'))
	{
		size++;
		(*value) = (char *) malloc(sizeof(char)*(size));
		(*value)[0] = c;
		(*value)[1] = '\0';
		c = getc(stdin);
		while( c != '\n' && c != '\t' && c != ' ' && c != EOF )
		{
			if(( c >= 'a' && c <='z')
				|| ( c >= 'A' && c <='Z')
				|| ( c >= '0' && c <='9'))
			{
				size++;
				(*value) = (char *) realloc((*value), sizeof(char)*size);
				(*value)[size-2] = c;
				(*value)[size-1] = '\0';
				c = getc(stdin);
			}
			else
			{
				return invalid;
			}
		}
		*arg_size = size;
		return tVAR;
	}
	return invalid;
}
