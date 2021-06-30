import java.awt.*;
import java.applet.*;
public class HelloJava extends Applet
{
  public void init() {
    setBackground(Color.blue);
  }
    public void paint(Graphics g)
    {    g.setColor(Color.pink);
        g.drawString("Hello ...",10,100);
         g.setColor(Color.orange);
 g.drawLine(10,10,30,30);
 g.drawLine(80,80,380,380);
 
 g.setColor(Color.red);
 g.fillRect(380,380,100,100);
 
 g.setColor(Color.green);
 g.fillRect(80,80,100,100);
 
 g.draw3DRect(180,180,200,200,true);
    }
}
