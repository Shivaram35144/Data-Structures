
#include<stdio.h>
#include<stdlib.h>

void prims(int n,int cost[][10]){
  int u,v,min,mincost=0,visited[n],ne=1;
  for(int i=0;i<n;i++){
    visited[i]=0;
  }
  visited[0]=1;//ch
  while(ne<n){
    for(int i=0;i<n;i++){
      min=999;
      for(int j=0;j<n;j++){
        if (cost[i][j]<min){
          if(visited[i]!=0){
            min=cost[i][j];
            u=i;v=j;
          }
        }
      }
      if(visited[u]==0 || visited[v]==0){
        printf("edge (%d, %d)= %d \n",u,v,min);
        ne+=1;
        mincost+=min;
        visited[v]=1;

      }
      cost[u][v]=cost[v][u]=999;
    }
    
  }
  printf("Cost of mst = %d",mincost);
}

int main(){
  int n,cost[10][10];
  printf("No of nodes ");
  scanf("%d",&n);
  printf("Adjacency matrix/cost matrix\n");
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      scanf("%d",&cost[i][j]);
      if(cost[i][j]==0){
        cost[i][j]=999;
      }
    }
  }
  prims(n,cost);
  return 0;
}
