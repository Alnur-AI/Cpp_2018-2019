#include <iostream>
#include <cstdlib>
using namespace std;


class date{
private:
    short dd;
    short mm;
    int yy;
public:///constructor and destructor
    date(short day, short month, int year);
    ~date(){};
public:///basic calculations
    void inc();
    void dec();
    void incDays(int days){ for (int k = 0; k < days; k++) inc(); }
    void decDays(int days){ for (int k = 0; k < days; k++) dec(); }
    int differenceBetweenDates(const date &other);
public:///getters
    short getDay(){return dd;}
    short getMonth(){return mm;}
    int   getYear(){return yy;}
public:///setters
    void set(short day, short month, int year);
public:///know the day
    short dayOfWeek();
    short daysInMonth(short month, int year);
    short daysInYear(){
        if (yy % 4 != 0 || ( yy % 100 == 0 && yy % 400 != 0))
            return 365;
        else	return 366;
    }
public:///some operators for work
    date &operator=(const date &other){set(other.dd, other.mm, other.yy); return *this;}
    bool operator!=(const date &other){ return (dd != other.dd && mm != other.mm && yy != other.yy);}
    bool operator==(const date &other){ return (dd == other.dd && mm == other.mm && yy == other.yy);}
    bool operator<=(const date &other){
        if (yy == other.yy){
            if (mm == other.mm){
                if (dd <= other.dd)
                    return true;

                if (dd > other.dd)
                    return false;
            }

            if (mm < other.mm)
                return true;

            if (mm > other.mm)
                return false;
        }

        if (yy < other.yy)
            return true;

        if (yy > other.yy)
            return false;

    }
    bool operator>=(const date &other){
        if (yy == other.yy){
            if (mm == other.mm){

                if (dd >= other.dd)
                    return true;

                if (dd < other.dd)
                    return false;
            }

            if (mm > other.mm)
                return true;

            if (mm < other.mm)
                return false;
        }

        if (yy > other.yy)
            return true;

        if (yy < other.yy)
            return false;


    };
    bool operator<(const date &other){
        if (yy == other.yy){
            if (mm == other.mm){
                if (dd < other.dd)
                    return true;

                if (dd >= other.dd)
                    return false;
            }
            if (mm < other.mm)
                return true;

            if (mm > other.mm)
                return false;

        }
        if (yy < other.yy)
            return true;

        if (yy > other.yy)
            return false;

    }
    bool operator>(const date &other){
        if (yy == other.yy){
            if (mm == other.mm){
                if (dd > other.dd)
                    return true;

                if (dd <= other.dd)
                    return false;
            }
            if (mm > other.mm)
                return true;

            if (mm < other.mm)
                return false;

        }
        if (yy > other.yy)
            return true;

        if (yy < other.yy)
            return false;
    }

public:///print
    void printDate();
    void printDayOfWeek(int i);
    void printMonth();
    void printMonthFormat();
    void printYearFormat();
};

        date::date(short day, short month, int year){
    dd = day;
    mm = month;
    yy = year;

    if (year % 4 != 0 || ( year % 100 == 0 && year % 400 != 0)){///not a leap year
        switch(month){
        case 1:
            if (day < 1 || day > 31){
                cout << "ERROR: WRONG DAY IN JANUARY" << endl;
                exit(1);
            }
            break;
        case 2:
            if (day < 1 || day > 28){
                cout << "ERROR: WRONG DAY IN FEBRUARY" << endl;
                exit(1);
            }
            break;
        case 3:
            if (day < 1 || day > 31){
                cout << "ERROR: WRONG DAY IN MARCH" << endl;
                exit(1);
            }
            break;
        case 4:
            if (day < 1 || day > 30){
                cout << "ERROR: WRONG DAY IN APRIL" << endl;
                exit(1);
            }
            break;
        case 5:
            if (day < 1 || day > 31){
                cout << "ERROR: WRONG DAY IN MAY" << endl;
                exit(1);
            }
            break;
        case 6:
            if (day < 1 || day > 30){
                cout << "ERROR: WRONG DAY IN JUNE" << endl;
                exit(1);
            }
            break;
        case 7:
            if (day < 1 || day > 31){
                cout << "ERROR: WRONG DAY IN JULY" << endl;
                exit(1);
            }
            break;
        case 8:
            if (day < 1 || day > 31){
                cout << "ERROR: WRONG DAY IN AUGUST" << endl;
                exit(1);
            }
            break;
        case 9:
            if (day < 1 || day > 30){
                cout << "ERROR: WRONG DAY IN SEPTEMBER" << endl;
                exit(1);
            }
            break;
        case 10:
            if (day < 1 || day > 31){
                cout << "ERROR: WRONG DAY IN OCTOBER" << endl;
                exit(1);
            }
            break;
        case 11:
            if (day < 1 || day > 30){
                cout << "ERROR: WRONG DAY IN NOVEMBER" << endl;
                exit(1);
            }
            break;
        case 12:
            if (day < 1 || day > 31){
                cout << "ERROR: WRONG DAY IN DECEMBER" << endl;
                exit(1);
            }
            break;
        default:
            cout << "ERROR: WRONG MONTH" << endl;
            exit(1);
            break;
        }
    }
	else{
        switch(month){
        case 1:
            if (day < 1 || day > 31){
                cout << "ERROR: WRONG DAY IN JANUARY" << endl;
                exit(1);
            }
            break;
        case 2:
            if (day < 1 || day > 29){
                cout << "ERROR: WRONG DAY IN FEBRUARY" << endl;
                exit(1);
            }
            break;
        case 3:
            if (day < 1 || day > 31){
                cout << "ERROR: WRONG DAY IN MARCH" << endl;
                exit(1);
            }
            break;
        case 4:
            if (day < 1 || day > 30){
                cout << "ERROR: WRONG DAY IN APRIL" << endl;
                exit(1);
            }
            break;
        case 5:
            if (day < 1 || day > 31){
                cout << "ERROR: WRONG DAY IN MAY" << endl;
                exit(1);
            }
            break;
        case 6:
            if (day < 1 || day > 30){
                cout << "ERROR: WRONG DAY IN JUNE" << endl;
                exit(1);
            }
            break;
        case 7:
            if (day < 1 || day > 31){
                cout << "ERROR: WRONG DAY IN JULY" << endl;
                exit(1);
            }
            break;
        case 8:
            if (day < 1 || day > 31){
                cout << "ERROR: WRONG DAY IN AUGUST" << endl;
                exit(1);
            }
            break;
        case 9:
            if (day < 1 || day > 30){
                cout << "ERROR: WRONG DAY IN SEPTEMBER" << endl;
                exit(1);
            }
            break;
        case 10:
            if (day < 1 || day > 31){
                cout << "ERROR: WRONG DAY IN OCTOBER" << endl;
                exit(1);
            }
            break;
        case 11:
            if (day < 1 || day > 30){
                cout << "ERROR: WRONG DAY IN NOVEMBER" << endl;
                exit(1);
            }
            break;
        case 12:
            if (day < 1 || day > 31){
                cout << "ERROR: WRONG DAY IN DECEMBER" << endl;
                exit(1);
            }
            break;
        default:
            cout << "ERROR: WRONG MONTH" << endl;
            exit(1);
            break;
        }
    }
}
void    date::inc(){
    dd++;
    switch (mm){
        case 1:
            if (dd == 32){
                dd = 1;
                mm = 2;
            }
            break;
        case 2:
            if (yy % 4 != 0 || ( yy % 100 == 0 && yy % 400 != 0)){///not a leap year
                if (dd == 29){
                    dd = 1;
                    mm = 3;
                }
            }
            else{
                if (dd == 30){
                    dd = 1;
                    mm = 3;
                }
            }
            break;
        case 3:
            if (dd == 32){
                dd = 1;
                mm = 4;
            }
            break;
        case 4:
            if (dd == 31){
                dd = 1;
                mm = 5;
            }
            break;
        case 5:
            if (dd == 32){
                dd = 1;
                mm = 6;
            }
            break;
        case 6:
            if (dd == 31){
                dd = 1;
                mm = 7;
            }
            break;
        case 7:
            if (dd == 32){
                dd = 1;
                mm = 8;
            }
            break;
        case 8:
            if (dd == 32){
                dd = 1;
                mm = 9;
            }
            break;
        case 9:
            if (dd == 31){
                dd = 1;
                mm = 10;
            }
            break;
        case 10:
            if (dd == 32){
                dd = 1;
                mm = 11;
            }
            break;
        case 11:
            if (dd == 31){
                dd = 1;
                mm = 12;
            }
            break;
        case 12:
            if (dd == 32){
                dd = 1;
                mm = 1;
                yy++;
            }
            break;
        }
}
void    date::dec(){
    dd--;
    switch (mm){
        case 1:
            if (dd == 0){
                dd = 31;
                mm = 12;
                yy--;
            }
            break;
        case 2:
            if (dd == 0){
                dd = 31;
                mm = 1;
            }
            break;
        case 3:
            if (yy % 4 != 0 || ( yy % 100 == 0 && yy % 400 != 0)){///not a leap year
                if (dd == 0){
                    dd = 28;
                    mm = 2;
                }
            }
            else{
                if (dd == 0){
                    dd = 29;
                    mm = 2;
                }
            }
            break;
        case 4:
            if (dd == 0){
                dd = 31;
                mm = 3;
            }
            break;
        case 5:
            if (dd == 0){
                dd = 30;
                mm = 4;
            }
            break;
        case 6:
            if (dd == 0){
                dd = 31;
                mm = 5;
            }
            break;
        case 7:
            if (dd == 0){
                dd = 30;
                mm = 6;
            }
            break;
        case 8:
            if (dd == 0){
                dd = 31;
                mm = 7;
            }
            break;
        case 9:
            if (dd == 0){
                dd = 31;
                mm = 8;
            }
            break;
        case 10:
            if (dd == 0){
                dd = 30;
                mm = 9;
            }
            break;
        case 11:
            if (dd == 0){
                dd = 31;
                mm = 10;
            }
            break;
        case 12:
            if (dd == 0){
                dd = 30;
                mm = 11;
            }
            break;
        }
}
int     date::differenceBetweenDates(const date &other){
    date temp = *this;
    int days = 0;

    if (temp == other) return days;

    if (temp > other){
        while (1){
            if (temp == other) break;
            temp.dec();
            days++;
        }
        return days;
    }
    if (temp < other){
        while (1){
            if (temp == other) break;
            temp.inc();
            days++;
        }
        return days;
    }
}
void    date::set(short day, short month, int year){
    dd = day;
    mm = month;
    yy = year;

    if (year % 4 != 0 || ( year % 100 == 0 && year % 400 != 0)){///not a leap year
        switch(month){
        case 1:
            if (day < 1 || day > 31){
                cout << "ERROR: WRONG DAY IN JANUARY" << endl;
                exit(1);
            }
            break;
        case 2:
            if (day < 1 || day > 28){
                cout << "ERROR: WRONG DAY IN FEBRUARY" << endl;
                exit(1);
            }
            break;
        case 3:
            if (day < 1 || day > 31){
                cout << "ERROR: WRONG DAY IN MARCH" << endl;
                exit(1);
            }
            break;
        case 4:
            if (day < 1 || day > 30){
                cout << "ERROR: WRONG DAY IN APRIL" << endl;
                exit(1);
            }
            break;
        case 5:
            if (day < 1 || day > 31){
                cout << "ERROR: WRONG DAY IN MAY" << endl;
                exit(1);
            }
            break;
        case 6:
            if (day < 1 || day > 30){
                cout << "ERROR: WRONG DAY IN JUNE" << endl;
                exit(1);
            }
            break;
        case 7:
            if (day < 1 || day > 31){
                cout << "ERROR: WRONG DAY IN JULY" << endl;
                exit(1);
            }
            break;
        case 8:
            if (day < 1 || day > 31){
                cout << "ERROR: WRONG DAY IN AUGUST" << endl;
                exit(1);
            }
            break;
        case 9:
            if (day < 1 || day > 30){
                cout << "ERROR: WRONG DAY IN SEPTEMBER" << endl;
                exit(1);
            }
            break;
        case 10:
            if (day < 1 || day > 31){
                cout << "ERROR: WRONG DAY IN OCTOBER" << endl;
                exit(1);
            }
            break;
        case 11:
            if (day < 1 || day > 30){
                cout << "ERROR: WRONG DAY IN NOVEMBER" << endl;
                exit(1);
            }
            break;
        case 12:
            if (day < 1 || day > 31){
                cout << "ERROR: WRONG DAY IN DECEMBER" << endl;
                exit(1);
            }
            break;
        default:
            cout << "ERROR: WRONG MONTH" << endl;
            exit(1);
            break;
        }
    }
	else{
        switch(month){
        case 1:
            if (day < 1 || day > 31){
                cout << "ERROR: WRONG DAY IN JANUARY" << endl;
                exit(1);
            }
            break;
        case 2:
            if (day < 1 || day > 29){
                cout << "ERROR: WRONG DAY IN FEBRUARY" << endl;
                exit(1);
            }
            break;
        case 3:
            if (day < 1 || day > 31){
                cout << "ERROR: WRONG DAY IN MARCH" << endl;
                exit(1);
            }
            break;
        case 4:
            if (day < 1 || day > 30){
                cout << "ERROR: WRONG DAY IN APRIL" << endl;
                exit(1);
            }
            break;
        case 5:
            if (day < 1 || day > 31){
                cout << "ERROR: WRONG DAY IN MAY" << endl;
                exit(1);
            }
            break;
        case 6:
            if (day < 1 || day > 30){
                cout << "ERROR: WRONG DAY IN JUNE" << endl;
                exit(1);
            }
            break;
        case 7:
            if (day < 1 || day > 31){
                cout << "ERROR: WRONG DAY IN JULY" << endl;
                exit(1);
            }
            break;
        case 8:
            if (day < 1 || day > 31){
                cout << "ERROR: WRONG DAY IN AUGUST" << endl;
                exit(1);
            }
            break;
        case 9:
            if (day < 1 || day > 30){
                cout << "ERROR: WRONG DAY IN SEPTEMBER" << endl;
                exit(1);
            }
            break;
        case 10:
            if (day < 1 || day > 31){
                cout << "ERROR: WRONG DAY IN OCTOBER" << endl;
                exit(1);
            }
            break;
        case 11:
            if (day < 1 || day > 30){
                cout << "ERROR: WRONG DAY IN NOVEMBER" << endl;
                exit(1);
            }
            break;
        case 12:
            if (day < 1 || day > 31){
                cout << "ERROR: WRONG DAY IN DECEMBER" << endl;
                exit(1);
            }
            break;
        default:
            cout << "ERROR: WRONG MONTH" << endl;
            exit(1);
            break;
        }
    }
}
short   date::dayOfWeek(){
    short indexCentury;
    if ( (yy - (yy%100))%400 == 100 ) indexCentury = 4;
    if ( (yy - (yy%100))%400 == 200 ) indexCentury = 2;
    if ( (yy - (yy%100))%400 == 300 ) indexCentury = 0;
    if ( (yy - (yy%100))%400 == 0 ) indexCentury = 6;
    short indexYears;
    if (yy % 4 != 0 || ( yy % 100 == 0 && yy % 400 != 0))
        indexYears = (yy%100 + (yy%100)/4 )%7;
    else if (mm == 1 || mm == 2)
        indexYears = (yy%100 + (yy%100)/4 )%7 - 1;
    short indexMonth;
    if (mm == 1 || mm == 10) indexMonth = 0;
    if (mm == 5) indexMonth = 1;
    if (mm == 8) indexMonth = 2;
    if (mm == 2 || mm == 3 || mm == 11) indexMonth = 3;
    if (mm == 6) indexMonth = 4;
    if (mm == 9 || mm == 12) indexMonth = 5;
    if (mm == 4 || mm == 7) indexMonth = 6;
    short indexDay;
    indexDay = dd%7;
    short total = indexDay + indexMonth + indexYears + indexCentury;
    total = total%7;
    if (total%7 == 0) total = 7;
    return total;
}
short date::daysInMonth(short month, int year){
        switch ( month )
        {
                case 1: return 31;
                case 3: return 31;
                case 4: return 30;
                case 5: return 31;
                case 6: return 30;
                case 7: return 31;
                case 8: return 31;
                case 9: return 30;
                case 10: return 31;
                case 11: return 30;
                case 12: return 31;
        }
        if ( month == 2 )
                if ( year % 4 != 0 || ( year % 100 == 0 && year % 400 != 0))
                        return 28;
                else    return 29;
}

