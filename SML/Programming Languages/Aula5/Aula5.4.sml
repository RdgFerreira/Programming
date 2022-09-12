print "\n\n";
datatype 'a pList = E | L of 'a * 'a pList;

print "\n";
val l1 = L(1.0, L(2.0, E));
val l2 = L(1, L(2, E));
val l3 = L(l1, E);

print "\nFuncao que retorna a cauda de pList: \n";
fun rest (L(_, t)) = t; (*retorna tail*)

print "\n";
rest l1;
rest l2;
rest l3;