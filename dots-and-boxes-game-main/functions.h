#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <windows.h>
#include <time.h>
typedef struct{
    char sl_array[12][12];
    int rem_moves;
    int scoore1 , movess1;
    int scoore2, movess2;
    int player_turn;
    int game_time;
    char name1[20],name2[20];
    int choice;

}save;


struct{
    char turn[60];
    char R[60];
    char C[60];
    char bar[60];
    char box1[60];
    char r1[60];
    char c1[60];
    char box2[60];
    char r2[60];
    char c2[60];
}undo;
typedef struct{
int score1,score2,moves1,moves2,remain,timee,turn;
char name1[20],name2[20];
int choice ;
}data;

void print_array(char Array[12][12],int n );
void initial_grid (int n);
int moves(char Array[12][12],int *p , int *c,int*t,int *z,int *ch);//z:ziada,p:player,C:undo counter,t:turn,c:t2fil w leha 3laka bal b
void check(char Array[12][12],int row , int col, int *a, int *b);
int computer (char Array[12][12],int *p, int *c, int n);
int random (int n);
void SetColor(int ForgC) ;
double timer(clock_t start) ;
void read_scores();
void add_player(int score,char name[20]);
void end_game(int score1 , int score2,char p1[20] ,char p2[20] ,int play);
data load(int choice1 , int choice2);
// p is counter for moves in for loop for each player
//a lw 2fl box +1 move for the player
//b lw 2fl box +1 score
#endif // FUNCTIONS_H



