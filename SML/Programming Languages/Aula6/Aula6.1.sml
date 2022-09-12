val a = 10; (*a é função constante/atômico/valor funcional constante/não aplicável (não toma argumentos)*)
fun f x = x + a; (*função int->int 1a ordem*)
val h = f; (*1a ordem*)(*h tem valor funcional: 
cidadãos de 1a classe: podem ser feitas atribuições val x = função, podem receber funções como argumentos,
podem retornar funções*)
f 5;
h 5;