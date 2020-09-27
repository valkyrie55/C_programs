#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define n 20

struct queue{
	int items[n];
	int front;  //front
	int rear;   //last
};
struct queue* createqueue();

// graph nodes
struct node{
	int vertex;
	struct node* next;
};

struct graph{
	int num;
	int *visited;
	struct node** adjlists;
};

struct node* createnode(int v){
	struct node* new = malloc(sizeof(struct node));
	new->vertex = v;
	new->next = NULL;
	return new;
}

struct queue* createqueue(){
	struct queue* q = malloc(sizeof(struct queue));
	q->front = -1;
	q->rear = -1;
	return q;
}

struct graph* creategraph(int vertices){
	struct graph* g = malloc(sizeof(struct graph));
	g->num = vertices;
	g->visited = malloc(vertices * sizeof(int)); //allocate memory for vertices array
	g->adjlists = malloc(vertices * sizeof(struct node*));
	int i;
	for(i =0;i<vertices;i++){
		g->adjlists[i] = NULL;
		g->visited[i] = 0;  
	}
	return g;
}

int isEmpty(struct queue* q){
	if(q->rear == -1)
		return 1;  //Queue is empty
	else
		return 0;
}

void enqueue(struct queue* q, int val){
	if(q->rear == n-1)
		printf("Queue is full!\n");
	else{
		if(q->front == -1)   //initially the queue will be empty
			q->front = 0;
		q->rear++;
		q->items[q->rear] = val;  //enqueued!
	}
}

int dequeue(struct queue* q){
	int val;
	if(isEmpty(q)){
		printf("Queue is empty!\n");
		val = -1;
	}
	else{
		val = q->items[q->front];  //take front element
		q->front++;
		if(q->front > q->rear){
			printf("Resetting queue\n");
			q->front = q->rear = -1;
		}
	}
	return val;
}

void display(struct queue* q){
	int i = q->front;
	if(isEmpty(q))
		printf("Queue is empty\n");
	else{
		printf("Queue contains: \n");
		for(i = q->front; i< q->rear+1; i++){
			printf("%d \n",q->items[i]);
		}
	}
}

void bfs(struct graph *g, int i){
	//create queue
	struct queue *q = createqueue();
	g->visited[i] = 1;  //marked as visited
	// put in the queue
	enqueue(q,i);

	while(!(isEmpty(q))){
		display(q);
		int currvertex = dequeue(q);   //extract the node
		printf("Visited: %d\n",currvertex);
		struct node* temp = g->adjlists[currvertex]; //extract the node to where currvertex points
		while(temp){
			int v = temp->vertex;
			// check if it is visited
			if(g->visited[v] == 0){   // not visited
				g->visited[v] = 1;    // mark as visited
				enqueue(q,v);
			}
			temp = temp->next;
		}
	}
}

void addedge(struct graph* g, int src, int des){
	//create node
	struct node* new = createnode(des);
	new->next = g->adjlists[src];
	g->adjlists [src] = new;   // edge from source to destination

	// now add a node from destination to source
	new = createnode(src);
	new->next = g->adjlists[des];
	g->adjlists[des] = new;
}


int main(){
	//create graph
	struct graph* g = creategraph(6);
	addedge(g,0,1);
	addedge(g,0,2);
	addedge(g,1,2);
	addedge(g,1,4);
	addedge(g,1,3);
	addedge(g,2,4);
	addedge(g,3,4);
	bfs(g,0);

	return 0;
}





