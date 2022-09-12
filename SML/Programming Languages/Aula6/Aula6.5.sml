(*Combinadores: funções que combinam funções*)
(*f e g valores funcionais e x um valor*)
fun compose f g x = f (g x); (*composição básica de funções*)

val a = 10;
fun f x = x + a;
fun g x = 2 * x;
val l = [f, g];
compose f g 5; (*20*)

(*
    hd tl l pega o segundo elemento de l: função g: 
    aplicada a 5 -> 5*2 = 10     
    compose hd tl l 5
*)
(compose hd tl l) 5;
(hd o tl) l 5; (*o operador de composição*)

(op o);

fun mymap _ [] = []
|   mymap f (h::t) = (f h) :: (mymap f t);
map; (*equivalente em sml*)

map ~ [1,2,3,4]; (*aplicar uma operação a uma lista: [~1,~2,~3,~4]*)
map (fn x => 2 * x) [1,2,3,4];
mymap (fn x => 7 * x) [1,2,3,4];

(*
    g multiplica por 2 e f soma 10 logo após a todos os elementos da lista
*)

map (fn x => (f o g) x) [1,2,3,4];

(*val l = [f, g];*)
(*
    equivalente a acima
*)
map (fn x => let val h = ((hd l) o (hd (tl l))) in h x end) [1,2,3,4];
(*                   h = ((f) o (g))               (f o g) x, onde x = x1,x2,x3,x4            *)