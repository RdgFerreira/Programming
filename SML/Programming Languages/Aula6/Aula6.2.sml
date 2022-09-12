val a = 10;

fun f x = x + a;
fun g x = 2 * x;

val p = (f, g);
val l = [f, g]; (*tipos homogêneos em listas*)

(#1 p) 5; (*acessa o primeiro elemento da tupla p: função f: retorna 5 + 10 = 15*)
(#2 p) 5; (*acessa o primeiro elemento da tupla p: função f: retorna 5 * 2 = 10*)