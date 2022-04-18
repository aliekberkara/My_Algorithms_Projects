#include<stdio.h>
#include<stdbool.h>
#define INF 9999999
#define V 5

int G[V][V];

//----------------------------------

void _init_(){
	int i = 0, j = 0;

	while(i < V){
		j = 0;
		while(j < V){
			if(i == j){
				G[i][j] = 0;
			}
			else{
				G[i][j] = INF;
			}
			j++;
		}
		i++;
	}
}

//----------------------------------------

void add(int src, int dest, int weight){

	G[src][dest] = weight;

}

//----------------------------------

void DisplayMatrix(int size){
	int i = 0, j = 0;
	printf("\n   ");

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
			if(G[i][j] == INF){
				printf(" -");
			}
			else{
				printf(" %d", G[i][j]);
			}
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n----------------------------------------\n");
}

//----------------------------------

int main() {

	_init_();
	add(0, 1, 9);
	add(0, 2, 75);

	add(1, 0, 9);
	add(1, 2, 95);
	add(1, 3, 19);
	add(1, 4, 42);

	add(2, 0, 75);
	add(2, 1, 95);
	add(2, 3, 51);
	add(2, 4, 66);

	add(3, 1, 19);
	add(3, 2, 51);
	add(3, 4, 31);

	add(4, 1, 42);
	add(4, 2, 66);
	add(4, 3, 31);

	DisplayMatrix(V);

//----------------------------------

	int no_edge, cost = 0;
	int selected[V];
	memset(selected, false, sizeof(selected));
	no_edge = 0;
	selected[0] = true;

	int x;
	int y;

	printf("\nE       W\n");
	printf("-       -\n");


	while (no_edge < V - 1) {
		int min = INF;
		x = 0;
		y = 0;

		for (int i = 0; i < V; i++) {
		  if (selected[i]) {
			for (int j = 0; j < V; j++) {
			  if (!selected[j] && G[i][j]) {
				if (min > G[i][j]) {
				  min = G[i][j];
				  x = i;
				  y = j;
				}
			  }
			}
		  }
		}
		printf("%d - %d : %d\n", x, y, G[x][y]);
		cost += G[x][y];
		selected[y] = true;
		no_edge++;
	}
	printf("\nSpanning tree cost: %d\n\n----------------------------------------", cost);

	return 0;
}
