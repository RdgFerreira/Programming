(*não podemos sobrecarrgar operadores nós mesmos por design de SML*)
(*criar novos tipos a partir de tipos existentes: type*)

print "\n\nCriacao de novos tipos a partir de tipos existentes: \n";
type T1 = int * real;
type T2 = int * real;

print "\nPrototipo de sobrecarga de tipos: \n";
fun foo (s1: T1) (s2: T2) = (#1 s1, #2 s2); (*tipo de saída inferido: int * real*)

print "\n";
val x1: T1 = (1, 3.0);
val x2: T2 = (2, 4.0);

print "\nfoo x1 x2: \n";
foo x1 x2;
print "\nfoo x2 x1: \n";
foo x2 x1; (*funcionam pq os tipos T0 e T1 casam/são compatíveis entre si e com a entrada de foo*)