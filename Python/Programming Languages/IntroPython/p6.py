# mapas e filtros
from list_functions import *

def printL(L):
    L = list(L)
    print("[", end="")
    # for elem in L: print(str(elem), end=" ")
    for i in range(len(L)): 
        if i != 0: print(", " + str(L[i]), end="")
        else: print(str(L[i]), end="")
    print("]")

def firstLetter(L): return map(lambda x: str.capitalize(x[0]), L)

LO = ["amora","abacate","beterraba","cereja","damasco","ervilha"] # Lista
SO = {"amora","abacate","beterraba","cereja","damasco","ervilha"} # Conjunto
TO = ("amora","abacate","beterraba","cereja","damasco","ervilha") # Tupla

printL(firstLetter(LO)) 
printL(firstLetter(SO)) 
printL(firstLetter(TO))

L = [1, 2, 3, 4, 5, 6]
printL(filter(lambda x: x > 2, L)) # [ 3 4 5 6 ]

def firstC(L,C): return filter(lambda x: x[0] == C, L) # duck typing: não sabemos o tipo de x, mas ele tem que ser iterável

printL(firstC([(1,2), (2,1), (1,3)] ,1)) # [(1,2), (1,3)]
printL(firstC([(1,2), [2,1], [1,3]], 1)) # [(1,2), [1,3]]
printL(firstC([('1','2'), ['2','1'], "1,2"], '1')) # [('1','2'), "1,2"]

