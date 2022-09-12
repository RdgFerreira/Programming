val a = 5;
a;

fun f x y = x + y;
val f = fn x => fn y => x + y;
fun f (x, y) = x + y;

fun f x = x + 1;
f 1; (* Substituimos x por 1 na expressão acima, então calculamos 1 + 1 = 2 *)

(* Nome: g; Corpo: x + a; Parâmetro: x; Variável kivre: a = 5 *)
fun g x = x + a;

val a = 8;
(* == 6, a continua sendo 5: escopo estático *)
g 1;

(*
    Aspectos importantes de funções:
    -   Nome,
    -   Corpo,
    -   Parâmetro,
    -   Variáveis Livres e seus valores no escopo de declaração.

    Combinação desses 4 aspectos: CLOSURE.
*)

(*
    Closure: (f, x, fBody, fDeclarationEnvironment)

    fun g x = x + a; ====> Closure: ("g", "x", x + a, {a -> 5})

    {a -> 1, b -> 2}
    val h = fn x => x + a - b ====> Closure: ("h", "x", x + a - b, {a -> 1, b -> 2})
    LetFun("h", "x", Prim2("+", Var "x",
                                    Prim2("-", Var "a", Var "b")),
                                                            Call("h", IConst 1) ==> h(1)
    )                            
*)

datatype expr = IConst of int | BConst of bool 
              | Prim2 of string * expr * expr
              | Prim1 of string * expr
              | Ite of expr * expr * expr (* if then else *)
              | Var of string (* Função constante: somente valor *)
              | Let of string * expr * expr
              | LetFun of string * string * expr * expr (* Closure *)
              | Call of string * expr; (* Chamada de função unária: nome e parâmetro *)

let val a = 1; val b = 2 in
    let val h = fn x => x + (a - b) in (h 1) end 
end;
(* Expressão equivalente à acima na ling abstrata *)
Let("a", IConst 1,
    Let("b", IConst 2,
        LetFun("h", "x",
            Prim2("+", Var "x",
                Prim2("-", Var "a", Var "b")),
                    Call("h", IConst 1))));

fun intToBool 1 = true
  | intToBool 0 = false
  | intToBool _ = raise Match;

fun boolToInt true = 1
  | boolToInt false = 0;

exception FreeVar;
fun lookup n ((k, v)::t) = if n = k then v else lookup n t
  | lookup n [] = raise FreeVar;

type 'v state = (string * 'v) list;
datatype value = Int of int 
               | Closure of string * string * expr * value state;



exception EvalError;
fun eval (IConst n) _ = n
  | eval (BConst b) _ = boolToInt b (* Converter valores booleanos para inteiros *)
  | eval (Var v) s = 
    let val v' = (lookup v s) in
                        case v' of
                              (Int i) => i
                            | (Closure(_,_,_,_)) => raise EvalError
    end
  | eval (Let(x, v, e)) s =
    let val v' = Int (eval v s) in 
        eval e ((x, v')::s) 
    end
  | eval (LetFun(f, x, fBody, e)) s = eval e ((f, Closure(f, x, fBody, s))::s)
  | eval (Call(f, e)) s =
    let val f' = lookup f s in
        case f' of
              (Int _) => raise EvalError
            | Closure(f'', x, fBody, fDeclState) =>
              let val e' = Int (eval e s) in
                  eval fBody ((x, e')::fDeclState) (* Escopo de declaração da função: estático *)
              end
    end
  | eval _ _ = raise Match;

let val f = fn x => x in f 1 end; 
val e1 = LetFun("f", "x", Var "x", Call("f", IConst 1));
eval e1 [];

















































