#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    for(int i = 0; i < 100; i++){
        int a = i + 1;
        int counter = 0;
        while (a != 1){
            if(a%2 == 1)
                a = 3*a + 1;
            a = a/2;
            counter++;
        }
        cout << i + 1 << ": " << counter << endl;
    }
    return 0;
}
