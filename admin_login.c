#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "utils.h"   //fetching the files
void admin_exist_user()
{
    FILE *f,*f1;
    char ch;
    char pwd[30];
    char usrn[50];
    f=fopen("admin_pswd.txt","r"); //opening the admin password file    
    printf("Enter username : ");
    scanf("%s",usrn);
    int i=0; 
    printf("Enter Password : ");
    scanf("%s",pwd);
    char *c1=malloc(sizeof(char)*300); //this is for storing the passwords 
    do
    {
        fgets(c1,200,f);
        int i=0,j=0;
        char *c;
        c= malloc(sizeof(char)*400);
        while(c1[j]!='\0')   //this will keep running till the the end of the null character does not come
        {
            if(c1[j]!=' ')
            {
                c[i]=c1[j];
                i++;   //storing individual characters in the arrays 
                j++;
            }
            if(c1[j]==' ')
            {
                if(strcmp(c,usrn)==0)
                break;
                else       //if the username enters the blank characters then the loopbreaks
                {
                    c= malloc(sizeof(char)*400);
                    i=0;
                    j++;
                }
            }
        }
        if(strcmp(c,usrn)==0) //if the value entered is flase then the loop will break
        break;
    }while(c1[0]!= EOF);

    int j=0;
    char *str[20];
    char *c;                          //entering the passwords to entering into the admin mode
	c=malloc(sizeof(char)*400);
     i=0;
    int k=0;
    while(c1[j]!='\0') //while the null character or enter is not entered in this 
    {
        if(c1[j]!=' ')
        {
            c[i]=c1[j];
            i++;
            j++; //copying and comparing the values
        }
        else
        {
        	c[i]='\0';
            str[k]=malloc(sizeof(char)*410);
            str[k]=c;
            k++;          
            i=0;            // for storing the values 
            c=malloc(sizeof(char)*400);
            j++;
        }
    }
    while(1)
    {                             //this compares the original password with the password entered till the correct value is entered
      if(strcmp(pwd,str[1])==0)
      {
        printf("Successful Login..\n");
        char *str1=malloc(sizeof(char)*200);
        str1=str[2];
        admin(str1);         
        system("clear");   //this will display a clear message at the end of a successful login in here
        break;
      }
      else
      {
      printf("Wrong Password....\n");
      scanf("%s",pwd); // chance to enter the correct password
      }
    }
}