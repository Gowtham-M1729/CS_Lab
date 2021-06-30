#include <iostream>
using namespace std;
int m,u,v,c=0;
int maxsimum(int a[], int l, int r) {
    //c++;
    //cout << m<<"-"<<u<<"-"<<v<<"  "<<l<<"---"<<r<< endl;
   if (r-l==1)
   {  c++;
      return a[l];
   }
   int m=(l+r)/2;
   int u=maxsimum(a,l,m);
   int v=maxsimum(a,m,r);
     cout <<"###   "<<u<<"    "<<v<< endl; 
    return u>v?u:v;    
}

int main() {
    int a[] = {34,35,36,1,4,42,0};
    int n = sizeof(a)/sizeof(int);
    cout <<n<<'\n'<< maxsimum(a,0,n) <<"count is"<<c<< endl;         
    return 0;
}
