datatype dinheiro = Reais of real | Centavos of int | Pessoa_Dinheiro of string * real;

fun amount (Centavos c) = c
  | amount (Reais r) = round (r * 100.0)
  | amount (Pessoa_Dinheiro (str, q)) = amount (Reais q);


amount(Reais(2.5));


