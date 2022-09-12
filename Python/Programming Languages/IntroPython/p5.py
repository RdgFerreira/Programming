# quickSort
from list_functions import *


## filterL(L): recebe uma lista L e um predicado f, e produza uma nova lista
##             com cada elemento de L que seja verdade para f
def filterL(L, f):
    if not L: return None
    else:
        T = filterL(tail(L), f)
        H = head(L)
        return (H, T) if f(H) else T

test("filter-greater-than-2", filterL((1, (2, (3, (4, None)))), lambda x: x > 2), py2ll([3, 4])) 

def filterOdds(L): # Filtra os números ímpares
    return filterL(L, lambda x: x % 2)

L = py2ll(range(2, 7))
test("filter-odds", filterOdds(L), (3, (5, None)))

def filterStr(L): # Filtra as strings
    return filterL(L, lambda x: isinstance(x, str))

L = py2ll([1, "2", True, "4", 3.14])
test("filter-str", filterStr(L), ("2", ("4", None)))



from math import sqrt
## isPrime(a): recebe um inteiro e retorna True se é primo
def isPrime(a):
    if a < 2:
        return False
    for x in range(2, int(sqrt(a)) + 1):
        if a % x == 0:
            return False
    return True

def filterPrimes(L):
    return filterL(L, isPrime)

L = py2ll(range(2, 7))
test("filter-primes", filterPrimes(L), (2, (3, (5, None))))


## append(L0, L1): concatena L0 e L1
def appendL(L1, L2):
    if not L1: return L2
    else: return (head(L1), appendL(tail(L1), L2))

L1 = py2ll([1, 2, 3])
L2 = py2ll([4, 5, 6])
test("append_lists", appendL(L1, L2), py2ll([1, 2, 3] + [4, 5, 6]))


# Escreva uma função qsort, que receba uma lista L, e retorne uma nova lista
# com os elementos de L ordenados em ordem ascendente.
def qSort(L):
    if not L: return None
    else:
        H = head(L)
        T = tail(L)
        Smalls = qSort(filterL(T, lambda x: x < H))
        Bigs = qSort(filterL(T, lambda x: x >= H))
        return appendL(appendL(Smalls, (H, None)), Bigs)

test("qSort", qSort(py2ll([5,4,2,3,7,8,1])), py2ll([1,2,3,4,5,7,8]))