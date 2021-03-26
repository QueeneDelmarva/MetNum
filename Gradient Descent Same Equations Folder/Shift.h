#pragma once 

// Function we'll use: x^3 - x - 1
float f1(float x); 

// Check if f'(x_new) > 0 OR f'(x_new) < 0
int check(float x1, float x2); 

// Function for f'(x_new) < 0, NEGATIVE
float shift_left(float x1, float x2); 

// Function for f'(x_new) > 0, POSITIVE
float shift_right(float x1, float x2); 

