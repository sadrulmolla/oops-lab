#include<iostream>
#include<cstring>

using namespace std;

//--------------------class for the item --------------------------

class item
{
	char icode[10];
	char name[30];
	float price;
	int qnty;
public:
	void getitem(void)
	{
		cout<<"Enter the name of the item: ";
		cin>>name;
		cout<<"Enter the item code of "<<name<<": ";
		cin>>icode;
		cout<<"Enter the rate of "<<name<<": ";
		cin>>price;
		cout<<"Enter the quantity of "<<name<<": ";
		cin>>qnty;
	}
	char*returname(void){return name;}
	char*returnicode(void){return icode;}
	void setprice(float x)
	{
		price=price+x;
	}
	void setqnty(float q)
	{
		qnty=qnty+q;
	}
	void display(void)
	{
		cout<<"\n";
		cout<<"code: "<<icode<<endl;
		cout<<"price: "<<price<<endl;
		cout<<"quantity: "<<qnty<<endl;
	}
	void showprice(void)
	{
		cout<<"\nprice= "<<price<<"\n";
	}
	void itemissu(int q)
	{
		qnty=qnty-q;
		if(qnty>=0)
		{
			printf("this order is valid");
		}
		else
		{
			printf("The order is not valid");
		}
	}
};//end of the item class

//----------------new class for iteam list----------------------------

class itemlist
{
	int count;//no of item
	item list[10];
public:
	itemlist()
	{
		count=0;
	}
	int find_icode(char c[])
	{
		int i;
		for(i=0;i<=count;i++)
		{
			if(strcmp(c,list[i].returnicode())==0)
			{
				return 0;
			}
		}
		return 1;
	}
	void prepare_list()
	{
		item t;
		t.getitem();
		if(find_icode(t.returnicode())==0)
		{
			printf("\nTHIS IS A DUPLICATE\n");
		}
		else
		{
			list[count]=t;
			count++;
		}
	}
	void changeprice(void)
	{
		float x;
		int i;
		char nam[30];
		cout<<"\nEnter  the item name:";
		cin>>nam;
		for(i=0;i<=count;i++)
		{
			if(strcmp(nam,list[i].returname())==0)
			{
				cout<<"Enter the price change "<<list[i].returname();
				cin>>x;
				list[i].setprice(x);
				break;
			}
		}	
	}
	void reciveitem(void)
	{
		float q;
		int i;
		char nam[30];
		cout<<"\nEnter  the item name:";
		cin>>nam;
		cout<<"Enter the qnty recived:";
		cin>>q;
		for(i=0;i<=count;i++)
		{
			if(strcmp(nam,list[i].returname())==0)
			{
				list[i].setqnty(q);
				break;
			}
		}
	}
	void details(void)
	{
		int i;
		char nam[30];
		cout<<"\nEnter  the item name: ";
		cin>>nam;
		for(i=0;i<=count;i++)
		{
			if(strcmp(nam,list[i].returname())==0)
			{
				list[i].display();
				break;
			}
		}
	}
	void priceofitem(void)
	{
		int i;
		char  nam[30];
		cout<<"\nEnter the item name: ";
		cin>>nam;
		for(i=0;i<=count;i++)
		{
			if(strcmp(nam,list[i].returname())==0)
			{
				list[i].showprice();
				break;
			}
		}
	}
	void issuitem(void)
	{
		int i,q;
		char  nam[30];
		cout<<"\nEnter the item name: ";
		cin>>nam;
		cout<<"Enter the quantity of issue: ";
		cin>>q;
		for(i=0;i<=count;i++)
		{
			if(strcmp(nam,list[i].returname())==0)
			{
				list[i].itemissu(q);
				break;
			}
		}
	}
};

//--------------------------------main function start------------------------------------

int main(void)
{
	itemlist c;
	c.prepare_list();
	while(1)
	{
		int opt;
		cout<<"\nchose option:\n1.Want to add another item\n2.Change the price of and item\n3.recive an alreay exist item\n4.issue an item\n5.check the price of an item\n6.details of an item\n7.EXIT\n:";
		cin>>opt;
		switch(opt)
		{
			case 1:
				c.prepare_list();
				break;
			case 2:
				c.changeprice();
				break;
			case 3:
				c.reciveitem();
				break;
			case 4:
				c.issuitem();
				break;
			case 5:
				c.priceofitem();
				break;
			case 6:
				c.details();
				break;
			case 7:
				exit(0);
			default:
				printf("This is not a valid option");

		}
	}
}