class TwoDAgain {
public static void main(String args[]) {
int twoD[][] = new int[4][];
/*twoD[0] = new int[1];
twoD[1] = new int[2];
twoD[2] = new int[3];
twoD[3] = new int[4];*/
int i, j, k = 0;
for(i=0; i<4; i++)
{ twoD[i] = new int[2*(i+1)];
for(j=0; j<2*(i+1); j++) {
twoD[i][j] = k;
k++;
}
}
for (int[] a : twoD)
      {
         for (int l : a)
         {
            System.out.print(l + " ");
         }
       System.out.println();
      }

}
}
