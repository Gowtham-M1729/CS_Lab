class MyClass extends Parent implements Interface {
  public static void main(String[] args) {
    MyClass ob =new MyClass();
    ob.new1();
    ob.mat();

  }
  public void new1(){
    System.out.println("Hi-Method of interface");
  }

}
class Parent{
  static int a=100;
  void mat(){
    System.out.println("Hi--Method of Parent class");
  }
}
interface Interface  {
  void new1();

}
