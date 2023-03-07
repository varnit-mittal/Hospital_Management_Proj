#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "utils.h"

void prof2(FILE *f,char name[], char c1[]);
char *view_prof2(char profile[]);
void booking(FILE *fp,FILE *f1,char name[]);
void admit_patient();
void update_patient();
void add_medic(char str[]);
int count_med(char name[]);

void doc(char name[])
{
    printf("-------------------------------------- Welcome to Ashadeep's Doctor Portal -------------------------------------------");
    FILE *f,*fp,*f1;
    printf("\nHi %s\n",name);
    int b=1,i;
    while(b)
    {
        printf("\n");
        printf("Press 1 to view your profile\n");
        printf("Press 2 to view booking requests\n");
        printf("Press 3 to view update a patient's status\n");
        printf("Press 4 to admit a patient\n");
        printf("Press 5 to prescribe medicine to a patient\n");
        printf("Press 6 to exit the portal\n");
        printf("Enter your input: ");
        int d;
        scanf("%d",&d);
        switch(d)
        {
            case 1:
            {
                FILE *f1;
                char *cdoc=malloc(sizeof(char)*300);
                char *c2=malloc(sizeof(char)*200);
                prof2(f1,name,cdoc);
                c2=view_prof2(cdoc);
                break;
            }
            case 2:
            {
                FILE *f2,*f3;
                booking(f2,f3,name);
                break;
            }
            case 3:
            {
                update_patient();
                break;
            }
            case 4:
            {
                admit_patient();
                break;
            }
            case 5:
            {
                char *med=malloc(sizeof(char)*300);
                add_medic(med);
                break;
            }
            case 6:
            {
                printf("You are exiting...\n");
                break;
            }
            
        }
        if(d==6)
        break;
    }
}                      

void admit_patient(){
    printf("Enter 1 to admit the patient in ICCU\n");
    printf("Enter 2 to admit the patient in Emergency\n");
    printf("Enter 3 to admit the patient in Ward\n");
    int pat_admit_choice;
    scanf("%d",&pat_admit_choice);
    char type[15];
    char filename[30];
    FILE *fa1 ;
    if(pat_admit_choice==1)
    {
        strcpy(filename,"iccu_info.txt");
        strcpy(type,"iccu");
        fa1=fopen("iccu_in_out.txt","a");

    }
    else if(pat_admit_choice==2)
    {
        strcpy(filename,"emergency_info.txt");
        strcpy(type,"emergency");
        fa1=fopen("emergency_in_out.txt","a");        
    }
    else if(pat_admit_choice==3)
    {
        strcpy(filename,"wards_info.txt");
        strcpy(type,"wards");
        fa1=fopen("wards_in_out.txt","a");

    }
    FILE *fp = fopen(filename,"a");
    FILE *fward = fopen("pat_ward.txt","a");

    char data[11][100];
    printf("Enter patient's Name: ");
    scanf("%s", data[0]);
    fprintf(fward,"%s","\n");
    fprintf(fward,"%s %s $\n$",data[0],type);
    printf("Enter patient's %s Ward Number: ", type);
    scanf("%s", data[1]);
    printf("Enter patient's %s Bed Number: ", type);
    scanf("%s", data[2]);
    printf("Enter patient's Disease: ");
    scanf("%s", data[3]);
    printf("Enter patient's Doctor assigned:");
    scanf("%s", data[4]);
    char *time=malloc(sizeof(char)*100);
    printf("Enter Date in: ");
    scanf("%s", time);
    // fprintf(fp,"%s","\n");
    fprintf(fp,"%s","\n");
    for(int i=0;i<5;i++)
        fprintf(fp, "%s ", data[i]);
    fprintf(fp,"%s $",time);
    fprintf(fp, "\n%s", "$");
    fprintf(fa1,"%s","\n");
    fprintf(fa1,"%s %s DD/MM/YYYY $\n",data[0],time);
    fprintf(fa1,"$");
    fclose(fa1);
}

