#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "utils.h"
void doc_new_user()
{
    FILE *f1,*f2;
    f1=fopen("doc_data.txt","r+");             //this opens the file containg the doctor details
    f2=fopen("doc_pswd.txt","r+");           //this opens the files containing the doctor's portal passwords
    struct info{
        char *name;char *dob;char *age;char *gen; char *phn; char *email;char *adrs; ;char *spl;
    };
    struct info ppl;
    printf("Enter First Name: ");
    ppl.name=malloc(sizeof(char)*30);           //this is for comparing the user details and information abput the doctors
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
    ppl.spl=malloc(sizeof(char)*40);                    //this is for entering all the details 
    printf("Enter Your Speciality: ");
    scanf("%s",ppl.spl);
    printf("Enter your Phone Number: ");
    ppl.phn=malloc(sizeof(char)*15);
    scanf("%s",ppl.phn);
    printf("Enter your email: ");
    ppl.email=malloc(sizeof(char)*40);              //storing all the details in there
    scanf("%s",ppl.email);
    printf("Enter your address: ");
    ppl.adrs=malloc(sizeof(char)*80);
    scanf("%s",ppl.adrs);
    fseek(f1,EOF,SEEK_END);
    fprintf(f1,"%s %s %s %s %s %s %s %s $\n",ppl.name,ppl.dob,ppl.age,ppl.gen,ppl.spl,ppl.phn,ppl.email,ppl.adrs);
    printf("\nCreate a username: ");
    char *usrn=malloc(sizeof(char)*30);
    scanf("%s",usrn);
    printf("Create Password: ");
    char pswd1[50];                        //This creates the password that we need 
    scanf("%s",pswd1);
    printf("Confirm Password: ");             //This confirms the password when we have entered it
    char pswd2[50];
    scanf("%s",pswd2);
    while(1)
    {
        if(strcmp(pswd1,pswd2)==0)             //if the correct password is entered then it will show us all the details in there
        {
            printf("Matched..\n");
            fseek(f2,EOF,SEEK_END);             
            fprintf(f2,"\n%s %s %s $",usrn,pswd1,ppl.name);
            break;
        }
        else
        {
            printf("Wrong..\n");
            printf("Create Password: ");              //Another chance to create a new password and then confirm it
            scanf("%s",pswd1);
            printf("Confirm Password: ");
            scanf("%s",pswd2);
        }
    }

}