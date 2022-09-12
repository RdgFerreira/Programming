(*
    Nova Linguagem:
    - inteiros: 2; 3; 5;
    - adição: 2 + 3;
    - subtração: 3 - 2;
    - parênteses: 5 + (3 - 2);
    - expressões booleanas: 0 < 1 || 1 > 2;
*)

datatype bexpr = BConst of bool | Not of bexpr | And of bexpr * bexpr | Or of bexpr * bexpr;

fun evalb (BConst n) = n
  | evalb (And(e1, e2)) = (evalb e1) andalso (evalb e2)
  | evalb (Or(e1, e2)) = (evalb e1) orelse (evalb e2)
  | evalb (Not(e1)) = not (evalb e1);

evalb (BConst true);
evalb (And(BConst true, BConst false));

datatype expr = IConst of int | Plus of expr * expr | Minus of expr * expr | Ite of bexpr * expr * expr;

(*Sintaxes abstratas*)
val e1 = IConst 2;
val e2 = Plus (IConst 5, IConst 2);
val e3 = Plus (IConst 3, Minus (IConst 5, IConst 2)); 

(*Interpretador*)
fun eval (IConst n) = n
  | eval (Plus(e1, e2)) = (eval e1) + (eval e2)
  | eval (Minus(e1, e2)) = (eval e1) - (eval e2)
  | eval (Ite(c, e1, e2)) = if (evalb c) then (eval e1) else (eval e2);

  


(*eval (Minus(e1, e2)) = let val res = (eval e1) - (eval e2) in if res < 0 then 0 else res end*)
eval (IConst 1);
eval e1;
eval e2;
eval e3;


eval (Minus(IConst 1, IConst 2));

eval (Ite(BConst true, e2, e3));
eval (Ite(BConst false, e2, e3));





