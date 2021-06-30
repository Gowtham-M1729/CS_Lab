import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class ExecuteAccount {
    public static void main(String args[]) throws IOException
    { 
      String name,AccountType;
      int deposit,i,k,withdraw,n;
      Account[] a;
      Scanner scan = new Scanner(System.in);
      BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
      a = new Account[5];
      System.out.println("Enter Total no. of accounts you want to create");
      n=scan.nextInt();
      a[0] = new Account("ABCD","Saving Bank Account ",5000);
      a[0].display();
      a[0].deposit(5000);
      a[0].withdraw(10000);
      for(i=1;i<n;i++)
         { 
            System.out.println("Enter Name:");
            name = reader.readLine();

            System.out.println("Enter Account type:");
            AccountType = reader.readLine();

            System.out.println("Enter deposit amount:");
            deposit = scan.nextInt();

            a[i] = new Account(name,AccountType,deposit);
            System.out.println("\n");
         }
      while(true)
        {  System.out.println("Enter Choice");
           System.out.println("1.Deposit");
           System.out.println("2.Withdraw");
           System.out.println("1.Display");
           System.out.println("4.Maintain");
           System.out.println("5.Exit");
           k = scan.nextInt();
           switch(k)
            { case 1:
                System.out.println("Enter Account and amount to be deposited");
                k=scan.nextInt();
                deposit = scan.nextInt();
                a[k].deposit(deposit);
                break;
             case 2:
                System.out.println("Enter Account and amount to be Withdrawn");
                k=scan.nextInt();
                withdraw = scan.nextInt();
                a[k].withdraw(withdraw);
                break;
             case 3:
                System.out.println("Enter Account to be Displayed");
                k=scan.nextInt();
                a[k].display();
                break;
            case 4:
                Account.maintain(a);
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
        String Name,AccountType;
        long AccountNumber,BalanceAmount;

        Random num = new Random();

        Account(String Name,String AccountType)
        {
            this.Name = Name;
            BalanceAmount = 0;
            this.AccountType = AccountType;
            AccountNumber = num.nextInt(1000) + 10000000;
        }

        Account(String Name,String AccountType,int Amount)
        {
            this.Name = Name;
            BalanceAmount = Amount;
            this.AccountType = AccountType;
            AccountNumber = num.nextInt(1000) + 10000000;
        }

        void display()
        {
            System.out.println("Name:" + Name);
            System.out.println("Balance:"+BalanceAmount);
            System.out.println("Account type:"+ AccountType);
            System.out.println("Account No.:" + AccountNumber);
            System.out.println();
        }

        void deposit(long Amount)
        {
            BalanceAmount += Amount;
            System.out.println("₹" + Amount + "Has been deposited successfully to your account");
            System.out.println("Updated Account Balance: ₹" + BalanceAmount);
            System.out.println();
        }

        void withdraw(long Amount)
        {
            if(Amount > BalanceAmount)
            {
                System.out.println("No Sufficient balance to withdraw the Amount: " + "₹" + Amount);
                System.out.println("Balance: ₹"+BalanceAmount);
                System.out.println();
            }
            else
            {
                BalanceAmount -= Amount;
                System.out.println("₹"+Amount+" has been withdrawn from your Account Successfully");
                System.out.println("Your Account Balance is: ₹"+BalanceAmount);
                System.out.println();
            }
        }
        static void maintain(Account[] a)
           { System.out.println("Total number of accounts are "+a.length);
               
             for(int i=0;i<5;i++)
              {  a[i].display();
              }
           }
}
