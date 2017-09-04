#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void print_array(int*,int);
void floyd(int*,int);
int main()
{
	srand(time(NULL));
	int n=0,i=0,j=0;
	n = rand()%5 +5;
	//n=3;
	printf("\n Value of n: %5d\n",n);
	int *adj = calloc(n*n,sizeof(int));
	int tmp=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(*(adj + i*n +j)==0&& i!=j)
			{
				tmp = rand()%10 + 1;
			*(adj + i*n +j) = tmp;
			*(adj + j*n +i) = tmp;
			}
			
		}
	}
	print_array(adj,n);
	floyd(adj,n);
}

void floyd(int *adj,int n)
{
	int i=0,k=0,j=0,tmp=0,dist=0;
	int* d[n+1];
	for(i=0;i<=n;i++)
	{
		d[i] = calloc(n*n,sizeof(int));
	}
	d[0] = adj;
	int p[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			p[i][j] =0;
	for(k=1;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(*(d[k-1]+i*n+j)> *(d[k-1]+ i*n +k) + *(d[k-1] + k*n +j))
				{
					*(d[k]+i*n+j) = *(d[k-1]+i*n+k) + *(d[k-1]+k*n+j);
					//*(p+i*n+j) = k;
					p[i][j] = k;
				}
				else
					*(d[k]+i*n+j) = *(d[k-1]+i*n+j);
			}
		}
	}
	print_array(p[0],n);
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			tmp =p[i][j];
			if(tmp!=0)
			{
			dist = *(d[tmp-1] +i*n +tmp) + *(d[tmp-1] + tmp*n + j);
			printf("\nShortest path between node: %d node: %d includes node: %d total distance: %d",(i+1),(j+1),tmp+1,dist);
			}
			else 
				printf("\nShortest path between node: %d node: %d is direct path total distance: %d",(i+1),(j+1),*(d[0]+i*n+j));
		}
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
