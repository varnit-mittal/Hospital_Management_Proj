#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "utils.h"
void pat_new_user()
{
    FILE *f1,*f2; 
    f1=fopen("pat_data.txt","r+");          //if the correct username is entered
    f2=fopen("pat_pswd.txt","r+");        //If the correct password is entered
    struct info{
        char *name;char *dob;char *age;char *gen; char *phn; char *email;char *adrs;
    };
    struct info ppl;                  //Storing them all in  a structural format
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
    scanf("%s",ppl.gen);                            //Thes are the list of the details that you can enter
    printf("Enter your Phone Number: ");
    ppl.phn=malloc(sizeof(char)*15);
    scanf("%s",ppl.phn);
    printf("Enter your email: ");
    ppl.email=malloc(sizeof(char)*40);
    scanf("%s",ppl.email);
    printf("Enter your address: ");          //These are all stored in their respective Filees
    ppl.adrs=malloc(sizeof(char)*80);
    scanf("%s",ppl.adrs);
    fseek(f1,EOF,SEEK_END);
    fprintf(f1,"\n%s %s %s %s %s %s %s $\n",ppl.name,ppl.dob,ppl.age,ppl.gen,ppl.phn,ppl.email,ppl.adrs);
    printf("\nCreate a username: ");
    char *usrn=malloc(sizeof(char)*30);
    scanf("%s",usrn);
    printf("Create Password: ");
    char pswd1[50];
    scanf("%s",pswd1);                    //Create a username for the patients
    printf("Confirm Password: ");
    char pswd2[50];                 // Confirm the passwords for the patients
    scanf("%s",pswd2);
    while(1)
    {
        if(strcmp(pswd1,pswd2)==0)
        {
            printf("Matched..\n");          //if the password matches then 
            fseek(f2,EOF,SEEK_END);
            fprintf(f2,"\n%s %s %s $",usrn,pswd1,ppl.name);   //this will fetch the details
            system("clear");
            break;
        }
        else
        {
            printf("Wrong..\n");            //Else there is a prompt for to enter the correct password
            printf("Create Password: ");
            scanf("%s",pswd1);
            printf("Confirm Password: ");
            scanf("%s",pswd2);
        }
    }

}