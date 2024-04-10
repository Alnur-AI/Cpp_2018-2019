#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

const int A = 1;
const int B = 2;
const int C = 3;
const int D = 4;
const int E = 5;

FILE *answers;
FILE *questions;
FILE *results;


int calculatingHowMuchQuestionsTotal(){
    int questionCounterTotal = 0;
    answers = fopen("answers.txt","r");
    if (answers == NULL) exit(1);

    char buf[1024];
    for (int i = 0; ;i++)
    {
        fgets(buf,1024,answers);
        if (buf[0]=='-')
        {
            fclose(answers);
            return questionCounterTotal;
        }
        questionCounterTotal++;
    }
}
int calculatingHowMuchQuestionsTotalRank_A(){
    questions = fopen("test.txt","r");
    if (questions == NULL) exit(1);
    char buffer [1024];
    int questionCounterRANK_A = 0;
    for (int i = 0; ;i++)
    {
        fgets(buffer,1024,questions);
        if (buffer[0] == 'R' && buffer[1] == 'A' && buffer[2] == 'N' && buffer[3] == 'K' && buffer[4] == ' ' && buffer[5] == 'A')
        {
            questionCounterRANK_A++;
        }
        else if (buffer[0] == '-' && buffer[1] == '-' && buffer[2] == '-' && buffer[3] == '-' && buffer[4] == '-')
        {
            fclose(questions);
            return questionCounterRANK_A;
        }
    }
}
int calculatingHowMuchQuestionsTotalRank_B(){
    questions = fopen("test.txt","r");
    if (questions == NULL) exit(1);
    char buffer [1024];
    int questionCounterRANK_B = 0;
    for (int i = 0; ;i++)
    {
        fgets(buffer,1024,questions);
        if (buffer[0] == 'R' && buffer[1] == 'A' && buffer[2] == 'N' && buffer[3] == 'K' && buffer[4] == ' ' && buffer[5] == 'B')
        {
            questionCounterRANK_B++;
        }
        else if (buffer[0] == '-' && buffer[1] == '-' && buffer[2] == '-' && buffer[3] == '-' && buffer[4] == '-')
        {
            fclose(questions);
            return questionCounterRANK_B;
        }
    }
}
int calculatingHowMuchQuestionsTotalRank_C(){
    questions = fopen("test.txt","r");
    if (questions == NULL) exit(1);
    char buffer [1024];
    int questionCounterRANK_C = 0;
    for (int i = 0; ;i++)
    {
        fgets(buffer,1024,questions);
        if (buffer[0] == 'R' && buffer[1] == 'A' && buffer[2] == 'N' && buffer[3] == 'K' && buffer[4] == ' ' && buffer[5] == 'C')
        {
            questionCounterRANK_C++;
        }
        else if (buffer[0] == '-' && buffer[1] == '-' && buffer[2] == '-' && buffer[3] == '-' && buffer[4] == '-')
        {
            fclose(questions);
            return questionCounterRANK_C;
        }
    }
}
int calculatingHowMuchQuestionsTotalRank_D(){
    questions = fopen("test.txt","r");
    if (questions == NULL) exit(1);
    char buffer [1024];
    int questionCounterRANK_D = 0;
    for (int i = 0; ;i++)
    {
        fgets(buffer,1024,questions);
        if (buffer[0] == 'R' && buffer[1] == 'A' && buffer[2] == 'N' && buffer[3] == 'K' && buffer[4] == ' ' && buffer[5] == 'D')
        {
            questionCounterRANK_D++;
        }
        else if (buffer[0] == '-' && buffer[1] == '-' && buffer[2] == '-' && buffer[3] == '-' && buffer[4] == '-')
        {
            fclose(questions);
            return questionCounterRANK_D;
        }
    }
}
int calculatingHowMuchQuestionsTotalRank_E(){
    questions = fopen("test.txt","r");
    if (questions == NULL) exit(1);
    char buffer [1024];
    int questionCounterRANK_E = 0;
    for (int i = 0; ;i++)
    {
        fgets(buffer,1024,questions);
        if (buffer[0] == 'R' && buffer[1] == 'A' && buffer[2] == 'N' && buffer[3] == 'K' && buffer[4] == ' ' && buffer[5] == 'E')
        {
            questionCounterRANK_E++;
        }
        else if (buffer[0] == '-' && buffer[1] == '-' && buffer[2] == '-' && buffer[3] == '-' && buffer[4] == '-')
        {
            fclose(questions);
            return questionCounterRANK_E;
        }
    }
}


