#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>


using namespace std;

class Student
{
	private:
		char  phone[15],branch[25];
		int roll,sem;
	public:
		char name[50];
		virtual void LibStatus()
		{
			char libname[50],libstatus[5];
			cout<<"For Current Student:"<<endl;
			ttt:
			cout<<"Enter student Name:";
			cin>>libname;
			
			
			
			//0000000000000000000000000000000000000000000000000
			
			ifstream sfile_obj;
        		Student sobj;
        		int flag=0;
        		sfile_obj.open("NHw.txt",ios::in);
                sfile_obj.seekg(0,ios::beg);
                
				
				
				while(!(sfile_obj.eof()))
    			{
        			sfile_obj.read((char*)&sobj, sizeof(sobj));
    			
    			//cout<<strcmp(sobj.name,libname)<<endl;
    			if(strcmp(sobj.name,libname)==0)
    			{
    				flag = 1;
    			break;		  			
        		}
        	}
        			//cout<<"flag = "<<flag;
        	    sfile_obj.close();
    			if(flag!=1)
    			{
    				cout<<"Enter valid student name...."<<endl;
    			 goto ttt;
    		    }
    		    
			//0000000000000000000000000000000000000000000000000
			
			cout<<"Enter Library Membership Status (Yes / No )";
			cin>>libstatus;
		}
		void accept()
		{
			
        	int i;	
			cout<<"Enter name :";
			cin>>name;
			cout<<"Enter branch:";
			cin>>branch;
			ssss:
			cout<<"Enter sem";
			cin>>sem;
			if(sem <1 || sem>8)
			{
				cout<<"Enter valid sem..."<<endl;
				goto ssss;
		    }
					
			phoneagain:	
			while(2)
			{
			cout<<"Enter phone number :";
			cin>>phone;
			
			
			for( i=0;i<=strlen(phone);i++)
			{
				
			}
			int x=--i;
			if (x!=10)		
			{
				cout<<"You have entered "<<x<<" digits!"<<endl;
				cout<<"Phone number should be 10 digits! Please try again..."<<endl;
				continue;
		    }
			break;
		   }
			
			//+++++++++++++++++++++
				ifstream sfile_obj;
        		Student sobj;
        		int flag=0;
        		sfile_obj.open("NHw.txt",ios::in);
                sfile_obj.seekg(0,ios::beg);
                 while(!(sfile_obj.eof()))
    			{
        			sfile_obj.read((char*)&sobj, sizeof(sobj));
        			
        			if(strcmp(sobj.phone,phone)==0)
        			{
        				cout<<"Duplicate phone number....";
        				flag=1;
 						break;       				
        			}
        		}
                sfile_obj.close();
    			if(flag!=0)
    			{
    			 goto phoneagain;
    		    }
			//+++++++++++++++++++++
			
			
			
			
			
			rollagain:
			cout<<"Enter roll number :";
			cin>>roll;
			
			//+++++++++++++++++++++
			//	ifstream sfile_obj;
        	//	Student sobj;
        		int rflag=0;
        		sfile_obj.open("NHw.txt",ios::in);
                sfile_obj.seekg(0,ios::beg);
                 while(!(sfile_obj.eof()))
    			{
        			sfile_obj.read((char*)&sobj, sizeof(sobj));
        			
        			if(sobj.roll==roll)
        			{
        				cout<<"Duplicate roll number....";
        				rflag=1;
 						break;       				
        			}
        		}
                sfile_obj.close();
    			if(rflag!=0)
    			{
    			 goto rollagain;
    		    }
			//+++++++++++++++++++++
			
			
			
			
     	}
     	void disp()
     	{
     		cout<<"Name"<<"        "<<"Phone"<<"     "<<"Roll"<<"      "<<"Branch"<<"      "<<"SEM"<<endl;
     		cout<<name<<"          "<<phone<<"    "<<roll<<"      "<<branch<<"        "<<sem<<endl;
        }
       
