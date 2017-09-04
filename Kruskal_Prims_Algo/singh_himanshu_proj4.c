#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct qnodes
{
	int nodeno;
	int cost;
};

struct edge
{
	int source;
	int dest;
	int wieght;
};

void print_array(int*,int);
void decreasekey(struct qnodes*, int ,int);
int deletemin(struct qnodes*,int);
void makequeue(int *, int , struct qnodes*);
void prims(int *,int);
void printq(struct qnodes* , int);
void exchange_sort(struct edge *, int);
int find(int , int *);
void union3(int ,int , int *, int *);
void kruskals(int *, int);
int main()
{
	
	
	srand(time(NULL));
	int n=0,i=0,j=0,choice=0;
	n = rand()%6 +5;
	//n=5;
	printf("\n Value of n: %5d\n",n);
	int *adj = calloc(n*n,sizeof(int));
	int tmp=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(*(adj + i*n +j)==0&& i!=j)
			{
				tmp = rand()%9 + 1;
			*(adj + i*n +j) = tmp;
			*(adj + j*n +i) = tmp;
			}
			
		}
	}
	
	////
	print_array(adj,n);
	printf("\n Enter 1 for prims, 2 for kruskals");
	scanf("%d",&choice);
	if(choice ==1)
	{
	printf("\n\n Prims: \n\n");
	prims(adj,n);
	}
	else if(choice ==2)
	{
	printf("\n\n Kruskals: \n\n");
	kruskals(adj,n);
	}
	else
	{
		printf("\n Enter correct value");
		return 1;
	}
}


void print_array(int* ptr, int input_size)                  //Simple print array function 
	{
	int i=0,j=0;
	printf("\n");
	for(i=0;i<input_size;i++)
	{
		for(j=0;j<input_size;j++)
		{
			printf("%5d",*(ptr+i*input_size+j));
		}
		printf("\n");
	}

	}
	
void kruskals(int *adj, int n)
{
	struct edge edge_matrix[(n*(n-1))/2];
	int i=0,j=0,k=0;
	int set_matrix[n];
	int hieght_matrix[n];
	int t_matrix[n][2];
	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(*(adj +i*(n)+j) ==0)
				continue;
			edge_matrix[k].source =i;
			edge_matrix[k].dest =j;
			edge_matrix[k].wieght = *(adj +i*(n)+j);
			k++;
		}
	}
	
	//for(i=0;i<((n*(n-1))/2);i++)
	//{
		//printf("\nsource: %2d dest: %2d wieght: %2d",edge_matrix[i].source,edge_matrix[i].dest,edge_matrix[i].wieght);
	//}
	
	for(i=0;i<n;i++)
	{
		set_matrix[i] = i;
		hieght_matrix[i] = 0;
	}
	exchange_sort(edge_matrix,(n*(n-1))/2);
	printf("\n\n");
	//for(i=0;i<((n*(n-1))/2);i++)
	//{
		//printf("\nsource: %2d dest: %2d wieght: %2d",edge_matrix[i].source,edge_matrix[i].dest,edge_matrix[i].wieght);
	//}
	
	////////
	int u=0,v=0,tmp=0,ucomp=0,vcomp=0,counter=0;
	while(counter!= n-1)
	{
		u = edge_matrix[tmp].source;
		v = edge_matrix[tmp].dest;
		ucomp = find(u,set_matrix);
		vcomp = find(v,set_matrix);
		
		if(ucomp!=vcomp)
		{
			t_matrix[counter][0] = u;
			t_matrix[counter][1] = v;
			union3(ucomp,vcomp,hieght_matrix,set_matrix);
			counter++;
		}
		tmp++;
	}
	
	for(i=0;i<n-1;i++)
	{
		printf("\nedge from %2d to %2d\n",t_matrix[i][0],t_matrix[i][1]);
	}
	
}

void union3(int repx,int repy, int *hieght, int *set_matrix)
{
	if(hieght[repx] == hieght[repy])
	{
		hieght[repx]++;
		set_matrix[repy] = repx;
	}
	else if(hieght[repx]>hieght[repy])
		set_matrix[repy] = repx;
	else
		set_matrix[repx] = repy;
}



int find(int x, int *set_matrix)
{
	int root=0, node =0,parent=0;
	root = x;
	while(root != set_matrix[root])
		root = set_matrix[root];
	
	node = x;
	while(node !=root)
	{
		parent = set_matrix[node];
		set_matrix[node] = root;
		node = parent;
	}
	
	return root;
}




void exchange_sort(struct edge *ptr, int input_size)
	{
	int i=0,j=0;
	struct edge swap;
		while(i<input_size)
		{
		j=i+1;
			while(j<input_size)
			{
				if(ptr[i].wieght>ptr[j].wieght)
				{
				//swap = ptr[i];
				//ptr[i] = ptr[j];
				//ptr[j] = swap;
				swap.source = ptr[i].source;
				swap.dest = ptr[i].dest;
				swap.wieght = ptr[i].wieght;
				
				ptr[i].source = ptr[j].source;
				ptr[i].dest = ptr[j].dest;
				ptr[i].wieght = ptr[j].wieght;
				
				ptr[j].source = swap.source;
				ptr[j].dest = swap.dest;
				ptr[j].wieght = swap.wieght;
				}
			j++;
			}
			//if(input_size<=20)
		//print_stars(ptr,input_size);
		i++;

		}
	}

void prims(int *adj,int nodes)
{
	
	int parent[nodes];
	int cost[nodes];
	int vnode =0;
	struct qnodes priorityq[nodes];
	int i=0,j=0;
	for(i=0;i<nodes;i++)
	{
		parent[i] = 300;
		cost[i] = 300;
	}
	cost[0] = 0;
	priorityq[0].cost = 0;
	parent[0]=0;
	makequeue(adj,nodes,priorityq);
	priorityq[0].cost = 0;
	parent[0]=0;
	for(i=0;i<nodes;i++)
	{
		vnode = deletemin(priorityq,nodes);
		//printf("\n pooped out: %5d",vnode);
		for(j=0;j<nodes;j++)
		{
			if(priorityq[j].cost>*(adj+vnode*(nodes)+j))
			{
				//cost[j] = *(adj+vnode*(nodes-1)+j);
				parent[j] = vnode;
				//decreasekey(priorityq,j,adj[vnode][j]);
				decreasekey(priorityq,j,*(adj+vnode*(nodes)+j));
			}
			//printq(priorityq,nodes);
		}
		//printq(priorityq,nodes);
	}
	for(i=1;i<nodes;i++)
		printf("\nedge from %2d to %2d",i,parent[i]);
	
}	

void printq(struct qnodes* ptr, int nodes)
{
	int i=0;
	for(i=0;i<nodes;i++)
	{
		printf("%5d cost: %5d\n", i,ptr[i].cost);
	}
}

void makequeue(int *adj, int nodes, struct qnodes* ptr)
{
	int i=0;
	for(i=0;i<nodes;i++)
	{
		ptr[i].cost = 300;
		ptr[i].nodeno = i;
	}
}

int deletemin(struct qnodes *ptr,int nodes)
{
	int tmp = 400,i=0,ret =0;
	for(i=0;i<nodes;i++)
	{
		if((ptr[i].cost<tmp) && (ptr[i].cost!=-1))
		{
			tmp = ptr[i].cost;
			ret =i;
		}
	}
	ptr[ret].cost = -1;
	return(ret);
}

void decreasekey(struct qnodes* ptr, int n,int val)
{
	if(ptr[n].cost!=-1)
	ptr[n].cost =  val;
}


