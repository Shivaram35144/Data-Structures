#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 7

int minDistance(int dist[], bool sptSet[])
{
	
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}


void printSolution(int dist[])
{
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t\t\t %d\n", i, dist[i]);
}


void dijkstra(int graph[V][V], int src)
{
	int dist[V]; 

	bool sptSet[V]; 
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	dist[src] = 0;

	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;
		for (int v = 0; v < V; v++)

			if (!sptSet[v] && graph[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	printSolution(dist);
}

int main()
{
	int graph[V][V] = { { 0, 5, 3, 2, 0, 0, 0 },
						{ 5, 0, 2, 0, 0, 3, 1 },
						{ 3, 2, 0, 7, 0, 7, 0 },
						{ 2, 0, 7, 0, 7, 2, 0 },
						{ 0, 0, 0, 7, 0, 1, 0 },
						{ 0, 3, 7, 2, 1, 0, 1 },
						{ 0, 1, 0, 0, 0, 1, 0},
						 };

	dijkstra(graph, 0);

	return 0;
}










//sort nlogn

#include<stdio.h>

int partition(int alist[],int first,int last){
    int pivotvalue = alist[first];
    int leftmark = first+1;
    int rightmark = last;
    int done = 0;
    while(done==0){
       while(leftmark <= rightmark && alist[leftmark] <= pivotvalue){
           leftmark = leftmark + 1;}

       while (alist[rightmark] >= pivotvalue && rightmark >= leftmark){
           rightmark = rightmark -1;}

       if(rightmark < leftmark){
           done = 1;}
       else{
           int temp = alist[leftmark];
           alist[leftmark] = alist[rightmark];
           alist[rightmark] = temp;} }
    int temp = alist[first];
    alist[first] = alist[rightmark];
    alist[rightmark] = temp;
    return rightmark; }
    
void quickSort(int alist[],int first,int last){
    if(first<last){
        int splitpoint = partition(alist,first,last);
        quickSort (alist,first,splitpoint-1);
        quickSort (alist,splitpoint+1,last);
}}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d ", array[i]);
  }
  printf("\n");
}
int main(){
  int n;
  printf("\nHow many elements?\t:  ");
  scanf("%d",&n);
  printf("\n");
  int data[n];
  printf("Enter the elements : \n");
  for(int i =0;i<n;i++){
      int x;
      scanf("%d",&x);
      data[i]=x;
  }
  int size = sizeof(data) / sizeof(data[0]);
  quickSort(data, 0,size);
  printf("\nThe sorted array is : \n");
  printArray(data, size);
}
