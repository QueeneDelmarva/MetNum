#include <iostream>
#include "Shift.h"
#include "GradientDescent.h"

using namespace std; 

// Function we'll use: x^2 + y^2 + x + y + 6 
float f(float x, float y) 
{
	float temp = pow(x,2) + pow(y,2) + x + x + 6;
	return (temp);
}

// Check if f'(x_new) > 0 OR f'(x_new) < 0
int check(float x, float y)
{
	if (f(x,0) * f(0,y) > 0)
		return(0);

	else if (f(x,0) * f(0,y) < 0)
		return(1);

	else
		return(2);
}

// Function for f'(x_new) < 0, NEGATIVE
float shift_left(float x, float y)
{
	int status_check = check(x,y);
	float temp_x;
	
	while (status_check == 0)
	{
		temp_x = x;
		x -= 2.;

        // Positive 
		if (f(temp_x,0) > 0)	
		{
			if (f(x,0) > f(temp_x,0))
				return(temp_x);

			else if (f(x,0) < f(temp_x,0))
			{
				if (check(x,y) == 1)
					return(x);

				else
					continue;
			}
		}
		
        // Negative 
		else if (f(temp_x,0) < 0)
		{
			if (f(x,0) < f(temp_x,0))
				return(temp_x);

			else if (f(x,0) > f(temp_x,0))
			{
				if (check(x,y) == 1)
					return(x);

				else
					continue;
			}
		}
	}
	
	return(x);
}

// Function for f'(x_new) > 0, POSITIVE
float shift_right(float x, float y)
{
	int status_check= check(x,y);
	float temp_y;
	
	while (status_check == 0)
	{
		temp_y = y;
		y += 2.;

		// Positive 
		if (f(0,temp_y) > 0)	
		{
			if (f(0,y) > f(0,temp_y))
				return(temp_y);

			else if (f(0,y) < f(0,temp_y))
			{
				if (check(x,y) == 1)
					return(y);

				else
					continue;
			}
		}
		
		// Negative 
		else if (f(0,temp_y) < 0)	
		{
			if (f(0,y) < f(0,temp_y))
				return(temp_y);

			else if (f(0,y) > f(0,temp_y))
			{
				if (check(x,y) == 1)
					return(y);

				else
					continue;
			}
		}
	}
	
	return(y);
}