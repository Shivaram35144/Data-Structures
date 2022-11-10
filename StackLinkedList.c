#include<stdio.h>
#include<stdlib.h>

struct node{
    int element;
    struct node* next;
};
typedef struct node * STACK;

int isempty(STACK s); 
STACK create();
void push(STACK s, int x); 
void pop(STACK s);
int topelement(STACK S); 
void display(STACK s);

int isempty(STACK s){
    return s->next==NULL;
}

STACK create() {
    STACK s;
    s= (struct node*)malloc(sizeof(struct node)); 
    s->element=-1;
    s->next = NULL;
    return s;
}

void push(STACK s,int x){
    STACK newnode;
    newnode= (struct node*)malloc(sizeof(struct node)); 
    newnode ->element=x;
    newnode ->next = s->next;
    s->next = newnode;
}

void pop(STACK s) {
    STACK temp;
    if(isempty(s)){ 
        printf("Stack is empty");
    }
    else {
        temp= s->next;
        s->next = temp ->next;
        printf("popped element %d", temp->element); 
        free(temp);
    }
}

int topelement(STACK s)
{
    STACK temp;
    if(!isempty(s))
    {   temp = s->next;
        return temp->element; 
    }
    else {
        printf("stack is empty");
        return -1; 
    }
}

void display(STACK s)
{
    STACK p;
    if(!isempty(s)) {
    printf("\nThe elements in STACK \n"); 
    p=s->next;
    while(p!=NULL){
        printf("\n%d",p->element); 
        p= p->next;
    }
    printf("\n");
    }
    else{
    printf("\n The STACK is empty");}
}

int main(){
    STACK s = create();
    int choice;
    
    int flag =1; 
    while(flag==1){
        int y,top;
        STACK s1;
        printf("1.PUSH\n2.POP\n3.TOP ELEMENT\n4.DISPLAY\n5.EXIT\nENTER CHOICE : ");
        scanf("%d",&choice);
        printf("\n");
        switch(choice){
            case 1:
                
                printf("Enter the elemet : ");
                scanf("%d",&y);
                printf("\n");
                push(s,y);
                break;
            case 2:
                pop(s);
                break;
            case 3:
                top = topelement(s);
                printf("TOP ELEMENT : %d\n",top);
                break;
            case 4:
                display(s);
                break;
            case 5:
                flag=0;
                printf("EXIT POINT\n");
                break;
            default:
                printf("invalid choice\n");
        }
    }
    return 0;
}