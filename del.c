#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "utils.h"
void del(FILE *f1, char str[])     //global scanning the functions
{
    rewind(f1);
    char ch;
    scanf("%c",&ch);
    char *c1=malloc(sizeof(char)*300);         //entering the details
    int k=0;
    do
    {
        fgets(c1,300,f1);
        if(strcmp(c1,str)==0)
        {        
            break;         //if the details match with the stored details
        }
        else
        {
            k=k+strlen(c1);
        }
        if(strcmp(c1,"$")==0)       //ending with our $ sign
        break;
    }while(1);
    fseek(f1,k,SEEK_SET);
    char *str1=malloc(sizeof(char)*300);
    if(strcmp(c1,"$")!=0)
    {
        int i;
        for(i=1;i<strlen(str);i++)          //This deletes the files till the $ sign is met
        {
            fprintf(f1,"%c",' ');       //printing till the null chahracter
        }
    }
    rewind(f1);
}