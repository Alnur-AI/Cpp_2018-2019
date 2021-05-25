#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

const int MAXcard  = 30;

typedef struct Card {
    int color;
    int type;
}card;

enum{RED = 101, YELLOW = 102, GREEN = 103, BLUE = 104};
enum{ZERO = 0, ONE = 1, TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, DRAWTWO = 10, WILDDRAWFOUR = 11, REVERSE = 12, SKIP = 13, WILD = 14};

void printPLAYER_NAME(int turn);
void printCARD(int color, int type);
void printPLAYER_COLUMN (card column[], int curr_max_cards);
void printUNO ();
int turnTOnextPLAYER(int turn, int MAXplayer);
int turnTOprevPLAYER(int turn, int MAXplayer);
int RULEsameCOLOR_or_sameTYPE(prev_color, prev_type, curr_color, curr_type);

int main(){
     //set color white, define steps, turn, and choice
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);//��� ������� ������������� ���� ������ � ������� �� �����. �������� ��������� conio.h � windows.h
    int turn = 1;//��� ���������� ����������� ���������� �� ������� ������
    int choice;//� ��� �������� �������� ����� ������ (����� ����� ������� ����� �� �������)
    int new_card_activator = 0;//����������� ����, ����� ��������� ������ �����
    card prev_choice;//����������, � ������� �������� ����� ����������� ������




    int MAXplayer;//����� ����� ������ �������
    printf("How much players would play?\nAnswer: ");

    do {
        scanf("%d", &MAXplayer);
        if (MAXplayer > 4 || MAXplayer < 2) printf("Please, choice 2,3 or 4 players.\nAnswer: ");
    }while (MAXplayer > 4 || MAXplayer < 2);

    int cardsplayer [MAXplayer + 1];//����� ���� � ������� ������
    for (int i = 1; i <= MAXplayer; i++) cardsplayer[i] = 7;// ���������, ��� � ������� ���������� 7 ����



    card columnplayer[MAXplayer + 1][MAXcard]; //�� ����� ����� ������� � ������ �� ����� ��������� ������ ���� ��� ������� ������.


    //�������� ����� �������
    srand (time(0));
    for (int i = 1; i <= MAXplayer; i++){
        for (int j = 1; j <= 7; j++){
            columnplayer[i][j].color = rand()%4+101;
            columnplayer[i][j].type = rand()%9;//������ ���� 14, �� ���� ����� �� �������� � ���� ������
        }
    }
    system("cls");//�������� ����� �� ������





    //������ ��� ����� ������! ��� ��� ��, ����� ��� ��� ������ ���� �����1 ������ ������� ������ ���
    printf("      GAME START!!!\n");
    printf("-------------------------\n");
        for (int i = 1; i <= MAXplayer; i++){
            printPLAYER_NAME(i);
            printf(" cards remain: %d\n", cardsplayer[i]);
        }
    printf("-------------------------\n\n\n");

    //����� �������� ����� �����
    printPLAYER_NAME(turn);
    printf(" attack...\n");
    printPLAYER_COLUMN (columnplayer[turn], cardsplayer[turn]);
    printf("Choice: ");
    scanf("%d", &choice);
    if (choice < 0 || choice > cardsplayer[turn]){//�� ������, ���� ����� ������� �����, ������� � ���� ���
        while(choice < 0 || choice > cardsplayer[turn]){
                printf("You don't have that card! Try again!\nChoice: ");
                scanf("%d", &choice);
        }
    }


    if (choice == 0){//������, ���� ����� ����� ����� ���� ��� ���� �����
        while(choice == 0){//������������: ������� ���� ����� ����� � ������ ����...?
                printf("You can't get a new card! Use available cards!\nChoice: ");
                scanf("%d", &choice);
        }
    }
    else{//���� ����� ������ �����, ������� � ������ ������ � ���� ����
        prev_choice.color = columnplayer[turn][choice].color;
        prev_choice.type = columnplayer[turn][choice].type;
    }


    if (new_card_activator == 0){//������ �� ���� ��������� ����
        for (int i = choice; i < cardsplayer[turn]; i++){//����������� �� ������� ��������� �����
                columnplayer[turn][i].color = columnplayer[turn][i + 1].color;
                columnplayer[turn][i].type = columnplayer[turn][i + 1].type;
        }
        cardsplayer[turn]--;
    }
    new_card_activator = 0;
    turn = turnTOnextPLAYER(turn, MAXplayer);//
    system("cls");


    while(1){//����������� ���� ����
        if (cardsplayer[1] == 0 || cardsplayer[2] == 0 || cardsplayer[3] == 0 || cardsplayer[4] == 0){//������ ����� � ������ �� ������� �������� ����� - ���� ����������.
                for (int i = 1; i <= MAXplayer; i++){
                    if (cardsplayer[i] == 0){
                        printf("GAME OVER! \n");
                        printPLAYER_NAME(i);
                        printf(" WINS!\n\n\n");
                    }
                    return 0;
                }
        }


        //�� �� ������ ������� ������, �������� ����� "������� ����"?
        printf("      UNO: ULTIMATE   \n");
        printf("-------------------------\n");
        for (int i = 1; i <= MAXplayer; i++){
            printPLAYER_NAME(i);
            printf(" cards remain: %d ", cardsplayer[i]);
            if (cardsplayer[i] == 1) printUNO();
            else printf("\n");
        }
        printf("-------------------------\n\n\n");


        printPLAYER_NAME(turnTOprevPLAYER(turn, MAXplayer));//��� ����������� ������
        printf(" ");
        printCARD(prev_choice.color, prev_choice.type);// ����� ����������� ������
        printPLAYER_NAME(turn);
        printf(" attack...\n");
        printPLAYER_COLUMN (columnplayer[turn], cardsplayer[turn]);// ������ �������� ������
        printf("Choice: ");
        scanf("%d", &choice);

        while(1){//�� ������, ���� ����� ������� �����, ������� � ���� ��� ��� �������� �������
            if (choice == 0){//����� ����� ����� ��� ���� �����
                break;
            }
            if (choice < 0 || choice > cardsplayer[turn]){//������� �����, ������� �� ���������� � ������
                printf("You don't have that card! Try again!\nChoice: ");
                scanf("%d", &choice);
            }
            if (RULEsameCOLOR_or_sameTYPE(prev_choice.color, prev_choice.type, columnplayer[turn][choice].color, columnplayer[turn][choice].type) == 0){//������� ����� �� �������������� �� ����� ��� ����
                printf("You can't choice %d card! That's against the rules! Pick another one.\nChoice: ", choice);
                scanf("%d", &choice);
                continue;
            }
            if (RULEsameCOLOR_or_sameTYPE(prev_choice.color, prev_choice.type, columnplayer[turn][choice].color, columnplayer[turn][choice].type) == 1){//������� ����� ��������������� �� ����� ��� ����.
                break;
            }
        }



        if (choice == 0){//������, ���� ����� ����� ����� ���� ��� ���� �����
            new_card_activator = 1;
            cardsplayer[turn]++;//�������� �����
            columnplayer[turn][cardsplayer[turn]].color = rand()%4+101;
            columnplayer[turn][cardsplayer[turn]].type = rand()%9;//rand()%14 ���� ����� ������� ��������((
        }
        else{//���� ����� ������ �����, ������� � ������ ������ � ���� ����
            prev_choice.color = columnplayer[turn][choice].color;
            prev_choice.type = columnplayer[turn][choice].type;
        }


        if (new_card_activator == 0){//������ �� ���� ��������� ����
            for (int i = choice; i < cardsplayer[turn]; i++){//����������� �� ������� ��������� �����
                    columnplayer[turn][i].color = columnplayer[turn][i + 1].color;
                    columnplayer[turn][i].type = columnplayer[turn][i + 1].type;
            }
            cardsplayer[turn]--;
        }
        new_card_activator = 0;
        turn = turnTOnextPLAYER(turn, MAXplayer);
        system("cls");


    }
    return 0;
}

