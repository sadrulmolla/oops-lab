#include<iostream>
#include<cstring>


using namespace std;

//----------------------------------------class to take the list of iteam------------------------------------

class iteamlist
{
private:
	char iteamcode[8],name[30];
	float rate;
	int quantity,count;
	static int count;
public:
	iteamlist()
	{
		count=0;
	}
	void getvalue(void)
	{
		cout<<"Enter the name of the item";
		cin>>name;
		cout<<"Enter the item code of "<<name;
		cin>>iteamcode;
		cout<<"Enter the rate of "<<name;
		cin>>rate;
		cout<<"Enter the quantity of "<<name;
		cin>>quantity;
		count++;
	}
	bool uniquenesscode(string iteamcode,int count)
	{
	}
	void changetherate(void)
	{
		float x;
		cout<<"Enter the new rate of "<<name;
		cin>>x;
		rate=x;
	}
	string returnname(void){return name;}
	void reciveditem(void)
	{
		int y;
		cout<<"How much quantity recived?\n";
		cin>>y;
		quantity=quantity+y;

	}
	void issueitem(void)
	{
		int x;
		if(quantity<=0)
		{
			cout<<"This iteam is not avilable";
		}
		else
		{
			cout<<"Enter the quantity issue:";
			cin>>x;
			if(x>quantity)
			{
				cout<<"That much item is not avilable";
			}
			else
			{
				quantity=quantity-x;
			}
		}
	}
	void priceitem(void)
	{
		cout<<rate<<"\n";
	}
};

//--------------------------------main function-----------------------------------------------

int main(void)
{

	iteamlist c[10];
	int i=0;
	c[i].getvalue();
	i++;
	while(1)
	{
		int opt;
		cout<<"chose option:\n1.Want to add another iteam\n2.Change the rate of an iteam\n3.reacived an iteam\n4.issue an iteam\n5.Cheack the price of an iteam";
		cin>>opt;
		switch(opt)
		{
			case 1:
				c[i].getvalue();
				i++;
				break;
			case 2:
				string name;
				cout<<"Enter the name of the iteam";
				cin>>name;
				for(int j=0;j<=i;j++)
				{
					if(name==c[j].returnname())
					{
						c[j].changetherate();
					}
				}

		}
	}
}