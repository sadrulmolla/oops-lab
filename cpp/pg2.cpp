

//-------------------------code to make a object behave like an integer or oprator overloading---------------------------


#include<iostream>
#include<cstring>

using namespace std;

class complex
{
private:
	float real;
	float imag;
public:
	void getvalue(void)
	{
		string s;
		cout<<"Enter the complex Number:";
		cin>>s;
		int index = s.find_first_of("+i");
		real = atoi(s.substr(0,index).c_str());
		imag = atoi(s.substr(index+2,3).c_str());
	}
	complex operator+(complex c2)
	{
		complex c3;
		c3.real=real+c2.real;
		c3.imag=imag+c2.imag;
		return(c3);
	}
	complex operator-(complex c2)
	{
		complex c3;
		c3.real=real-c2.real;
		c3.imag=imag-c2.imag;
		return(c3);
	}
	void display(void)
	{
		if(imag!=0 && real!=0)
		{
			cout<<real<<"+i"<<imag<<endl;
		}
		else if(imag==0)
		{
			cout<<real<<endl;
		}
		else if(real==0)
		{
			cout<<"i"<<imag<<endl;
		}
	}
	
};

int main(void)
{
	while(1)
	{
		int opt,opt1;
		complex c1,c2;
		c1.getvalue();
		c2.getvalue();
		printf("1.Addition\n2.Subtraction\n");
		scanf("%d",&opt);
		complex c3;
		if(opt==1)
		{
			c3=c1+c2;
		}
		else
		{
			c3=c1-c2;
		}
		c3.display();
		printf("Want to exist:\n1.yes\n2.No\n");
		scanf("%d",&opt1);
		if(opt1==1)
		{
			break;
		}
	}
}
