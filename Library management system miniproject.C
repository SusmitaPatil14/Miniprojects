#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct lib_stud {
 char  fname[20],ID[10];
 struct lib_stud *next;
};
struct lib_book {
 char  title[50]; int stock;
 struct lib_book *next;
 
 };
struct lib_issue {
 char  name[50],ID[10],title[50];
 int idate,idatem,idatey;
 };
 struct lib_retbook {
 char  name[50],ID[10],title[20]; int rdate,idatem,idatey;
 };
/*====================================================student=============================*/
void savedata()
{
	FILE *outfile;
	char c;
   struct lib_stud *input,*head;;

    // open Accounts file for writing
   outfile = fopen ("studentrec.txt","a");
   if (outfile == NULL)
     {
      fprintf(stderr, "\nError opening file\n\n");
      goto here;
     }
      printf("%c\n",c);
     c='y';
     while((c!='n') && (c!='N'))
     {

     input=(struct lib_stud*)malloc(sizeof(struct lib_stud));
     input->next=NULL;
     head=input;

     printf("Enter student name...");
     scanf("%s", input->fname);  fflush(stdin);
     printf("Enter student ID...");
     scanf("%s", input->ID);
     fflush(stdin);
     printf("Do you want to continue Y/N");
     scanf("%c", &c);
     fwrite (input, sizeof(struct lib_stud), 1, outfile);


     }
      fclose(outfile);
      
      here: printf("");
}

void showdata()
{
		FILE *infile;
		struct lib_stud input;
	infile = fopen("studentrec.txt", "r");
	if (infile == NULL)
     {
      fprintf(stderr, "\nPlease enter records!\n\n");
      goto here;
     }
  printf("\nNAME\tID\n");
     printf("\n----\t--\n");
   while (fread (&input, sizeof(struct lib_stud), 1, infile))
    printf ("%s\t%s\n",input.fname, input.ID);
    fclose(infile);
	printf("\n==================================End=================================\n");
	here: printf("");
}
/*====================================================student=============================*/


/*====================================================book=============================*/
void savedatab()
{
	char c;
	c='y';
	while((c!='n') && (c!= 'N'))
{
	int action=0;
	action=1;
	char title[50];
	int dbstock;
	struct lib_book xxx;
	
	FILE *f;
	f=fopen("bookrec.txt","r");
	printf("Enter book title:");
	scanf("%s", title);
	
	   while (fread (&xxx, sizeof(struct lib_book), 1, f))
{
	if(strcmp(title,xxx.title)==0)
	{
		//printf("Book rec found!");
		 action=2;
		dbstock=xxx.stock;
		goto here;
	}
}

	here: printf("");
	fclose(f);
	
	if(action ==1)
	{
		
	
	
	FILE *outfile, *outfile1; char c;
   struct lib_book *input,*head;
    // open Accounts file for writing
   outfile = fopen ("bookrec.txt","a");
   if (outfile == NULL)
     {
      fprintf(stderr, "\nError opening file\n\n");
      exit (1);
     }
     
     input=(struct lib_book*)malloc(sizeof(struct lib_book));
     input->next=NULL;
     head=input;
     
    
     strcpy(input->title,title);
     printf("Enter stock...");
     scanf("%d", &input->stock);
     
     fflush(stdin);
     
    
          fwrite (input, sizeof(struct lib_book), 1, outfile);

      fclose(outfile);
}
else
{
	
	FILE *outfile, *outfile1; char c;
   struct lib_book *input,*head;
    // open Accounts file for writing
   outfile = fopen ("bookrec.txt","a");
   if (outfile == NULL)
     {
      fprintf(stderr, "\nError opening file\n\n");
      exit (1);
     }
     
     input=(struct lib_book*)malloc(sizeof(struct lib_book));
     input->next=NULL;
     head=input;
     
     
     strcpy(input->title,title);
     printf("Enter stock...");
     scanf("%d", &input->stock);
     
     printf("Updated stock =%d\n\n\n\n",input->stock+dbstock);
     
     fflush(stdin);
     
    
          fwrite (input, sizeof(struct lib_book), 1, outfile);

       fclose(outfile);
	
	
	
	
}//end of if

printf("Do you wish to continue Y/N?");
scanf("%c", &c);
}
}


