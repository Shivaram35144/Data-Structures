#include<stdio.h>
const int MAXELEMENT = 100;

struct stackrecord{
    
    int top;
    int x[MAXELEMENT];
};

typedef struct stackrecord STACK;

int isempty(STACK s){
    return s.top ==-1;
}

int isfull(STACK s){
    return s.top==MAXELEMENT-1;
}

STACK create(){
    STACK s;
    s.top=-1;
    return s;
}

STACK push(STACK s,int y){
    if(isfull(s)){
        printf("STACK IS FULL\n");
    }
    else{
        ++s.top;
        s.x[s.top]=y;
        printf("Done!\n\n");
    }
    return s;
}

STACK pop(STACK s){
    if(isempty(s)){
        printf("STACK IS EMPTY\n");
    }
    else{
        printf("Value popped is %d\n",s.x[s.top]);
        s.top--;
    }
    return s;
}

int topelement(STACK s){
    if(isempty(s)){
        printf("STACK IS EMPTY\n");
        return -1;
    }
    else{
        printf("top element is %d\n",s.x[s.top]);
        return s.top;
    }
    return s.top;
}

void display(STACK s){
    for(int i=s.top;i>=0;i--){
        printf("%d\n",s.x[i]);
    }
}

int main(){
    STACK s = create();
    int choice;
    
    int flag =1; 
    while(flag==1){
        int y,top;
        //STACK s1;
        printf("1.PUSH\n2.POP\n3.TOP ELEMENT\n4.DISPLAY\n5.EXIT\nENTER CHOICE : ");
        scanf("%d",&choice);
        printf("\n");
        switch(choice){
            case 1:
                
                printf("Enter the elemet : ");
                scanf("%d",&y);
                printf("\n");
                s = push(s,y);
                break;
            case 2:
                s= pop(s);
                break;
            case 3:
                top = topelement(s);
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