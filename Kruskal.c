#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Graph
{
  int source;
  int dest;
  int weight;
}graph;
int parent[999];

int find1(int i)
{
    while(parent[i] > -1)
        i = parent[i];

    return i;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b =temp;
}
int union1(int i,int j, int parent[])
{
   parent[i] = j;
}
int partition(struct Graph G[], int low, int high)
{
    int pivot = G[high].weight;
    int i, pIndex;
    pIndex = low;
    for(i=low; i<high; i++)
    {
        if(G[i].weight < pivot)
        {
            swap(&G[i].weight, &G[pIndex].weight);
            swap(&G[i].source, &G[pIndex].source);
            swap(&G[i].dest, &G[pIndex].dest);
            pIndex++;
        }
    }
    swap(&G[pIndex].weight, &G[high].weight);
    swap(&G[pIndex].source, &G[high].source);
    swap(&G[pIndex].dest, &G[high].dest);
    return pIndex;
}
void quickSort(struct Graph G[], int low, int high)
{
    if(low < high)
    {
        int pIndex = partition(G, low, high);
        quickSort(G, low, pIndex-1);
        quickSort(G, pIndex+1, high);
    }
}
void Kruskal(struct Graph G[], int V, int E)
{
    quickSort(G, 0, E-1);
    int i,  cost, p1, p2;
    cost = 0;

    for(i=0; i < V; i++)
        parent[i] = -1;

    for(i=0; i< E; i++)
    {
        p1 = find1(G[i].source);
        p2 = find1(G[i].dest);

            if(p1 != p2)
            {
                union1(p1, p2, parent);
                printf("%d\t%d\t%d\n", G[i].source, G[i].dest, G[i].weight);
                cost += G[i].weight;
            }
    }
     printf("\n Minimum cost= %d \n",cost);
}
int main()
{
    int V, E;
    printf("Enter the number of vertices and edges of the graph: -");
    scanf("%d%d", &V, &E);
    struct Graph G[V];
    printf("\nEnter the source, destination and the weight: - ");
    int i;
    for(i=0; i < E; i++)
    {
        scanf("%d%d%d", &G[i].source, &G[i].dest, &G[i].weight );
    }
    Kruskal(G, V, E);
    return 0;
}
