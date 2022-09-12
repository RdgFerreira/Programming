# MergeSort Funcional
def head(L): return L[0]
def tail(L): return L[1]
def py2ll(L):
    if not L: return None
    else: return (head(L), py2ll(L[1:]))
def ll2py(L):
    if not L: return []
    else: return [head(L)] + ll2py(tail(L))

## split(L): recebe uma lista L e retorna duas listas L0 e L1 (metades) t.q.:
### e in L --> e in L0 || e in L1
### size(L) == size(L0) + size(L1)
### abs(size(L0) - size(L1)) <= 1
def split(L):
    if not L: return (None, None)
    if not tail(L): return (L, None)
    else:
        H0 = head(L)
        H1 = head(tail(L))
        (T0, T1) = split(tail(tail(L)))
        return ((H0, T0), (H1, T1))

L1 = py2ll([0, 1, 2, 3])
L2 = py2ll([2, 1, 3])
print("L1:", L1)
print("L2:", L2)
# L = (0, (1, (2, (3, None)))), H0 = 0, H1 = 1, split((2, (3, None))) ||--> (T0, T1) = ((2, None), (3, None)), return ((H0, T0), (H1, T1)) == ((0, (2, None)), (1, (3, None)))
    # L = (2, (3, None)), H0 = 2, H1 = 3, split(None) ||--> (T0, T1) = (None, None), return ((H0, T0), (H1, T1)) == ((2, None), (3, None))
        # L = None, return (None, None)
print("split(L1):", (ll2py(split(L1)[0]), ll2py(split(L1)[1])))
print("split(L2):", (ll2py(split(L2)[0]), ll2py(split(L2)[1])))
print("")

## sorted(L): retorna True quando L for uma lista ordenada em ordem ascendente, False caso contrário
def sorted(L):
    if not L: return True
    elif not tail(L): return True
    else:
        C1 = head(L) <= head(tail(L))
        return C1 and sorted(tail(L))

print("sorted(L1):", sorted(L1))
print("sorted(L2):", sorted(L2))
print("")

## merge(L0, L1): retorna uma lista L t.q.:
### e in L0 || e in L1 --> e in L
### size(L0) + size(L1) == size(L)
### sorted(L0) and sorted(L1) == sorted(L)
def merge(L0, L1):
    if not L0: return L1
    if not L1: return L0
    H0 = head(L0)
    T0 = tail(L0)
    H1 = head(L1)
    T1 = tail(L1)
    if H0 < H1: # cabeça da lista ordenada 1 é menor que a cabeça da lista ordenada 2
        return (H0, merge(T0, L1))
    else: 
        return (H1, merge(L0, T1))

L1 = py2ll([2, 5, 8, 9])
L2 = py2ll([3, 6, 7])
print("L1:", L1)
print("L2:", L2) 
print("merge(L1, L2):", ll2py(merge(L1, L2)))
print("")

## mergeSort(L): função pura (mantém L intacta) que retorna uma lista LL t.q.:
### e in L <--> e in LL
### sorted(LL)
def mergeSort(L):
    if not L: return None
    if not tail(L): return L
    else: 
        (L0, L1) = split(L)
        return merge(mergeSort(L0), mergeSort(L1))

L = py2ll([2, 9, 7, 6, 4, 3, 8, 5, 1])
print("L:", L)
print("mergeSort(L):", ll2py(mergeSort(L)))