/*void savedatab()
{
	FILE *outfile; char c;
   struct lib_book *input,*head;
    // open Accounts file for writing
   outfile = fopen ("bookrec.txt","a");
   if (outfile == NULL)
     {
      fprintf(stderr, "\nError opening file\n\n");
      exit (1);
     }
     
     input=(struct lib_book*)malloc(sizeof(struct lib_book));
     input->next=NULL;
     head=input;
     
      c='y';
     while((c!='n') && (c!='N'))
     {
     printf("Enter book title...");
     scanf("%s", input->title);
     printf("Enter stock...");
     scanf("%d", &input->stock);
     
     fflush(stdin);
     
    printf("Do you want to continue Y/N");
     scanf("%c", &c);
          fwrite (input, sizeof(struct lib_book), 1, outfile);
  }      fclose(outfile);

}
*/
void showdatab()
{

		FILE *infile;
		struct lib_book input;
	infile = fopen("bookrec.txt", "r");
	if (infile == NULL)
     {
      fprintf(stderr, "\nPlease enter records!\n\n");
      goto here;
     }
      printf("\nTITLE\tSTOCK\n");
      printf("\n-----\t-----\n");
   while (fread (&input, sizeof(struct lib_book), 1, infile))
    printf ("%s\t%d\n\n",input.title, input.stock);

    fclose(infile);
    here: printf("");

}


/*====================================================book=============================*/

/*====================================================issue book=============================*/

void savedataib()
{
	
	time_t t = time(NULL);
	FILE *chkinfile, *chkinfile1,*chkinfile5; int ctr;
	struct lib_issue chkinput;
	struct lib_book chkbook;
	struct lib_stud chkstud;
     int flag,flag11,ii;
	FILE *outfile;
    struct lib_issue input;
    struct lib_book input1;
    char srcname[50];
    struct tm tm = *localtime(&t);
    // open Accounts file for writing
   outfile = fopen ("issue.txt","a");
   if (outfile == NULL)
     {
      fprintf(stderr, "\nError opening file\n\n");
      exit (1);
     }


     printf("Enter student name...");
     scanf("%s", input.name);
     printf("Enter student ID...");
     scanf("%s", input.ID);
     //=========================================
     
     
     //=============================================
     
    chkinfile5 = fopen ("studentrec.txt","r");
   if (chkinfile5 == NULL)
     {
      fprintf(stderr, "\nError opening file\n\n");
      exit (1);
     }
     fflush(stdin);

     //strcpy(srcname, input.name);
     
      while (fread (&chkstud, sizeof(struct lib_stud), 1, chkinfile5))
     {
     		 if(strcmp(chkstud.fname,input.name)==0 && strcmp(chkstud.ID,input.ID)==0) 
     	     {    flag11=1;
     	 }
     }
     	
     //	printf("\n\n\n\n%s\n\n\n\n", chkstud.fname);
	 if(flag11==1) 
	 { goto here1; }
     else
     {
	 printf("STUDENT RECORD NOT FOUND!!");
     goto here;
	     }
		 

     //===================================
     
     
     here1: printf("");
     
     
     
     
     
     

chkinfile = fopen("issue.txt", "r");
        if (chkinfile == NULL)
     {
      fprintf(stderr, "\nError opening file\n\n");
      exit (1);
     }
 ctr=0;
    while (fread (&chkinput, sizeof(struct lib_issue), 1, chkinfile))
   {if(strcmp(chkinput.name,input.name)==0 && strcmp(chkinput.ID,input.ID)==0) ctr++; 
   }

  

   if (ctr>=4)
   {
   printf("STUDENT HAS TAKEN 4 BOOKS ALREADY....! ");  //break;
   goto here;
   }
   else
     {
   printf("%d BOOKS ISSUED TILL DATE....\n\n", ctr); 
   
   printf("***********************ISSUE DATE:  %d/%d/%d******************************\n\n",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);

    }

   fclose(chkinfile);
    
     
     //=========================================
          
    
	
	
	 printf("Enter book title...");
     scanf("%s", input1.title);
     //=========================================
  
     
     chkinfile1 = fopen("bookrec.txt","r");
    if (chkinfile1 == NULL)
     {
      fprintf(stderr, "\nBook records not available.  Please check if book details are entered!\n\n");
      goto here;
     }
 
	

	
	flag=0;
	while (fread (&chkbook, sizeof(struct lib_book), 1, chkinfile1))
   {
  
       if(strcmp(chkbook.title,input1.title)==0)
	   {flag=1;  
	   	   break;
	
	    } 
	}
	 
	    if(flag==1)
       {  
	   
	   
	   
	    printf("NO OF COPIES AVAILABLE ARE : %d\n",chkbook.stock);  
     
          
	 input.idate = tm.tm_mday;
	 input.idatem =tm.tm_mon + 1;
	 input.idatey  = tm.tm_year+1900;
	 strcpy(input.title, input1.title);
	 
     
     printf("Stock for the book title: %s is updated. \nAVAILABLE STOCK IS: %d\n\n", chkbook.title, --chkbook.stock);
     
     fwrite (&input, sizeof(struct lib_issue), 1, outfile);
     fclose(outfile);
	 
}
	  
	   else
 {
   printf("PLEASE ENTER BOOK DETAILS FIRST.....EXITING\n\n\n\n"); 
}
	  
	  
	here: printf("Exiting to Main Menu\n\n");
	  

 }


