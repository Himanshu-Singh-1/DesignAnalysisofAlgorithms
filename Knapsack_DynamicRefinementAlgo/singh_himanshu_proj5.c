#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
typedef struct items
{
	int profit;
	int wieght;
	float ratio;
}items;
int size;
int set=0;
void bruteforce(items*,int,int);
int computetable(int*,int,int,items*,int,int*);
//int computetable1(int*,int,int,items*,int);
void refinement_dynamic(items*,int,int);
void backtracking(items*,int,int);
void exchange_sort(int,items*);
float kwf2(int,int,int,int*,int*,int,int);
void backtracking(items*,int,int);
void knapsack(int,int,int,int*,int*,int,int,int *,int *,int*,int);
int promising(int,int*,int*,int,int,int,int,int);
int unique_profit(int,int,items*);
int unique_weight(int,int,items*);
void main()
{
	int i=0,n=0, knapsack_capacity =0,wieghtsum=0,tmp=0;
	srand(time(NULL));
	n = rand()%5 + 4;
	size = n;
	//n=3;
	items bagitems[n];
	printf("\nNumber of bagitems: %5d",n);
    for(i=0;i<n;i++)
	{
		tmp = rand()%16 + 5;
		while(!unique_weight(i,tmp,bagitems))
		tmp = rand()%16 + 5;
		bagitems[i].wieght = tmp; 
		wieghtsum = wieghtsum + bagitems[i].wieght;
		tmp = rand()%21 + 10;
		while(!unique_profit(i,tmp,bagitems))
			tmp = rand()%21 + 10;
		bagitems[i].profit = tmp;
	}		
	knapsack_capacity = floor(0.6*wieghtsum);
	//n=3;
	//knapsack = 25;
	
	printf("\n\nBRUTE FORCE:");
	bruteforce(bagitems,n,knapsack_capacity);
	printf("\n\nDYNAMIC PROGRAMMING WITH REFINEMENT:");
	refinement_dynamic(bagitems,n,knapsack_capacity);
	printf("\n\n BACKTRACKING:");
	backtracking(bagitems,n,knapsack_capacity);
	
	//for(i=0;i<n;i++)
	//{
		//printf("\nprofit: %5d, wieght: %5d",bagitems[i].profit,bagitems[i].wieght);
	//}
	//printf("\nKnapsack capacity: %5d", knapsack);
}

int unique_profit(int i,int x,items *bag)
{
	int j=0;
	for(j=0;j<i;j++)
	{
		if(x==bag[j].profit)
			return 0;
	}
	return 1;
}

int unique_weight(int i,int x,items *bag)
{
int j=0;
	for(j=0;j<i;j++)
	{
		if(x ==bag[j].wieght)
			return 0;
	}
	return 1;
}
void backtracking(items* bag,int n,int load)
{
	int maxprofit =0,num=0;
int C=0,i=0;
int p[n+1];
int w[n+1];
int upperbound[n+1];
int bestset[n+1];
int include[n+1];	
	for(i=0;i<n;i++)
	{
		bag[i].ratio = (float)bag[i].profit/(float)bag[i].wieght;
	}
	exchange_sort(n,bag);
	
	//for(i=0;i<n;i++)
	//{
		//printf("\n%5d %5d %5f",bag[i].wieght,bag[i].profit,bag[i].ratio);
	//}
	C=load;
	bestset[0]=0;
	include[0]=0;
	p[0]=0;
	w[0]=0;
	for(i=1;i<=n;i++)
	{
		p[i] = bag[i-1].profit;
		w[i] = bag[i-1].wieght;
		bestset[i]= 0;
		include[i] = 0;
	}
	knapsack(0,0,0,w,p,C,n,bestset,include,&maxprofit,num);
	printf("\n***Maxprofit Backtracking: %5d ***",maxprofit);
	printf("\n Items used in bag:");
	for(i=1;i<n+1;i++)
	{
		if(bestset[i]==1)
		{
			printf("\nWieght: %5d\tProfit: %5d",bag[i-1].wieght,bag[i-1].profit);
		}
	}

	
}

	
void knapsack(int i,int profit,int weight,int *w,int* p,int C, int n,int *bestset,int *include,int* maxprofit,int num)
{ 
    int j=0;
	if(weight<=C&&profit>*maxprofit)
	{
		*maxprofit =profit;
		num =i; 
		for(j=0;j<=i;j++)
		bestset[j] = include[j];
	}
	
	if(promising(i,w,p,C,n,weight,profit,*maxprofit))
	{
		include[i+1] = 1;
		knapsack(i+1,profit+p[i+1],weight+w[i+1],w,p,C,n,bestset,include,maxprofit,num);
		//include[i+1] = 0;
		include[i+1] =0;
		knapsack(i+1,profit,weight,w,p,C,n,bestset,include,maxprofit,num);
	}
	return ;
	
}

int promising(int i,int* w,int *p, int C, int n,int wieght,int profit,int maxprofit)
{
	float bound =0;
	if(wieght>=C)
		return 0;
	bound = kwf2(i+1,wieght,profit,w,p,C,n);
	if(bound>maxprofit)
		return 1;
	else
		return 0;
}

