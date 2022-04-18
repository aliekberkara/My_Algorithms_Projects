#include <stdio.h>
#define INF 9999
#define MAX 5

int Graph[MAX][MAX];

void _init_(){
	int i = 0, j = 0;

	while(i < MAX){
		j = 0;
		while(j < MAX){
			if(i == j){
				Graph[i][j] = 0;
			}
			else{
				Graph[i][j] = INF;
			}
			j++;
		}
		i++;
	}
}

//----------------------------------------

void add(int src, int dest, int weight){

	Graph[src][dest] = weight;

}

//----------------------------------------

void Dijkstra(int Graph[MAX][MAX], int n, int start) {
	int cost[MAX][MAX], distance[MAX], pred[MAX];
	int visited[MAX], count, mindistance, nextnode, i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (Graph[i][j] == 0)
				cost[i][j] = INF;
			else
				cost[i][j] = Graph[i][j];

	for (i = 0; i < n; i++) {
		distance[i] = cost[start][i];
		pred[i] = start;
		visited[i] = 0;
	}

	distance[start] = 0;
	visited[start] = 1;
	count = 1;

	while (count < n - 1) {
		mindistance = INF;

		for (i = 0; i < n; i++)
			if (distance[i] < mindistance && !visited[i]) {
			mindistance = distance[i];
			nextnode = i;
			}

		visited[nextnode] = 1;
		for (i = 0; i < n; i++)
			if (!visited[i])
				if (mindistance + cost[nextnode][i] < distance[i]) {
					distance[i] = mindistance + cost[nextnode][i];
					pred[i] = nextnode;
				}
		count++;
	}
	printf("S    D     W\n-    -     -");
	for (i = 0; i < n; i++){
		if (i != start) {
			printf("\n%d -> %d --- %d", start, i, distance[i]);
		}
	}
	printf("\n\n----------------------------------------\n\n");
}

//----------------------------------------

void DisplayMatrix(int size){
	int i = 0, j = 0;
	printf("   ");

	while(i<size){
		printf("%d ", i);
		i++;
	}
	i = 0;
	printf("\n   ");
	while(i<size){
		printf("_ ");
		i++;
	}
	i = 0;
	printf("\n");
	while(i<size){
		j = 0;
		printf("%d|", i);
		while(j<size){
			if(Graph[i][j] == INF){
				printf(" -");
			}
			else{
				printf(" %d", Graph[i][j]);
			}
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n\n----------------------------------------\n\n");
}

//----------------------------------------

int main() {
	int n, u;
	n = MAX;

	_init_();

	add(0, 1, 8);
	add(0, 2, 9);
	add(0, 3, 4);

	add(1, 0, 2);
	add(1, 3, 9);
	add(1, 4, 12);

	add(2, 0, 9);
	add(2, 4, 24);

	add(3, 0, 9);
	add(3, 2, 6);
	add(3, 3, 6);

	add(4, 0, 7);
	add(4, 1, 8);
	add(4, 2, 32);
	add(4, 3, 33);
	add(4, 4, 1);

	DisplayMatrix(MAX);

	u = 0;
	Dijkstra(Graph, n, u);

	return 0;
}
