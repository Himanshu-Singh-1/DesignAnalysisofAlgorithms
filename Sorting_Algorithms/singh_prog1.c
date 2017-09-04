#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int* random_number_array(int);
void print_array(int *,int);
void exchange_sort(int,int *);
void insertion_sort(int,int*);
void merge_sort(int *,int,int);
void merge(int *,int,int,int);
void quick_sort(int*,int,int);
int  divide(int*,int,int);
void swap(int*,int,int);
void print_stars(int *,int);
int *c=NULL;                 //Final sorted array for merge sort 
int star_input;             //saving the entered input size globally,to use input size across functions where input size is not passed
int main ()
{
	int choice=0,input_size=0,*ptr;
	while(1)
	{
			printf("\n1.Exchange Sort\n2.Insertion Sort\n3.Merge Sort\n4.Quick Sort\n");
			scanf("%d",&choice);
			if(choice<1||choice>4)
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
									ptr = random_number_array(input_size);            //Fenerating an array of random numbers size of array is input_size
									print_array(ptr,input_size);                     //Printing unsorted array
									if(input_size<=20)
									print_stars(ptr,input_size);                    //Printing star representation of unsorted array
									exchange_sort(input_size,ptr);                                
									printf("\nSORTED ARRAY:");
									print_array(ptr, input_size);
									break;
									case 2:
									ptr = random_number_array(input_size);
									print_array(ptr,input_size);
									if(input_size<=20)
                  print_stars(ptr,input_size);
									insertion_sort(input_size,ptr);
                  //print_stars(ptr,input_size);
									printf("\nSORTED ARRAY:");
									print_array(ptr,input_size);
									break;
									case 3:
									ptr = random_number_array(input_size);
									print_array(ptr,input_size);
									c = malloc(input_size*sizeof(int));        //Global array where final sorted values are stored
                  if(input_size<=20)
									print_stars(ptr,input_size);
									merge_sort(ptr,0,input_size-1);
                  printf("\nSORTED ARRAY:");
                  if(input_size<=2)
                  print_array(ptr,input_size);
                  else
									print_array(c,input_size);
									break ;
									case 4:
									ptr = random_number_array(input_size);
									print_array(ptr,input_size);
                  if(input_size<=20)
									print_stars(ptr,input_size);
									quick_sort(ptr,0,input_size-1);
									printf("\nSORTED ARRAY:");
									print_array(ptr,input_size);
                  break;
									default:
									return 0;
							}

			}

	}

	int * random_number_array(int input_size)
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

	void print_array(int* ptr, int input_size)                  //Simple print array function 
	{
					int i=0;
					while(i<input_size)
					{
									printf("\n%5d",ptr[i]);
									i++;
					}
          printf("\n");

	}

	void print_stars(int *ptr,int input_size)    //Printing array values in the for of stars
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

	void exchange_sort(int input_size, int* ptr)
	{
	int i=0,j=0,swap=0;
	while(i<input_size)
	{
					j=i+1;
					while(j<input_size)
					{
									if(ptr[i]>ptr[j])
									{
													swap = ptr[i];
													ptr[i] = ptr[j];
													ptr[j] = swap;
									}
									j++;
					}
					if(input_size<=20)
									print_stars(ptr,input_size);
					i++;

	}
	}

void insertion_sort(int input_size, int* ptr)
{
int i=0,j=0,x=0;
while(i<input_size-1)
{
				j = i;
        x = i;
				if(ptr[i]>ptr[i+1])
				{
								swap(ptr,i,i+1);
								while(j>=0)
								{
												if(ptr[x]<ptr[j])
												{
																swap(ptr,x,j);
																x=j;
																}
																j--;
								}
				}
				if(input_size<=20)
								print_stars(ptr,input_size);              //Printing the array in star form after each iteration

i++;
}
}


void merge_sort(int *ptr,int low,int high)
{
      //if(star_input<=20)
			//print_stars(ptr,star_input);
			int	mid = low + floor((high-low)/2);
      if(high-low+1==2)
{
if (ptr[low]>ptr[high])
swap(ptr,low,high);
return;
}
			if(high-low+1>=2)
			{
				merge_sort(ptr,low,mid);
				merge_sort(ptr,mid+1,high);
				merge(ptr,low,mid,high);
				if(star_input<=20)
        print_stars(ptr,star_input);       //Printing the array in star form after most relevant step of merge sort algorithm: merge in each iteration        
			}
			else 
							return;
}

void merge(int* ptr,int low,int mid,int high)     //Merging step of merge sort algorithm 
{
     
				int i=low,j=mid+1,index=low;
				while(i<mid+1 && j<=high)
				{
								if(ptr[i]<ptr[j])
												
												c[index++] = ptr[i++];
												else
																c[index++] = ptr[j++];
				}
				while(i<=mid)
								c[index++] = ptr[i++];
				while(j<=high)
								c[index++] = ptr[j++];
 for(i=low;i<=high;i++)
{
ptr[i] = c[i];
}
}

void quick_sort(int* ptr,int low,int high)
{
				if(low<high)
				{
								int mid =divide(ptr,low,high);
								if(star_input<=20)                       //Printing the array in star form after most relevant step of quick sort: divide in each iteration
                print_stars(ptr,star_input);
								quick_sort(ptr,low,mid-1);
								quick_sort(ptr,mid+1,high);
				}
				


}

int divide(int* ptr,int low,int high)                //Divide step of quick sort algorithm
{
				int i=low,j=high;
				int pivotindex =low + rand()%(high-low+1);
				int pivot = ptr[pivotindex];
				swap(ptr,low,pivotindex);
				while(i<j)
				{
								while(ptr[i]<=pivot&&i<=j)
								i++;
								while(ptr[j]>pivot)
												j--;
												if(i<j)
																swap(ptr,i,j);
				}
        swap(ptr,low,j);
				return j;

}


void swap(int* ptr,int i, int j)             //Simple swap function 
{
				int swap=0;
				swap = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = swap;
}
	
