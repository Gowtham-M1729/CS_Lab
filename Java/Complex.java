import java.util.Scanner;

class Complex
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        int num;
        double real1=0,real2,imaginary1,imaginary2;
        
        for(;;)
        {
            System.out.print("1.    Add a real number and a complex number.\n");
            System.out.print("2.    Add two complex numbers.\n");
            System.out.print("3.    To Exit.\n");
            int choice = scan.nextInt();
            
            switch(choice)
            {
                case 1:
                
                    System.out.print("Enter an integer : ");
                    num = scan.nextInt();
                    System.out.print("Enter real part for complex number : ");
                    real1 = scan.nextDouble();
                    System.out.print("Enter a imaginary part for first complex number : ");
                    imaginary1 = scan.nextDouble();
                    ComplexNumber comp1 = new ComplexNumber(real1, imaginary1);
                    SumComplexNum result = new SumComplexNum();
                    ComplexNumber comp3 = result.add(num,comp1);
                    System.out.println(comp3.real + " +i" + comp3.imaginary);
                    break;
                
                case 2:
                
                    System.out.print("Enter real part for first complex number : ");
                    num = scan.nextInt();
                    System.out.print("Enter a imaginary part for first complex number : ");
                    imaginary1 = scan.nextDouble();
                    System.out.print("Enter real part for second complex number : ");
                    real2 = scan.nextDouble();
                    System.out.print("Enter imaginary part for second complex number : ");
                    imaginary2 = scan.nextDouble();
                    comp1 = new ComplexNumber(num, imaginary1);
                    ComplexNumber comp2 = new ComplexNumber(real2, imaginary2);
                    result = new SumComplexNum();
                    comp3 = result.add(comp1,comp2);
                    System.out.println(comp3.real + " i" + comp3.imaginary);
                    break;
                
                case 3:
                    
                        System.exit(0);
                    
                default:
                
                    System.out.println("Enter the correct choice...\n");
                
            }
        }
    }
}

class ComplexNumber
{
    double real,imaginary;
    ComplexNumber(double real, double imaginary)
    {
        this.real = real;
        this.imaginary = imaginary;
    }
} 

class SumComplexNum
{
    int number;
    double real,imaginary; 
    
    ComplexNumber add(int number , ComplexNumber comp1)
    {
        comp1.real = comp1.real + number;
        return comp1;
    }

    ComplexNumber add(ComplexNumber comp1 , ComplexNumber comp2)
    {
        comp1.real = comp1.real + comp2.real;
        comp1.imaginary = comp1.imaginary + comp2.imaginary;

        return comp1;
    }
}
