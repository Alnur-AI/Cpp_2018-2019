#include <iostream>
#include <conio.h>
#include <windows.h>

#define HOME 0
#define UNIVERSITY 1
#define CITY 2
using namespace std;


typedef struct Student{
    /// FIRST IMPORTANT LINES OF LIFE (LIFE PURPOSES)
    unsigned short hungry = 1000;//MAX 1000
    unsigned short ment_health = 1000;//MAX 1000
    unsigned short phys_health = 1000;//MAX 1000
    unsigned short attendance = 1000;//MAX 1000
    /// SECOND IMPORTANT LINES OF LIFE (MONEY, REPUTATION)
    unsigned long long money = 5000;
    unsigned short finalsOccured = 0;//begin of study
    unsigned short location = 0;// in university
    unsigned int university_reputation = 0;//��� ������, ��� ������ ����� ������� ����� �����, ������� � ������
    unsigned int world_reputation = 0;//��� ������, ��� ������ �����
    /// THIRD IMPORTANT LINES OF LIFE (STUDY)
    unsigned short credit_1 = 0;//MAX 1000
    unsigned short credit_2 = 0;//MAX 1000
    unsigned short credit_3 = 0;//MAX 1000
    unsigned short credit_4 = 0;//MAX 1000
    unsigned short credit_5 = 0;//MAX 1000
    unsigned short exam_1 = 0;//MAX 1000
    unsigned short exam_2 = 0;//MAX 1000
    unsigned short exam_3 = 0;//MAX 1000
    unsigned short exam_4 = 0;//MAX 1000
    unsigned short exam_5 = 0;//MAX 1000
    unsigned short diploma = 0;//MAX 10000
    ///SECRET INFO TO FINAL STATISTIC
    unsigned long long money_earned = 0;//������� ���� ���������� �����
    unsigned short corrup_action = 0;// ������� ��� ��� ������
    ///ITEMS
    unsigned short Phone = 0;//no phone
    unsigned short PC = 0;//no pc
    bool antistress = false;
    bool book = false;
    bool favorite_book = false;
}student;
typedef struct Calendar_date{
    unsigned short hour = 9;//9:00
    unsigned short day = 1;//1
    unsigned short month = 9;//September
    unsigned short year = 1;//1 study year
}calendarDate;
typedef struct GameCoordMenu{
    short action = 0;
    short choice = 0;
}coordMenu;


char move;
student player;
calendarDate date;
coordMenu menuChoice;

void print_main_statistics();
void print_time_date();
void increase_date();
void setcur(int x, int y);

void display_home_screen();
void display_univ_screen();
void display_city_screen();

void display_home_hungry_screen();
void display_home_ment_health_screen();
void display_home_phys_health_screen();
void display_home_exam_prep_screen();
void display_home_shop_screen();
void display_home_change_location_screen();
void display_home_cheats_screen();

void display_univ_hungry_screen();
void display_univ_ment_health_screen();
void display_univ_phys_health_screen();
void display_univ_attendance_screen();
void display_univ_exam_prep_screen();
void display_univ_shop_screen();
void display_univ_change_location_screen();
void display_univ_cheats_screen();

void display_city_hungry_screen();
void display_city_ment_health_screen();
void display_city_phys_health_screen();
void display_city_money_income_screen();
void display_city_shop_screen();
void display_city_change_location_screen();
void display_city_cheats_screen();

void GAMEOVER_hungry_message();
void GAMEOVER_mentHealth_message();
void GAMEOVER_physHealth_message();
void GAMEOVER_attendance_message();
void GAMEOVER_failed_credit();
void GAMEOVER_failed_exam();
void show_final_statistic();

