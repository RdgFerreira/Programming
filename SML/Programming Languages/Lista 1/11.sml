datatype btree = Leaf | Node of (btree * int * btree);

val t = Node (Node (Leaf, 1, Leaf), 6, Node (Leaf, 12, Leaf));

(*
fun traverse (Leaf) = []
  | traverse (Node (t1, m, t2)) =
    let val l1 = traverse t1;
        val l2 = traverse t2
    in
        l1 @ [m] @ l2
    end;
*)

fun sumAll (Leaf) = 0
  | sumAll (Node (left, m, right)) = 
    let val l = sumAll left val r = sumAll right
    in l + m + r end;


sumAll t;