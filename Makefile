$(CC) = gcc
final:
		$(CC) administration.c admin_login.c admin_signup.c billing.c update.c pat_login.c pat_signup.c diff_dates.c update2.c doc.c doc_login.c doc_signup.c main.c patient.c del.c -o hsp.out

Clean:
		rm *.o hsp.out


		    
          
       
