#ifndef _ACS_DATA_H_
#define _ACS_DATA_H_

typedef enum {tOP=0, tNUM, tVAR, invalid, expression, eof} token;

token nextToken(char ** value);
#endif
