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
      | fact n = n * fact(n - 1)
    
    val halfPi = 1.57

    fun pow (base, 0) = 1
      | pow (base, exp) = base * pow (base, exp - 1)
    
    fun double x = 2 * x
end ;