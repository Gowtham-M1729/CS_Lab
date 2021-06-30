#include <stdio.h>

int main()
{
    int A[2] = {1,2}, *P;
    P = A;
    printf("%d %d",++*P,*P++);
}
