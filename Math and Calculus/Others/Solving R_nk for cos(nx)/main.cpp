#include <iostream>
#include <cmath>
using namespace std;

const int m = 20;
const int n = 20;
long long A[m][n];

void init_A(){
    for (int j = 0; j < n; j++)
        A[0][j] = 1;

    for (int i = 0; i < m; i++){
        if (i == 0){
            A[i][0] = 1;
            continue;
        }
        A[i][0] = A[i - 1][0] + (i + 1)*(i + 1);
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (i > 0 && j > 0)
                A[i][j] = A[i - 1][j] + A[i][j - 1];
        }
    }
}
void print_A(){
    cout << "print A array" << endl;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
int sngK(int k){
    if (k%2 == 0){
        return pow((-1),(k%4)/2);
    }
    return 0;
}
long long coef_cr (int k, int dim){
    if (sngK(k)== 0)
        return 0;
    if (dim == k)
        return sngK(k);
    if (dim == k + 1)
        return (1 + k)*sngK(k);
    if (dim >= k + 2)
        if (dim - 2 - k == 0){
            return pow(2, dim - 1 - k)*sngK(k)*(k/2 + 1)*(k/2 + 1);
        }
        return pow(2, dim - 1 - k)*sngK(k)*A[k/2 + 1 - 1][dim - 2 - k - 1];
}

int main(){
    init_A();
    //print_A();

    int num = 40;
    for (int j = 0; j <= num; j++){
        cout << j << ": ";
        for (int i = 0; i <= num; i++){
            if (i <= j)
                cout << coef_cr(i, j) << " ";
        }
        cout << endl;
    }


    return 0;
}
