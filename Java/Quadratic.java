class Quadratic { 
        static void fib(int a,int b,int c) 
          {
              if(b*b-4*a*c<0)
                { System.out.println("Roots are Imaginary");
                  if(b!=0)
                  System.out.println(-1*b/2 +"+i"+Math.sqrt(Math.abs(b*b-4*a*c))/2+"  and  "+-1*b/2 +"-i"+Math.sqrt(Math.abs(b*b-4*a*c)));
                  else
                   System.out.println("i"+Math.sqrt(Math.abs(b*b-4*a*c))/2 + "   and    " + "-i" + Math.sqrt(Math.abs(b*b-4*a*c))/2);
                }
               if(b*b-4*a*c>0)
                { System.out.println("Roots are Real and Distinct");
                  if(b!=0)
                   System.out.println(-1*b/2+"+"+Math.sqrt((b*b-4*a*c))/2+"   and  "+-1*b/2 +"-"+Math.sqrt((b*b-4*a*c))/2);
                  else
                    System.out.println(Math.sqrt((b*b-4*a*c))/2+"   and    "+ "-"+Math.sqrt((b*b-4*a*c))/2);
                }
               if(b*b-4*a*c==0)
                { System.out.println("Roots are Real and Equal");
                  System.out.println(-1*b/2+" and "+-1*b/2 );
                }
	
          }
	public static void main(String args[]) 
	{       int i;
		int a = Integer.parseInt(args[0]);
                int b = Integer.parseInt(args[1]);
                int c = Integer.parseInt(args[2]); 
		fib(a,b,c);
	} 
}
