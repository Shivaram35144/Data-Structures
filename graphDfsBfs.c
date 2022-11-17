#include<stdio.h>
#include<stdlib.h>

int MAX =10;
//#define MAX 10;

void BFS(int adj[][MAX] ,int visited[],int start){
    int queue[MAX],rear=-1,front=-1;

    for(int k=0;k<MAX;k++){
        visited[k]=0;
    }

    queue[++rear]=start;
    ++front;
    visited[start]=1;

    while(rear>=front){
        start = queue[front++];
        printf("%c ",start+65);
    

    for(int i=0;i<MAX;i++){
        if(adj[start][i] && visited[i] ==0){
            queue[++rear]=i;
            visited[i]=1;

        }
    }
    }

}


void DFS(int adj[][MAX] ,int visited[],int start){
    int stack[MAX],top=-1;

    for(int k=0;k<MAX;k++){
        visited[k]=0;
    }

    stack[++top]=start;
    //++front;
    visited[start]=1;

    while(top!=-1){
        start = stack[top--];
        printf("%c ",start+65);
    

    for(int i=0;i<MAX;i++){
        if(adj[start][i] && visited[i] ==0){
            stack[++top]=i;
            visited[i]=1;
            break;
        }
    }
    }


}

int main(){
    int visited[MAX] ;
    int adj[MAX][MAX];
    int choice,size;

    int flag=0;

    while(flag==0){
        printf("\n1.ENTER VALUES\n2.BFS\n3.DFS\n4.EXIT\n");
        printf("Enter choice : ");
        scanf("%d",&choice);
    }   switch(choice){
            case 1: 
                printf("Enter adjacency matrix : ");
                for(int i=0;i<MAX;i++){
                    for(int j=0;j<MAX;j++){
                        scanf("%d",&adj[i][j]);
                    }
                }
                break;
            case 2:
                printf("BFS TRAVERSAL\n");
                BFS(adj,visited,0);
                break;
            case 3:
                printf("DFS traversal\n");
                DFS(adj,visited,0);
                break;
            case 4:
                flag=1;
                break;
            default:
                printf("Wrong Choice");

    }

    return 0;

}