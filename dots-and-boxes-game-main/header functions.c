#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
char Array[12][12];
int n=12;
char row , col;
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
int undo_counter=0;
int undoTemp;

typedef struct{
int scores;
char name[5];

}player;

typedef struct{
int score1,score2,moves1,moves2,remain,timee,turn;
char name1[20],name2[20];
int choice ;
}data;

player players[10];


void print_array(char Array[12][12],int n ){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

                    if(Array[i][j]==-60||Array[i][j]==124 || Array[i][j]==49 ){
                        SetColor(4);
                        printf("%c ",Array[i][j]);
                        SetColor(15);
                    }
                    else if (Array[i][j]==-51||Array[i][j]==-70 || Array[i][j]==50){
                        SetColor(1);
                        printf("%c ",Array[i][j]);
                        SetColor(15);
                    }

                    else{

            printf("%c ",Array[i][j]);
                    }

        }
        printf("\n");
    }
}

void initial_grid (int n){

    for(int i=1;i<n;i+=2){
        for(int j=1;j<n;j+=2){
            Array[i][j]=254;
        }
    }


    for(int i=1;i<n;i+=2){
        for(int j=2;j<n;j+=2){
            Array[i][j]=' ';
        }
    }

    for(int i=2;i<n;i+=2){
        for(int j=1;j<n;j+=2){
            Array[i][j]=' ';
        }
    }

    for(int i=2;i<n;i+=2){
        for(int j=2;j<n;j+=2){
            Array[i][j]=' ';
        }
    }

    for(int i=1;i<n;i++){
        Array[0][i]=i+96;
    }

    for(int i=1;i<n;i++){
        Array[i][0]=i+96;
    }

    Array[0][0]=' ';

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%c ",Array[i][j]);
        }
        printf("\n");
    }

}

