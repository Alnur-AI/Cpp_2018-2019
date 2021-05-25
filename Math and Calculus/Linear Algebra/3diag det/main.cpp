#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

class ratio{
private:///structure
    int num, denum;
public:///constructors
    ratio() {set(0, 1);}
    ratio(int n) {set(n,1);}
    ratio(int n, int d) {set(n,d);}
public:///copy constructor
    ratio(ratio const &src);
public:///define functions
    void set(int n, int d){num = n; denum = d; normalize();}
    int get_num() {return num;}
    int get_denum() {return denum;}
    void set_num(int num){this->num = num;}
    void set_denum(int denum){this->denum = denum;}
    void writeRatio(ratio &other){cout << "num: "; cin >> other.num; cout << "denum: "; cin >> other.denum;}
    double makedouble(){return (double)num / (double)denum;}
private:///arithmetics functions
    ratio add(const ratio &other);
    ratio sub(const ratio &other);
    ratio mult(const ratio &other);
    ratio div(const ratio &other);
public:///operators
    ratio operator+(const ratio &other){return add(other);};
    ratio operator-(const ratio &other){return sub(other);};
    ratio operator*(const ratio &other){return mult(other);};
    ratio operator/(const ratio &other){return div(other);};
    ratio &operator=(const ratio &other){set(other.num, other.denum); return *this;}
    bool operator==(const ratio &other){return (num == other.num && denum == other.denum);};
    friend ostream &operator<<(ostream &os, ratio &r);
private:///functions to make fractions right
    void normalize();
    int gcf(int a, int b);
    int lcm(int a, int b);
};

//---------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------
ratio::ratio(ratio const &src){
    num = src.num;
    denum = src.denum;
}
void ratio::normalize(){
    if (denum == 0 || num == 0){
        num = 0;
        denum = 1;
    }
    if (denum < 0){
        num *= -1;
        denum *= -1;
    }
    int n = gcf(num, denum);
    num = num / n;
    denum = denum / n;
}
int ratio::gcf(int a, int b){
    if (a % b == 0)
        return abs(b);
    else
        return gcf(b, a % b);
}
int ratio::lcm(int a, int b){
    return (a / gcf(a,b) * b);
}
ratio ratio::add(const ratio &other){
    ratio that;
    int lcd = lcm(denum, other.denum);
    that.set(num * lcd / denum + other.num * lcd / other.denum, lcd);
    that.normalize();
    return that;
}
ratio ratio::sub(const ratio &other){
    ratio that;
    int lcd = lcm(denum, other.denum);
    that.set(num * lcd / denum - other.num * lcd / other.denum, lcd);
    that.normalize();
    return that;
}
ratio ratio::mult(const ratio &other){
    ratio that;
    that.set(num * other.num, denum * other.denum);
    that.normalize();
    return that;
}
ratio ratio::div(const ratio &other){
    ratio that;
    that.set(num * other.denum, denum * other.num);
    that.normalize();
    return that;
}
ostream &operator<<(ostream &os, ratio &r){
    os << r.num << "/" << r.denum;
    return os;
}
int main (){
    ratio a, b, c;
    cout << "a-"; a.writeRatio(a);
    cout << "b-"; b.writeRatio(b);
    cout << "c-"; c.writeRatio(c);
    cout << "a = " << a << " b = " << b << " c = "<< c  << endl;


    ratio p, q;
    p = a;
    q = ratio(-1,1) * b * c;
    cout << "p = " << p << " q = " << q << endl;


    ratio D_1, D_2;
    D_1 = a;
    D_2 = a*a - b*c;
    cout << "D_1 = " << D_1 << " D_2 = " << D_2 << endl;


    double alpha, beta, p_dbl, q_dbl, descr;
    p_dbl = p.makedouble();
    q_dbl = q.makedouble();
    descr = sqrt(p_dbl*p_dbl + 4*q_dbl);
    alpha = (p_dbl + descr)/2.0;
    beta = (p_dbl - descr)/2.0;
    cout << "alpha = " << alpha << " beta = " << beta << endl;

    ratio c1, c2, BeTa = ratio((int)beta,1), AlPhA = ratio((int)alpha,1);
    if (AlPhA == BeTa){
        cout << "alpha = beta\n";
        alpha = (p_dbl)/2.0;
        beta = (p_dbl)/2.0;
        AlPhA = ratio((int)alpha,1);
        BeTa = ratio((int)beta,1);
        c1 = D_2/(AlPhA*AlPhA) - D_1/(AlPhA);
        c2 = ratio(2,1)*D_1/(AlPhA) - D_2/(AlPhA*AlPhA);
        cout << "c1 = " << c1 << " c2 = " << c2 << endl;

        cout << "\n" << "D_n = (" << AlPhA << ")^n(n(" << c1 << ") + (" << c2 << ")\n";
    }else{
        c1 = (D_2 - BeTa * D_1)/(AlPhA)/(AlPhA-BeTa);
        c2 = (D_2 - AlPhA * D_1)/(BeTa)/(BeTa-AlPhA);
        cout << "c1 = " << c1 << " c2 = " << c2 << endl;

        cout << "\n" << "D_n = (" << c1 << ")(" << AlPhA << ")^n + (" << c2 << ")(" << BeTa<< ")^n\n";
    }



    return 0;
}
