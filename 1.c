#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc,char *argv[])
{
    int i;
    pid_t pid;
    pid=fork();
    if(pid<0)
    {
      printf("Child creation id failed\n");
      exit(-1);
    }
    else if(pid>0)
    {
       wait(NULL);
       printf("process id of child is %d\n",getpid());
       printf("Parent starts\n Even No\n");
       for(i=0;i<=10;i+=2)
         printf("%d\n",i);
       printf("parent ends\n");
    }
    else if(pid==0)
    {
       printf("process id of child is %d\n",getpid());
       printf("process id of parent is %d\n",getppid());
       i=execl(argv[1],argv[2],0);
       printf("child ends\n");
    }
}
