#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>
int main()
{
    int i, a[20], n;
    int shmfd = shm_open("sharedmemory", O_RDWR, 0666);
    ftruncate(shmfd, 4096);
    char *str = mmap(0, 4096, PROT_WRITE, MAP_SHARED, shmfd, 0);
    printf("Enter range required\n");
    scanf("%d", &n);
    printf("enter the array elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int largest = a[0];

    for (i = 1; i < n; i++)

    {

        if (largest < a[i])

            largest = a[i];
    }
    sprintf(str, "%d\t", largest);

    return 0;
}
