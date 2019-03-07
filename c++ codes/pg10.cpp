#include<iostream>
#include<cstring>

using namespace std;

class Blance
{
protected:
	char*acnt_num;
	int blance;
	int month,year,day;
	int type;
public:
	void get(void)
	{
		acnt_num=new char[12];
		cout<<"Enter the Acount Number: ";
		cin>>acnt_num;
		cout<<"Enter the Amount: ";
		cin>>blance;
		time_t t = time(NULL);
		tm* timePtr = localtime(&t);
		day=(int)timePtr->tm_mday;
		month=(int)(timePtr->tm_mon)+1;
		year=(int)(timePtr->tm_year)+1900;
	}
	void display(void)
	{
		cout<<"\n===================================================\n";
		cout<<"\nAccount Number: "<<acnt_num<<endl;
		cout<<"Blance: "<<blance<<endl;
		cout<<"Last Update: "<<day<<":"<<month<<":"<<year<<endl;
	}
	char*returnactno(void){return acnt_num;}
};

class saving:public Blance
{
public:
	void timeupdate(void)
	{
		time_t t = time(NULL);
		tm* timePtr = localtime(&t);
		day=(int)timePtr->tm_mday;
		month=(int)(timePtr->tm_mon)+1;
		year=(int)(timePtr->tm_year)+1900;
	}
	void transation(void)
	{
		int type,amount;
		cout<<"Enter the Transaction Type:(1.withdrawal/2.deposit)\n=>";
		cin>>type;
		cout<<"Enter the Amount: ";
		cin>>amount;
		if(amount+500>blance && type==1){cout<<"Transaction Faild";}
		else
		{
			if(type==1){blance-=amount;}
			else {blance+=amount;}
			timeupdate();
		}
		
	}
	void display(void)
	{
		Blance::display();
		cout<<"Account Type: Saving Account"<<endl;
		cout<<"\n====================================================\n";
	}
	int returnblance(void){return blance;}
};
class current:public Blance
{
public:
	/*int check_validity(int amount)
	{
		if(amount>(blance+2000) && type==1){return 0;}
		else return 1;
	}*/
	void timeupdate(void)
	{
		time_t t = time(NULL);
		tm* timePtr = localtime(&t);
		day=(int)timePtr->tm_mday;
		month=(int)(timePtr->tm_mon)+1;
		year=(int)(timePtr->tm_year)+1900;
	}
	void transation(void)
	{
		int type,amount;
		cout<<"Enter the Transaction Type:(1.withdrawal/2.deposit)\n=>";
		cin>>type;
		cout<<"Enter the Amount: ";
		cin>>amount;
		if(amount>(blance+20000) && type==1)
		{
			cout<<"Transaction Faild";
		}
		else
		{
			if(type==1){blance-=amount;}
			else {blance+=amount;}
			timeupdate();
		}
	}
	void display(void)
	{
		Blance::display();
		cout<<"Account Type: Current Account";
		cout<<"\n====================================================\n";
	}
};

class blancelist
{
	current clist[6];
	saving slist[6];
	int count1,count2;
public:
	blancelist()
	{
		count1=0;
		count2=0;
	}
	int check_id(char*c)
	{
		int i;
		for(i=0;i<=count1;i++)
		{
			if(strcmp(c,clist[i].returnactno())==0)
			{
				return i;
			}
		}
		for(i=0;i<=count2;i++)
		{
			if(strcmp(c,slist[i].returnactno())==0)
			{
				return i;
			}
		}
		return -1;

	}
	int check(int n,char*c)
	{
		if(strcmp(c,clist[n].returnactno())==0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	void cprepaird(void)
	{
		current t;
		t.get();
		if(check_id(t.returnactno())>=0)
		{
			cout<<"The Account No can't be same.";
		}
		else
		{
			clist[count1]=t;
			count1++;
		}
	}
	void sprepaird(void)
	{
		saving t;
		t.get();
		if(check_id(t.returnactno())>=0)
		{
			cout<<"The Account No can't be same.";
		}
		else if(t.returnblance()>500)
		{
			slist[count2]=t;
			count2++;
		}
		else
		{
			cout<<"Amount cant be less then 500";
		}
	}
	void update(void)
	{
		char*acc;
		acc=new char [11];
		cout<<"Enter The Account No\n=>";
		cin>>acc;
		if(check_id(acc)>=0)
		{
			int n=check_id(acc);
			if(check(n,acc)==0)
			{
				slist[n].transation();
			}
			else
			{
				clist[n].transation();
			}
		}
		else
		{
			cout<<"Plase Enter A valid Account No.";
		}

	}
	void print(void)
	{
		char*acc;
		acc=new char [11];
		cout<<"Enter The Account No\n=>";
		cin>>acc;
		if(check_id(acc)>=0)
		{
			int n=check_id(acc);
			if(check(n,acc)==0)
			{
				slist[n].display();
			}
			else
			{
				clist[n].display();
			}
		}
		else
		{
			cout<<"Plase Enter A valid Account No.";
		}

	}
};
int main(void)
{
	blancelist b;
	int opt;
	while(1)
	{
		cout<<"\n--------------------------------------------------------\n";
		cout<<"Chose An Option";
		cout<<"\n---------------------------------------------------------\n";
		cout<<"1.Enter New saving Account\n2.Enter New Current Account\n3.Make a Transaction\n4.Display Details of an Account\n5.EXIT\n=>";
		cin>>opt;
		switch(opt)
		{
			case 1:
				b.sprepaird();
				break;
			case 2:
				b.cprepaird();
				break;
			case 3:
				b.update();
				break;
			case 4:
				b.print();
				break;
			case 5:
				exit(0);
			default:
				cout<<"Enter A Valid Option";
				break;
		}
	}
}