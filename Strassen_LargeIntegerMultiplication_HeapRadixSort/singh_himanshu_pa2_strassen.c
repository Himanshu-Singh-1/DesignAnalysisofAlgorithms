#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>
int n=0;
void display_array(int *,int);
void generate_random_array(int *);
void matrix_multiply(int,int *,int *,int *);
void strassen_multiply(int,int *,int *,int *);
void divide_matrix(int,int*,int*,int*,int*,int*);
int* add_matrix(int,int*,int*);
int* sub_matrix(int,int*,int*);
void compose(int,int*,int*,int*,int*,int*);
void input_val(int*);
void error_check(int,int*,int*);
void main(int argc,char* argv[])
{
	srand(time(NULL));
    if(argc !=2)
	{
		printf("\nEnter correct number of inputs");
		return;
	}
	else
	{
		n = atoi(argv[1]);
	}
	
    printf("\n%d\n",n);	
	
	int *arr1 = malloc(n*n*sizeof(int));
	int *arr2 = malloc(n*n*sizeof(int));
	int *arr3 = malloc(n*n*sizeof(int));
	int *arr4 = malloc(n*n*sizeof(int));
	generate_random_array(arr1);
	generate_random_array(arr2);
	//input_val(arr1);
	//input_val(arr2);
	display_array(arr1,n);
	display_array(arr2,n);
	matrix_multiply(n,arr1,arr2,arr3);   // Display usual multiply matrix
	display_array(arr3,n);
	strassen_multiply(n,arr1,arr2,arr4);
	error_check(n,arr3,arr4);         //To check if the multiplication by both methods are equal
	display_array(arr4,n);            // Display strassen multiply array 
}

void error_check(int n,int *arr1,int *arr2)  // Function to check equivalence of two matrices
{
	int i=0,j=0,flag=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(arr1[i*n+j]!=arr2[i*n+j])
			{
				printf("\nVelue mismatch at %d:",(i*n+j));
				flag=1;
			}
		}
	}
	if(flag==1)
		printf("\nsize of array:%d\n\n",n);
}

void input_val(int *arr)
{
	int i=0,j=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			 scanf("%d",(arr+i*n+j));
		}
	}
}

void matrix_multiply(int n,int* arr1,int* arr2,int* arr3)  //Basic matrix multiply algo 
{
	int i=0,j=0,k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			arr3[n*i+j] = 0;
			for(k=0;k<n;k++)
			{
				arr3[n*i+j] = arr3[n*i+j] + arr1[i*n+k]*arr2[n*k +j];
			}
		}
	}
}

void generate_random_array(int *arr)
{
	int i=0;
	while(i<n*n)
	{
		//*(arr +i) = rand()% (int)(floor(sqrt(INT_MAX/n))) + 0 ;
		*(arr +i) = rand()%100 + 0 ;
		i++;
	}
}

