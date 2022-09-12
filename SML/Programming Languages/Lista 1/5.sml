fun cumSum [] = []
  | cumSum (h::[]) = h::[]
  | cumSum (h::t) = h::(cumSum ( (h + hd t)::(tl t) ));

cumSum [1,2,3];
cumSum [6, 10, 3, 11];
