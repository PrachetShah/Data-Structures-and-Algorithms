#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    struct node *next;
    int data;
}node;

typedef struct graph{
    int visited[20];
    node *edges[20];
}graph;

graph* createGraph(graph *g , int vertices_count){
  int i=0 , j=0;
  int num_edges;
  int edge_to;

  for (i=0; i<vertices_count; i++){
    printf("Enter no of edges for vertex %d : " , i);
    scanf("%d" , &num_edges);
    node *v = (node *)malloc(sizeof(node));
    v->data = i;
    v->next = NULL;
    g->edges[i] = v;
    g->visited[i] = 0;
    for(j=0; j < num_edges; j++){
      node *to = (node *)malloc(sizeof(node));
      printf("Edge from %d to : " , i);
      scanf("%d" , &edge_to);
      to->data = edge_to;
      to->next = NULL;
      while(v->next != NULL){
          v = v->next;
      }
      v->next = to;
    }
  }
  return g;
}

void displayGraph(graph* graph, int num_vertices) {
  int v;
  for (v = 0; v < num_vertices; v++) {
    node* temp = graph->edges[v];
    printf("\n Vertex %d:\n ", v);
    while (temp){
      if(temp->next==NULL){
        printf("%d-> NULL" , temp->data);
      }
      else{
        printf("%d-> ", temp->data);
      }
      temp = temp->next;
    }
    printf("\n");
  }
}

void DFS(graph *g , int vertex){
  node* temp = g->edges[vertex];
  g->visited[vertex] = 1;
  printf("Visited->%d \n", vertex);

  while (temp != NULL) {
    int connectedVertex = temp->next->data;
    if (g->visited[connectedVertex] == 0) {
      DFS(g, connectedVertex);
    }
    temp = temp->next;
  }
}

int main(void){
  graph* g = (graph *)malloc(sizeof(graph));
  int num_vertices = 0;
  printf("Enter no of vertices : ");
  scanf("%d" , &num_vertices);
  g = createGraph(g , num_vertices);
  displayGraph(g , num_vertices);
  printf("\nDFS Order: \n");
  DFS(g , 0);
}
