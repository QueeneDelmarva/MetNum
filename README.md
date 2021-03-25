# Numerical Methods 

Numerical methods are used to solve multidimensional problems, finding the extremum of a function determines either the maximum or minimum values. The functions could take on the algorithm search of the bracketing, naive search, or modified secant method. We apply the extremum to the Gradient Descent Method to find the minimum of a vector-valued function by multiplying the gradient with a step size; we get the step size as a dynamic alpha from the algorithm search iterations. 

Bracketing Method: Bisection and False-Position

The Bracketing Method consists of the Bisection Method and False-Position Method, both are similar in operation except for it's formula. 

## Gradient Descent Steps 
1. Choose any x_vector =〈x1, x2, ..., xn〉
2. Calculate ∇f(x_vector)=〈fx1, fx2, ..., fn〉 
3. Calculate x_vector_new = x_vector - ∇f(x_vector)alpha 
4. Repeat until ||∇f(x_vector)|| < e, where e is a small number. 

## Bracketing Method Steps
1. Choose a function and two inital x: f(x), x1, x2
2. Bisection Formula: x_new = x1+x2/2 || False-Position Formula: x_new = x2 - (f(x2)(x1-x2)/f(x1)-f(x2)) 
3. Check if f'(new) > 0 OR f'(new) is < 0. 
4. Then determine if x_new = x1 OR x2 depedning on the f'(new)'s sign. 
5. Repeat Step 2 until f'(x_new) < e, where e is 0. 

## Functions Used 
### See the Bracketing Different Equations Folder 
1. Bisection Method: f(x) = x^3 - x - 1, x1 = 1 and x2 = 2 
2. False-Position Method: f(x) = 2x^3 - 2x - 5, x1 = -5 and x2 = unknown 
### See the Gradient Descent Same Equations Folder
3. Gradient Descent Method: f(x,y) = x^2 + y^2 + x + y + 6, x = -1, y = 1, constant alpha = 0.1, dynamic alpha = *depends on the Bracketing Iterations
