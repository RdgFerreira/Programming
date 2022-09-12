(*
    ordem superior: f e x qualquer coisa, função polimórifica que possui duas variáveis
*)
fun app (f, x) = f x;

val a = 10;
fun f x = x + a;
fun g x = 2 * x;
val l = [f, g];

(*
    acessa a cabeça da lista l: função f: retorna 5 + 10 = 15
*)
app ((hd l), 5);
(*
    acessa a cabeça da cauda da lista l (2o elemento): função g: retorna 5 *2 = 10
*)
app ((hd (tl l)), 5);