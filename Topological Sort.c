#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int n, adj[MAX][MAX];
int queue[MAX];
int front=-1, rear=-1;
//int topsort[MAX],index_array[MAX];
void insert_queue(int node)   // To insert a node into queue
{
	if(rear==MAX-1)
		printf("Queue Overflow.\n");
	else
	{
		if(front==-1)   //if queue is initially empty
			front=0;
		queue[++rear]=node;
	}
}
int delete_queue()     // To delete a node fron the queue
{
	int del_node;
	if(front==-1 || front> rear)
	{
		printf("Queue Underflow.\n");
		return ;
	}
	else
	{
		del_node=queue[front++];
		return del_node;
	}
}
void create_graph()   //Function for creating inputted graph using edge input. For directed graph use origin and destination node to make a particular edge.
{
	int i,max_edges,org,dest;   //org-origin and dest- destination
	printf("Enter the number of vertices: ");
	scanf("%d",&n);
	max_edges=n*(n-1);
	for(i=1;i<=max_edges;i++)
	{
		printf("Enter edge %d(0 to quit): ",i);
		scanf("%d %d",&org,&dest);
		if((org==0) && (dest==0))
			break;
		if(org>n || dest>n || org<=0 || dest<=0)
		{
			printf("Invalid edge");
			i--;
		}
		else
			adj[org][dest]=1;
	}
}
void display()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%d ",adj[i][j]);
		printf("\n");
	}
}
int find_indegree(int node)
{
	int i,in_deg=0;
	for(i=1;i<=n;i++)
	{
		if(adj[i][node]==1)
			in_deg++;
	}
	return in_deg;
}
void topological_sort()
{
	int node,j=0,del_node,I;
	int topsort[MAX],indeg[MAX];
	//Find the in_degree of each node
	for(node=1;node<=n;node++)
	{
		indeg[node]=find_indegree(node);
		if(indeg[node]==0)
			insert_queue(node);
	}
	//continue loop until queue is empty
	while(front<=rear)
	{
		del_node=delete_queue();
		topsort[j]=del_node; //add the deleted node to topsort
		j++;
		//delete the del_node edges
		for(node=1;node<=n;node++)
		{
			if(adj[del_node][node]==1)
			{
				adj[del_node][node]=0;
				indeg[node]=indeg[node]-1;
				if(indeg[node]==0)
					insert_queue(node);
			}
		}
	}
	printf("The topological sorting can be given as: \n");
	for(node=0;node<j;node++)	
		printf("%c\t",topsort[node]+64);
}
int main()
{
	create_graph();
	printf("The adjacency matrix is: \n");
	display();
	topological_sort();
	return 0;
}
