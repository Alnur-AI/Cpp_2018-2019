#include <iostream>
using namespace std;

long long pow (long long a, long long b){
    if (b <= 0)
        return 1;
    long long a1 = 1;
    for (int i = 0; i < b; i++)
        a1 = a*a1;
    return a1;
}

long long fact (long long n){
    if(n < 0) // если пользователь ввел отрицательное число
        return 0; // возвращаем ноль
    if (n == 0) // если пользователь ввел ноль,
        return 1; // возвращаем факториал от нуля - не удивляетесь, но это 1 =)
    else // Во всех остальных случаях
        return n * fact(n - 1); // делаем рекурсию.
}

long long C(long long n, long long k){
    if (n < k)
        return -1;
    return fact(n)/fact(n-k)/fact(k);
}

long long alpha(int k, int n){
    if (k%2 == 1)
        return 0;
    long long S = 0;
    for (int p = k/2; p <= n/2; p++)
        S = S + pow(-1, 2*p - k/2)*C(n, 2*p)*C(p, p - k/2);
    return S;
}
int main(){
    int n;
    cout << "COS(nx) expantion to (cosx)^n polynome." << endl;
    cout << "Put the n: ";
    cin >> n;
    for (int i = 0; i <= n; i++){
        cout << alpha(i, n) << " ";
    }
    cout << "\nWrite something and press ENTER to exit:";
    char waste;
    cin >> waste;
    return 0;
}
