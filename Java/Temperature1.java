import java.util.*;
import java.util.function.Supplier; 
class Temperature1 {
       
        static int fib() 
          {   Scanner scan = new Scanner(System.in);
              int j,i,k,max=0,l=0,m=0,min=10000,l1=0,m1=0;
              String[] array=new String[10];
              for (j = 1; j<= 5; j++)
                  { System.out.println("Enter city name "+j);
                    array[j]=scan.nextLine();
                    
                  } 
              int a[][] = new int[7][6];
              for (i = 1; i <= 6; i++)
                 {    System.out.println("For day "+i);
	              for (j = 1; j<= 5; j++)
                         {   System.out.println("Enter for city  "+array[j]);
                            k = scan.nextInt();
                            a[i][j]=k;
                            if(k>max)
                             { max=k;
                               l=j;
                               m=i;
                             }
                           if(k<min)
                             { min=k;
                               l1=j;
                               m1=i;
                             }
                           
                         }
                 }
                 for (j = 1; j<= 5; j++)
                     System.out.print("\t"+array[j]);
                  System.out.print("\n");
                 for (i = 1; i <= 6; i++)
                 {    System.out.print("Day "+i);
	              for (j = 1; j<= 5; j++)
                          System.out.print("\t"+a[i][j]);
                       System.out.print("\n");
                 }
                 System.out.print("\n");
              System.out.println("Maximum Temperature of "+max+" at "+array[l]+" on "+m);
              System.out.println("Maximum Temperature of "+min+" at "+array[l1]+" on "+m1);
              return 1;
           
	}
	public static void main(String args[]) 
	{        
		fib();
	}
     
}
