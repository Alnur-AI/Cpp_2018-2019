#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>


typedef struct Card {
    int color;
    int type;
}card;

enum{RED = 101, YELLOW = 102, GREEN = 103, BLUE = 104};
enum{ZERO = 0, ONE = 1, TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, DRAWTWO = 10, WILDDRAWFOUR = 11, REVERSE = 12, SKIP = 13, WILD = 14};



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
    printf("O");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

int rule (int p_color, int p_type, int c_color, int c_type){
    if ((p_color == c_color || p_type == c_type) &&  c_type < 10) return 0;
    if (p_color == c_color && c_type == SKIP) return 1;//INSTALLED
    if (p_color == c_color && c_type == REVERSE) return 2;
    if (p_color == c_color && c_type == DRAWTWO) return 3;
    if (c_type == WILDDRAWFOUR) return 4;
    if (p_color != c_color || p_type != c_type) return 5;
}


int main()
{
    //set color white, define steps, turn, and choice
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    int step = 0;
    int turn = 1;
    int choice;
    //int action_rule;
    int action_rule_reverse_aftermatch;
    int new_card_activator = 0;
    int last_player_without_new_card = 1;
    int reverse_activated = 0;
    card prev_choice;
    card curr_choice;

    //define players
    int player1cards, player2cards, player3cards, player4cards;
    int MAXplayer;
    printf("WELCOME TO UNO GAME! \nHow much players would play?\n\nOnly: ");
    do {
        scanf("%d", &MAXplayer);
        if (MAXplayer > 4 || MAXplayer < 2) printf("Please, choice 2,3 or 4 players.\n");
    }while (MAXplayer > 4 || MAXplayer < 2);
    switch (MAXplayer){/*set player cards*/
    case 2:
        player1cards = 7;
        player2cards = 7;
        break;
    case 3:
        player1cards = 7;
        player2cards = 7;
        player3cards = 7;
        break;
    case 4:
        player1cards = 7;
        player2cards = 7;
        player3cards = 7;
        player4cards = 7;
        break;
    }
    system("cls");



    //define player columns
    card player1column[100];
    card player2column[100];
    card player3column[100];
    card player4column[100];



    //random all cards
    srand (time(0));
    for (int i = 1; i <= player1cards; i++){
        player1column[i].color = rand()%4+101;
        player1column[i].type = rand()%14;

        player2column[i].color = rand()%4+101;
        player2column[i].type = rand()%14;

        player3column[i].color = rand()%4+101;
        player3column[i].type = rand()%14;

        player4column[i].color = rand()%4+101;
        player4column[i].type = rand()%14;
    }



    //first move
    printf("      GAME START!!!\n");
    switch (MAXplayer){/*print how much card are remain*/
    case 2:
        printf("-------------------------\n");
        printPLAYER_NAME(1);
        printf(" cards remain: %d\n", player1cards);
        printPLAYER_NAME(2);
        printf(" cards remain: %d\n", player2cards);
        printf("-------------------------\n\n\n");
        break;
    case 3:
        printf("-------------------------\n");
        printPLAYER_NAME(1);
        printf(" cards remain: %d\n", player1cards);
        printPLAYER_NAME(2);
        printf(" cards remain: %d\n", player2cards);
        printPLAYER_NAME(3);
        printf(" cards remain: %d\n", player3cards);
        printf("-------------------------\n\n\n");
        break;
    case 4:
        printf("-------------------------\n");
        printPLAYER_NAME(1);
        printf(" cards remain: %d\n", player1cards);
        printPLAYER_NAME(2);
        printf(" cards remain: %d\n", player2cards);
        printPLAYER_NAME(3);
        printf(" cards remain: %d\n", player3cards);
        printPLAYER_NAME(4);
        printf(" cards remain: %d\n", player4cards);
        printf("-------------------------\n\n\n");
        break;
    }
    printPLAYER_NAME(turn);
    printf(" attacking...\n");
    switch (turn){/*print player column*/
        case 1:
            printPLAYER_COLUMN(player1column, player1cards);
            break;
        case 2:
            printPLAYER_COLUMN(player2column, player2cards);
            break;
        case 3:
            printPLAYER_COLUMN(player3column, player3cards);
            break;
        case 4:
            printPLAYER_COLUMN(player4column, player4cards);
            break;
    }
    printf("Choice: ");
    scanf("%d", &choice);
    switch(turn){/*fix choice*/
    case 1:
        if (choice < 0 || choice > player1cards){
            while(choice < 0 || choice > player1cards){
                    printf("You don't have that card! Try again!");
                    scanf("%d", &choice);
                }
        }
        break;
    case 2:
        if (choice < 0 || choice > player2cards){
            while(choice < 0 || choice > player2cards){
                    printf("You don't have that card! Try again!");
                    scanf("%d", &choice);
                }
        }
        break;
    case 3:
        if (choice < 0 || choice > player3cards){
            while(choice < 0 || choice > player3cards){
                    printf("You don't have that card! Try again!");
                    scanf("%d", &choice);
                }
        }
        break;
    case 4:
        if (choice < 0 || choice > player4cards){
            while(choice < 0 || choice > player4cards){
                    printf("You don't have that card! Try again!");
                    scanf("%d", &choice);
                }
        }
        break;
    }
    if (choice == 0){
        new_card_activator = 1;
        action_rule_reverse_aftermatch = 1;
        switch(turn){
        case 1:
            player1cards++;
            player1column[player1cards].color = rand()%4+101;
            player1column[player1cards].type = rand()%9;//rand()%14 спец карты хреново работают((
            break;
        case 2:
            player2cards++;
            player2column[player2cards].color = rand()%4+101;
            player2column[player2cards].type = rand()%9;//rand()%14
            break;
        case 3:
            player3cards++;
            player3column[player3cards].color = rand()%4+101;
            player3column[player3cards].type = rand()%9;//rand()%14
            break;
        case 4:
            player4cards++;
            player4column[player4cards].color = rand()%4+101;
            player4column[player4cards].type = rand()%9;//rand()%14
            break;
        }
    }
    switch (turn){/*previous choice filling(with player choice)*/
    case 1:
        prev_choice.color = player1column[choice].color;
        prev_choice.type = player1column[choice].type;
        break;
    case 2:
        prev_choice.color = player2column[choice].color;
        prev_choice.type = player2column[choice].type;
        break;
    case 3:
        prev_choice.color = player3column[choice].color;
        prev_choice.type = player3column[choice].type;
        break;
    case 4:
        prev_choice.color = player4column[choice].color;
        prev_choice.type = player4column[choice].type;
        break;
    }
    step++;

    if (prev_choice.type == SKIP){

        switch (turn){/*get player column smaller*/
        case 1:
            for (int i = choice; i < player1cards; i++){
                player1column[i].color = player1column[i + 1].color;
                player1column[i].type = player1column[i + 1].type;
            }
            player1cards--;
            break;
        case 2:
            for (int i = choice; i < player2cards; i++){
                player2column[i].color = player2column[i + 1].color;
                player2column[i].type = player2column[i + 1].type;
            }
            player2cards--;
            break;
        case 3:
            for (int i = choice; i < player3cards; i++){
                player3column[i].color = player3column[i + 1].color;
                player3column[i].type = player3column[i + 1].type;
            }
            player3cards--;
            break;
        case 4:
            for (int i = choice; i < player4cards; i++){
                player4column[i].color = player4column[i + 1].color;
                player4column[i].type = player4column[i + 1].type;
            }
            player4cards--;
            break;
        }

        if (reverse_activated == 0){
            turn++;
            if (turn > MAXplayer) turn = 1;
            turn++;
        }
        else
        {
            turn--;
            if (turn < 1) turn = MAXplayer;
            turn--;
        }
        new_card_activator = 1;

        choice = -1;
        system("cls");
    }
    else if(prev_choice.type == REVERSE){
        new_card_activator = 1;
        turn--;
        if (turn < 1) turn = MAXplayer;
        choice = -1;
        system("cls");
        reverse_activated = 1;
    }
    else{
        new_card_activator = 0;
        turn++;
        if (turn > MAXplayer) turn = 1;
        choice = -1;
        system("cls");
    }
    if (new_card_activator == 0){
        switch (turn){/*get player column smaller*/
        case 1:
            for (int i = choice; i < player1cards; i++){
                player1column[i].color = player1column[i + 1].color;
                player1column[i].type = player1column[i + 1].type;
            }
            player1cards--;
            break;
        case 2:
            for (int i = choice; i < player2cards; i++){
                player2column[i].color = player2column[i + 1].color;
                player2column[i].type = player2column[i + 1].type;
            }
            player2cards--;
            break;
        case 3:
            for (int i = choice; i < player3cards; i++){
                player3column[i].color = player3column[i + 1].color;
                player3column[i].type = player3column[i + 1].type;
            }
            player3cards--;
            break;
        case 4:
            for (int i = choice; i < player4cards; i++){
                player4column[i].color = player4column[i + 1].color;
                player4column[i].type = player4column[i + 1].type;
            }
            player4cards--;
            break;
        }
    }
    new_card_activator = 0;




    //other moves
    while (1){
        if (player1cards == 0 || player2cards == 0 || player3cards == 0 || player4cards == 0){
            if (player1cards == 0){
                printf("GAME OVER! \n");
                printPLAYER_NAME(1);
                printf(" WINS!\n\n\n");
            }
            if (player2cards == 0){
                printf("GAME OVER! \n");
                printPLAYER_NAME(2);
                printf(" WINS!\n\n\n");
            }
            if (player3cards == 0){
                printf("GAME OVER! \n");
                printPLAYER_NAME(3);
                printf(" WINS!\n\n\n");
            }
            if (player4cards == 0){
                printf("GAME OVER! \n");
                printPLAYER_NAME(4);
                printf(" WINS!\n\n\n");
            }
            return 0;
        }

        printf("      UNO: ULTIMATE   \n");
        switch (MAXplayer){/*print how much card are remain*/
        case 2:
            printf("-------------------------\n");
            printPLAYER_NAME(1);
            printf(" cards remain: %d\n", player1cards);
            printPLAYER_NAME(2);
            printf(" cards remain: %d\n", player2cards);
            printf("-------------------------\n\n\n");
            break;
        case 3:
            printf("-------------------------\n");
            printPLAYER_NAME(1);
            printf(" cards remain: %d\n", player1cards);
            printPLAYER_NAME(2);
            printf(" cards remain: %d\n", player2cards);
            printPLAYER_NAME(3);
            printf(" cards remain: %d\n", player3cards);
            printf("-------------------------\n\n\n");
            break;
        case 4:
            printf("-------------------------\n");
            printPLAYER_NAME(1);
            printf(" cards remain: %d\n", player1cards);
            printPLAYER_NAME(2);
            printf(" cards remain: %d\n", player2cards);
            printPLAYER_NAME(3);
            printf(" cards remain: %d\n", player3cards);
            printPLAYER_NAME(4);
            printf(" cards remain: %d\n", player4cards);
            printf("-------------------------\n\n\n");
            break;
        }
        if (turn != 1 && turn != MAXplayer){
            if (last_player_without_new_card == turn && action_rule_reverse_aftermatch != 1){
                printPLAYER_NAME(turn - 1);
            }
            else{
                printPLAYER_NAME(last_player_without_new_card);
            }
            printf(" ");
            printCARD(prev_choice.color, prev_choice.type);
            //printf("\n");
        }
        if (turn == 1){
            if (last_player_without_new_card == turn && action_rule_reverse_aftermatch != 1){
                printPLAYER_NAME(MAXplayer);
            }
            else{
                printPLAYER_NAME(last_player_without_new_card);
            }
            printf(" ");
            printCARD(prev_choice.color, prev_choice.type);
            //printf("\n");
        }
        if (turn == MAXplayer){
            if (last_player_without_new_card == turn && action_rule_reverse_aftermatch != 1){
                printPLAYER_NAME(MAXplayer - 1);
            }
            else{
                printPLAYER_NAME(last_player_without_new_card);
            }
            printf(" ");
            printCARD(prev_choice.color, prev_choice.type);
            //printf("\n");
        }
        printPLAYER_NAME(turn);
        printf(" attacking...\n\n");
        switch (turn){/*print player column*/
            case 1:
                printPLAYER_COLUMN(player1column, player1cards);
                break;
            case 2:
                printPLAYER_COLUMN(player2column, player2cards);
                break;
            case 3:
                printPLAYER_COLUMN(player3column, player3cards);
                break;
            case 4:
                printPLAYER_COLUMN(player4column, player4cards);
                break;
        }
        printf("Choice: ");
        scanf("%d", &choice);
        switch(turn){/*fix choice*/
        case 1:
            if (choice < 0 || choice > player1cards){
                while(choice < 0 || choice > player1cards){
                    printf("You don't have that card! Try again!");
                    scanf("%d", &choice);
                }
            }
            break;
        case 2:
            if (choice < 0 || choice > player2cards){
                while(choice < 0 || choice > player2cards){
                    printf("You don't have that card! Try again!");
                    scanf("%d", &choice);
                }
            }
            break;
        case 3:
            if (choice < 0 || choice > player3cards){
                while(choice < 0 || choice > player3cards){
                    printf("You don't have that card! Try again!");
                    scanf("%d", &choice);
                }
            }
            break;
        case 4:
            if (choice < 0 || choice > player4cards){
                while(choice < 0 || choice > player4cards){
                    printf("You don't have that card! Try again!");
                    scanf("%d", &choice);
                }
            }
            break;
        }
        if (choice == 0){
            action_rule_reverse_aftermatch = 1;
            int last_player_without_new_card = turn - 1;
            new_card_activator = 1;
            switch(turn){
            case 1:
                player1cards++;
                player1column[player1cards].color = rand()%4+101;
                player1column[player1cards].type = rand()%9;// rand()%14спец карты не работают
                break;
            case 2:
                player2cards++;
                player2column[player2cards].color = rand()%4+101;
                player2column[player2cards].type = rand()%9;
                break;
            case 3:
                player3cards++;
                player3column[player3cards].color = rand()%4+101;
                player3column[player3cards].type = rand()%9;
                break;
            case 4:
                player4cards++;
                player4column[player4cards].color = rand()%4+101;
                player4column[player4cards].type = rand()%9;
                break;
            }
        }


        if (new_card_activator == 0){
         switch (turn){/*current choice filling (with player choice)*/
            case 1:
                curr_choice.color = player1column[choice].color;
                curr_choice.type = player1column[choice].type;
                break;
            case 2:
                curr_choice.color = player2column[choice].color;
                curr_choice.type = player2column[choice].type;
                break;
            case 3:
                curr_choice.color = player3column[choice].color;
                curr_choice.type = player3column[choice].type;
                break;
            case 4:
                curr_choice.color = player4column[choice].color;
                curr_choice.type = player4column[choice].type;
                break;
            }

            switch (turn){/*previous choice filling(with player choice)*/
            case 1:
                prev_choice.color = player1column[choice].color;
                prev_choice.type = player1column[choice].type;
                break;
            case 2:
                prev_choice.color = player2column[choice].color;
                prev_choice.type = player2column[choice].type;
                break;
            case 3:
                prev_choice.color = player3column[choice].color;
                prev_choice.type = player3column[choice].type;
                break;
            case 4:
                prev_choice.color = player4column[choice].color;
                prev_choice.type = player4column[choice].type;
                break;
            }
        }
        if (rule(prev_choice.color, prev_choice.type, curr_choice.color, curr_choice.type) == 1){
            new_card_activator = 0;
            switch (turn){/*get player column smaller*/
            case 1:
                for (int i = choice; i < player1cards; i++){
                    player1column[i].color = player1column[i + 1].color;
                    player1column[i].type = player1column[i + 1].type;
                }
                player1cards--;
                break;
            case 2:
                for (int i = choice; i < player2cards; i++){
                    player2column[i].color = player2column[i + 1].color;
                    player2column[i].type = player2column[i + 1].type;
                }
                player2cards--;
                break;
            case 3:
                for (int i = choice; i < player3cards; i++){
                    player3column[i].color = player3column[i + 1].color;
                    player3column[i].type = player3column[i + 1].type;
                }
                player3cards--;
                break;
            case 4:
                for (int i = choice; i < player4cards; i++){
                    player4column[i].color = player4column[i + 1].color;
                    player4column[i].type = player4column[i + 1].type;
                }
                player4cards--;
                break;
            }
            if (action_rule_reverse_aftermatch == 0){
                turn++;
                if (turn > MAXplayer) turn = 1;
                turn++;
            }
            else{
                turn--;
                if (turn < 1) turn = MAXplayer;
                turn--;
            }
            step++;

            choice = -1;
            system("cls");
            continue;
        }
        if (new_card_activator == 0){
            switch (turn){/*get player column smaller*/
            case 1:
                for (int i = choice; i < player1cards; i++){
                    player1column[i].color = player1column[i + 1].color;
                    player1column[i].type = player1column[i + 1].type;
                }
                player1cards--;
                break;
            case 2:
                for (int i = choice; i < player2cards; i++){
                    player2column[i].color = player2column[i + 1].color;
                    player2column[i].type = player2column[i + 1].type;
                }
                player2cards--;
                break;
            case 3:
                for (int i = choice; i < player3cards; i++){
                    player3column[i].color = player3column[i + 1].color;
                    player3column[i].type = player3column[i + 1].type;
                }
                player3cards--;
                break;
            case 4:
                for (int i = choice; i < player4cards; i++){
                    player4column[i].color = player4column[i + 1].color;
                    player4column[i].type = player4column[i + 1].type;
                }
                player4cards--;
                break;
            }
            last_player_without_new_card = turn;
        }
        new_card_activator = 0;
        if (reverse_activated == 0 && action_rule_reverse_aftermatch == 0){
            turn++;
            if (turn > MAXplayer) turn = 1;
        }
        else{
            turn--;
            if (turn < 1) turn = MAXplayer;
        }
        reverse_activated = 0;
        choice = -1;
        system("cls");
        step++;
    }
}
