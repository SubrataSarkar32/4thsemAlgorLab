#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node *next;
    int vertex;
}node;
 
node *G[20];   
//heads of linked list
int visited[20];
int n;
void read_graph(); 
//create adjacency list
void insert(int,int);  
//insert an edge (vi,vj) in te adjacency list
void DFS(int);
 
void DFS(int i)
{
    node *p;
   
	printf("\n%d",i);
    p=G[i];
    visited[i]=1;
    while(p!=NULL)
    {
       i=p->vertex;
       
	   if(!visited[i])
            DFS(i);
        p=p->next;
    }
}
 
void read_graph(int n,int* arr1)
{
    int i,vi,vj,no_of_edges;
    //printf("Enter number of vertices:");
   
	//scanf("%d",&n);
 
    //initialise G[] with a null
   
	for(i=0;i<n;i++)
    {
        G[i]=NULL;
        //read edges and insert them in G[]
       
		printf("Enter number of edges:");
       	scanf("%d",&no_of_edges);
 
       	for(i=0;i<no_of_edges;i++)
        {
        	printf("Enter an edge(u,v):");
			scanf("%d%d",&vi,&vj);
			insert(vi,vj);
			arr1[vi][vj]=1;
        }
    }
}
 
void insert(int vi,int vj)
{
    node *p,*q;
    
	//acquire memory for the new node
	q=(node*)malloc(sizeof(node));
    q->vertex=vj;
    q->next=NULL;
 
    //insert the node in the linked list number vi
    if(G[vi]==NULL)
        G[vi]=q;
    else
    {
        //go to end of the linked list
        p=G[vi];
       
		while(p->next!=NULL)
        	p=p->next;
        p->next=q;
    }
}
int main(void)
{
	int a,b,c,d,e,i=0,j=0;
	int** arr1;
	int** arr2;
	printf("Enter number of vertices:");
	scanf("%d",&a);
	getchar();
	arr1=(int**)calloc(a,sizeof(int*));
	arr2=(int**)calloc(a,sizeof(int*));
	for(i=0;i<a;i++)
	{
		arr1[i]=(int*)calloc(a,sizeof(int));
		arr2[i]=(int*)calloc(a,sizeof(int));
	}
	printf("Enter number of entries:");
	scanf("%d",&d);
	getchar();
	int i;
    read_graph(a,arr1);
    //initialised visited to 0
   
	for(i=0;i<n;i++)
        visited[i]=0;
        
	printf("Adjacency matrix representation:- \n\n")
	for(i=0;i<a;i++)
	{
		for(j=0;j<a;j++)
		{
			printf("%d ",arr2[i][j]);
		}
		printf("\n");
	}
	printf("Adjacency list representation:- \n\n");
	for(i=0;i<a;i++)
	{
		printf("%d->"i);
		j=0;
		while(arr1[i][j]!=0)
		{
			printf("%d,"arr1[i][j]);
			j++;
		}
		printf("\n");
	}
	//Now bfs and dfs
	
 
    DFS(0);
	int* currvisit;
	for(i=0;i<a;i++)
	{
		currvisit[i]=0;
	}
	printf("Enter starting vertext of bfs and dfs:");
	scanf("%d",e);
	getchar();
	visited[0]=e;
	
	return 0;
}
