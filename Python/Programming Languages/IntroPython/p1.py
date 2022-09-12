# Funções puras: existem somente uma resposta possível para cada valor

## Obs: operador += impuro; operador + puro (não altera o valor dos argumentos originais)
## Imperativo: Mudança de Estado (variáveis) via comandos
def factImp(n):
    ans = 1
    while n > 1:
        ans *= n
        n -= 1
    return ans

## Funcional: Reescrita de textos (não há estados) via definições
### Loops em ling funcionais: recursão e iteradores
def factFun(n):
    if n > 1:
        return n * factFun(n - 1)
    else:
        return 1

print(factImp(5), factFun(5))





