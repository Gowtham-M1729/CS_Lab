import MyPack.*;

class Account 
{
	public static void main(String[] args)
	{
		Balance acc[] = new Balance[3];
		
		acc[0]=new Balance("Manoj Kumar C",1000);
		acc[1]=new Balance("Rakshitha C",2000);
		acc[2]=new Balance("Manjula S",3000);

		for(int i=0;i<3;i++)
		{
			acc[i].show();
		}
	}
}
