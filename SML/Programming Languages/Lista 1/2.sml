(* implemente a função pow *)
fun pow (0, exp) = 0
  | pow (base, 0) = 1
  | pow (base, exp) = let val nextExp = exp - 1 in base * (pow (base, nextExp)) end;

pow (5, 2);
pow (2, 0);
pow (5, 1);
pow (0, 2);