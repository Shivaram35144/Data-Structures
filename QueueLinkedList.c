#include<stdio.h>
#include<stdlib.h>

struct rec {
    int element;
    struct rec * next;
};

struct q_rec{
    struct rec* front;
    struct rec* rear;
};
typedef struct q_rec queue;

queue init();
int isempty(queue Q);
int front(queue Q);
queue enqueue(queue Q, int x); 
queue dequeue(queue Q);
void display(queue Q);

queue init() {
queue Q; Q.front = NULL; Q.rear = NULL; return Q;
}
int isempty(queue Q)
{
return (Q.front==NULL); }

queue enqueue(queue Q, int x)
{
    struct rec* newnode;
    newnode=(struct rec*)malloc(sizeof(struct rec)); newnode->element = x;
    newnode->next = NULL;
    if(Q.rear==NULL)
    { Q.rear = newnode; Q.front = newnode; }
    else
    { Q.rear->next=newnode;
    Q.rear =newnode; } return Q;
}

int front(queue Q) {
if (isempty(Q))
{
printf("\nQueue is empty\n"); return -1;
} else
return Q.front->element; }

queue dequeue(queue Q)
{ struct rec* temp;
if(isempty(Q)) {
printf("\nQueue is empty\n"); return Q;
}
else {
printf(" dequeued element %d", Q.front->element); temp=Q.front;
if(Q.front==Q.rear)
{ Q.front = NULL; Q.rear = NULL; }
else
{ Q.front= Q.front->next; }
free(temp); return Q;
}
}

void display(queue Q)
{
    struct rec* p;
    if(isempty(Q)) {
        printf("\nQueue is empty\n"); 
    }
    else {
        p=Q.front;
        while(p!=NULL) {
            printf("\n%d", p->element); 
            p=p->next;
        }
    }
}

int main(){

    int c;
    
    queue q=init();
    
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
