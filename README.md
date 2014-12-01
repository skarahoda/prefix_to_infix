prefix_to_infix
===============

A translator from prefix expresion to infix expresion

The grammar of the source code is G where N = {S, E, tVAR, tNUM}, Σ = {+, -, 0-9, a-z, A-Z}, S is the start symbol, and P consists of the following production rules:

S -> E
E -> + E E | - E E | tNUM | tVAR
tNUM -> [1-9] | tNUM[0-9]
tVAR -> [a-zA-Z] | tVAR[a-zA-Z0-9]