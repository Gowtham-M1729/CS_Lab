class pyramid
{
    synchronized void draw_pyramid(char c)
    {
        for(int i=0;i<10;i+=2)
        {
            for(int k=10-i;k>0;k-=2)
                System.out.print(" ");
            
            for(int j=0;j<=i;j++)
                System.out.print(c);

            System.out.println();
        }
    }
}

class A extends Thread
{
    pyramid p1;
    A(pyramid p1)
    {
        this.p1=p1;
    }
    public void run()
    {
        p1.draw_pyramid('*');
    }
}

class B extends Thread
{
    pyramid p2;
    B(pyramid p2)
    {
        this.p2=p2;
    }
    public void run()
    {
        p2.draw_pyramid('#');
    }
}

class SyncTest 
{
    public static void main(String[] args)    
    {
        pyramid p = new pyramid();
        A t1 = new A(p);
        B t2 = new B(p);
        
        t1.start();
        t2.start();
    }
}
