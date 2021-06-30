import java.util.*; 
class Prime {
public static void main(String args[]) {
Scanner ob = new Scanner(System.in);
 int l=ob.nextInt();
 int k=ob.nextInt();
 boolean b=true;
 for(int i = l;i<=k; i++)
    {
      for(int j = 2;j*j<=i; j++)
         {
            if(i%j==0)
              {  b=false;
                 break;
               
              }
         }
      if(b && i>1)
         { 
            System.out.println(i);
         }
      b=true;
            
    }
 }
}
