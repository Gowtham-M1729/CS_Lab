import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        String A=new String();
        A=sc.nextLine();
        char s[]=A.toCharArray();
        char s1[]=new char[A.length()];
        int i,j;
        i=0;
        j=(A.length()-1);
        System.out.println(j+"\t"+s[0]+"\t"+A);
        while(i<(A.length())&&j>=0)
        
        {   
            s1[i]=s[j];
            System.out.println(s1[i]+"\t"+s[j]);
            i++;
            j--;
            
        }
        String s2=new String(s1);
        System.out.println(s2+"\t"+A+ A.equalsIgnoreCase(s2)+"\t"+A.length()+"\t"+s2.length());
        if(A.equals(s2))
        {
                    System.out.println("palin");

        }
i=0;
j=(A.length()-1);
while(i<(1+A.length()/2)&&j>=0)
        
        {   if(s[i]==s[j])
              { System.out.println(s[i]+"\t"+s[j]);
                i++;
                j--;
                continue;
              }
            else
              System.exit(0);
            
            
        }
      System.out.println("palin");
        /* Enter your code here. Print output to STDOUT. */
        
    }
}
