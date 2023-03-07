#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "utils.h"
void update2(FILE *f1, char str[],char name[])            //storing the updates
{
    char ch;
    scanf("%c",&ch);
    char *c1=malloc(sizeof(char)*300);
    int k=0;
    do
    {
        fgets(c1,300,f1);                 //till the right string is entered
        if(strcmp(c1,str)==0)
        {
            break;
        }
        else
        {
            k=k+strlen(c1);
        }
        if(strcmp(c1,"$")==0)
        break;
    }while(1);
    fseek(f1,k,SEEK_SET);
    char *str1=malloc(sizeof(char)*300);
    char *doc_name = malloc(sizeof(char)*300);
    char *date = malloc(sizeof(char)*300);                  //These are for entering the deatils 
    char *time = malloc(sizeof(char)*300);                   //these for entering the new details
    char *prob = malloc(sizeof(char)*300);
    char *contact =malloc(sizeof(char)*300);
    
    
    printf("Enter your update: \n");
    printf("Enter Doctor Name\n");
    scanf("%s",doc_name);
    printf("Enter Date\n");
    scanf("%s",date);
    printf("Enter Enter Time\n");                   //I f we want to channge the new details
    scanf("%s",time);
    printf("Enter Problems faced\n");
    scanf("%s",prob);
    printf("Enter contact details\n");
    scanf("%s",contact);
    strcpy(str1,name);
    strcat(str1," ");
    strcat(str1,doc_name);
    strcat(str1," ");
    strcat(str1,date);
    strcat(str1," ");                       //this will concatanate the problems to individual data in the files that we have created
    strcat(str1,time);
    strcat(str1," ");
    strcat(str1,prob);
    strcat(str1," ");
    strcat(str1,contact);
    strcat(str1,"$");
    if(strcmp(c1,"$")!=0)
    {
        int i;
        for(i=1;i<strlen(str);i++)
        {
            fprintf(f1,"%c",' ');
        }
    }
    // char *str2=malloc(sizeof(char)*300);
    // int j;
    // for(j=0;j<strlen(str)-1;j++)
    // {
    //     str2[j]=str[j];
    // }
    // j++;
    // str2[j]=' ';
    // strcat(str2,str1);
    fseek(f1,0,SEEK_SET);
    k=0;
    do
    {
        c1=fgets(c1,300,f1);              //updates the file and then store it accordingly
        k=k+strlen(c1);
    }while(strcmp(c1,"$")!=0);
    fseek(f1,k,SEEK_SET);
    // fprintf(f1,"\n%s",str2);
    int i=0;
    char *str3=malloc(sizeof(char)*300);
    for(i=0;i<strlen(str1)-1;i++)
    {
        str3[i]=str1[i];
    }
    strcat(str3," $\n");
    fprintf(f1,"\n%s$",str3);
    str=str1;
}
