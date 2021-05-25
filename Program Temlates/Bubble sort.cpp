#include <iostream>
using namespace std;
int main()
{
	int a [10] {1,4,3,5,6,7,2,9,8,10};
	for (int i = 10; i>0; i--)
		for (int j = 0; j < i; j++) 
		{
			if (a[j] > a[j+1])
			{
				int *temp = new int;
				*temp = a[j];
				a[j] = a[j+1];
				a[j+1] = *temp;
				delete temp;
				for (int k = 0; k<10; k++)
				{
					cout << a[k] << " ";
				}
				cout<<endl;
			}
		}
	for (int i = 0; i<10; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}
