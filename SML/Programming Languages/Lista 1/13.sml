fun square x = x * x;
fun sum (a, b) = a + b;
fun compose (square, sum, a, b) = square (sum (a, b));

compose(square,sum,4,5)