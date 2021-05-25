#include <iostream>
#include <cstdlib>

void init_A(double **A, int n){
    int *temp = new int;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            //A[i][j] = 0;
            *temp = rand()%10;
            A[i][j] = (double)*temp;
        }
    }
    delete temp;
}

void delete_arr(double** A, int n){
    for (int i = 0; i < n; i++)
        delete [] A[i]; // ERROR HERE
    delete []A;
}

void init_up_step(double **M, int n){
   for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (i > j) M[i][j] = 0;
            //else M[i][j] = 9;
        }
   }
}
void init_down_step(double **M, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (i < j) M[i][j] = 0;
            if (i == j) M[i][j] = 1;
            //if (i > j) M[i][j] = 9;
        }
    }
}
void printArr(double **M, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cout << M[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

double **init(double **M, int n){
    M = new double*[n];
    for (int i = 0; i < n; i++)
        M[i] = new double [n];
    return M;
}

double sum(int start, int end, int q, int k, double**A, double **B){
    if (start == end) return 0;
    double s = 0.0;
    for (int i = start; i < end; i++){
        s += A[q][i] * B[i][k];
    }
    return s;
}

void LU_create(double **A, double **L, double **U, int n){
    for (int q = 0; q < n; q++){
        for (int k = 0; k < n; k++){
            if (k >= q){
                U[q][k] = A[q][k] - sum(0, q , q, k, L, U);
                if (U[q][q] == 0.0){
                    std::cout << "IMPOSSIBLE!!!" << std::endl;
                    U[q][q] = 1;
                    L[k][q] = 1;
                    continue;
                }
                L[k][q] = ( A[k][q] - sum(0, q , k, q, L, U) ) / U[q][q];
            }
        }
    }
}

void AxB(double **A, double **B, double **Res, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            Res[i][j] = sum(0,n,i,j,A,B);
        }
    }
}

double det(double **A, int n){
    double **L;
    double **U;

    L = init(L, n);
    U = init(U, n);

    std::cout << "1) INITIALIZED\n";

    init_down_step(L, n);
    init_up_step(U, n);
    std::cout << "2) PREPARED\n";

    LU_create(A,L,U, n);
    std::cout << "3) CREATED\n";

    double res = 1;
    for (int i = 0; i < n; i++){
        res *= U[i][i];
    }
    std::cout << "4) CALCULATED\n";

    delete_arr(L, n);
    delete_arr(U, n);
    std::cout << "5) DELETED\n";

    return res;
}

int main(){
    srand(1);

    int n = 3;


    double **A;
    double **L;
    double **U;

    A = init(A, n);
    L = init(L, n);
    U = init(U, n);

    init_down_step(L, n);
    init_up_step(U, n);
    init_A(A, n);
     A[0][0] = 10; A[0][1] = -7; A[0][2] = 0;
    A[1][0] = -3; A[1][1] =  6; A[1][2] = 2;
    A[2][0] =  5; A[2][1] = -1; A[2][2] = 5;

    std::cout << "MATRIX A" << std::endl;
    printArr(A, n);

    LU_create(A,L,U, n);

    std::cout << "MATRIX L" << std::endl;
    printArr(L, n);
    std::cout << "MATRIX U" << std::endl;
    printArr(U, n);

    double **Check;
    Check = init(Check, n);
    AxB(L,U,Check, n);
    std::cout << "MATRIX LU" << std::endl;
    printArr(Check, n);
    return 0;
}
/*

    while (n > 0){
        double **A;
        A = init(A,n);
        init_A(A,n);
        std::cout << "MATRIX A" << std::endl;
        printArr(A, n);
        std::cout << "det is equal: " << det(A,n) << std::endl;
        delete_arr(A, n);
        std::cin >> n;
    }

    double **Check;
    Check = init(Check);
    AxB(L,U,Check);
    std::cout << "MATRIX LU" << std::endl;
    printArr(Check);

*/
