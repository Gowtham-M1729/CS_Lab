public class main{
    public static void main(String args[]) {
       mallard m=new mallard();
       redhead r=new redhead();
       rduck f=new rduck();
       m.ma();
       r.re();
       f.rd();
       }
}
abstract class Duck{
    void swim()
    {
        System.out.println("Bird is swimming");
    }
    void sound()
    {
        System.out.println("Quack....quack...quack...");
    }
    void identity()
    {
        
    }
    abstract void fly();
}
class mallard extends Duck{
    void ma(){
       System.out.println("MALLARD DUCK SIMULATION:");
       swim();
       sound();
       fly();
    }
    void fly()
    {
        System.out.println("Duck is flying");
    }
}
class redhead extends Duck{
    void re(){
       System.out.println("REDHEAD DUCK SIMULATION:");
       swim();
       sound();
       fly();
    }
    void fly()
    {
        System.out.println("Duck is flying");
    }
}
class rduck extends Duck{
    void rd(){
               System.out.println("RUBBER DUCK SIMULATION:");
         swim();
         sound();
         fly();
    }
          void fly(){
            System.out.println("not flying");
            }
}
