// An abstract class with constructor 
abstract class Base { 
	Base() { System.out.println("Base Constructor Called"); } 
	abstract void fun(); 
         {System.out.println("Derived fun() called");}
} 
class Derived extends Base { 
	Derived() { System.out.println("Derived Constructor Called"); }
	void fun() { System.out.println("Derived1111 fun() called"); } 
} 
class Main1 { 
	public static void main(String args[]) { 
	Base d = new Derived(); 
        //d.fun();
	} 
} 

