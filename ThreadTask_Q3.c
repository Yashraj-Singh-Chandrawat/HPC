#include<stdio.h>
#include <pthread.h>
#include <time.h>


 int arr1[1000][1000]; // global array 
 int arr2[1000][1000];
 int result[1000][1000];
 struct arrinput{
    int st;
    int end;
  
 };

 void *addMatrix(void * input){

    struct arrinput *n= input;

    for(int i=n->st;i<n->end;i++){

    for(int j=0;j<1000;j++){
  
        result[i][j]=arr1[i][j]+arr2[i][j];

    }

    }
    
   return NULL;
 }

 int main(){

     struct timespec start, end;
double time_taken;
clock_gettime(CLOCK_MONOTONIC, &start);

    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            arr1[i][j]=j;
            arr2[i][j]=j;
        }
       
     }
 

    struct arrinput n1,n2,n3,n4;
   n1.st=0;
   n1.end=250;

   n2.st=250;
   n2.end=500;

   n3.st=500;
   n3.end=750;

   n4.st=750;
   n4.end=1000;

  pthread_t thread1, thread2,thread3,thread4;

    pthread_create(&thread1,NULL,addMatrix,&n1);
    pthread_create(&thread2,NULL,addMatrix,&n2);
    pthread_create(&thread3,NULL,addMatrix,&n3);
    pthread_create(&thread4,NULL,addMatrix,&n4);


     pthread_join(thread1,NULL);
     pthread_join(thread2,NULL);
     pthread_join(thread3,NULL);
     pthread_join(thread4,NULL);


     for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            printf("%d ",result[i][j]);
        }
        printf("\n");
     }
 clock_gettime(CLOCK_MONOTONIC, &end);
 time_taken = (end.tv_sec - start.tv_sec)
           + (end.tv_nsec - start.tv_nsec) / 1e9;

   printf("\nTime taken = %f seconds\n", time_taken);

 }