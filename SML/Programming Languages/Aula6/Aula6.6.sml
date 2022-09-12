(*
    fold: percorrer a lista, a cada iteração aplica a função especificada 
    lembrando do valor calculado anteriormente
*)
(*
    foldl: fold a esquerda, foldr: fold a direita
*)
foldl;
foldr;

foldl (op +) 0 [1,2,3,4]; (*soma todos os valores da lista com 0: 10*)
foldr (op -) 1 [1,2,3,4]; (* (4-1) = 3, (3-3) = 0, (2-0) = 2, (1-2) = ~1*)

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
  | myfoldl f c (h::t) = myfoldl f (f (h, c)) t;

myfoldl (op ^) "" ["a", "b", "c"]; (*cba*)

fun myfoldr _ c [] = c
  | myfoldr f c (h::t) = f (h, myfoldr f c t);

myfoldr (op ^) "" ["a", "b", "c"]; (*abc*)

(*
    fltro de elementos de uma lista dada uma condição/predicado
*)
fun filter _ [] = []
  | filter p (h::t) = if p h then h::(filter p t) else filter p t;
filter;

filter (fn x => x > 1 andalso x < 4) [1,2,3,4];