void payCredit_message();
void payExam_message();
int main(void){
    ///cout << "Please, play on the ENG keyboard" << endl;
    setlocale(LC_ALL, "Russian");
    while(1){
        if (date.day == 30 && date.month == 6 && date.year == 4 && date.hour == 9)
            break;
        print_main_statistics();
        cout << "������� ��������������: ";
        switch (player.location){
            case HOME:
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                cout << "���" << endl << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

                display_home_screen();
                break;
            case UNIVERSITY:
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                cout << "�����������" << endl << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

                display_univ_screen();
                break;
            case CITY:
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                cout << "�����" << endl << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

                display_city_screen();
                break;
        }
        move = _getch();
        if (move == 'W' || move == 'w'){
            menuChoice.choice--;
            if (menuChoice.choice < 0)
                menuChoice.choice = 0;
        }
        if (move == 'S' || move == 's'){
            menuChoice.choice++;
        }
        if (move == 'A' || move == 'a'){
            menuChoice.action--;
            menuChoice.choice = 0;
            if (menuChoice.action < 0)
                menuChoice.action = 0;
        }
        if (move == 'D' || move == 'd'){
            menuChoice.action++;
        }
        if (move == 'E' || move == 'e'){
            if (player.location == HOME){
                if (menuChoice.action == 0){
                    if (menuChoice.choice == 0){
                        if (player.money >= 10){
                            player.money -= 10;

                            player.hungry += 20;
                            if (player.hungry > 1000)
                                player.hungry = 1000;

                            player.ment_health -= 5;
                            if (player.ment_health <= 0)
                                GAMEOVER_mentHealth_message();

                            player.phys_health -=10;
                            if (player.phys_health <= 0)
                                GAMEOVER_physHealth_message();
                        }
                    }
                    if (menuChoice.choice == 1){
                        if (player.money >= 20){
                            player.money -= 20;

                            player.hungry += 20;
                            if (player.hungry > 1000)
                                player.hungry = 1000;

                            player.ment_health += 5;
                            if (player.ment_health > 1000)
                                player.ment_health = 1000;

                            player.phys_health +=5;
                            if (player.phys_health > 1000)
                                player.phys_health = 1000;
                        }
                    }
                    if (menuChoice.choice == 2){
                        if (player.money >= 20){
                            player.money -= 20;

                            player.hungry += 40;
                            if (player.hungry > 1000)
                                player.hungry = 1000;

                            player.ment_health += 10;
                            if (player.ment_health > 1000)
                                player.ment_health = 1000;

                            player.phys_health -=5;
                            if (player.phys_health <= 0)
                                GAMEOVER_physHealth_message();
                        }
                    }
                    if (menuChoice.choice == 3){
                        if (player.money >= 20){
                            player.money -= 20;

                            player.hungry += 60;
                            if (player.hungry > 1000)
                                player.hungry = 1000;

                            player.phys_health -= 10;
                            if (player.phys_health <= 0)
                                GAMEOVER_physHealth_message();
                        }
                    }
                    if (menuChoice.choice == 4){
                        if (player.money >= 25){
                            player.money -= 25;

                            player.hungry += 100;
                            if (player.hungry > 1000)
                                player.hungry = 1000;

                            player.ment_health += 30;
                            if (player.ment_health > 1000)
                                player.ment_health = 1000;

                            player.phys_health -= 20;
                            if (player.phys_health <= 0)
                                GAMEOVER_physHealth_message();
                        }
                    }
                    if (menuChoice.choice == 5){
                        if (player.money >= 50){
                            player.money -= 50;

                            player.hungry += 100;
                            if (player.hungry > 1000)
                                player.hungry = 1000;

                            player.ment_health += 100;
                            if (player.ment_health > 1000)
                                player.ment_health = 1000;

                            player.phys_health -= 20;
                            if (player.phys_health <= 0)
                                GAMEOVER_physHealth_message();
                        }
                    }
                    if (menuChoice.choice == 6){
                        if (player.money >= 50){
                            player.money -= 50;

                            player.hungry += 50;
                            if (player.hungry > 1000)
                                player.hungry = 1000;

                            player.ment_health += 70;
                            if (player.ment_health > 1000)
                                player.ment_health = 1000;

                            player.phys_health += 50;
                            if (player.phys_health > 1000)
                                player.phys_health = 1000;
                        }
                    }
                    if (menuChoice.choice == 7){
                        if (player.money >= 100){
                            player.money -= 100;

                            player.hungry += 200;
                            if (player.hungry > 1000)
                                player.hungry = 1000;

                            player.ment_health += 20;
                            if (player.ment_health > 1000)
                                player.ment_health = 1000;

                            player.phys_health -= 70;
                            if (player.phys_health <= 0)
                                GAMEOVER_physHealth_message();
                        }
                    }
                    if (menuChoice.choice == 8){
                        if (player.money >= 200){
                            player.money -= 200;

                            player.hungry += 250;
                            if (player.hungry > 1000)
                                player.hungry = 1000;

                            player.ment_health += 50;
                            if (player.ment_health > 1000)
                                player.ment_health = 1000;

                            player.phys_health += 10;
                            if (player.phys_health > 1000)
                                player.phys_health = 1000;
                        }
                    }
                    if (menuChoice.choice == 9){
                        if (player.money >= 300){
                            player.money -= 300;

                            player.hungry += 300;
                            if (player.hungry > 1000)
                                player.hungry = 1000;

                            player.ment_health += 100;
                            if (player.ment_health > 1000)
                                player.ment_health = 1000;

                            player.phys_health -= 50;
                            if (player.phys_health <= 0)
                                GAMEOVER_physHealth_message();
                        }
                    }
                    if (menuChoice.choice == 10){
                        if (player.money >= 500){
                            player.money -= 500;

                            player.hungry += 450;
                            if (player.hungry > 1000)
                                player.hungry = 1000;

                            player.ment_health += 60;
                            if (player.ment_health > 1000)
                                player.ment_health = 1000;

                            player.phys_health += 35;
                            if (player.phys_health > 1000)
                                player.phys_health = 1000;
                        }
                    }
                    if (menuChoice.choice == 11){
                        if (player.money >= 1500){
                            player.money -= 1500;

                            player.hungry += 600;
                            if (player.hungry > 1000)
                                player.hungry = 1000;

                            player.ment_health += 200;
                            if (player.ment_health > 1000)
                                player.ment_health = 1000;

                            player.phys_health += 150;
                            if (player.phys_health > 1000)
                                player.phys_health = 1000;
                        }
                    }
                    if (menuChoice.choice == 12){
                        if (player.money >= 5000){
                            player.money -= 5000;

                            player.hungry += 750;
                            if (player.hungry > 1000)
                                player.hungry = 1000;

                            player.ment_health += 500;
                            if (player.ment_health > 1000)
                                player.ment_health = 1000;

                            player.phys_health += 300;
                            if (player.phys_health > 1000)
                                player.phys_health = 1000;
                        }
                    }
                    if (menuChoice.choice == 13){
                        if (player.money >= 15000){
                            player.money -= 15000;

                            player.hungry += 1000;
                            if (player.hungry > 1000)
                                player.hungry = 1000;

                            player.ment_health += 800;
                            if (player.ment_health > 1000)
                                player.ment_health = 1000;

                            player.phys_health += 650;
                            if (player.phys_health > 1000)
                                player.phys_health = 1000;
                        }
                    }
                }
                if (menuChoice.action == 1){
                    if (menuChoice.choice == 0){
                        player.ment_health += 50;
                        if (player.ment_health > 1000)
                                player.ment_health = 1000;
                        player.phys_health -= 10;
                        if (player.phys_health <= 0)
                            GAMEOVER_physHealth_message();
                        increase_date();
                    }
                    if (menuChoice.choice == 1 && player.antistress == true){
                        player.ment_health += 50;
                        if (player.ment_health > 1000)
                            player.ment_health = 1000;
                        increase_date();
                    }
                    if (menuChoice.choice == 2 && player.book == true){
                        player.ment_health += 150;
                        if (player.ment_health > 1000)
                            player.ment_health = 1000;
                        increase_date();
                    }
                    if (menuChoice.choice == 3 && player.favorite_book == true){
                        player.ment_health += 250;
                        if (player.ment_health > 1000)
                            player.ment_health = 1000;
                        increase_date();
                    }
                    if (menuChoice.choice == 4){
                        player.ment_health += 20;
                        if (player.ment_health > 1000)
                            player.ment_health = 1000;

                        player.phys_health += 20;
                        if (player.phys_health > 1000)
                            player.phys_health = 1000;
                        increase_date();
                    }
                    if (menuChoice.choice == 5 && player.Phone == true){
                        player.ment_health += 125;
                        if (player.ment_health > 1000)
                            player.ment_health = 1000;
                        increase_date();
                    }
                    if (menuChoice.choice == 6 && player.PC == true){
                        player.ment_health += 200;
                        if (player.ment_health > 1000)
                            player.ment_health = 1000;
                        increase_date();
                    }
                    if (menuChoice.choice == 7){
                        if (player.money >= 10){
                            player.money -= 10;

                            player.ment_health += 60;
                            if (player.ment_health > 1000)
                                player.ment_health = 1000;

                            player.phys_health -= 30;
                            if (player.phys_health <= 0)
                                GAMEOVER_physHealth_message();

                            increase_date();
                        }
                    }
                    if (menuChoice.choice == 8){
                        if (player.money >= 50){
                            player.money -= 50;

                            player.ment_health += 60;
                            if (player.ment_health > 1000)
                                player.ment_health = 1000;

                            player.phys_health -= 10;
                            if (player.phys_health <= 0)
                                GAMEOVER_physHealth_message();

                            increase_date();
                        }
                    }
                    if (menuChoice.choice == 9){
                        if (player.money >= 200){
                            player.money -= 200;

                            player.ment_health += 150;
                            if (player.ment_health > 1000)
                                player.ment_health = 1000;

                            player.phys_health -= 60;
                            if (player.phys_health <= 0)
                                GAMEOVER_physHealth_message();

                            increase_date();
                        }
                    }
                    if (menuChoice.choice == 10){
                        if (player.money >= 300){
                            player.money -= 300;

                            player.hungry += 200;
                            if (player.hungry > 1000)
                                player.hungry = 1000;

                            player.ment_health += 200;
                            if (player.ment_health > 1000)
                                player.ment_health = 1000;

                            player.phys_health -= 10;
                            if (player.phys_health <= 0)
                                GAMEOVER_physHealth_message();

                            increase_date();
                        }
                    }
                    if (menuChoice.choice == 11){
                        if (player.money >= 1000){
                            player.money -= 1000;

                            player.hungry += 400;
                            if (player.hungry > 1000)
                                player.hungry = 1000;

                            player.ment_health += 400;
                            if (player.ment_health > 1000)
                                player.ment_health = 1000;

                            player.phys_health -= 20;
                            if (player.phys_health <= 0)
                                GAMEOVER_physHealth_message();

                            increase_date();
                        }
                    }
                    if (menuChoice.choice == 12){
                        if (player.money >= 1500){
                            player.money -= 1500;

                            player.ment_health += 600;
                            if (player.ment_health > 1000)
                                player.ment_health = 1000;

                            player.phys_health -= 60;
                            if (player.phys_health <= 0)
                                GAMEOVER_physHealth_message();

                            increase_date();
                        }
                    }
                    if (menuChoice.choice == 13){
                        if (player.money >= 3500){
                            player.money -= 3500;

                            player.hungry += 1000;
                            if (player.hungry > 1000)
                                player.hungry = 1000;

                            player.ment_health += 800;
                            if (player.ment_health > 1000)
                                player.ment_health = 1000;

                            player.phys_health -= 30;
                            if (player.phys_health <= 0)
                                GAMEOVER_physHealth_message();

                            increase_date();
                        }
                    }
                    if (menuChoice.choice == 14){
                        if (player.money >= 10000){
                            player.money -= 10000;

                            player.ment_health += 6000;
                            if (player.ment_health > 1000)
                                player.ment_health = 1000;

                            player.phys_health -= 10;
                            if (player.phys_health <= 0)
                                GAMEOVER_physHealth_message();

                            increase_date();
                        }
                    }
                }
            }
        }
        if (menuChoice.action == 7 && player.location == HOME)
            menuChoice.action = 6;
        if (menuChoice.action == 0 && menuChoice.choice == 14)
            menuChoice.choice = 13;
        if (menuChoice.action == 1 && menuChoice.choice == 15)
            menuChoice.choice = 14;
        if (move == 'Q' || move == 'q'){
            system("cls");
            cout << "Q ������ ������. ��������� ��������� �������!" << endl;
            return 0;
        }

        system("cls");
    }
    //print_result_of_game();
    return 0;
}

