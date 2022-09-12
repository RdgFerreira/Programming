print "\n\n";
datatype 'a pList = E | L of 'a * 'a pList;

print "\n";
val l1 = L(1.0, L(2.0, E));
val l2 = L(1, L(2, E));
val l3 = L(l1, E);

print "\nFuncao que retorna o ultimo elemento de pList: \n";
fun last (L(h, E)) = h
  | last (L(h, l)) = last l;
  (*| last E = 0;*) (*Não pode ser E = E, pois força a lista a ser uma lista de listas (coerção de tipo)*)(*E = 0 força a ser tipo int*)

print "\n";
last l1;
last l2;
last l3; (*retorna l1*)