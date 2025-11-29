#define BUFFERSIZE 10
#include <stdio.h>
#include<stdio.h>

int n,item ,item1;
int mutex,empty,full=0;
int in,out;
int buffer[20];

void wait(int s){
    while(s<0);
    s--;
}

void signall(int s){
    s++;
}


void producer(){
    do{
        wait(empty);
        wait(mutex);
        printf("Enter the items");
        scanf("%d",&item);
        buffer[in] = item;
        in=in+1;
        signall(mutex);
        signall(full);
    }
    while(in<n);
}


void consumer(){
    do{
        wait(full);
        wait(mutex);
        item1=buffer[out];
        printf("The consumed is %d\n",item1);
        out=out+1;
        signall(mutex);
        signall(empty);
        
    }
    while(out<n);
}

void main(){
    printf("Enter the value of n");
    scanf("%d", &n);
    empty=n;
    
    while(in<n){
        producer();
    }
    while(in!=out){
        consumer();
    }
}
