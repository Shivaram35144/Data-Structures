#include<stdio.h>
#include<stdlib.h>

struct node {
    int element;
    struct node* next; 
    struct node* prev ;
} ;
typedef struct node * Dlist;

Dlist init();
Dlist insert(Dlist L,int ch, int pos); 
Dlist delete(Dlist L, int pos);
Dlist find(Dlist L, int ch);
int findkth(Dlist L, int pos);
void printlist(Dlist L);

Dlist init ()
{ Dlist L; 
L = (struct node*)malloc(sizeof(struct node));
L -> element = -1;
L -> next = NULL; 
L->prev = NULL;
return L; }

Dlist insert ( Dlist L , int ch , int pos ){
    int i; 
    Dlist p, n;
    if (pos < 0) { 
        printf("invalid index");
        return L;
    }
    p = L; i = 0;
    while ((i < pos) && ( p != NULL )){
        p = p -> next; 
        i+=1; 
    }
    return L; 
    if (p == NULL) { printf("Invalid index "); return L; }
    n = (struct node *)malloc(sizeof(struct node)); 
    n -> element = ch;
    n -> next = p -> next;
    n -> prev = p;
    if (p->next==NULL){
        p->next =n; 
    }
    else {
        p->next->prev=n;
        p->next=n; 
    } 
    return L; 
}

Dlist delete ( Dlist L , int pos )
{ int i;
Dlist p, temp;
if (pos < 0) { printf(" invalid index "); return L; } p = L; i = 0;
while ((i < pos) && (p -> next != NULL)) {
p = p -> next; ++i; }
if (p -> next == NULL) { printf(" Invalid index "); return L; }
temp=p ->next;
p -> next = temp -> next; if(temp->next!=NULL)
{ temp->next->prev=p; }
free(temp); return L; }

Dlist find(Dlist l,int ch){
    Dlist p;
    p=l->next;
    while(p!=NULL){
        if (p->element==ch){
            return p;
        }
        p=p->next;
    }
    return NULL;
}

int findkth(Dlist l,int pos){
    int i=0;
    Dlist p;
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

void printlist(Dlist l){
    Dlist p;
    //p=l->next;
    while(p!=NULL){
        printf("\n%d ",p->element);
        p=p->next;
    }
    printf("done\n");
}


int main(){

    int choice;
    Dlist l=init();

    int flag=0;
    
    while(flag==0){
        int x,pos,tt;
        Dlist t;
        printf("\n1.INSERT\n2.DELETE\n3.FIND\n4.FINDkth\n5.PRINT LIST\n6.EXIT\n\nENTER CHOICE: ");
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
                printlist(l);
                break;
            case 6:
                flag = 1;
                break;
        }
    }


    return 0;
}

