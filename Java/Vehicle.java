interface Moveable{
int AVG_SPEED = 40;
void move();
}
class Vehicle implements Moveable{
public void move() {
System.out.println("Average speed is");
}
public static void main (String[] arg) {
Moveable vc = new Vehicle();
vc.move();
}
}
