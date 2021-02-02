#include<stdio.h>
#include<conio.h>
#define INFINITY 9999
#define MAX 10
 
void dijkstra(int G[MAX][MAX], int n, int startnode) {
 
	int cost[MAX][MAX], distance[MAX], pred[MAX];
	int visited[MAX], c, min_distance, nextnode, i, j;
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(G[i][j] == 0)
				cost[i][j] = INFINITY;
			else
				cost[i][j] = G[i][j];
		}
	}
	
	for(i = 0; i < n; i++) {
		distance[i] = cost[startnode][i];
		pred[i] = startnode;
		visited[i] = 0;
	}
	
	distance[startnode] = 0;
	visited[startnode] = 1;
	c = 1;
	
	while(c < n - 1) {
		min_distance = INFINITY;
		
		for(i = 0; i < n; i++) {
			if(distance[i] < min_distance && !visited[i]) {
				min_distance = distance[i];
				nextnode = i;
			}
		}
					
		visited[nextnode] = 1;
		for(i = 0; i < n; i++) {
			if(!visited[i]) {
				if(min_distance + cost[nextnode][i] < distance[i]) {
						distance[i] = min_distance + cost[nextnode][i];
						pred[i] = nextnode;
				}
			}
		}
		c++;
	}
 
	for(i = 0; i < n; i++) {
		if(i != startnode) {
			printf("\nDistance of node %d = %d", i, distance[i]);
			printf("\nPath = %d", i);
			j = i;
			do {
				j = pred[j];
				printf(" <- %d",j);
			}while(j != startnode);
		}
	}
}
 
int main() {
	int G[MAX][MAX], i, j, n, u;
	printf("Enter no. of vertices: ");
	scanf("%d", &n);
	printf("Enter the adjacency matrix\n");
	
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			scanf("%d", &G[i][j]);
	
	printf("\nEnter the starting node: ");
	scanf("%d", &u);
	dijkstra(G, n, u);
	
	return 0;
}
 
