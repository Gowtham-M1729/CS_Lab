import java.util.*;  
public class List1{  
public static void main(String args[]){
  Scanner scan = new Scanner(System.in);  
 //Creating a List  
 List<String> list=new ArrayList<String>();   
 list.add("Mango");  
 list.add("Apple");  
 list.add("Banana");  
 list.add("Grapes");
 String s=scan.nextLine();
 list.add(s);   
 for(String fruit:list)  
  System.out.println(fruit);  
  
}
//char a[][] = new char[10][10];
//for (j = 1; j<= 5; j++)
//a[j][10]=scan.nextLine();
//List<String> list=new ArrayList<String>(); 
//list.add(scan.nextLine());
//String[] array = list.toArray(new String[list.size()]);
}  