void update_patient()
{
    char *patient=malloc(100*sizeof(char));
    printf("Enter patient's Name: ");
    scanf("%s",patient);
    // for(int i=0;i<15;i++)
        // printf("%d ",patient[i]);
    FILE *ff=fopen("pat_ward.txt","r+");
    char *temp=(char *)malloc(sizeof(char)*500);
    int f=0;
    if(ff!=NULL)
    {
        
        do
        {
            fgets(temp,200,ff);
            int i=0,j=0;
            char *c;
            c= malloc(sizeof(char)*400);
            while(temp[j]!='\0')
            {
                if(temp[j]!=' ')
                {
                    c[i]=temp[j];
                    i++;
                    j++;
                }
                if(temp[j]==' ')
                {
                    if(strcmp(c,patient)==0)
                    break;
                    else
                    {
                        c= malloc(sizeof(char)*400);
                        i=0;
                        j++;
                    }
                }
            }
            if(strcmp(c,patient)==0)
            break;
            if(strcmp(temp,"$")==0)
            {
                f=-1;
                printf("----Patient Not Found-----\n");
                break;
            }
        }while(temp[0]!= EOF);
    }
    char *curr_ward=malloc(100*sizeof(char));
    if (f==0)
    {
        int j=0;
        char *str[20];
        char *c;
        c=malloc(sizeof(char)*400);
        int i=0;
        int k=0;
        while(temp[j]!='\0')
        {
            if(temp[j]!=' ')
            {
                c[i]=temp[j];
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
        curr_ward=str[1];
        printf("Patient is current in %s \n",curr_ward);
        FILE *fcurr_ward;
        FILE *fcurr_info;
        if (strcmp(curr_ward,"iccu")==0)
        {
            fcurr_ward=fopen("iccu_in_out.txt","r+");
            fcurr_info=fopen("iccu_info.txt","r+");
        }
        else if (strcmp(curr_ward,"emergency")==0)
        {
            fcurr_ward=fopen("emergency_in_out.txt","r+");
            fcurr_info=fopen("emergency_info.txt","r+");
        }
        else if (strcmp(curr_ward,"wards")==0)
        {
            fcurr_ward=fopen("wards_in_out.txt","r+");
            fcurr_info=fopen("wards_info.txt","r+");
        }
    
        char opt;
        printf("Do you want to update admission type (ICCU, Emergency, Ward, Discharge) : (y/n) ");
        char cd;
        scanf("%c",&cd);
        scanf("%c",&opt);
        if(opt=='y')
        {
            printf("Enter 1 to shift the patient \n");
            printf("Enter 2 to discharge the patient \n");
            int choice_ward;
            scanf("%d",&choice_ward);
            FILE *new_ward_info;
            FILE *new_in_out;
            char *c1=malloc(sizeof(char)*300);
            int f=0;
            rewind(fcurr_info);
            do
            {
                fgets(c1,200,fcurr_info);
                int i=0,j=0;
                char *c;
                c= malloc(sizeof(char)*400);
                while(c1[j]!='\0')
                {
                    if(c1[j]!=' ')
                    {
                        c[i]=c1[j];
                        i++;
                        j++;
                    }
                    if(c1[j]==' ')
                    {
                        if(strcmp(c,patient)==0)
                        break;
                        else
                        {
                            c= malloc(sizeof(char)*400);
                            i=0;
                            j++;
                        }
                    }
                }
                if(strcmp(c,patient)==0)
                break;
                if(strcmp(c1,"$")==0)
                {
                printf("--NO Data Found--\n");
                f=-1;
                break;
                }
            }while(c1[0]!= EOF);
            rewind(ff);
            char *c2=malloc(sizeof(char)*300);
            do
            {
                fgets(c2,200,ff);
                int i=0,j=0;
                char *c;
                c= malloc(sizeof(char)*400);
                while(c2[j]!='\0')
                {
                    if(c2[j]!=' ')
                    {
                        c[i]=c2[j];
                        i++;
                        j++;
                    }
                    if(c2[j]==' ')
                    {
                        if(strcmp(c,patient)==0)
                        break;
                        else
                        {
                            c= malloc(sizeof(char)*400);
                            i=0;
                            j++;
                        }
                    }
                }
                if(strcmp(c,patient)==0)
                break;
                if(strcmp(c2,"$")==0)
                {
                printf("NO Data Found\n");
                break;
                }
            }while(c2[0]!= EOF);
            if (choice_ward ==1)
            {
                printf("As you need to close details of patient in the previous ward. Please enter current date:  ");
                char *date=malloc(100);
                scanf("%s",date);
                printf("Enter 1 to continue :");
                char *temp2=malloc(100*sizeof(char));
                fseek(fcurr_ward,0,SEEK_SET);
                fscanf(fcurr_ward,"%s",temp2);
                while (strcmp(temp2,patient)!=0)
                {
                    fscanf(fcurr_ward,"%s",temp2);
                }
                fscanf(fcurr_ward,"%s",temp2);
                fprintf(fcurr_ward," %s",date);
                fseek(ff,0,SEEK_SET);
                del(fcurr_info,c1);
                del(ff,c2);
                admit_patient();
                
                
            }
            if(choice_ward==2)
            {
                del(fcurr_info,c1); 
                if(f==0)
                {
                    printf("As you need to close details of patient in the previous ward. Please enter current date:  ");
                    char *date = malloc(100);
                    scanf("%s",date);
                    char *temp2=malloc(100*sizeof(char));
                    fscanf(fcurr_ward,"%s",temp2);
                    while (strcmp(temp2,patient)!=0)
                    {
                        fscanf(fcurr_ward,"%s",temp2);
                    }
                    fscanf(fcurr_ward,"%s",temp2);
                    fprintf(fcurr_ward," %s",date);
                }
                
                del(ff,c2);
            }
        }
    }

}

void prof2(FILE *f,char name[], char c1[])
{
    f=fopen("doc_data.txt","r");
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
                i++;
                j++;
            }
            if(c1[j]==' ')
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
        break;
    }while(c1[0]!= EOF);
}

