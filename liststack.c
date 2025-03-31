#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* top=NULL;
int count=0;

// empty
// Description: checking if stack is empty
// Input: none
// Output: 1 (empty) or 0 (not empty)
int empty(){
    return count==0;
}

// full
// Description: checking if stack is full
// Input: none
// Output: 1 (full) or 0 (not full)
int full(){
    return count==10;
}

// push
// Description: push integer onto stack
// Input: integer
// Output: none
void push(int value){
    Node* new=(Node*)malloc(sizeof(Node));
    (*new).data=value;
    (*new).next=top;
    top=new;
    count++;
}

// pop
// Description: pop integer from stack
// Input: none
// Output: popped integer
int pop(){
    if(empty()){
        return -1;
    }
    
    Node* temp=top;
    int returndata=(*temp).data;
    top=(*top).next;
    free(temp);
    count--;
    
    return returndata;
}

void prints(){
    int num[10]={0};
    int a=count-1;
    printf("Current stack: ");
    
    Node* temp=top;
    while (temp!=NULL){
        num[a--]=(*temp).data;
        temp=(*temp).next;
    }
    
    for (int i=0;i<count;i++){
        printf("%d ",num[i]);
    }
    printf("\n");
}

void main(){
    int n,k;
    while(1){
        printf("Type push integer (pop is -1): ");
        scanf("%d",&n);

        if(n==-1){
            k=pop();
            if(k==-1){
                printf("Already Empty\n");
                break;
            }
            printf("Popped integer: %d\n", k);
        }
        else{
            if(full()){
                printf("Already Full\n");
                break;
            }
            push(n);
        }
        prints();
    }
}
