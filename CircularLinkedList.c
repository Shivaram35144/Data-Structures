#include <stdio.h>
#include <stdlib.h>

struct node{
    int element;
    struct node* next;
    
};
typedef struct node * clist;

clist init();
clist insert(clist L,int ch, int pos); 
clist delete(clist L, int pos);
clist find(clist L, int ch);
int findkth(clist L, int pos); 
void printlist(clist L);
void deletelist(clist L);

clist init () {
    clist L; 
    L = (struct node *)malloc(sizeof(struct node)); 
    L -> element = -1;
    L -> next = L;
    return L; 
}

clist insert ( clist L , int ch , int pos ){
    int i;
    clist p, n;
    if (pos < 0) { 
        printf("invalid index"); 
        return L; } 
    p = L; i = 0;
    while ((i < pos) && (( p !=L )|| (i==0))) 
    {
        p = p -> next; 
        i+=1; 
    }
    if (( p ==L )&&(i != 0)){
        printf("invalid index");
        return L; 
    }
    n = (struct node*)malloc(sizeof(struct node));
    n -> element = ch;
    n -> next = p -> next;
    p -> next = n;
    return L; 
}

clist delete ( clist L , int pos )
{ int i;
clist p, temp;
if (pos < 0) { 
    printf("invalid index"); 
    return L; 
}
p = L; i = 0;
while((i<pos) && (p->next!=L)){
    p = p -> next;
    i+=1; 
}
if (p -> next ==L) { 
    printf("Invalid index "); 
    return L; 
}
temp = p ->next;
p -> next = temp -> next;
free(temp); return L; 
}

clist find( clist L , int ch )
{
clist p;
p = L -> next; while (p !=L) {
if (p -> element == ch) return p;
p = p -> next; }
return NULL;
}

int findkth ( clist L , int pos )
{ int i; clist p;
i = 0;
p = L -> next;
while ((i < pos) && (p !=L)) {
p = p -> next;
++i; }
if (p == L) {
printf("Invalid index"); return -1; }
return p -> element; }

void printlist(clist l){
    clist c=l->next;
    printf("%d ",l->element);
    while(c!=l){
    printf("%d ",c->element);
    c=c->next;}
    printf("\n");
}

void deletelist(clist l){
    clist p,temp;
    p=l->next;
    
    while(p!=l){
        temp=p;
        p=p->next;
        free(temp);
    }
    l->next=NULL;
}


int main(){
    int choice;
    clist l=init();

    int flag=0;
    
    while(flag==0){
        int x,pos,tt;
        clist t;
        printf("\n1.INSERT\n2.DELETE\n3.FIND\n4.FINDkth\n5.PRINT LIST\n6.DELETELIST\n7.EXIT\n\nENTER CHOICE: ");
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
                //deletelist(l);
                break;
            case 7:
                flag = 1;
                break;
        }
    }


    return 0;
}

