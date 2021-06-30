import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class Employee {
    String employeeID,employeeName,departmentName;
    double basicPay,grossPay,netPay,incomeTax;
    final int DA = 58;
    final int HRA = 16;

    Employee(String employeeID,String employeeName,String departmentName,double basicPay)
    {
        this.employeeID = employeeID;
        this.employeeName = employeeName;
        this.departmentName = departmentName;
        this.basicPay = basicPay;
    }
    double GrossPay()
    {
        grossPay = basicPay + (DA * 0.100 *basicPay)  + (HRA * 0.100 * basicPay);
        return grossPay; 
    }

    double IncomeTax()
    {
        if(grossPay<=200000)
        {
            incomeTax=0.0;
            return incomeTax;
        }
        else if(grossPay>200000 && grossPay<=300000)
        {
            incomeTax = 0.1*grossPay;
            return incomeTax;
        }
        else if(grossPay>300000 && grossPay<=500000)
        {
            incomeTax = 0.15*grossPay;
            return incomeTax;
        }
        else
        {
            incomeTax = 0.3*grossPay;
            double additionalTax = 0.02*incomeTax;
            incomeTax += additionalTax;
            return incomeTax;
        }
        
    }

    double netPay()
    {
        netPay = grossPay-this.IncomeTax();
        return netPay;
    }
}
public class Main3{
    public static void main(String args[]) throws IOException
    { 
      String s1,s2,s3,s4;
      int i,k,j=0,n;
      double pay;
      Employee[] a;
      Scanner scan = new Scanner(System.in);
      BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
      System.out.println("Enter Total no. of Employees");
      n=scan.nextInt();
      a = new Employee[n];
      for(i=0;i<n;i++)
         { 
            System.out.println("Enter Employee ID:");
            s1 = reader.readLine();

            System.out.println("Enter the Employee Name:");
            s2 = reader.readLine();

            System.out.println("Enter Department Name:");
            s3 = reader.readLine();
           
            System.out.println("Enter Basic Pay:");
            pay = scan.nextFloat();

            a[i] = new Employee(s1,s2,s3,pay);
            System.out.println("\n");
         }
     for(i=0;i<n;i++)
        {  System.out.print("Employee ID:  ");
           System.out.println(a[i].employeeID);
           System.out.print("Employee Name: ");
           System.out.println(a[i].employeeName);
           System.out.print("Employee Department Name:  ");
           System.out.println(a[i].departmentName);
           System.out.print("Employee Basic Pay:   ");
           System.out.println(a[i].basicPay);
           System.out.print("Employee Gross Pay:   ");
           System.out.println(a[i].GrossPay());
           System.out.print("Employee netPay:  ");
           System.out.println(a[i].netPay());   
           System.out.println("\n\n"); 
       }
}
}