void print_main_statistics(){
    cout << "���������: " << endl << endl;
    if (date.hour >= 9 && date.hour <= 15 && player.location != UNIVERSITY){
        cout << "�� ������ ���� � ������������!!!" << endl;
    }
    if (date.hour >= 9 && date.hour <= 15 && player.location == UNIVERSITY){
        cout << "�������� ������������!!!" << endl;
    }
    if (date.hour < 9){
        cout << "�� ������ ���� � ������������ ����� " << 9 - date.hour << " ����." << endl;
    }
    if ( date.hour > 15){
        cout << "�� ������ ���� � ������������ ����� " << 24 - date.hour + 9 << " �����." << endl;
    }
    if (date.hour <= 6 && date.hour >= 0)
        cout << "������ �����! �� ����� �����!\n[-50 ����� - 50 �� - 50 ��]" << endl << endl;
    else
        cout << "�� ����� �������� ����� ����� " << 24 - date.hour << " �����" << endl << endl;
    print_time_date();
    cout  << endl << "����������: " << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << endl << "�����: " << player.hungry << " (MAX 1000)" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    cout << "��������������� ��������: " << player.ment_health << " (MAX 1000)" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
    cout << "���������� ��������: " << player.phys_health << " (MAX 1000)" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
    cout << "���������: " << player.attendance << " (MAX 1000)" << endl;
    cout << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << "������: " << player.money << " ���" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    cout << "��������� � ������������: " << player.university_reputation << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    cout << "��������� � ����: " << player.world_reputation << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    cout << "������ ��������: " << player.finalsOccured << endl;
    cout << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "������� �������: " << player.Phone << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
    cout << "������� ���������: " << player.PC << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);


}
void print_time_date(){
    switch (date.month){
        case 1:
            cout << date.day << " January\n" << "Study Year: " << date.year << endl;
            if (date.hour < 10){
                cout << "Time: 0" << date.hour << ":00" << endl;
            }
            else{
                cout << "Time: " << date.hour << ":00" << endl;
            }
            break;
        case 2:
            cout << date.day << " February\n" << "Study Year: " << date.year << endl;
            if (date.hour < 10){
                cout << "Time: 0" << date.hour << ":00" << endl;
            }
            else{
                cout << "Time: " << date.hour << ":00" << endl;
            }
            break;
        case 3:
            cout << date.day << " March\n" << "Study Year: " << date.year << endl;
            if (date.hour < 10){
                cout << "Time: 0" << date.hour << ":00" << endl;
            }
            else{
                cout << "Time: " << date.hour << ":00" << endl;
            }
            break;
        case 4:
            cout << date.day << " April\n" << "Study Year: " << date.year << endl;
            if (date.hour < 10){
                cout << "Time: 0" << date.hour << ":00" << endl;
            }
            else{
                cout << "Time: " << date.hour << ":00" << endl;
            }
            break;
        case 5:
            cout << date.day << " May\n" << "Study Year: " << date.year << endl;
            if (date.hour < 10){
                cout << "Time: 0" << date.hour << ":00" << endl;
            }
            else{
                cout << "Time: " << date.hour << ":00" << endl;
            }
            break;
        case 6:
            cout << date.day << " June\n" << "Study Year: " << date.year << endl;
            if (date.hour < 10){
                cout << "Time: 0" << date.hour << ":00" << endl;
            }
            else{
                cout << "Time: " << date.hour << ":00" << endl;
            }
            break;
        case 7:
            cout << date.day << " July\n" << "Study Year: " << date.year << endl;
            if (date.hour < 10){
                cout << "Time: 0" << date.hour << ":00" << endl;
            }
            else{
                cout << "Time: " << date.hour << ":00" << endl;
            }
            break;
        case 8:
            cout << date.day << " August\n" << "Study Year: " << date.year << endl;
            if (date.hour < 10){
                cout << "Time: 0" << date.hour << ":00" << endl;
            }
            else{
                cout << "Time: " << date.hour << ":00" << endl;
            }
            break;
        case 9:
            cout << date.day << " September\n" << "Study Year: " << date.year << endl;
            if (date.hour < 10){
                cout << "Time: 0" << date.hour << ":00" << endl;
            }
            else{
                cout << "Time: " << date.hour << ":00" << endl;
            }
            break;
        case 10:
            cout << date.day << " October\n" << "Study Year: " << date.year << endl;
            if (date.hour < 10){
                cout << "Time: 0" << date.hour << ":00" << endl;
            }
            else{
                cout << "Time: " << date.hour << ":00" << endl;
            }
            break;
        case 11:
            cout << date.day << " November\n" << "Study Year: " << date.year << endl;
            if (date.hour < 10){
                cout << "Time: 0" << date.hour << ":00" << endl;
            }
            else{
                cout << "Time: " << date.hour << ":00" << endl;
            }
            break;
        case 12:
            cout << date.day << " December\n" << "Study Year: " << date.year << endl;
            if (date.hour < 10){
                cout << "Time: 0" << date.hour << ":00" << endl;
            }
            else{
                cout << "Time: " << date.hour << ":00" << endl;
            }
            break;
        default:
            cout << "IN FUNCTION void print_time(int) switch case of months gives month: " << date.month << endl;
            exit (1);
    }

}
void increase_date(){
    date.hour++;
    if (date.hour == 24){
        date.hour = 0;
        switch (date.month){
            case 1:
                date.day++;
                if (date.day == 32){
                    date.day = 1;
                    date.month = 2;
                }
                break;
            case 2:
                date.day++;
                if (date.day == 29){
                    date.day = 1;
                    date.month = 3;
                }
                break;
            case 3:
                date.day++;
                if (date.day == 32){
                    date.day = 1;
                    date.month = 4;
                }
                break;
            case 4:
                date.day++;
                if (date.day == 31){
                    date.day = 1;
                    date.month = 5;
                }
                break;
            case 5:
                date.day++;
                if (date.day == 32){
                    date.day = 1;
                    date.month = 6;
                }
                break;
            case 6:
                date.day++;
                if (date.day == 31){
                    date.day = 1;
                    date.month = 7;
                }
                break;
            case 7:
                date.day++;
                if (date.day == 32){
                    date.day = 1;
                    date.month = 8;
                }
                break;
            case 8:
                date.day++;
                if (date.day == 32){
                    date.day = 1;
                    date.month = 9;
                    date.year++;
                }
                break;
            case 9:
                date.day++;
                if (date.day == 31){
                    date.day = 1;
                    date.month = 10;
                }
                break;
            case 10:
                date.day++;
                if (date.day == 32){
                    date.day = 1;
                    date.month = 11;
                }
                break;
            case 11:
                date.day++;
                if (date.day == 31){
                    date.day = 1;
                    date.month = 12;
                }
                break;
            case 12:
                date.day++;
                if (date.day == 32){
                    date.day = 1;
                    date.month = 1;
                }
                break;
        }
    }
}

