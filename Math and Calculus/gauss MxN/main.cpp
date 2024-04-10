#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

template <class type>
class Matrix{
	template <class x> friend ostream & operator << (ostream &, const Matrix <x> &);//cout output
	template <class x> friend istream & operator >> (istream &, Matrix <x> &);//cin input

	private:
        type **matr;
        int mm;
        int nn;

        void create(){//выделение памяти под матрицу
            if (nn > 0)
                matr = new type*[nn];
            else
                matr = NULL;
            for(int i = 0; i < mm; i++)
                matr[i] = new type[mm];
        }


	public:
        Matrix<type>();//конструктор без параметров
        Matrix<type>(int n, int m);//конструктор для матрицы n x m
        Matrix<type>(int n);//конструктор для квадратной матрицы порядка n
        Matrix<type>(int n, int m, const type&a);//конструктор для матрицы nxm с заполнением одним элементом
        Matrix<type>(const Matrix &rhs);//конструктор копирования
        ~Matrix<type>();//деструктор

        void fillMatrix();//заполнение матрицы с клавы
        void showMatrix();//вывод матрицы на экран
        int getLine() const;//получить количество строк
        int getColumn() const;//получить количество столбцов
        int maxFromColumn(int j);//индекс максимального элемента в столбце j
        type& getElement(int i, int j);//получение элемента [i][j]
        inline type* operator[](const int i);//перегруженный оператор индексирования
        const Matrix<type>& operator=(const Matrix &rhs);//перегруженный оператор присваивания
        Matrix<type> operator*(const Matrix &rhs);//перегруженный оператор умножения
        void gauss();//вывод решения СЛАУ методом Гаусса

};

int main(void){
	Matrix <double> r2;
	cin >> r2;
	cout << r2;
	r2.gauss();
	cout << endl << r2 ;
	return 0;
}


template <class type>
ostream &operator << (ostream &os, const Matrix<type> &obj){
	for(int i = 0; i < obj.getLine(); i++){
		for(int j = 0; j < obj.getColumn(); j++){
			os << setw(4) << obj.matr[i][j];
		}
		os << endl;
	}
	return os;
}

template <class type>
istream& operator>> (istream& is, Matrix<type>& obj){
	cout << "Input N x M: " << endl;
	is >> obj.nn >> obj.mm;
	obj.create();
	cout << "Fill it: " << endl;
	for(int i = 0; i < obj.nn; i++)
		for(int j = 0; j < obj.mm; j++){
			cout << "matrix[" << i << "][" << j << "] = ";
			is >> obj.matr[i][j];
			cout << endl;
		}
	return is;
}

template <class type>
Matrix<type>:: Matrix(){
	nn = 0;
	mm = 0;
	matr = NULL;
}

template <class type>
Matrix<type>:: Matrix(int n, int m){
	nn = n;
	mm = m;
	create();
}


template <class type>
Matrix<type>:: Matrix(int n){
	nn = n;
	mm = n;
	create();
}

template <class type>
Matrix<type>:: Matrix(int n, int m, const type&a){
	nn = n;
	mm = m;
	create();
	for (int i = 0; i < nn; i++)
		for (int j = 0; j < mm; j++)
			matr[i][j] = a;
}

template <class type>
Matrix<type>:: Matrix(const Matrix<type> &rhs){
	nn = rhs.nn;
	mm = rhs.mm;
	create();
	for (int i = 0; i < nn; i++)
		for ( int j = 0; j < mm; j++)
			matr[i][j] = rhs.matr[i][j];
}

template <class type>
Matrix<type>:: ~Matrix(){
	for (int i = 0; i < nn; i++)
		delete [] matr[i];
	delete[] matr;
	cout << "Matrix deleted" << endl;
}

template <class type>
const Matrix<type>& Matrix<type>:: operator=(const Matrix &rhs){
	if (this != &rhs){
		int i, j;
		if (nn != rhs.nn || mm != rhs.mm){
			if (matr != NULL){
				for (int i = 0; i < nn; i++)
					delete [] matr[i];
				delete[] matr;
			}
			nn = rhs.nn;
			mm = rhs.mm;
			create();
		}
		for (i = 0; i < nn; i++)
			for(j = 0; j < mm; j++)
				matr[i][j] = rhs.matr[i][j];
	}
	return *this;
}

