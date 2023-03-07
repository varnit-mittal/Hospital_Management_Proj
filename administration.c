#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "utils.h"

void view_billing(char name[]);
void pharmacy(FILE *pha, char pharmacys[], char name[]) //global scanning through a file 
{
    pha=fopen("pharmacy.txt","r");
    if(pha!=NULL)                   //file pointer pointing to pharmacy.txt 
    {
        do
        {
            fgets(pharmacys,200,pha);
            int i=0,j=0;
            char *c;
            c= malloc(sizeof(char)*400); //c is taking input in the form of multiple strings
            while(pharmacys[j]!='\0')
            {
                if(pharmacys[j]!=' ')
                {
                    c[i]=pharmacys[j];
                    i++;
                    j++;
                }
                if(pharmacys[j]==' ') //if it will be a space then it stores it into a character pointer array
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
            if(strcmp(pharmacys,"$")==0) //we have added this as a customary sign to end our inputs with a $ sign
            {
                printf("Medicine-Not-Found-In-Stock..\n");
                break;
            }
        }while(pharmacys[0]!= EOF); //condition to check the end of file
    }
}
void view_pharma(char pharm[]) //breaking a string into words using spaces and end of string
{
    int j=0;
    char *str[20];
    char *c;                     //with this you can view the list of our medicines in our pharmacy
	c=malloc(sizeof(char)*400);
    int i=0;
    int k=0;
    while(pharm[j]!='\0') //check the end of line in a file
    {
        if(pharm[j]!=' ')
        {
            c[i]=pharm[j];  // storing individual characters into c until a space is found
            i++;
            j++;
        }
        else
        {
        	c[i]='\0';
            str[k]=malloc(sizeof(char)*410); //storing till a null character or empty space found
            str[k]=c;
            k++;
            i=0;
            c=malloc(sizeof(char)*400);
            j++;
        }
    }
    printf("Name of Medicine: %s\n",str[0]);
    printf("Company: %s\n",str[1]);
    printf("Stock Available: %s\n",str[2]);
    printf("Price: %s\n",str[3]);
}
void view_billing(char name[])
{
    billing_calc(name);
}

void doc_read(FILE *fp,char doc[],char doc_name[])
{
    fp=fopen("doc_data.txt","r");
    if(fp!=NULL)
    {
        do
        {
            fgets(doc,200,fp);    //this is pointing to the doc_data.txt file stored
            int i=0,j=0;
            char *c;
            c= malloc(sizeof(char)*400);
            while(doc[j]!='\0')
            {
                if(doc[j]!=' ')
                {
                    c[i]=doc[j]; //if there is a blank space in it then the values in c are inputted inside it
                    i++;         //storing till a blank file is found
                    j++;
                }
                if(doc[j]==' ')
                {
                    if(strcmp(c,doc_name)==0) //if values dont match then the loop  will break
                    break;
                    else
                    {
                        c= malloc(sizeof(char)*400);
                        i=0;
                        j++; //storing them dynamically in a string
                    }
                }
            }
            if(strcmp(c,doc_name)==0)
            break;                    //copying the values and ending the file if $ sign is written
            if(strcmp(doc,"$")==0)
            {
                printf("Doctor-Not-Found\n");
            break;
            }
        }while(doc[0]!= EOF);
    }
}

void doc_view(char doc[])   
{
    int j=0;
    char *str[20];
    char *c;
	c=malloc(sizeof(char)*400);
    int i=0;
    int k=0;
    while(doc[j]!='\0') //executing till an null character is found
    {
        if(doc[j]!=' ') //till an empty string is found it will store the characters in a char pointer called c in our code
        {
            c[i]=doc[j];
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
    printf("                    Doctor's Profile\n");
    printf("Name: %s\n",str[0]);
    printf("D.O.B: %s\n",str[1]);
    printf("Age: %s\n",str[2]);       //these are the parameters that we are considering for the doctor's profile
    printf("Gender: %s\n",str[3]);
    printf("Speciality: %s\n",str[4]);
    printf("Phone Number: %s\n",str[5]);
    printf("Email: %s\n",str[6]);
    printf("Address: %s\n",str[7]);
}

void clean_read(FILE *fp,char clean[])
{
    printf("Here is our cleaning staff:\n");
    printf("1.Hemang\n");
    printf("2.Hemant\n");
    printf("3.Tanish\n");
    printf("4.Shriya\n"); 
    printf("5.Ragini\n");
    printf("6.Soma\n");
    int i;
    printf("Select to view Profile: ");
    char *name=malloc(sizeof(char)*300); //this will point to our files that contain the cleaner data
    while(1)
    {
        scanf("%d",&i);
        switch(i)
        {
            case 1:
            {
                name="Hemang";
                break;
            }
            case 2:
            {
                name="Hemant";
                break;
            }
            case 3:
            {
                name="Tanish";
                break;
            }
            case 4:
            {
                name="Shriya";
                break;
            }
            case 5:
            {
                name="Ragini";
                break;
            }
            case 6:
            {
                name="Soma";
                break;
            }
            default:
            {
                printf("You have entered Something Wrong...\nPlease Re-enter....\n");
            }
        }
        if(i==1 || i==2 || i==3 || i==4 || i==5 || i==6)
        break;
    }
    fp=fopen("cleaning.txt","r"); //opening and pointing to the cleaning.txt file where we have stored the cleaner details in it
    if(fp!=NULL)
    {
        do
        {
            fgets(clean,200,fp);//getting the paramters
            int i=0,j=0;
            char *c;
            c= malloc(sizeof(char)*400);
            while(clean[j]!='\0')
            {
                if(clean[j]!=' ')
                {                   //storing the details into an empty string till a back space is found
                    c[i]=clean[j];
                    i++;
                    j++;
                }
                if(clean[j]==' ')
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
            break;                    //a customary end to our display with our $ sign
            if(strcmp(clean,"$")==0)
            break;
        }while(clean[0]!= EOF);
    }
}

void clean_view(char clean[])
{
    int j=0;
    char *str[20];
    char *c;
	c=malloc(sizeof(char)*400); //viewing our cleaner details 
    int i=0;
    int k=0;
    while(clean[j]!='\0')
    {
        if(clean[j]!=' ')
        {
            c[i]=clean[j];
            i++;
            j++;        //storing till an empty string is found
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
    printf("-----------------------Cleaner's Profile----------------------\n");
    printf("Name: %s\n",str[0]);
    printf("D.O.B: %s\n",str[1]);
    printf("Age: %s\n",str[2]);
    printf("Gender: %s\n",str[3]);
    printf("Cleaning Job: %s\n",str[4]);
    printf("Phone Number: %s\n",str[5]);
    printf("Email: %s\n",str[6]);
    printf("Address: %s\n",str[7]);
}
void wards_management(FILE *fp){    //this for navigating through the wards and searching for individual patients situated in our wards

    fp=fopen("wards_info.txt","r+");
    char *total_capacity = (char *)malloc(sizeof(char)*500); //assumed total_capacity is not more than 100 digits
    fscanf(fp,"%s",total_capacity);
    int total_cap = atoi(total_capacity); //converting a string of numbers to integers for our billing purposes
    char *temp=(char *)malloc(sizeof(char) * 300);
    size_t temp_capacity = 300;
    int i=0;
    while (strcmp(temp,"$")!=0) //ending with our customary display with a $ sign
    {
        getline(&temp,&temp_capacity,fp);
        ++i;
    }
    i=i/2-1;
    int current_capacity=i;
    printf("Do you want to search for a specific patient (y/n)? : ");
    char option;
    scanf(" %c",&option);
    if (option=='y')
    {
        char *patient=(char *)malloc(sizeof(char)*50);
        printf("Enter the patient name :\n");
        scanf("%s",patient);               
        rewind(fp);          //this will take file pointer to the first character of the file
        char *temp=(char *)malloc(sizeof(char)*50);
        if(fp!=NULL)
        { 
            do
            {
                fgets(temp,200,fp);
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
                    printf("----Patient Not Found-----\n");
                    return ;
                }
            }while(temp[0]!= EOF);
        }

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
        printf("Patient is %s\n",str[0]);
        printf("Ward Number :%s\n",str[1]);
        printf("Bed Number  :%s\n",str[2]);   //this gives us the individual details of the patient's info 
        printf("Disease is  :%s\n",str[3]);
        printf("Doctor Assigned is  :%s\n",str[4]); 
    }
    char n;
    printf("Do you want to know the usage statistics (y/n) : ");
    scanf(" %c",&n); //this will point the useage statistics of the beds and wards used
    if(n=='y'){
    printf("Current Usage : %d\n",current_capacity);
    printf("Total Capacity : %d\n",total_cap);
    printf("Usage = %d%%",(current_capacity/total_cap));
    printf("----------------------------------------------------------------\n");
    }    
}
void iccu_management(FILE *ifu){
    ifu=fopen("iccu_info.txt","r+"); //opening the iccu text files
    if (ifu==NULL){
        printf("Cannot find required file");
        return;
    }
      char *total_capacity = (char *)malloc(sizeof(char)*500); //assumed total_capacity is not more than 100 digits
    fscanf(ifu,"%s",total_capacity);
    int total_cap = atoi(total_capacity);          
    char *temp=(char *)malloc(sizeof(char) * 300);
    size_t temp_capacity = 300;
    int i=0;
    while (strcmp(temp,"$")!=0) 
    {
        getline(&temp,&temp_capacity,ifu); 
        ++i;
    }
    i=i/2-1;
    int current_capacity=i;
    printf("Do you want to search for a specific patient (y/n)? : ");  //for navigating to see a specific patient there
    char option;
    scanf(" %c",&option);
    if (option=='y')
    {
        
        char *patient=(char *)malloc(sizeof(char)*50);
        printf("Enter the patient name :\n");       //this will rewind back and show the details of the patient details previously entered 
        scanf("%s",patient);
        rewind(ifu);
        char *temp=(char *)malloc(sizeof(char)*50);
        if(ifu!=NULL)
        { 
            do
            {
                fgets(temp,200,ifu);
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
                    printf("----Patient Not Found-----\n");
                    return ;
                }
            }while(temp[0]!= EOF);
        }

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
        printf("Patient is %s\n",patient);
        printf("Ward Number :%s\n",str[1]);     //this gives the details of the patient if we choose him
        printf("Bed Number  :%s\n",str[2]);
        printf("Disease is  :%s\n",str[3]);
        printf("Doctor Assigned is  :%s\n",str[4]); 
    }
    char n;
    printf("Do you want to know the usage statistics (y/n) : ");
    scanf(" %c",&n);
    if(n=='y'){
    printf("Current Usage : %d\n",current_capacity);
    printf("Total Capacity : %d\n",total_cap);       //the statistics of the ghospital can also be seen over here
    printf("Usage = %d%%",(current_capacity/total_cap)*100);
    }
    printf("----------------------------------------------------------------\n");
}
void emergency_info(FILE * ieu){
    ieu=fopen("emergency_info.txt","r+");  // for reading the files
    char *total_capacity = (char *)malloc(sizeof(char)*500); //assumed total_capacity is not more than 500 digits
    fscanf(ieu,"%s",total_capacity);
    int total_cap = atoi(total_capacity);      // checking the total capacities in there
    char *temp=(char *)malloc(sizeof(char) * 300);
    size_t temp_capacity = 300;
    int i=0;
    while (strcmp(temp,"$")!=0)    //till we have not entered the $ sign in there
    {
        getline(&temp,&temp_capacity,ieu);
        ++i;
    }
    i=i/2-1;
    int current_capacity=i;  //shows the current capacity
    printf("Do you want to search for a specific patient (y/n)? : ");
                                   // to search for a specific patient in thhe records 
    char option;
    scanf(" %c",&option);
    if (option=='y')
    {
        
        char *patient=(char *)malloc(sizeof(char)*50);
        printf("Enter the patient name :\n");
        scanf("%s",patient);  
        rewind(ieu);     //for searching through the details in there
        char *temp=(char *)malloc(sizeof(char)*50);
        if(ieu!=NULL)
            { 
                do
                {
                    fgets(temp,200,ieu);
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
                        printf("----Patient Not Found-----\n");
                        return ;
                    }
                }while(temp[0]!= EOF);
            }

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
        printf("Patient  :%s\n",patient);
        printf("Ward Number :%s\n",str[1]);
        printf("Bed Number : %s\n",str[2]);        //displays the data 
        printf("Emergency is  :%s\n",str[3]);
        printf("Doctor Assigned  :%s\n",str[4]); 
    }
    char n;
    printf("Do you want to know the usage statistics (y/n) : ");
    scanf(" %c",&n);
    if(n=='y'){                                               //this displays the useage data
    printf("Current Usage : %d\n",current_capacity);
    printf("Total Capacity : %d\n",total_cap);
    printf("Usage = %d%%",(current_capacity/total_cap)*100);
    printf("----------------------------------------------------------------\n");
    }
}
void prof1(FILE *f,char name[], char c1[])
{
    f=fopen("admin_data.txt","r");
    do
    {
        fgets(c1,200,f);
        int i=0,j=0;                    //read opens the admin data files 
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
                {                     //if the details dont match then in that case
                    c= malloc(sizeof(char)*400);
                    i=0;
                    j++;
                }
            }
        }
        if(strcmp(c,name)==0)
        break;
    }while(c1[0]!= EOF);                //ending the while loop
} 

void view_prof1(char profile[])
{
    int j=0;
    char *str[20];
    char *c;
	c=malloc(sizeof(char)*400);           //for viewing the profiles 
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
    printf("Role in the Hospital: %s\n",str[4]);          //this is for viewing the doctors and other staaf member's profile 
    printf("Contact details: \n");
    printf("%s\n",str[5]);
    printf("%s\n",str[6]);
    printf("Adress: %s\n",str[7]);
}
void admin(char name[])
{        
    
    /*
    pharmacy management
    cleaning management
    billing
    wards management               //these following parameters will be covered in here
    ICU management
    emergency
    doctors
    */
   printf("*******************ADMIN PORTAL*********************\n");
   printf("Welcome %s\n",name);              //Welcome to the admin portal 
   
   while(1)
   {
        char *str1=malloc(sizeof(char)*300);
        char *str2=malloc(sizeof(char)*400);
        FILE *f1,*f2,*f3,*f4,*f5,*f6,*f7,*f8;
        printf("Enter the option to which you want to nevigate:\n");
        printf("1.pharmacy management\n");
        printf("2.cleaning management\n");
        printf("3.billing\n");
        printf("4.wards management\n");
        printf("5.ICU management\n");
        printf("6.Emergency 24X7\n");              //these are the options that we are willing to offer in our ADMIN PORTAL
        printf("7.Doctor's Profile\n");
        printf("8.View your profile\n");
        printf("9.EXIT\n");
        int i;
        scanf("%d",&i);
        switch(i)
        {
            case 1:
            {
                printf("************ Welcome to Ashadeep's Pharmacy *************\n");
                printf("Enter the medicine name to see the details of the medicine in the stock: ");
                scanf("%s",str1);
                pharmacy(f1,str2,str1);      //displays the pharmacy the stocks and details of the medicine
                if(strcmp(str2,"$")!=0)
                view_pharma(str2);
                break;
            }
            case 2:
            {
                printf("************************ This is Ashadeep's Cleaning Management System ************************\n");
                clean_read(f2,str1);
                clean_view(str1);   //for viewing the cleaing staff which we have previously made above
                break;
            }
            case 3:
            {
                printf("******************* This is Ashadeep's Billing Management System ***************************\n");
                printf("Enter the patient's name and view the billing:\n");
                scanf("%s",str1);        
                view_billing(str1);             //fetching the details that we had previously made
                break;
            }
            case 4:
            {
                printf("*************** This is Ashadeep's Ward Managment System ********************\n");
                wards_management(f4);         //opeing the fward management system files that we have made
                break;
            }
            case 5:
            {
                printf("*************** This is Ashadeep's ICU Management System ********************\n");
                iccu_management(f5);   //this is the ICU management system
                break;
            }
            case 6:
            {
                printf("*************** This is Ashadeep's Emergency 24X7 Management System ******************\n");
                emergency_info(f6);       //this is the emergency ward portal made
                break;
            }
            case 7:
            {
                printf("*********************** This is Ashadeep's Doctor Management System ************************\n");
                printf("Enter the name of the doctor you want to view the profile of: ");
                scanf("%s",str1);
                doc_read(f7,str2,str1);
                if(strcmp(str2,"$")!=0)         //this is for vewing the profiles the profiles of the doctors and their managements
                doc_view(str2);
                break;
            }
            case 9:
            {
                printf("Exiting........\n");        //exiting the application and breaking past it
                break;
            }
            case 8:
            {
                prof1(f8,name,str1);
                view_prof1(str1);
                break;
            }
            default:
            {
                printf("You must have entered a wrong value....\nRe-enter the value.....\n");
                break;             //when the values dont match
            }
        }
        if(i==9)
        break;
   }
}