void GAMEOVER_attendance_message(){
    system("cls");
    cout << "�� ������� ����� �� �������� �����������.\n��� ������ ���������.\n������������� ��� ����� ���� ������?\n������ ��������, ��� �� ��� ���� ������ ������\n������ - �� ����� ����� � �����. ����� - ���� �����.\n������� ���� ��������� ���, ��� �������� ���� ����!" << endl;
    show_final_statistic();
    move = _getch();
    exit(0);
}
void GAMEOVER_failed_credit(){
    system("cls");
    cout << "�� �������� �����.\n��� ������ ���������.\n������������� ��� ����� ���� ������?\n������ ��������, ��� �� ��� ���� ������ ������\n������ - �� ����� ����� � �����. ����� - ���� �����.\n������� ���� ��������� ���, ��� �������� ���� ����!" << endl;
    show_final_statistic();
    move = _getch();
    exit(0);
}
void GAMEOVER_failed_exam(){
    system("cls");
    cout << "�� �������� �������.\n��� ������ ���������.\n������������� ��� ����� ���� ������?\n������ ��������, ��� �� ��� ���� ������ ������\n������ - �� ����� ����� � �����. ����� - ���� �����.\n������� ���� ��������� ���, ��� �������� ���� ����!" << endl;
    show_final_statistic();
    move = _getch();
    exit(0);
}
void GAMEOVER_hungry_message(){
    system("cls");
    cout << "�� ����� �������� �, ����������, �� ����� � �������.\n��� ������������ ������ ������ � ��������� � ��������.\n� ���������, ���� ������������ ����� � ��� ��������� �������, � �� �� ������ ����� ��������.\n��� ��������� �� ��������������.\n������������� ��� ����� ���� ������?\n������ ��������, ��� �� ��� ���� ������ ������\n������ - �� ����� ����� � �����. ����� - ���� �����.\n������� ���� ��������� ���, ��� �������� ���� ����!" << endl;
    show_final_statistic();
    move = _getch();
    exit(0);
}
void GAMEOVER_mentHealth_message(){
    system("cls");
    cout << "�� ������� �������, ��������, �� ������� �������� �� ���� �������.\n��� ����� ��������� �����, ��� �� ������� ������� ����.\n� �������, ��� ������ �� ����������� � ��������� � ��������, � ����������.\n���� ������� �������� ��� ���������� ���� ����� ���������� ���������, ��� ����� � ������������.\n��� ��������� �� ��������� ��������.\n�� �����������, ������ ����� �������������, ����� ����������� �����!\n����������� - �� ����� ������. ����� - ���� �����\n������� �� ����������!"<< endl;
    show_final_statistic();
    move = _getch();
    exit(0);
}
void GAMEOVER_physHealth_message(){
    system("cls");
    cout << "���������� ��������, ������ ������� � ���������� ������ �������� ���� �������� �� ����������� �������.\n�� ���� ���������� ������������������.\n� ���������, ���� ������� ����� ����� ������ ���� � �� ���� ��������� �� ��������.\n������!\n�� ������ ��������� �����������.\n�� ����� ��� � �����������.\n��� �� �� ������ ������ ������?\n������ - �� ����� ����� � �����. ����� - ���� �����.\n������� ���� ��������� ���, ��� �������� ���� ����!" << endl;
    show_final_statistic();
    move = _getch();
    exit(0);
}

