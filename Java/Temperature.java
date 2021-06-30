import java.util.*;
import java.util.function.Supplier; 
class Temperature {
       
        static int fib() 
          {   Scanner scan = new Scanner(System.in);
              int j,i,k,max=0,l=0,m=0;
              String[] array=new String[10];
              for (j = 1; j<= 5; j++)
                  array[j]=scan.nextLine();    
              for (j = 1; j<= 5; j++)
                  System.out.println(max+" "+array[j]); 
              int a[] = new int[5*6];
              for (i = 1; i <= 6; i++)
                 {    System.out.println("For day "+i);
	              for (j = 1; j<= 5; j++)
                         {  k = scan.nextInt();
                            a[j]=k;
                            if(k>max)
                             { max=k;
                               l=j;
                               m=j;
                             }
                         }
                 }
              System.out.println(max+" at "+array[l]+" on"+m);
              return 1;
           
	}
	public static void main(String args[]) 
	{        
		fib();
	}
     
}
