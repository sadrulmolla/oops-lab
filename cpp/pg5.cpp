


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
	array(array& b)
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
	array operator + (array a)
	{
		array t(size);
		for(int i=0;i<size;i++)
		{
			t.ptr[i]=ptr[i]+a.ptr[i];
		}
		return t;
	}
	array operator = (array a)
	{
		for(int i=0;i<size;i++)
		{
			a.ptr[i]=ptr[i];
		}
		return*this;
	}
	int operator [] (int a)
	{
		return ptr[a];
	}
	array operator * (int a)
	{
		array t(size);
		int i;
		for(i=0;i<size;i++)
		{
			t.ptr[i]=ptr[i]*a;
		}
		return t;
	}
	int returnsize(void){return size;}

};

//------------------to add two array and make equal two array ------------------------

void addarray(array arr,array arr1)
{
	if(arr.returnsize()==arr1.returnsize())
	{
		(arr1+arr).display();
		arr1=arr;
		arr1.display();
	}
	else
	{
		cout<<"size of both array have to be same";
	}
}


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
	array arr(4);
	array arr1(4,5);
	array arr2=arr1;
	array arr3(Arr,size);
	arr.display();
	arr1.display();
	arr2.display();
	arr3.display();
	int cons;
	cout<<"constructor type of a & b:\n1.default & parameterized\n2.parameterized & coppy\n3.coppy & array initialized\n4.array initialized and default\n5.parameterized & array initialized\n6.copy & default\n=>";
	cin>>cons;
	switch(cons)
	{
		case 1:
			addarray(arr,arr1);
			break;
		case 2:
			addarray(arr1,arr2);
			break;
		case 3:
			addarray(arr2,arr3);
			break;
		case 4:
			addarray(arr3,arr2);
			break;
		case 5:
			addarray(arr1,arr3);
		case 6:
			addarray(arr,arr2);
		default:
			cout<<"this is not valid option";
	}

	
	cout<<"Enter the array no:";
	int en,no;
	cin>>no;
	en=arr3[no];
	cout<<en<<endl;
	switch(cons)
	{
		case 1:
			(arr*5).display();
			break;
		case 2:
			(arr1*5).display();
			break;
		case 3:
			(arr2*5).display();
			break;
		case 4:
			(arr3*5).display();
			break;
		case 5:
			(arr1*5).display();
			break;
		case 6:
			(arr*5).display();
	}
	return 0;
}
