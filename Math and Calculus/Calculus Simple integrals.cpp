#include <iostream>
#include <cmath>
using namespace std;

double f (double X)
{
	return X*X*X;//put your function here
}


int main(void)
{
	double a;
	double b;
	double step = 0.000001;
	double sum = 0.0;
	
	cout<<"Please, enter your initial point: ", cin>> a;
	cout<<"Please, enter your last point: ", cin>> b;
	
	for(double x = a; x<=b; x=x+step)
	{
		sum += f(x)*step;
	}
	
	cout<<sum;
	
	cin.get();
	return 0;
}
