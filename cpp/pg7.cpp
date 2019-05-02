

//======================================Degine a STRING class which will have the initialization facultiy similar to array class==========================
#include<iostream>
#include<cstring>

using namespace std;

class strg
{
	char*name;
	int count;
public:
	strg(char*str)
	{
		name=new char[std::strlen(str)];
		name=str;
		count=1;
	}
	strg(strg& b)
	{
		name=new char[std::strlen(b.name)+1];
		name=b.name;
	}
	void display(void)
	{
		cout<<name<<endl;
	}
	strg operator = (strg&a)
	{
		name=a.name;
		a.count++;
	}
	char*operator + (strg a)
	{
		int i,j;
		char * newArray = new char[std::strlen(name)+std::strlen(a.name)+1];
		std::strcpy(newArray,name);
		std::strcat(newArray,a.name);
		cout<<newArray<<endl;
		delete [] newArray;
	}
	int operator - (strg a)
	{
		if(strcmp(a.name,name)==0)
		{
			return 0;
		}
		else if(strcmp(a.name,name)<0)
		{
			return -1;
		}
		else
		{
			return 1;
		}
	}
	void refer(void)
	{
		cout<<count<<endl;
	}
	~strg()
	{
		cout<<"Distructor call"<<endl;
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
	char*str1,*str2;
	str1=new char[30];
	str2=new char[30];
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
				c3.refer();
				c1=c3;
				cout<<"3rd string refering to first:\n";
				c1.display();
				c3.refer();
				break;
			case 2:
				cout<<"2nd and 3rd string are connected:\n";
				(c2+c3);
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