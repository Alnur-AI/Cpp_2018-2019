#include <iostream>
#include <cstdlib>
const int n = 5;

class Ratio{

	friend void compare (Ratio &, Ratio &);
	friend ostream & print_ratio (ostream &, Ratio &);
	friend int gcd (unsigned int, unsigned int);

	public:
		Ratio(int _num = 0, int _denum = 1)
		:num{_num}, denum{_denum}
		{
			if( num * denum != 0)
			normalize();
		}

		Ratio operator + (Ratio r) {
			return Ratio(num*r.denum + r.num*denum, denum*r.denum);
		}
		Ratio operator - (Ratio r) {
            return Ratio(num*r.denum - r.num*denum, denum*r.denum);
		}

		Ratio operator * (Ratio r) {
			return Ratio(num * r.num, denum * r.denum);
		}

		Ratio operator / (Ratio r) {
			return Ratio(num * r.denum, denum * r.num);
		}

		double ToDouble () {
			return 1.0 * num / denum;
		}

	private:
		int num, denum, sgn = 1, gcd_num;
		void normalize() {

			if(num * denum < 0)
				sgn = -1;

			num = abs(num);
			denum = abs(denum);

			gcd_num = gcd(num, denum);

			num = sgn * num / gcd_num;
			denum = denum / gcd_num;

			return;
		}

};

ostream & print_cmp (ostream & os, Ratio & r1, Ratio & r2, char sgn) {
	print_ratio(os, r1);
	os << ' ' << sgn << ' ';
	return print_ratio(os, r2);
}

ostream & print_ratio (ostream & os, Ratio & r){
	return (os << ' ' << '(' << r.num << ',' << r.denum << ") ");
}


void compare (Ratio & r1, Ratio & r2) {

	if(((r1.denum < r2.denum) && (r1.num >= r2.num)) || ((r1.denum <= r2.denum) && (r1.num > r2.num))){
		print_cmp(cout, r1, r2, '>');
	}

	if(((r1.denum > r2.denum) && (r1.num <= r2.num)) || ((r1.denum >= r2.denum) && (r1.num < r2.num))){
		print_cmp(cout, r1, r2, '<');
	}

	if((r1.denum == r2.denum) && (r1.num == r2.num)){
		print_cmp(cout, r1, r2, '=');
	}

	return;
}

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
    for (int q = 0; q < n; q++){
        for (int k = 0; k < n; k++){
            if (k >= q){
                U[q][k] = A[q][k] - sum(0, q , q, k, L, U);
                if (U[q][q] == 0){
                    std::cout << "IMPOSSIBLE!!!" << std::endl;
                    exit(0);
                }
                L[k][q] = ( A[k][q] - sum(0, q , k, q, L, U) ) / U[q][q];

            }
        }
    }
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

void AxB(int **A, int **B, int **Res){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            Res[i][j] = sum(0,n,i,j,A,B);
        }
    }
}

int main(){
    srand(3);
    Ratio **A;
    Ratio **L;
    Ratio **U;

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

    Ratio **Check;
    Check = init(Check);
    AxB(L,U,Check);
    std::cout << "MATRIX LU" << std::endl;
    printArr(Check);
    return 0;
}
