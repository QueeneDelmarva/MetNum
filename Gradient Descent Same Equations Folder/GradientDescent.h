#pragma once 

// Derivative with respect to x
float dfdx(float x); 

// Derivative with respect to y
float dfdy(float y);

// Combine the derivative x and y into one equation 
float dfdxdfdy(float x_vector, float y_vector); 

// Converting Linear Equation into Matrix Form 
float matrix_prev(int x, int y, int c);
float matrix_next(int x, int y, int c);

// Subtracting prev and next  
float sub_matrix(int prev, int next);

// Check if the Step Size needs to increment or decrement 
float check_size(float x_vector, float y_vector);

// Step Size increases if farther from 0 
float bigStep(float x_vector, float y_vector); 

// Step Size decreases if closer to 0
float smallStep(float x_vector, float y_vector); 