float kwf2(int i,int weight,int profit,int *w,int *p,int C,int n)
{
	
	float bound = profit;
	int j;
	float x[n+1];
	for(j=i;j<=n;j++)
		x[j] =0;
	while(weight<C&&i<=n)
	{
		if((weight + w[i])<=C)
		{
			x[i]=1;
			weight = weight +w[i];
			bound = bound +(float)p[i];
		}
		else
		{
			x[i]=(float)(C-weight)/(float)w[i];
			weight = C;
			bound = bound +(float)p[i]*x[i];
		}
		i++;
	}
	return bound;
}

void exchange_sort(int input_size, items* ptr)
{
	int i=0,j=0;
	items swap;
	while(i<input_size)
	{
	j=i+1;
	while(j<input_size)
	{
		if(ptr[i].ratio>ptr[j].ratio)
		{
			swap = ptr[i];
		    ptr[i] = ptr[j];
			ptr[j] = swap;
		}
			j++;
	}
					i++;
	}
}

//int upperbound(items *bag,int n,int knapsack)

void refinement_dynamic(items *bag,int n,int knapsack_capacity)
{
	int i=0,j=0,profit=0;
	int *B = calloc(sizeof(int),((knapsack_capacity+1)*(n+1)));
	int *selected = calloc(sizeof(int),n);
	//int *included = calloc(sizeof(int),n);
	profit = computetable(B,n,knapsack_capacity,bag,n,selected+1);
	printf("\n\n**MaxProfit Dynamic: %5d**\n\n",profit);

	printf("\nTable with non zero values are the only ones calculated:\n");
	for(i=0;i<=n;i++)
	{
	    for(j=0;j<=knapsack_capacity;j++)
		{
		 printf("%5d",B[n*i +j]);
		}
		printf("\n");
	}
	printf("\nItems Included in knapsack:\n");
	for(i=0;i<n;i++)
	{
		if(*(selected+i)==1)
		{
			printf("\n%5d %5d",bag[i].wieght,bag[i].profit);
		}
	}
	printf("\n\n");
	//for(i=0;i<=n;i++)
	//{
		//printf("%5d",*(selected+n*i+j));
		
		//printf("\n");
	//}
	
	//printf("\n\n from buteforce:");
	//for(j=n-1;j>=0;j--)
	//{
		//if(set&(1<<j))
		//{
			//printf("\nWieght:%5d\tProfit:%5d", bag[j].wieght,bag[j].profit);
		//}
	//}
}

int computetable(int *B,int n,int w,items *bag,int itemsize,int *selected)
{
	int tmp1=0,tmp2=0,i=0;
	if(n==0||w<=0)
	{
		*(selected+n-1)= 0;
		return 0;
	}
	//tmp1 = computetable(B,n-1,w,bag,itemsize);
	if(bag[n-1].wieght>w)
	{
		//*(selected+n-1)= 0;
		tmp1 = computetable(B,n-1,w,bag,itemsize,selected);
		*(B+(n)*itemsize+w) = tmp1;
		return tmp1;
	}
	else
	{
	//tmp2 = computetable(B,n-1,(w-bag[n-1].wieght),bag,itemsize) + bag[n-1].profit;
		tmp1 = computetable(B,n-1,w,bag,itemsize,selected);
		tmp2 = computetable(B,n-1,(w-bag[n-1].wieght),bag,itemsize,selected) + bag[n-1].profit;
	if(tmp1>tmp2)
	{
		*(selected+n-1)= 0;
		*(B+(n)*itemsize+w) = tmp1;
		return tmp1;
	}
	else
	{
		*(selected+n-1)= 1;
		*(B+(n)*itemsize+w) = tmp2;
		return tmp2;
	}
	}
}

void bruteforce(items *bag,int n, int knapsack_capacity)
{
	int setsize= pow(2,n);
	items powerset[setsize];
	int i=0,j=0,maxval=0,setnumber=0;
	for(i=0;i<setsize;i++)
	{
		powerset[i].profit = 0;
		powerset[i].wieght = 0;
	}
	printf("\nAll bag items:");
	for(i=0;i<n;i++)
	{
		printf("\nprofit: %5d, wieght: %5d",bag[i].profit,bag[i].wieght);
	}
	printf("\nKnapsack capacity: %5d", knapsack_capacity);
	for(i=0;i<setsize;i++)
	{
		for(j=0;j<n;j++)
		{
		if(i&(1<<j))
		{
			//include bag[i];
			powerset[i].profit = powerset[i].profit+bag[j].profit;
			powerset[i].wieght = powerset[i].wieght + bag[j].wieght;
		}
		}
	}
	
	for(i=0;i<setsize;i++)
	{
		//printf("\nPowerser \t P: %5d\t W:%5d", powerset[i].profit,powerset[i].wieght);
		if((powerset[i].wieght<=knapsack_capacity)&&(powerset[i].profit>=maxval))
		{
			maxval = powerset[i].profit;
			setnumber = i;
		}
	}
	//printf("\nKnapsack capacity: %5d\n", knapsack_capacity);
	printf("\n***MaxProfit Brute Force: %5d***",powerset[setnumber].profit);
	printf("\n Items used in knapsack:");
	for(j=0;j<n;j++)
	{
		if(setnumber&(1<<j))
		{
			printf("\nWieght:%5d\tProfit:%5d", bag[j].wieght,bag[j].profit);
		}
	}
	set = setnumber;
}