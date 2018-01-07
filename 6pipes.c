#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
   pid_t pid;
   int pfd[2];
   int f1,f2,f3,flag,i,j;
   static unsigned int ar[25],br[25];
   if(pipe(pfd)==-1)
   {
     printf("error in pipes\n");
     exit(-1);
   }
   pid=fork();
   if(pid==0)
   {
      f1=-1;
      f2=1;
      for(i=0;i<25;i++)
      {
        f3=f1+f2;
        printf("%d\n",f3);
        f1=f2;
        f2=f3;
        ar[i]=f3;
      }
      write(pfd[1],ar,25*sizeof(int));
   }
   else if(pid>0)
   {
      wait(NULL);
      read(pfd[0],br,25*sizeof(int));
      printf("parent process will print prime numbers\n");
      for(i=0;i<25;i++)
      {
          flag=0;
          if(br[i]<=1)
            flag=1;
          for(j=1;j<=(br[i]/2);j++)
          {
             if(br[i]%2==0)
             {
               flag=1;
               break; 
             }
          }
          if(flag==0)
              printf("%d\t",br[i]);
      }
      printf("\n");
   }
   else
   {
     printf("process creation failed\n");
     exit(-1);
   }
}
