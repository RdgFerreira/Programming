# Funções de Alta Ordem: recebem outras funções como parâmetro / Retornam outras funções
def head(L): return L[0]
def tail(L): return L[1]
def py2ll(L):
    if not L: return None
    else: return (head(L), py2ll(L[1:]))

## Ordem Zero: Recebem e retornam apenas dados
def fact(n):
    if n > 1: return n * fact(n - 1)
    else: return 1

def double(n): return 2 * n
def inc(n): return 1 + n

## Ordem n: Recebem outras funções de ordem n-1 como parâmetro:
def twice(fun, n): return fun(fun(n))
def third(twice, fun, n): return fun(twice(fun, n))
def fourth(third, twice, fun, n): return fun(third(twice, fun, n))
def fifth(fourth, third, twice, fun, n): return fun(fourth(third, twice, fun, n))

n = 1
print("n =", n)
print("double(n):", double(n))
print("twice(double, n):", twice(double, n))
print("third(twice, double, n):", third(twice, double, n))
print("fourth(third, twice, double, n):", fourth(third, twice, double, n))
print("fifth(fourth, third, twice, double, n):", fifth(fourth, third, twice, double, n))
print("")

## Ordem 1:
def apply(L, f):
    for x in L:
        print(x, f(x))

## test(título do teste, expressão a ser testada, valor esperado)
def test(title, value, expected):
    print("[" + title + "] " + "Expected: " + str(expected) + " Actual: " + str(value))
    if value == expected: print("Pass")
    else: print("Fail")

## incL(LL): incrementa de 1 todos os valores de uma LL
def incL(L):
    if not L: return None
    else: return (head(L) + 1, incL(tail(L)))
def factL(L):
    if not L: return None
    else: return (fact(head(L)), factL(tail(L)))
def strL(L):
    if not L: return None
    else: return (str(head(L)), strL(tail(L)))

L1 = py2ll([1, 2, 3])
print("L1 =", L1, "\n")
test("incL", incL(L1), (2, (3, (4, None))))
test("factL", factL(L1), (1, (2, (6, None))))
test("strL", strL(L1), ('1', ('2', ('3', None))))
print("")

## Uma estrutura comum: mapa
def mapL(L, f):
    if not L: return None
    else: return (f(head(L)), mapL(tail(L), f))

L2 = py2ll([2, 3])
print("L2 =", L2, "\n")
test("map-fact", mapL(L2, fact), (2, (6, None)))
test("map-str", mapL(L2, str), ('2', ('3', None)))
test("map-inc", mapL(L2, inc), (3, (4, None)))
test("map-inc-lam", mapL(L2, lambda x: x + 1), (3, (4, None))) ## Expressão lambda: função anônima
print("")

## Expressões lambda
square = lambda x: x * x
print("square(3) =", square(3))
print("(lambda x: x * x) (5) =", (lambda x: x * x) (5))

add = lambda x, y: x + y
print("add(-1, 1) =", add(-1, 1))
print("")

add = lambda x: lambda y: x + y ## Notação currificada: funções parciais: aplicação leva a criação de novas funções
print("Notação currificada: add(3)(4) =", add(3)(4))
incBy1 = add(1) ## add: fábrica de funções
incBy2 = add(2)
print("incBy1(1) =", incBy1(1))
print("incBy2(1) =", incBy2(1))
print("")

# Closures
## 2 ponteiros
    ### Variáveis livres: N = valor
    ### Código: corpo da função
## incN(L, N): recebe lista L e inteiro N e retorna uma nova lista com cada elemento de L aumentado de N
def incN(L, N):
    return mapL(L, lambda x: x + N) ## N não declarada em lambda: variável livre em lambda

L2 = py2ll([1, 2])
print("L2 =", L2, "\n")
test("map-inc-N", incN((1, (2, None)), 2), (3, (4, None)))
print("")

## Funções equivalentes:
def make_inc_1(n): # fábrica
    def inc(x): return x + n
    return inc
def make_inc_2(n): # fábrica
    return lambda x: x + n
make_inc_3 = lambda n: lambda x: x + n

inc1 = make_inc_1(1)
inc2 = make_inc_2(1)
inc3 = make_inc_3(1)
print("inc1(2) == inc2(2) == inc3(2):", inc1(2) == inc2(2) == inc3(2))








