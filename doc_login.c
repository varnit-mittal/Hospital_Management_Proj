#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "utils.h"
void doc_exist_user()
{
    FILE *f,*f1;
    char ch;                   //this is reading the inputs 
    char pwd[30];
    char usrn[50];
    f=fopen("doc_pswd.txt","r");
    printf("Enter username : ");
    scanf("%s",usrn);
    int i=0;                  //This then checks with the stored username 
    printf("Enter Password : ");
    scanf("%s",pwd);                  //This then checks with the password
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
            {
                c[i]=c1[j];
                i++;               //till the correct password is entered it keeps coping the list
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
        break;
    }while(c1[0]!= EOF);

    int j=0;
    char *str[20];
    char *c;
	c=malloc(sizeof(char)*400);
     i=0;
    int k=0;
    while(c1[j]!='\0')
    {
        if(c1[j]!=' ')             //it will keep entering till a null character doesnt come out
        {
            c[i]=c1[j];
            i++;
            j++;
        }
        else
        {
        	c[i]='\0';
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
        printf("Successful Login..\n");                //this comapres with the successfull login attempts
        char *str1=malloc(sizeof(char)*200);
        str1=str[2];
        doc(str1);
        break;
      }
      else
      {
      printf("Wrong Password....\n");          //in case when there is a wrong password it will redirect back to where it came from
      scanf("%s",pwd);
      }
    }
}