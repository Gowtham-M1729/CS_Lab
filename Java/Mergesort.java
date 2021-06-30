import java.util.Scanner;

class Mergesort
{
    public static void main(String[] args)
    {
        int i,j,k;
        Scanner ob = new Scanner(System.in);
        System.out.print("Enter n : ");
        int n = ob.nextInt();

        int a[] = new int[n];
        System.out.println("Enter elements for array 1");
        for(i=0;i<n;i++)
        {
            System.out.print("Enter "+i+1+" : ");
            a[i] = ob.nextInt();
        }

        System.out.println("Enter elements for array 2");
        int m = ob.nextInt();
        int b[] = new int[m];
        for(i=0;i<m;i++)
        {
            System.out.print("Enter "+i+1+" : ");
            b[i] = ob.nextInt();
        }
        int l=n+m;
        int c[] = new int[l];
        k=0;
        i=0;
        j=0;
        while(i<n && j<m)
        {   System.out.println("-");
            if(a[i]<=b[j])
            {
                c[k]=a[i];
                i+=1;
                k+=1;
            }
            else
            {
                c[k]=b[j];
                j+=1;
                k+=1;
            }
           
        }
        while(i<n)
        {
            c[k]=a[i];
             k++;
             i++;
             
        }
         while(j<m)
        {
            c[k]=b[j];
             k++;
             j++;
        }
          
          

        System.out.println("Sorted array :-");
        for(k=0;k<l;k++)
        {
            System.out.print(c[k]+" "); 
        }
    }
}
