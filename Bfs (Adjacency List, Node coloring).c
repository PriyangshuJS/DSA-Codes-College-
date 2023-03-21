#include <stdio.h>
#include <stdlib.h>
enum color{White, Gray, Black};


typedef struct list_node {
  int index_of_item;
  struct list_node *next;
}list_node;


typedef struct node {
  int data;
  enum color colr;
  list_node *head;
}node;

typedef struct graph{
  int number_of_vertices;
  node heads[]; 
}graph;

node* new_node(int data) {
  node *z;
  z = malloc(sizeof(node));
  z->data = data;
  z->head = NULL;
  z->colr = White;

  return z;
}

list_node* new_list_node(int item_index) {
  list_node *z;
  z = malloc(sizeof(list_node));
  z->index_of_item = item_index;
  z->next = NULL;

  return z;
}

graph* new_graph(int number_of_vertices) {

  graph *g = malloc(sizeof(graph) + (number_of_vertices*sizeof(node)));
  g->number_of_vertices = number_of_vertices;

  int i;
  for(i=0; i<number_of_vertices; i++) {
    node *z = new_node(-1); 
    g->heads[i] = *z; 
  }

  return g;
}

void add_node_to_graph(graph *g, int data) {

  node *z = new_node(data);
  int i;
  for(i=0; i<g->number_of_vertices; i++) {
    if (g->heads[i].data < 0) {
      g->heads[i] = *z;
      break;
    }
  }
}


int in_graph_head_list(graph *g, int data) {
  int i;
  for(i=0; i<g->number_of_vertices; i++) {
    if(g->heads[i].data == data)
      return 1;
  }
  return 0;
}

void add_edge(graph *g, int source, int dest) {
 
  if(!in_graph_head_list(g, source)) {
    add_node_to_graph(g, source);
  }
  if(!in_graph_head_list(g, dest)) {
    add_node_to_graph(g, dest);
  }

  int i,j;

  for(i=0; i<g->number_of_vertices; i++) {
    if(g->heads[i].data == source) { 

      int dest_index;
      for(j=0; j<g->number_of_vertices; j++) {
        if(g->heads[j].data == dest) {
          dest_index = j;
          break;
        }
      }

      list_node *n = new_list_node(dest_index);
      if (g->heads[i].head == NULL) {
        g->heads[i].head = n;
      }
      else { 
        list_node *temp;
        temp = g->heads[i].head;

        while(temp->next != NULL) {
          temp = temp->next;
        }
        temp->next = n;
      }
      break;
    }
  }
}


typedef struct queue_node {
  node *n;
  struct queue_node *next;
}queue_node;

struct queue
{
    int count;
    queue_node *front;
    queue_node *rear;
};
typedef struct queue queue;

int is_empty_queue(queue *q)
{
  return !(q->count);
}

void enqueue(queue *q, node *n)
{
  queue_node *new_queue_node;
  new_queue_node = malloc(sizeof(queue_node));
  new_queue_node->n = n;
  new_queue_node->next = NULL;
  if(!is_empty_queue(q))
  {
    q->rear->next = new_queue_node;
    q->rear = new_queue_node;
  }
  else
  {
    q->front = q->rear = new_queue_node;
  }
  q->count++;
}

queue_node* dequeue(queue *q)
{
  queue_node *tmp;
  tmp = q->front;
  q->front = q->front->next;
  q->count--;
  return tmp;
}

queue* make_queue()
{
  queue *q;
  q = malloc(sizeof(queue));
  q->count = 0;
  q->front = NULL;
  q->rear = NULL;
  return q;
}

void print_queue(queue *q) {
  queue_node *tmp;
  tmp = q->front;
  while(tmp != NULL) {
    printf("%d\t",tmp->n->data);
    tmp = tmp->next;
  }
  printf("\n");
}

void bfs(graph *g) {
  node s = g->heads[0];
  int i;
  for(i=0; i<g->number_of_vertices; i++) {
    g->heads[i].colr = White;
  }
  s.colr = Gray;

  queue* q = make_queue();
  enqueue(q, &s);
  printf("The sequence output\n");
  while(!is_empty_queue(q)) {
    queue_node *u = dequeue(q);
    list_node *temp;
    temp = u->n->head;
    while(temp != NULL) {
      if (g->heads[temp->index_of_item].colr == White) {
        g->heads[temp->index_of_item].colr = Gray;
        enqueue(q, &g->heads[temp->index_of_item]);
      }
      temp = temp->next;
    }
    u->n->colr = Black;
    printf(" %d ",u->n->data);

  }
}

int main() {
  graph *g = new_graph(8);
  add_edge(g, 1, 2);
  add_edge(g, 1, 3);
  add_edge(g, 2, 4);
  add_edge(g, 4, 5);
  add_edge(g, 5, 6);
  add_edge(g, 5, 8);
  add_edge(g, 6, 7);
  add_edge(g, 6, 8);
  add_edge(g, 8, 7);
  bfs(g);
  printf("\n");
  return 0;
}
