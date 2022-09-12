# Dados Imutáveis: Usados para construir funções puras
## Listas mutáveis em python, tuplas imutáveis

## Funções Puras:
### Clareza, Corretude

## Listas Encadeadas (usando tuplas):
### "None" é uma lista; Se L é uma lista, então um elemento mais L é uma lista
L = (0, (1, (2, None)))
print("L: ", L)
print("L[0]: ", L[0]) # Head
print("L[1]: ", L[1]) # Tail

L0 = L
L1 = (-1, L0)
print("L1: ", L1)

def head(L): return L[0]
def tail(L): return L[1]

def py2ll(L): # python list --> linked list (imutável)
    if not L: return None
    else: return (head(L), py2ll(L[1:]))
print("py2ll([1,2,3]): ", py2ll([1,2,3]))

def ll2py(L): # linked list --> python list (imutável)
    if not L: return []
    else: return [head(L)] + ll2py(tail(L))
print("ll2py((1, (2, (3, None)))): ", ll2py((1, (2, (3, None)))))

def size(L): # size of a linked list
    if not L: return 0
    else: return 1 + size(tail(L))
print("size of L1: ", size(L1))


