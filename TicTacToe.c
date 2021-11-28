/*
Writer: Sappir Bohbot.

This is basic Tic Tac Toe game i made during C programing course in Udemy (https://www.udemy.com/course/c-programming-for-beginners-/).
for now the game contains only one mode - two players. Next i will add singal player mod with three difficult levels.
*/
#include <stdio.h>
#include <stdlib.h>

int Player,choise;
char x = 'X';
char o = 'O';
char table[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

//Functions declaretion:
int winCheck();
void display();
void markBoard(char mark);


int main()
{  
    int result = -1;
    char mark;
    Player = 2;
    printf("Hello!\n");

    while(result == -1)
    {
        Player++;
        display();
        Player = (Player %2)? 1 : 2 ;
        printf("Player %d, enter number: ",Player);
        scanf("%d", &choise);

        mark = (Player == 1)? x : o;
        markBoard(mark);
        result = winCheck();
       
    }
    if(result == 0 ){ printf("It's a Drow!\n");}
    else{
        printf("The winner is Player %d!\n",Player);
    }
    
}

void markBoard(char mark)
{
    if(choise == 1 && table[0][0]=='1'){
        table[0][0] = mark;
    }
    else if(choise == 2 && table[0][1]=='2'){
        table[0][1] = mark;
    }
    else if(choise == 3 && table[0][2]=='3'){
        table[0][2] = mark;
    }
    else if(choise == 4 && table[1][0]=='4'){
        table[1][0] = mark;
    }
    else if(choise == 5 && table[1][1]=='5'){
        table[1][1] = mark;
    }
    else if(choise == 6 && table[1][2]=='6'){
        table[1][2] = mark;
    }
    else if(choise == 7 && table[2][0]=='7'){
        table[2][0] = mark;
    }
    else if(choise == 8 && table[2][1]=='8'){
        table[2][1] = mark;
    }   
     else if(choise == 9 && table[2][2]=='9'){
        table[2][2] = mark;
    }
    else
    {
        printf("Invalid Move!\n");
        Player--;
    }

}

void display()
{
    system("clear");
    printf("\nTicTacToe\n");
    printf("\nPlayer 1 (X), Player 2 (O)\n\n");

    printf(" %c | %c | %c \n",table[0][0],table[0][1],table[0][2]);
    printf("___|___|___\n");
    printf(" %c | %c | %c \n",table[1][0],table[1][1],table[1][2]);
    printf("___|___|___\n");
    printf(" %c | %c | %c \n",table[2][0],table[2][1],table[2][2]);
    printf("   |   |   \n");
}

int winCheck()
{
    /********************************
      1 = game over with a result.
     -1 = game in progress.
      0 = game over with no result. 
    ********************************/
    int ans = -1;
    if(table[0][0] == table[0][1] && table[0][1] == table[0][2]){ans = 1;}
    else if(table[1][0] == table[1][1] && table[1][1] == table[1][2]){ans = 1;}
    else if(table[2][0] == table[2][1] && table[2][1] == table[2][2]){ans = 1;}

    else if(table[0][0] == table[1][0] && table[1][0] == table[2][0]){ans = 1;}
    else if(table[0][1] == table[1][1] && table[1][1] == table[2][1]){ans = 1;}
    else if(table[0][2] == table[1][2] && table[1][2] == table[2][2]){ans = 1;}

    else if(table[0][0] == table[1][1] && table[1][1] == table[2][2]){ans = 1;}
    else if(table[0][2] == table[1][1] && table[1][1] == table[2][0]){ans = 1;}

    else if(table[0][0] != '1' && table[0][1] != '2' && table[0][2] != '3' && table[1][0] != '4' && table[1][1] != '5' && table[1][2] != '6' &&
                table[2][0] != '7' && table[2][1] != '8' && table[2][2] != '9')
            {
                ans = 0;
            }     
    return ans;
}
