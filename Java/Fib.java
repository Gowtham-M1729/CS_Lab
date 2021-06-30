import java.util.*; 
class Fib { 
        static int fib(int n) 
          {
        int i;
	int a[] = new int[n + 1];
        char b[] = new char[n + 1]; 
        for (i = 0; i <= n; i++)
           System.out.print(b[i]); 
        a[0] = 0; 
        a[1] = 1;
			 
        for (i = 2; i <= n; i++)
	    a[i] = a[i - 1] + a[i - 2]; 

	for (i = 0; i <= n; i++)
           System.out.print(a[i]+"\t");
           return 1;
          }
           
	

	public static void main(String args[]) 
	{       Scanner ob = new Scanner(System.in);
                System.out.println("Enter n");
		int n = ob.nextInt();
		fib(n);
	} 
}
