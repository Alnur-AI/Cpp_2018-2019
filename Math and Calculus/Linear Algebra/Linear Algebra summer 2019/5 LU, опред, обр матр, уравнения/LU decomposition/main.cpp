#include <iostream>
#include <cstdlib>
const int n = 7;

void init_A(int **A){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            A[i][j] = rand()%10;
        }
   }
}
void init_up_step(int **M){
   for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (i > j) M[i][j] = 0;
            else M[i][j] = 9;
        }
   }
}
void init_down_step(int **M){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (i < j) M[i][j] = 0;
            if (i == j) M[i][j] = 1;
            if (i > j) M[i][j] = 9;
        }
    }
}
void printArr(int **M){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            std::cout << M[i][j] << "\t";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int**init(int **M){
    M = new int*[n];
    for (int i = 0; i < n; i++)
        M[i] = new int [n];
    return M;
}

int sum(int start, int end, int q, int k, int**A, int **B){
    if (start == end) return 0;
    int s = 0;
    for (int i = start; i < end; i++){
        s += A[q][i] * B[i][k];
    }
    return s;
}

void LU_create(int **A, int **L, int **U){
    bool ZEROERR = 0;
    for (int q = 0; q < n; q++){
        for (int k = 0; k < n; k++){
            if (k >= q){
                U[q][k] = A[q][k] - sum(0, q , q, k, L, U);
                //if (U[q][q] == 0){
                //    std::cout << "IMPOSSIBLE!!!" << std::endl;
                //    exit(0);
                //}
                if (U[q][q] == 0){
                    ZEROERR = 1;
                    U[k][q] = 1;
                    continue;
                }
                L[k][q] = ( A[k][q] - sum(0, q , k, q, L, U) ) / U[q][q];
            }
        }
    }
    if (ZEROERR == 1){
        std::cout << "ZERO ERROR OCCURED! NEXT MATRIX [L] AND [U] WILL BE NOT ACCURATE CONSTRUCTED!!!\n" << std::endl;
    }
}

void AxB(int **A, int **B, int **Res){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            Res[i][j] = sum(0,n,i,j,A,B);
        }
    }
}

void error_count(int **A, int **B){
    int c = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (A[i][j]!=B[i][j]) c++;
        }
    }
    std::cout << c << " ERRORS OCCURED (max: " << n*n << ")" << std::endl;
}

int main(){
    srand(0);
    int **A;
    int **L;
    int **U;

    A = init(A);
    L = init(L);
    U = init(U);

    init_down_step(L);
    init_up_step(U);
    init_A(A);

    std::cout << "MATRIX A" << std::endl;
    printArr(A);

    LU_create(A,L,U);

    std::cout << "MATRIX L" << std::endl;
    printArr(L);
    std::cout << "MATRIX U" << std::endl;
    printArr(U);

    int **Check;
    Check = init(Check);
    AxB(L,U,Check);
    std::cout << "MATRIX LU" << std::endl;
    printArr(Check);

    error_count(A, Check);
    return 0;
}