void display_array(int *arr,int n)
{
	int i=0,j=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%7d",arr[i*n+j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

void strassen_multiply(int n, int *a, int *b, int *c)   //Multiply matrices by strassen algorithm
{
	if(n==1)
	{
		*c = (*a)*(*b);
		return;
	}
	int *a11,*a12,*a21,*a22;
	a11 = malloc((n/2)*(n/2)*sizeof(int));
	a12 = malloc((n/2)*(n/2)*sizeof(int));
	a21 = malloc((n/2)*(n/2)*sizeof(int));
	a22 = malloc((n/2)*(n/2)*sizeof(int));
	
	int *b11,*b12,*b21,*b22;
	b11 = malloc((n/2)*(n/2)*sizeof(int));
	b12 = malloc((n/2)*(n/2)*sizeof(int));
	b21 = malloc((n/2)*(n/2)*sizeof(int));
	b22 = malloc((n/2)*(n/2)*sizeof(int));
	
	int *m1,*m2,*m3,*m4,*m5,*m6,*m7,*tmp1;
	m1 = malloc((n/2)*(n/2)*sizeof(int));
	tmp1=malloc((n/2)*(n/2)*sizeof(int));
	m2 = malloc((n/2)*(n/2)*sizeof(int));
	m3 = malloc((n/2)*(n/2)*sizeof(int));
	m4 = malloc((n/2)*(n/2)*sizeof(int));
	m5 = malloc((n/2)*(n/2)*sizeof(int));
	m6 = malloc((n/2)*(n/2)*sizeof(int));
	m7 = malloc((n/2)*(n/2)*sizeof(int));
	
	int *c11,*c12,*c21,*c22;
	c11 = malloc((n/2)*(n/2)*sizeof(int));
	c12 = malloc((n/2)*(n/2)*sizeof(int));
	c21 = malloc((n/2)*(n/2)*sizeof(int));
	c22 = malloc((n/2)*(n/2)*sizeof(int));
	
	divide_matrix(n,a,a11,a12,a21,a22);
	divide_matrix(n,b,b11,b12,b21,b22);
	/*
	display_array(a11,(n/2));
	display_array(a12,(n/2));
	display_array(a21,(n/2));
	display_array(a22,(n/2));
	
	display_array(b11,(n/2));
	display_array(b12,(n/2));
	display_array(b21,(n/2));
	display_array(b22,(n/2));
	*/
	strassen_multiply(n/2,add_matrix(n/2,a11,a22),add_matrix(n/2,b11,b22),m1);
	strassen_multiply(n/2,add_matrix(n/2,a21,a22),b11,m2);
	strassen_multiply(n/2,a11,sub_matrix(n/2,b12,b22),m3);
	strassen_multiply(n/2,a22,sub_matrix(n/2,b21,b11),m4);
	strassen_multiply(n/2,add_matrix(n/2,a11,a12),b22,m5);
	strassen_multiply(n/2,sub_matrix(n/2,a21,a11),add_matrix(n/2,b11,b12),m6);
	strassen_multiply(n/2,sub_matrix(n/2,a12,a22),add_matrix(n/2,b21,b22),m7);
	/*
	printf("\n********************\n");
	display_array(m1,n/2);
	display_array(m2,n/2);
	display_array(m3,n/2);
	display_array(m4,n/2);
	display_array(m5,n/2);
	display_array(m6,n/2);
	display_array(m7,n/2);
	printf("\n********************\n");
	*/
	/*
	display_array(a11,n/2);
	display_array(a12,n/2);
	display_array(a21,n/2);
	display_array(a22,n/2);
	*/
	c11 = add_matrix(n/2,add_matrix(n/2,m1,m4),sub_matrix(n/2,m7,m5));
	c12 = add_matrix(n/2,m3,m5);
	c21 = add_matrix(n/2,m2,m4);
	c22 = add_matrix(n/2,add_matrix(n/2,m1,m3),sub_matrix(n/2,m6,m2));
	//c = compose(n,c11,c12,c21,c22);
	compose(n,c11,c12,c21,c22,c);
	//printf("\nafter compose:");
	//display_array(c,n);
}

void compose(int n,int *c11,int *c12,int *c21,int *c22,int *c)
{
	int i=0,j=0;
	//int *c = malloc(sizeof(int)*n*n);
	
	for(i=0;i<(n/2);i++)
	{
		for(j=0;j<(n/2);j++)
		{
			*(c+i*n+j) = *(c11+(n/2)*i+j);
			*(c+i*n +j +n/2)= *(c12+(n/2)*i+j);
			*(c+(i+(n/2))*n + j) = *(c21+(n/2)*i+j);
			*(c +(i+(n/2))*n+j+n/2) = *(c22+(n/2)*i+j);
		}
	}
	/*
	for(i=0;i<(n);i++)
	{
		for(j=0;j<(n);j++)
		{
			*(c+i*n+j) = *(c11+(n/2)*i+j);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			*(c+i*n +j +n)= *(c12+(n/2)*i+j);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			*(c+(i+n)*n + j) = *(c21+(n/2)*i+j);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			*(c +(i+n)*n+j) = *(c22+(n/2)*i+j);
		}
	}
	*/
		//display_array(c,n);
	//return c;
	}

int* add_matrix(int n, int *a, int *b)
{
	int i=0,j=0;
	int *c = malloc(sizeof(int)*n*n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			*(c + i*n +j) = *(a + i*n +j) + *(b + i*n +j);
		}
	}
	return(c);
}

int* sub_matrix(int n, int *a,int *b)
{
	int i=0,j=0;
	int *c = malloc(sizeof(int)*n*n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			*(c + i*n +j) = *(a + i*n +j) - *(b + i*n +j);
		}
	}
	return c;
}

void divide_matrix(int n,int* a,int* a11,int* a12, int* a21, int* a22)
{
	int size = n/2,i=0,j=0;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
		*(a11 + i*size + j) = *(a + i*n +j);
		*(a12 + i*size +j) = *(a + i*n + j + size);
		*(a21 +i*size +j) = *(a + (i+size)*n+j);
		*(a22 + i*size+j) = *(a + (i+size)*n+j +size);
		}
	}
	/*
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		*(a11 + i*size + j) = *(a + i*n +j);
	}
    for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			*(a12 + i*size +j) = *(a + i*n + j + size);
		}
	}		
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			*(a21 +i*size +j) = *(a + (i+size)*n+j);
		}
	}
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			*(a22 + i*size+j) = *(a + (i+size)*n+j +size);
		}
	}
	*/
}
