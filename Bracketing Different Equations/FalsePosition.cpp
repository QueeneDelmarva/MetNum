#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function we'll use: 2x^3 - 2x - 5
float f(float x)
{
	float temp = (2*pow(x,3))-(2*x)-5;
	return (temp);
}

// Check if f'(x_new) > 0 OR f'(x_new) < 0
int check(float x1, float x2)
{
	if (f(x1) * f(x2) > 0)
		return(0);

	else if (f(x1) * f(x2) < 0)
		return(1);

	else
		return(2);
}

// Function for f'(x_new) < 0, NEGATIVE
float shift_left(float x1, float x2)
{
	int status_check = check(x1,x2);
	float temp_x1;
	
	while (status_check == 0)
	{
		temp_x1 = x1;
		x1 -= 2.;

        // Positive 
		if (f(temp_x1) > 0)	
		{
			if (f(x1) > f(temp_x1))
				return(temp_x1);

			else if (f(x1) < f(temp_x1))
			{
				if (check(x1,x2) == 1)
					return(x1);

				else
					continue;
			}
		}
		
        // Negative 
		else if (f(temp_x1) < 0)
		{
			if (f(x1) < f(temp_x1))
				return(temp_x1);

			else if (f(x1) > f(temp_x1))
			{
				if (check(x1,x2) == 1)
					return(x1);

				else
					continue;
			}
		}
	}
	
	return(x1);
}

// Function for f'(x_new) > 0, POSITIVE
float shift_right(float x1, float x2)
{
	int status_check= check(x1,x2);
	float temp_x2;
	
	while (status_check == 0)
	{
		temp_x2 = x2;
		x2 += 2.;

		// Positive 
		if (f(temp_x2) > 0)	
		{
			if (f(x2) > f(temp_x2))
				return(temp_x2);

			else if (f(x2) < f(temp_x2))
			{
				if (check(x1,x2) == 1)
					return(x2);

				else
					continue;
			}
		}
		
		// Negative 
		else if (f(temp_x2) < 0)	
		{
			if (f(x2) < f(temp_x2))
				return(temp_x2);

			else if (f(x2) > f(temp_x2))
			{
				if (check(x1,x2) == 1)
					return(x2);

				else
					continue;
			}
		}
	}
	
	return(x2);
}

// Main Driver
int main()
{
	float x1, x2;
	int status_check = 0;
	
    // One initial x and a random/unknown variable 
	x1 = -5;		
	x2 = 10.; 

	status_check = check(x1, x2);

	if (status_check == 0)
	{
		x1 = shift_left(x1,x2);
		x2 = shift_right(x1,x2);
	}

	else if (status_check == 2)

	{
		if (f(x1) == 0)
			printf("the root is %f\n", x1);

		else if (f(x2) == 0)
			printf("the root is %f\n", x2);
		
		exit(0);
	}
	
	float error = 100.;
	float x_new;
	int count=0;

	while (fabs(error) > 1.e-5)
	{
		count++;

		// Bisection Formula 
		x_new = (x1+x2)/2.;

		float f_x_new = f(x_new);

        // x_new = x1
		if ((f_x_new > 0) && (f(x1) > 0))
			x1 = x_new;
		else if ((f_x_new < 0) && (f(x1) < 0))
			x1 = x_new;

        // x_new = x2
		else if ((f_x_new > 0) && (f(x2) > 0))
			x2 = x_new;
		else if ((f_x_new < 0) && (f(x2) < 0))
			x2 = x_new;
			
		error = f(x_new);
		printf("iteration %d, x_new=%f f(x)=%f\n", count, x_new, f(x_new));
	}
	
	printf("the root is %f and f(x)=%f \n", x_new, f(x_new));
}