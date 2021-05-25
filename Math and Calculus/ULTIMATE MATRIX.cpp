#include <iostream>
using namespace std;
// ‘ункци€ вывода матрицы
void PrintMatr(int **mas, int m) {
  int i, j;
  for (i = 0; i<m; i++) {
    for (j = 0; j<m; j++)
      cout << mas[i][j] << " ";
    cout << endl;
  }
}
// ѕолучение матрицы без i-й строки и j-го столбца
void GetMatr(int **mas, int **p, int i, int j, int m) {
  int ki, kj, di, dj;
  di = 0;
  for (ki = 0; ki<m Ч 1; ki++) { // проверка индекса строки
    if (ki == i) di = 1;
    dj = 0;
    for (kj = 0; kj<m Ч 1; kj++) { // проверка индекса столбца
      if (kj == j) dj = 1;
      p[ki][kj] = mas[ki + di][kj + dj];
    }
  }
}
// –екурсивное вычисление определител€
int Determinant(int **mas, int m) {
  int i, j, d, k, n;
  int **p;
  p = new int*[m];
  for (i = 0; i<m; i++)
    p[i] = new int[m];
  j = 0; d = 0;
  k = 1; //(-1) в степени i
  n = m Ч 1;
  if (m<1) cout << "ќпределитель вычислить невозможно!";
  if (m == 1) {
    d = mas[0][0];
    return(d);
  }
  if (m == 2) {
    d = mas[0][0] * mas[1][1] Ч (mas[1][0] * mas[0][1]);
    return(d);
  }
  if (m>2) {
    for (i = 0; i<m; i++) {
      GetMatr(mas, p, i, 0, m);
      cout << mas[i][j] << endl;
      PrintMatr(p, n);
      d = d + k * mas[i][0] * Determinant(p, n);
      k = -k;
    }
  }
  return(d);
}
// ќсновна€ функци€
int main() {
  int m, i, j, d;
  int **mas;
  system("chcp 1251");
  system("cls");
  cout << "¬ведите размерность квадратной матрицы: ";
  cin >> m;
  mas = new int*[m];
  for (i = 0; i<m; i++) {
    mas[i] = new int[m];
    for (j = 0; j<m; j++) {
      cout << "mas[" << i << "][" << j << "]= ";
      cin >> mas[i][j];
    }
  }
  PrintMatr(mas, m);
  d = Determinant(mas, m);
  cout << "ќпределитель матрицы равен " << d;
  cin.get(); cin.get();
  return 0;
} 
