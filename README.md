# Numerical Methods 

Bracketing Method: Bisection and False-Position

The Bracketing Method consists of the Bisection Method and False-Position Method, both are similar in operation except for it's formula. 

## Steps
1. Choose a function and two inital x: f(x), x1, x2
2a. Bisection Formula: x_new = x1+x2/2
2b. False-Position Formula: x_new = x2 - (f(x2)(x1-x2)/f(x1)-f(x2)) 
3. Check if f'(new) > 0 OR f'(new) is < 0. 
4. Then determine if x_new = x1 OR x2 depedning on the f'(new)'s sign. 
5. Repeat Step 2 until f'(x_new) < e, where e is 0. 

## Functions Used 
1. Bisection Method: f(x) = x^3 - x - 1, x1 = 1 and x2 = 2 
2. False-Position Method: f(x) = 2x^3 - 2x - 5, x1 = -5 and x2 = 7 
