class A extends Thread
{
    public void run()
    {
        for(int i=1;i<=5;i++)
        {
            if(i==1)    yield();
            System.out.println("From Thread A : i = "+i);
        }
        System.out.println("Exit from A...");
    }
}

class B extends Thread
{
    public void run()
    {
        for(int j=1;j<=5;j++)
        {
            System.out.println("From Thread B : j = "+j);
            if(j==3)    stop();
        }
        System.out.println("Exit from B...");
    }
}

class C extends Thread
{
    public void run()
    {
        for(int k=1;k<=5;k++)
        {
            System.out.println("From Thread C : k = "+k);
            if(k==1)
            try
            {
                sleep(1000);
            }
            catch (Exception e){}
        }
        System.out.println("Exit from C...");
    }
}

class ThreadMethods 
{
    public static void main(String[] args)    
    {
        A T1 = new A();
        B T2 = new B();
        C T3 = new C();
        System.out.println("Start Thread A");
        T1.start();
        System.out.println("Start Thread B");
        T2.start();
        System.out.println("Start Thread C");
        T3.start();
        System.out.println("End of main Thread...");
    }
}