//----------------------------------------------
//--------------------------------------------------
int moves(char Array[12][12], int *p , int *c,int *t,int *z,int *ch){//z >> remaining
    int a;
    int b = 0 ;
    printf("for undo >> 'un' ");
     printf("for redo >> 're' \n");
     printf("for save >> 'ss' ");
     printf("for menu >> 'me'\n");
    printf("Enter row then column : ");
    scanf(" %c %c",&row,&col);
    row = tolower(row);
    col = tolower(col);
    row-=96;
    col-=96;
    if(row==21 && col== 14){ //undo
            if(undo_counter>0){
                *z+=1;
                undo_counter-=1;
                Array[undo.R[undo_counter]][undo.C[undo_counter]]=' ' ;
                Array[undo.r1[undo_counter]][undo.c1[undo_counter]] = ' ';
                Array[undo.r2[undo_counter]][undo.c2[undo_counter]] = ' ';

                if(*t == undo.turn[undo_counter]){
                    *p+=1;
                }

            for(int i=0;i<undo_counter;i++){ //return color
                if(undo.R[i]==undo.r1[undo_counter]+1 && undo.C[i]==undo.c1[undo_counter]){
                    Array[undo.r1[undo_counter]+1][undo.c1[undo_counter]]=undo.bar[i];
                }
                if(undo.R[i]==undo.r1[undo_counter] && undo.C[i]==undo.c1[undo_counter]+1){
                    Array[undo.r1[undo_counter]][undo.c1[undo_counter]+1]=undo.bar[i];
                }
                if(undo.R[i]==undo.r1[undo_counter]-1 && undo.C[i]==undo.c1[undo_counter]){
                    Array[undo.r1[undo_counter]-1][undo.c1[undo_counter]]=undo.bar[i];
                }
                if(undo.R[i]==undo.r1[undo_counter] && undo.C[i]==undo.c1[undo_counter]-1){
                    Array[undo.r1[undo_counter]][undo.c1[undo_counter]-1]=undo.bar[i];
                }
                if(undo.R[i]==undo.r2[undo_counter]+1 && undo.C[i]==undo.c2[undo_counter]){
                    Array[undo.r2[undo_counter]+1][undo.c2[undo_counter]]=undo.bar[i];
                }
                if(undo.R[i]==undo.r2[undo_counter] && undo.C[i]==undo.c2[undo_counter]+1){
                    Array[undo.r2[undo_counter]][undo.c2[undo_counter]+1]=undo.bar[i];
                }
                if(undo.R[i]==undo.r2[undo_counter]-1 && undo.C[i]==undo.c2[undo_counter]){
                    Array[undo.r2[undo_counter]-1][undo.c2[undo_counter]]=undo.bar[i];
                }
                if(undo.r2[i]==undo.r2[undo_counter] && undo.c2[i]==undo.c2[undo_counter]-1){
                    Array[undo.r2[undo_counter]][undo.c2[undo_counter]-1]=undo.bar[i];
                }
         if(*ch==2){
                 *z-=1;
                 *t=2;
                 *p-=1;
                Array[undo.R[undo_counter]][undo.C[undo_counter]]=undo.bar[undo_counter];
                Array[undo.r1[undo_counter]][undo.c1[undo_counter]] = undo.box1[undo_counter];
                Array[undo.r2[undo_counter]][undo.c2[undo_counter]] =undo.box2[undo_counter];
                undo_counter+=1;
                Array[undo.R[undo_counter]][undo.C[undo_counter]]=undo.bar[undo_counter];
                Array[undo.r1[undo_counter]][undo.c1[undo_counter]] = undo.box1[undo_counter];
                Array[undo.r2[undo_counter]][undo.c2[undo_counter]] =undo.box2[undo_counter];
                }
            }

            }
    return 0;
    }else if(row==18 && col== 5){    //redo
        if(undoTemp>undo_counter){
            *z-=1;
             Array[undo.R[undo_counter]][undo.C[undo_counter]]=undo.bar[undo_counter];
             Array[undo.r1[undo_counter]][undo.c1[undo_counter]] = undo.box1[undo_counter];
             Array[undo.r2[undo_counter]][undo.c2[undo_counter]] =undo.box2[undo_counter];
             if(*t == undo.turn[undo_counter]){
                    *p+=1;}

                if(undo.box1[undo_counter]==50){
                     Array[undo.R[undo_counter]][undo.C[undo_counter]]=' ';
                     Array[undo.r1[undo_counter]+1][undo.c1[undo_counter]]=205;
                     Array[undo.r1[undo_counter]][undo.c1[undo_counter]+1]=186;
                     Array[undo.r1[undo_counter]-1][undo.c1[undo_counter]]=205;
                     Array[undo.r1[undo_counter]][undo.c1[undo_counter]-1]=186;
                }
                if(undo.box1[undo_counter]==49){
                     Array[undo.R[undo_counter]][undo.C[undo_counter]]=' ';
                     Array[undo.r1[undo_counter]+1][undo.c1[undo_counter]]=196;
                     Array[undo.r1[undo_counter]][undo.c1[undo_counter]+1]=124;
                     Array[undo.r1[undo_counter]-1][undo.c1[undo_counter]]=196;
                     Array[undo.r1[undo_counter]][undo.c1[undo_counter]-1]=124;
                }
                if(undo.box2[undo_counter]==50){
                     Array[undo.R[undo_counter]][undo.C[undo_counter]]=' ';
                     Array[undo.r2[undo_counter]+1][undo.c2[undo_counter]]=205;
                     Array[undo.r2[undo_counter]][undo.c2[undo_counter]+1]=186;
                     Array[undo.r2[undo_counter]-1][undo.c2[undo_counter]]=205;
                     Array[undo.r2[undo_counter]][undo.c2[undo_counter]-1]=186;
                }
                if(undo.box2[undo_counter]==49){
                     Array[undo.R[undo_counter]][undo.C[undo_counter]]=' ';
                     Array[undo.r2[undo_counter]+1][undo.c2[undo_counter]]=196;
                     Array[undo.r2[undo_counter]][undo.c2[undo_counter]+1]=124;
                     Array[undo.r2[undo_counter]-1][undo.c2[undo_counter]]=196;
                     Array[undo.r2[undo_counter]][undo.c2[undo_counter]-1]=124;
                }
                 if(*ch==2){

                 *z-=1;
                 *t=2;
                 *p-=1;
                Array[undo.R[undo_counter]][undo.C[undo_counter]]=undo.bar[undo_counter];
                Array[undo.r1[undo_counter]][undo.c1[undo_counter]] = undo.box1[undo_counter];
                Array[undo.r2[undo_counter]][undo.c2[undo_counter]] =undo.box2[undo_counter];
                undo_counter+=1;
                Array[undo.R[undo_counter]][undo.C[undo_counter]]=undo.bar[undo_counter];
                Array[undo.r1[undo_counter]][undo.c1[undo_counter]] = undo.box1[undo_counter];
                Array[undo.r2[undo_counter]][undo.c2[undo_counter]] =undo.box2[undo_counter];
                }
                undo_counter+=1;
                }
                return 0;
    }

    else if(row==13 && col== 5){
        return 5;
    }
    else if(row==19 &&col==19){
        return 3;
    }

    else{

    if(row>n-1 || col>n-1){
        printf("invalid move!\n");
        *p = *p + 1;
        return 0;
    }
    else {
    if (Array[row][col] == ' '){
        if(row%2!=0 && col%2==0){
                if(*t==1){
                Array[row][col] = 196;
                undo.turn[undo_counter]=*t;
                undo.R[undo_counter]=row;
                undo.C[undo_counter]=col;
                undo.bar[undo_counter]=196;
                }
                else{
                Array[row][col] = 205;
                 undo.turn[undo_counter]=*t;
                undo.R[undo_counter]=row;
                undo.C[undo_counter]=col;
                undo.bar[undo_counter]=205;}

           check(Array,row,col,&a,&b);
            undo_counter+=1;
            undoTemp = undo_counter;
           *p = a + *p ;
           *c = b ;
           return 1;
           }

        else if(row%2==0 && col%2!=0){

                if(*t==1){
                Array[row][col] = 124;
                 undo.turn[undo_counter]=*t;
                undo.R[undo_counter]=row;
                undo.C[undo_counter]=col;
                undo.bar[undo_counter]=124;}
                else{
                Array[row][col] = 186;
                undo.turn[undo_counter]=*t;
                undo.R[undo_counter]=row;
                undo.C[undo_counter]=col;
                undo.bar[undo_counter]=186;}

            check(Array,row,col,&a,&b);
            undo_counter+=1;
            undoTemp = undo_counter;
            *p = a + *p ;
            *c=b;
          return 1;
        }
        else{
            printf("Invalid place!\n");
                *p = *p + 1;
            return 0;
        }
        }
    else{printf("Invalid place!\n");
        *p = *p + 1;
        return 0;}
    }
    }
}
//-------------------------------------------------------------
void check(char Array[12][12],char x , char y , int *a , int *b  ){           //x<<row,y<<col
    *a=0;
if(Array[x][y]==124 || Array[x][y]==-70){
        if((Array[x-1][y+1]==-60 || Array[x-1][y+1]==-51) && (Array[x+1][y+1]==-60||Array[x+1][y+1]==-51) && (Array[x][y+2]==124||Array[x][y+2]==-70)){
            if(Array[x][y]==124){
            Array[x][y+1]=49;
            Array[x-1][y+1]=-60;
            Array[x+1][y+1]=-60;
            Array[x][y+2]=124;
            undo.box1[undo_counter]=49;
            undo.r1[undo_counter]=x;
            undo.c1[undo_counter]=y+1;
            printf("\n%d %d %d\n",undo.box1[undo_counter],undo.r1[undo_counter],undo.c1[undo_counter]);
            *b+=1;
            }
            else{
            Array[x][y+1]=50;
            Array[x-1][y+1]=-51;
            Array[x+1][y+1]=-51;
            Array[x][y+2]=-70;
            undo.box1[undo_counter]=50;
            undo.r1[undo_counter]=x;
            undo.c1[undo_counter]=y+1;
            printf("\n%d %d %d\n",undo.box1[undo_counter],undo.r1[undo_counter],undo.c1[undo_counter]);
            *b+=1;

            }
            *a =1;

        }
        if((Array[x-1][y-1]==-60||Array[x-1][y-1]==-51) && (Array[x+1][y-1]==-60 || Array[x+1][y-1]==-51 )&& (Array[x][y-2]==124||Array[x][y-2]==-70)){
            if(Array[x][y]==124){
            Array[x][y-1]=49;
            Array[x-1][y-1]=-60;
            Array[x+1][y-1]=-60;
            Array[x][y-2]=124;
            undo.box2[undo_counter]=49;
            undo.r2[undo_counter]=x;
            undo.c2[undo_counter]=y-1;
            printf("\n%d %d %d\n",undo.box2[undo_counter],undo.r2[undo_counter],undo.c2[undo_counter]);
            *b+=1;
            }
            else{
            Array[x][y-1]=50;
            Array[x-1][y-1]=-51;
            Array[x+1][y-1]=-51;
            Array[x][y-2]=-70;
            undo.box2[undo_counter]=50;
            undo.r2[undo_counter]=x;
            undo.c2[undo_counter]=y-1;
            printf("\n%d %d %d\n",undo.box2[undo_counter],undo.r2[undo_counter],undo.c2[undo_counter]);
            *b+=1;
            }
            *a=1;

        }

}
else{
    if ((Array[x-1][y+1]==124 || Array[x-1][y+1]==-70 ) && (Array[x-1][y-1]==124 || Array[x-1][y-1]==-70) && (Array[x-2][y]==-60||Array[x-2][y]==-51)){
       if(Array[x][y]==-60){
         Array[x-1][y]=49;
         Array[x-1][y+1]=124;
         Array[x-1][y-1]=124;
         Array[x-2][y]=-60;
        undo.box1[undo_counter]=49;
        undo.r1[undo_counter]=x-1;
        undo.c1[undo_counter]=y;
        printf("\n%d %d %d\n",undo.box1[undo_counter],undo.r1[undo_counter],undo.c1[undo_counter]);
         *b+=1;
       }
       else{
         Array[x-1][y]=50;
         Array[x-1][y+1]=-70;
         Array[x-1][y-1]=-70;
         Array[x-2][y]=-51;
        undo.box1[undo_counter]=50;
        undo.r1[undo_counter]=x-1;
        undo.c1[undo_counter]=y;
        printf("\n%d %d %d\n",undo.box1[undo_counter],undo.r1[undo_counter],undo.c1[undo_counter]);
         *b+=1;
       }

        *a=1;

    }
    if((Array[x+1][y+1]==124||Array[x+1][y+1]==-70) && (Array[x+1][y-1]==124 || Array[x+1][y-1]==-70) && (Array[x+2][y]==-60||Array[x+2][y]==-51)){
       if(Array[x][y]== -60){
        Array[x+1][y]=49;
        Array[x+1][y+1]=124;
        Array[x+1][y-1]=124;
        Array[x+2][y]=-60;
         undo.box2[undo_counter]=49;
            undo.r2[undo_counter]=x+1;
            undo.c2[undo_counter]=y;
            printf("\n%d %d %d\n",undo.box2[undo_counter],undo.r2[undo_counter],undo.c2[undo_counter]);
        *b+=1;
       }
       else{
        Array[x+1][y]=50;
        Array[x+1][y+1]=-70;
        Array[x+1][y-1]=-70;
        Array[x+2][y]=-51;
         undo.box2[undo_counter]=50;
            undo.r2[undo_counter]=x+1;
            undo.c2[undo_counter]=y;
            printf("\n%d %d %d\n",undo.box2[undo_counter],undo.r2[undo_counter],undo.c2[undo_counter]);
        *b+=1;
       }
        *a =1;

    }

}
}

