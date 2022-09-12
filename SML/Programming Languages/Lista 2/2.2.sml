(* implemente a função eval *)

datatype area = RConst of real | 
                AQuadrado of area | 
                ARetangulo of area * area | 
                ACirculo of area;

fun eval (RConst r) = r
  | eval (AQuadrado(lado)) = let val l = eval(lado) in l * l end
  | eval (ARetangulo(lado1, lado2)) = eval(lado1) * eval(lado2)
  | eval (ACirculo(raio)) = let val r = eval(raio) in 3.14 * r * r end;