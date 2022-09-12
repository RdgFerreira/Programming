(******************
    FINITE SETS
*******************)

val l = [1,2,4,5];

fun isIn x [] = false
  | isIn x (h::t) = h = x orelse isIn x t;

isIn 5 l;
isIn 7 l;

fun union s1 [] = s1
  | union s1 (h::t) = if isIn h s1 then union s1 t else union (h::s1) t;

union l l;
union l [1,9];

fun setminus [] s2 = [] (*[] minus s2*)
  | setminus s1 [] = s1 (*s1 minus []*)
  | setminus (h::t) s2 = if isIn h s2 then setminus t s2 else h::(setminus t s2);

setminus l [1,9];
setminus l [];
setminus [] l;