template <class type>
Matrix<type> Matrix <type>:: operator*(const Matrix &rhs){
	if (mm != rhs.nn){
		cout << "ERROR";
		throw("3");
		//return NULL;
	}
	int i, j, k;
	Matrix<type> ans(nn, rhs.mm);
	for (i = 0; i < nn; i++)
		for (j = 0; j < rhs.mm; j++){
			ans.matr[i][j] = 0;
			for (k = 0; k < mm; k++)
				ans.matr[i][j] += matr[i][k] * rhs.matr[k][j];
		}
		return ans;
}

template <class type>
inline type* Matrix<type>:: operator[](const int i){
	if (i<0 || i >= mm)
		throw("FATAL ERROR: Matrix subscript out of bounds");
	return matr[i];
}

template <class type>
void Matrix<type>:: showMatrix(){
	for(int i = 0; i < nn; i++){
		for(int j = 0; j < mm; j++){
			cout.width(4);
			cout << setprecision(2) << matr[i][j];
		}
		cout << endl;
	}
}

template <class type>
int Matrix<type>:: getLine() const{
	return nn;
}

template <class type>
int Matrix<type>:: getColumn() const{
	return mm;
}

template <class type>
void Matrix<type>:: fillMatrix(){
	cout << "Заполните матрицу: ";
	for(int i = 0; i < nn; i++)
		for(int j = 0; j < mm; j++)
		{
			cout << "matrix[" << i << "][" << j << "] = ";
			cin >> matr[i][j];
			cout << endl;
		}
}

template <class type>
int Matrix<type>:: maxFromColumn(int j){
	int ans = 0;
	for(int i = 1; i < nn; i++)
	{
		if (matr[ans][j] < matr[i][j])
			ans = i;
	}
	return ans;
}

template <class type>
void Matrix<type>:: gauss(){
	int i, k, j;
	type *b, *x;
	b = new type[nn];
	x = new type[nn];
	cout << "Input column with undependent elements b: ";
	for (i = 0; i < nn; i++){
		cin >> b[i];
		x[i] = 0;
	}
	for (i = 0; i < nn; i++)
		cout << b[i] << " ";
	cout << endl;
	cout << *this;
	for (i = 0; i < nn; i++)
		cout << b[i] << " ";
	for (k = 0; k < nn; k++){
		for (i = k + 1; i < nn; i++){
			if (matr[k][k]==0){
				cout << "\n Нет решения.\n";
				return;
			}
			float M = matr[i][k] / matr[k][k];
			for (j = k; j < nn; j++){
				matr[i][j] -= M * matr[k][j];
			}
			b[i] -= M * b[k];
       }
	}
	for (i = nn - 1; i >= 0; i--){
		float s = 0;
		for(j = i; j < nn; j++){
			s = s + matr[i][j] * x[j];
		}
       x[i] = (b[i] - s) / matr[i][i];
   }

	for (i = 0; i < nn; i++)
		cout <<" "<< x[i] << ":";
	delete [] x;
	delete [] b;
}




/*
#include <iostream>
#include <cstdlib>
struct matrix{
    double **Arr;
    int m;
    int n;
};

double **init(matrix A);
void gauss_up(matrix A, int till_row, int till_col);
void gauss_down(matrix A, int till_row, int till_col);
void print_arr(matrix A);

int main(){
    matrix B;
    B.m = 6;
    B.n = 12;
    B.Arr = init(B);
    print_arr(B);
    return 0;
}

double **init(matrix A){
    A.Arr = new double*[A.m];
    for (int i = 0; i < A.m; i++){
        A.Arr[i] = new double [A.n];
        for (int j = 0; j < A.n; j++)
            A.Arr[i][j] = rand()%10;
    }
    return A.Arr;
}
void print_arr(matrix A){
    for (int i = 0; i < A.m; i++){
        for (int j = 0; j < A.n; j++)
            std::cout << A.Arr[i][j] << "\t";
        std::cout << std::endl;
    }
}

void gauss_up(matrix A, int till_row, int till_col){
    for (int j = 0; j < A.n; j++){
        for (int i = j; i < A.m; i++){
            if (A.Arr[j][j] == 0){

            }
        }
    }

}



*/
