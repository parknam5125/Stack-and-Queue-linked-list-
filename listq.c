#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* front=NULL;
Node* rear=NULL;
int count=0;

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
    Node* new=(Node*)malloc(sizeof(Node));
    
    (*new).data=value;
    (*new).next=NULL;

    if(empty()){
        front=new;
        rear=new;
    }

    else{
        (*rear).next=new;
        rear=new;
    }
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
    
    Node* temp=front;
    int returndata=(*temp).data;
    front=(*front).next;

    free(temp);
    count--;

    if(empty()){
        front=NULL;
        rear=NULL;
    }
    
    return returndata;
}

void printq(){
    printf("current queue: ");
    Node* temp=front;
    while(temp!=NULL){
        printf("%d ", (*temp).data);
        temp=(*temp).next;
    }
    printf("\n");
}

void main(){
    int n,k;
    while(1){
        printf("Type enqueue integer (dequeue is -1): ");
        scanf("%d",&n);

        if(n==-1){
            k=dequeue();
            if(k==-1){
                printf("Already Empty\n");
                break;
            }
            printf("Dequeued integer: %d\n", k);
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