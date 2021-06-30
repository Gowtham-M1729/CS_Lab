import java.applet.*;
import java.awt.*;
public class RectangleTest extends Applet
{
    int x, y, w, h;
    public void init()
    {
        x = Integer.parseInt(getParameter("Xvalue"));
        y = Integer.parseInt(getParameter("Yvalue"));
        w = Integer.parseInt(getParameter("Wvalue"));
        h = Integer.parseInt(getParameter("Hvalue"));
    }
    public void paint(Graphics g)
    {
        g.drawRect(x, y, w, h);
        g.setColor(Color.pink);
    }
}
