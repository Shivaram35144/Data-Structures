//ARRAY IMPLEMENTATION OF TREE

#include<stdio.h>
#include<math.h>
#include<string.h>

const int MAX =20;

typedef struct arr{
    int arr[MAX];
    //int size;
} bt;

bt init(int n){
    bt b;
    for(int i=0;i<n;i++){
        b.arr[i]=-1;
    }
    return b;
}

bt addleft(int val,int parent,bt b){
    if(b.arr[parent*2]!=-1){
        printf("Already a element is present\n");
        return b;
    }
    else{
        b.arr[parent*2]=val;
        return b;
    }
}

bt addright(int val,int parent,bt b){
    if(b.arr[parent*2+1]!=-1){
        printf("Already a element is present\n");
        return b;
    }
    else{
        b.arr[parent*2+1]=val;
        return b;
    }
}

int levels(int arr[],int siz){
    int i=1,count=0;
    while(i<=siz){
        i*=2;
        count+=1;
        //printf("%d %d\n",i,count);
    }
    printf("levels : %d",count);
    return count;
}

//LEVEL ORDER TRAVERSAL
int main(){
    int arr[]={-1,1,2,3,4,5,6,7,8};
    int siz=sizeof(arr)/sizeof(arr[0]);
    //printf("%d\n",siz);
    int x=levels(arr,siz-1);

    printf("\nLevel 1: ");

    int k=1;
    for(int i=0;i<x;i++){
        for(int j=0;j<pow(2,i);j++){
            if(arr[k]){
            printf("%d ",arr[k]);
            k+=1;}
        }
        printf("\nLevel %d: ",i+2);
    }


    
}


