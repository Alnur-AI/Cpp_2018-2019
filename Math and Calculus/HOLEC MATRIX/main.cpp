#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;


class matrix
{
protected: /// main structure {{  item[n][m]  }}
    double **item;// Двойной указатель для создания
    int m;// Сколько столбцов в матрице
    int n;// Сколько строк в матрице
    void create() // Выделяем память для нашего объекта
    {
        if (n > 0)
            item = new double*[n];
        else
            item = NULL;
        for(int i = 0; i < n; i++)
            item[i] = new double[m];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                item[i][j] = 0;
    }
public: ///constructors and destructor
    matrix();// Создаем матрицу с нулевым размером
    matrix(int nn, int mm);//Создаем матрицу произвольного размера
    matrix(int nn);//Создаем квадратную матрицу
    matrix(const matrix &rhs);
    ~matrix();//Уничтожаем матрицу чтобы освободить память
public: ///Math matrix functions
    ///FIND MAX ELEMENT
    int indexMaxFromColumn(int j, int start);//Возвращает индекс наибольшего числа в столбце
    int indexMaxFromRow(int i, int start);//Возвращает индекс наибольшего числа в строке
    ///SWAP ROWS AND COLUMNS
    void swapRows(int i, int j);//Меняем местами строки
    void swapColumns(int i, int j);//Меняем местами столбцы
    ///MULTIPLY ROWS AND COLUMNS WITH SOME ELEMENTS
    void multRow(int row, double coeff);//Умножаем строку на число
    void multColumn(int col, double coeff);//Умножаем столбец на число
    ///DIVIDE ROWS AND COLUMNS WITH SOME ELEMENTS
    void divRow(int row, double coeff);//Делим строку на число
    void divColumn(int col, double coeff);//Делим строку на число
    ///ADD ROWS AND COLUMNS 'I' WITH OTHER ROW AND COLUMN 'J'
    void addRowToRow(int i, int j);//Добавляем к строке i строку j
    void addColumnToColumn(int i, int j);//Добавляем к столбцу i строку j
    void addRowToRowWithCoeff(int i, int j, double coeff);//Добавляем к строке i строку j умноженную на коэффициент
    void addColumnToColumnWithCoeff(int i, int j, double coeff);//Добавляем к столбцу i строку j умноженную на коэффициент
    ///SUBSTRACT ROWS AND COLUMNS 'I' WITH OTHER ROW AND COLUMN 'J'
    void subRowToRow(int i, int j);// Вычитаем из iй строки строку j
    void subColumnToColumn(int i, int j);// Вычитаем из iго столбца jй столбец
    void subRowToRowWithCoeff(int i, int j, double coeff);// Вычитаем из iй строки строку j умноженную на кожффициент
    void subColumnToColumnWithCoeff(int i, int j, double coeff);// Вычитаем из iго столбца jй столбец умноженный на коэффициент
    ///GAUSS FUNCTIONS
    void gaussSimpleAnyTypeUProw(bool showMatrixChange);//Приводит матрицу к верхступенчатому виду модифицируя строки
    void gaussSimpleAnyTypeDOWNcolumn(bool showMatrixChange);//Приводит матрицу к нижнеступечатому виду модифицируя столбцы
    ///SYSTEM OF LINEAR EQUATIONS FUNCTIONS
    void makeSystemLinearEquationsAnswers(bool showMatrixChange);//Метод жордана-гаусса для нахождения СЛАУ
    ///FIND DETERMINANT
    long double detGaussChangeRow(bool showMatrixChange);//Найти определитель матрицы
    ///TRANSPOSING
    void transpose();//транспонирует матрицу
public: ///primary functions
    void destroyMatrix();//Уничтожить матрицу и сделать ее нулевого размера
    void itemFill(double value);//Все элементы матрицы равны value
    void randFill(double min, double max);// Все элементы в размере от 0 до 10
    void input();// ВВодим вручную матрицу
    void print();// Печатаем матрицу
    int  getRow() const;//Выводим сколько строк в матрице
    int  getColumn() const;//Выводим сколько столбцов в матрице
    double getItem(int i, int j);//Выдает элемент по индексу
public: /// operators
    friend matrix  operator+  (matrix &a, matrix &b);
    friend matrix  operator-  (matrix &a, matrix &b);
    friend matrix  operator*  (matrix &a, matrix &b);
    friend matrix  operator*  (matrix &b, double a);
    friend matrix  operator*  (double a, matrix &b);
    const matrix  &operator=  (const matrix &rhs);
    friend ostream   &operator<< (ostream &, const matrix &);
    friend istream   &operator>> (istream &, matrix &);
protected: /// Special functions to change rows and columns
    double gcf(double a, double b);//Возвращает НОК двух чисел
    double gcf_allRow(int i);//Возвращает НОК всей строки
    double gcf_allCol(int j);//Возвращает НОК всего столбца
};
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////CONSTRUCTORS AND DESTRUCTORS//////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
matrix:: matrix()
{
    n = 0;
    m = 0;
    item = NULL;
}
matrix:: matrix(int nn, int mm)
{
    n = nn;
    m = mm;
    create();
}
matrix:: matrix(int nn)
{
    n = nn;
    m = nn;
    create();
}
matrix:: matrix(const matrix &rhs)
{
    n = rhs.n;
    m = rhs.m;
    create();
    for (int i = 0; i < n; i++)
        for ( int j = 0; j < m; j++)
            item[i][j] = rhs.item[i][j];
}
matrix:: ~matrix()
{
    for (int i = 0; i < n; i++)
        delete [] item[i];
    delete[] item;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////MATH MATRIX FUNCTIONS/////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
int  matrix:: indexMaxFromColumn(int j, int start)
{
    if (j <= 0)
    {
        cout << "Columns IN indexMaxFromColumn are leas or equal zero";
        exit(1);
    }
    if (j > m)
    {
        cout << "Columns IN indexMaxFromColumn are bigger than n";
        exit(1);
    }
    j--;
    int ans = 1;
    for(int i = start; i < n; i++)
        if (item[ans][j] < item[i][j])
            ans = i;
    return ans;
}
int  matrix:: indexMaxFromRow(int i, int start)
{
    if (i <= 0)
    {
        cout << "ROWS IN indexMaxFromRow are leas or equal zero";
        exit(1);
    }
    if (i > n)
    {
        cout << "ROWS IN indexMaxFromRow are bigger than m";
        exit(1);
    }
    i--;
    int ans = 1;
    for(int j = start; j < m; j++)
        if (item[i][ans] < item[i][j])
            ans = i;
    return ans;
}
 void matrix:: swapRows(int i, int j)
{
    if (i <= 0 || j <= 0)
    {
        cout << "ROWS IN swapRows are leas or equal zero";
        exit(1);
    }
    if (i > n || j > n)
    {
        cout << "ROWS IN swapRows are bigger than m";
        exit(1);
    }
    i--;
    j--;
    int item_i_k;
    for (int k = 0; k < m; k++)
    {
        item_i_k = item[i][k];
        item[i][k] = item [j][k];
        item[j][k] = item_i_k;
    }
}
void matrix:: swapColumns(int i, int j)
{
    if (i <= 0 || j <= 0)
    {
        cout << "Columns IN swapColumns are leas or equal zero";
        exit(1);
    }
    if (i > m || j > m)
    {
        cout << "Columns IN swapColumns are bigger than n";
        exit(1);
    }
    i--;
    j--;
    int item_k_i;
    for (int k = 0; k < n; k++)
    {
        item_k_i = item[k][i];
        item[k][i] = item [k][j];
        item[k][j] = item_k_i;
    }
}
void matrix:: multRow(int row, double coeff)
{
    if (row <= 0)
    {
        cout << "ROWS IN multRow are leas or equal zero";
        exit(1);
    }
    if (row > n)
    {
        cout << "ROWS IN indexMaxFromRow are bigger than m";
        exit(1);
    }
    row--;
    for (int k = 0; k < m; k++)
        item[row][k] *= coeff;
}
void matrix:: multColumn(int col, double coeff)
{
    if (col <= 0)
    {
        cout << "Columns IN multColumn are leas or equal zero";
        exit(1);
    }
    if (col > m)
    {
        cout << "Columns IN multColumn are bigger than n";
        exit(1);
    }
    col--;
    for (int k = 0; k < n; k++)
        item[k][col] *= coeff;
}
void matrix:: divRow(int row, double coeff)
{
    if (row <= 0)
    {
        cout << "ROWS IN divRow are leas or equal zero";
        exit(1);
    }
    if (row > n)
    {
        cout << "ROWS IN divRow are bigger than m";
        exit(1);
    }
    row--;
    for (int k = 0; k < m; k++)
        item[row][k] /= coeff;
}
void matrix:: divColumn(int col, double coeff)
{
    if (col <= 0)
    {
        cout << "Columns IN divColumn are leas or equal zero";
        exit(1);
    }
    if (col > m)
    {
        cout << "Columns IN divColumn are bigger than n";
        exit(1);
    }
    col--;
    for (int k = 0; k < n; k++)
        item[k][col] /= coeff;
}
void matrix:: addRowToRow(int i, int j)
{
    if (i <= 0 || j <= 0)
    {
        cout << "ROWS IN addRowToRow are leas or equal zero";
        exit(1);
    }
    if (i > n || j > n)
    {
        cout << "ROWS IN addRowToRow are bigger than m";
        exit(1);
    }
    i--;
    j--;
    for (int k = 0; k < m; k++)
        item[i][k] += item[j][k];
}
void matrix:: addColumnToColumn(int i, int j)
{
    if (i <= 0 || j <= 0)
    {
        cout << "Columns IN addColumnToColumn are leas or equal zero";
        exit(1);
    }
    if (i > m || j > m)
    {
        cout << "Columns IN addColumnToColumn are bigger than n";
        exit(1);
    }
    i--;
    j--;
    for (int k = 0; k < n; k++)
        item[k][i] += item[k][j];
}
void matrix:: addRowToRowWithCoeff(int i, int j, double coeff)
{
    if (i <= 0 || j <= 0)
    {
        cout << "ROWS IN addRowToRowWithCoeff are leas or equal zero";
        exit(1);
    }
    if (i > n || j > n)
    {
        cout << "ROWS IN addRowToRowWithCoeff are bigger than m";
        exit(1);
    }
    i--;
    j--;
    for (int k = 0; k < m; k++)
        item[i][k] += (coeff*item[j][k]);
}
void matrix:: addColumnToColumnWithCoeff(int i, int j, double coeff)
{
    if (i <= 0 || j <= 0)
    {
        cout << "Columns IN addColumnToColumnWithCoeff are leas or equal zero";
        exit(1);
    }
    if (i > m || j > m)
    {
        cout << "Columns IN addColumnToColumnWithCoeff are bigger than n";
        exit(1);
    }
    i--;
    j--;
    for (int k = 0; k < n; k++)
        item[k][i] += (coeff*item[k][j]);
}
void matrix:: subRowToRow(int i, int j)
{
    if (i <= 0 || j <= 0)
    {
        cout << "ROWS IN subRowToRow are leas or equal zero";
        exit(1);
    }
    if (i > n || j > n)
    {
        cout << "ROWS IN subRowToRow are bigger than m";
        exit(1);
    }
    i--;
    j--;
    for (int k = 0; k < m; k++)
        item[i][k] -= item[j][k];
}
void matrix:: subColumnToColumn(int i, int j)
{
    if (i <= 0 || j <= 0)
    {
        cout << "Columns IN subColumnToColumn are leas or equal zero";
        exit(1);
    }
    if (i > m || j > m)
    {
        cout << "Columns IN subColumnToColumn are bigger than n";
        exit(1);
    }
    i--;
    j--;
    for (int k = 0; k < n; k++)
        item[k][i] -= item[k][j];
}
void matrix:: subRowToRowWithCoeff(int i, int j, double coeff)
{
    if (i <= 0 || j <= 0)
    {
        cout << "ROWS IN subRowToRowWithCoeff are leas or equal zero";
        exit(1);
    }
    if (i > n || j > n)
    {
        cout << "ROWS IN subRowToRowWithCoeff are bigger than m";
        exit(1);
    }
    i--;
    j--;
    for (int k = 0; k < m; k++)
        item[i][k] -= (coeff*item[j][k]);
}
void matrix:: subColumnToColumnWithCoeff(int i, int j, double coeff)
{
    if (i <= 0 || j <= 0)
    {
        cout << "Columns IN subColumnToColumnWithCoeff are leas or equal zero";
        exit(1);
    }
    if (i > m || j > m)
    {
        cout << "Columns IN subColumnToColumnWithCoeff are bigger than n";
        exit(1);
    }
    i--;
    j--;
    for (int k = 0; k < n; k++)
        item[k][i] -= (coeff*item[k][j]);
}
void matrix:: gaussSimpleAnyTypeUProw(bool showMatrixChange)
{
    double item_a_a, item_b_a;
    if (n <= m)
    {
        for (int a = 1; a <= m - 1; a++)
            for(int b = 1; b <= n; b++)
                if (b > a)
                {
                    //if (showMatrixChange == true) cout << "from row#" << b << " subtracting row#" << a << endl;
                    if (item[a - 1][a - 1] == 0)
                        swapRows(a,b);
                    if (item[b - 1][a - 1] == 0)
                        continue;

                    item_a_a = item[a - 1][a - 1];
                    item_b_a = item[b - 1][a - 1];

                    multRow(a, item_b_a);
                    if (showMatrixChange == true) print();
                    multRow(b, item_a_a);
                    if (showMatrixChange == true) print();

                    subRowToRow(b,a);
                    if (showMatrixChange == true) print();

                    divRow(a, gcf_allRow(a));
                    if (showMatrixChange == true) print();
                    divRow(b, gcf_allRow(b));
                    if (showMatrixChange == true) print();
                    if (showMatrixChange == true) cout << "-------------------------------------------------------" << endl;
                }
    }
    else
    {
        for (int a = 1; a <= n - 1; a++)
            for(int b = 1; b <= n; b++)
                if (b > a)
                {
                    if (item[a - 1][a - 1] == 0)
                        swapRows(a,b);
                    if (item[b - 1][a - 1] == 0)
                        continue;

                    item_a_a = item[a - 1][a - 1];
                    item_b_a = item[b - 1][a - 1];


                    multRow(a, item_b_a);
                    if (showMatrixChange == true) print();
                    multRow(b, item_a_a);
                    if (showMatrixChange == true) print();

                    subRowToRow(b, a);
                    if (showMatrixChange == true) print();

                    divRow(a, gcf_allRow(a));
                    if (showMatrixChange == true) print();
                    divRow(b, gcf_allRow(b));
                    if (showMatrixChange == true) print();
                    if (showMatrixChange == true) cout << "-------------------------------------------------------" << endl;
                }
    }
}
void matrix:: makeSystemLinearEquationsAnswers(bool showMatrixChange)
{
    if (n + 1 == m)
    {
            if (showMatrixChange == true) cout << "DOING GAUSS" << endl;
        gaussSimpleAnyTypeUProw(showMatrixChange);
            if (showMatrixChange == true){
                print();
                cout << "#########################################################################" << endl;
            }
        double item_a_b, item_b_b;
        for (int b = m - 1; b >= 1; b--){
            for (int a = b - 1; a >= 1; a--)
            {
                item_a_b = item[a - 1][b - 1];
                item_b_b = item[b - 1][b - 1];

                if (item_a_b == 0) break;
                if (item_b_b == 0) break;

                multRow(a, item_b_b);
                    if (showMatrixChange == true) print();
                multRow(b, item_a_b);
                    if (showMatrixChange == true) print();

                subRowToRow(a,b);
                    if (showMatrixChange == true) print();

                divRow(b, gcf_allRow(b));
                    if (showMatrixChange == true) print();
                divRow(a, gcf_allRow(a));
                    if (showMatrixChange == true) print();
                    if (showMatrixChange == true) cout << "-------------------------------------------------------" << endl;
            }
        }


        return;
    }
    else
    {
        cout << "Sorry, this matrix is not a type for solving system of linear equations" << endl;
        return;
    }
}
void matrix:: gaussSimpleAnyTypeDOWNcolumn(bool showMatrixChange)
{
    matrix a(n,m);
    a = *this;
    a.transpose();
    a.gaussSimpleAnyTypeUProw(showMatrixChange);
    a.transpose();
    *this = a;
}
long double matrix:: detGaussChangeRow(bool showMatrixChange)
{
        long double det = 1.0;
        double item_a_a, item_b_a, gcf_allRow_a, gcf_allRow_b;
        if (n == m){
            for (int a = 1; a <= m - 1; a++)
                for(int b = 1; b <= n; b++)
                    if (b > a)
                    {
                        //if (showMatrixChange == true) cout << "from row#" << b << " subtracting row#" << a << endl;
                        if (item[a - 1][a - 1] == 0){
                            swapRows(a,b);
                            det *= (long double)-1;
                            if (showMatrixChange)cout << "Now determinant is equal: " << det << endl;
                        }

                        if (item[b - 1][a - 1] == 0)
                            continue;

                        item_a_a = item[a - 1][a - 1];
                        item_b_a = item[b - 1][a - 1];
                        gcf_allRow_a = gcf_allRow(a);
                        gcf_allRow_b = gcf_allRow(b);

                        multRow(a, item_b_a);
                        if (showMatrixChange) print();
                        det /= (long double)item_b_a;
                        if (showMatrixChange) cout << "Now determinant is equal: " << det << endl;
                        multRow(b, item_a_a);
                        if (showMatrixChange) print();
                        det /= (long double)item_a_a;
                        if (showMatrixChange) cout << "Now determinant is equal: " << det << endl;


                        subRowToRow(b,a);
                        if (showMatrixChange) print();


                        divRow(a, gcf_allRow_a);
                        if (showMatrixChange) print();
                        det *= (long double)gcf_allRow_a;
                        if (showMatrixChange) cout << "Now determinant is equal: " << det << endl;
                        divRow(b, gcf_allRow_b);
                        if (showMatrixChange) print();
                        det *= (long double)gcf_allRow_b;
                        if (showMatrixChange) cout << "Now determinant is equal: " << det << endl;
                        if (showMatrixChange) cout << "-------------------------------------------------------" << endl;
                    }
            for (int k = 1; k <= n; k++)
                det *= (long double)item[k - 1][k - 1];
            if (showMatrixChange) cout << "Now determinant is equal: " << det << endl;
            return det;
        }
        else
        {
            cout << "It's not a square matrix. Now det = 0" << endl;
            return 0.0;
        }
}
void matrix:: transpose()
{
    matrix newObj(m,n);
    for(int i = 0; i < newObj.n; i++)
        for(int j = 0; j < newObj.m; j++)
            newObj.item[i][j] = item[j][i];
    destroyMatrix();
    *this = newObj;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////PRIMARY FUNCTIONS/////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
void matrix:: destroyMatrix()
{
    for (int i = 0; i < n; i++)
        delete [] item[i];
    delete[] item;
    m = 0;
    n = 0;
    item = NULL;
}
void matrix:: itemFill(double value)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            item[i][j] = value;
}
void matrix:: randFill(double min, double max)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            item[i][j] = (double)(rand()%(int)max)+min;
}
void matrix:: input()
{
    cout << "Fill the matrix: \n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            cout << "matrix[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> item[i][j];
            cout << endl;
        }
}
void matrix:: print()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout.width(14);
            cout << setprecision(2) << item[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
int matrix::  getRow() const
{
    return n;
}
int matrix::  getColumn() const
{
    return m;
}
double matrix:: getItem(int i, int j)
{
    return item[i - 1][j - 1];
}
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////OPERATORS///////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
matrix operator+ (matrix &a, matrix &b)
{
    if ((a.m != b.m)||(a.n != b.n))
    {
        cout << "WRONG SIZE IN + OPERATOR";
        exit(1);
    }
    matrix tmp(a.n, a.m);
    for(int i = 0; i < tmp.n; i++)
        for(int j = 0; j < tmp.m; j++)
            tmp.item[i][j] = a.item[i][j] + b.item[i][j];
    return tmp;
}
matrix operator- (matrix &a, matrix &b)
{
    if ((a.m != b.m)||(a.n != b.n))
    {
        cout << "WRONG SIZE IN - OPERATOR";
        exit(1);
    }
    matrix tmp(a.n, a.m);
    for(int i = 0; i < tmp.n; i++)
        for(int j = 0; j < tmp.m; j++)
            tmp.item[i][j] = a.item[i][j] - b.item[i][j];
    return tmp;
}
matrix operator* (matrix &a, matrix &b)
{
    if (a.m != b.n)
    {
        cout << "ERROR WITH * OPERATOR";
        exit(1);
    }
    int i, j, k;
    matrix ans(a.n, b.m);
    for (i = 0; i < a.n; i++)
        for (j = 0; j < b.m; j++)
        {
            ans.item[i][j] = 0;
            for (k = 0; k < a.m; k++)
                ans.item[i][j] += a.item[i][k] * b.item[k][j];
        }
    return ans;
}
matrix operator* (double a, matrix &b)
{
    matrix ans(b.n, b.m);
    for (int i = 0; i < b.n; i++)
        for (int j = 0; j < b.m; j++)
        {
            ans.item[i][j] = a * b.item[i][j];
        }
    return ans;
}
matrix operator* ( matrix &b, double a)
{
    matrix ans(b.n, b.m);
    for (int i = 0; i < b.n; i++)
        for (int j = 0; j < b.m; j++)
        {
            ans.item[i][j] = a * b.item[i][j];
        }
    return ans;
}
ostream     &operator<< (ostream &os, const matrix &obj)
{
    for(int i = 0; i < obj.getRow(); i++)
    {
        for(int j = 0; j < obj.getColumn(); j++)
        {
            os << setw(4) << obj.item[i][j];
        }
        os << endl;
    }
    return os;
}
istream     &operator>> (istream& is, matrix& obj)
{
    cout << "N x M: " << endl;
    is >> obj.n >> obj.m;
    obj.create();
    cout << "Fill the matrix: " << endl;
    for(int i = 0; i < obj.n; i++)
        for(int j = 0; j < obj.m; j++)
        {
            cout << "Element[" << i << "][" << j << "] = ";
            is >> obj.item[i][j];
            cout << endl;
        }
    return is;
}
const matrix & matrix:: operator=(const matrix &rhs)
{
    if (this != &rhs)
    {
        int i, j;
        if (n != rhs.n || m != rhs.m)
        {
            if (item != NULL)
            {
                for (int i = 0; i < n; i++)
                    delete [] item[i];
                delete[] item;
            }
            n = rhs.n;
            m = rhs.m;
            create();
        }
        for (i = 0; i < n; i++)
            for(j = 0; j < m; j++)
                item[i][j] = rhs.item[i][j];
    }
    return *this;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////GCF FUNCTIONS//////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
double matrix:: gcf(double a, double b)
{
    int int_a = (int)a;
    int int_b = (int)b;
    if (int_a % int_b == 0)
        return abs(int_b);
    else
        return gcf(int_b, int_a % int_b);
}
double matrix:: gcf_allRow(int i)
{
    if (i <= 0)
    {
        cout << "ROWS IN gcf_allRow are leas or equal zero";
        exit(1);
    }
    if (i > n)
    {
        cout << "ROWS IN gcf_allRow are bigger than m";
        exit(1);
    }
    i--;

    int zeroCount = 0;
    double M = item[i][0];
    for (int k = 1; k < m; k++)
    {
        if (item[i][k] == 0)
        {
            zeroCount++;
            continue;
        }
        M = gcf(M, item[i][k]);
    }
    if (zeroCount >= m - 1)
    {
        return 1;
    }
    return M;
}
double matrix:: gcf_allCol(int j)
{
    if (j <= 0)
    {
        cout << "Columns IN gcf_allCol are leas or equal zero";
        exit(1);
    }
    if (j > m)
    {
        cout << "Columns IN gcf_allCol are bigger than m";
        exit(1);
    }
    j--;

    int zeroCount = 0;
    double M = item[0][j];
    for (int k = 1; k < n; k++)
    {
        if (item[k][j] == 0)
        {
            zeroCount++;
            continue;
        }
        M = gcf(M, item[k][j]);
    }
    if (zeroCount >= n - 1)
    {
        return 1;
    }
    return M;
}






























































class matrixHOLEC:public matrix{
public:///Constructors and destructor
    matrixHOLEC(){
        matrix::n = 0;
        matrix::m = 0;
        matrix::item = NULL;
    }
    matrixHOLEC(int nn, int mm){
        matrix::n = nn;
        matrix::m = mm;
        matrix::create();
    }
    matrixHOLEC(int nn){
        matrix::n = nn;
        matrix::m = nn;
        matrix::create();
    }
    matrixHOLEC(const matrixHOLEC &rhs){
        matrix::n = rhs.n;
        matrix::m = rhs.m;
        matrix::create();
        for (int i = 0; i < matrix::n; i++)
            for ( int j = 0; j < matrix::m; j++)
                matrix::item[i][j] = rhs.item[i][j];
    }
    ~matrixHOLEC(){}
public:///holec
    void makeholec(const matrixHOLEC &L);
    void changeItem(int i, int j, double value){
        i--; j--;
        item[i][j] = value;
    }
};

void matrixHOLEC::makeholec(const matrixHOLEC &L){
    if(m != n || L.m != n){
        std::cout << "IMPOSSIBLE. [A] OR [L] ARE NOT SQUART. NO CHANGES.\n";
        return ;
    }
    double s;
    for (int j = 0; j < n; j++){
        for (int i = j; i < n; i++){
            s = 0;
            if (i == j){
                for(int k = 0; k < j; k++)
                    s += L.item[j][k]*L.item[i][k];
                if (item[j][i] - s <= 0){
                    std::cout << "IMPOSSIBLE. NEGATIVE ORIENTATION. NO CHANGES.\n";
                    return ;
                }
                L.item[i][j] = sqrt(item[j][i] - s);
                //TESTER//std::cout << "[" << i << "][" << j << "]:" << A.Arr[i][j] << "\n";
                continue;
            }
            for(int k = 0; k < j; k++)
                s += L.item[j][k]*L.item[i][k];
            if (item[j][j] == 0){
                    std::cout << "IMPOSSIBLE. NEGATIVE ORIENTATION. [L] NOW EQUAL ZERO.\n";
                    return ;
            }
            L.item[i][j] = (item[j][i] - s)/L.item[j][j];
        }
    }
    return ;
}




int main()
{
    matrixHOLEC A(3), L(3);

    A.changeItem(1,1, 81.0);     A.changeItem(1,2, -45.0);   A.changeItem(1,3, 45.0);
    A.changeItem(2,1, -45.0);    A.changeItem(2,2, 50.0);    A.changeItem(2,3, -15.0);
    A.changeItem(3,1, 45.0);     A.changeItem(3,2, -15.0);   A.changeItem(3,3, 38.0);

    A.makeholec(L);
    A.print();
    L.print();
    return 0;
}
