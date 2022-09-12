fun sumLists ([], []) = []
  | sumLists ((h1::t1), (h2::t2)) = (h1 + h2)::(sumLists (t1, t2));

sumLists ([1,2], [3,4]);