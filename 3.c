#include <stdlib.h>

int main()
{
   int smallest,count=0,time,limit,i,arr[10],burst[10],temp[10];
   double end=0,turn=0,wait=0;
   float avg_w,avg_t;
   printf("\nenter the number of processes\n");
   scanf("%d",&limit);
   printf("enter the data\n");
   for(i=0;i<limit;i++)
   {
     printf("enter arrival time\n");
     scanf("%d",&arr[i]);
     printf("enter burst time\n");
     scanf("%d",&burst[i]);
     temp[i]=burst[i];
   }
   burst[9]=9999;
   for(time=0;count!=limit;time++)
   {
     smallest=9;
     for(i=0;i<limit;i++)
     {
       if(arr[i]<=time && burst[i]<burst[smallest] && burst[i]>0)
         smallest=i;
     }
   
   printf("P%d|",smallest);
   burst[smallest]--;
   if(burst[smallest]==0)
   {
     count++;
     end=time+1;
     wait=wait+end-arr[smallest]-temp[smallest];
     turn=turn+end-arr[smallest];
   }
  } 
  avg_w=(wait/limit);
  avg_t=(turn/limit);
   printf("%lf is average waiting time\n",avg_w);
    printf("%lf is average turn around  time\n",avg_t);
   return 0;
}