void show_final_statistic(){
    cout << endl << "����������:" << endl;
}

void display_home_screen(){
    setcur(50,0);
    if (menuChoice.action == 0){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout << "  �����" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        display_home_hungry_screen();
    }
    if (menuChoice.action == 1){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout << "  ��������������� ��������" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        display_home_ment_health_screen();
    }
    if (menuChoice.action == 2){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout << "  ���������� ��������" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        display_home_phys_health_screen();
    }
    if (menuChoice.action == 3){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout << "  ���������� � ���������" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        display_home_exam_prep_screen();
    }
    if (menuChoice.action == 4){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout << "  �������" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        display_home_shop_screen();
    }
    if (menuChoice.action == 5){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout << "  ������� �������" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        display_home_change_location_screen();
    }
    if (menuChoice.action == 6){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout << "  ����" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        display_home_cheats_screen();
    }
}
void display_home_hungry_screen(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    if (menuChoice.choice == 0){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 64);
        setcur(50,1);
        cout << "->������� (10 ���) [+20 ����� -5 �� -10 ��]" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        setcur(50,1);
        cout << "  ������� (10 ���) [+20 ����� -5 �� -10 ��]" << endl;
    }
    if (menuChoice.choice == 1){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 64);
        setcur(50,2);
        cout << "->����� (20 ���) [+20 ����� +5 �� +5 ��]" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        setcur(50,2);
        cout << "  ����� (20 ���) [+20 ����� +5 �� +5 ��]" << endl;
    }
    if (menuChoice.choice == 2){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 64);
        setcur(50,3);
        cout << "->���-��� (20 ���) [+40 ����� +10 �� -5 ��]" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        setcur(50,3);
        cout << "  ���-��� (20 ���) [+40 ����� +10 �� -5 ��]" << endl;
    }
    if (menuChoice.choice == 3){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 64);
        setcur(50,4);
        cout << "->�������� �������� (20 ���) [+60 ����� +0 �� -10 ��]" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        setcur(50,4);
        cout << "  �������� �������� (20 ���) [+60 ����� +0 �� -10 ��]" << endl;
    }
    if (menuChoice.choice == 4){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 64);
        setcur(50,5);
        cout << "->�������� (25 ���) [+100 ����� +30 �� -20 ��]" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        setcur(50,5);
        cout << "  �������� (25 ���) [+100 ����� +30 �� -20 ��]" << endl;
    }
    if (menuChoice.choice == 5){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 64);
        setcur(50,6);
        cout << "->������� (50 ���) [+100 ����� +100 �� -20 ��]" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        setcur(50,6);
        cout << "  ������� (50 ���) [+100 ����� +100 �� -20 ��]" << endl;
    }
    if (menuChoice.choice == 6){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 64);
        setcur(50,7);
        cout << "->������� (50 ���) [+50 ����� +70 �� +50 ��]" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        setcur(50,7);
        cout << "  ������� (50 ���) [+50 ����� +70 �� +50 ��]" << endl;
    }
    if (menuChoice.choice == 7){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 64);
        setcur(50,8);
        cout << "->������ (100 ���) [+200 ����� +20 �� -70 ��]" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        setcur(50,8);
        cout << "  ������ (100 ���) [+200 ����� +20 �� -70 ��]" << endl;
    }
    if (menuChoice.choice == 8){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 64);
        setcur(50,9);
        cout << "->����� ���� (200 ���) [+250 ����� +50 �� +10 ��]" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        setcur(50,9);
        cout << "  ����� ���� (200 ���) [+250 ����� +50 �� +10 ��]" << endl;
    }
    if (menuChoice.choice == 9){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 64);
        setcur(50,10);
        cout << "->������ ����� �� ��� (300 ���) [+300 ����� +100 �� -50 ��]" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        setcur(50,10);
        cout << "  ������ ����� �� ��� (300 ���) [+300 ����� +100 �� -50 ��]" << endl;
    }
    if (menuChoice.choice == 10){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 64);
        setcur(50,11);
        cout << "->����� �� ���� (500 ���) [+450 ����� +60 �� +35 ��]" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        setcur(50,11);
        cout << "  ����� �� ���� (500 ���) [+450 ����� +60 �� +35 ��]" << endl;
    }
    if (menuChoice.choice == 11){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 64);
        setcur(50,12);
        cout << "->����� �� ��������� (1500 ���) [+600 ����� +200 �� +150 ��]" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        setcur(50,12);
        cout << "  ����� �� ��������� (1500 ���) [+600 ����� +200 �� +150 ��]" << endl;
    }
    if (menuChoice.choice == 12){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 64);
        setcur(50,13);
        cout << "->�������� ��������� (5000 ���) [+750 ����� +500 �� +300 ��]" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        setcur(50,13);
        cout << "  �������� ��������� (5000 ���) [+750 ����� +500 �� +300 ��]" << endl;
    }
    if (menuChoice.choice == 13){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 64);
        setcur(50,14);
        cout << "->�������� ����������� ��� (15000 ���) [+1000 ����� +800 �� +650 ��]" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        setcur(50,14);
        cout << "  �������� ����������� ��� (15000 ���) [+1000 ����� +800 �� +650 ��]" << endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
