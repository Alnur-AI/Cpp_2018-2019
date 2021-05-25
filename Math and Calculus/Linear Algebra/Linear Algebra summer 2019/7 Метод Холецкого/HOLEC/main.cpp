#include <iostream>
#include <cstdlib>
#include <cmath>

struct matrix{
    double **Arr;
    int m;
    int n;
};

matrix multyply(matrix C, matrix A, matrix B);
matrix copy_matrix(matrix new_matrix, matrix orig_matrix);
void zero_arr(matrix A);
void print_arr(matrix A);//print array
matrix holec(matrix L, matrix A);
matrix init(matrix A, int m, int n);
matrix transp(matrix New_m, matrix A);
void delete_matrix(matrix A);

int main(){
    matrix A = init(A,3,3);

    A.Arr[0][0] =  81.0;
    A.Arr[0][1] = -45.0;
    A.Arr[0][2] = 45.0;
    A.Arr[1][0] =  -45.0;
    A.Arr[1][1] = 50.0;
    A.Arr[1][2] = -15.0;
    A.Arr[2][0] =  45.0;
    A.Arr[2][1] = -15.0;
    A.Arr[2][2] = 38.0;

    std::cout << "MATRIX [A]\n";
    print_arr(A);


    matrix L = init(L,3,3);
    L = holec(L, A);
    std::cout << "MATRIX [L]\n";
    print_arr(L);

    matrix Lt = init(Lt,3, 3);
    Lt = transp(Lt,L);
    std::cout << "MATRIX [Lt]\n";
    print_arr(Lt);

    matrix LLt = init(LLt,3,3);
    LLt = multyply(LLt, L, Lt);
    std::cout << "MATRIX [LLt]\n";
    print_arr(LLt);

    return 0;
}
matrix multyply(matrix C, matrix A, matrix B){
    if (A.n != B.m){
        std::cout << "IMPOSSIBLE TO MULTIPLY!!! YOU WILL GET [C] MATRIX BACK\n";
        return C;
    }
    C.m = A.m;
    C.n = B.n;
    for (int i = 0; i < C.m; i++){
        for (int j = 0; j < C.n; j++){
            C.Arr[i][j] = 0.0;
            for (int k = 0; k < B.m; k++)
                C.Arr[i][j] += A.Arr[i][k] * B.Arr[k][j];

        }
    }
    return C;
}

matrix transp (matrix New_m, matrix A){
    if (New_m.m != A.n || New_m.n != A.m){
        std::cout << "IMPOSSIBLE TO TRANSP! YOU WILL GET YOUR MATRIX BACK\n";
        return New_m;
    }

    for (int i = 0; i < New_m.n; i++)
        for (int j = 0; j < New_m.m; j++)
            New_m.Arr[i][j] = A.Arr[j][i];


    return New_m;
}
matrix copy_matrix(matrix new_matrix, matrix orig_matrix){
    if(new_matrix.m != orig_matrix.m || new_matrix.n != orig_matrix.n){
        std::cout << "NOT THE SAME MATRIXSES. NO CHANGES\n";
        return new_matrix;
    }
    for (int i = 0; i < new_matrix.m; i++)
        for (int j = 0; j < new_matrix.n; j++)
            new_matrix.Arr[i][j] = orig_matrix.Arr[i][j];
    return new_matrix;
}
matrix init(matrix A, int m, int n){
    A.m = m;
    A.n = n;

    A.Arr = new double*[A.m];
    for (int i = 0; i < A.m; i++){
        A.Arr[i] = new double [A.n];
        for (int j = 0; j < A.n; j++)
            A.Arr[i][j] = 0;
    }
    return A;
}
void delete_matrix(matrix A){
    for (int i = 0; i < A.m; i++)
        delete [] A.Arr[i];
    delete []A.Arr;
}
matrix holec(matrix L, matrix A){
    if(A.m != A.n || L.m != A.n){
        std::cout << "IMPOSSIBLE. [A] OR [L] ARE NOT SQUART. [L] NOW EQUAL ZERO.\n";
        zero_arr(L);
        return L;
    }
    //int orient = arr_orient(A);
    int orient = 1;
    if (orient <= 0){
        std::cout << "IMPOSSIBLE. NEGATIVE ORIENTATION. [L] NOW EQUAL ZERO.\n";
        zero_arr(L);
        return L;
    }
    double s;
    for (int j = 0; j < A.n; j++){
        for (int i = j; i < A.n; i++){
            s = 0;
            if (i == j){
                for(int k = 0; k < j; k++)
                    s += L.Arr[j][k]*L.Arr[i][k];
                if (A.Arr[j][i] - s <= 0){
                    std::cout << "IMPOSSIBLE. NEGATIVE ORIENTATION. [L] NOW EQUAL ZERO.\n";
                    zero_arr(L);
                    return L;
                }
                L.Arr[i][j] = sqrt(A.Arr[j][i] - s);
                //TESTER//std::cout << "[" << i << "][" << j << "]:" << A.Arr[i][j] << "\n";
                continue;
            }
            for(int k = 0; k < j; k++)
                s += L.Arr[j][k]*L.Arr[i][k];
            if (A.Arr[j][j] == 0){
                    std::cout << "IMPOSSIBLE. NEGATIVE ORIENTATION. [L] NOW EQUAL ZERO.\n";
                    zero_arr(L);
                    return L;
                }
            L.Arr[i][j] = (A.Arr[j][i] - s)/L.Arr[j][j];
        }
    }
    return L;
}
void zero_arr(matrix A){
    for (int i = 0; i < A.m; i++){
        for (int j = 0; j < A.n; j++)
            A.Arr[i][j] = 0;
    }
}
void print_arr(matrix A){
    for (int i = 0; i < A.m; i++){
        for (int j = 0; j < A.n; j++)
            std::cout << A.Arr[i][j] << "\t";
        std::cout << std::endl;
    }
}