	    void srch(char *sname)
        {
        		ifstream sfile_obj;
        		Student sobj;
        		int flag=0;
        		sfile_obj.open("NHw.txt",ios::in);
        		if(sfile_obj.eof() || sfile_obj == NULL)
                {
                	cout<<"There are no records available....";
                }
                else
                {  
                sfile_obj.seekg(0,ios::beg);
                 while(!(sfile_obj.eof()))
    			{
        			sfile_obj.read((char*)&sobj, sizeof(sobj));
        			
        			if(strcmp(sobj.name,sname)==0)
        			{	cout<<"Record found";
        				if(sfile_obj.eof()!=1)
        				{
					
        				cout<<endl<<sobj.name<<"          "<<sobj.phone<<"    "<<sobj.roll<<endl<<endl<<endl;
        				flag=1;}
 						//break;       				
        			}
        		}
                sfile_obj.close();
    			if(flag==0)
    			{
    				cout<<"RECORD NOT FOUND!"<<endl<<endl;
    		    }
				}
        }
		void semsrch(int sem)
        {
        		ifstream sfile_obj;
        		Student sobj;
        		int flag=0;
        		sfile_obj.open("NHw.txt",ios::in);
        		if(sfile_obj.eof() || sfile_obj == NULL)
                {
                	cout<<"There are no records available....";
                }
                else
                {  
                sfile_obj.seekg(0,ios::beg);
                 while(!(sfile_obj.eof()))
    			{
        			sfile_obj.read((char*)&sobj, sizeof(sobj));
        			if(!sfile_obj.eof())
        			if(sobj.sem==sem)
        			{
        				cout<<endl<<sobj.name<<"          "<<sobj.phone<<"    "<<sobj.roll<<"       "<<sobj.branch<<"       "<<sobj.sem<<endl<<endl;
        				flag=1;
        				
        			}
        		}
                sfile_obj.close();
    			if(flag==0)
    			{
    				cout<<"RECORD NOT FOUND!"<<endl<<endl;
    		    }
    		}
        } 
        void bsrch(char *sbranch)
        {
        		ifstream sfile_obj;
        		Student sobj;
        		int flag=0;
        		sfile_obj.open("NHw.txt",ios::in);
        		
        		
        		if(sfile_obj.eof() || sfile_obj == NULL)
                {
                	cout<<"There are no records available....";
                }
                else
                {  
                sfile_obj.seekg(0,ios::beg);
                 while(!(sfile_obj.eof()))
    			{
        			sfile_obj.read((char*)&sobj, sizeof(sobj));
        			if(!sfile_obj.eof())
        			if(strcmp(sobj.branch,sbranch)==0)
        			{
        				cout<<endl<<sobj.name<<"          "<<sobj.phone<<"    "<<sobj.roll<<"       "<<sobj.branch<<"      "<<sobj.sem<<endl<<endl;
        				flag=1;
        				
        			}
        		}
                sfile_obj.close();
    			if(flag==0)
    			{
    				cout<<"RECORD NOT FOUND!"<<endl<<endl;
    		    }
		}
        }
        void srch(int roll)
        {
        	
        		ifstream sfile_obj;
        		Student sobj;
        		int flag=0;
        		sfile_obj.open("NHw.txt",ios::in);
               
                if(sfile_obj.eof() || sfile_obj == NULL)
                {
                	cout<<"There are no records available....";
                }
                else
                {     
                 sfile_obj.seekg(0,ios::beg);
                
                 while(!(sfile_obj.eof()))
    			{
        			sfile_obj.read((char*)&sobj, sizeof(sobj));
        			
        			if(sobj.roll==roll)
        			{
        				if(sfile_obj.eof()!=1){
						
        				cout<<endl<<"================================================================"<<endl;
        				cout<<"Record found";
        				cout<<endl<<sobj.name<<"          "<<sobj.phone<<"    "<<sobj.roll<<"        "<<sobj.branch<<"       "<<sobj.sem<<endl<<endl;
        				cout<<endl<<"================================================================"<<endl;
        				flag=1;
        			}
 			}
        		}
                sfile_obj.close();
    			if(flag==0)
    			{
    				cout<<"RECORD NOT FOUND!"<<endl<<endl;
    		    }
    		    
    		}
        }
        
        int calctotstuds()
        {
        	
        	int temp=0;
        	
        		ifstream sfile_obj;
        		Student sobj;
        		int flag=0;
        		sfile_obj.open("NHw.txt",ios::in);
                sfile_obj.seekg(0,ios::beg);
                 while(sfile_obj.read((char*)&sobj, sizeof(sobj)))
    			{
    				temp++;
        		}
                sfile_obj.close();
    			return temp;
    		    
        }
        
        
                	
        friend void totalstuds(Student s);
        
        
};



void totalstuds(Student s)
{
	cout<<endl<<"================================================================"<<endl;
	cout<<"Total number of students is : "<<s.calctotstuds()<<endl<<endl;
	cout<<endl<<"================================================================"<<endl;
	
}


//===========================================================================