char *view_prof2(char profile[])
{
    int j=0;
    char *str[20];
    char *c;
    c=malloc(sizeof(char)*400);
    int i=0;
    int k=0;
    while(profile[j]!='\0')
    {
        if(profile[j]!=' ')
        {
            c[i]=profile[j];
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
    printf("Name: %s\n",str[0]);
    printf("D.O.B: %s\n",str[1]);
    printf("Age: %s\n",str[2]);
    printf("Gender: %s\n",str[3]);
    printf("Contact details: \n");
    printf("%s\n",str[4]);
    printf("%s\n",str[5]);
    printf("Address: %s\n",str[6]);
    printf("Specialization: %s\n",str[7]);
    return str[7];
}

void booking(FILE *fp,FILE *f1,char name[])
{
    fp= fopen("new_book.txt","r");
    f1= fopen("booking_data.txt","r+");
    char *book=malloc(sizeof(char)*300);
    char *nb=malloc(sizeof(char)*300);
    if(fp!=NULL)
    {
        
        do
        {
            fgets(book,200,fp);
            int i=0,j=0;
            char *c;
            c= malloc(sizeof(char)*400);
            while(book[j]!='\0')
            {
                if(book[j]!=' ')
                {
                    c[i]=book[j];
                    i++;
                    j++;
                }
                if(book[j]==' ')
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
            break;
            if(strcmp(book,"$")==0)
            break;
        }while(book[0]!= EOF);
    }
    int j=0;
    char *data_elements[20];
    char *elements;
    elements=malloc(sizeof(char)*400);
    int i=0;
    int k=0;
    while(book[j]!='\0')
    {
        if(book[j]!=' ')
        {
            elements[i]=book[j];
            i++;
            j++;
        }
        else
        {
            elements[i]='\0';
            data_elements[k]=malloc(sizeof(char)*410);
            data_elements[k]=elements;
            k++;
            i=0;
            elements=malloc(sizeof(char)*400);
            j++;
        }
    }
    if(strcmp(book,"$")!=0)
    {
        printf("Booking request found..\n");
        char *ans=malloc(sizeof(char)*10);
        printf("Do you want to accept request/s.. (yes/no)...\n");
        scanf("%s",ans);
        FILE *ff;
        char *cdoc=malloc(sizeof(char)*300);
        prof2(ff,name,cdoc);
        char *cspec=malloc(sizeof(char)*100);
        cspec=view_prof2(cdoc);
        strcpy(nb,data_elements[0]);
        strcat(nb," ");
        strcat(nb,data_elements[1]);
        strcat(nb," ");
        strcat(nb,cspec);
        strcat(nb," ");
        strcat(nb,data_elements[2]);
        strcat(nb," ");
        strcat(nb,data_elements[3]);
        strcat(nb," ");
        strcat(nb,data_elements[5]);
        strcat(nb," ");
        strcat(nb,ans);
        strcat(nb," $");
        fprintf(f1,"\n%s\n$",nb);
    }
    else
    {
        printf("No booking request found..\n");
    }
}
void add_medic(char str[])
{
    FILE *f1=fopen("medications_data.txt","r+");
    char *pat=malloc(sizeof(char)*150);
    printf("Enter the patien name to whom you want to prescribe medicine: ");
    scanf("%s",pat);
    strcpy(str,pat);
    strcat(str," ");
    printf("Enter the medicine you want to prescribe to the patient\n");
    printf("Type EXIT to stop entering the medicine\n");
    while(1)
    {
        char *med=malloc(sizeof(char)*200);
        
        scanf("%s",med);
        if(strcmp(med,"EXIT")!=0)
        {
            strcat(str,med);
            strcat(str," ");
        }
        else
        break;
    }
    strcat(str,"$");
    fprintf(f1,"\n%s\n$",str);
}

int count_med(char name[])
{
    FILE *fp=fopen("medications_data.txt","r+");
    char *book=malloc(sizeof(char)*300);

    if(fp!=NULL)
    {
        do
        {
            fgets(book,200,fp);
            int i=0,j=0;
            char *c;
            c= malloc(sizeof(char)*400);
            while(book[j]!='\0')
            {
                if(book[j]!=' ')
                {
                    c[i]=book[j];
                    i++;
                    j++;
                }
                if(book[j]==' ')
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
            break;
            if(strcmp(book,"$")==0)
            break;
        }while(book[0]!= EOF);
    }

    int j=0;
    char *str[20];
    char *c;
    c=malloc(sizeof(char)*400);
    int i=0;
    int k=0;
    while(book[j]!='\0')
    {
        if(book[j]!=' ')
        {
            c[i]=book[j];
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
    k=k-2;
    return k;
}