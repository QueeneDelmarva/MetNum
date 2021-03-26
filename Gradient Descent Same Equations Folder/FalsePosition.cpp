#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Shift.cpp"
#include "GradientDescent.cpp"

// Main Driver
int main()
{
	float x, y;
	float x_vector, y_vector;

	int status_check = 0;
	int size_check = 0;
		
    // Choose any initial x, y 
	x = -1;		
	y = 10.;

	// Checking the roots 
	status_check = check(x, y);

	
	if (status_check == 0) 		// (f(x,0) * f(0,y) > 0)
	{
		x = shift_left(x,y);
		y = shift_right(x,y);
	}
	
	else if (status_check == 2)	// If (f(x,0) * f(0,y) = 0)
	{
		if (f(x,0) == 0)
			printf("the root is %f\n", x);

		else if (f(0,y) == 0)
			printf("the root is %f\n", y);
		
		exit(0);
	}
	
	// Choose any x_vector, y_vector 
	x_vector = 0; 
	y_vector = 1;

	// Checking the step-size 
	size_check = check_size(x_vector, y_vector); 

	if (size_check == 0) 		// if(dfdx(x_vector) * dfdy(y_vector) > 0)
	{		
		x_vector = bigStep(x,y); 
		y_vector = smallStep(x,y); 

	} 
	
	else if (size_check == 2)	// if(dfdx(x_vector) * dfdy(y_vector) = 0)
	{
		if (check_size(x_vector,0) == 0) 
		printf("the stepsize is %f\n", x_vector);

		else if (check_size(0,y_vector) == 0)
		printf("the stepsize is %f\n", x_vector);
	}

	float error = 100.;
	float delta = 10.; 

	float x_new, y_new; 
	float step_size;

	float constant_alpha = 0.1; 
	//float dynamic_alpha;

	int count = 0;

	while (fabs(error) > 1.e-5 && fabs(delta) > 1.e-2)
	{
		count++;

		// Bisection Formula 
		x_new = (x+y)/2.;
		y_new = (x+y)/2.;

		// New Roots 
		float f_x_new = f(x_new, y_new);

        // x_new = x
		if ((f_x_new > 0) && (f(x,0) > 0))
			x = x_new;
		else if ((f_x_new < 0) && (f(x,0) < 0))
			x = x_new;

        // y_new = y
		else if ((f_x_new > 0) && (f(0,y) > 0))
			y = y_new;
		else if ((f_x_new < 0) && (f(0,y) < 0))
			y = y_new;

		error = f(x_new, y_new);

		// New Step Size
		float f_x_new_vector = dfdxdfdy(x_vector, y_vector); 

		// x_new_vector = x_vector 
		if ((f_x_new_vector > 0) && (dfdx(x_vector) > 0 && dfdy(y_vector) > 0))
			x_vector = step_size; 
		else if ((f_x_new_vector > 0) && (dfdx(x_vector) < 0 && dfdy(y_vector) < 0))
			x_vector = step_size; 

		// x_new_vector = y_vector 
		if ((f_x_new_vector > 0) && (dfdx(x_vector) > 0 && dfdy(y_vector) > 0))
			y_vector = step_size; 
		else if ((f_x_new_vector > 0) && (dfdx(x_vector) < 0 && dfdy(y_vector) < 0))
			y_vector = step_size; 

		// Dynamic Alpha or the Learning Rate
		// dynamic_alpha += ((x_new + y_new)/2); 

		// Constant Alpha or the Learning Rate 
		constant_alpha += ((x_new + y_new)/2);

		// Gradient Descent Formula  
	//	step_size = sub_matrix(x_vector,y_vector)*dynamic_alpha; 
		step_size = sub_matrix(x_vector,y_vector)*constant_alpha; 

		delta = dfdxdfdy(x_vector, y_vector); 

		printf("the iteration %d, step-size is %f and f(x)=%f \n", count, step_size, dfdxdfdy(x_vector, y_vector));
	}
}