#include <stdio.h>
const int MAXLEN =5;

typedef struct queuestruct{
    int elements[MAXLEN];
    int front;
    int rear;
    int size;

}QUEUE;

QUEUE init(){
    QUEUE q;
    q.front=0;
    q.rear=-1;
    q.size =0;
    return q;
    
}
int isempty(QUEUE q){
 return q.size==0;
}
int isfull (QUEUE q){
    return q.size==MAXLEN;
}
int front (QUEUE q){
    if(isempty(q)){
        printf("Queue is empty");
        return -1;
    }
    else return q.elements[q.front];
}
QUEUE enqueue (QUEUE q, int m) {
    if(isfull(q)){
        printf("Queue is full\n");
        return q;
    }
    else{
        printf("Size : %d\n",q.size);
        q.rear=(q.rear+1)%MAXLEN;
        q.elements[q.rear]=m;
        q.size++;
        printf("Size : %d\n",q.size);
        return q;

    }
}
QUEUE dequeue (QUEUE q) {
    if(isempty(q)){
        printf("Queue is empty\n");
        return q;
    }
    else{
        printf("dequeued element is %d\n",front(q));
        q.front=(q.front+1 )% MAXLEN;
        q.size--;
        return q;
    }

}
void display (QUEUE q) {
    if(isempty(q)){
        printf("Queue is empty");

    }
    else{
        int i=q.front;
        while(1){
            printf("%d\n",q.elements[i]);
            if(i==q.rear){
                break;
            }
            i=(i+1)%MAXLEN;

        }

    }
}



int main(){

    int c;
    
    QUEUE q=init();
    
    int m,fr,flag=1;
    while(flag==1){
        printf("1.Enqueue\n2.Dequeue\n3.Front element\n4.DISPLAY\n5.EXIT\n");
        printf("Enter the Choice:");
        scanf("%d",&c);
    switch(c){
        case 1:
            
            printf("Enter the Element:");
            scanf("%d",&m);
            q=enqueue(q,m);
            break;
            
        case 2:
            q=dequeue(q);
            break;
        case 3:
            fr=front(q);
            printf("Element at the front of the queue : %d\n",fr);
            break;
        case 4:
            display(q);
            break;
        case 5:
            printf("EXIT POINT");
            flag=0;
            break;
        default:
            printf("Enter valid choice");
        
    }
    }

    return 0;

}

