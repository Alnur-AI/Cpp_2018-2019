#include <iostream>
using namespace std;
int main()
{
	int n = 4;
	int x [n];
	for(x[0] = 1; x[0] <= 4; x[0]++)
		for(x[1] = 1; x[1] <= 4; x[1]++)
			for(x[2] = 1; x[2] <= 4; x[2]++)
				for(x[3] = 1; x[3] <= 4; x[3]++)
				{
					if ( x[0]!=x[1] && x[0]!=x[2] && x[0]!=x[3] && 
						 x[1]!=x[2] && x[1]!=x[3] && 
						 x[2]!=x[3] )
					cout<< x[0] <<" "<< x[1] <<" "<<  x[2] <<" "<<  x[3] <<" "<<endl;
				}
	return 0;			
}
