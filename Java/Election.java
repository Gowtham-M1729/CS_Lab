import java.util.*; 
class Election {
       
        static int fib() 
          {   Scanner scan = new Scanner(System.in);
              int j=0,i,k,max=0,l=0;
              int a[] = new int[6];
              for (i = 1; true; i++)
                 {    System.out.println("Enter Ballot  "+i);
                            k = scan.nextInt();
                            if(k<1 || k>5)
                              a[0]++;
                            else
                              a[k]++;
                      System.out.println("If you want to end enter any charcter");
                        char c = scan.next().charAt(0);
                        if(Character.isAlphabetic(c))
                          break;
                        else
                          continue;
                      
                 }
              for (i = 0; i < a.length; i++)
                 { 
                  if (a[i] > max) 
                     { max = a[i];
                       j=i;
                     }
                 }
              for (i = 1; i <=a.length; i++)
                 System.out.println("Number of  ballots for " +i+" are"+a[i]);
              System.out.println("maximum vote is "+max+" for "+j);
              System.out.println("Number of spoilts ballots are"+a[0]);
              return 1;
           
	}
	public static void main(String args[]) 
	{        
		fib();
	}
     
}
