//Program to find root by new method

/*****NOTE
	This method works for extreme values of x(n)
	Hence we must use 'double'  data type instead of 'float' because it exceeds the range of float

*/

#include<stdio.h>
#include<math.h>

void fast_root();
double f(double x);
double fderivative(double x);
double f2derivative(double x);

int main()
{
	fast_root();
	return 0;
}

// function to find root by new method
void fast_root()
{
	// initial value
	double xinit = 0;
	
	double epsilon = 0.000001;
	int iteration = 0;

	//first iteration
	double xcurr = xinit;
	double xnext = xcurr - f(xcurr)/fderivative(xcurr) - ((1.0/2)*(f(xcurr)/fderivative(xcurr))*(f(xcurr)/fderivative(xcurr))*(f2derivative(xcurr)/fderivative(xcurr)));
	printf("iteration: %d \n",iteration+1);

	// loop doing the subsequent iterations
	while ( fabs(xnext-xcurr) + fabs(f(xnext)) > epsilon)	// limiting condition
	{

		// x(n) for current step = x(n+1) of previous step
		xcurr = xnext;

		// finding x(n+1) by formula
		xnext = xcurr - f(xcurr)/fderivative(xcurr) - ((1.0/2)*(f(xcurr)/fderivative(xcurr))*(f(xcurr)/fderivative(xcurr))*(f2derivative(xcurr)/fderivative(xcurr)));
		
		iteration++;
		printf("iteration: %d\n",iteration+1);	
	}

	printf("Total iterations=%d approx root=%f funcvalatroot %f \n",iteration+1, xnext, f(xnext));
}

//function
double f(double x)
{
	return cos(x)- x*exp(x); 	
}

//function to find first derivative
double fderivative(double x)
{
	return -sin(x)-(exp(x)*(1+x));
}

// function to find 2nd derivative
double f2derivative(double x)
{
	return -cos(x)-(exp(x)*(2+x));
}