void date::printDate(){
    cout << "|day: " << dd << "|month: " << mm << "|year: " << yy << "|" << endl;
}
void date::printMonth(){
	switch (mm){
		case 1: cout << "January"; break;
		case 2: cout << "February"; break;
		case 3: cout << "March"; break;
		case 4: cout << "April"; break;
		case 5: cout << "May"; break;
		case 6: cout << "June"; break;
		case 7: cout << "July"; break;
		case 8: cout << "August"; break;
		case 9: cout << "September"; break;
		case 10: cout <<"October"; break;
		case 11: cout <<"November"; break;
		case 12: cout <<"December"; break;
		default: exit(0); break;
	}
}
void date::printDayOfWeek(int i){
	switch (i){
                case 1: cout << "Monday";  break;
                case 2: cout << "Tuesday"; break;
                case 3: cout << "Wednesday"; break;
                case 4: cout << "Thursday"; break;
                case 5: cout << "Friday";  break;
                case 6: cout << "Saturday"; break;
                case 7: cout << "Sunday";  break;
                default: exit(0); break;
    }
}
void date::printMonthFormat(){
    cout << "     ";
	printMonth();
	cout << " " << yy << " year" << endl;
	cout << "Mn  Tu  Wd  Th  Fr  Sa  Su " << endl;
	int numday = daysInMonth(mm, yy);
	date temp(1,mm,yy);
	short first_day = temp.dayOfWeek();
	int i = first_day;

	while ( i > 1 ){
		cout << "    ";
		i--;
	}
	i = 1;
	while (i <= numday){
		if ( i < 10 )
			cout << i << "   ";
		else
			cout << i << "  ";
		i++;
		if ( (first_day % 7)  == 0 )
			cout << endl;
		first_day++;
	}
}
void date::printYearFormat(){
    date temp(dd,1,yy);
	while ( temp.mm <= 12 ){
		temp.printMonthFormat();
		cout << endl << endl;
        temp.mm++;
	}
}

int main()
{
    date d(3,8,2019);
    d.printYearFormat();
    d.printDate();
    return 0;
}
