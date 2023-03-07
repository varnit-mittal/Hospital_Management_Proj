#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "utils.h"
#define COLOR_BOLD_RED  "\e[1;31m"             //THESE ARE FOR THE DISPLAYS 
#define COLOR_OFF   "\e[m"                     
int main()
{
    
    printf(COLOR_BOLD_RED "                       Welcome to Ashadeep Hospital                  \n" COLOR_OFF);
    int i;
    printf("1. Existing User \n");
    printf("2. New User\n\n");             //The main welcome portal to OUR ASHADEEP HOSPITAL 
    int b=1;
    while(b)
    {
        int j;
        scanf("%d",&i);
        switch(i)
        {
            case 1:
            {
                printf("You are an existing user: \n");
                printf("Please select whether you want to enter as a: \n");       //We are giving you three optiions 
                                                                                  //You can enter this in 3 ways Doctor Patient And the Admin Staff
                printf("1. Doctor\n");
                printf("2. Patient\n");
                printf("3. Admin Staff\n");
                printf("4. To go to previous options\n");
                scanf("%d",&j);
                switch(j)
                {
                    case 1:
                    {  
                        doc_exist_user();        //opening the doctor's data that we have previously made
                        break;
                    }
                    case 2:
                    {
                        pat_exist_user();              //printing the patinets details that we have asked for in there
                        break;
                    }
                    case 3:
                    {
                        admin_exist_user();
                        break;                    //opening the admin portal in there
                    }
                    case 4:
                    {
                        printf("Going back to previous options\n");          //if it is an existing user or a new user in there
                        printf("1. Existing User \n");
                        printf("2. New User\n");
                        break;
                    }
                    default:
                    {
                        printf("Going back to previous options\n");
                        printf("1. Existing User \n");
                        printf("2. New User\n");              //in any other case going back to the previous options is considered
                        break;
                    }

                }
                break;
            }
            case 2:
            {
                printf("You are a new user: \n");
                printf("Please select whether you want to enter as a: \n");     //if you are a new user then
                printf("1. Doctor\n");
                printf("2. Patient\n");
                printf("3. Admin Staff\n");         //three ways you can access this website
                printf("4. To go to previous options\n");
                scanf("%d",&j);
                switch(j)
                {
                    case 1:
                    {
                        doc_new_user();
                        printf("Welcome Doctor\n");
                        break;                  // for entering the details of the doctor
                    }
                    case 2:
                    {
                        pat_new_user();
                        printf("Welcome\n");
                        printf("Don't Worry! Good care will be given :) \n");       //for entering the details of the patient
                        break;
                    }
                    case 3:
                    {
                        admin_new_user();
                        printf("Welcome to the team \n");           //for accessing the admin staff responsible for the task that they have to carryout
                        break;
                    }
                    case 4:
                    {
                        printf("Going back to previous options\n");
                        printf("1. Existing User \n");
                        printf("2. New User\n");
                        break;
                    }
                    default:
                    {
                        printf("Going back to previous options\n");
                        printf("1. Existing User \n");             //going back to the previous options
                        printf("2. New User\n");
                        break;
                    }

                }
                break;
            }
            default:
            {
                printf("You have entered a Wrong Value\n Please try again.....\n");
                printf("1. Existing User \n");        //in case the wrong values are entered
                printf("2. New User\n");
            }
        }
        if(i==1)
        {
            if(j==1 || j==2 || j==3)
            b=0;
        }                           //for 1 and 2 this will default back to 0 so that we can enter the details again and again
        if(i==2)
        {
            if(j==1 || j==2 || j==3)
            b=0;
        }
    }
    
}