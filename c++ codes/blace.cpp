#include<iostream>
#include<cstring>


using namespace std;
class TRANSACTION
{
	char*acc_num;
	int amount;
	int month,year,day;
	int type;
public:
	void getdata(void)
	{
		acc_num=new char[12];
		cout<<"Enter the Acount Number: ";
		cin>>acc_num;
		cout<<"Enter the Transaction Type:(1.withdrawal/2.deposit)\n=>";
		cin>>type;
		cout<<"Enter the Amount: ";
		cin>>amount;
	}
	int return_day(void){return day;}
	int return_month(void){return month;}
	int return_year(void){return year;}
	int return_amount(void){return amount;}
	char*return_accnum(void){return acc_num;}
	int return_type(void){return type;}

	void refres(void)
	{
		time_t t = time(NULL);
		tm* timePtr = localtime(&t);
		day=(int)timePtr->tm_mday;
		month=(int)(timePtr->tm_mon)+1;
		year=(int)(timePtr->tm_year)+1900;
	}

};

class BLANCE
{
	char*acnt_num;
	int blance;
	int month,year,day;
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
	int return_blance(void){return blance;}
	void display(void)
	{
		cout<<"\n===================================================\n";
		cout<<"\nAccount Number: "<<acnt_num<<endl;
		cout<<"Blance: "<<blance<<endl;
		cout<<"Last Update: "<<day<<":"<<month<<":"<<year<<endl;
		cout<<"\n====================================================\n";
	}
	char*returnactno(void){return acnt_num;}

	void updatedata(TRANSACTION tran)
	{
		if(tran.return_type()==1){blance=blance-tran.return_amount();}
		else {blance=blance+tran.return_amount();}
		day=tran.return_day();
		month=tran.return_month();
		year=tran.return_year();
	}
};

class blance_list
{
	BLANCE list[10];
	int count;
public:
	blance_list()
	{
		count=0;
	}
	int check_id(char*c)
	{
		int i;
		for(i=0;i<=count;i++)
		{
			if(strcmp(c,list[i].returnactno())==0)
			{
				return i;
			}
		}
		return -1;
	}
	void prepaird(void)
	{
		BLANCE t;
		t.get();
		if(check_id(t.returnactno())>=0)
		{
			cout<<"The Account No can't be same.";
		}
		else
		{
			list[count]=t;
			count++;
		}
	}
	void update(void)
	{
		TRANSACTION tran;
		tran.getdata();
		if(check_id(tran.return_accnum())>=0)
		{
			int n=check_id(tran.return_accnum());
			if((list[n].return_blance()<tran.return_amount())&& tran.return_type()==1)
			{
				cout<<"Transaction Faild.";
			}
			else
			{
				tran.refres();
				list[n].updatedata(tran);
			}
		}
		else
		{
			cout<<"Plase Enter A valid Account No.";
		}

	}
	void print(void)
	{
		char*act;
		act=new char [12];
		cout<<"Enter The Account Number: ";
		cin>>act;
		if(check_id(act)>=0)
		{
			int n=check_id(act);
			list[n].display();
		}
		else
		{
			cout<<"Plase Enter A valid Account No.";
		}
	}

};

int main(void)
{
	blance_list b;
	int opt;
	while(1)
	{
		cout<<"\n--------------------------------------------------------\n";
		cout<<"Chose An Option";
		cout<<"\n---------------------------------------------------------\n";
		cout<<"1.Enter New Details\n2.Make a Transaction\n3.Display Details of an Account\n4.EXIT\n=>";
		cin>>opt;
		switch(opt)
		{
			case 1:
				b.prepaird();
				break;
			case 2:
				b.update();
				break;
			case 3:
				b.print();
				break;
			case 4:
				exit(0);
			default:
				cout<<"Plase Enter A valid Option\n";


		}
	}
}