void display_home_ment_health_screen(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    if (menuChoice.choice == 0){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
        setcur(50,1);
        cout << "->�������� ������� ����� (0 ���)[+50 ��, -10 ��]" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        setcur(50,1);
        cout << "  �������� ������� ����� (0 ���)[+50 ��, -10 ��]" << endl;
    }
    if (menuChoice.choice == 1){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
        setcur(50,2);
        cout << "->�������� � ������������ (0 ���. ����� ����������)[+100 ��]" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        setcur(50,2);
        cout << "  �������� � ������������ (0 ���. ����� ����������)[+100 ��]" << endl;
    }
    if (menuChoice.choice == 2){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
        setcur(50,3);
        cout << "->�������� ����� (0 ���. ����� �����)[+150 ��]" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        setcur(50,3);
        cout << "  �������� ����� (0 ���. ����� �����)[+150 ��]" << endl;
    }
    if (menuChoice.choice == 3){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
        setcur(50,4);
        cout << "->�������� ������� ����� (0 ���. ����� ������� �����)[+250 ��]" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        setcur(50,4);
        cout << "  �������� ������� ����� (0 ���. ����� ������� �����)[+250 ��]" << endl;
    }
    if (menuChoice.choice == 4){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
        setcur(50,5);
        cout << "->�������������� (0 ���) [+20 �� + 20 ��]" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        setcur(50,5);
        cout << "  �������������� (0 ���) [+20 �� + 20 ��]" << endl;
    }
    if (menuChoice.choice == 5){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
        setcur(50,6);
        cout << "->�������� � �������� (0 ���, ����� ������� ) [+125 ��]" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        setcur(50,6);
        cout << "  �������� � �������� (0 ���, ����� ������� ) [+125 ��]" << endl;
    }
    if (menuChoice.choice == 6){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
        setcur(50,7);
        cout << "->�������� �� �������� (0 ���, ����� ������� ) [+200 ��]" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        setcur(50,7);
        cout << "  �������� �� �������� (0 ���, ����� ������� ) [+250 ��]" << endl;
    }
    if (menuChoice.choice == 7){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
        setcur(50,8);
        cout << "->�������� (10 ���) [+60 �� -30 ��]" << endl;
    }

    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        setcur(50,8);
        cout << "  �������� (10 ���) [+60 �� -30 ��]" << endl;
    }
    if (menuChoice.choice == 8){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
        setcur(50,9);
        cout << "->������ ���� (50 ���) [+60 �� -10 ��]" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        setcur(50,9);
        cout << "  ������ ���� (50 ���) [+60 �� -10 ��]" << endl;
    }
    if (menuChoice.choice == 9){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
        setcur(50,10);
        cout << "->������ ������� �������� (200 ���) [+150 �� -60 ��]" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        setcur(50,10);
        cout << "  ������ ������� �������� (200 ���) [+150 �� -60 ��]" << endl;
    }
    if (menuChoice.choice == 10){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
        setcur(50,11);
        cout << "->����������� ����� ������� ��� (300 ���) [+200 ����� +200 �� -10 ��]" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        setcur(50,11);
        cout << "  ����������� ����� ������� ��� (300 ���) [+200 ����� +200 �� -10 ��]" << endl;
    }
    if (menuChoice.choice == 11){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
        setcur(50,12);
        cout << "->����������� �������� ��� (1000 ���) [+400 ����� +400 �� -20 ��]" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        setcur(50,12);
        cout << "  ����������� �������� ��� (1000 ���) [+400 ����� +400 �� -20 ��]" << endl;
    }
    if (menuChoice.choice == 12){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
        setcur(50,13);
        cout << "->������ ������� �������� (1500 ���) [+600 �� -60 ��]" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        setcur(50,13);
        cout << "  ������ ������� �������� (1500 ���) [+600 �� -60 ��]" << endl;
    }
    if (menuChoice.choice == 13){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
        setcur(50,14);
        cout << "->����������� ��������� (3500 ���) [+1000 �����, +800 ��, -30 ��]" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        setcur(50,14);
        cout << "  ����������� ��������� (3500 ���) [+1000 �����, +800 ��, -30 ��]" << endl;
    }
    if (menuChoice.choice == 14){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
        setcur(50,15);
        cout << "->������ ������� �������� (10000 ���) [+1000 ��, -10 ��]" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        setcur(50,15);
        cout << "  ������ ������� �������� (10000 ���) [+1000 ��, -10 ��]" << endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
void display_home_phys_health_screen(){
    if(menuChoice.action == 2){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 16);
        setcur(50,3);
        cout << "->Physical Health" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
        setcur(50,3);
        cout << "  Physical Health" << endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
void display_home_exam_prep_screen(){
    setcur(50,4);
    if(menuChoice.action == 3){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 128);
         cout << "->Exam Preparation" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
         cout << "  Exam Preparation" << endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
void display_home_shop_screen(){
    setcur(50,5);
    if(menuChoice.action == 4){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 96);
         cout << "->Shop" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
         cout << "  Shop" << endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
void display_home_change_location_screen(){
    setcur(50,6);
    if(menuChoice.action == 5){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9*16);
        cout << "->Change Location" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
        cout << "Change Location" << endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
void display_home_cheats_screen(){
    setcur(50,7);
    if(menuChoice.action == 6){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15*16);
        cout << "->Cheats" << endl;
    }
    else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout << "  Cheats" << endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void display_univ_screen(){
    setcur(50,0);
    cout << "MENU:" << endl;
    setcur(50,1);
    cout << "Hungry" << endl;
    setcur(50,2);
    cout << "Mental Health" << endl;
    setcur(50,3);
    cout << "Physical Health" << endl;
    setcur(50,4);
    cout << "Attendance" << endl;
    setcur(50,5);
    cout << "Exam Preparation" << endl;
    setcur(50,6);
    cout << "Shop" << endl;
    setcur(50,7);
    cout << "Change Location" << endl;
    setcur(50,8);
    cout << "Cheats" << endl;
}

void display_city_screen(){
    setcur(50,0);
    cout << "MENU:" << endl;
    setcur(50,1);
    cout << "Hungry" << endl;
    setcur(50,2);
    cout << "Mental Health" << endl;
    setcur(50,3);
    cout << "Physical Health" << endl;
    setcur(50,4);
    cout << "Money Income" << endl;
    setcur(50,5);
    cout << "Shop" << endl;
    setcur(50,6);
    cout << "Change Location" << endl;
    setcur(50,7);
    cout << "Cheats" << endl;
}

void setcur(int x, int y){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//���������� ��� �������� ���������� ������������
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hConsole, coord);
}






























/*
while(date.day != 31 && date.month != 6 && date.year != 4 && date.hour != 9){
        switch (player.location){
            case 0://HOME

                break;
            case 1://UNIVERSITY

                break;
            case 2://WORKPLACE

                break;
        }
        move = _getch();
        system("cls");
    }


switch ((month + 8)%13){
        case 1:
            if (hours < 10){
                cout << days << " January" << " Study Year: " << year << endl;
                cout << "Time: 0" << hours << ":00" << endl;
            }
            else
                cout << "DAY: " << days << " MONTH: " << "January" << " YEAR: " << year << " HOUR: " << hours << ":00" << endl;
            break;
        default:
            cout << "IN FUNCTION void print_time(int) switch case of months gives month: " << (month + 8)%13 << endl;
            exit (1);
    }
void print_time(int timer){
    if (timer < 0){
        cout << "NEGATIVE TIME IN FUNCTION PRINT_TIME" << endl;
        exit(1);
    }

    int days = 1;//first day of study
    int month = 1;//september
    int year = timer / 8760;//first course
    int hours = timer % 24;

    if (hours < 10)
        cout << "DAY: " << days << " MONTH: " << (month + 8)%13 << " YEAR: " << year << " HOUR: 0" << hours << ":00" << endl;
    else
        cout << "DAY: " << days << " MONTH: " << (month + 8)%13 << " YEAR: " << year << " HOUR: " << hours << ":00" << endl;
}
*/
