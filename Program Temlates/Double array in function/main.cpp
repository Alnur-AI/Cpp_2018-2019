#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void arrprint(int** arr, int m, int n) {
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cout << arr[i][j] << ' ' << &arr[i][j] << '\t';
		}
		cout << endl;
	}
}

int main() {
	int m=3, n=5;
	int** p = new int*[m];
	for(int i = 0; i < m; i++) {
		p[i] = new int[n];
		for(int j = 0; j < n; j++) {
			p[i][j] = rand()%10;
		}
	}

	arrprint(p, m, n);

	for(int i = 0; i < m; i++) delete[] p[i];
	delete[] p;
}