void printPLAYER_NAME(int turn){
    switch (turn){
    case 1:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
        printf("PLAYER %d", turn);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    break;
    case 2:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
        printf("PLAYER %d", turn);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    break;
    case 3:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
        printf("PLAYER %d", turn);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    break;
    case 4:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
        printf("PLAYER %d", turn);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    break;
    default:
        return;
    break;
    }
}
void printCARD(int color, int type){

    if (type == WILDDRAWFOUR){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        printf("CARD: WILD DRAW FOUR\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        return;
    }
    switch ( color ) {
      case RED:
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
          switch(type){
            case ZERO:
                printf("CARD: ZERO\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case ONE:
                printf("CARD: ONE\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case TWO:
                printf("CARD: TWO\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case THREE:
                printf("CARD: THREE\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case FOUR:
                printf("CARD: FOUR\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case FIVE:
                printf("CARD: FIVE\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case SIX:
                printf("CARD: SIX\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case SEVEN:
                printf("CARD: SEVEN\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case EIGHT:
                printf("CARD: EIGHT\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case NINE:
                printf("CARD: NINE\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case DRAWTWO:
                printf("CARD: DRAW TWO\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case REVERSE:
                printf("CARD: REVERSE\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case SKIP:
                printf("CARD: SKIP\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case WILD:
                printf("CARD: WILD\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            default:
                printf("ERROR!\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
          }
      break;
      case YELLOW:
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
          switch(type){
            case ZERO:
                printf("CARD: ZERO\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case ONE:
                printf("CARD: ONE\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case TWO:
                printf("CARD: TWO\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case THREE:
                printf("CARD: THREE\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case FOUR:
                printf("CARD: FOUR\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case FIVE:
                printf("CARD: FIVE\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case SIX:
                printf("CARD: SIX\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case SEVEN:
                printf("CARD: SEVEN\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case EIGHT:
                printf("CARD: EIGHT\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case NINE:
                printf("CARD: NINE\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case DRAWTWO:
                printf("CARD: DRAW TWO\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case REVERSE:
                printf("CARD: REVERSE\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case SKIP:
                printf("CARD: SKIP\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case WILD:
                printf("CARD: WILD\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            default:
                printf("ERROR!\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
          }
      break;
      case GREEN:
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
          switch(type){
            case ZERO:
                printf("CARD: ZERO\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case ONE:
                printf("CARD: ONE\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case TWO:
                printf("CARD: TWO\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case THREE:
                printf("CARD: THREE\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case FOUR:
                printf("CARD: FOUR\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case FIVE:
                printf("CARD: FIVE\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case SIX:
                printf("CARD: SIX\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case SEVEN:
                printf("CARD: SEVEN\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case EIGHT:
                printf("CARD: EIGHT\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case NINE:
                printf("CARD: NINE\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case DRAWTWO:
                printf("CARD: DRAW TWO\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case REVERSE:
                printf("CARD: REVERSE\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case SKIP:
                printf("CARD: SKIP\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case WILD:
                printf("CARD: WILD\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            default:
                printf("ERROR!\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
          }
      break;
      case BLUE:
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
          switch(type){
            case ZERO:
                printf("CARD: ZERO\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case ONE:
                printf("CARD: ONE\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case TWO:
                printf("CARD: TWO\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case THREE:
                printf("CARD: THREE\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case FOUR:
                printf("CARD: FOUR\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case FIVE:
                printf("CARD: FIVE\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case SIX:
                printf("CARD: SIX\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case SEVEN:
                printf("CARD: SEVEN\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case EIGHT:
                printf("CARD: EIGHT\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case NINE:
                printf("CARD: NINE\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case DRAWTWO:
                printf("CARD: DRAW TWO\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case REVERSE:
                printf("CARD: REVERSE\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case SKIP:
                printf("CARD: SKIP\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            case WILD:
                printf("CARD: WILD\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
            default:
                printf("ERROR!\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            break;
          }
      break;
      default:
          printf("ERROR!\n");
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
      break;
  }
}
void printPLAYER_COLUMN (card column[], int curr_max_cards){
    int counter = 1;

    printf("        Card List:\n-------------------------\n");
    printf("0) PICK NEW CARD\n");
    for (int i = 1; i <= curr_max_cards; i++){
            printf("%d) ",counter++);
            printCARD(column[i].color, column[i].type);
    }
    printf("-------------------------\n");
}
void printUNO (){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
    printf("U");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
    printf("N");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
    printf("O!\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

int turnTOnextPLAYER(int turn, int MAXplayer){
    turn++;
    if (turn > MAXplayer) turn = 1;
    return turn;
}
int turnTOprevPLAYER(int turn, int MAXplayer){
    turn--;
    if (turn < 1) turn = MAXplayer;
    return turn;
}
int RULEsameCOLOR_or_sameTYPE(prev_color, prev_type, curr_color, curr_type){
    if (prev_color == curr_color || prev_type == curr_type){
        return 1;
    }
    else{
        return 0;
    }
}

/*
int global_rule_new_card;
int global_rule_skip;
int global_rule_reverse;
int global_rule_drawtwo;
int global_rule_wilddrawfour;
int global_rule_wild;
int local_rule_new_card;
int local_rule_skip;
int local_rule_reverse;
int local_rule_drawtwo;
int local_rule_wilddrawfour;
int local_rule_wild;



bool res = false;
for (int i = 0; i < n; i++){
    res ||= cards[i].a == d
}

*/
