val a = 5;
fun double x = 2 * x;
fun square x = x * x;
square a;
double a;

let val b = 5 
in 
    b + 3 
end;
(*b;*) (*b fora do escopo, ele só existe dentro do let*)

(**************)
let val a = 5 in
    let val square = fn x => x * x in
        let val double = fn x => 2 * x in
            let val b = 5 in
                b + (square (double a))
            end
        end
    end
end;
(*Cada let abre um escopo, cada end fecha um escopo*)
let val a = 5 in
    let val square = fn x => x * x in
        let val double = fn x => 2 * x in
            let val b = 5 in
                (let val a = 2 in
                    b + (square (double a)) (*a = 2*)
                end) + (square (double a)) (*a = 5*)
            end
        end
    end
end;

fun f x = x + let val f = fn y => y + x in f (x + 1) end; (*5 + (6 + 1)*)
f 5;
fun f x = x + let val f = fn x => x + x in f (x + 1) end;
f 5;




(************************)
(*
    1 + 2
    Prim2("+", Iconst 1, Iconst 2)
*)
datatype expr = IConst of int
              | Prim2 of string * expr * expr
              | Var of string
              | Let of string * expr * expr;

(*let val a = 17 val x = 2 in z + x end;*)
val e = Let("z", IConst 17,
            Let("x", IConst 2, Prim2("+", Var "z", Var "x"))); (*Acessando variável a*)

exception FreeVar;
fun lookup n ((k, v)::t) = if n = k then v else lookup n t
  | lookup _ [] = raise FreeVar;

fun eval (IConst n) _ = n
  | eval (Var n) s = eval (lookup n s) s
  | eval (Prim2 (f, e1, e2)) s =
    let val v1 = (eval e1 s); val v2 = (eval e2 s) 
    in 
    case f of 
      ("+") => v1 + v2
    | ("-") => v1 - v2
    | ("*") => v1 * v2
    | ("/") => v1 div v2
    | _ => raise Match
    end
  | eval (Let(x, v, e)) s = eval e ((x, IConst (eval v s))::s);  (*Escopo estático*)
                          (*eval e ((x, v)::s);*) (*Escopo dinâmico: variáveis avaliadas no escopo em que ocorrem, não no escopo que são declaradas (escopo estático, SML)*)

(*exemplos: preencher e testar com eval e []*)
eval e [];
val e1 = Let("a", IConst 20,
             Prim2("*", Var "a", IConst 20));
eval e1 [];
val e2 = Let("a", IConst 24,
             Prim2("/", Var "a", Var "z"));
eval e2 [("z", IConst 3)];


(********************)
val e3 = Let("z", IConst 17,
             Prim2("+", Var "z",
                   Prim2("+", Var "x", IConst 2)));
(*eval e3 [];* exceção FreeVar x (variavel livre)*)


fun isIn x [] = false
  | isIn x (h::t) = h = x orelse isIn x t;

fun union s1 [] = s1
  | union s1 (h::t) = if isIn h s1 then union s1 t else union (h::s1) t;

fun setminus [] s2 = [] 
  | setminus s1 [] = s1
  | setminus (h::t) s2 = if isIn h s2 then setminus t s2 else h::(setminus t s2);

fun freeVars (IConst _) = []
  | freeVars (Var v) = [v]
  | freeVars (Prim2(_, e1, e2)) = union (freeVars e1) (freeVars e2)
  | freeVars (Let(x, v, e)) = setminus (freeVars e) (setminus (freeVars e) [x]);


fun closed e = freeVars e = [];

exception NoNCLosed;
fun run e = if closed e then eval e [] else raise NoNCLosed;

(* run e3; -> variável livre detectada *)















































