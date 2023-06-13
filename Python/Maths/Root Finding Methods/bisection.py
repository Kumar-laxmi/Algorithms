# Bi Section Algorithm

# Working
"""
    provide the equation and then an interval with an iteration limit.

    The result will be either the root answer if found or not found.
"""

# Limitations
"""
    This is designed only for 1 variable
"""

# Creating a class for function objects
class f():
    def __init__(self,eq: str):
        self.eq = eq
    def setEq(self,eq: str):
        self.eq = eq 
    def getEq(self):
        return self.eq
    def getVal(self,val: float):
        equate = self.eq.replace("x",str(val))
        res = eval(equate)
        return res

def biSection(func: f,low_limit: float,up_limit: float,iter: int):
    # The response container
    result = {
        "status":"not found",
        "answer":0,
    }

    # Main Bi section code
    for i in range(iter):
        x = (low_limit + up_limit)/2
        res = func.getVal(x)

        if (res > 0):
            up_limit = x
        elif (res < 0):
            low_limit = x
        else:
            result["status"] = "found"
            break
    result["answer"] = x
    return result

##### Main Function ######
eq = input("Enter the equation:")
func = f(eq)

low_limit = float(input("Enter the lower limit:"))
upper_limit = float(input("Enter the upper limit:"))

iter = int(input("Enter the number of iterations:"))

res = biSection(func,low_limit,upper_limit,iter)

if (res["status"] == "found"):
    print(f"The Root is x={res['answer']}")
else:
    print(f"The Nearest Root is x={res['answer']}")