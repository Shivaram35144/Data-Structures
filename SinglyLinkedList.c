#include<stdio.h>
#include<stdlib.h>

struct node{
    int element;
    struct node* next;
};

typedef struct node * llist;

llist init(){
    llist l;
    l=(struct node *)malloc(sizeof(struct node));
    l->element=-1;
    l->next=NULL;

    return l;
}

llist insert(llist l,int ch,int pos){
    int i;
    llist p,n;
    if(pos<0){
        printf("\nInvalid Choice");
        return l;
    }
    p=l;
    i=0;
    while(i<pos && p!=NULL){
        p=p->next;
        i+=1;
    }
    if(p==NULL){
        printf("\nInvalid Index");
        return l;
    }
    n=(struct node *)malloc(sizeof(struct node));
    n->element=ch;
    n->next=p->next;
    p->next=n;
    return l;
}

llist delete(llist l,int pos){
    int i;
    llist p,temp;
    if(pos<0){
        printf("\nInvalid Index");
        return l;
    }
    p=l;i=0;
    while(i<pos && p!=NULL){
        p=p->next;
        i+=1;
    }
    if(p==NULL){
        printf("\nInvalid Index");
        return l;
    }
    temp=p->next;
    p->next=temp->next;
    free(temp);
    return l;
}

void print(llist l){
    llist p;
    p=l->next;
    while(p!=NULL){
        printf("\n%d ",p->element);
        p=p->next;
    }
}

llist find(llist l,int ch){
    llist p;
    p=l->next;
    while(p!=NULL){
        if (p->element==ch){
            return p;
        }
        p=p->next;
    }
    return NULL;
}

int findkth(llist l,int pos){
    int i=0;
    llist p;
    p=l->next;
    while(i<pos && p!=NULL){
        p=p->next;
        i+=1;
    }
    if(p==NULL){
        printf("\nInvalid Index");
        return -1;
    }
    return p->element;
}

void deletelist(llist l){
    llist p,temp;
    p=l->next;
    l->next=NULL;
    while(p!=NULL){
        temp=p;
        p=p->next;
        free(temp);
    }
}

int main(){

    int choice;
    llist l=init();

    int flag=0;
    
    while(flag==0){
        int x,pos,tt;
        llist t;
        printf("\n1.INSERT\n2.DELETE\n3.FIND\n4.FINDkth\n5.DELETELIST\n6.EXIT\n\nENTER CHOICE: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter value to be inserted : ");
                scanf("%d",&x);
                printf("\nEnter pos in which inserted : ");
                scanf("%d",&pos);
                insert(l,x,pos);
                break;
            case 2:
                printf("\nEnter pos in which deleted : ");
                scanf("%d",&pos);
                delete(l,pos);
                break;
            case 3:
                printf("\nEnter value to be found : ");
                scanf("%d",&x);
                t=find(l,x);
                printf("Adderss of given element is %p",t);
                break;
            case 4:
                printf("\nEnter pos to be found : ");
                scanf("%d",&pos);
                tt=findkth(l,pos);
                printf("\nElement in given position is : %d",tt);
                break;
            case 5:
                deletelist(l);
                break;
            case 6:
                flag = 1;
                break;
        }
    }


    return 0;
}