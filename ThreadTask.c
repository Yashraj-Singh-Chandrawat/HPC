#include<stdio.h>
#include <pthread.h>
#include <time.h>

 int arr[10000]; // global array 
 struct arrinput{
    int st;
    int end;
    int sum;
    int max; 
    int min;
    int evencount;
 };


  int findsum(int arr[], int length){
   
    int sum =0;
    for(int i=0;i<length;i++)
     sum+=arr[i];

     return sum;
  }

  int findmin(int arr[],int length){
     
    int min=arr[0];

     for(int i=1;i<length;i++)
     if(min>arr[i]) min=arr[i];

      return min;
  }


  int findmax(int arr[],int length){
   
    int max=arr[0];
     for(int i=1;i<length;i++)
     if(max<arr[i]) max=arr[i];

      return max;
  
  }


   int evencount(int arr[],int length){
   int count =0;
   for(int i=0;i<length;i++){
      if(!(arr[i]%2)) count++;

   }
   return count ;

  }


  void*  findsumt(void * data){
   
   struct arrinput *temp= data;
   int sum=0;

   for(int i=temp->st;i<temp->end;i++)
   sum+=arr[i];
     
   temp->sum=sum;
 return NULL;
  }


  void* findmaxt(void * data){
   
   struct arrinput *temp= data;
   int max=arr[temp->st];

 //printf(" my work is from  %d to %d \n",temp->st,temp->end);

   for(int i=temp->st;i<temp->end;i++)
   if(max<arr[i])max=arr[i];
     
   temp->max=max;
   //printf("\ntask done saving value of max = %d",temp->max);
 return NULL;
  }

   void* findmint(void * data){
   
   struct arrinput *temp= data;
   int min=arr[temp->st];

   for(int i=temp->st;i<temp->end;i++)
   if(min>arr[i])min=arr[i];
     
   temp->min=min;
  return NULL;
  }

  void* countevent(void * data){
   
   struct arrinput *temp= data;
   int count=0;

   for(int i=temp->st;i<temp->end;i++)
   if(!(arr[i]%2))count ++;
     
   temp->evencount=count;
 
   return NULL;
  }




int main(){


 struct timespec start, end;
double time_taken;
clock_gettime(CLOCK_MONOTONIC, &start);
   
    // putting random values inside the arr array
   for(int i=0;i<10000;i++)
   arr[i]=i%50;

   //  creating data input for different Threads
   struct arrinput n1,n2,n3,n4;
   n1.st=0;
   n1.end=10;

   n2.st=10;
   n2.end=5000;

   n3.st=5000;
   n3.end=7500;

   n4.st=7500;
   n4.end=10000;
// task done
   
// creating thread variables
    pthread_t thread1, thread2,thread3,thread4;

    pthread_create(&thread1,NULL,findmaxt,&n1);
    pthread_create(&thread2,NULL,findmaxt,&n2);
    pthread_create(&thread3,NULL,findmaxt,&n3);
    pthread_create(&thread4,NULL,findmaxt,&n4);

     pthread_join(thread1,NULL);
     pthread_join(thread2,NULL);
     pthread_join(thread3,NULL);
     pthread_join(thread4,NULL);

     
    pthread_create(&thread1,NULL,findmint,&n1);
    pthread_create(&thread2,NULL,findmint,&n2);
    pthread_create(&thread3,NULL,findmint,&n3);
    pthread_create(&thread4,NULL,findmint,&n4);

    
     pthread_join(thread1,NULL);
     pthread_join(thread2,NULL);
     pthread_join(thread3,NULL);
     pthread_join(thread4,NULL);

    pthread_create(&thread1,NULL,findsumt,&n1);
    pthread_create(&thread2,NULL,findsumt,&n2);
    pthread_create(&thread3,NULL,findsumt,&n3);
    pthread_create(&thread4,NULL,findsumt,&n4);

     pthread_join(thread1,NULL);
     pthread_join(thread2,NULL);
     pthread_join(thread3,NULL);
     pthread_join(thread4,NULL);

    pthread_create(&thread1,NULL,countevent,&n1);
    pthread_create(&thread2,NULL,countevent,&n2);
    pthread_create(&thread3,NULL,countevent,&n3);
    pthread_create(&thread4,NULL,countevent,&n4);
    
     pthread_join(thread2,NULL);
     pthread_join(thread3,NULL);
     pthread_join(thread4,NULL);

    
     printf("\nMax of tsk 1 is %d ",n1.max);
     printf("\nMax of tsk 2 is %d ",n2.max);
     printf("\nMax of tsk 3 is %d ",n3.max);
     printf("\nMax of tsk 4 is %d ",n4.max);


    printf("\nMIN of tsk 1 is %d ",n1.min);
     printf("\nMIN of tsk 2 is %d ",n2.min);
     printf("\nMIN of tsk 3 is %d ",n3.min);
     printf("\nMIN of tsk 4 is %d ",n4.min);


     printf("\nSUM of tsk 1 is %d ",n1.sum);
     printf("\nSUM of tsk 2 is %d ",n2.sum);
     printf("\nSUM of tsk 3 is %d ",n3.sum);
     printf("\nSUM of tsk 4 is %d ",n4.sum);

     printf("\nEVEN COUNT of tsk 1 is %d ",n1.evencount);
     printf("\nEVEN COUNT of tsk 2 is %d ",n2.evencount);
     printf("\nEVEN COUNT of tsk 3 is %d ",n3.evencount);
     printf("\nEVEN COUNT of tsk 4 is %d ",n4.evencount);

   clock_gettime(CLOCK_MONOTONIC, &end);
   time_taken = (end.tv_sec - start.tv_sec)
           + (end.tv_nsec - start.tv_nsec) / 1e9;

   printf("\nTime taken = %f seconds\n", time_taken);
   

    return 0;
}