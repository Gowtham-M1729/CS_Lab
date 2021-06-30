import java.util.Scanner;
class Geeksfg {
        Scanner myObj = new Scanner(System.in);
	
	/*public static void concat(StringBuffer s1)
	{       StringBuffer[] a = str.split(" ", 2);
		s1 = a[0] + "Oriented" + a[1];
	}*/

	
	public static void main(String[] args)
	{       Scanner myObj = new Scanner(System.in);
		String s1 = myObj.nextLine();
		System.out.println("String: " + s1);

		StringBuffer s2 = new StringBuffer(s1);
                int k=s2.indexOf(" ");
		//concat(s2);
                s2.insert(k+1,"Oriented " );
		System.out.println("StringBuffer: " + s2+"   "+k);
                String str = s2.toString();
                SubStringCons.ops();
                String[] arr=s1.split(" ");
                for(String j:arr)
                   System.out.print(j+"\t");
                char[] arr1=s1.toCharArray();
                for(char l:arr1)
                      System.out.print(l+"\t");

	}
   
}
class SubStringCons {
public static void ops()
{
byte ascii[] = {65, 66, 67, 68, 69, 70 };
String s1 = new String(ascii);
System.out.println(s1);
String s2 = new String(ascii, 2, 3);
System.out.println(s2);
}
}

