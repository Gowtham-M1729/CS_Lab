import java.applet.Applet;
import java.awt.*;

public class a extends Applet {
	TextField text1, text2;
        Button b1;  
	public void init()
	{
		text1 = new TextField(10);
		text2 = new TextField(10);
		text1.setText("0");
		text2.setText("0");
		add(text1);
		add(text2);
                b1=new Button("Click");  
                b1.setBounds(80,150,60,50);
                add(b1);
	}
	public void paint(Graphics g) {
		int num1 = 0;
		int num2 = 0;
		int sum;
		String s1, s2, s3;

		g.drawString("Input a number in each box ", 10, 50);
		try {
			s1 = text1.getText();
			num1 = Integer.parseInt(s1);
			s2 = text2.getText();
			num2 = Integer.parseInt(s2);
		}
		catch(Exception e1)
		{}
        sum = num1 + num2;
        int a=gcd(num1 ,num2);
        int b=num1*num2/a;
         //if(b1==true)
         {
        String str = "THE SUM IS: "+String.valueOf(sum);
         String str1 = "THE GCD IS: "+String.valueOf(a);
          g.drawString (str,100, 125);
         String str2 = "THE LCM IS: "+String.valueOf(b);
          g.drawString (str2,100, 150);
          g.drawString (str1,100, 175);
          }
     }
     public boolean action(Event ev, Object obj)
     {
         repaint();
         return true;
     }
     int gcd(int num1, int num2)
          {
              if (num2 == 0)
                 return num1;
              return gcd(num2, num1 % num2); 
         }
 }
 
