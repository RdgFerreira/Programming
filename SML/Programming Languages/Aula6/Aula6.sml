(*(*Funções de ordem superior(>1): funções que manipulam funções (tanto no input quanto output)*)
f0 : A; (*tipo atômico: não é construído a partir de outros tipos*)
f1 : A1 x ... x An -> A; (*1a ordem*)(*tuplas*)
f2 : (A1 -> A2) x A3 x ... x An -> A (*2a ordem: envolvem tipos funcionais: retornam uma função*)
f3 : A1 x ... x An -> (A -> 'A); (*2a ordem*)*)

val a = 10; (*a é função constante/atômico/valor funcional constante/não aplicável (não toma argumentos)*)
fun f x = x + a; (*função int->int 1a ordem*)
val h = f; (*1a ordem*)(*h tem valor funcional: 
cidadãos de 1a classe: podem ser feitas atribuições dessa forma, podem receber funções como argumentos,
podem retornar funções*)
f 5;
h 5;

fun g x = 2 * x;
val p = (f, g);
val l = [f, g]; (*tipos homogêneos em listas*)
(#1 p) 5; (*acessa o primeiro elemento da tupla p: função f: retorna 5 + 10 = 15*)
(#2 p) 5;

fun app (f, x) = f x; (*ordem superior: f e x qualquer coisa, dunção polimórifica que possui duas variáveis*)
app ((hd l), 5); (*acessa a cabeça da lista l: funçãao f: retorna 5 + 10 = 15*)
app ((hd (tl l)), 5);

val f2 = fn x => ~x; (*Maneira "raiz" de declarar funções: f2 nomeia fn,
um construtor de valores funcionais, argumento x => definição (-x)
vantagem: criar funções sem dá-las nome (funções anônimas)*)
f2;
f2 4;
f2 ~4;
(fn x => ~x) 5; (*função anônima*)

fun myPlus x1 x2 = x1 + x2; (*função de ordem superior*)
val myPlus' = fn x1 => (fn x2 => (x1 + x2)); (*equivalente, sem usar tuplas, 
toma x1 que produz um resultado funcional que toma x2 que toma x1 + x2*)
myPlus' 4 5;
(myPlus' 4) 5; (*equivalente a acima*)
myPlus' 4;

val myPlus4 = (myPlus' 4); (*qualquer int somado a 4*)(*furrificação*)
myPlus4 7;

fun foo x1 x2 x3 x4 = [x1,x2,x3,x4];
foo 1 2 3 4;
((((foo 1) 2) 3) 4); (*equivalente a acima, funções são sempre unárias, elementos da tupla de parâmetros aplicados sucessivamente como em myPlus'*)

(*Combinadores: funções que combinam funções*)
(*f e g valores funcionais e x um valor*)
fun compose f g x = f (g x); (*composição básica de funções*)

compose f g 5; (*20*)
(compose hd tl l) 5; (*hd tl l pega o segundo eemento de l: função g: aplicada a 5 -> 5*2 = 10     compose hd tl l 5*)
(hd o tl) l 5; (*o operador de composição*)
(op o);

fun mymap _ [] = []
|   mymap f (h::t) = (f h) :: (mymap f t);
map; (*equivalente*)

map ~ [1,2,3,4]; (*aplicar uma operação a uma lista: [~1,~2,~3,~4]*)
map (fn x => 2 * x) [1,2,3,4];
mymap (fn x => 7 * x) [1,2,3,4];

val a = 10;
fun f x = x + a;
fun g x = 2 * x;
val l = [1,2,3,4];
map (fn x => (f o g) x) l; (*g multiplica por 2 e f soma 10 logo após a todos os elementos da lista*)

(*map (fn x => let val h = ((hd l) o (hd (tl l))) in h x end) [1,2,3,4];*)

(*fold: percorrer a lista, a cada iteração aplica a função especificada lembrando do valor calculado anteriormente*)
(*foldl: fold a esquerda, foldr: fold a direita*)
foldl;
foldr;
foldl (op +) 0 [1,2,3,4]; (*soma todos os valores da lista com 0: 10*)
foldr (op +) 1 [1,2,3,4];

foldl (op ^) "" ["a", "b", "c"]; (*cba*)
foldr (op ^) "" ["a", "b", "c"]; (*abc*)

(*
    4 + (3 + (2 + (1 + 0)))

    foldl + 0       [1,2,3,4]
    foldl + (1 + 0) [2,3,4] (foldl + (hd + resultado acumulado) tl)
    foldl + (2 + 1) [3,4]
    foldl + (3 + 3) [4]
    foldl + (4 + 6) []
    10

    foldr ^ ""        [a, b, c]
    foldr ^ (c ^ "")  [a, b]
    foldr ^ (b ^ c)   [a]
    foldr ^ (a ^ bc)  []
    abc

    foldl ^ ""        [a, b, c]
    foldl ^ (a ^ "")  [b, c]
    foldl ^ (b ^ a)   [a]
    foldl ^ (c ^ ba)  []
    cba
*)

fun myfoldl _ c [] = c
|   myfoldl f c (h::t) = myfoldl f (f (h, c)) t;
myfoldl (op ^) "" ["a", "b", "c"];

fun myfoldr _ c [] = c
|   myfoldr f c (h::t) = f (h, myfoldr f c t);

fun filter _ [] = []
| filter p (h::t) = if p h then h::(filter p t) else filter p t; (*fltro de elementos de uma lista dada uma condição/predicado*)

filter (fn x => x > 1) [1,2,3,4];


















































































