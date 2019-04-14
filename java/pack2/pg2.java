import java.util.*;

//class to save details of a single item

class item
{
    private String i_code;
    private String name;
    private float rate;
    private int quan;

    Scanner s =new Scanner(System.in);//object read a data
    public void getdetails()//function to get details about any item
    {
        System.out.print("Enter The Name of the Product: ");
        name=s.nextLine();
        /*System.out.print("Enter The Item_code: ");
        i_code=s.nextLine();*/
        System.out.print("Enter The rate: ");
        rate=s.nextFloat();
        System.out.print("Enter The Quintity: ");
        quan=s.nextInt();
    }
    public String returncode(){return i_code;}
    public float returnprice(){return rate;}
    public String return_name(){return name;}
    public void pricecng(float r){rate=r;}
    public void chnageqn(int x){quan=quan+x;}
    public int return_qn(){return quan;}
    public void getIcode(int count)
    {
        String sta1=Integer.toString(count);
        i_code=name+sta1;
    }
    public void show()
    {
        System.out.println("=================================================\n");
        System.out.println("Name: "+name);
        System.out.println("Item Code: "+i_code);
        System.out.println("Rate: "+rate);
        System.out.println("quintity: "+quan);
        System.out.println("==================================================\n");
    }
}

//class to save all item in a array

class itemlist
{
    Scanner src =new Scanner(System.in);
    private item it[]=new item[10];
    private int count=0;

    public int check_id(String c)
    {
        int i;
        for(i=0;i<count;i++)
        {
            if(c.equalsIgnoreCase(it[i].returncode()))
            {
                return i;
            }
        }
        return -1;

    }
    public void getitem()
    {
        item t=new item();
        t.getdetails();
        t.getIcode(count);
        if(check_id(t.returncode())<0)
        {
            it[count]=t;
            count++;
        }
        else
        {
            System.out.println("The Item code is Same");
        } 

    }
    public void changeprice()
    {
        float r;
        int n;
        String cd;
        System.out.println("Enter The code of the Item: ");
        cd=src.nextLine();
        System.out.println("Enter The new rate:");
        r=src.nextFloat();
        src.nextLine();
        if(check_id(cd)>=0)
        {
            n=check_id(cd);
            it[n].pricecng(r);
        }
        else{System.out.println("Id Does'nt exist");}
    }
    public void costly()
    {
        int n,i;
        System.out.println("Enter The Price: ");
        n=src.nextInt();
        src.nextLine();
        for(i=0;i<count;i++)
        {
            if(it[i].returnprice()>n){System.out.println(it[i].return_name());}
        }
    }
    public void checkrate()
    {
        String cd;
        int n;
        float m;
        System.out.println("Enter The code of the Item:");
        cd=src.nextLine();
        if(check_id(cd)>=0){
            n=check_id(cd);
            m=it[n].returnprice();
            System.out.println("Rate: "+m);
        }
        else{System.out.println("Id Doesn't exist");}
    }
    public void recive()
    {
        String cd;
        int n,x;
        System.out.println("Enter The code of the Item: ");
        cd=src.nextLine();
        System.out.println("Enter The Amount Recived: ");
        x=src.nextInt();
        src.nextLine();
        if(check_id(cd)>=0){
            n=check_id(cd);
            it[n].chnageqn(x);
        }
        else{System.out.println("Id Does'nt exist");}
    }
    public void issue()
    {
        String cd;
        int n,x,p;
        System.out.println("Enter The code of the Item:");
        cd=src.nextLine();
        System.out.println("Enter The Amount issued:");
        x=src.nextInt();
        src.nextLine();
        p=-x;
        if(check_id(cd)>=0){
            n=check_id(cd);
            if(it[n].return_qn()>=x)
            {
                it[n].chnageqn(p);
            }
            else{System.out.println("Plese Enter A less Amount");}
        }
        else{System.out.println("Id Doesn't exist");}
    }
    public void display()
    {
        String cd;
        int n;
        System.out.println("Enter The code of the Item:");
        cd=src.nextLine();
        if(check_id(cd)>=0){
            n=check_id(cd);
            it[n].show();
        }
        else{System.out.println("Id Doesn't exist");}
    }
}
public class pg2
{
    public static void main(String[] args){
        int opt;
        Scanner src=new Scanner(System.in);
        itemlist i_list=new itemlist();
        while(true)
        {
            System.out.println("-----------------------------------------");
			System.out.println("		OPTIONS");
            System.out.println("-----------------------------------------");
            System.out.print("1.Enter A New Item\n2.Change The Rate of An item\n3.issue An Item\n4.recive An item\n5.Check Rate of An Item\n6.Check How many Items cost more then a certian Amount\n7.Check The Details of A Item\n8.EXIT\n=>");
            opt=src.nextInt();
            System.out.print("\033[H\033[2J");
            System.out.flush();
            switch(opt)
            {
                case 1:
                        i_list.getitem();
                        break;
                case 2:
                        i_list.changeprice();
                        break;
                case 3:
                        i_list.issue();
                        break;
                case 4:
                        i_list.recive();
                        break;
                case 5:
                        i_list.checkrate();
                        break;
                case 6:
                        i_list.costly();
                        break;
                case 7:
                        i_list.display();
                        break;
                case 8:
                        System.exit(0);
                        src.close();
                default:
                        System.out.println("Enter A valid Option");
            }
        }
    }
}