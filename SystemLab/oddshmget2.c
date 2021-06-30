    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/shm.h>
    #include <unistd.h>
    #include<string.h>
    int main(int argc,char *argv[])
    {

        char *a = argv[1];
        int num = atoi(a),temp;
        key_t key = ftok("shmfile",65);
        // shmget returns an identifier in shmid
        int shmid = shmget(key,1024,0666|IPC_CREAT);
        // shmat to attach to shared memory
        char *str = (char*) shmat(shmid,(void*)0,0);
            if(num<=0)
            {
            printf("\n limit not defined properly\n");
            return 1;
            }
            else
            {
            int i=1,count=0;
            while(count!=num)
            {
            printf("%d , ",i);
            sprintf(str,"%d\n",i);
            str+=strlen(str);
            count++;
            i=i+2;
            }
            }
        
        return 0;
    }	

