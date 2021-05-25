#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;


template <class type>
class matrix
{
protected: /// main structure {{  item[n][m]  }}
    type **item;// Двойной указатель для создания
    int m;// Сколько столбцов в матрице
    int n;// Сколько строк в матрице
    void create() // Выделяем память для нашего объекта
    {
        if (n > 0)
            item = new type*[n];
        else
            item = NULL;
        for(int i = 0; i < n; i++)
            item[i] = new type[m];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                item[i][j] = 0;
    }
public: ///constructors and destructor
    matrix<type>();// Создаем матрицу с нулевым размером
    matrix<type>(int nn, int mm);//Создаем матрицу произвольного размера
    matrix<type>(int nn);//Создаем квадратную матрицу
    matrix<type>(const matrix &rhs);
    ~matrix<type>();//Уничтожаем матрицу чтобы освободить память
public: ///Math matrix functions
    ///FIND MAX ELEMENT
    int indexMaxFromColumn(int j, int start);//Возвращает индекс наибольшего числа в столбце
    int indexMaxFromRow(int i, int start);//Возвращает индекс наибольшего числа в строке
    ///SWAP ROWS AND COLUMNS
    void swapRows(int i, int j);//Меняем местами строки
    void swapColumns(int i, int j);//Меняем местами столбцы
    ///MULTIPLY ROWS AND COLUMNS WITH SOME ELEMENTS
    void multRow(int row, type coeff);//Умножаем строку на число
    void multColumn(int col, type coeff);//Умножаем столбец на число
    ///DIVIDE ROWS AND COLUMNS WITH SOME ELEMENTS
    void divRow(int row, type coeff);//Делим строку на число
    void divColumn(int col, type coeff);//Делим строку на число
    ///ADD ROWS AND COLUMNS 'I' WITH OTHER ROW AND COLUMN 'J'
    void addRowToRow(int i, int j);//Добавляем к строке i строку j
    void addColumnToColumn(int i, int j);//Добавляем к столбцу i строку j
    void addRowToRowWithCoeff(int i, int j, type coeff);//Добавляем к строке i строку j умноженную на коэффициент
    void addColumnToColumnWithCoeff(int i, int j, type coeff);//Добавляем к столбцу i строку j умноженную на коэффициент
    ///SUBSTRACT ROWS AND COLUMNS 'I' WITH OTHER ROW AND COLUMN 'J'
    void subRowToRow(int i, int j);// Вычитаем из iй строки строку j
    void subColumnToColumn(int i, int j);// Вычитаем из iго столбца jй столбец
    void subRowToRowWithCoeff(int i, int j, type coeff);// Вычитаем из iй строки строку j умноженную на кожффициент
    void subColumnToColumnWithCoeff(int i, int j, type coeff);// Вычитаем из iго столбца jй столбец умноженный на коэффициент
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
    void itemFill(type value);//Все элементы матрицы равны value
    void randFill(type min, type max);// Все элементы в размере от 0 до 10
    void input();// ВВодим вручную матрицу
    void print();// Печатаем матрицу
    int  getRow() const;//Выводим сколько строк в матрице
    int  getColumn() const;//Выводим сколько столбцов в матрице
    type getItem(int i, int j);//Выдает элемент по индексу
public: /// operators
    template <class x> friend matrix<x>  operator+  (matrix<x> &a, matrix<x> &b);
    template <class x> friend matrix<x>  operator-  (matrix<x> &a, matrix<x> &b);
    template <class x> friend matrix<x>  operator*  (matrix<x> &a, matrix<x> &b);
    template <class x> friend matrix<x>  operator*  (matrix<x> &b, x a);
    template <class x> friend matrix<x>  operator*  ( x a, matrix<x> &b);
                    const matrix<type>  &operator=  (const matrix &rhs);
    template <class x> friend ostream   &operator<< (ostream &, const matrix<x> &);
    template <class x> friend istream   &operator>> (istream &, matrix<x> &);
protected: /// Special functions to change rows and columns
    type gcf(type a, type b);//Возвращает НОК двух чисел
    type gcf_allRow(int i);//Возвращает НОК всей строки
    type gcf_allCol(int j);//Возвращает НОК всего столбца
};
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////CONSTRUCTORS AND DESTRUCTORS//////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class type> matrix<type>:: matrix()
{
    n = 0;
    m = 0;
    item = NULL;
}
template <class type> matrix<type>:: matrix(int nn, int mm)
{
    n = nn;
    m = mm;
    create();
}
template <class type> matrix<type>:: matrix(int nn)
{
    n = nn;
    m = nn;
    create();
}
template <class type> matrix<type>:: matrix(const matrix<type> &rhs)
{
    n = rhs.n;
    m = rhs.m;
    create();
    for (int i = 0; i < n; i++)
        for ( int j = 0; j < m; j++)
            item[i][j] = rhs.item[i][j];
}
template <class type> matrix<type>:: ~matrix()
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
template <class type> int  matrix<type>:: indexMaxFromColumn(int j, int start)
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
template <class type> int  matrix<type>:: indexMaxFromRow(int i, int start)
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
template <class type> void matrix<type>:: swapRows(int i, int j)
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
template <class type> void matrix<type>:: swapColumns(int i, int j)
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
template <class type> void matrix<type>:: multRow(int row, type coeff)
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
template <class type> void matrix<type>:: multColumn(int col, type coeff)
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
template <class type> void matrix<type>:: divRow(int row, type coeff)
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
template <class type> void matrix<type>:: divColumn(int col, type coeff)
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
template <class type> void matrix<type>:: addRowToRow(int i, int j)
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
template <class type> void matrix<type>:: addColumnToColumn(int i, int j)
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
template <class type> void matrix<type>:: addRowToRowWithCoeff(int i, int j, type coeff)
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
template <class type> void matrix<type>:: addColumnToColumnWithCoeff(int i, int j, type coeff)
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
template <class type> void matrix<type>:: subRowToRow(int i, int j)
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
template <class type> void matrix<type>:: subColumnToColumn(int i, int j)
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
template <class type> void matrix<type>:: subRowToRowWithCoeff(int i, int j, type coeff)
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
template <class type> void matrix<type>:: subColumnToColumnWithCoeff(int i, int j, type coeff)
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
template <class type> void matrix<type>:: gaussSimpleAnyTypeUProw(bool showMatrixChange)
{
    type item_a_a, item_b_a;
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
template <class type> void matrix<type>:: makeSystemLinearEquationsAnswers(bool showMatrixChange)
{
    if (n + 1 == m)
    {
            if (showMatrixChange == true) cout << "DOING GAUSS" << endl;
        gaussSimpleAnyTypeUProw(showMatrixChange);
            if (showMatrixChange == true){
                print();
                cout << "#########################################################################" << endl;
            }
        type item_a_b, item_b_b;
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
template <class type> void matrix<type>:: gaussSimpleAnyTypeDOWNcolumn(bool showMatrixChange)
{
    matrix <type> a(n,m);
    a = *this;
    a.transpose();
    a.gaussSimpleAnyTypeUProw(showMatrixChange);
    a.transpose();
    *this = a;
    a.destroyMatrix();
}
template <class type> long double matrix<type>:: detGaussChangeRow(bool showMatrixChange)
{
        long double det = 1.0;
        type item_a_a, item_b_a, gcf_allRow_a, gcf_allRow_b;
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
template <class type> void matrix<type>:: transpose()
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
template <class type> void matrix<type>:: destroyMatrix()
{
    for (int i = 0; i < n; i++)
        delete [] item[i];
    delete[] item;
    m = 0;
    n = 0;
    item = NULL;
}
template <class type> void matrix<type>:: itemFill(type value)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            item[i][j] = value;
}
template <class type> void matrix<type>:: randFill(type min, type max)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            item[i][j] = (type)(rand()%max)+min;
}
template <class type> void matrix<type>:: input()
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
template <class type> void matrix<type>:: print()
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
template <class type> int matrix<type>::  getRow() const
{
    return n;
}
template <class type> int matrix<type>::  getColumn() const
{
    return m;
}
template <class type> type matrix<type>:: getItem(int i, int j)
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
template <class type>       matrix<type> operator+ (matrix<type> &a, matrix<type> &b)
{
    if ((a.m != b.m)||(a.n != b.n))
    {
        cout << "WRONG SIZE IN + OPERATOR";
        exit(1);
    }
    matrix<type> tmp(a.n, a.m);
    for(int i = 0; i < tmp.n; i++)
        for(int j = 0; j < tmp.m; j++)
            tmp.item[i][j] = a.item[i][j] + b.item[i][j];
    return tmp;
}
template <class type>       matrix<type> operator- (matrix<type> &a, matrix<type> &b)
{
    if ((a.m != b.m)||(a.n != b.n))
    {
        cout << "WRONG SIZE IN - OPERATOR";
        exit(1);
    }
    matrix<type> tmp(a.n, a.m);
    for(int i = 0; i < tmp.n; i++)
        for(int j = 0; j < tmp.m; j++)
            tmp.item[i][j] = a.item[i][j] - b.item[i][j];
    return tmp;
}
template <class type>       matrix<type> operator* (matrix<type> &a, matrix<type> &b)
{
    if (a.m != b.n)
    {
        cout << "ERROR WITH * OPERATOR";
        exit(1);
    }
    int i, j, k;
    matrix<type> ans(a.n, b.m);
    for (i = 0; i < a.n; i++)
        for (j = 0; j < b.m; j++)
        {
            ans.item[i][j] = 0;
            for (k = 0; k < a.m; k++)
                ans.item[i][j] += a.item[i][k] * b.item[k][j];
        }
    return ans;
}
template <class type>       matrix<type> operator* (type a, matrix<type> &b)
{
    matrix<type> ans(b.n, b.m);
    for (int i = 0; i < b.n; i++)
        for (int j = 0; j < b.m; j++)
        {
            ans.item[i][j] = a * b.item[i][j];
        }
    return ans;
}
template <class type>       matrix<type> operator* ( matrix<type> &b, type a)
{
    matrix<type> ans(b.n, b.m);
    for (int i = 0; i < b.n; i++)
        for (int j = 0; j < b.m; j++)
        {
            ans.item[i][j] = a * b.item[i][j];
        }
    return ans;
}
template <class type>       ostream     &operator<< (ostream &os, const matrix<type> &obj)
{
    for(int i = 0; i < obj.getLine(); i++)
    {
        for(int j = 0; j < obj.getColumn(); j++)
        {
            os << setw(4) << obj.matr[i][j];
        }
        os << endl;
    }
    return os;
}
template <class type>       istream     &operator>> (istream& is, matrix<type>& obj)
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
template <class type> const matrix<type>& matrix<type>:: operator=(const matrix &rhs)
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
template <class type> type matrix<type>:: gcf(type a, type b)
{
    if (a % b == 0)
        return abs(b);
    else
        return gcf(b, a % b);
}
template <class type> type matrix<type>:: gcf_allRow(int i)
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
    type M = item[i][0];
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
template <class type> type matrix<type>:: gcf_allCol(int j)
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
    type M = item[0][j];
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

































template <class type>
class matrixWithLU:public matrix<type>{
public:///Constructors and destructor
    matrixWithLU(){
        matrix<type>::n = 0;
        matrix<type>::m = 0;
        matrix<type>::item = NULL;
    }
    matrixWithLU(int nn, int mm){
        matrix<type>::n = nn;
        matrix<type>::m = mm;
        matrix<type>::create();
    }
    matrixWithLU(int nn){
        matrix<type>::n = nn;
        matrix<type>::m = nn;
        matrix<type>::create();
    }
    matrixWithLU(const matrixWithLU<type> &rhs){
        matrix<type>::n = rhs.n;
        matrix<type>::m = rhs.m;
        matrix<type>::create();
        for (int i = 0; i < matrix<type>::n; i++)
            for ( int j = 0; j < matrix<type>::m; j++)
                matrix<type>::item[i][j] = rhs.item[i][j];
    }
    ~matrixWithLU(){}
public:///LU, inverse, solving equations
    void LUdecomposition(const matrixWithLU <type>&L,const  matrixWithLU <type>&U, bool showMatrixChange);
    void Inverse(bool showMatrixChange);
    void findMatrixInAXB (const matrixWithLU <type>&A,const  matrixWithLU <type>&B, bool showMatrixChange);//AX = B
};
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////LU, INVERSE, SOLVING EQUATIONS//////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class type> void   matrixWithLU<type>::  LUdecomposition(const matrixWithLU <type>&L,const matrixWithLU <type>&U, bool showMatrixChange)
{
    /// if matrices are not unacceptable
    if (this->n != this->m || this->n != L.m || this->m != U.n) return ;
    if (L.m != L.n || U.m != U.n || L.m != U.n || U.m != L.n) return;
    /// define new matrix for work
    int size = L.n;
    matrixWithLU <type> tempM (size, 2*size);
    /// creating this matrix AI to make it after UL
    for (int a = 0; a < size; a++){
        for (int b = 0; b < 2*size; b++){
            if (b < size){
                tempM.item[a][b] = this->item[a][b];
                continue;
            }
            if (b >= size && a + size == b){
                tempM.item[a][b] = 1;
                continue;
            }
            if (b > size && a + size != b){
                tempM.item[a][b] = 0;
                continue;
            }
        }
    }
    ///doing gauss UP
    tempM.gaussSimpleAnyTypeUProw(showMatrixChange);
    ///write result in L and U matrices
    for (int a = 0; a < size; a++){
        for (int b = 0; b < 2*size; b++){
            if (b < size){
                U.item[a][b] = tempM.item[a][b];
                continue;
            }
            if (b >= size){
                L.item[a][b - size] = tempM.item[a][b];
                continue;
            }
        }
    }
}
template <class type> void   matrixWithLU<type>::  Inverse(bool showMatrixChange){
    /// if matrices are not unacceptable
    if (this->m != this->n) return;
    int size = this->n;
    matrixWithLU <type> tempM (size, 2*size);

    for (int a = 0; a < size; a++){
        for (int b = 0; b < 2*size; b++){
            if (b < size){
                tempM.item[a][b] = this->item[a][b];
                continue;
            }
            if (b >= size && a + size == b){
                tempM.item[a][b] = 1;
                continue;
            }
            if (b >= size && a + size != b){
                tempM.item[a][b] = 0;
                continue;
            }
        }
    }
    tempM.gaussSimpleAnyTypeUProw(showMatrixChange);
    type item_a_a, item_b_a;
    for (int a = size; a >= 1; a--){
        for (int b = a - 1; b >= 1; b--){

            if (tempM.item[a - 1][a - 1] == 0)
                tempM.swapRows(a,b);
            if (tempM.item[b - 1][a - 1] == 0)
                continue;

            item_a_a = tempM.item[a - 1][a - 1];
            item_b_a = tempM.item[b - 1][a - 1];

            tempM.multRow(a,item_b_a);
            if (showMatrixChange) tempM.print();
            tempM.multRow(b,item_a_a);
            if (showMatrixChange) tempM.print();
            tempM.subRowToRow(b,a);
            if (showMatrixChange) tempM.print();
            tempM.divRow(b, tempM.gcf_allRow(b));
            if (showMatrixChange) tempM.print();
            tempM.divRow(a, tempM.gcf_allRow(a));
            if (showMatrixChange) tempM.print();
        }
    }
    for (int a = 0; a < size; a++)
        for (int b = 0; b < size; b++)
            this->item[a][b] = tempM.item[a][b+size];
    *this = tempM;
}
template <class type> void   matrixWithLU<type>::  findMatrixInAXB (const matrixWithLU <type>&A,const  matrixWithLU <type>&B, bool showMatrixChange)
{
    if (this->n != this->m || this->n != B.m || this->m != A.n) return ;
    if (A.n != A.m || B.n != B.m || A.n != B.m || B.n != A.m) return ;
    matrixWithLU <type> tempM(A.n,2*A.n);
    int size = A.n;

    for (int a = 0; a < size; a++){
        for (int b = 0; b < 2*size; b++){
            if (b < size){
                tempM.item[a][b] = A.item[a][b];
                continue;
            }
            if (b >= size ){
                tempM.item[a][b] = B.item[a][b - size];
                continue;
            }
        }
    }

    tempM.gaussSimpleAnyTypeUProw(showMatrixChange);
    type item_a_a, item_b_a;
    for (int a = size; a >= 1; a--){
        for (int b = a - 1; b >= 1; b--){

            if (tempM.item[a - 1][a - 1] == 0)
                tempM.swapRows(a,b);
            if (tempM.item[b - 1][a - 1] == 0)
                continue;

            item_a_a = tempM.item[a - 1][a - 1];
            item_b_a = tempM.item[b - 1][a - 1];

            tempM.multRow(a,item_b_a);
            if (showMatrixChange) tempM.print();
            tempM.multRow(b,item_a_a);
            if (showMatrixChange) tempM.print();
            tempM.subRowToRow(b,a);
            if (showMatrixChange) tempM.print();
            tempM.divRow(b, tempM.gcf_allRow(b));
            if (showMatrixChange) tempM.print();
            tempM.divRow(a, tempM.gcf_allRow(a));
            if (showMatrixChange) tempM.print();
        }
    }
    *this = tempM;
}
int main()
{
    int num = 5;



    matrixWithLU <int> A(num);

    matrixWithLU <int> B(num);

    matrixWithLU <int> X(num);
    X.randFill(1,10);
    X.print();
    X.LUdecomposition(A,B,false);
    A.print();
    B.print();
    X.print();
    return 0;
}
