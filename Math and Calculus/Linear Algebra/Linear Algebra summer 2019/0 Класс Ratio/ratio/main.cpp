#include <iostream>
using namespace std;

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


int main() {
	int num, denum;
	cout << "input: num1 denum1 num2 denum2" << endl;

	cin >> num >> denum;
	Ratio r1(num,denum);

	cin >> num >> denum;
	Ratio r2(num,denum);


	print_ratio (cout , r1);
	print_ratio (cout , r2);
	cout << endl;


    Ratio r;
	r = r1 + r2;
	cout << "sum is equal:";
	print_ratio (cout , r);
    cout << endl;


	r = r1 * r2;
	cout << "multiply is equal:";
	print_ratio (cout, r);
    cout << endl;


	r = r1 / r2;
	cout << "division is equal:";
	print_ratio (cout, r);
	cout << endl;


	compare(r1, r2);
	cout << endl;


	cout.precision(4);
	cout << "r1 in double: ";
	cout << r1.ToDouble() << endl;

	cout << "r2 in double: ";
	cout << r2.ToDouble() << endl;
	return 0;
}
