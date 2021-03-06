#include<stdio.h>
#include<math.h>

void newton_raphson();
void bisection();
float f(float x);
float fderivative(float x);

int main()
{
	newton_raphson();
	bisection();
	return 0;
}

void newton_raphson()
{
	float epsilon = 0.000001;
    float xinit = 1;	
    float xcurr = xinit;
    float xnext = xcurr- f(xcurr)/fderivative(xcurr);
	float alpha = -0.567143;
	int i=1;
	
	while (fabs(f(xnext)) > epsilon && i<100)
	{   
        xcurr=xnext; 
	    xnext= xcurr- f(xcurr)/fderivative(xcurr);
		printf("iterations = %d approx root = %f\n", i, xnext);
		i++;	
	}

     printf("Total iterations = %d approx root = %f\n", i, xnext);
}

float f(float x)
{
	return x + exp(x);
}

float fderivative(float x)
{
	return 1 + exp(x);
}

void bisection()
{
	float a = -1, b = 0;
	float c;
	float epsilon = 0.0000001;
	float alpha = -0.567143;
	int i = 0;

	while(i++ < 100)
	{
		if(f(a)*f(b) < 0) {
			c = (a+b)/2;

			if(fabs(f(c)) < epsilon) {
				printf("iteration: %d, root is: %f\n", i, c);
				return;
			}

			if(f(c)*f(a) < 0) {
				printf("iteration: %d, root is: %f\n", i, c);
				b = c;
			}
			else if(f(c)*f(b) < 0) {
				printf("iteration: %d, root is: %f\n", i, c);
				a = c;
			}
		}
		else
			return;
	}

	printf("iteration: %d, root is: %f\n", i, c);
}
