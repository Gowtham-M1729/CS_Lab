import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Studentscore {
    public static void main(String args[])
    { 
      int deposit,i,k,n,m,b,d;
      Student[] a;
      Scanner scan = new Scanner(System.in);
      System.out.println("Enter Total no. of Students ");
      n=scan.nextInt();
      a = new Student[n];
      for(i=0;i<n;i++)
         { 
            System.out.print("Enter Roll Number of "+(i+1)+"th student:");
            k=  scan.nextInt();

            System.out.print("Enter score 1 of student "+(i+1)+" ");
            m = scan.nextInt();
    
            System.out.print("Enter score 2 of student "+(i+1)+" ");
            d = scan.nextInt();

            System.out.print("Enter score 3 of student "+(i+1)+" ");
            b = scan.nextInt();

            a[i] = new Student(k,m,d,b);
            System.out.println("\n");
         }
      while(true)
        {  System.out.println("Enter Choice");
           System.out.println("1.Total");
           System.out.println("2.Display");
           System.out.println("3.Maximum in each Subject");
           System.out.println("0.Exit");
           k = scan.nextInt();
           switch(k)
            {   case 1:
                Student.Total(a);
                break;
             case 2:
                Student.display(a);
                break;
            case 3:
                Student.maintain(a);
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

class Student {
        int[] s = new int[3]; 
        int Rn,max;
        Student(int Rn,int s1,int s2,int s3)
        {
            this.Rn = Rn;
            s[0] = s1;
            s[1] = s2;
            s[2] = s3;
           
        }

        static void display(Student[] a)
        {
            System.out.println("ROLL NO.\tSubject-1\tSubject-2\tSubject-3\t");
            for(int i=0;i<a.length;i++)
               { 
                  System.out.println((i+1)+"\t\t"+a[i].s[0]+"\t\t"+a[i].s[1]+"\t\t"+a[i].s[2]);
               }
                  
            System.out.println();        
        }
        

        static void Total(Student[] a)
        {   int l=0,max=0;
            for(int i=0;i<a.length;i++)
              {   int c=0;
                  for(int j=0;j<3;j++)
                    {  
                         c+=a[i].s[j];
                    }
                  if(max<c)
                    { max=c;
                      l=i+1;
                    }
                 System.out.println("Totalmarks obtained by "+(i+1) +" Student  is "+c);
              }
           System.out.println("Highest mark of "+  max +" is "+" is obtained by Roll Number "+l);
        }
        static void maintain(Student[] a)
           { 
              int l=0;
             for(int i=0;i<3;i++)
              {   int max=0;
                  for(int j=0;j<a.length;j++)
                    {  if(a[j].s[i]>max)
                         {
                           max=a[j].s[i];
                           l=j;
                         }
                    }
                 System.out.println("Highest mark in "+  (i+1) +" subject is "+max+" by Roll Number "+l);
              }
           }
}
