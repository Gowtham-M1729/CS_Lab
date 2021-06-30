import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class ExecuteAccount_5q {
    public static void main (String args[]) throws IOException
    {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("Enter Total no. of accounts you want to create");
        int num = Integer.parseInt(reader.readLine());
        Account[] account = new Account[num];

        for(int i=0;i<num;++i)
        {
            System.out.println("Enter Name:");
            String name = reader.readLine();

            System.out.println("Enter Account type:");
            String AccountType = reader.readLine();

            System.out.println("Enter deposit amount:");
            int amount = Integer.parseInt(reader.readLine());

            account[i] = new Account(name,AccountType,amount);
            System.out.println("\n");
        }

        while(true) {
            System.out.println("Enter Choice");
            System.out.println("1.Display");
            System.out.println("2.Deposit");
            System.out.println("3.Withdraw");
            System.out.println("4.Maintain");
            System.out.println("5.Exit");

            int choice = Integer.parseInt(reader.readLine());

            if (choice != 4)
            {
                System.out.println("Enter Account");
                int number = Integer.parseInt(reader.readLine());
                if(number > num || number == 0)
                    System.out.println("Please Enter a valid Account:");
                else
                {
                    System.out.println(choice);
                    switch(choice)
                    {

                        case 1:
                            account[number-1].display();
                            break;
                        case 2:
                            System.out.println("Enter the amount you want to deposit");
                            int Amount = Integer.parseInt(reader.readLine());
                            account[number-1].deposit(Amount);
                            System.out.println("Balance: ₹"+ account[number-1].BalanceAmount);
                            break;
                        case 3:
                            System.out.println("Enter the Amount you want to withdraw:");
                            Amount = Integer.parseInt(reader.readLine());
                            account[number-1].withdraw(Amount);
                            System.out.println("Balance: ₹"+ account[number-1].BalanceAmount);
                            break;
                        case 5:
                            System.out.println("+++++++++");
                            System.exit(0);
                           
                            
                    }
                }
            }
            else
            {
                Account.maintain(num,account);
            }
        }

    }
}

class Account {
        String Name,AccountType;
        long AccountNumber,BalanceAmount;

        Random num = new Random();

        Account(String Name,String AccountType,int Amount)
        {
            this.Name = Name;
            BalanceAmount = Amount;
            this.AccountType = AccountType;

            //code below generates account number randomly with a fixed prefix
            AccountNumber = num.nextInt(1000000) + 3000000;
            String tempNum = "39543" + AccountNumber;
            AccountNumber = Long.parseLong(tempNum);
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

        static void maintain(int num,Account[] account)
        {
            System.out.println("The total no. of accounts in our bank are:" + num);
            for(int i=0;i<num;++i)
            {
                account[i].display();
            }
        }
}
