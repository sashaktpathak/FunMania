#include<stdio.h>
#include<conio.h>
#include<windows.h>
int i = 0;
static int result = -2;
static char choice;
char store_choice[9];
int matrix[3][3];
static int wins_1 = 0;
static int wins_2 = 0;
char repetation_choice;
char print_matrix[9]={'1','2','3','4','5','6','7','8','9'};
static int ch_counter = 0;
const int frame_counter_x = 80;
const int frame_counter_y = 28;
COORD coordinate = {0,0};
void gotoxy(int,int);
void drawFrame();
void drawFrame2();
void drawFrame3();
void drawFrame4();
void fillrect1(int);
void fillrect2(int,int);
void fillrect3();
void initialize();
void value_putter(int,int);
void drawBoard(int,int,int);
void set_win()
{
 wins_1 = 0;
 wins_2 = 0;
}
void main_game()
{
    static int player = 1;
 do
 {
 int cnt =0;
 player=1;
 system("cls");
 initialize();
 while(cnt<9)
 {
  drawBoard(player,wins_1,wins_2);
  system("cls");
  cnt++;
  result=checkwin();
  if(result!=-1)
    break;
  if(player==1)
    player=2;
  else
    player=1;
 }
 if(result==1)
 {
   system("cls");
   printf("Player %d Wins !!!!!!!!!!!!!!",player);
   if(player==1)
    wins_1++;
   else
    wins_2++;
 }
 else
 {
     system("cls");
     printf("Game Tie!!!>");
     wins_1++;
     wins_2++;
 }
 printf("\n\n\n\t\t\tPress y to ReStart\t");
 repetation_choice=getch();
 }while(repetation_choice=='y');
 system("cls"); main();
}
int main4(int argc,char *argv[])
{
 main_game();
 return 0;
}
int checkwin()
{
    if (print_matrix[0] == print_matrix[1] && print_matrix[1] == print_matrix[2])
        return 1;

    else if (print_matrix[3] == print_matrix[4] && print_matrix[4] == print_matrix[5])
        return 1;

    else if (print_matrix[6] == print_matrix[7] && print_matrix[7] == print_matrix[8])
        return 1;

    else if (print_matrix[0] == print_matrix[3] && print_matrix[3] == print_matrix[6])
        return 1;

    else if (print_matrix[1] == print_matrix[4] && print_matrix[4] == print_matrix[7])
        return 1;

    else if (print_matrix[2] == print_matrix[5] && print_matrix[5] == print_matrix[8])
        return 1;

    else if (print_matrix[0] == print_matrix[4] && print_matrix[4] == print_matrix[8])
        return 1;

    else if (print_matrix[2] == print_matrix[4] && print_matrix[4] == print_matrix[6])
        return 1;

    else if (print_matrix[0] != '1' && print_matrix[1] != '2' && print_matrix[2] != '3' && print_matrix[3] != '4' && print_matrix[4] != '5' && print_matrix[5] != '6' && print_matrix[6] != '7' && print_matrix[7] != '8' && print_matrix[8] != '9')
        return 0;
    else
        return  - 1;
}
void drawBoard(int player, int wins_1, int wins_2)
{
  drawFrame();
  drawFrame2();
  drawFrame3();
  drawFrame4();
  gotoxy(12,10);
  for(i=0;i<41;i++)
    printf("=");
  gotoxy(12,18);
  for(i=0;i<41;i++)
    printf("=");
  for(i=0;i<5;i++)
    {
      gotoxy(22,5+i);
      printf("|");
      gotoxy(23,5+i);
      printf("|");
    }
    for(i=0;i<5;i++)
    {
      gotoxy(39,5+i);
      printf("|");
      gotoxy(40,5+i);
      printf("|");
    }
    for(i=0;i<17;i++)
    {
      gotoxy(22,7+i);
      printf("|");
      gotoxy(23,7+i);
      printf("|");
    }
    for(i=0;i<17;i++)
    {
      gotoxy(39,7+i);
      printf("|");
      gotoxy(40,7+i);
      printf("|");
    }
    gotoxy(15,7);
    printf("%c",print_matrix[0]);
    gotoxy(29,7);
    printf("%c",print_matrix[1]);
    gotoxy(44,7);
    printf("%c",print_matrix[2]);
    gotoxy(15,14);
    printf("%c",print_matrix[3]);
    gotoxy(29,14);
    printf("%c",print_matrix[4]);
    gotoxy(44,14);
    printf("%c",print_matrix[5]);
    gotoxy(15,22);
    printf("%c",print_matrix[6]);
    gotoxy(29,22);
    printf("%c",print_matrix[7]);
    gotoxy(44,22);
    printf("%c",print_matrix[8]);
    fillrect1(player);
    fillrect2(wins_1,wins_2);
    fillrect3();
    rep_inp :
    gotoxy(3,frame_counter_y);
    printf("Enter 1 - 9, Player %d to Occupy the Block!!\t\t",player);
    choice=getch();
    if(choice=='q'||choice=='Q')
        {system("cls"); main();}
    if(choice=='r'||choice=='R')
        {system("cls"); main4(1,'a');}
    else if(choice>='1'&&choice<='9')
    {
      for(i=0;i<ch_counter;i++)
           {if(choice==store_choice[i])
             goto rep_inp;}
           if(i==ch_counter)
           {
            printf("%c",choice);
            store_choice[ch_counter]=choice;
            ch_counter++;
           }
    }
    else
        goto rep_inp;
    value_putter(choice,player);

}
void value_putter(int ch,int player)
{
    int prep =1;
    if(player == 1)
    prep = 1;
    else
    prep = 2;
    if(ch=='1')
        {matrix[0][0]=prep;  if(prep==1) print_matrix[0]='X'; else print_matrix[0]='O';}
    if(ch=='2')
        {matrix[0][1]=prep;  if(prep==1) print_matrix[1]='X'; else print_matrix[1]='O';}
    if(ch=='3')
        {matrix[0][2]=prep;  if(prep==1) print_matrix[2]='X'; else print_matrix[2]='O';}
    if(ch=='4')
        {matrix[1][0]=prep;  if(prep==1) print_matrix[3]='X'; else print_matrix[3]='O';}
    if(ch=='5')
        {matrix[1][1]=prep;  if(prep==1) print_matrix[4]='X'; else print_matrix[4]='O';}
    if(ch=='6')
        {matrix[1][2]=prep;  if(prep==1) print_matrix[5]='X'; else print_matrix[5]='O';}
    if(ch=='7')
        {matrix[2][0]=prep;  if(prep==1) print_matrix[6]='X'; else print_matrix[6]='O';}
    if(ch=='8')
        {matrix[2][1]=prep;  if(prep==1) print_matrix[7]='X'; else print_matrix[7]='O';}
    if(ch=='9')
        {matrix[2][2]=prep;  if(prep==1) print_matrix[8]='X'; else print_matrix[8]='O';}

}
//================================================ FRAME WORK ===========================================================================
void drawFrame()
{
 for(i=0;i<frame_counter_x;i++)
    printf("=");
 gotoxy(0,1);
 for(i=0;i<frame_counter_y;i++)
    printf("|\n");
 for(i=1;i<frame_counter_y+1;i++)
    {
     gotoxy(frame_counter_x-1,i);
     printf("|\n");
    }
 gotoxy(0,frame_counter_y+1);
 for(i=0;i<frame_counter_x;i++)
    printf("=");
}
void drawFrame2()
{
 gotoxy(frame_counter_x+1,0);
 for(i=frame_counter_x;i<frame_counter_x+35;i++)
    printf("=");
 for(i=1;i<frame_counter_y/3;i++)
  {
   gotoxy(frame_counter_x+1,i);
   printf("|\n");
  }
  for(i=1;i<frame_counter_y/3;i++)
  {
   gotoxy(frame_counter_x+35,i);
   printf("|\n");
  }
 gotoxy(frame_counter_x+1,frame_counter_y/3);
 for(i=0;i<35;i++)
    printf("=");
}
void drawFrame3()
{
  for(i=1;i<frame_counter_y/4;i++)
  {
   gotoxy(frame_counter_x+1,i+frame_counter_y/3);
   printf("|\n");
  }
  for(i=1;i<frame_counter_y/4;i++)
  {
   gotoxy(frame_counter_x+35,i+frame_counter_y/3);
   printf("|\n");
  }
 gotoxy(frame_counter_x+1,frame_counter_y/3+(frame_counter_y/4));
 for(i=0;i<35;i++)
    printf("=");
}
void drawFrame4()
{
  for(i=1;i<(5*frame_counter_y/12)+2;i++)
  {
   gotoxy(frame_counter_x+1,i+(7*frame_counter_y)/12);
   printf("|\n");
  }
  for(i=1;i<(5*frame_counter_y/12)+2;i++)
  {
   gotoxy(frame_counter_x+35,i+7*frame_counter_y/12);
   printf("|\n");
  }
 gotoxy(frame_counter_x+1,frame_counter_y+1);
 for(i=0;i<35;i++)
    printf("=");
}
void fillrect1(int player)
{
    gotoxy(frame_counter_x+4,3);
    if(player==1)
    {
        printf("Player 1(X)      <--");
        gotoxy(frame_counter_x+4,5);
        printf("Player 2(O)      WAIT");
    }
    else
    {
        printf("Player 1(X)      WAIT");
        gotoxy(frame_counter_x+4,5);
        printf("Player 2(O)      <--");
    }
}
void fillrect2(int wins_1,int wins_2)
{
    gotoxy(frame_counter_x+4,12);
    printf("No. of Wins Player 1  -->  %d",wins_1);
    gotoxy(frame_counter_x+4,14);
    printf("No. of Wins Player 2  -->  %d",wins_2);
}
void fillrect3()
{
    gotoxy(frame_counter_x+2,18);
    printf("Rules:");
    gotoxy(frame_counter_x+3,20);
    printf("1. Player 1 -> X  ");
    gotoxy(frame_counter_x+3,21);
    printf("2. Player 2 -> O  ");
    gotoxy(frame_counter_x+3,22);
    printf("3. Enter Square No. to ");
    gotoxy(frame_counter_x+6,23);
    printf("Occupy Specific Block");
    gotoxy(frame_counter_x+3,24);
    printf("4. Occupied Block Numbers");
    gotoxy(frame_counter_x+7,25);
    printf("Cannot be Repeated");
    gotoxy(frame_counter_x+3,26);
    printf("5. Press Q to Exit Anytime");
    gotoxy(frame_counter_x+3,27);
    printf("6. Press R to Restart Game");
    gotoxy(frame_counter_x+7,28);
    printf("AnyTime!");
}
void gotoxy(int x,int y)
{
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinate);
}
void initialize()
{
    char k;
    for(k='1',i=0;k<='9',i<9;i++,k++)
     print_matrix[i]=k;
    result = -2;
    ch_counter=0;
    for(i=0;i<9;i++)
        store_choice[i]='-1';
}
