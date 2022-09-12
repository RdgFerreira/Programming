print "\n\nLista polimorfica\n";
datatype 'a pList = E | L of 'a * 'a pList;

print "\n";
val l1 = L(1.0, L(2.0, E));
val l2 = L(1, L(2, E));

print "\nLista de listas\n";
val l3 = L(l1, E);