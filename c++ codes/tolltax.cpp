#include<iostream>
#include<cstring>

using namespace std;
//template <class T>
struct file
{
	char*name=new char [20];
	int blance;
};
class TOLLTAX
{
	int tollamount,numcar;
	int count1,count2,count3,count;
	struct file a[10];

public:
	TOLLTAX()
	{
		tollamount=0;
		numcar=0;
		count1=0;
		count2=0;
		count3=0;
		count=6;
		a[1].name="sadrul";
		a[1].blance=1000;
		a[2].name="sahil";
		a[2].blance=1000;
		a[3].name="irin";
		a[3].blance=1000;
		a[4].name="sourav";
		a[4].blance=1000;
		a[5].name="avishek";
		a[5].blance=1000;
	}
	int check_name(char*c)
	{
		int i;
		for(i=0;i<=count;i++)
		{
			if(strcmp(c,a[i].name)==0)
			{
				return i;
			}
		}
		return -1;

	}
	void recive_type(int t)
	{
		int rt;
		cout<<"Enter The Recive Type:(1.prepaid/2.instance)";
		cin>>rt;
		if(rt==1)
		{
			char*nam;
			nam=new char [20];
			cout<<"Enter the name:";
			cin>>nam;
			int n=check_name(nam);
			a[n].blance-=t;
		}

	}
	void add_account(void)
	{
		char*nm;
		nm=new char [10];
		cout<<"Enter the name:";
		cin>>a[count].name;
		cout<<"Enter the amount:";
		cin>>a[count].blance;
		count++;
	}
	void displayaccdet(void)
	{
		cout<<"\n========================================================\n";
		cout<<"account name\tblance\n";
		cout<<"\n========================================================\n";
		for(int i=1;i<count;i++)
		{
			cout<<a[i].name<<"\t\t"<<a[i].blance<<endl;
		}
	}
	void recevingtoll(void)
	{
		int t;
		int cartype;
		cout<<"Enter the Amount of Tax\n=>";
		cin>>t;
		cout<<"Enter the Car type(2/3/4......wheelers)\n=>";
		cin>>cartype;
		recive_type(t);
		check_type(cartype);
		tollamount+=t;
		numcar++;
	}
	void check_type(int c)
	{
		if(c==2){count1++;}
		else if(c==3){count2++;}
		else {count3++;}
	}
	void diplaycarnum(void)
	{
		cout<<"The Number of car cross The Bridge is:"<<numcar<<endl;
	}
	void diplaytollamount(void)
	{
		cout<<"The Number of Amount Collected is:"<<tollamount<<endl;
	}
	void diplaycartypes(void)
	{
		cout<<"\n========================================================\n";
		cout<<"2 wheelers=>"<<count1<<endl<<"3 wheelers=>"<<count2<<endl<<"4 wheelers=>"<<count3<<endl;
		cout<<"========================================================\n";
	}
};

int main(void)
{
	TOLLTAX a;
	int opt;
	while(1)
	{
		cout<<"----------------------------------------------------------------\n";
		cout<<"Chose the Option\n";
		cout<<"-----------------------------------------------------------------\n";
		cout<<"1.Recving Toll\n2.Display The Number of Cars That Cross The Bridge\n3.Display The Amount of Toll Collected\n4.Display The tyes of cars Cross the Bridge\n5.Display all Account details\n6.Add Account\n7.EXIT\n=>";
		cin>>opt;
		switch(opt)
		{
			case 1:
				a.recevingtoll();
				break;
			case 2:
				a.diplaycarnum();
				break;
			case 3:
				a.diplaytollamount();
				break;
			case 4:
				a.diplaycartypes();
				break;
			case 5:
				a.displayaccdet();
				break;
			case 6:
				a.add_account();
				break;
			case 7:
				exit(0);
			default:
				cout<<"Plase Chose A valid Option";
				break;
		}
	}
}