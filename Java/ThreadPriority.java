class A extends Thread 
{
    public void run()
    {
        System.out.println("Thread A started...");
        for(int i=1;i<=4;i++)
        {
            System.out.println("From thread A : i = "+i);
        }
        System.out.println("Exit from A...");
    }
}

class B extends Thread 
{
    public void run()
    {
        System.out.println("Thread B started...");
        for(int j=1;j<=4;j++)
        {
            System.out.println("From thread B : j = "+j);
        }
        System.out.println("Exit from B...");
    }
}

class C extends Thread
{
    public void run()
    {
        System.out.println("Thread C started...");
        for(int k=1;k<=4;k++)
        {
            System.out.println("From Thread C : k = "+k);
        }
        System.out.println("Exit from C...");
    }
}

class ThreadPriority 
{
    public static void main(String[] args)
    {
        A T1 = new A();
        B T2 = new B();
        C T3 = new C();

        T3.setPriority(Thread.MIN_PRIORITY);
        T2.setPriority(T1.getPriority()+1);
        T1.setPriority(Thread.MIN_PRIORITY);

        System.out.println("Start Thread A");
        T1.start();
        System.out.println("Start Thread B");
        T2.start();
        System.out.println("Start Thread C");
        T3.start();
        System.out.println("End of main Thread");
    }
}
