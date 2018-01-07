#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/un.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#define shmsize 27
int main()
{
   char c;
   char *shm,*s;
   int shmid;
   key_t key=2013;
   if((shmid=shmget(key,shmsize,IPC_CREAT|0666))<0)
   {
      perror("shmget");
      exit(1);
   }
   printf("shared memory id id %d\n",shmid);
   if((shm=shmat(shmid,NULL,0))==(char*)-1)
   {
     perror("shmat");
     exit(1);
   }
   memset(shm,0,shmsize);
   s=shm;
   printf("writing (a-z) to shared memory\n");
   for(c='a';c<='z';c++)
   {
     *s++=c;
   }
   *s='\0';

  while(*shm!='*');
  printf("client finished reading\n");

  if(shmdt(shm)!=0)
   fprintf(stderr,"could not close memory segment\n");
   shmctl(shmid,IPC_RMID,0);
}
