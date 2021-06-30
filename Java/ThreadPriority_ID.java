class A extends Thread
{
    public void run()
    {
        System.out.println("Thread A\t Thread ID : "+Thread.currentThread().getId()
        +"\tThread Priority : "+Thread.currentThread().getPriority());
    }
}

class B extends Thread
{
    public void run()
    {
        System.out.println("Thread B\t Thread ID : "+Thread.currentThread().getId()
        +"\tThread Priority : "+Thread.currentThread().getPriority());
    }
}

class C extends Thread
{
    public void run()
    {
        System.out.println("Thread C\t Thread Id : "+Thread.currentThread().getId()
        +"\tThread Priority : "+Thread.currentThread().getPriority());
    }
}

class ThreadPriority_ID 
{
    public static void main(String[] args)    
    {
        A T1 = new A();
        B T2 = new B();
        C T3 = new C();

        T1.setPriority(Thread.MIN_PRIORITY);
        T2.setPriority(Thread.NORM_PRIORITY);
        T3.setPriority(Thread.MAX_PRIORITY);

        System.out.println("Main Thread\t Thread ID : "+Thread.currentThread().getId()
        +"\tThread Priority : "+Thread.currentThread().getPriority());

        T1.start();
        T2.start();
        T3.start();
    }
}
