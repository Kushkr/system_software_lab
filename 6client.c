#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/un.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#define shmsize 27
int main()
{
//   char c;
   char *shm,*s;
   int shmid;
   key_t key=2013;
   if((shmid=shmget(key,shmsize,0666))<0)
   {
      perror("shmget");
      exit(1);
   }
   else
  {
   printf("shared memory id id %d\n",shmid);
   if((shm=shmat(shmid,NULL,0))==(char*)-1)
   {
     perror("shmat");
     exit(1);
   }
   printf("shared memory contents\n");
   for(s=shm;*s!='\0';s++)
     putchar(*s);
   putchar('\n');
   *shm='*';
 }
}
