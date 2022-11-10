// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node* left;
    struct node * right;
};

typedef struct node * BST;

BST init(int x){
    BST b;
    b=(struct node *)malloc(sizeof(struct node));
    b-> val = x;
    b->right = NULL;
    b->left = NULL;
    return b;
}

BST find (int x, BST t){
    if(t==NULL){
        return NULL;
    }
    if(x<t->val){
        return find(x,t->left);
    }
    else if(x>t->val){
            return find(x,t->right);
    }
    else{
        return t;
    }
}

BST findmin(BST t){
    if(t==NULL){
        return NULL;
    }
    else{
        if(t->left==NULL){
            return t;
        }
        else{
            return findmin(t->left);
        }
    }
        
}

BST findmax(BST t){
    if(t==NULL){
        return NULL;
    }
    else{
        if(t->right==NULL){
            return t;
        }
        else{
            return findmax(t->right);
        }
    }
        
}



BST addto(int element,BST t){
    //printf("%d\n",element);
    //BST n = init(element);
    if(t==NULL){
        return init(element);
        
    }
    else{
        if(element<t->val){
            t->left=addto(element,t->left);
        }
        else if(element>t->val){
            t->right=addto(element,t->right);
        }
        else{
            return t;
        }
    }
    return t;
}

BST del(int x,BST t){
    BST temp;
    if(t==NULL){
        printf("Code properly");
    }
    else{
        if(x<t->val){
            t->left=del(x,t->left);
        }
        else{
            if(x>t->val){
            t->right=del(x,t->right);
            }
            else{
                if(t->left && t->right){
                    temp=findmin(t->right);
                    t->val=temp->val;
                    t->right=del(t->val,t->right);
                }
                else{
                    temp=t;
                    if(t->left==NULL){
                        t=t->right;
                    }
                    else{
                        if(t->right ==NULL){
                            t=t->left;
                            
                        }
                    }
                }
            
        }
        }
        
    }
    //free(temp);
    return t;
}

void inorder(BST t){
    //printf("Hi\n");
    if(t==NULL){
        return;
    }
        inorder(t->left);
        printf("%d ",t->val);
        inorder(t->right);
}

//postorder : 


int main() {
    

    int n,x;
    scanf("%d",&n);
    scanf("%d",&x);
    BST t=init(x);
    
    for(int i =0;i<n-1;i++){
        int p;
        scanf("%d",&p);
        t=addto(p,t);
        //printf("%d\n",p);
    }
    
    
    
    inorder(t);
    printf("\n");
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    printf("%d\n",findmin(t)->val);
    printf("%d\n",findmax(t)->val);
    
    t=del(a,t);
    t=del(b,t);
    inorder(t);

    return 0;
}