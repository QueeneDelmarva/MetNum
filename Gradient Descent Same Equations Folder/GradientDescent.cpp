#include <iostream>
#include "Shift.h"
#include "GradientDescent.h"

using namespace std; 

// Gradient Vector x^2 + y^2 + x + y + 6 
float dfdx(float x) { // Derivative with respect to x 
	float temp = 2*x + 1; 
	return (temp);
}

float dfdy(float y) { // Derivative with respect to y
	float temp = 2*y + 1; 
	return (temp);
}

float dfdxdfdy(float x_vector, float y_vector) {
    return dfdx(x_vector) && dfdy(y_vector);
}
// Converting Linear Equation into Matrix Form 
float matrix_prev(int x, int y, int c) { // (1) The Previous Equation 
    int prev; 

    // The x variables from dfdx(x) equation 
    while ((x = dfdx(x))) { 
        int matrix[x][y];
        char variable[] = {'x'}; 
        int constant[x][1]; 

        for (int i = 0; i < 2; i++) {
            for (int j = 0; i < 1; i++)
                 return matrix[2][1];
        }
        return constant[x][0];
    }
    return prev;

    // The y variables from dfdy(y) equation 
    while ((y = dfdy(y))) {
        int matrix[x][y]; 
        char variable[] = {'y'}; 
        int constant[y][1]; 

        for (int i = 0; i < 2; i++) {
            for (int j = 0; i < 1; i++)
                return matrix[2][1];
        }
        return constant[y][0];
    }
    return prev;
}

float matrix_next(int x, int y, int c) { // (2) The Next Equation 
    int next;

    // The x variables from dfdx(x) equation 
    while ((x = dfdx(x))) { 
        int matrix[x][y];
        char variable[] = {'x'}; 
        int constant[x][1]; 

        for (int i = 0; i < 2; i++) {
            for (int j = 0; i < 1; i++)
                 return matrix[2][1];
        }
        return constant[x][0];
    }
    return next;

    // The y variables from dfdy(y) equation 
    while ((y = dfdy(y))) {
        int matrix[x][y]; 
        char variable[] = {'y'}; 
        int constant[y][1]; 

        for (int i = 0; i < 2; i++) {
            for (int j = 0; i < 1; i++)
                return matrix[2][1];
        }
        return constant[y][0];
    }
    return next;
}

// Subtracting matrix_next from matrix_prev 
float sub_matrix(int prev, int next) {
    while (prev == matrix_prev(0,0,0)) {
        int x, y; 
        int matrix[x][y]; 

            for (int i = 0; i < 2; i++) {
                for (int j = 0; i < 1; i++)
                    return matrix[2][1];
        }  
        return prev; 
    }

    while (next == matrix_next(0,0,0)) {
        int x, y; 
        int matrix[x][y]; 

            for (int i = 0; i < 2; i++) {
                for (int j = 0; i < 1; i++)
                    return matrix[2][1];
        }  
        return next;
    }
    return (prev - next); 
}

// Check if the Step Size needs to increment or decrement 
float check_size(float x_vector, float y_vector) {
    float func_dfdx = dfdx(x_vector); 
    float func_dfdy = dfdy(y_vector);
       
    if(dfdx(x_vector) * dfdy(y_vector) > 0) 
        return 0; 
     else if (dfdx(x_vector) * dfdy(y_vector) < 0) 
        return 1; 
     else 
        return 2; 
}

// Step Siz increases if it's farther away from 0
float bigStep(float x_vector, float y_vector) {
    int size_check = (x_vector, y_vector); 
    int dynamic_alpha; 
    int stepsize; 
    float temp_x_vector; 

    do {
        for(int i = 0; i < x_vector; i++) {
            for(int j = 0; j < y_vector; j++) {
                return stepsize++;
            }
        }
    } while (dynamic_alpha >= 0 && dynamic_alpha <= 0);

  return(x_vector); 
}

// Step Size decreases if closer to 0
float smallStep(float x_vector, float y_vector) {
    int size_check = (x_vector, y_vector); 
    int dynamic_alpha; 
    int stepsize; 
    float temp_y_vector; 

    do {
        for(int i = 0; i < x_vector; i++) {
            for(int j = 0; j < y_vector; j++) {
                return stepsize++;
            }
        }
    } while (dynamic_alpha >= 0 && dynamic_alpha <= 0);

  return(y_vector);    
}