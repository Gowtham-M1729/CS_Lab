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
    const int SIZE 4096;
/* name of the shared memory object */
    const char *name = "OS";
/* strings written to shared memory */
    const char *message0 = "Hello";
    const char *message1 = "World!";
/* shared memory file descriptor */
    int shm fd;
/* pointer to shared memory obect */
    void *ptr;
/* create the shared memory object */
    shm fd = shm open(name, O CREAT | O RDRW, 0666);
    
/* configure the size of the shared memory object */
    ftruncate(shm fd, SIZE);
    
/* memory map the shared memory object */
    ptr = mmap(0, SIZE, PROT WRITE, MAP SHARED, shm fd, 0);
    
/* write to the shared memory object */
    sprintf(ptr,"%s",message0);
    
ptr += strlen(message0);
sprintf(ptr,"%s",message1);
ptr += strlen(message1);
return 0;
}
