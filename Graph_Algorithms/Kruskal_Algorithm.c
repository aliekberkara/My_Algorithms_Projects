#include <stdio.h>
#define INF 9999
#define MAX 30

typedef struct edge {
  int u, v, w;
} edge;

//----------------------------------

typedef struct edge_list {
  edge data[MAX];
  int n;
} edge_list;

//----------------------------------

edge_list elist;

int Graph[MAX][MAX], n;
edge_list spanlist;

//----------------------------------

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

//----------------------------------

void kruskalAlgo() {
  int belongs[MAX], i, j, cno1, cno2;
  elist.n = 0;

  for (i = 1; i < n; i++)
    for (j = 0; j < i; j++) {
      if (Graph[i][j] != 0) {
        elist.data[elist.n].u = i;
        elist.data[elist.n].v = j;
        elist.data[elist.n].w = Graph[i][j];
        elist.n++;
      }
    }

  sort();

  for (i = 0; i < n; i++)
    belongs[i] = i;

  spanlist.n = 0;

  for (i = 0; i < elist.n; i++) {
    cno1 = find(belongs, elist.data[i].u);
    cno2 = find(belongs, elist.data[i].v);

    if (cno1 != cno2) {
      spanlist.data[spanlist.n] = elist.data[i];
      spanlist.n = spanlist.n + 1;
      applyUnion(belongs, cno1, cno2);
    }
  }
}

//----------------------------------

int find(int belongs[], int vertexno) {
  return (belongs[vertexno]);
}

//----------------------------------

void applyUnion(int belongs[], int c1, int c2) {
  int i;

  for (i = 0; i < n; i++)
    if (belongs[i] == c2)
      belongs[i] = c1;
}

//----------------------------------

void sort() {
  int i, j;
  edge temp;

  for (i = 1; i < elist.n; i++)
    for (j = 0; j < elist.n - 1; j++)
      if (elist.data[j].w > elist.data[j + 1].w) {
        temp = elist.data[j];
        elist.data[j] = elist.data[j + 1];
        elist.data[j + 1] = temp;
      }
}

//----------------------------------

void print() {
  int i, cost = 0;

  for (i = 0; i < spanlist.n; i++) {
    printf("\n%d - %d : %d", spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].w);
    cost = cost + spanlist.data[i].w;
  }

  printf("\n\nSpanning tree cost: %d\n\n----------------------------------------", cost);
}

//----------------------------------

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
	printf("\n----------------------------------------\n");
}

//----------------------------------

int main() {
  int i, j, total_cost;

  n = 6;

  _init_();
  add(0, 1, 4);
  add(0, 2, 4);

  add(1, 0, 4);
  add(1, 2, 2);

  add(2, 0, 4);
  add(2, 1, 2);
  add(2, 3, 3);
  add(2, 4, 4);

  add(3, 2, 3);
  add(3, 4, 3);

  add(4, 2, 4);
  add(4, 3, 3);

  add(5, 2, 2);
  add(5, 4, 3);

  DisplayMatrix(n);
  kruskalAlgo();
  print();
  printf("\n");
}
