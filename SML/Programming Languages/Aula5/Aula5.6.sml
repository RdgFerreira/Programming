print "\n\n";
datatype 'a pList = E | L of 'a * 'a pList;

val l1 = L(1.0, L(2.0, E));
val l2 = L(1, L(2, E));
val l3 = L(l1, E);

print "\nFuncao que retorna o maior elemento da litsa: \n";
fun maxAux n E = n (*n:real define lista de reais como parâmetro*)
  | maxAux n (L(h, t)) = maxAux (if h > n then h else n) t; (*operação > sobrecarregada pra int,real,char, mas não para todos*)(*escolhe-se int pelo alg de inferência de tipos*)
fun max (L(h, t)) = maxAux h t;

print "\nmax l2: \n";
max l2;
(*max l1, l3: erro*)

print "\nFuncao que retorna true caso encontre algum elemento da litsa e false caso contrario: \n";
fun find n E = false
  | find n (L(h, t)) = (n = h) orelse (find n t); (*parametro de entrada: qualquer tipo que abarca o operador de igualdade, parâmetro de aída: bool*)
(*aspas duplas denotam tipos que abarcam igualdade (excluem tipos funcionais e reais)*)

print "\nfind 1 l2: \n";
find 1 l2;
val l4 = L(l2, E);

print "\nfind l2 l4: \n";
find l2 l4;
(*find 1.0 l1; -> erro, igualdade n definida pra reais*)