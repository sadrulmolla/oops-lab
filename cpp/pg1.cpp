#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

//defining class for 24 hour format 

class time24
{
	private:
		int hour,minute,second;
		const char*t;
	public:
		void timeinput24(void)
		{
			int hrs,min,sec;
			printf("Enter the time:\n");
			scanf("%2d:%2d:%2d",&hrs,&min,&sec);
			hour=hrs;
			minute=min;
			second=sec;
		}
		void convert12(void)
		{
			if(hour>12)
			{
				hour=hour-12;
				t="PM";
			}
			else
			{
				t="AM";
			}
		}
		void timedisplay(void)
		{
			cout << hour << ":" << minute << ":" << second << " " << t << endl;
		}
		void addminute24(int min)
		{
			//cout<<"Enter the minute\n";
			//cin>>min;
			minute=min+minute;
			if(minute>=60)
			{
				hour=hour+minute/60;
				if(hour>=24)
				{
					hour=hour%24;
				}
				minute=minute%60;
			}
		}
};
class time12
{
	private:
		int hour,minute,second;
		char t[3];
	public:
		void timeinput12(void)
		{
			int hrs,min,sec;
			printf("Enter the time:");
			scanf("%2d:%2d:%2d %[^\n]",&hrs,&min,&sec,t);
			hour=hrs;
			minute=min;
			second=sec;
		}
		void convert24(void)
		{
			if(strcmp(t,"PM")==0)
				hour=hour+12;
				if(hour>=24)
				{
					hour=hour%24;
				}
		}
		void display(void)
		{
			cout << hour << ":" << minute << ":" << second <<endl;
		}
		void addminute12(int min)
		{
			//cout<<"Enter the minute\n";
			minute=min+minute;
			if(minute>=60)
			{
				hour=hour+minute/60;
				if(hour>=24)
				{
					hour=hour%24;
				}
				minute=minute%60;
			}
		}
};

int main(void)
{
	int format;
	printf("Enter the format(12 hrs or 24hrs):");
	scanf("%d",&format);
	if(format==24)
	{
		time24 t1;
		t1.timeinput24();
		t1.convert12();
		cout << "12 hour time format: ";
		t1.timedisplay();
		printf("Want to add minute\n1.yes\n2.No");
		int c;
		scanf("%d",&c);
		if(c==1)
		{
			int min; 
			scanf("%d",&min);
			t1.addminute24(min);
			t1.timedisplay();
		}
	}
	else
	{
		time12 t2;
		t2.timeinput12();
		t2.convert24();
		cout<<"24 hour time format: ";
		t2.display();
		printf("Want to add minute\n1.yes\n2.no\n");
		int c;
		scanf("%d",&c);
		if(c==1)
		{	
			int min; 
			scanf("%d",&min);
			t2.addminute12(min);
			t2.display();
		}
	}
	return 0;
}