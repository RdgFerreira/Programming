class FormulaError(Exception): pass
class OperatorError(Exception): pass

operators = {
    "+": lambda x, y: x + y,
    "-": lambda x, y: x - y,
    "*": lambda x, y: x * y,
    "/": lambda x, y: x / y
}

def calculator():
    expr = input()
    expr = expr.split()

    if len(expr) != 3: raise FormulaError("A entrada nao consiste de 3 elementos")

    try:
        a = float(expr[0])
        b = float(expr[2])
    except ValueError: raise FormulaError("O primeiro e o terceiro valor de entrada devem ser numeros")

    operator = expr[1]
    if operator in operators: return operators[operator](a, b)
    else: raise OperatorError(operator + " nao e um operador valido")

try: print("Resultado = ", calculator())
except FormulaError as msg: print(msg)
except OperatorError as msg: print(msg) 

