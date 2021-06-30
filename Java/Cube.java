import java.util.*;
public class Cube {
    public static void main(String[] args)
    {
        int n,side;
        System.out.println("Enter the no. of cubes you want to create");
        Scanner scan = new Scanner(System.in);
        n = scan.nextInt();
        cube[] CubeArray = new cube[n];

        for(int i=0;i<n;++i)
        {
            System.out.println("Enter side for cube "+(i+1)+" :");
            side = scan.nextInt();
            CubeArray[i] = new cube(side);
        }

        while(true)
        {
            try
            {
                System.out.println("Enter the cube Number");
                int i = scan.nextInt();

                System.out.println(" ");
                System.out.println("Volume of cube " + i + " is " + CubeArray[i - 1].volume());
                System.out.println("Surface area of cube " + i + " is " + CubeArray[i - 1].SurfaceArea());
                System.out.println(" ");
            }
            catch(IndexOutOfBoundsException e)
            {
                System.out.println("Please Enter a valid cube number:");
            }
           System.out.println(" If you want to exit Enter any char E");
               if(scan.next().charAt(0)=='E')
                 System.exit(0);
         
        }
    }
}

class cube
{
    int side;
    cube(int side)
    {
        this.side = side;
    }

    cube()
    {
        side = -1;
    }

    double volume()
    {
        return side*side*side;
    }

    double SurfaceArea()
    {
        return 6*side*side;
    }
}