class GradStud:public Student
{
	private:
		char year_passed[10];
		float cgpa;
	public:
		void LibStatus()
		{
			char libname[50],libstatus[5];
			cout<<"For Grad Student:"<<endl;
			ttt:
			cout<<"Enter student Name:";
			cin>>libname;
			
			//0000000000000000000000000000000000000000000000000
			
			ifstream sfile_obj;
        		Student sobj;
        		int flag=0;
        		sfile_obj.open("NHwg.txt",ios::in);
                sfile_obj.seekg(0,ios::beg);
                
				
				
				while(!(sfile_obj.eof()))
    			{
        			sfile_obj.read((char*)&sobj, sizeof(sobj));
    			
    			//cout<<strcmp(sobj.name,libname)<<endl;
    			if(strcmp(sobj.name,libname)==0)
    			{
    				flag = 1;
    			break;		  			
        		}
        	}
        			//cout<<"flag = "<<flag;
        	    sfile_obj.close();
    			if(flag!=1)
    			{
    				cout<<"Enter valid student name...."<<endl;
    			 goto ttt;
    		    }
    		    
			//0000000000000000000000000000000000000000000000000
			
			
			
			
			
				
			
			
			cout<<"Enter Library Membership Status (Yes / No )";
			cin>>libstatus;
		}
	void accept()
		{
			cout<<endl<<"================================================================"<<endl;
        Student::accept();
        cout<<"Enter year passed out : ";
        cin>> year_passed;
        cout<<"Emter C G P A : ";
        cin>>cgpa;	
		cout<<endl<<"================================================================"<<endl;
				
     	}
     	void disp()
     	{
     		
		
     		Student::disp();
     		cout<<endl<<"Year passed out : "<<year_passed;
     		cout<<endl<<"CGPA : "<<cgpa<<endl<<endl;
     		
     		
        }
   };

//===========================================================================
 


int main()
{
	
	int ch;
		char a='y';
		int temp=0;
	ofstream file_obj,gfile_obj;	
	ifstream file_objr,gfile_objr;
	Student sobj;
    GradStud gobj;
    
    Student *libstatus;
    
    
    
    
 while(true)
 {
 	cout<<endl<<"=/=/=/=/=/=/=/=/=/=/=/WELCOME/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/"<<endl;
	cout<<"NEW HORIZON COLLEGE, STUDENT MANAGEMENT SYSTEM verson 1.0"<<endl<<"1.Enter new student records"<<endl<<"2.Display Records"<<endl<<"3.Search by name"<<endl<<"4.Search by roll number"<<endl<<"5.Number of total students"<<endl<<"6.Enter Grad Students Records"<<endl<<"7. Display Grad Stud Records"<<endl<<"8.Enter Current Student Library Status"<<endl<<"9.Enter Grad Student Library Status"<<endl<<"10.List Records based on Branch"<<endl<<"11.List Records based on semester"<<endl<<"12.Exit"<<endl;
	cout<<"Enter your choice...    :";
	cin >> ch;
	
	switch(ch)
	{
		case 1: 
		
         a='y';
         while(a!='n' && a !='N')
	 { 
	     file_obj.open("NHw.txt",ios::app);

	    sobj.accept();
       file_obj.write((char*)&sobj, sizeof(sobj));
        
       file_obj.close();
       fflush(stdin);
      
	   cout<<"Press any key to continue...(press 'N' to exit)?";       
       cin>>a;
      fflush(stdin);
      file_obj.close();
     }
	break;
	
	case 2:
	
	    file_objr.open("NHw.txt",ios::in);
	           file_objr.seekg(0,ios::beg);
	    
	    
	
    
    while( file_objr.read((char*)&sobj, sizeof(sobj)))
    {
    
        sobj.disp();    
	
	    
    }

        file_objr.close();
    
  	break;
	case 3:
		char sname[50];
		cout<<"Enter name of the student to search: ";
		cin>>sname;
		sobj.srch(sname);
		break;
	case 4:
		int r;
		cout<<"Enter roll number of the student to search: ";
		cin>>r;
		sobj.srch(r);
		break;
	case 5:
		totalstuds(sobj);
	    break;	
	case 6:
		a='y';
		 while(a!='n' && a!='N')
	 { 	gfile_obj.open("NHwg.txt",ios::app);

	    gobj.accept();
	    
	    	    
	    
       gfile_obj.write((char*)&gobj, sizeof(gobj));
        
       gfile_obj.close();
       fflush(stdin);
	   cout<<"Press any key to continue...(press 'N' to exit)?";       
	   cin>>a;
      fflush(stdin);
      
      gfile_obj.close();
     }
      break;
      case 7:
	  
	  
      	gfile_objr.open("NHwg.txt",ios::in);
        gfile_objr.seekg(0,ios::beg);
        
        
    
    while(gfile_objr.read((char*)&gobj, sizeof(gobj)))
    {
        temp++;
        gobj.disp();        
    }
    if (temp==0)
    cout<<"FILE EMPTY! Please do data entry first."<<endl;
    gfile_objr.close();
      	
      	
      	break;
    case 8:
    	libstatus = new Student();
	    libstatus->LibStatus();
    	break;
    case 9:
    	libstatus = new GradStud();
    	libstatus->LibStatus();
    	break;
    case 10:
    	char b[25];
    	cout<<"Enter branch :";
    	cin>>b;
    	sobj.bsrch(b);
    	break;
    case 11:
    	int sem;
    	
    	cout<<"Enter semester :";
    	cin>>sem;
    	if(sem==1 ||sem==2 ||sem==3 ||sem==4 ||sem==5 ||sem==6||sem==7||sem==8)
       	sobj.semsrch(sem);
       	else
       	cout<<"Invalid data entered!";
     
       	break;
	case 12:
		exit(1);
		break;
}
}
	return 0;
}

	
