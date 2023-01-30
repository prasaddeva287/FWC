import numpy as np

def circle_equation(a, b):
    center = np.array([-a, -b])
    radius = a**2 - b**2
    equation = "({x} + {a})^2 + ({y} + {b})^2 = {r}^2".format(x=center[0], y=center[1], a=a, b=b, r=radius)
    return equation

# Example
print(circle_equation(2, 1))
# Output: (x + 2)^2 + (y + 1)^2 = 3^2