void showdataib()
{
		FILE *infile;
		struct lib_issue input;
        infile = fopen("issue.txt", "r");
        if (infile == NULL)
     {
      fprintf(stderr, "\nNo records found in the file!\n\n");
      goto here;
     }
     printf("\nNAME\tID\tTITLE\tDATE\n");
     printf("\n----\t-----\t---------\t----\n");
   while (fread (&input, sizeof(struct lib_issue), 1, infile))
    printf ("%s\t%s\t%s\t%d/%d/%d\n",input.name,input.ID, input.title,input.idate,input.idatem,input.idatey);
    fclose(infile);
	here: printf("Exiting to Main Menu\n\n");
}


/*====================================================issue book=============================*/


/*====================================================return book=============================*/

/*void savedatarb()
{

time_t t = time(NULL);

	FILE *chkinfile; int ctr;
	struct lib_issue chkinput;
    int flag;
    int due;
    char title[50];
	FILE *outfile;
    struct lib_retbook input;
    int issuedondate,issuedondate1,issuedondate2;
   outfile = fopen ("retbook.txt","a");
   if (outfile == NULL)
     {
      fprintf(stderr, "\nError opening file\n\n");
      exit (1);
     }
struct tm tm = *localtime(&t);	


     printf("Enter student name...");
     scanf("%s", input.name);
   
   
       
	  		
	  printf("Enter book title:");
	  scanf("%s", input.title);
	  
	  printf("Enter issue date (DD):");
	  scanf("%d",&issuedondate);
	  	 input.rdate = tm.tm_mday;
	  	 input.idatem = tm.tm_mon+1;
	  	 input.idatey = tm.tm_year+1900;
	  	
        printf("************************RETURN DATE = %d/%d/%d***********************************\n\n\n", tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
     
     
      fwrite (&input, sizeof(struct lib_retbook), 1, outfile);
         // printf("Diff between issue date and today is %d \nPLEASE REFER TO THE FINE CHART IN CASE YOU CROSS 7 DAY LIMIT....!!!!\n\n\n", input.rdate-issuedondate );
          due=0;
          if(input.rdate-issuedondate>7)
          {
          	due=input.rdate-issuedondate-7;
          printf("FINE: %d\n\n\n", (due)*2);
      }
      else
      { printf("\nTHERE ARE NO EXTRA CHARGES!\nTHANK YOU FOR USING THE LIBRARY MANAGEMENT SYSTEM (Version 1.0)\n\n\n");
      }
      fclose(outfile);
       
}*/

/*====================================================return book=============================*/

