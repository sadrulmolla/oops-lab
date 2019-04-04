import java.util.*;

import javax.swing.plaf.synth.SynthListUI;

class student
{
	String roll;
	String name;
	String course;
	int day,month,year;
	String  subname[]=new String[5];
	int submarks[]=new int[5];

	Scanner s =new Scanner(System.in);

	public void getName()
	{
		System.out.println("Enter The Name Of the Student:");
		name=s.nextLine();
		year = Calendar.getInstance().get(Calendar.YEAR);
		month=Calendar.getInstance().get(Calendar.MONTH);
		day = Calendar.getInstance().get(Calendar.DAY_OF_MONTH);
		//System.out.println(year+":"+month+":"+day);
		
	}
	public void getResult()
	{
		int i;
		System.out.println("Enter The 5 subjects Name:");
		for(i=0;i<5;i++)
		{
			System.out.print("=>");
			subname[i]=s.nextLine();
		}
		System.out.println("Enter The Marks of 5 Subjects:");
		for(i=0;i<5;i++)
		{
			System.out.print("=>");
			submarks[i]=s.nextInt();
		}
	}
	public void display()
	{
		int i;
		System.out.println("\n===================================");
		System.out.println("Name: "+name);
		System.out.println("Roll: "+roll);
		System.out.println("Admisson Date: "+year+":"+month+":"+day);
		System.out.println("Marksheet:");
		for(i=0;i<5;i++)
		{
			System.out.println(subname[i]+": "+submarks[i]);
		}
		System.out.println("===================================");
	}
	public void prtname(){System.out.println(name);}
}

class bcse extends student
{
	static int count=0;
	public void getRoll()
	{
		String sta1= Integer.toString(year);
		String sta2= Integer.toString(count);
		sta1=sta1.substring(3,4);
		if(count==100)
		{
			roll="BCSE/"+sta1+sta2;
		}
		else if(count>=10 && count<100)
		{
			roll="BCSE/"+sta1+"0"+sta2;
		}
		else
		{
				roll="BCSE/"+sta1+"00"+sta2;
		}
		count++;
	}
	public int return_count(){return count;}
}

class etce extends student
{
	static int count=0;
	public void getRoll()
	{
		String sta1= Integer.toString(year);
		String sta2= Integer.toString(count);
		sta1=sta1.substring(3,4);
		if(count==100)
		{
			roll="ETCE/"+sta1+sta2;
		}
		else if(count>=10 && count<100)
		{
			roll="ETCE/"+sta1+"0"+sta2;
		}
		else
		{
				roll="ETCE/"+sta1+"00"+sta2;
		}
		count++;
	}
	public int return_count(){return count;}
}

class civil extends student
{
	static int count=0;
	public void getRoll()
	{
		String sta1= Integer.toString(year);
		String sta2= Integer.toString(count);
		sta1=sta1.substring(3,4);
		if(count==100)
		{
			roll="CVIL/"+sta1+sta2;
		}
		else if(count>=10 && count<100)
		{
			roll="CVIL/"+sta1+"0"+sta2;
		}
		else
		{
			roll="CVIL/"+sta1+"00"+sta2;
		}
		count++;
	}
	public int return_count(){return count;}
}
class elctr extends student
{
	static int count=0;
	public void getRoll()
	{
		String sta1= Integer.toString(year);
		String sta2= Integer.toString(count);
		sta1=sta1.substring(3,4);
		if(count==100)
		{
			roll="ELCT/"+sta1+sta2;
		}
		else if(count>=10 && count<100)
		{
			roll="ELCT/"+sta1+"0"+sta2;
		}
		else
		{
				roll="ELCT/"+sta1+"00"+sta2;
		}
		count++;
	}
	public int return_count(){return count;}
}

class Studentlist
{
	Scanner src =new Scanner(System.in);
	private bcse cs[] = new bcse[5];
	private elctr el[] = new elctr[5];
	private etce etc[] = new etce[5];
	private civil cl[]= new civil[5];

	public int getdeperment()
	{
		int opt1;
		System.out.print("Enter The Deperment\n1.BCSE\n2.ETCE\n3.CIVIL\n4.ELECTRICAL\n=>");
		opt1=src.nextInt();
		return opt1;
	}

	public void getprepaird()
	{
		int opt1;
		opt1=getdeperment();
		switch(opt1)
		{
			case 1:
				bcse t= new bcse();
				t.getName();
				t.getResult();
				t.getRoll();
				if(t.return_count()<=5)
				{
					cs[t.return_count()]=t;
				}
				break;
			case 2:
				etce t1= new etce();
				t1.getName();
				t1.getResult();
				t1.getRoll();
				if(t1.return_count()<=5)
				{
					etc[t1.return_count()]=t1;
				}
				break;
			case 3:
				civil t2= new civil();
				t2.getName();
				t2.getResult();
				t2.getRoll();
				if(t2.return_count()<=5)
				{
					cl[t2.return_count()]=t2;
				}
				break;
			case 4:
				elctr t3= new elctr();
				t3.getName();
				t3.getResult();
				t3.getRoll();
				if(t3.return_count()<=5)
				{
					el[t3.return_count()]=t3;
				}
				break;
			default:
				System.out.println("Plese Enter A Valid Input");
				break;	
		}

	}
	/*public int search_rool(String roll)
	{
		String substring = roll.substring(Math.max(roll.length() - 2, 0));
		int result = Integer.parseInt(substring);
		return result;
	}*/
	public void display()
	{
		int opt1,r;
		opt1=getdeperment();
		System.out.print("Enter The Roll No(Excluding Deperment Code): ");
		r=src.nextInt();
		try{
		if(opt1==1){cs[r].display();}
		else if(opt1==2){etc[r].display();}
		else if(opt1==3){cl[r].display();}
		else if(opt1==4){el[r].display();}
		else{System.out.println("Enter A Valid Option");}
		}
		catch(NullPointerException e ){
			System.out.println("This Roll No Does'nt Exist.");
		}
	}
	public void prt()
	{
		int opt,i,n;
		opt=getdeperment();
		if(opt==1)
		{
			n=cs[1].return_count();
			for(i=0;i<n;i++)
			{
				cs[i].prtname();
			}
		}

	}
}

public class pg1{

	public static void main(String[] args){
		int opt;
		Scanner src =new Scanner(System.in);
		Studentlist slist= new Studentlist();
		while(true)
		{
			System.out.println("-----------------------------------------");
			System.out.println("		OPTIONS");
			System.out.println("-----------------------------------------");
			System.out.print("1.Enter The Details Of A Student\n2.Check Details Of A Student\n3.Check Student List Of A Deperment\n4.EXIT\n=>");
			opt=src.nextInt();
			System.out.print("\033[H\033[2J");
			System.out.flush();
			switch(opt)
			{
				case 1:
					slist.getprepaird();
					break;
				case 2:
					slist.display();
					break;
				case 3:
					slist.prt();
					break;
				case 4:
					System.exit(0);
					src.close();
				default:
					System.out.println("Enter A valid Option");
			}
		}
					
	}
}