void SetColor(int ForgC)
{
     WORD wColor;
     //This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}


int random (int n){
    int randomm;
    randomm=((rand()%(n-1))+1);
   return randomm;
}


int computer (char Array[12][12],int *p,int *c, int n){
int index1 , index2;
 while(n>0){
    index1 = random(n);
     index2 = random(n);
if(index1 < n && index2 <n && ((index1%2 !=0 && index2 %2 == 0)|| (index2%2 !=0 && index1 %2 == 0)) && Array[index1][index2]==' '){
     break;
}}
int a=0,b=0;
        if(index1%2!=0 && index2%2==0){
                Array[index1][index2] = -51;
                undo.turn[undo_counter]=2;
                undo.R[undo_counter]=index1;
                undo.C[undo_counter]=index2;
                undo.bar[undo_counter]=-51;


           check(Array,index1,index2,&a,&b);
           undo_counter+=1;
           *p = a + *p ;
           *c = b ;
           return 1;
        }

        else if(index1%2==0 && index2%2!=0){
                Array[index1][index2] = -70;
                undo.turn[undo_counter]=2;
                undo.R[undo_counter]=index1;
                undo.C[undo_counter]=index2;
                undo.bar[undo_counter]=-70
                ;

            check(Array,index1,index2,&a,&b);
            undo_counter+=1;
            *p = a + *p ;
             *c= b;
          return 1;
        }

}



double timer(clock_t start){


    clock_t end;     //>>>> clock_t is a type(class)
    double time_used;
    int minutes , seconds ;
    end = clock();
    time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
     minutes = time_used /60 ;
     seconds = time_used -(minutes *60);

    SetColor(2);
    printf("                Time :  %d : %d \n",minutes,seconds);
return time_used;
}



void read_scores(){

 FILE *h ;
h= fopen("scores_data.txt","a+");

for(int i = 0;i<50;i++){
    fscanf(h,"%d %s",&players[i].scores,&players[i].name);
}
for (int i = 50; i>=0; i--)
	{
		for (int j = i - 1; j >=0; j--)
		{
			if(players[i].scores < players[j].scores)
			{
				player temp = players[i];
				players[i] = players[j];
				players[j] = temp;
			}

		}
	}

int counter=0;
for(int i =50;i>=0; i--){
    if(players[i].scores!=0&&players[i].scores>=1&&players[i].scores<=25){
            printf("\t\t\t%s >> %d \n\n",players[i].name,players[i].scores);
            counter++;}
    if(counter==10){break;}
}

fclose(h);


}

void add_player(int score,char name[20]){
FILE *h ;
h= fopen("scores_data.txt","a+");

fprintf(h,"%d ",score);
fputs(name,h);
fprintf(h,"\n");

fclose(h);
}

void end_game(int score1 , int score2,char p1[20],char p2[20],int play ){


                        SetColor(5);
                        printf("            THE GAME ENDED ! \n");

                        if(score1>score2){
                            SetColor(4);
                            printf("            THE WINNER IS : %s WITH SCORE %d \n",p1,score1);
                             add_player(score1,p1);

                        }
                        else if (score2>score1){
                                SetColor(1);
                            printf("            THE WINNER IS : %s WITH SCORE %d \n",p2,score2);
                            if(play!=-1){
                                add_player(score2,p2);

                        }
}
                        else {
                            printf("    DRAW !\n");
                        }




}

data load(int choice1,int choice2){
    data loaded_data;
FILE*n;
if (choice1==1){
    if (choice2==1){
        n=fopen("saved1.txt","r");
                    if(n == NULL){
        /* File not created hence exit */
        printf("not saved.\n");
        exit(EXIT_FAILURE);
    }
    }
    else if(choice2==2){
        n=fopen("saved2.txt","r");
                    if(n == NULL){
        /* File not created hence exit */
        printf("not saved.\n");
        exit(EXIT_FAILURE);
    }
    }
    else if(choice2==3){
        n=fopen("saved3.txt","r");
                    if(n == NULL){
        /* File not created hence exit */
        printf("not saved.\n");
        exit(EXIT_FAILURE);
    }
    }
    else {
        printf("error");
         exit(EXIT_FAILURE);
    }
}
else if (choice1==2){
            if (choice2==1){
        n=fopen("saved4.txt","r");
            if(n == NULL){
        /* File not created hence exit */
        printf("not saved.\n");
        exit(EXIT_FAILURE);
    }
    }
    else if(choice2==2){
        n=fopen("saved5.txt","r");
        if(n == NULL){
        /* File not created hence exit */
        printf("not saved.\n");
        exit(EXIT_FAILURE);
    }
    }
    else if(choice2==3){
        n=fopen("saved6.txt","r");
        if(n == NULL){
        /* File not created hence exit */
        printf("not saved.\n");
        exit(EXIT_FAILURE);
    }
    }
    else {
        printf("error");
        exit(EXIT_FAILURE);
    }

}

fscanf(n,"%d %d %d %d %d %d %d %d",&loaded_data.timee,&loaded_data.moves1,&loaded_data.moves2,&loaded_data.turn,&loaded_data.remain,&loaded_data.score1,&loaded_data.score2,&loaded_data.choice);
for(int i=0 ;i<12;i++){
for(int j=0;j<12;j++){

    fscanf(n,"%c",&Array[i][j]);
}
}
print_array(Array,12);
fscanf(n,"%s%s",&loaded_data.name1,&loaded_data.name2);

return loaded_data;
}
