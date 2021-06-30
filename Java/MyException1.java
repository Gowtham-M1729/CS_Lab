// Java program to demonstrate user defined exception

// This program throws an exception whenever balance
// amount is below Rs 1000
class MyException1 extends Exception
{
	//store account information
	private static int accno[] = {1001, 1002, 1003, 1004};

	private static String name[] =
				{"Nish", "Shubh", "Sush", "Abhi", "Akash"};

	private static double bal[] =
		{10000.00, 12000.00, 5600.0, 999.00, 1100.55};

	// default constructor
	MyException1() { }

	// parametrized constructor
	MyException1(String str) { super(str); }

	// write main()
	static void fib() throws MyException1
	{
		
			// display the heading for the table
			System.out.println("ACCNO" + "\t" + "CUSTOMER" +
										"\t" + "BALANCE");

			// display the actual account information
			for (int i = 0; i < 5 ; i++)
			{
				System.out.println(accno[i] + "\t" + name[i] +
											"\t" + bal[i]);

				// display own exception if balance < 1000
				if (bal[i] < 1000)
				{
					
					throw new MyException1("Balance is less than 1000");
					//throw me;
                                        //throw new MyException1();
				}
			}
		 //end of try

		/*catch (MyException e) {
			e.printStackTrace();
		}*/
	}
    public static void main(String[] args)
	{
		
                try {
                        System.out.print("Enter the data: ");
                        fib();
                    } catch (MyException1 e) {
                        System.out.println("Error: " + e.getMessage());
                        e.printStackTrace();
                       
                    } 
	}
}

