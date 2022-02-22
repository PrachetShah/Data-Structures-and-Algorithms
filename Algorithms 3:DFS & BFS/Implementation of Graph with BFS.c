#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    struct node *next;
    int data;
}node;

typedef struct Q{
    node *first;
    node *last;
}Q;

typedef struct graph{
    node *edges[20];
    int *visited[20];
}graph;

void display(Q *q){
  node *ptr = q->first;
  int i=1;

  if(q->first==NULL){
    printf("Empty Queue");
  }
  else{
    while(ptr!=NULL){
      printf("%d is at position ( %d ) in Queue\n" , ptr->data , i);
      i++;
      ptr=ptr->next;
    }
  }
}

Q* enq(Q *q , int val){
  node *p = (node *)malloc(sizeof(node));
  p->data=val;
  p->next=NULL;
  if(q->first==NULL){
    q->first=q->last=p;
  }
  else{
    q->first->next=q->last;
    q->last->next=p;
    q->last=p;
  }
  return q;
}

int deq(Q *q){
  node *temp = (node *)malloc(sizeof(node));
  int dltVal;
  if(q->first==NULL){
    printf("Underflow");
    return -1;
  }
  else{
    temp=q->first;
    dltVal = temp->data;
    if(temp->next!=NULL){
      temp->next=q->first->next;
      q->first=temp->next;
      free(temp);
      return dltVal;
    }
    else{
      free(temp);
      q->first=q->last=NULL;
      return dltVal;
    }
  }
}

void BFS(graph *g , Q * q , int vertex){
  g->visited[vertex]=1;
  q=enq(q , vertex);
  node * temp;

  while(q->first!=NULL){
    int currentVertex = deq(q);
    printf("Visited->%d\n", currentVertex);
    temp=g->edges[currentVertex];

    while(temp!=NULL){
      if(g->visited[temp->data]==0){
        g->visited[temp->data] = 1;
        q=enq(q , temp->data);
      }
      temp=temp->next;
    }
  }
}


graph* createGraph(graph *g , int vertices_count){
  int i=0 , j=0 ;
  int num_edges;
  int edge_to;

  for (i=0; i<vertices_count; i++){
    printf("Enter no of edges for vertex %d : " , i);
    scanf("%d" , &num_edges);
    node *v = (node *)malloc(sizeof(node));
    v->data = i;
    v->next=NULL;
    g->edges[i]=v;
    g->visited[i] = 0;
    for(j=0;j<num_edges;j++){
      node *to = (node *)malloc(sizeof(node));
      printf("Edge from %d to : " , i);
      scanf("%d" , &edge_to);
      to->data = edge_to;
      to->next=NULL;
      while(v->next!=NULL){
          v=v->next;
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
    printf("\nVertex %d: \n", v);
    while (temp) {
        if(temp->next==NULL){
            printf("%d-> NULL" , temp->data);
        }else{
             printf("%d-> ", temp->data);
        }

      temp = temp->next;
    }
    printf("\n");
  }
}

void main(){
  graph* g = (graph *)malloc(sizeof(graph));
  Q* q = (Q *)malloc(sizeof(Q));
  q->first=q->last=NULL;
  int num_vertices = 0;
  printf("Enter no of vertices : ");
  scanf("%d" , &num_vertices);
  g = createGraph(g , num_vertices);
  displayGraph(g , num_vertices);
  printf("\nBFS \n");
  BFS(g , q,  0);
}
