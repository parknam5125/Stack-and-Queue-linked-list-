#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;
Node node[10];
int count=0;
Node* front=&node[0];
Node* rear=&node[1];
void init(){
    for(int i=0;i<10;i++){
        node[i].next=&node[(i+1)%10];
    }
}

//empty
//Description: checking queue is empty
//Input: none
//Output: 1(empty) or 0(no empty) 
int empty(){
    return count==0;
}

//full
//Description: checking queue is full
//Input: none
//Output: 1(full) or 0(no full)
int full(){
    return count==10;
}

//enqueue
//Description: enqueue integer into queue
//Input: integer
//Output: none
void enqueue(int value){
    if(empty()){
        (*front).data=value;
        count++;
        return;
    }
    (*rear).data=value;
    rear=(*rear).next;
    count++;
}

//dequeue
//Description: dequeue integer from queue
//Input: none
//Output: dequeued integer
int dequeue(){
    if(empty()){
        return -1;
    }
    int temp;

    temp=(*front).data;
    front=(*front).next;
    count--;

    return temp;
}

void printq(){
    printf("Current Queue: ");
    Node* tempfront=front;
    Node* temprear=rear;
    while(tempfront!=temprear){
        printf("%d ",(*tempfront).data);
        tempfront=(*tempfront).next;
    }
    if((tempfront==temprear)&&count==10){
        for(int i=0;i<10;i++){
            printf("%d ",(*tempfront).data);
            tempfront=(*tempfront).next;
        }
    }
    if((front==rear)&&count==0){
        rear=(*rear).next;
    }
    printf("\n");
}

void main(){
    int n,k;
    init();
    while(1){
        printf("Type enqueue integer(dequeue is -1): ");
        scanf("%d",&n);
        if(n==-1){
            k=dequeue();
            if(k==-1){
                printf("Already Empty");
                break;
            }
        }
        else{
            if(full()){
                printf("Already Full\n");
                break;
            }
            enqueue(n);
        }
        printq();

    }
}