void fillCorrectAnswersInSheet(char a[]){
    char buf[1024];
    answers = fopen("answers.txt", "r");
    if (answers == NULL) exit(1);
    for (int i = 0; ; i++)
    {
        fgets(buf, 1024, answers);
        if (buf[2] == '-')
        {
            fclose(answers);
            return;
        }
        a[i] = buf[2];
    }
}
void makeArrayEmpty(char array[],int howMuchElements ){
    for (int i = 0; i < howMuchElements; i++)
    {
        array[i] = '*';
    }
    return;
}

int RANKchecker(int Ai, int Bi, int Ci, int Di, int Ei){
    if (Ai == 0 && Bi == 0 && Ci == 0 && Di == 0 && Ei == 0) return 0;
    int array[5] = {Ai, Bi, Ci, Di, Ei};
    for (int i = 0; i < 5; i++)
    {
        if (array[i]!=0) return i + 1;
    }
}

int main()
{
    printf("Press Enter to start the test:\n(DON'T PUT ANY LETTER, JUST ENTER, PLEASE!)\n");
    char waste = getchar();


    int currentRANK;
    char currentAnswer;
    int currentQuestion = 1;
    int solvedQuestions = 0;

    int howMuchQuestions       = calculatingHowMuchQuestionsTotal();
    int howMuchQuestionsRank_A = calculatingHowMuchQuestionsTotalRank_A();
    int howMuchQuestionsRank_B = calculatingHowMuchQuestionsTotalRank_B();
    int howMuchQuestionsRank_C = calculatingHowMuchQuestionsTotalRank_C();
    int howMuchQuestionsRank_D = calculatingHowMuchQuestionsTotalRank_D();
    int howMuchQuestionsRank_E = calculatingHowMuchQuestionsTotalRank_E();

    int leftQuestionsRANK_A = howMuchQuestionsRank_A;
    int leftQuestionsRANK_B = howMuchQuestionsRank_B;
    int leftQuestionsRANK_C = howMuchQuestionsRank_C;
    int leftQuestionsRANK_D = howMuchQuestionsRank_D;
    int leftQuestionsRANK_E = howMuchQuestionsRank_E;

    char correctAnswers [howMuchQuestions];
    char studentAnswers [howMuchQuestions];

    fillCorrectAnswersInSheet(correctAnswers);
    makeArrayEmpty(studentAnswers, howMuchQuestions);

    //printf("Hello! Let's start the test!\n\n");
    //printf("%s\n%s\nTotal:%d\n (1)A:%d\n (2)B:%d\n (3)C:%d\n (4)D:%d\n (5)E:%d\n\n", correctAnswers, studentAnswers, howMuchQuestions, leftQuestionsRANK_A, leftQuestionsRANK_B, leftQuestionsRANK_C, leftQuestionsRANK_D, leftQuestionsRANK_E);

    int valueRANKchecker = RANKchecker(leftQuestionsRANK_A, leftQuestionsRANK_B, leftQuestionsRANK_C, leftQuestionsRANK_D, leftQuestionsRANK_E);
    if (valueRANKchecker == 0)
    {
        printf("There are no questions! ");
        return 0;
    }

    char buffer[1024];
    questions = fopen("test.txt","r");
    if (questions == NULL) exit(1);
    fgets(buffer, 1024, questions);

    while (valueRANKchecker != 0){

        system("cls");
        valueRANKchecker = RANKchecker(leftQuestionsRANK_A, leftQuestionsRANK_B, leftQuestionsRANK_C, leftQuestionsRANK_D, leftQuestionsRANK_E);
        printf("  Right answers: %s\nStudent answers: %s\n Total:%d\n (1)A:%d\n (2)B:%d\n (3)C:%d\n (4)D:%d\n (5)E:%d\n\n", correctAnswers, studentAnswers, howMuchQuestions, leftQuestionsRANK_A, leftQuestionsRANK_B, leftQuestionsRANK_C, leftQuestionsRANK_D, leftQuestionsRANK_E);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
        printf("Your current rank: %d\n\n", valueRANKchecker );
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);


        while (buffer[0] != 'R' && buffer[1] != 'A' && buffer[2] != 'N' && buffer[3] != 'K'){
            fgets(buffer, 1024, questions);
            //printf("%s",buffer);
            if (buffer[0] == '-' && buffer[1] == '-' && buffer[2] == '-' ){
                fclose(questions);
                questions = fopen("test.txt","r");
                if (questions == NULL) exit(1);
                currentQuestion = 1;
            }

        }


        if(buffer[0] == 'R' && buffer[1] == 'A' && buffer[2] == 'N' && buffer[3] == 'K' && buffer [5] == 'A' && valueRANKchecker == A){
                do{
                    printf("%s",buffer);
                    fgets(buffer, 1024, questions);
                }while (buffer[0] != '|' && buffer[1] != '|' && buffer[2] != '|' );

                printf("\nMy answer is: ");
                currentAnswer = _getch();
                //currentAnswer = getchar();
                //scanf("%c",&currentAnswer);
                studentAnswers[currentQuestion - 1] = currentAnswer;
                currentQuestion++;
                solvedQuestions++;
                leftQuestionsRANK_A--;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                printf(":::::ITERATION COMPLITED:::::\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                fgets(buffer, 1024, questions);
                continue;
        }
        if(buffer[0] == 'R' && buffer[1] == 'A' && buffer[2] == 'N' && buffer[3] == 'K' && buffer [5] == 'B' && valueRANKchecker == B){
                do{
                    printf("%s",buffer);
                    fgets(buffer, 1024, questions);
                }while (buffer[0] != '|' && buffer[1] != '|' && buffer[2] != '|' );
                printf("\nMy answer is: ");
                currentAnswer = _getch();
                //currentAnswer = getchar();
                //scanf("%c",&currentAnswer);
                studentAnswers[currentQuestion - 1] = currentAnswer;
                currentQuestion++;
                solvedQuestions++;
                leftQuestionsRANK_B--;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                printf(":::::ITERATION COMPLITED:::::\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                fgets(buffer, 1024, questions);
                continue;
        }
        if(buffer[0] == 'R' && buffer[1] == 'A' && buffer[2] == 'N' && buffer[3] == 'K' && buffer [5] == 'C' && valueRANKchecker == C){
                do{
                    printf("%s",buffer);
                    fgets(buffer, 1024, questions);
                }while (buffer[0] != '|' && buffer[1] != '|' && buffer[2] != '|' );

                printf("\nMy answer is: ");
                currentAnswer = _getch();
                //currentAnswer = getchar();
                //scanf("%c",&currentAnswer);
                studentAnswers[currentQuestion - 1] = currentAnswer;
                currentQuestion++;
                solvedQuestions++;
                leftQuestionsRANK_C--;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                printf(":::::ITERATION COMPLITED:::::\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                fgets(buffer, 1024, questions);
                continue;
        }
        if(buffer[0] == 'R' && buffer[1] == 'A' && buffer[2] == 'N' && buffer[3] == 'K' && buffer [5] == 'D' && valueRANKchecker == D){
                do{
                    printf("%s",buffer);
                    fgets(buffer, 1024, questions);
                }while (buffer[0] != '|' && buffer[1] != '|' && buffer[2] != '|' );

                printf("\nMy answer is: ");
                currentAnswer = _getch();
                //currentAnswer = getchar();
                //scanf("%c",&currentAnswer);
                studentAnswers[currentQuestion - 1] = currentAnswer;
                currentQuestion++;
                solvedQuestions++;
                leftQuestionsRANK_D--;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                printf(":::::ITERATION COMPLITED:::::\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                fgets(buffer, 1024, questions);
                continue;
        }
        if(buffer[0] == 'R' && buffer[1] == 'A' && buffer[2] == 'N' && buffer[3] == 'K' && buffer [5] == 'E' && valueRANKchecker == E){
                do{
                    printf("%s",buffer);
                    fgets(buffer, 1024, questions);
                }while (buffer[0] != '|' && buffer[1] != '|' && buffer[2] != '|' );

                printf("\nMy answer is: ");
                currentAnswer = _getch();
                //currentAnswer = getchar();
                //scanf("%c",&currentAnswer);
                studentAnswers[currentQuestion - 1] = currentAnswer;
                currentQuestion++;
                solvedQuestions++;
                leftQuestionsRANK_E--;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                printf(":::::ITERATION COMPLITED:::::\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                fgets(buffer, 1024, questions);
                continue;
        }

        fgets(buffer, 1024, questions);

        currentQuestion++;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
        printf(":::::ITERATION COMPLITED:::::\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    }

    printf("Press Enter to end the test and save results:\n(DON'T PUT ANY LETTER, JUST ENTER, PLEASE!)\n");
    waste = getchar();

    fclose(questions);
    return 0;
}
