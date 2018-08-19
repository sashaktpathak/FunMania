#include<stdio.h>
#include<windows.h>
void main_2()
{
    //----------------------------------------------------------------------------------
     char game_name_entry[30];
 char user_name_entry[30];
 char publisher_entry[20];
 char contact_entry[20];
 int rating,price;
 FILE *fp,*fw;
 fp=fopen("games.txt","a");
 fw=fopen("newgames.txt","a");
 printf("===================GAME ENTRY==================\n");
 gotoxy(5,3);
 printf("Game Name  :");
 gotoxy(5,5);
 printf("User Name  :");
 gotoxy(5,7);
 printf("Publisher  :");
 gotoxy(5,9);
 printf("Contact Number  :");
 gotoxy(5,11);
 printf("Price  :");
 gotoxy(5,13);
 printf("Rating  :");
 gotoxy(1,30);
 printf("AT any Time type 'BACK' in any field or invalid Entry in Integer Entry to Go Back");
 gotoxy(22,3);
 scanf("%s",game_name_entry);
 if(strcmpi(game_name_entry,"back")==0)
    {system("cls"); main();}
 gotoxy(22,5);
 scanf("%s",user_name_entry);
 if(strcmpi(user_name_entry,"back")==0)
    {system("cls"); main();}
 gotoxy(22,7);
 scanf("%s",publisher_entry);
 if(strcmpi(publisher_entry,"back")==0)
    {system("cls"); main();}
 gotoxy(27,9);
 scanf("%s",contact_entry);
 if(strcmpi(contact_entry,"back")==0)
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
 fprintf(fw,"\n%s %s %s %s %d %d",game_name_entry,user_name_entry,publisher_entry,contact_entry,price,rating);
 system("cls");
 gotoxy(20,7);
 printf("Saving Game Information Please WAIT !!");
 getch();
 gotoxy(20,9);
 printf("Please Upload the Game to Following Cloud Storage Link :)");
 gotoxy(25,11);
 printf("https://funmania.com/get_game?=ae23nd8808.asp");
 gotoxy(35,15);
 printf(" )|   Thank you  |)");
 getch();
 fclose(fp);
 fclose(fw);
    //==================================================================================
}
