import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Book{
    public static void main(String args[]) throws IOException
    { 
      String name,bcode;
      int i,k,quantity,n,j=0;
      double price;
      Account[] a;
      Scanner scan = new Scanner(System.in);
      BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
      System.out.println("Enter Total no. of accounts you want to create");
      n=scan.nextInt();
      a = new Account[n];
      for(i=0;i<n;i++)
         { 
            System.out.println("Enter Name of the Book:");
            name = reader.readLine();

            System.out.println("Enter Book Code:");
            bcode = reader.readLine();

            System.out.println("Enter price of the book:");
            price = scan.nextInt();
           
            System.out.println("Enter number of such books:");
            quantity = scan.nextInt();

            a[i] = new Account(name,bcode,quantity,price);
            System.out.println("\n");
         }
      while(true)
        {  System.out.println("Enter Choice");
           System.out.println("Enter 1 to buy a book");
           System.out.println("Enter 2 to see available books");
           System.out.println("Enter 0 to Exit");
           k = scan.nextInt();
           switch(k)
            { case 1:
                System.out.println("Enter code of the Book");
                bcode = reader.readLine();
                for(i=0;i<n;i++)
                 {  
                    if(a[i].code.equals(bcode))
                      {
                       a[i].Buy();
                       break;
                      }
                 }
                if(i==n)
                  System.out.println("Such Book is not here");
                break;
             case 2:
                Account.display(a);
                break;
            case 0:
                System.exit(0);
            default:
                System.out.println("Enter a vaild choice ");
                break;
             }
       }
      
    }
}

class Account {
        String Name,code;
        int quantity,k;
        double price;
        Scanner scan = new Scanner(System.in);
        Account(String s,String m,int b,double k)
        {
            Name = s;
            quantity=b;
            code = m;
            price=k;
        }

        void Buy()
        {  System.out.println("NAME\t\t CODE\t\tUNIT PRICE\t\tQUANTITY\t\tTOTAL PRICE");
           System.out.println(Name+"\t\t"+code+ "\t\t" +price+ "\t\t\t" +quantity+ "\t\t\t"+quantity*price+"\n");
           if(quantity==0)
             {  System.out.println("No Such books available now");
                return;
             }
           System.out.println("How many books you want buy of  this type");
           k = scan.nextInt();
           if(k<=quantity)
             { 
               quantity-=k;
               System.out.println(k+" "+Name+" Books");
               System.out.println("Pay "+k*price);
             }
           else
             { System.out.println("There are only "+quantity+" Books\n If you want to buy these Enter 1");
               if(scan.nextInt()==1)
                { 
                  System.out.println(quantity+" "+Name+" Books");
                  System.out.println("Pay "+quantity*price);
                  quantity=0;
                }
             }
                
        }

        static void display(Account[] a)
         {
            System.out.println("NAME\t\t CODE\t\tPRICE\t\tQUANTITY\t\tTOTAL PRICE");
            for(int i=0;i<a.length;i++)
               {
                System.out.println(a[i].Name+"\t\t"+a[i].code+ "\t\t"+a[i].price+ "\t\t" +a[i].quantity+ "\t\t\t"+a[i].quantity*a[i].price);
               }
         }
}
