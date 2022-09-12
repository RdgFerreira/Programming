# Reduções
from functools import reduce
from list_functions import *

L = [1, 2, 3, 4, 5]
test("Redução com soma", reduce(lambda acc, x: acc + x, L), 15); print("") 
# Aplica continuamente, da esq -> dir, somas no objeto iterável e acumula os resultados
# iniciamos o acumulador de 0
# acc=0
# acc=0,b=1
# acc=1,b=2
# acc=3,b=3
# acc=6,b=4
# acc=10,b=5
# acc=15
test("Redução com soma", reduce(lambda acc, x: acc + x, L, -15), 0); print("")

import operator
test("Redução com soma", reduce(operator.add, L, -15), 0); print("")
test("Reducao com multiplicacao", reduce(operator.mul, L), 120); print("")

LS = ["amora","abacate","beterraba","cereja","damasco","ervilha"]
test(
    "Reducao com str concat", 
    reduce(operator.add, LS), 
    "amoraabacatebeterrabacerejadamascoervilha"
);print("")


Op = lambda acc, x: acc + ", " + x
test(
    "Reducao com Op", 
    reduce(Op, LS), 
    'amora, abacate, beterraba, cereja, damasco, ervilha'
);print("")


test(
    "Reducao selecionar max elemento",
    reduce(lambda acc, x: acc if acc > x else x, L),
    5
);print("")


# x precisa ter o método len (listas, conjuntos e tuplas)
def sumLens(L): return reduce(lambda acc, x: acc + len(x), L, 0)
def sumLens2(L): return reduce(operator.add, map(lambda x: len(x), L), 0)
test(
    "Somar comprimentos de strings",
    sumLens(LS), # sumLens2(LS)
    41
);print("")