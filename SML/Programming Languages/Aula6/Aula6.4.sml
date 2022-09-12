(*
    Maneira "raiz" de declarar funções: f2 nomeia fn,
    um construtor de valores funcionais, argumento x => definição (-x)
    vantagem: criar funções sem dá-las nome (funções anônimas)
*)
val f2 = fn x => ~x;

f2;
f2 4;
f2 ~4;

(fn x => ~x) 5; (*função anônima*)
fun myPlus x1 x2 = x1 + x2; (*função de ordem superior*)
(*
    equivalente, sem usar tuplas, 
    toma x1 que produz um resultado funcional que toma x2 que toma x1 + x2
*)
val myPlus' = fn x1 => (fn x2 => (x1 + x2));

myPlus' 4 5; 
(myPlus' 4) 5; (*equivalente a acima*)
myPlus' 4; (*leva a uma fn: int -> int*)

val myPlus4 = (myPlus' 4); (*qualquer int somado a 4*)(*furrificação*)

myPlus4 7;

fun foo x1 x2 x3 x4 = [x1,x2,x3,x4];

foo 1 2 3 4;
(*
    equivalente a acima, funções são sempre unárias,
    elementos da tupla de parâmetros aplicados sucessivamente como em myPlus'
*)
((((foo 1) 2) 3) 4);