
//==================================================programe to make  a array class of a specific size=========================================

#include<iostream>
#include<cstring>

using namespace std;

class array
{
	int size;
	int*ptr;
public:
	array(int k=0)
	{
		size=k;
		if(k!=0)
		{
			ptr=new int [k];
		}
		else
		{
			ptr=NULL;
		}
		for(int i=0;i<size;i++)
		{
			ptr[i]=0;
		}
	}
	array(int k,int value)
	{
		size=k;
		if(k!=0)
		{
			ptr=new int [k];
		}
		else
		{
			ptr=NULL;
		}
		for(int i=0;i<size;i++)
		{
			ptr[i]=value;
		}
	}
	array(array &b)
	{
		size=b.size;
		if(size!=0)
		{
			ptr=new int [size];
		}
		else
		{
			ptr=NULL;
		}
		for(int i=0;i<size;i++)
		{
			ptr[i]=b.ptr[i];
		}
	}
	array(int*a,int k)
	{
		size=k;
		if(size!=0)
		{
			ptr=new int [size];
		}
		else
		{
			ptr=NULL;
		}
		for(int i=0;i<size;i++)
		{
			ptr[i]=a[i];
		}
	}			
	void display(void)
	{
		for(int i=0;i<size;i++)
		{
			cout<<ptr[i]<<"\t";
		}
		cout<<endl;
	}
	array operator +(array &a)
	{
		array t(size);
		for(int i=0;i<size;i++)
		{
			t.ptr[i]=ptr[i]+a.ptr[i];
		}
		return t;
	}
	void operator =(array &a)
	{
		for(int i=0;i<size;i++)
		{
			a.ptr[i]=ptr[i];
		}
	}
		
	int returnsize(void){return size;}			

};

int main(void)
{
	int*Arr,size;
	cout<<"Enter the size of the array";
	cin>>size;
	Arr=new int [size];
	cout<<"Enter the value of the array";
	for(int i=0;i<size;i++)
	{
		cin>>Arr[i];
	}
	array arr(3);
	array arr1(4,5);
	array arr2=arr1;
	array arr3(Arr,size);
	arr.display();
	arr1.display();
	arr2.display();
	arr3.display();
	if(arr.returnsize()==arr3.returnsize())
	{
		array arr4(arr.returnsize());
		arr4=arr+arr3;
		arr4.display();
		arr4=arr;
		arr4.display();
	}
	else
	{
		cout<<"size of both array have to be same";
	}
	return 0;
}
