#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<sys/mman.h>
int main()
{
/* the size (in bytes) of shared memory object */
    int SIZE=4096;
/* name of the shared memory object */
   const char *name = "OS";
/* shared memory file descriptor */
   int shm fd;
/* pointer to shared memory obect */
   void *ptr;
/* open the shared memory object */
   shm fd = shm open(name, O RDONLY, 0666);
/* memory map the shared memory object */
   ptr = mmap(0, SIZE, PROT READ, MAP SHARED, shm fd, 0);
/* read from the shared memory object */
   printf("%s",(char *)ptr);
/* remove the shared memory object */
   shm unlink(name);
return 0;
}
