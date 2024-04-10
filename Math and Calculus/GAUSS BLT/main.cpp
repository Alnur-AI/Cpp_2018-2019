#include <iostream>
#include <cstdlib>
int**init(int **M, int n){
    M = new int*[n];
    for (int i = 0; i < n; i++)
        M[i] = new int [n + 1];
    return M;
}
void init_A(int **A, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n + 1; j++){
            A[i][j] = rand()%10;
        }
   }
}
void printArr(int **M, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            std::cout << M[i][j] << "\t";

        std::cout << "||| " << M[i][j] << "\t";

        std::cout << std::endl;
    }
    std::cout << std::endl;
}
void gauss_up(int **A, int n){
    ///1 make max triagle up
    for (int j = 0; j < n; j++){
        for (int i = n - 1; i > 0; i--){
            if (A[i][j] == 0){

            }
        }
    }
}
void gauss_down(int **A, int n){

}
int gcd(unsigned int n1, unsigned int n2){

	if(n1 == 0 || n2 == 0) return 0;
	if(n1 == n2) return n1;
	if(n1 >= n2){
		return gcd(n1 - n2, n2);
	}
	else{
		return gcd(n1, n2 - n1);
	}
}
int main()
{
    int n;
    std::cout << "Size: ";
    std::cin >> n;
    std::cout << std::endl;

    int **A;
    A = init(A, n);
    init_A(A, n);

    gauss_up(A,n);
    gauss_down(A,n);
    printArr(A, n);
    std::cout << gcd(10,20);


    return 0;
}
