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
		cout<<"subjects name: \n";
		cin>>sub1name;
		cin>>sub2name;
		cin>>sub3name;
		cin>>sub4name;
		cin>>sub5name;
		cout<<"\n"<<"subjects Marks: \n";
		cin>>sub1M;
		cin>>sub2M;
		cin>>sub3M;
		cin>>sub4M;
		cin>>sub5M;
	}
	void marks(void)
	{
		cout<<sub1name<<": "<<sub1M<<endl;
		cout<<sub2name<<": "<<sub2M<<endl;
		cout<<sub3name<<": "<<sub3M<<endl;
		cout<<sub4name<<": "<<sub4M<<endl;
		cout<<sub5name<<": "<<sub5M<<endl;
	}
	void singlemarks(void)
	{
		char subname[10];
		cout<<"Enter the subject name: ";
		cin>>subname;
		if(strcmp(subname,))
	}
};

//-----------------class for faculty name ----------------------------------------


//--------------class for store a students details--------------------------------

class Student
{
	int roll;
	char name[30];
	char course[10];
	char admdate[10];
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
		sublist.getmarks();//get marks in all subjects
	}
	char*returname(void){return name;}
	void display(void)
	{
		cout<<"name: "<<name<<endl;
		cout<<"Roll No: "<<roll<<endl;
		cout<<"Course name: "<<course<<endl;
		cout<<"Admisson date: "<<admdate<<endl;
	}
	int returnroll(void){return roll;}
	void showmarks(void)
	{
		sublist.marks();
	}
	void submarks(void)
	{
		sublist.singlemarks();
	}
};

//--------------------------class to store the student list details---------------------------------------

class studentlist
{
	Student list[10];//to make a student list 
	int count;//no of student has taken addmisson
public:
	studentlist()
	{
		count=0;
	}
	void preparelist(void)
	{
		Student t;
		t.getvalue();
		list[count]=t;
		count++;
	}
	void printname(void)
	{
		int i;
		for(i=0;i<count;i++)
		{
			cout<<i+1<<". ";
			cout<<list[i].returname();
			cout<<endl;
		}
	}
	void marksheet(void)
	{
		int i,rollno;
		cout<<"Roll of the student: ";
		cin>>rollno;
		for(i=0;i<count;i++)
		{
			if(rollno==list[i].returnroll())
			{
				list[i].showmarks();
				break;
			}
		}
	}
	void showdetails(void)
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
	void showsubmarks(void)
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
		cout<<"1.Want to add details of a student\n2.Show details of a student\n3.Marksheet of a student\n4.show marks in a subject\n4.EXIT\n:";
		cin>>opt;
		switch(opt)
		{
			case 1:
				c.preparelist();
				break;
			case 2:
				cout<<"\nNAME LIST OF THE STUDENTS\n";
				cout<<"-------------------------------\n";
				c.printname();
				c.showdetails();
				break;
			case 3:
				cout<<"\nMARKSHEET\n";
				cout<<"---------------------------------\n";
				c.printname();
				c.marksheet();
				break;
			case 4:
				c.showsubmarks();
				exit(0);
			default:
				cout<<"This is Not a Valid option";
				break;
		}
	}
}