#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
struct date {
    int day;
    int month;
    int year;             //This creates a structure consisting of day month and years
};

int isLeapYear(int year) {
    if (year % 4 != 0) {                //this function is to check whether a given year is a leap year or not
        return 0;
    } else if (year % 100 != 0) {
        return 1;
    } else if (year % 400 != 0) {       //this for comparing the parameeters of a leap year or not
        return 0;
    } else {
        return 1;
    }
}

int daysInMonth(int month, int year) {
    int days = 0;
    switch (month) {
        case 1:                    //for comparing the days and the months
            days = 31;
            break;
        case 2:
            if (isLeapYear(year)) {
                days = 29;                 //if it is not a leap year then.....
            } else {
                days = 28;
            }
            break;
        case 3:
            days = 31;
            break;
        case 4:
            days = 30;
            break;
        case 5:
            days = 31;
            break;
        case 6:
            days = 30;
            break;
        case 7:                        //THESE ARE THE DIFFERENT DATE CASES IN HERE
            days = 31;
            break;
        case 8:
            days = 31;
            break;
        case 9:
            days = 30;
            break;
        case 10:
            days = 31;
            break;
        case 11:
            days = 30;
            break;
        case 12:
            days = 31;
            break;
    }
    return days;
}

int dateToDays(struct date d) {
    int days = 0;
    int i;                                      //checking if the given year is a leap year or not
    for (i = 1; i < d.year; i++) {
        if (isLeapYear(i)) {
            days += 366;
        } else {
            days += 365;
        }
    }
    for (i = 1; i < d.month; i++) {
        days += daysInMonth(i, d.year);
    }
    days += d.day;             //this adds and tells you the total no. of days used in this
    return days;
}

int diff_dates(char *d_in,char *d_out) {
    
    struct date date1a, date2b;
    int days1, days2, diff;             //THIS is for computing the difference between the dates 
    char *day=malloc(5);
    for (int i = 0; i < 2; i++)
    {
        day[i]=d_in[i];
    }  
    char *month=malloc(5);
    int j=3;
    for (int i = 0; i < 2; i++)
    {
        month[i]=d_in[j];
        j++;
    }
    char *year=malloc(5);
    int k=5;
    for (int i = 0; i < 2; i++)
    {
        year[i]=d_in[k];
        k++;
    }
    (date1a.day=atoi(day));
    (date1a.month=atoi(month));             //this is for adding and calculating the total number of days months and year
    (date1a.year=atoi(year));

    char *day1=malloc(5);
    for (int i = 0; i < 2; i++)
    {
        day1[i]=d_out[i];
    }  
    char *month1=malloc(5);
    int jj=3;
    for (int i = 0; i < 2; i++)
    {
        month1[i]=d_out[jj];
        jj++;
    }                                //for computing the diffence between the dates
    char *year1=malloc(5);
    int kk=5;
    for (int i = 0; i < 2; i++)
    {
        year1[i]=d_out[kk];
        kk++;
    }
    (date2b.day=atoi(day1));
    (date2b.month=atoi(month1));
    (date2b.year=atoi(year1));

    days1 = dateToDays(date1a);
    days2 = dateToDays(date2b);
    diff = abs(days1 - days2);
    // printf("Difference between dates: %d days\n",diff);
    return diff;                   //This is returing the net difference between the dates
}
