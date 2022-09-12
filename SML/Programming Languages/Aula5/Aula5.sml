datatype iList = E | L of int * iList;
E;
L;
val l = L(1, L(2, L(3, E)));

datatype 'a pList = E | L of 'a * 'a pList;
val l1 = L(1.0, L(2.0, E));
val l2 = L(1, L(2, E));
val l3 = L(l1, E); (*Lista de listas*)

fun first (L(h, _)) = h; (*retorna head*)

first l1;
first l2;
first l3;

fun rest (L(_, t)) = t;

rest l1;
rest l2;
rest l3;

fun last (L(h, E)) = h
  | last (L(h, l)) = last l;
  (*| last E = 0;*) (*Não pode ser E = E, pois força a lista a ser uma lista de listas (coerção de tipo)*)(*E = 0 força a ser tipo int*)

last l1;
last l2;
last l3; (*retorna l1*)

fun maxAux n E = n (*n:real define lista de reais como parâmetro*)
  | maxAux n (L(h, t)) = maxAux (if h > n then h else n) t; (*operação > sobrecarregada pra int,real,char, mas não para todos*)(*escolhe-se int pelo alg de inferência de tipos*)
fun max (L(h, t)) = maxAux h t;

max l2;
(*max l1, l3: erro*)

fun find n E = false
|   find n (L(h, t)) = n = h orelse find n t; (*parametro de entrada: qualquer tipo que abarca o operador de igualdade, parâmetro de aída: bool*)
(*aspas duplas denotam tipos que abarcam igualdade (excluem tipos funcionais e reais)*)

find 1 l2;
val l4 = L(l2, E);
find l2 l4;
(*find 1.0 l1; -> erro, igualdade n definida pra reais*)

(*não podemos sobrecarrgar operadores nós mesmos por design de SML*)
(*criar novos tipos a partir de tipos existentes: type*)

type T0 = int * real;
type T1 = int * real;

fun foo (s1: T1) (s2: T0) = (#1 s1, #2 s2); (*tipo de saída inferido: int * real*)

val x1: T0 = (1, 3.0);
val x2: T1 = (2, 4.0);

foo x1 x2;
foo x2 x1; (*funcionam pq os tipos T0 e T1 casam/são compatíveis entre si e com a entrada de foo*)








