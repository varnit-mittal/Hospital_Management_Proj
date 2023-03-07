#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>           //this shows the time displayal of the billing times or not
#include "utils.h"

/*
bed price =  1000/day
iccu price = 800/day
emergency = 500/day
ge.ward =  250/day
food = 150/day
pharma = 25/med

*/
int ward_bill(char name[],FILE *ward,FILE *fpp);
int iccu_bill(char name[],FILE *iccu,FILE *fpp);
int emergency_bill(char name[],FILE *emergency,FILE *fpp);
void billing_calc(char name[])
{
    FILE *ward=fopen("wards_in_out.txt","r+");
    FILE *emergency=fopen("emergency_in_out.txt","r+");
    FILE *iccu=fopen("iccu_in_out.txt","r+");
    FILE *fpp=fopen("billing.txt","r+");
    fseek(fpp,EOF,SEEK_END);
    fprintf(fpp,"\n");
    fprintf(fpp,"%s ",name);
    int a =ward_bill(name,ward,fpp);
    int b =iccu_bill(name,iccu,fpp);
    int c =emergency_bill(name,emergency,fpp);
    int total_time = a+b+c;
    int pharma = count_med(name);
    printf("Food - %d days @ %d/ = %d\n",total_time,100,total_time*100);
    printf("Pharma - @ %d/dose for %d medicines = %d\n",25,pharma,pharma*25);
    int total_price = a*250+b*800+c*500+100*total_time+pharma*25;
    printf("Total price = %d\n",total_price);
    printf("After Tax (%d)%% = %.2f\n",18,total_price*1.18);
    fprintf(fpp,"\n$");
    
}
int ward_bill(char name[],FILE *ward,FILE *fpp){
    int ward_f=0;
    char *ward_data=malloc(sizeof(200));
        if(ward!=NULL)
        {
            do
            {
                fgets(ward_data,200,ward);
                int i=0,j=0;
                char *c;
                c= malloc(sizeof(char)*400);
                while(ward_data[j]!='\0')
                {
                    if(ward_data[j]!=' ')
                    {
                        c[i]=ward_data[j];
                        i++;
                        j++;
                    }
                    if(ward_data[j]==' ')
                    {
                        if(strcmp(c,name)==0)
                        break;
                        else
                        {
                            c= malloc(sizeof(char)*400);
                            i=0;
                            j++;
                        }
                    }
                }
                if(strcmp(c,name)==0)
                {
                    ward_f=1;
                    break;
                }
                if(strcmp(ward_data,"$")==0)
                {
                    ward_f=0;
                    break;
                }
            }while(ward_data[0]!= EOF);
        }
            int j=0;
            char *ward_elements[20];
            char *elements;
            elements=malloc(sizeof(char)*400);
            int i=0;
            int k=0;
            while(ward_data[j]!='\0')
            {
                if(ward_data[j]!=' ')
                {
                    elements[i]=ward_data[j];
                    i++;
                    j++;
                }
                else
                {
                    elements[i]='\0';
                    ward_elements[k]=malloc(sizeof(char)*410);
                    ward_elements[k]=elements;
                    k++;
                    i=0;
                    elements=malloc(sizeof(char)*400);
                    j++;
                }
            }
            int diff_ward;
            if(ward_f){
                if(ward_elements[2][1]=='D')
                {
                    printf("Calculating bill as of current date. Patient is not discharged from the ward. Contact respective doctor.\n");
                    char *dates=malloc(100);
                    scanf("%s",dates);
                    strcpy(ward_elements[2],dates);
                }
                diff_ward=diff_dates(ward_elements[2],ward_elements[1]);
                fprintf(fpp,"%d %d ",diff_ward*250,diff_ward);
                printf("General Ward - %d days @ %d = %d \n",diff_ward,250,diff_ward*250);
            }
            else
            {
                fprintf(fpp,"%d %d ",0,0);
                printf("General Ward - 0 days -  %d\n",0);

            }
            return diff_ward;
            
}
int iccu_bill(char name[],FILE *iccu,FILE *fpp){
    int ward_f=0;
    char *ward_data=malloc(sizeof(200));
        if(iccu!=NULL)
        {
            do
            {
                fgets(ward_data,200,iccu);
                int i=0,j=0;
                char *c;
                c= malloc(sizeof(char)*400);
                while(ward_data[j]!='\0')
                {
                    if(ward_data[j]!=' ')
                    {
                        c[i]=ward_data[j];
                        i++;
                        j++;
                    }
                    if(ward_data[j]==' ')
                    {
                        if(strcmp(c,name)==0)
                        break;
                        else
                        {
                            c= malloc(sizeof(char)*400);
                            i=0;
                            j++;
                        }
                    }
                }
                if(strcmp(c,name)==0)
                {
                    ward_f=1;
                    break;
                }
                if(strcmp(ward_data,"$")==0)
                {
                    ward_f=0;
                    break;
                }
            }while(ward_data[0]!= EOF);
        }
            int j=0;
            char *ward_elements[20];
            char *elements;
            elements=malloc(sizeof(char)*400);
            int i=0;
            int k=0;
            while(ward_data[j]!='\0')
            {
                if(ward_data[j]!=' ')
                {
                    elements[i]=ward_data[j];
                    i++;
                    j++;
                }
                else
                {
                    elements[i]='\0';
                    ward_elements[k]=malloc(sizeof(char)*410);
                    ward_elements[k]=elements;
                    k++;
                    i=0;
                    elements=malloc(sizeof(char)*400);
                    j++;
                }
            }
            int diff_ward;
            if(ward_f){
                if(ward_elements[2][1]=='D')
                {
                    printf("Calculating bill as of current date. Patient is not discharged from the ward. Contact respective doctor.\n");
                    char *dates=malloc(100);
                    scanf("%s",dates);
                    strcpy(ward_elements[2],dates);
                }
                diff_ward=diff_dates(ward_elements[2],ward_elements[1]);
                fprintf(fpp,"%d %d ",diff_ward*800,diff_ward);
                printf("ICCU - %d days @ %d = %d \n",diff_ward,800,diff_ward*800);
            }
            else{
                fprintf(fpp,"%s %s ","0","0");
                printf("ICCU - 0 days -  %d\n",0);                
            }
            return diff_ward;
            
}
int emergency_bill(char name[],FILE *emergency,FILE *fpp){
    int ward_f=0;
    char *ward_data=malloc(sizeof(200));
        if(emergency!=NULL)
        {
            do
            {
                fgets(ward_data,200,emergency);
                int i=0,j=0;
                char *c;
                c= malloc(sizeof(char)*400);
                while(ward_data[j]!='\0')
                {
                    if(ward_data[j]!=' ')
                    {
                        c[i]=ward_data[j];
                        i++;
                        j++;
                    }
                    if(ward_data[j]==' ')
                    {
                        if(strcmp(c,name)==0)
                        break;
                        else
                        {
                            c= malloc(sizeof(char)*400);
                            i=0;
                            j++;
                        }
                    }
                }
                if(strcmp(c,name)==0)
                {
                    ward_f=1;
                    break;
                }
                if(strcmp(ward_data,"$")==0)
                {
                    ward_f=0;
                    break;
                }
            }while(ward_data[0]!= EOF);
        }
            int j=0;
            char *ward_elements[20];
            char *elements;
            elements=malloc(sizeof(char)*400);
            int i=0;
            int k=0;
            while(ward_data[j]!='\0')
            {
                if(ward_data[j]!=' ')
                {
                    elements[i]=ward_data[j];
                    i++;
                    j++;
                }
                else
                {
                    elements[i]='\0';
                    ward_elements[k]=malloc(sizeof(char)*410);
                    ward_elements[k]=elements;
                    k++;
                    i=0;
                    elements=malloc(sizeof(char)*400);
                    j++;
                }
            }
            int diff_ward;
            if(ward_f){
                if(ward_elements[2][1]=='D')
                {
                    printf("Patient is not discharged from the ward. Calculating bill as of current date. Contact respective doctor.\nEnter Date :");
                    char *dates=malloc(100);
                    scanf("%s",dates);
                    strcpy(ward_elements[2],dates);
                }
                diff_ward=diff_dates(ward_elements[2],ward_elements[1]);
                fprintf(fpp,"%d %d ",diff_ward*500,diff_ward);
                printf("Emergency - %d days @ %d = %d \n",diff_ward,500,diff_ward*500);
            }
            else{
                fprintf(fpp,"%s %s ","0","0");
                printf("Emergency - 0 days -  %d\n",0);
            }
            return diff_ward;
            
}
