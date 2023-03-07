#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "utils.h"           
void pat_exist_user()       //this gives the patinet details
{ 
    FILE *f,*f1;
    char ch;
    char pwd[30];
    char usrn[50];
    f=fopen("pat_pswd.txt","r");
    printf("Enter username : ");      //For entering the passwords 
    scanf("%s",usrn);
    int i=0;
    printf("Enter Password : ");
    scanf("%s",pwd);                     //entering the passwrod and then it will compare with the file sstoring the data
    char *c1=malloc(sizeof(char)*300);
    do
    {
        fgets(c1,200,f);
        int i=0,j=0;
        char *c;
        c= malloc(sizeof(char)*400);
        while(c1[j]!='\0')
        {
            if(c1[j]!=' ')
            {                             //keep storing till the reight values are met
                c[i]=c1[j];
                i++;
                j++;
            }
            if(c1[j]==' ')
            {
                if(strcmp(c,usrn)==0)
                break;
                else
                {
                    c= malloc(sizeof(char)*400);
                    i=0;
                    j++;
                }
            }
        }
        if(strcmp(c,usrn)==0)
        break;                     //if true then the loop shaal break
    }while(c1[0]!= EOF);

    int j=0;
    char *str[20];
    char *c;
	c=malloc(sizeof(char)*400);
     i=0;
    int k=0;                //for storing the password
    while(c1[j]!='\0')
    {
        if(c1[j]!=' ')
        {
            c[i]=c1[j];
            i++;
            j++;
        }
        else
        {
        	c[i]='\0';                        //entering and storing till a null character is entered in this
            str[k]=malloc(sizeof(char)*410);
            str[k]=c;
            k++;
            i=0;
            c=malloc(sizeof(char)*400);
            j++;
        }
    }
    while(1)
    {
      if(strcmp(pwd,str[1])==0)
      {
        printf("Successful Login..\n");             //if the entered and the stored matches it means that we havegotten a successful login
        char *str1=malloc(sizeof(char)*200);
        str1=str[2];
        patient(str1);
        break;
      }
      else
      {
      printf("Wrong Password....\n");
      scanf("%s",pwd);              //else it is a wrong password
      }
    }
}