/*
   1        A       B                         
------- = ----- + -----  <=> A*g(x)+B*f(x) = 1 
f(x)g(x)   f(x)    g(x)                       
*/
#include <iostream>
#include <cmath>
using namespace std;

double f (double x, double a, double b)
{
	return (a*x+b);//f(x) function
}

double g (double x, double a, double b)
{
	return (a*x+b);//g(x) function
}


int main(void)
{
	double A, B;
	double a1, b1;
	double a2, b2;
	
	cout<< "This version solving problem with two linear functions\n" << endl;
	cout<< "    1        A       B                           " << endl; 
	cout<< " ------- = ----- + -----  <=> Ag(x) + Bf(x) = 1  " << endl;
	cout<< " f(x)g(x)   f(x)    g(x)                         " << endl;
	cout<< endl;
	
	cout<< "Please, write a and b coefficients for the first  f(x) = ax+b equation: ";
	cin>> a1 >> b1;
	cout<< "Your first function is: " << a1 << "x + " << b1 << endl <<endl;
	
	cout<< "Please, write a and b coefficients for the second g(x) = ax+b equation: ";
	cin>> a2 >> b2;
	cout<< "Your second function is: "<< a2 << "x + " << b2 << endl <<endl;
	
	int xA0 =  -b2/a2;//solution for g(x) when A=0
	int xB0 = -b1/a1;//solution for f(x) when B=0
	
	A = 1/g(xB0, a2, b2);
	B = 1/f(xA0, a1, b1);
	
	cout<<"Answers: "<< "A = " << A << "; " << "B = " << B << endl;
}
