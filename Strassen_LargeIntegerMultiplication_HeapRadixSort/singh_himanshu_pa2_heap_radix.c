#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int* random_number_array(int);
void print_array(int *,int);
void print_stars(int *,int);

int* random_number_array1(int);
void print_array1(int *,int);
void print_stars1(int *,int);

void swap(int*,int,int);
void maxheapify(int *,int,int);
void heap_sort(int *,int);
void build_maxheap(int *,int);
void counting_sort(int *,int,int);
void radix_sort(int*,int);
int maximum(int*,int);
int star_input;
int main()
{
	int choice=0,input_size=0,*ptr,*output;
	while(1)
	{
			printf("\n1.Heap Sort\n2. Radix Sort");
			scanf("%d",&choice);
			if(choice<1||choice>2)
			{
					printf("\n Invalid choice");
					return 0;
					}
					printf("\nEnter the inut size");
					scanf("%d",&input_size);
					star_input=input_size;
					if(input_size<1||input_size>1000)
					{
							printf("\nInvalid size entered enter size between 1 and 1,000");
							return 0;
							}
							switch(choice)
							{
								case 1:
									ptr = random_number_array(input_size);            //Generating an array of random numbers size of array is input_size
									print_array(ptr,input_size);									//Printing unsorted array
									//build_maxheap(ptr,input_size);
									//printf("\nAfter build heap\n");
									//print_stars(ptr,input_size);                    //Printing star representation of unsorted array
									heap_sort(ptr,input_size);
									print_array(ptr,input_size);                     //Printing sorted array
									//print_stars(ptr,input_size);
									break;
									
								case 2:
								ptr = random_number_array1(input_size);								//Generating an array of random numbers size of array is input_size									
									print_array1(ptr,input_size);                     //Printing unsorted array
									//print_stars1(ptr,input_size);                    //Printing star representation of unsorted array
									//radix_sort(input_size,ptr);
									radix_sort(ptr,input_size);
									print_array1(ptr,input_size);
									//print_stars1(ptr,input_size);
									break;
							}
	}
}
int maximum(int *ptr, int n)
{
	int i=0,largest=0;
	for(i=0;i<n;i++)
	{
		if(ptr[i]>largest)
			largest =ptr[i];
	}
	return(largest);
}
void radix_sort(int *ptr,int n)
{
	int max = maximum(ptr,n);
	int i=0;
	for(i=1;(max/i)>0;i*=10)
	{
		counting_sort(ptr,n,i);
		if(n<=20)
		print_stars1(ptr,n);
	}
}


int * random_number_array1(int input_size)
	{
			srand(time(NULL));		
			int *ptr;
			ptr= malloc(sizeof(int)*input_size);
			input_size--;
      while(input_size>=0)
			{
							if(input_size<=20)
											ptr[input_size] = rand()%15 + 0;                 //Generating random numbers between 0 and 15 for input_size less than 20
											else
															ptr[input_size] = rand();
							input_size--;
			}
			return(ptr);
	}

	void print_array1(int* ptr, int input_size)                  //Simple print array function 
	{
					int i=0;
					while(i<input_size)
					{
									printf("\n%5d",ptr[i]);
									i++;
					}
          printf("\n");

	}

	void print_stars1(int *ptr,int input_size)    //Printing array values in the for of stars
	{
          printf("\n");
					int i=0,j=0;
					while(i<input_size)
					{
									for(j=0;j<ptr[i];j++)
													printf("*");
													printf("\n");
													i++;

					}

	}

void build_maxheap(int *ptr, int n)        //building max heap from array of values
{
	int i=0;
	for(i=floor(n/2);i>=1;i--)
	{
		maxheapify(ptr,i,n);
	}
}
void heap_sort(int *ptr,int n)         //sorting the built max heap
{
	int i=0;
	build_maxheap(ptr,n);             //first build max heap 
	printf("\nAfter build max heap\n");
	print_array(ptr,n);               //printing max heap of array.
	printf("\n");
	for(i=n;i>=1;i--)
	{
		swap(ptr,1,i);
		//print_array(ptr,n);
		maxheapify(ptr,1,i-1);
		//print_array(ptr,n);
		if(n<=20)
		print_stars(ptr,n);               //printing stars after each line of algorithm has fnished execution
	}
}

void maxheapify(int *ptr,int node, int n)
{
	int lchild=0,rchild=0,largest=node;
	lchild = node*2;
	rchild = node*2 +1;
	if(lchild<=n&&ptr[lchild]>=ptr[node])
		largest = lchild;	
	if(rchild<=n&&ptr[rchild]>=ptr[largest])
		largest = rchild;
	
	if(largest!=node)
	{
		swap(ptr,largest,node);
		maxheapify(ptr,largest,n);
	}
}

void swap(int* ptr,int i, int j)             //Simple swap function 
{
				int swap=0;
				swap = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = swap;
}
	
int * random_number_array(int input_size)
	{
			srand(time(NULL));		
			int *ptr;
			ptr= malloc(sizeof(int)*(input_size+1));
			ptr[0]=input_size;
      while(input_size>=1)
			{
				if(input_size<=20)
					ptr[input_size] = rand()%15 + 0;                 //Generating random numbers between 0 and 15 for input_size less than 20
											else
															ptr[input_size] = rand();
							input_size--;
			}
			return(ptr); 
	}

	void print_array(int* ptr, int input_size)                  //Simple print array function 
	{
					int i=1;
					while(i<=input_size)
					{
									printf("\n%5d",ptr[i]);
									i++;
					}
          printf("\n");

	}

	void print_stars(int *ptr,int input_size)    //Printing array values in the for of stars
	{
          printf("\n");
					int i=1,j=0;
					while(i<=input_size)
					{
									for(j=0;j<ptr[i];j++)
													printf("*");
													printf("\n");
													i++;

					}

	}

	
void counting_sort(int *ptr,int n, int exp)    //counting sort a stable sorting algorithm used by radix sort
{   int *output =malloc(sizeof(int)*n);
	int k=10;
	int *count = calloc(k,sizeof(int));
	int i=0,j=0;
	//for(i=0;i<k;i++)
		//count[i]=0;
	for(j=0;j<n;j++)
		count[((ptr[j])/exp)%10]++;
	
	for(i=1;i<k;i++)
		count[i] = count[i] + count[i-1];
	for(j=n-1;j>=0;j--)
	{
		output[(count[((ptr[j])/exp)%10])-1] = ptr[j];
		count[((ptr[j])/exp)%10]--;
	}
	for(i=0;i<n;i++)
		ptr[i] = output[i];
}