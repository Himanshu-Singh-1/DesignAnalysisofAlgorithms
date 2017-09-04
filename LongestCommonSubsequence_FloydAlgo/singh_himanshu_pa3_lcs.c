#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void lcs(char *, char *,int,int);
int main(int argc, char *argv[])
{
	char *a;
	char *b;
	//char *substring;
	if(argc ==3)
	{
		a = argv[1];
		b = argv[2];
		printf("\nInput String a: %s",a);
		printf("\nInput String b: %s\n",b);
	}
	
	else
	{
		printf("\n Incorrect number of arguments passed\n");
		return 1;
	}
	
    lcs(a,b,strlen(a),strlen(b));
	return 1;
	}

void lcs(char *x, char *y,int m,int n)
{
	
	int c[m+1][n+1];
	int i=0,j=0;
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==0||j==0)
				c[i][j]=0;
		}
	}
	
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			//if(i==0||j==0)
				//c[i][j] = 0;
			if (x[i-1] == y[j-1])
				c[i][j] = c[i-1][j-1] +1;
			else
			{
				if(c[i-1][j]>c[i][j-1])
					c[i][j] = c[i-1][j];
                else
					c[i][j] = c[i][j-1];
			}
				
		}
	}
	
	int ptr = c[m][n];
	char lcs[ptr+1];
	lcs[ptr] = '\0';
	
	i=m;
j=n;
	while(i>0 && j>0)
	{
		if(x[i-1] == y[j-1])
		{
			lcs[ptr-1] = x[i-1];
			i--;
			j--;
			ptr--;
		}
		else if(c[i-1][j]>c[i][j-1])
			i--;
		else
			j--;
	}
	printf("\n*** %s ***\n",lcs);
	/*
	int m = strlen(x);
	int n = strlen(y);
	int *c = malloc(sizeof(int)*(m+1)*(n+1));
	int *b = malloc(sizeof(int)*(m+1)*(n+1));
	int i=0,j=0;
	for(i=0;i<=m;i++)
	*(c+ m) = 0;
	for(i=0;i<=n;i++)
		*(c + i*n) = 0;
	
	for(i=1;i<m;i++)
	{
		for(j=1;j<n;j++)
		{
			if(x[i] == y[i])
			{
				*(c +i*n+j) = *(c +(i-1)*n+j-1) +1;
				*(b+i*n+j) = 3;
			}
			else if(*(c+ n*(i-1)+j) >= *(c+i*n+j-1))
			{
				*(c+i*n+j) = *(c+(i-1)*n+j);
				*(b+i*n+j) = 2;
			}
			else
			{
				*(c+i*n+j) = *(c+i*n+j-1);
				*(b+i*n+j) = 1;
			}
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			printf("%3d",*(c+i*n+j));
		printf("\n");
	}
	*/
}
