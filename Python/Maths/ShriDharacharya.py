import math

def ShriDharacharyaFormulae(a, b, c):
    compValue = (b ** 2) - 4 * a * c
    val1 = -b / (2 * a)
    
    if compValue >= 0:
        val2 = math.sqrt(compValue) / (2 * a)
        print(val1 + val2, "and", val1 - val2)
    else:
        print("Imaginary roots")

a = float(input())
b = float(input())
c = float(input())
ShriDharacharyaFormulae(a, b, c)
