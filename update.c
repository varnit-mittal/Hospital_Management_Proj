#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "utils.h"
void update(FILE *f1, char str[])       //global scanning
{
    char ch;
    scanf("%c",&ch);
    char *c1=malloc(sizeof(char)*300);    //storing the individual details
    int k=0;
    do
    {
        fgets(c1,300,f1);
        if(strcmp(c1,str)==0)
        {
            break;
        }
        else
        {
            k=k+strlen(c1);
        }
        if(strcmp(c1,"$")==0)   //ending with our $ sign
        break;
    }while(1);
    fseek(f1,k,SEEK_SET);
    char *str1=malloc(sizeof(char)*300);
    printf("Enter your update: \n");
    
    fgets(str1,300,stdin);
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
        c1=fgets(c1,300,f1);
        k=k+strlen(c1);
    }while(strcmp(c1,"$")!=0);   //storing and updating the details
    fseek(f1,k,SEEK_SET);
    // fprintf(f1,"\n%s",str2);
    int i=0;
    char *str3=malloc(sizeof(char)*300);
    for(i=0;i<strlen(str1)-1;i++)
    {
        str3[i]=str1[i];
    }
    strcat(str3," $\n");
    fprintf(f1,"\n%s$",str3);     //updating the deetails
    str=str1;
}