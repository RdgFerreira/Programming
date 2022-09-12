fun max [] = 0
  | max (h::[]) = h
  | max (h::t) = let val x = (max t) in if h > x then h else x end;

max [1,2,3,2];