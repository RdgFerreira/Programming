(*
    Nova Linguagem:
    - inteiros: 2; 3; 5;
    - adição: 2 + 3;
    - subtração: 3 - 2;
    - parênteses: 5 + (3 - 2);
    - expressões booleanas: 0 < 1 || 1 > 2;
    - variáveis inteiras: x + 2
*)

datatype bexpr = BConst of bool | Not of bexpr 
                 | And of bexpr * bexpr 
                 | Or of bexpr * bexpr;

fun evalb (BConst n) = n
  | evalb (And(e1, e2)) = (evalb e1) andalso (evalb e2)
  | evalb (Or(e1, e2)) = (evalb e1) orelse (evalb e2)
  | evalb (Not(e1)) = not (evalb e1);

datatype expr = IConst of int | Plus of expr * expr 
                | Minus of expr * expr 
                | Ite of bexpr * expr * expr
                | Var of string; (*Construtor que toma strings, para referenciar variáveis na avaliação*)

(*Sintaxes abstratas*)
val e1 = IConst 2;
val e2 = Plus (IConst 5, IConst 2);
val e3 = Plus (IConst 3, Minus (IConst 5, IConst 2));


type memory = (string * int) list;

fun lookup x ((key, value)::t) = if x = key then value else lookup x t
  | lookup x [] = raise Match;

(*Dicionário de Pares de associação (Memória) *)
val state : memory = [("x", 6)]; (*Lista de tuplas de string * int*)

(*Interpretador*)
fun eval (IConst n) _ = n
  | eval (Plus(e1, e2)) state = (eval e1 state) + (eval e2 state)
  | eval (Minus(e1, e2)) state = (eval e1 state) - (eval e2 state)
  | eval (Ite(c, e1, e2)) state = eval (if (evalb c) then e1 else e2) state
  | eval (Var n) state = lookup n state;

val e = Plus (Var "x", IConst 2); (*val x = 2*)
eval e state; (*x + 2, mas, pela memória, x = 6, logo, x + 2 = 8*)
(*eval (Plus(Var "y", IConst 2)) state; (*erro: y não está em state*)*)
(*Expressão fechada: expressão sem variáveis livres (não vinculadas a valores)*)



(******************
    FINITE SETS
*******************)

val l = [1,2,4,5];

fun isIn x [] = false
  | isIn x (h::t) = h = x orelse isIn x t;

isIn 5 l;
isIn 7 l;

fun union s1 [] = s1
  | union s1 (h::t) = if isIn h s1 then union s1 t else union (h::s1) t;

union l l;
union l [1,9];

fun setminus [] s2 = [] (*[] minus s2*)
  | setminus s1 [] = s1 (*s1 minus []*)
  | setminus (h::t) s2 = if isIn h s2 then setminus t s2 else h::(setminus t s2);

setminus l [1,9];
setminus l [];
setminus [] l;


(******************
    FREE VARIABLES
*******************)

fun isInMemory n (s : memory) = 
    case s of
        [] => false
    |   ((k, _)::t) => n = k orelse isInMemory n t;


(*retorna as variáveis que não têm valores associados*)
fun freeVars (e : expr) (s : memory) : string list = 
  case e of 
      (Var n) => if not (isInMemory n s) then [n] else []
    | (IConst _) => []
    | (Plus(e1, e2)) => union (freeVars e1 s) (freeVars e2 s)
    | (Minus(e1, e2)) => union (freeVars e1 s) (freeVars e2 s)
    | (Ite(_, e1, e2)) => union (freeVars e1 s) (freeVars e2 s);



freeVars (e) (state);

fun isClosed e s = (freeVars e s) = [];

exception NoNCLosed;

fun run (e : expr) (s : memory) : int =
    if isClosed e s then eval e s else raise NoNCLosed;
































