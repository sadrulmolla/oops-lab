

//======================================Degine a STRING class which will have the initialization facultiy similar to array class==========================
#include<iostream>
#include<cstring>

using namespace std;

class strg
{
	string name;
public:
	//strg ()
	//{
	//	name=NULL;
	//}
	strg(string str)
	{
		name=str;
	}
	strg(strg& b)
	{
		name=b.name;
	}
	void display(void)
	{
		cout<<name<<endl;
	}
	strg operator = (strg a)
	{
		name=a.name;
		return*this;
	}
	strg operator + (strg a)
	{
		strg result(name);
		result.name=name+a.name;
		return result;
	}
	int operator - (strg a)
	{
		if(a.name==name)
		{
			return 0;
		}
		else if(a.name>name)
		{
			return -1;
		}
		else
		{
			return 1;
		}
	} 
};

//--------------realtion opeartion of two string---------------------------------------

void relationoperation(int n)
{
	if(n==0)
	{
		cout<<"Both string are same\n";
	}
	else if(n==1)
	{
		cout<<"string2 is greater\n";
	}
	else
	{
		cout<<"string1 is greater\n";
	}
}

//-----------------------------main function-------------------------------------------

int main(void)
{
	string str1,str2;
	int opt;
	str1="sadrul";
	strg c1(str1);
	strg c2=c1;
	cout<<"Enter the string\n=>";
	cin>>str2;
	strg c3(str2);
	c1.display();
	c2.display();
	c3.display();
	while(1)
	{
		cout<<"-------------------------------------\n";
		cout<<"Options\n";
		cout<<"--------------------------------------\n";
		cout<<"1.Assiging one object for another\n2.connected using +\n3.realtion of two string\n4.EXIT\n=>";
		cin>>opt;
		switch(opt)
		{
			case 1:
				c1=c3;
				cout<<"3rd string copying to first:\n";
				c1.display();
				break;
			case 2:
				cout<<"2nd and 3rd string are connected:\n";
				(c2+c3).display();
				break;
			case 3:
				cout<<"realtion of 2nd and 3rd :\n";
				relationoperation(c2-c3);
				break;
			case 4:
				exit(0);
		}
	}
		return 0;
}