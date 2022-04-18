#include <stdio.h>
#include <stdlib.h>

struct node {
    int vertex;
    struct node* next;
};

struct node* createNode(int v);

//----------------------------------------

struct Graph {
    int numVertices;
    int* visited;
    struct node** adjLists;
};

//----------------------------------------

void DFS(struct Graph* graph, int vertex) {
    struct node* adjList = graph->adjLists[vertex];
    struct node* temp = adjList;

    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

//----------------------------------------

struct node* createNode(int v) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

//----------------------------------------

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node*));

    graph->visited = malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

//----------------------------------------

void addEdge(struct Graph* graph, int src, int dest) {
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

//----------------------------------------

void printGraph(struct Graph* graph) {
    int v;
    for (v = 0; v < graph->numVertices; v++) {
        struct node* temp = graph->adjLists[v];
        printf("%d | ", v);
        while (temp->next != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("%d\n", temp->vertex);
    }
    printf("\n");
}

int main() {

    int choice;

    while(1) {
        printf("\n\n1- Create Adjacency List\n2- DFS\n3- Exit\n\nChoose One: ");
        scanf("%d", &choice);
        struct Graph* graph = createGraph(5);
        addEdge(graph, 0, 1);
        addEdge(graph, 0, 2);
        addEdge(graph, 1, 2);
        addEdge(graph, 2, 3);
        addEdge(graph, 4, 1);
        addEdge(graph, 3, 4);
        if(choice == 1) {
            printf("\n----------------------------------------\n\n");
            printGraph(graph);
            printf("----------------------------------------\n");
        } else if(choice == 2) {
            printf("\n----------------------------------------\n\nDFS Algorithm:\n\n");
            DFS(graph, 2);
            printf("\n\n----------------------------------------\n\n");
        } else if(choice == 3) {
            printf("\n\n----------------------------------------\n\nLogged Out!\n\n");
            break;
        } else {
            printf("\n\n----------------------------------------\n\nTry Again!!!\n\n");
        }
    }
    return 0;
}
