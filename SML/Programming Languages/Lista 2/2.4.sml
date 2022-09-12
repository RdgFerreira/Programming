(* implemente a função simplify *)

datatype UnOp = Not;
datatype BinOp = Add | Sub | Mul | Or | Eq | Gt;

datatype Sexpr = IConst of int | 
                 Op1 of UnOp * Sexpr | 
                 Op2 of BinOp * Sexpr * Sexpr;

fun simplify (Op2(Add, x, IConst 0)) = simplify x
  | simplify (Op2(Add, IConst 0, x)) = simplify x
  | simplify (Op2(Sub, x, IConst 0)) = simplify x
  | simplify (Op2(Mul, x, IConst 1)) = simplify x
  | simplify (Op2(Mul, IConst 1, x)) = simplify x
  | simplify (Op2(Mul, _, IConst 0)) = IConst 0
  | simplify (Op2(Mul, IConst 0, _)) = IConst 0
  | simplify (Op2(Sub, x, y)) = if ((simplify x) = (simplify y)) then (IConst 0) else (if ((simplify y) = IConst 0) then (simplify x) else (Op2(Sub, simplify x, simplify y)))
  | simplify (Op1(Not, Op1(Not, x))) = simplify x
  | simplify (Op2(Or, x, y)) = if ((simplify x) = (simplify y)) then (simplify x) else (Op2(Or, simplify x, simplify y))
  | simplify e = 
                case e of
                         (Op1(Op, x)) =>
                                         let val y = (simplify x)
                                         in if (y = x) then e else simplify (Op1(Op, y)) end
                       | (Op2(Op, x, y)) =>
                                             let val z1 = (simplify x) 
                                                 val z2 = (simplify y)
                                             in if (z1 = x) andalso (z2 = y) then e else simplify (Op2(Op, z1, z2)) end
                       | _ => e;