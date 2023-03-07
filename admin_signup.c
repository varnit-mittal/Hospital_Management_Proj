#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "utils.h"
void admin_new_user()
{
    FILE *f1,*f2;
    f1=fopen("admin_data.txt","r+"); //opening files
    f2=fopen("admin_pswd.txt","r+");
    struct info{ //creating structures
        char *name;char *dob;char *age;char *gen; char *phn; char *email;char *adrs; ;char *spl;
    };
    struct info ppl;//taking data from stdout
    printf("Enter First Name: "); 
    ppl.name=malloc(sizeof(char)*30);
    scanf("%s",ppl.name);
    printf("Enter Date of Birth (dd/mm/yyyy): ");
    ppl.dob=malloc(sizeof(char)*15);
    scanf("%s",ppl.dob);
    printf("Enter your age: ");
    ppl.age=malloc(sizeof(char)*4);
    scanf("%s",ppl.age);
    printf("Enter your gender: ");
    ppl.gen=malloc(sizeof(char)*15);
    scanf("%s",ppl.gen);
    ppl.spl=malloc(sizeof(char)*40);
    printf("Enter Your Role in this Hospital: ");
    scanf("%s",ppl.spl);
    printf("Enter your Phone Number: ");
    ppl.phn=malloc(sizeof(char)*15);
    scanf("%s",ppl.phn);
    printf("Enter your email: ");
    ppl.email=malloc(sizeof(char)*40);
    scanf("%s",ppl.email);
    printf("Enter your address: ");
    ppl.adrs=malloc(sizeof(char)*80);
    scanf("%s",ppl.adrs);
    fseek(f1,EOF,SEEK_END); //moving file pointer to eof 
    fprintf(f1,"\n%s %s %s %s %s %s %s %s $\n",ppl.name,ppl.dob,ppl.age,ppl.gen,ppl.spl,ppl.phn,ppl.email,ppl.adrs);
    printf("\nCreate a username: ");//username
    char *usrn=malloc(sizeof(char)*30);
    scanf("%s",usrn);
    printf("Create Password: ");//password
    char pswd1[50];
    scanf("%s",pswd1);
    printf("Confirm Password: ");
    char pswd2[50];
    scanf("%s",pswd2);
    while(1)//till confirm password  = password entered
    {
        if(strcmp(pswd1,pswd2)==0)
        {
            printf("Matched..\n");
            fseek(f2,EOF,SEEK_END);
            fprintf(f2,"\n%s %s %s $",usrn,pswd1,ppl.name);
            system("clear");
            break;
        }
        else
        {
            printf("Wrong..\n");
            printf("Create Password: ");
            scanf("%s",pswd1);
            printf("Confirm Password: ");
            scanf("%s",pswd2);
        }
    }

}