#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<windows.h>
void typeEffect(const char *text, int delay)
{
    while (*text)
    {
        printf("%c", *text);
        fflush(stdout);
        Sleep(delay);
        text++;
    }
}
const char *name(int i)
{
    char *ch[] = {"invalid", "rock", "paper", "scissor"};
    if (i >= 1 && i <= 3)
        return ch[i]; // if true input.
    return ch[0];     // if not true input.
}
int possible(int x, int y)
{
    if (x > 3|| y>3)
    {
        printf("\t\t!!INVALID ROUND !!\n");
    }
    else if (x == y)
    {
        printf("\t\t!! its draw, try again !!\n");
    }
}
int main()
{
    system("color 0A");
    printf("------------------------------------------------------------------------------------------------\n");
    int mode, computer, player, n, m;
    srand(time(0));
    typeEffect("RULE BOOK:-\nROCK beats SCISSORS\nSCISSOR beats PAPER\nPAPER beats ROCK\n",30);
    typeEffect("choose:\t1:- rock\t2:- paper\t3:- scissor\n",30);
    for (int i = 1; i <= 5; i++)
    {
        printf("------------------------------------------------------------------------------------------------\n");
        typeEffect("choosyour mode:\t1:- player mode\t\t2:-computer mode\t",30);
        scanf("%d", &mode);
        getchar(); 
        if (mode == 1)
        {
            char player[2][50];
            int p1 = 0, p2 = 0;
            for (int i = 0; i < 2; i++)
            {
                printf("Enter player %d name: ", i + 1);
                fgets(player[i], 50, stdin);
                player[i][strcspn(player[i], "\n")] = '\0'; 
            }
            for (int i = 1; i <= 3; i++)
            {
                printf("----------------------------| ROUND%d |--------------------------------------------------------\n", i);
                printf("enter the choice of %s : ", player[0]);
                scanf("%d", &m);
                printf("enter the choice of %s : ", player[1]);
                scanf("%d", &n);
                printf("%s choose: %s \t\t", player[0], name(m)); 
                printf("%s choose : %s \n", player[1], name(n));
                possible(m,n);
                if ((m == 1 && n == 3) || (m > n))
                {
                    printf("\t\t !! %s win !!\n", player[0]);
                    p1++;
                }
                else if ((m == 3 && n == 1) || (m < n))
                {
                    printf("\t\t!! %s win !!\n", player[1]);
                    p2++;
                }
            }
            typeEffect("--------------------------------| RESULT| ------------------------------------------------------\n",30);
            printf("%s score: %d\n%s score: %d\n", player[0], p1, player[1], p2);
            if (p1 > p2)
                printf("!! %s is winner !!\n", player[0]);
            else if (p1 == p2)
                typeEffect("BOTH ARE EQUALLY WIN !!\n",30);
            else
                printf("!! %s is winner !! \n", player[1]);
        }
        else if (mode == 2)
        {
            char player[1][20];
            int p1 = 0, p2 = 0;
            printf("Enter player name: ",30);
            fgets(player[0], 20, stdin);
            player[0][strcspn(player[0], "\n")] = '\0';
            for (int i = 1; i <= 3; i++)
            {
                printf("------------------------------| ROUND-%d| ------------------------------------------------------- \n", i);
                printf("enter the choice of %s :", player[0]);
                scanf("%d", &m);
                int c = rand() % 3 + 1;
                printf("%s choose: %s \t\t", player[0], name(m)); 
                printf("computer choose: %s\n", name(c));
                possible(m, c);
                if ((m == 1 && c == 3) || (m > c))
                {
                    printf("\t\t!! %s win!!\n", player[0]);
                    p1++;
                }
                else if ((m == 3 && c == 1) || (m < c))
                {
                    printf("\t\t!! computer win !!\n");
                    p2++;
                }
            }
            printf("--------------------------------| RESULT |------------------------------------------------------\n");
            printf("%s score: %d\ncomputer score: %d\n", player[0], p1, p2);
            if (p1 > p2)
                printf("!! %s is winner !!\n", player[0]);
            else if (p1 == p2)
                typeEffect("BOTH ARE EQUALLY WIN !!\n",30);
            else
                printf("!! COMPUTER is winner !!\n");
        
        }
        else
        {
            typeEffect("\t\t--INVALID INPUT---- TRY AGAIN--",30);
            break;
        }
        typeEffect("------------------------------| THAT WAS REALLY FUN |-----------------------------------------\n",30);
        typeEffect("\t\t\t  | WOULD YOU LIKE TO PLAY AGAIN |\n",30);
        typeEffect("\t\t\t\t1:- yes\t 2:-no\t",30);
        scanf("%d", &n);
        if (n == 2)
        {
            typeEffect("\t\t\t!! HOPE YOU ENJOY THIS GAME !!\n \t\t\t\t!! HAVE A NICE DAY !!",30);
            break;
        }
        else{
            typeEffect("---------------------------| YOU ARE ENJOYING THIS GAME |---------------------------------------\n",30);
        typeEffect("\t\t\t  | LET'S MAKE IT MORE INTRESTING |\n",30);
        }
    }
    return 0;
}
