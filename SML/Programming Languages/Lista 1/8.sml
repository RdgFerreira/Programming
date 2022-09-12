fun allTrue [] = false
  | allTrue (h::[]) = h
  | allTrue (h::t) = if (not (h andalso true)) then false else (allTrue t);

allTrue [true, true, true];
allTrue [true, false, true];
allTrue [true, true, false]