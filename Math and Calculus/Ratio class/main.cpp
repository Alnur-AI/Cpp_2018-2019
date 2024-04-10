#include <iostream>
#include <stdlib.h>
using namespace std;

class ratio{
private:///main structure
    int num, denum;
public:///constructors
    ratio() {set(0, 1);}
    ratio(int n) {set(n,1);}
    ratio(int n, int d) {set(n,d);}
public:///copy constructor
    ratio(ratio const &src);
public:///primary functions
    void set(int n, int d){num = n; denum = d; normalize();}

    int get_num() {return num;}
    int get_denum() {return denum;}

    float get_float(){return (float)num /(float)denum;}
    double get_double(){return (double)num /(double)denum;}
    long double get_long_double(){return (long double)num /(long double)denum;}
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
    bool operator<=(const ratio &other){
        int lcn = lcm(denum, other.denum);
        int temp1 = num * lcn / denum;
        int temp2 = other.num * lcn / other.denum;
        return (temp1 <= temp2);
    };
    bool operator>=(const ratio &other){
        int lcn = lcm(denum, other.denum);
        int temp1 = num * lcn / denum;
        int temp2 = other.num * lcn / other.denum;
        return (temp1 >= temp2);
    };
    bool operator<(const ratio &other){
        int lcn = lcm(denum, other.denum);
        int temp1 = num * lcn / denum;
        int temp2 = other.num * lcn / other.denum;
        return (temp1 < temp2);
    };
    bool operator>(const ratio &other){
        int lcn = lcm(denum, other.denum);
        int temp1 = num * lcn / denum;
        int temp2 = other.num * lcn / other.denum;
        return (temp1 > temp2);
    };
    friend ostream &operator<<(ostream &os, ratio &r);
    friend istream &operator>>(istream &is, ratio &r);
private:///functions to make fractions right
    void normalize();
    int gcf(int a, int b);
    int lcm(int a, int b);
};

int main(void )
{
    ratio a(1,3), b(1,3);
    return 0;
}


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
istream &operator>>(istream &is, ratio &r){
    std::cout << "Put numerator: ";
    is >> r.num;
    std::cout << "Put denominator: ";
    is >> r.denum;
    return is;
}
