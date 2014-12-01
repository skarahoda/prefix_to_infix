prefix_to_infix
===============

A translator from prefix expresion to infix expresion

The grammar of the source code is G where N = {S, E, tVAR, tNUM, tOP}, Σ = {+, -, 0-9, a-z, A-Z}, S is the start symbol, and P consists of the following production rules:

S -> E
E -> tOP E E | tNUM | tVAR
tNUM -> [1-9] | tNUM[0-9]
tVAR -> [a-zA-Z] | tVAR[a-zA-Z0-9]
tOP -> + | -

Semantic functions associated with the grammar rules is given as follows:

| Production	|		Semantic function			|
|---------------|-------------------------------------------------------|
| S -> E	| S.attr = E.attr					|
| E -> tOP E E	| E.attr = "(" + E1.attr + tOP.attr + E2.attr + ")"	|
| E -> tNUM	| E.attr = tNUM						|
| E -> tVAR	| E.attr = tVAR						|

The translator uses following state machine:

| STATE |  tOP  |   E   | tNUM  | tVAR  |    $    |
|-------|-------|-------|-------|-------|---------|
|   0   |   1   |   2   |   3   |   4   |  error  |
|   1   |   1   |   5   |   3   |   4   |  error  |
|   2   | error | error | error | error | success |
|   3   |   -   |   -   |   -   |   -   |    -    |
|   4   |   -   |   -   |   -   |   -   |    -    |
|   5   |   1   |   6   |   3   |   4   |  error  |
|   6   |   -   |   -   |   -   |   -   |    -    |

State 0:
	S -> ·E
	E -> ·tOP E E
	E -> ·tNUM
	E -> ·tVAR
	
State 1:
	E -> tOP· E E
	E -> ·tOP E E
	E -> ·tNUM
	E -> ·tVAR

State 2:
	S -> E·

State 3:
	E -> tNUM·
	
State 4:
	E -> tVAR·

State 5:
	E -> tOP E·E
	E -> ·tOP E E
	E -> ·tNUM
	E -> ·tVAR
	
State 6:
	E -> tOP E E·
