print "\n\n";
datatype 'a pList = E | L of 'a * 'a pList;

print "\n";
val l1 = L(1.0, L(2.0, E));
val l2 = L(1, L(2, E));
val l3 = L(l1, E);

print "\nFuncao que retorna o primeiro elemento de pList: \n";
fun first (L(h, _)) = h; (*retorna head*)

print "\n";
first l1;
first l2;
first l3;