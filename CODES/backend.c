#include<stdio.h>
#include<malloc.h>
#include<windows.h>
#include "backend_sell.h"
struct node
{
    char game_name[30];
    char publisher[20];
    char contact[11];
    int price;
    int rating;
    struct node *link;
};
typedef struct node * new;
struct node *head =NULL;
void insert_game();
void create_list();
void buy_game(struct node *);
void display_review(int,int);
void display_all();
void select_g(char [],int,char []);
void gotoxy(int,int);
void display_given(char [],int);
int main5(void)
{
 char choice;
 char src[30],ch;
 create_list();
 do
 {
  ch='y';
  system("cls");
  printf("==============MENU===============\nPress 1. To display all\nPress 2. To Search Given Game\nPress 0. Back to Previous Page\nPress 4.to Goto Sell Page\n");
  choice=getch();
  switch(choice)
  {
   case '1':
   system("cls");
   head=NULL;
   create_list();
   display_all();
   break;
   case '2':
    system("cls");
    head=NULL;
    create_list();
    printf("Enter KeyWord:\t");
    scanf("%s",src);
    display_given(src,1);
    break;
   case '0':
    system("cls"); main();
    break;
   case '4':
    system("cls"); main_2();
   default:
    continue;
 }
 printf("\nEnter y to Continue:\t");
 fflush(stdin);
 }while(ch=='y');
 return 0;
}
void select_g(char game[30],int back,char pub[30])
{
    int i;
    char ch;
    system("cls");
    struct node *tmp;
    for(i=0;i<25;i++)
    printf("==");
    for(tmp=head;tmp!=NULL;tmp=tmp->link)
    {
        if(strcmpi(tmp->game_name,game)==0)
        {
          printf("\nGame Name:\t%s\n",tmp->game_name);
          printf("\nPublisher :\t%s\n",tmp->publisher);
          for(i=0;i<25;i++)
            printf("--");
          printf("\nPrice:\t%d\n",tmp->price);
          for(i=0;i<4;i++)
          {gotoxy(85,i); printf("|");}
          for(i=0;i<29;i++)
          {gotoxy(53,i); printf("|");}
          gotoxy(54,4);
          for(i=0;i<22;i++)
          printf("---");
          gotoxy(55,2);
          printf("Rating:  ");
          for(i=0;i<tmp->rating&&i<5;i++)
            printf("! ");
          gotoxy(90,2);
          if(tmp->rating==1) printf("Need Improvement    :(");
          else if(tmp->rating==2) printf("PLayable    | )");
          else if(tmp->rating==3) printf("Hot    | - )");
          else if(tmp->rating==4) printf("On Fire    : o");
          else printf("Mind Blowing    ( | >");
          display_review(56,6);
          gotoxy(5,7);
          printf("Press B to Buy:\t");
          printf("\tPress A to go Back;");
          gotoxy(9,9);
          ch=_getch();
          if((ch=='a'||ch=='A')&&back==0)
          display_all();
          else if((ch=='a'||ch=='A')&&back==1)
            display_given(game,1);
          else if((ch=='a'||ch=='A')&&back==2)
                display_given(pub,1);
         else if(ch=='B'||ch=='b')
                    buy_game(tmp);
        }
    }
}
void buy_game(struct node *tmp)
{
    int noc;
    char buyer_name[30];
    FILE *fw;
    fw=fopen("buy.txt","a");
    system("cls");
    gotoxy(5,3);
    printf("Game     \t\t:\t%s",tmp->game_name);
    gotoxy(5,5);
    printf("Publisher\t\t:\t%s",tmp->publisher);
    gotoxy(5,7);
    printf("Rating   \t\t:\t%d",tmp->rating);
    gotoxy(5,9);
    printf("Price    \t\t:\tRs.%d",tmp->price);
    gotoxy(5,11);
    printf("Enter Your First Name and Number of Copies of Game to be Bought");
    gotoxy(5,12);
    printf("Enter "" 'Menu'"" to go back to Main Menu in place of Name");
    gotoxy(5,14);
    printf("Name  :  ");
    scanf("%s",buyer_name);
    if(strcmpi(buyer_name,"Menu")==0)
       {fclose(fw); return;}
    gotoxy(5,15);
    printf("Number of Copies : ");
    scanf("%d",&noc);
    fprintf(fw,"%s %s %d  Payment Pending\n",tmp->game_name,buyer_name,noc);
    gotoxy(10,17);
    printf("Please Make the Payment at Given Link Below to Download the Game");
    gotoxy(24,19);
    printf("https://funmania.com/vh12?hjsw.asp");
    gotoxy(28,22);
    printf("Thank you :)!");
    gotoxy(33,25);
    fclose(fw);
    _getch();
}
void display_given(char src[30],int num)
{
    char ch[30];
    struct node *tmp;
    int flag=-1;
    system("cls");
    for(tmp=head;tmp!=NULL;tmp=tmp->link)
    {
        if(strcmpi(tmp->game_name,src)==0)
        {
            printf("%s--%s--%d\n",tmp->game_name,tmp->publisher,tmp->price);
            flag=1;
        }
    }
    for(tmp=head;tmp!=NULL;tmp=tmp->link)
    {
        if(strcmpi(tmp->publisher,src)==0)
        {
            printf("%s--%s--%d\n",tmp->game_name,tmp->publisher,tmp->price);
            flag=2;
        }
    }
    if(flag==-1) printf("\nNOt FOUND!!!!!!!!!!\n");
    else
    {
     printf("\nEnter Game Name Select Game (Default Will take you Back to Home Page):\t");
     scanf("%s",ch);
     if(num==1)
      select_g(ch,flag,src);
     else
      admin_game_del(ch);
    }
}
void set_head_null()
{
    head=NULL;
}
void display_review(int x,int y)
{
    gotoxy(x,y);
    printf("<--==!REVIEWS AND LaTEST UpDates;)==-->");
    gotoxy(x,y+2);
    FILE *fr;
    int k=y+2,i=0;
    fr=fopen("review.txt","r");
    char ch;
    while(fscanf(fr,"%c",&ch)!=EOF&&i<18)
        { printf("%c",ch);  if(ch=='\n'){gotoxy(x,++k); i++;} }
    if(i==18)
    {gotoxy(x,++k);
    printf("In Main Menu Select Review and Updates Option for More!!!");}
    fclose(fr);
}
void display_all()
{
    system("cls");
    char ch[30];
    new tmp;
    tmp=head;
    while(tmp!=NULL)
    {
        printf("%s--%s--%d\n",tmp->game_name,tmp->publisher,tmp->price);
        tmp=tmp->link;
    }
    printf("\nEnter Game Name Select Game (Default Will take you Back toHome Page):\t");
    scanf("%s",ch);
    select_g(ch,0,"");
}
void create_list()
{
    FILE *fp;
    fp=fopen("games.txt","r");
    int pp,rat;
    char gn[30],pub[20];
    while(fscanf(fp,"%s%s%d%d",gn,pub,&pp,&rat)!=EOF)
     {
         struct node *tmp = malloc(sizeof(struct node));
         tmp->price=pp;
         tmp->rating=rat;
         strcpy(tmp->game_name,gn);
         strcpy(tmp->publisher,pub);
         tmp->link=NULL;
         if(head==NULL)
            head=tmp;
         else
         {
            struct node *tmp2;
            tmp2=head;
            while(tmp2->link!=NULL)
                tmp2=tmp2->link;
            tmp2->link=tmp;
         }
     }
     fclose(fp);
}
