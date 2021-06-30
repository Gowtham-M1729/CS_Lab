class pyjava { 
        static int fib(int n) 
          {	int j,i; 	 
              for (i = 1; i <= n; i++)
                 { 
	              for (j = 1; j<= n-i; j++)
                          System.out.print(" ");
                      for (j = 0; j<= 2*(i-1); j++)
                          System.out.print("*");
                 System.out.print("\n");
                 }
              return 1;
           
	}
	public static void main(String args[]) 
	{       int i;
		int n = Integer.parseInt(args[0]); 
		fib(n);
	} 
}
