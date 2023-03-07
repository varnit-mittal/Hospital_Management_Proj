#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "utils.h"
void prof(FILE *,char name[], char c1[]);
void view_prof(char profile[]);                      // These are the global scanning files
void booking_data(FILE *,char [], char c1[]);        // These are the functions that are offered in our patient files
char* medications(FILE *fin, char name[]);
void view_booking_data(char data[]);             
void view_medic(char medic[]);
void make_booking(FILE * book, char str[], char name[]);
void records(FILE *rec,char name[],char recs[]);
void view_records(char recs[]);
void patient(char name[])
{
    FILE *fp;                  //The file pointers that open thee files
    FILE *f;
    FILE *f1;
    FILE *f2,*f3,*f4;
    char *profile =malloc(sizeof(char)*300);
    // fp= fopen("patient.txt","r");
    // fscanf(fp,"%s",name);
    printf("\nHi %s\n",name);
    char *make_bo=malloc(sizeof(char)*200);     //While you enter the name of the patient
    int b=1,i;
    while(b)
    {
        printf("\n");
        printf("Press 1 to view your medications\n");
        printf("Press 2 to view your bookings\n");
        printf("Press 3 to make new bookings\n");          //With the above functions defined you can see the following things about the patinet 
        printf("Press 4 to view your medical records\n");
        printf("Press 5 to view your profile\n");
        printf("Enter 6 to exit\n");
        scanf("%d",&i);
        switch(i)       //i is the option that you choose to view about the medical records
        {
            case 1:
            {
                char *medic= malloc(sizeof(char)*300);
                medic=medications(f,name);         //This is to view the medication's files
                view_medic(medic);
                break;
            }
            case 2:
            {
                char *bo=malloc(sizeof(char)*300);
                booking_data(f1,name,bo);
                int j=0;
                char *str[20];
                char *c;
                c=malloc(sizeof(char)*400);
                int i=0;
                int k=0;                //You can can book the files from here
                while(bo[j]!='\0')
                {
                    if(bo[j]!=' ')
                    {
                        c[i]=bo[j];
                        i++;
                        j++;
                    }
                    else
                    {
                        c[i]='\0';
                        str[k]=malloc(sizeof(char)*410);
                        str[k]=c;
                        k++;          //These are to enter the booking details
                        i=0;
                        c=malloc(sizeof(char)*400);
                        j++;
                    }
                }
                if(strcmp(bo,"$")!=0)
                {                   //Till our $sign is coming
                if(strcmp(str[0],name)==0)
                view_booking_data(bo);
                else                   //If the appointment is not accepted then it will display the following messages
                printf("Doctor didn't approve your booking yet or you didn't book any appointment\n");
                }
                else
                printf("Doctor didn't approve your booking yet or you didn't book any appointment\n");
                break;
            }
            case 3:
            {
                make_booking(f2,make_bo,name);          //To make the necessary changes in bookings
                break;
            }
            case 4:
            {
                char *re=malloc(sizeof(char)*300);
                records(f3,name,re);
                int j=0;
                char *str[20];
                char *c;
                c=malloc(sizeof(char)*400);          //To view your medical records that are about you
                int i=0;
                int k=0;
                while(re[j]!='\0')
                {                                    //Executing till the null character
                    if(re[j]!=' ')
                    {
                        c[i]=re[j];
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
                if(strcmp(re,"$")!=0)       //ending till our $ sign 
                {
                if(strcmp(str[0],name)==0)
                view_records(re);
                else
                printf("No records available"); //If your name does not matches with the records that our available
                }
                else
                printf("No records available");
                break;
            }
            case 5:
            {
                prof(f4,name,profile);
                view_prof(profile);                 //This function is to view your profiles
                break;
            }
            case 6:
            {
                printf("You are exiting...\n");
                break;           //Exiting the application the patient details
            }
            default:
            {
                printf("You have entered a wrong value..\nPlease Try again..\n");
                break;
            }         //Incase the given inputs dont match then we are givng another chance
        }
        if(i==6)
        b=0;   //   This exits the application returning us back to ground 0
    }
    
}  
void prof(FILE *f,char name[], char c1[])           //global scanning
{
    f=fopen("pat_data.txt","r");
    do
    {                         //opens the patinet data txt file that we have made
        fgets(c1,200,f);
        int i=0,j=0;
        char *c;
        c= malloc(sizeof(char)*400);
        while(c1[j]!='\0')
        {
            if(c1[j]!=' ')
            {                            //Storing the dara
                c[i]=c1[j];
                i++;
                j++;
            }
            if(c1[j]==' ')
            {
                if(strcmp(c,name)==0)
                break;        //For copying the details
                else
                {
                    c= malloc(sizeof(char)*400);
                    i=0;
                    j++;
                }
            }
        }
        if(strcmp(c,name)==0)
        break;             //If it matches
    }while(c1[0]!= EOF);
}

void view_prof(char profile[])
{
    int j=0;
    char *str[20];              //This is to view the patinet's profile
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
            str[k]=c;                  //for storing the details
            k++;
            i=0;
            c=malloc(sizeof(char)*400);
            j++;
        }
    }
    printf("Name: %s\n",str[0]);
    printf("D.O.B: %s\n",str[1]);           //These are the necessary functions or the necessary details
    printf("Age: %s\n",str[2]);
    printf("Gender: %s\n",str[3]);          //The details that this contains
    printf("Contact details: \n");
    printf("%s\n",str[4]);
    printf("%s\n",str[5]);
    printf("Adress: %s\n",str[6]);
}
void booking_data(FILE * booking_file,char name[], char c1[])       //For booking the files it will open
{
    booking_file=fopen("booking_data.txt","r");
    if(booking_file!=NULL)          //opening the booking data files
    {
        
        do
        {
            fgets(c1,200,booking_file);         //This opens the booking txt files
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
                if(c1[j]==' ')          //enters till a null character comes
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
            if(strcmp(c1,"$")==0) //ending with our $ sign in the txt file
            break;
        }while(c1[0]!= EOF);
    }
}
void view_booking_data(char booking_data[]){        //for veiwing our patinet profiles
    int j=0;
    char *data_elements[20];
    char *elements;
	elements=malloc(sizeof(char)*400);
    int i=0;
    int k=0;
    while(booking_data[j]!='\0')  //displays till our null character is met 
    {
        if(booking_data[j]!=' ')
        {
            elements[i]=booking_data[j];
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
    printf("Doctor: %s\n",data_elements[1]);
    printf("(%s)\n",data_elements[2]);
    printf("Date: %s\n",data_elements[3]);    //This displays the details that we had earlier added 
    printf("Time: %s\n",data_elements[4]);
    printf("Contact details:%s\n",data_elements[5]);
    printf("Allocated slot (Y\\N) %s\n",data_elements[6]);      //I will display these details
}
char* medications(FILE *fin, char name[])           //global scanning
{
    fin=fopen("medications_data.txt","r"); //for opening the medication files
    char *c1=malloc(sizeof(char)*400);
    do
    {
        fgets(c1,400,fin);
        int i=0,j=0;
        char *c;
        c= malloc(sizeof(char)*400);
        while(c1[j]!='\0')           //For storing the individual data
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
    }while(c1[0]!=EOF);

    return c1;
}

void view_medic(char medic[])       //This views the medical details shown 
{
    int j=0;
    char *c;
	c=malloc(sizeof(char)*400);
    int i=0;
    int k=0;
    while(medic[j]!='\0')
    {
        if(medic[j]!=' ')
        {
            c[i]=medic[j];
            i++;            //For storing of the files 
            j++;
        }
        else
        {
        	c[i]='\0';
            printf("%s\n",c);
            i=0;
            c=malloc(sizeof(char)*400);
            j++;
        }
    }
    
}
void make_booking(FILE * book,char str[], char name[]) ///global scanning bieng done here again
{
    book = fopen("new_book.txt","r+");
    update2(book,str,name);
    printf("Booking is done...Please wait for confirmation...Your patience is appreciated..\n");
    fclose(book); //For booking of the patients
}       //this will be stored with the help of FILE I/O in our databases files 

void records(FILE *rec,char name[],char recs[])         //for opening our records file
{
    rec=fopen("record.txt","r");  //reading through our records file
    if(rec!=NULL)
    {
        do
        {
            fgets(recs,200,rec);    //for getting our records file
            int i=0,j=0;
            char *c;
            c= malloc(sizeof(char)*400);
            while(recs[j]!='\0')
            {
                if(recs[j]!=' ')
                {
                    c[i]=recs[j];
                    i++;
                    j++;         //storing the files 
                }
                if(recs[j]==' ')
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
            if(strcmp(recs,"$")==0)        //ending with our $ sign 
            break;
        }while(recs[0]!= EOF);
    }

}
void view_records(char recs[])       //for viewing the records 
{   
    int j=0;
    char *data_elements[20];
    char *elements;
	elements=malloc(sizeof(char)*400);
    int i=0;
    int k=0;
    while(recs[j]!='\0')
    {
        if(recs[j]!=' ')
        {
            elements[i]=recs[j];         //reading and storing the data
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
    // Height
    //Weight
    //Blood Pressure
    // Oxygen measurements

    printf("Height: %s\n",data_elements[1]);
    printf("Weight: %s\n",data_elements[2]);
    printf("Blood Pressure: %s\n",data_elements[3]);        //The patient's details
    printf("spO2: %s\n",data_elements[4]);
    int m=5;
    while(m!=12)
    {
        printf("Test-%d: %s\n",m-4,data_elements[m]); //the final test details
        m++;
        
    }

}
