#include<stdio.h>
#include<dos.h>
#include<windows.h>
#include<MMSystem.h>
int flag_beginning=-1;
void main()
{
int i;
char chh;
PlaySound(TEXT("music.wav"), NULL, SND_ASYNC);
if(flag_beginning==-1)
{
 main_begin();
 flag_beginning=0;
}
system("cls");
printf("\t\t\t\tPress T to Play\n");
gotoxy(0,3);
printf("\t");
for(i=0;i<41;i++)
printf("-");
printf("\n");

for(i=4;i<15;i++)
{
gotoxy(0,i);
printf("\t|\t\t\t\t\t|");
}
printf("\n\t");
for(i=0;i<41;i++)
printf("-");
printf("\n\n\n");
printf("GAME :: TIC-TAC-TOE\t\tPRICE :: $ 1.99\n\n\n\n");
printf("Press ::\n\n");
printf("\t\tB to Buy\n");
printf("\t\tS to Sell\n");
printf("\t\tD for Demo\n");
printf("\t\tL to login as Admin\n");
printf("\t\tE to Exit");
for(i=5;i<14;i++)
{
gotoxy(0,i);
if(i==9)
printf("\t\t   O  ||    X   ||  O");
else
printf("\t\t      ||\t||");
}

gotoxy(0,7);
printf("\t\t");
for(i=0;i<24;i++)
printf("=");
gotoxy(0,11);
printf("\t\t");
for(i=0;i<24;i++)
printf("=");

for(i=4;i<15;i++)
{
gotoxy(0,i);
printf("\t|");
}

printf("\n\t");
for(i=0;i<41;i++)
printf("-");
printf("\n\n\n");
gotoxy(12,22);
chh=NULL;
chh=getch();
if(chh=='t'||chh=='T')
 {set_win(); main_game();}
else if(chh=='b'||chh=='B')
 {system("cls"); main5();}
else if(chh=='s'||chh=='S')
 {system("cls"); main_2();}
else if(chh=='d'||chh=='D')
 {demo();}
else if(chh=='l'||chh=='L')
 {login();}
 else if(chh=='e'||chh=='E')
    exit(0);
 else
 {system("cls"); main();}
}
void justframe()
{
    system("cls");
    int i;
    for(i=0;i<55;i++)
        printf("==");
    for(i=1;i<27;i++)
    {gotoxy(0,i); printf("|");}
    for(i=1;i<27;i++)
    {gotoxy(109,i); printf("|");}
    gotoxy(0,27);
    for(i=0;i<55;i++)
    printf("==");
}
void demo()
{
    justframe();
    char ch_demo;
    gotoxy(5,3);
    printf("We are Currently Offering These Games For Demo :) ");
    gotoxy(7,7);
    printf("1. TIC-TAC-TOE\t\t\tPress P Play and B to Go Back");
    gotoxy(15,22);
    printf("MORE GAME WILL BE ADDED SOON. STAY TOONED ;)\t\tPress E to Exit");
    gotoxy(15,9);
    ch_demo=getch();
    if(ch_demo=='p'||ch_demo=='P')
    {set_win(); main_game();}
    else if(ch_demo=='b'||ch_demo=='B')
    {system("cls"); main();}
    else if(ch_demo=='e'||ch_demo=='E')
    exit(0);
    else
        demo();
}
void admin_entry()
{
 system("cls");
 char game_name_entry[30];
 char publisher_entry[20];
 int rating,price;
 FILE *fp;
 fp=fopen("games.txt","a");
 justframe();
 gotoxy(3,3);
 printf("===================GAME ENTRY==================\n");
 gotoxy(5,7);
 printf("Game Name  :");
 gotoxy(5,9);
 printf("Publisher  :");
 gotoxy(5,11);
 printf("Price  :");
 gotoxy(5,13);
 printf("Rating  :");
 gotoxy(1,25);
 printf("AT any Time type 'BACK' in any field or invalid Entry in Integer Entry to Go Back");
 gotoxy(22,7);
 scanf("%s",game_name_entry);
 if(strcmpi(game_name_entry,"back")==0)
    {system("cls"); main();}
 gotoxy(22,9);
 scanf("%s",publisher_entry);
 if(strcmpi(publisher_entry,"back")==0)
    {system("cls"); main();}
 gotoxy(18,11);
 scanf("%d",&price);
 if(!(price>=0&&price<=1000000))
    {system("cls"); main();}
 gotoxy(18,13);
 scanf("%d",&rating);
 if(!(rating>=0&&rating<=1000000))
    {system("cls"); main();}
 fprintf(fp,"\n%s %s %d %d",game_name_entry,publisher_entry,price,rating);
 system("cls");
 gotoxy(20,7);
 printf("Saving Game Information Please WAIT !!");
 getch();
 gotoxy(20,9);
 printf("Please Upload the Game to Following Cloud Storage Link :)");
 gotoxy(25,11);
 printf("https://funmania.com/get_game?=ae23nd8808.asp");
 gotoxy(25,15);
 printf(" Successfully Added Game As Admin :)");
 getch();
 fclose(fp);
 main();
}
void admin_game_del(char ch_game[30])
{
    FILE *fp,*fw;
    int flag_del=-1;
    char filename[] = "games.txt";
    fp=fopen("games.txt","r");
    fw=fopen("temp.txt","w");
    int pp,rat;
    char gn[30],pub[20];
    while(fscanf(fp,"%s%s%d%d",gn,pub,&pp,&rat)!=EOF)
     {
         if(strcmpi(gn,ch_game)!=0)
            fprintf(fw,"%s %s %d %d\n",gn,pub,pp,rat);
            else
                flag_del=0;
     }
     if(flag_del==-1)
     {
     gotoxy(5,10);
     printf("Game Deletion Not Successful");
     }
     else
     {
        gotoxy(5,10);
        printf("Game Successfully Deleted");
     }
     fclose(fp);
     fclose(fw);
     if(remove(filename)==0);
        //printf("fhgtft");
     rename("temp.txt","games.txt");
     gotoxy(5,12);
     getch();
     admin();
}
void admin_deletion()
{
 char ch_del[30];
 justframe();
 gotoxy(5,3);
 printf("Enter Keyword : ");
 scanf("%s",ch_del);
 set_head_null();
 create_list();
 display_given(ch_del,2);
}
void admin()
{
    char ch_admin;
    justframe();
    gotoxy(5,3);
    printf("You Can Enter New Games or Delete Games Here");
    gotoxy(5,6);
    printf("Press E for New Entry\t\t\t\tPress D for Deletion");
    gotoxy(10,19);
    printf("Press Q to EXIT \t\t\tPress B to go Back");
    gotoxy(25,12);
    ch_admin=getch();
    if(ch_admin=='b'||ch_admin=='B')
    {system("cls"); main();}
    else if(ch_admin=='q'||ch_admin=='Q')
    exit(0);
    else if(ch_admin=='e'||ch_admin=='E')
     admin_entry();
    else if(ch_admin=='d'||ch_admin=='D')
     admin_deletion();
    else
        admin();
}
void login()
{
    char ch1;
    justframe();
    gotoxy(5,6);
    printf("PRESS FOUR SEQUENCE CODE TO PROCEED\t");
    ch1=getch();
    if(ch1=='0')
    {
        ch1=getch();
        if(ch1=='1')
        {
         ch1=getch();
         if(ch1=='2')
          {
           ch1=getch();
           if(ch1=='3')
             admin();
            else
              main();
          }
          else
            main();
        }
        else
            main();
    }
    else
        main();
}
