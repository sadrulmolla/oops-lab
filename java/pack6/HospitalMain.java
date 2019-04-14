import java.util.*;
import java.io.*;
class Patient{
    String name;
    String id;
    String docId;
    boolean isAssigned;
    String[] history = new String[100];
    int count1=0;
    Patient(){
        name="";
        id="";
        docId="";
        isAssigned = false;
        for(int j=0;j<100;j++)
            history[j] ="";
    }
}
class Hospital{
    Patient[] pa = new Patient[100];
    String[] doc = new String[10];
    HashMap<String, ArrayList<String>> occurences = new HashMap<String, ArrayList<String>>();
    public static int count = 0;
    public void createDoctorId()
    {
        for(int i=0;i<3;i++)
            doc[i]= "00"+(i+1);
    }
    public void registerPatient(Scanner input)
    {
        pa[count] = new Patient();
        System.out.println("Enter Patients Name");
        pa[count].name = input.next();
        pa[count].id = "00"+(count+1);
        System.out.println(pa[count].name+"'s ID is "+pa[count].id);
        int y = (int) getRandomInteger(0,2);
        pa[count].docId = doc[y];
        System.out.println(pa[count].name+" is assigned to Doctor "+doc[y]);
        pa[count].isAssigned = true;
        ArrayList<String> list = occurences.get(doc[y]);
        if(list == null){
            list = new ArrayList<>();
            list.add(pa[count].id);
        }
        else {list.add(pa[count].id);}

        occurences.put(doc[y],list);
        count++;
    }
    public void observePatient(Scanner input, String id)
    {
        for(int i=0;i<=count;i++)
        {
            if(id.equalsIgnoreCase(pa[i].id)){
                System.out.println("Blood Pressure:");
                String bp = input.next();
                System.out.println("Body Temparature(In Farhenhite)");
                String temp =input.next();
                System.out.println("Time of Observation(in 24 hour format HH:mm)");
                String time = input.next();
                System.out.println("Date of Observation dd/mm/yyyy");
                String date = input.next();
                String str = "Blood Pressure: "+bp+",  Temparature: "+temp+",  Observation Time: "+time+",  Date is: "+date;
                pa[i].history[pa[i].count1]= str;
                pa[i].count1++;
                return;
            }
        }
        System.out.println("Patient ID not found");
    }
    public static double getRandomInteger(double min, double max){
        double y = (int) (Math.random() * ((max-min)+1)) + min;
        return y;
    }
    public void details(String id)
    {
        for(int i=0;i<=count;i++)
        {
            if(id.equalsIgnoreCase(pa[i].id)){
                System.out.println("Details of patient=>"+pa[i].id);
                System.out.println("Assigned Doctor Id: "+pa[i].docId);
                for(int j=0;j<=pa[i].count1;j++)
                {
                    System.out.println(pa[i].history[j]);
                }
                return;
            }
        }
        System.out.println("Patient id not found");
    }
    public void docCheck(){
        System.out.println(occurences.toString());
    }

}
public class HospitalMain {
    public static void main(String[] args)throws IOException
    {
        Hospital ht = new Hospital();
        Scanner input = new Scanner(System.in);
        ht.createDoctorId();
        do{
            System.out.println("Want Choices?");
            System.out.println("1.Yes");
            System.out.println("2.No");
            int ans= input.nextInt();
            if(ans==1){
                System.out.print("\033[H\033[2J");
			    System.out.flush();
                System.out.println("===========================================");
                System.out.println("1.Register New Patient");
                System.out.println("2.Check Details");
                System.out.println("3.Record Observations");
                System.out.println("4.Check Doctor's Status");
                System.out.println("===========================================");
                int ans1 = input.nextInt();
                if(ans1==1)
                {
                    ht.registerPatient(input);
                }
                else if(ans1==2)
                {
                    System.out.println("Enter Patient Id");
                    String str1 = input.next();
                    ht.details(str1);
                }
                else if(ans1==3){
                    System.out.println("Enter Patient Id");
                    String str2 = input.next();
                    ht.observePatient(input,str2);
                }
                else if(ans1==4){
                    ht.docCheck();
                }
                else
                    System.out.println("Wrong Choice");
            }
            else if(ans==2){
                input.close();
                break;
            }
            else
                System.out.println("Wrong input");
        }while(true);
    }
}
