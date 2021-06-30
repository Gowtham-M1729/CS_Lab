class Super_class
 {
 int num=20;
 public void display()
   {
 System.out.println("This is the display method of superclass");
   }
}
class sub_class extends Super_class 
 {
 int num=10;

 public void display()
  {
 System.out.println("This is the display method of subclass");
  }

 public void my_method()
  {
 //sub_class b=new sub_class ();
 display();
 super.display();
 System.out.println("value of the variable named num in sub class:"+ num);
 System.out.println("value of the variable named num in super class:"+ super.num);
  } 
 }
class A 
{
 public static void main(String args[])
  {
 sub_class obj = new sub_class();
 obj.my_method(); 
  } 
}
