

//======================================programe to make a student marksheet and show his/her details=============================

#include<iostream>
#include<cstring>

using namespace std;

//-------------------------class for store the valu of the subjects-----------

class subjects
{
	char subname[6][10];
	int subM[6];
public:
	void getmarks(void)
	{
		int i;
		cout<<"subjects name: \n";
		for(i=1;i<=5;i++)
		{
			cin>>subname[i];
		}		
		cout<<"\n"<<"subjects Marks: \n";
		for(i=1;i<=5;i++)
		{
			cin>>subM[i];
		}
		
	}
	void marks(void)
	{
		int i;
		for(i=1;i<=5;i++)
		{
			cout<<subname[i]<<": "<<subM[i]<<endl;
		}
	}
	void singlemarks(void)
	{
		char subn[10];
		int i;
		cout<<"Enter the subject name: ";
		cin>>subn;
		for(i=1;i<=5;i++)
		{
			if(strcmp(subn,subname[i])==0)
			{
				cout<<subname[i]<<": "<<subM[i]<<endl;
			}
		}
	}
	void update(void)
	{
		char subn[10];
		int i;
		int submark;
		cout<<"Enter the subject name: ";
		cin>>subn;
		cout<<"Enter the new marks : ";
		cin>>submark;
		for(i=1;i<=5;i++)
		{
			if(strcmp(subn,subname[i])==0)
			{
				subM[i]=submark;
			}
		}

	}
};

//--------------class for store a students details--------------------------------

class Student
{
	int roll;
	char name[30];
	char course[10];
	char admdate[10];
	char faculty[10];
	subjects sublist;
public:
	void getvalue(void)
	{
		cout<<"Enter the Roll No: ";
		cin>>roll;
		cout<<"Enter the name of the student: ";
		scanf(" %[^\n]%*c", name);
		cout<<"Enter the course name: ";
		cin>>course;
		cout<<"Enter the addmisson Date: ";
		cin>>admdate;
		cout<<"Enter the Faculty Name: ";
		cin>>faculty;
		sublist.getmarks();//get marks in all subjects
	}
	char*returname(void){return name;}
	void display(void)
	{
		cout<<"name: "<<name<<endl;
		cout<<"Roll No: "<<roll<<endl;
		cout<<"Course name: "<<course<<endl;
		cout<<"Faculty: "<<faculty<<endl;
		cout<<"Admisson date: "<<admdate<<endl;
	}
	int returnroll(void){return roll;}
	char*returnfac(void){return faculty;}
	void showmarks(void)
	{
		sublist.marks();
	}
	void submarks(void)
	{
		sublist.singlemarks();
	}
	void update_submarks(void)
	{
		sublist.update();
		while(1)
		{
			int opt;
			cout<<"Want to upadate another subject marks:\n1.yes\n2.NO\n:";
			cin>>opt;
			if(opt==1){sublist.update();}
			else if(opt==2){break;}
			else{cout<<"please give a valid option:\n";}
		}
	}
};

//--------------------------class to store the student list details---------------------------------------

class studentlist
{
	Student list[10];//to make a student list 
	int count;//no of student has taken addmisson
public:
	studentlist()//constructor
	{
		count=0;
	}
	void preparelist(void)//to add another student's details
	{
		Student t;
		t.getvalue();
		list[count]=t;
		count++;
	}
	void printname(void)//to print all student's name and roll
	{
		int i;
		cout<<"NAME"<<"\t   "<<"ROLL NO"<<endl;
		cout<<"-----------------------------------------------------------\n";
		for(i=0;i<=count;i++)
		{
			cout<<i+1<<". ";
			cout<<list[i].returname()<<"\t"<<list[i].returnroll()<<endl;
			cout<<endl;
		}
	}
	void marksheet(void)//to show the marksheet a student
	{
		int i,rollno;
		cout<<"Roll of the student: ";
		cin>>rollno;
		for(i=0;i<=count;i++)
		{
			if(rollno==list[i].returnroll())
			{
				list[i].showmarks();
				break;
			}
		}
	}
	void showdetails(void)//to show details of a student
	{
		int i;
		int rollno;
		cout<<"ROLL NO of the student: ";
		cin>>rollno;
		for(i=0;i<=count;i++)
		{
			if(rollno==list[i].returnroll())
			{
				list[i].display();
				break;
			}
		}
	}
	void showsubmarks(void)//to show marks of particular subject
	{
		int i;
		int rollno;
		cout<<"ROLL NO of the student: ";
		cin>>rollno;
		for(i=0;i<=count;i++)
		{
			if(rollno==list[i].returnroll())
			{
				list[i].submarks();
				break;
			}
		}
	}
	void showfacultydetails(void)//to show the  list of student of a faculty 
	{
		int i;
		char fac[10];
		cout<<"Enter the Faculty name:";
		cin>>fac;
		cout<<"\n----------------------------------------------------------\n";
		cout<<"NAME"<<"\t   "<<"  ROLL NO"<<endl;
		cout<<"-----------------------------------------------------------\n";
		for(i=0;i<=count;i++)
		{
			if(strcmp(fac,list[i].returnfac())==0)
			{
				cout<<list[i].returname()<<"\t"<<list[i].returnroll()<<endl;
			}
		}
	}
	void updatemarks(void)//to update the marks of a particular
	{
		int i;
		int rollno;
		cout<<"ROLL NO of the student: ";
		cin>>rollno;
		for(i=0;i<=count;i++)
		{
			if(rollno==list[i].returnroll())
			{
				list[i].update_submarks();
				break;
			}
		}

	}
};


//---------------main function --------------------------------

int main(void)
{
	studentlist c;
	while(1)
	{
		int opt;
		cout<<"\n--------------------------------------------------"<<endl;
		cout<<"chose any option"<<endl;
		cout<<"--------------------------------------------------"<<endl;
		cout<<"1.Want to add details of a student\n2.Show details of a student\n3.Marksheet of a student\n4.show marks in a subject\n5.show the student list\n6.show the list of a Faculty\n7.update the marks of a subject\n8.EXIT\n:";
		cin>>opt;
		switch(opt)
		{
			case 1:
				c.preparelist();
				break;
			case 2:
				c.showdetails();
				break;
			case 3:
				cout<<"\nMARKSHEET\n";
				cout<<"---------------------------------\n";
				c.marksheet();
				break;
			case 4:
				c.showsubmarks();
				break;
			case 5:
				cout<<"\nNAME AND ROLL OF ALL THE STUDENTS\n";
				cout<<"-------------------------------------------------\n";
				c.printname();
				break;
			case 6:
				c.showfacultydetails();
				break;
			case 7:
				c.updatemarks();
				break;
			case 8:
				exit(0);
			default:
				cout<<"This is Not a Valid option";
				break;
		}
	}
	return 0;
}
