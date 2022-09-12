exception nonpositive

signature MATH =
sig
    val fact: int -> int
    val halfPi: real
    val pow: int * int -> int
    val double: int -> int
end ;

structure MyMathLib :> MATH =
struct
    fun fact 0 = 1
      | fact n = if n > 0 then n * fact (n - 1) else raise nonpositive
    
    val halfPi = 1.57

    fun pow (base, 0) = 1
      | pow (base, exp) = if base > 0 then base * pow(base, exp - 1) else raise nonpositive

    fun double n = if n > 0 then 2 * n else raise nonpositive
end ;

fun useMyMathLib (n, operator) = 
    let fun aux n "fact" = Int.toString(MyMathLib.fact(n))
          | aux n "pow" = Int.toString(MyMathLib.pow(n, n))
          | aux n "double" = Int.toString(MyMathLib.double(n))
    in aux n operator end 
    handle nonpositive => "Nao posso lidar com numeros negativos!";