void savedatarb()
{
		time_t t = time(NULL);
        struct tm tm = *localtime(&t);

	
	struct lib_issue isss;
	struct lib_book ibbb;
	struct lib_retbook rbbb;
	char sname[50],title[50],sID[10];
	int d,m,y,late,fflag;
	late=0;fflag=0;
	printf("Enter student name:");
	scanf("%s",sname);
	printf("Enter student ID:");
	scanf("%s",sID);
	printf("Enter book title:");
	scanf("%s",title);
	FILE *fff;
	fff=fopen("issue.txt","r");
	
   while (fread (&isss, sizeof(struct lib_issue), 1, fff))
	{
		
	
	if((strcmp(isss.name,sname)==0) && (strcmp(isss.ID,sID)==0) && (strcmp(isss.title,title)==0)  )
	{
		
	  d=isss.idate; m=isss.idatem;y=isss.idatey;
	  
	  printf("The book was issued on : %d/%d/%d\n",d,m,y); fflag=1;
	}
}
	if (fflag==0)
	{
		
		goto there;
	}
	
	
	
	fclose(fff);
	
	
	fff=fopen("bookrec.txt","r");
	
	while (fread (&ibbb, sizeof(struct lib_book), 1, fff))
	{
		
		
	if(strcmp(ibbb.title,title)==0)
	{
	  printf("UPDATED THE STOCK FOR THE BOOK RETURNED WITH TITLE = %s\nOLD STOCK = %d\nNEW STOCK=%d\n", title,ibbb.stock-1,ibbb.stock);
	}
	
	
	}
	fclose(fff);
	

    if(tm.tm_mday - d > 7)
    {
       	 late = (tm.tm_mday-d)*2;
       	 printf("LATE FEE = %d\n", late);
     } 
     else
     {
     	printf("NO LATE CHARGES\n");
     }
	

	strcpy(rbbb.name,sname);
	strcpy(rbbb.title,title);
	rbbb.rdate = tm.tm_mday;
	rbbb.idatem=tm.tm_mon+1;
	rbbb.idatey=tm.tm_year+1900;
	printf("\nReturn date = %d/%d/%d\n",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
	strcpy(rbbb.ID,sID);
	fff=fopen("retbook.txt","a");
    fwrite (&rbbb, sizeof(struct lib_retbook), 1, fff);

	fclose(fff);
	goto endit;
	
	there: printf("Please check the entered data, ensure correct student name, ID, book title is entered\n\nExiting to the main Menu....\n\n\n");
	endit: printf("");
}


void showdatarb()
{
	

		FILE *infile;
		struct lib_retbook input;
        infile = fopen("retbook.txt", "r");
        if (infile == NULL)
     {
      fprintf(stderr, "\nRecords not available\n\n");
       goto here;
     }
     printf("Name    ID       Title      RetDate\n");
   while (fread (&input, sizeof(struct lib_retbook), 1, infile))
    printf ("%s\t%s\t%s\t%d/%d/%d\n",input.name,input.ID, input.title,input.rdate,input.idatem,input.idatey);
    

    
    fclose(infile);
   here: printf("");
}







int main()
{
	
	int ans=0;
	while(1)
	{
	printf("===================LIBRARY MANAGEMENT SYSTEM=============================\n");
	printf("===========================MAIN MENU=====================================\n");

	printf("1.Student data entry \n2.Display student records\n3.Book data entry\n4.Display book records\n5.Issue book\n6.Display issue records\n7.Return book\n8.Display return records\n9.Exit\n");
	printf("===========================MAIN MENU=====================================\nEnter you choice (1 through 9)....");	
	scanf("%d",&ans);
	
	switch(ans)
	{
		case 1:
			printf("Student records data entry...\n\n");
			savedata();
			
			
			break;
		case 2:
			printf("Displaying student records...\n\n");
			showdata();
			break;
		case 3:
			printf("Book records data entry...\n\n");
			savedatab();
			break;
		case 4:
			printf("Displaying book records...\n\n");
			showdatab();
			break;
		case 5:
			printf("Issue book...\n\n");
			savedataib();
			break;
		case 6:
			printf("Displaying issue records...\n\n");
			showdataib();
			break;
		case 7:
			printf("Return book data entry...\n\n");
			savedatarb();
			break;
		case 8:
			printf("Displaying return records...\n\n");
			showdatarb();
			break;
		case 9:
			printf("Exiting the system....\nTHANK YOU FOR USING THE LIBRARY MANAGEMENT SYSTEM!");
			exit(1);
		break;
    }
	
   }
	
	
	return 0;
}


