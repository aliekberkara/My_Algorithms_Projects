#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

struct queue {
    int items[SIZE];
    int front;
    int rear;
};

//----------------------------------------

struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);
void printQueue(struct queue* q);

//----------------------------------------

struct node {
    int vertex;
    struct node* next;
};

//----------------------------------------

struct Graph {
    int numVertices;
    struct node** adjLists;
    int* visited;
};

//----------------------------------------

void BFS(struct Graph* graph, int startVertex) {
    struct queue* q = createQueue();

    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        struct node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
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

struct queue* createQueue() {
    struct queue* q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

//----------------------------------------

int isEmpty(struct queue* q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

//----------------------------------------

void enqueue(struct queue* q, int value) {
    if (q->rear == SIZE - 1)
        printf("\nQueue is Full!!");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

//----------------------------------------

int dequeue(struct queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

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
        printf("\n\n1- Create Adjacency List\n2- BFS\n3- Exit\n\nChoose One: ");
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
            printf("\n----------------------------------------\n\nBFS Algorithm:\n\n");
            BFS(graph, 2);
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
