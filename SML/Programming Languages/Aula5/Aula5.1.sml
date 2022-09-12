print "\n\nLista de inteiros\n";
datatype iList = E | L of int * iList;

print "\nE: \n";
E;

print "\nL: \n";
L;

print "\nCriando l = [1, 2, 3]: \n";
val l = L(1, L(2, L(3, E)));