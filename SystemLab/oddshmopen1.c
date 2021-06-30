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
int main(int argc, char *argv[])
{

    char *a = argv[1];
    int num = atoi(a), temp, odd;
    int shmfd = shm_open("sharedmemory", O_RDWR, 0666);
    ftruncate(shmfd, 4096);
    char *str = mmap(0, 4096, PROT_WRITE, MAP_SHARED, shmfd, 0);
    if (num <= 0)
    {
        printf("\n limit not defined properly\n");
        return 1;
    }
    else
    {
        int i = 1, count = 0;
        while (count != num)
        {
            printf("%d , ", i);
            sprintf(str, "%d\n", i);
            str += strlen(str);
            count++;
            i = i + 2;
        }
    }
    return 0;
}
