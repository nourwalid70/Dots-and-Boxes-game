#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "functions.h"
#include <windows.h>
#include <time.h>

char Array[12][12];
char row , col;

    struct{
    char name[20];
    int score;
    int moves ;
    char color;
    }player1,player2;
save game ;
int main()
{
clock_t start ;
int pORc;
    int back1=1;int choice3;
    while(back1 == 1){
            player1.moves=0;player1.score=0;
            player2.moves=0;player2.score=0;
    int n;
       printf("                            Enter the number of your choice.\n");
    printf("                                        main menu\n1: Start  game.\n2: Top 10.\n3: Exit.\n");
    int choice1 ;
    scanf(" %d", &choice1);
    switch(choice1){
        case 1: {printf("1: Beginner.\n2: Expert.\n");
                int choice2;
                scanf("%d", &choice2);
                switch(choice2){
                    case 1: n=6;break;
                    case 2: n=12;break;
                    default: printf("Invalid choice!\n");break;
                }
                if(choice2!=1&&choice2!=2){break;}
                    printf("1: new game .\n2:Load saved game.\n");
                    int choice4;
                    int choice3;
                    scanf("%d",&choice4);
                    if(choice4==1){
                printf("1: Two players.\n2: One player.\n");
                scanf("%d",&choice3);
                if(choice3==1){
                    printf("Enter player 1 name :  ");
                    fflush(stdin);
                    gets(player1.name);
                    printf("\nEnter player 2 name :  ");
                    fflush(stdin);
                    gets(player2.name);
                    player1.color="red";
                    player2.color="blue";
                    pORc=1;
                }
                else if (choice3==2){
                    printf("Enter player 1 name :  ");
                    fflush(stdin);
                    gets(player1.name);
                    player2.name[20]="computer";
                    player1.color="red";
                    player2.color="blue";
                    pORc=-1;
                    player2.score=0;
                }
                else{break;}

                // initializing array.
                    initial_grid(n);
                     start = clock();
                    }
                    else if(choice4!=1&&choice4!=2){break;}
                //--------------------------------------------
                    int remaining,returnValue;
                    if(n==12){
                        remaining = 60;
                    }else{
                        remaining = 12;
                    }
                    int p1 ,p2,turn,turn2;
                    int c =0 ;
if (choice4==2){

        printf("1:saved1.\n2:saved2\n3:saved3\n");
        int choice5;
        scanf("%d",&choice5);
        data loaded=load(choice2,choice5);

    player1.moves=loaded.moves1 ; player1.score=loaded.score1 ;
    memcpy(player1.name,loaded.name1,20);
    player2.moves=loaded.moves2 ; player2.score=loaded.score2 ;
    memcpy(player2.name,loaded.name2,20);
    remaining=loaded.remain;
    start = loaded.timee;
    turn=loaded.turn;
    turn2=loaded.turn;
    choice3=loaded.choice;


}
                        while(remaining>0){
                            p1=1;

                        for (int i=0;i<p1;i++){
                        if(remaining==0){break;}
                       if(returnValue =! 0){
                        if(choice4==2&&turn2==2){break;}
                        else{
                            turn = 1 ;
                            turn2=1;
                        }
                        }
                        SetColor(4);
                        printf("It's %s turn \n",player1.name);
                        c=0;
                        returnValue = moves(Array,&p1,&c,&turn,&remaining,&choice3);
                       if(returnValue==5 ||returnValue==3){break;}
                        player1.moves+=returnValue;
                        SetColor(15);
                        player1.score +=c ;
                        print_array(Array,n);
                        SetColor(4);
                        printf("%s moves : %d       %s score :%d \n",player1.name,player1.moves,player1.name,player1.score);
                        SetColor(15);
                        SetColor(1);
                        printf("%s moves : %d       %s score :%d \n",player2.name,player2.moves,player2.name,player2.score);
                        SetColor(15);
                        remaining-=returnValue;

                        SetColor(2);
                        printf("                Remaining moves: %d \n", remaining);
                         timer(start);


                            }

                            if(returnValue==5){
                                SetColor(15);
                    printf("back to menu >> 1\nexit >>> 2\n");
                    scanf("%d",&back1);
                                    break;}


                        p2=1;
                        for (int i=0;i<p2;i++){
                            if(returnValue==3){break;}
                        if(remaining==0){break;}

                        if(returnValue =! 0){
                            turn = 2 ;
                            turn2=2;
                        }

                        SetColor(1);
                        printf("It's %s turn \n",player2.name);
                        c=0;
                        if(choice3==2){
                        returnValue = computer(Array,&p2,&c, n);
                        }
                        else if (choice3==1){
                        returnValue = moves(Array,&p2,&c,&turn,&remaining,&choice3);
                        }
                        if(returnValue==5||returnValue==3){break;}
                        SetColor(15);
                        player2.score +=c;
                        player2.moves +=returnValue;
                        if(choice3==2){
                            Sleep(1200);
                        }
                        print_array(Array,n);
                        SetColor(4);
                        printf("%s moves : %d       %s score :%d \n",player1.name,player1.moves,player1.name,player1.score);
                        SetColor(15);
                        SetColor(1);
                        printf("%s moves : %d       %s score :%d \n",player2.name,player2.moves,player2.name,player2.score);
                        SetColor(15);

                        remaining-=returnValue;
                        SetColor(2);
                        printf("                Remaining moves: %d \n", remaining);
                        timer(start);


                                }
                                if(returnValue==5){
                                SetColor(15);
                    printf("back to menu >> 1\nexit >>> 2\n");
                    scanf("%d",&back1);
                                    break;}


                        else if (returnValue==3){
                            save game;
                            game.game_time=timer(start);
                            game.movess1=player1.moves;
                            game.movess2=player2.moves;
                            game.player_turn=turn;
                            game.rem_moves=remaining;
                            game.scoore1=player1.score;
                            game.scoore2=player2.score;
                            memcpy(game.name1,player1.name,20);
                            memcpy(game.name2,player2.name,20);
                            game.choice=choice3;
                            for(int i=0;i<12;i++){
                                for(int j=0;j<12;j++){
                            game.sl_array[i][j]=Array[i][j];
                                }
                            }
                                       FILE *n ;
                        printf("Choose place to save\n1:saved1.\n2:saved2.\n3:saved3.\n");
                        int choice5;
                        scanf("%d",&choice5);

                     if(choice2==1){
                        if (choice5==1){
                            n=fopen("saved1.txt","w");
                        }
                        else if(choice5==2){
                            n=fopen("saved2.txt","w");
                        }
                        else if(choice5==3){
                            n=fopen("saved3.txt","w");
                        }
                        else {
                            printf("error");return 0;
                        }
                     }
                     else if (choice2==2){

                            if (choice5==1){
                                n=fopen("saved4.txt","w");
                                }
                            else if(choice5==2){
                                n=fopen("saved5.txt","w");
                                }
                            else if(choice5==3){
                                n=fopen("saved6.txt","w");
                                }
                            else {
                                printf("error");return 0;
                                }
                                            }

	fprintf(n,"%d %d %d %d %d %d %d %d",game.game_time,game.movess1,game.movess2,game.player_turn,game.rem_moves,game.scoore1,game.scoore2,game.choice);

    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
             fprintf(n,"%c",Array[i][j]);
        }
    }

    fputs(player1.name ,n);
   fprintf(n,"%c",32);
    fputs(player2.name,n);
    fclose(n);

                        SetColor(15);
                    printf("back to menu >> 1\nexit >>> 2\n");
                    scanf("%d",&back1);
                            break;
                        }
                   turn2=1;
                        }
                        if(returnValue==5||returnValue==3){break;}

                        printf("\n\n");

                    end_game( player1.score ,player2.score,player1.name,player2.name,pORc);
                                SetColor(15);
                    printf("back to menu >> 1\nexit >>> 2\n");
                    scanf("%d",&back1);


                            break;}



                //---------------------------------------------------------------

        case 2:{
            SetColor(2);
            printf("\t\t\t Top 10\n\n");

              read_scores();

                SetColor(15);
                printf("back to menu >> 1\nexit >>> 2\n");
                scanf("%d",&back1);
                break;}
        case 3:return 0;
                break;
     default: printf("Invalid choice!\n");break;

    }
        }

    return 0;
}
