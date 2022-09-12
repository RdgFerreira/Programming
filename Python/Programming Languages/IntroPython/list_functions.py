def head(L): return L[0]
def tail(L): return L[1]

def py2ll(L): # python list --> linked list (imutável)
    if not L: return None
    else: return (head(L), py2ll(L[1:]))

def ll2py(L): # linked list --> python list (imutável)
    if not L: return []
    else: return [head(L)] + ll2py(tail(L))

def size(L): # size of a linked list
    if not L: return 0
    else: return 1 + size(tail(L))

## sorted(L): retorna True quando L for uma lista ordenada em ordem ascendente, False caso contrário
def sorted(L):
    if not L: return True
    elif not tail(L): return True
    else:
        C1 = head(L) <= head(tail(L))
        return C1 and sorted(tail(L))

def filterL(L, f):
    if not L: return None
    else:
        T = filterL(tail(L), f)
        H = head(L)
        return (H, T) if f(H) else T

def appendL(L1, L2):
    if not L1: return L2
    else: return (head(L1), appendL(tail(L1), L2))

def mapL(L, f):
    if not L: return None
    else: return (f(head(L)), mapL(tail(L), f))

def test(title, value, expected):
    print("[" + title + "] " + "Expected: " + str(expected) + " Actual: " + str(value))
    if value == expected: print("Pass")
    else: print("Fail")

def printL(L):
    L = list(L)
    print("[", end="")
    # for elem in L: print(str(elem), end=" ")
    for i in range(len(L)): 
        if i != 0: print(", " + str(L[i]), end="")
        else: print(str(L[i]), end="")
    print("]")