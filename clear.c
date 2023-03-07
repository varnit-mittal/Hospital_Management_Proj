#include<stdio.h>
int main()
{
    FILE *f1=fopen("pat_pswd.txt","w");
    FILE *f2=fopen("pat_data.txt","w");
    FILE *f3=fopen("admin_data.txt","w");
    FILE *f5=fopen("admin_pswd.txt","w");
    FILE *f4 =fopen("doc_pswd.txt","w");
    FILE *f6=fopen("doc_data.txt","w");
    FILE *f8 =fopen("patient.txt","w");
    FILE *f9=fopen("billing.txt","w");
    FILE *f10=fopen("record.txt","w");
    FILE *f11=fopen("booking_data.txt","w");
    FILE *f12=fopen("new_book.txt","w");
    FILE *f13=fopen("billing.txt","w");
    FILE *f15=fopen("emergency_info.txt","w");
    FILE *f16=fopen("iccu_info.txt","w");
    FILE *f17=fopen("medications_data.txt","w");
    FILE *f18=fopen("new_book.txt","w");
    FILE *f20=fopen("wards_info.txt","w");
    FILE *f21=fopen("iccu_in_out.txt","w");
    FILE *f22=fopen("emergency_in_out.txt","w");
    FILE *f23=fopen("wards_in_out.txt","w");
    FILE *f24=fopen("pat_ward.txt","w");
    fprintf(f24,"%s","$"); 
    fprintf(f21,"%s","$");
    fprintf(f22,"%s","$");
    fprintf(f23,"%s","$");
    fprintf(f2,"%s","$");
    fprintf(f3,"%s","$");
    fprintf(f4,"%s","$");
    fprintf(f5,"%s","$");
    fprintf(f6,"%s","$");
    fprintf(f8,"%s","$");
    fprintf(f9,"%s","$");
    fprintf(f10,"%s","$");
    fprintf(f11,"%s","$");
    fprintf(f12,"%s","$");
    fprintf(f13,"%s","$");
    fprintf(f15,"800\n%s","$");
    fprintf(f16,"700\n%s","$");
    fprintf(f17,"%s","$");
    fprintf(f18,"%s","$");
    fprintf(f20,"1000\n%s","$");
}
 /*This includes the admin data
 The user data 
 The ward informations 
 The emergency medications 
 The Pharmacy details                                      
 The billing details and necessary informations 
 The new details*/