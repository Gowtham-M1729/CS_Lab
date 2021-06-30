import java.util.Scanner;
class cities_temp
{
   public Scanner sc=new Scanner(System.in);
   public static void main(String args[])
   {
   temp t = new temp();
   t.read();
   }
}
class temp
{  
   Scanner sc=new Scanner(System.in);
   int[][] tem=new int[5][6];
   void read()
   { 
      System.out.println("Enter the daily max temperature of 5 cities on 1st 6 days of january");
      for(int i[]:tem)
      {
         System.out.println("Enter the temp of day "+i);
         for(int j:i)
         {  System.out.println("Enter the temp of day "+tem[j]+"   "+i[0]);
            //tem[i][j]=sc.nextFloat();
         }
      }
   }
}
