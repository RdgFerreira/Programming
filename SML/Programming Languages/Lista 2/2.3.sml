(* implemente a função eval *)

datatype perimetro  = RConst of real | 
                      PQuadrado of perimetro | 
                      PRetangulo of perimetro * perimetro | 
                      PCirculo of perimetro | 
                      PTriangulo of perimetro * perimetro * perimetro;

fun eval (RConst r) = r
  | eval (PQuadrado(lado)) = let val l = (eval lado) in l + l + l + l end
  | eval (PRetangulo(lado1, lado2)) = 
                                     let val l1 = (eval lado1)
                                         val l2 = (eval lado2)
                                     in l1 + l2 + l1 + l2 end
  | eval (PCirculo(raio)) = let val r = (eval raio) in (3.14 * r) + (3.14 * r) end
  | eval (PTriangulo(lado1, lado2, lado3)) = 
                                            let val l1 = (eval lado1)
                                                val l2 = (eval lado2)
                                                val l3 = (eval lado3)
                                            in l1 + l2 + l3 end;