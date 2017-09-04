#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int* random_number_array(int);
void print_number_array(int*,int);
int* large_integer_add(int*,int*,int,int *);
int* large_integer_sub(int*,int*,int);
void divide_number_2(int,int*,int*,int*);
void divide_number_3(int,int*,int*,int*,int*);
//int* large_integer_multiply(int *,int *,int size);
int* large_integer_multiply3(int *,int *,int size);
int simple_multiply(int*,int*,int);
int *multiplyby10(int *,int,int);
int* sum_mul(int*,int*,int*,int*,int*,int*,int*,int*,int*,int);
int* large_integer_multiply2(int*,int*,int);
int* sum_mul2(int*,int*,int*,int*,int);
void main(int argc,char* argv[])
{
	int *num1,*num2,n,*product;
	int *test_sum,*test_sub,*x,*y,*z,*x1,*y1,*z1,tmp=0;
	
	if(argc !=2)
	{
		printf("\nEnter correct no of inputs, only one to specify number of digits\n");
		return;
	}
	
	else
		n = atoi(argv[1]);
	
	srand(time(NULL));
	//printf("\nEnter the number of digits, enter number not multiple of 6 to exit\n");
	//scanf("%d",&n);
	num1= random_number_array(n);
	num2=random_number_array(n);
	
	if(n%6!=0)
	{
		printf("\nEnter digits in multiple of 6");
		return;
	}
	
	print_number_array(num1,n);
	print_number_array(num2,n);
	
	product = large_integer_multiply2(num1,num2,n);  //multiply by dividing into 2 numbers
	printf("\nfinal product numbers dividing into 2 numbers:\n");
	print_number_array(product,n*2);
	
	product = large_integer_multiply3(num1,num2,n);  //multiplying by dividing into 3 numbers 
	printf("\nfinal product after multiplying by dividing into 3 numbers:\n");
	print_number_array(product,n*2);
	
	}

int* large_integer_multiply3(int *a,int *b,int n)
{
	int i=0;
	int *product = malloc(sizeof(int)*n*2),simpletmp=0;
	if(n ==3)
	{
		simpletmp = simple_multiply(a,b,n);
		for(i=n*2-1;i>=0;i--)
		{
			product[i] = simpletmp%10;
			simpletmp = simpletmp/10;
		}
		return(product);
	}
		
	int *x,*y,*z;
	int *x1,*y1,*z1;
	int *tmp1,*tmp2,*tmp3,*tmp4,*tmp5,*tmp6,*tmp7,*tmp8,*tmp9;
	
	x = malloc(sizeof(int)*(n/3));
	y = malloc(sizeof(int)*(n/3));
	z = malloc(sizeof(int)*(n/3));
	x1 = malloc(sizeof(int)*(n/3));
	y1= malloc(sizeof(int)*(n/3));
	z1 = malloc(sizeof(int)*(n/3));
	
	divide_number_3(n,a,x,y,z);
	divide_number_3(n,b,x1,y1,z1);
	
	tmp1 = large_integer_multiply2(x,x1,n/3);
	
	tmp1 = multiplyby10(tmp1,2*(n/3)+(4*n)/3,2*(n/3));
	
	tmp2 = large_integer_multiply2(z,x1,n/3);
	tmp3 = large_integer_multiply2(x,z1,n/3);
	tmp4 = large_integer_multiply2(y,y1,n/3);
	
	tmp2 = multiplyby10(tmp2,2*(n/3)+(2*n)/3,2*(n/3));
	tmp3 = multiplyby10(tmp3,2*(n/3)+(2*n)/3,2*(n/3));
	tmp4 = multiplyby10(tmp4,2*(n/3)+(2*n)/3,2*(n/3));
	
	tmp5 = large_integer_multiply2(x,y1,n/3);
	tmp6 = large_integer_multiply2(y,x1,n/3);
	
	tmp5 = multiplyby10(tmp5,2*(n/3)+(n),2*(n/3));
	tmp6 = multiplyby10(tmp6,2*(n/3)+(n),2*(n/3));
	
	tmp7 = large_integer_multiply2(y,z1,n/3);
	tmp8 = large_integer_multiply2(z,y1,n/3);
	
	tmp7 = multiplyby10(tmp7,2*(n/3)+(n/3),2*(n/3));
	tmp8 = multiplyby10(tmp8,2*(n/3)+(n/3),2*(n/3));
	
	tmp9 = large_integer_multiply2(z,z1,n/3);
	
	product = sum_mul(tmp1,tmp2,tmp3,tmp4,tmp5,tmp6,tmp7,tmp8,tmp9,n);
	return(product);
}

int* sum_mul(int* tmp1,int* tmp2,int* tmp3,int* tmp4,int* tmp5,int* tmp6,int* tmp7,int* tmp8,int* tmp9,int n) //adding terms for multiply divide by 3 algo 
{
	/*
	printf("\nPrinting tmp values:\n");
	print_number_array(tmp1,(4*n)/3 +(n/3)*2);

    print_number_array(tmp2,2*(n/3)+(2*n)/3);
	print_number_array(tmp3,2*(n/3)+(2*n)/3);
	print_number_array(tmp4,2*(n/3)+(2*n)/3);
	
	print_number_array(tmp5,2*(n/3)+(n));
	print_number_array(tmp6,2*(n/3)+(n));
	print_number_array(tmp7,2*(n/3)+(n/3));
	print_number_array(tmp8,2*(n/3)+(n/3));
	print_number_array(tmp9,(n/3)*2);
	*/
	
	int i=0;
	int *sum = calloc(n*2,sizeof(int));
	int tmp=0,carry=0;
	for(i=0;i<=2*n;i++)
	{
	if(i<=(n/3)*2)
	tmp = tmp1[(((4*n)/3 + (n/3)*2))-i-1] + tmp2[(2*(n/3)+(2*n)/3)-i-1] +tmp3[(2*(n/3)+(2*n)/3)-i-1] + tmp4[(2*(n/3)+(2*n)/3)-i-1] + tmp5[(2*(n/3)+(n))-i-1] +tmp6[(2*(n/3)+(n))-i-1]+tmp7[(2*(n/3)+(n/3))-i-1] +tmp8[(2*(n/3)+(n/3))-i-1] + tmp9[2*(n/3)-i-1];
	else if(i<=(2*(n/3)+(n/3)))
	tmp = tmp1[(((4*n)/3 + (n/3)*2))-i-1] + tmp2[(2*(n/3)+(2*n)/3)-i-1] +tmp3[(2*(n/3)+(2*n)/3)-i-1] + tmp4[(2*(n/3)+(2*n)/3)-i-1] + tmp5[(2*(n/3)+(n))-i-1] +tmp6[(2*(n/3)+(n))-i-1]+tmp7[(2*(n/3)+(n/3))-i-1] +tmp8[(2*(n/3)+(n/3))-i-1];
    else if(i<=2*(n/3)+(2*n)/3)
		tmp = tmp1[(((4*n)/3 + (n/3)*2))-i-1] + tmp2[(2*(n/3)+(2*n)/3)-i-1] +tmp3[(2*(n/3)+(2*n)/3)-i-1] + tmp4[(2*(n/3)+(2*n)/3)-i-1] + tmp5[(2*(n/3)+(n))-i-1] +tmp6[(2*(n/3)+(n))-i-1];
	else if(i<=2*(n/3)+n)
	tmp = tmp1[(((4*n)/3 + (n/3)*2))-i-1]  + tmp5[(2*(n/3)+(n))-i-1] +tmp6[(2*(n/3)+(n))-i-1];
    else
		tmp = tmp1[(((4*n)/3 + (n/3)*2))-i-1];
	sum[n*2-i-1] = (tmp+carry)%10;
	carry = ((tmp+carry)/10)%10;
	//printf("\nvalue at:   %d    is:   %d carry is:    %d \n",(n*2-i-1),sum[n*2-i-1],carry);
	}
	return(sum);
}

int *multiplyby10(int *tmp,int n,int x)   // representation of number in tens units... etc place
{
	int *ptr = calloc(n,sizeof(int)*n),i=0;
	for(i=0;i<x;i++)
	{
		ptr[i] = tmp[i]; 
	}
	return(ptr);
}

void print_number_array(int *ptr,int size)  // print number represented by array, number of digits = size 
{
	int i=0;
	printf("\n");
	for(i=0;i<size;i++)
		printf("%d",ptr[i]);
	printf("\n");
}

int * random_number_array(int size)  // generate random number array of size n 
{
	int *tmp=malloc(sizeof(int)*size),i=0;
	tmp[0] = rand()%9 +1;
	for(i=1;i<size;i++)
		tmp[i] = rand()%9 +0;
	return(tmp);
}

int* large_integer_add(int *a,int *b,int size,int *carry_rtrn) // rudimentry used by the inefficient algo 
{
	int *sum = malloc(sizeof(int)*(size)),carry=0,i=0;
	for(i=size-1;i>=0;i--)
	{
		//sum[i+1] = sum[i] +(a[i] +b[i])%10 +carry;
		sum[i] = sum[i] +(a[i] +b[i]+carry)%10;
		if((a[i]+b[i]+carry)>9)
		carry = ((a[i]+b[i]+carry) - (a[i]+b[i]+carry)%10)/10;
		else
			carry =0;
	}
	*carry_rtrn = carry;
	//printf("\n added array:");
	//print_number_array(sum,size);
	return(sum);
}

int *large_integer_sub(int *a,int *b,int size) //needs attention when value at a> value at b not required for this present algo 
{
	int k=0,i=0;
	int *diff = malloc(sizeof(int)*(size));
	for(i=size-1;i>=0;i--)
	{
		while(a[i]<b[i])
		{
			k=1;
			a[i-k] = a[i-k]-1; 
			a[i] = a[i] +10;
			k++;
		}
		diff[i] = a[i]-b[i];
	}
	return(diff);
}

int simple_multiply(int *a,int *b,int n)   //simple multiply function for 2 arrays of size n, each entry of array is a digit of number
{
	int x=0,y=0,count=0,i=0;
	for(i=n-1;i>=0;i--)
	{
		x = x+a[i]*pow(10,count);
		y = y+b[i]*pow(10,count);
		count++;
	}
	return(x*y);
	
}


/*           Ineffiecient algorithm computes correct product but slow
int* large_integer_multiply(int *a, int *b, int n)
{
	int *product = malloc(sizeof(int)*n*2),tmp=0;
	if(n <=3)
	{
		tmp = simple_multiply(a,b,n);
		for(int i=n*2-1;i>=0;i--)
		{
			product[i] = tmp%10;
			tmp = tmp/10;
		}
		/*
		printf("****************");
		print_number_array(a,n);
		print_number_array(b,n);
		print_number_array(product,n*2);
		printf("****************");
		
		return(product);
	}
	int *tmp1,*tmp2,*tmp3,i=0;
	int *cpy1,*cpy2,*cpy3;
	int carry=0;
	cpy1 = calloc(n*2,sizeof(int));
	cpy2 = calloc(n*2,sizeof(int));
	cpy3 = calloc(n*2,sizeof(int));
	
	int *x = malloc(sizeof(int)*n/2);
	int *y = malloc(sizeof(int)*n/2);
	int *z = malloc(sizeof(int)*n/2);
	int *w = malloc(sizeof(int)*n/2);
	
	divide_number_2(n,a,x,y);
	divide_number_2(n,b,w,z);
	/*
	print_number_array(x,n/2);
	print_number_array(y,n/2);
	print_number_array(w,n/2);
	print_number_array(z,n/2);
	
	//product = large_integer_add((large_integer_add(large_integer_multiply(x,z,n/2),large_integer_multiply(x,w,n/2),n)),(large_integer_add(large_integer_multiply(y,z,n/2),large_integer_multiply(y,w,n/2),n)),n*2);
	tmp1 = large_integer_multiply(x,w,n/2);
	tmp2 = large_integer_add(large_integer_multiply(x,z,n/2),large_integer_multiply(w,y,n/2),n,&carry);
	tmp3 = large_integer_multiply(y,z,n/2);
	int flag=0;
	//if(n!=6)
		//n=n+2;
	for(i=0;i<n;i++)
	{
		cpy1[i] = tmp1[i];
	}
	//for(i=0;i<n+1;i++)
		//cpy2[i+n/2] = tmp2[i];
	for(i=0;i<n;i++)
	{
		//cpy2[2*n-n/2-1-i] = tmp2[n-i];
		cpy2[i+n/2] = tmp2[i];
	}
cpy2[(n/2)-1] = carry;	
	for(i=0;i<n;i++)
		cpy3[i+n] = tmp3[i];
	/*
	printf("\nOriginal array\n");
	print_number_array(tmp1,n);
	print_number_array(tmp2,n);
	print_number_array(tmp3,n);
	
	printf("\nCopied array\n:");
	print_number_array(cpy1,n*2);
	print_number_array(cpy2,n*2);
	print_number_array(cpy3,n*2);
	printf("\n");
	
	
	int *product1=NULL;
	product1 = large_integer_add(cpy1,cpy2,n*2,&carry);
	//printf("\nproduct1:   ");
	//print_number_array(product1,n*2);
	product = large_integer_add(product1,cpy3,n*2,&carry);
	//printf("\nproduct:   ");
	//print_number_array(product,n*2);
	//product = large_integer_add(large_integer_add(cpy1,cpy2,n*2),cpy3,n*2);
	/*
	printf("****************");
		print_number_array(a,n);
		print_number_array(b,n);
		print_number_array(product,n*2);
		printf("****************");
		printf("\nsimple multiply:    %d",simple_multiply(a,b,n));
		
	return(product);	
}*/


int* large_integer_multiply2(int *a, int *b, int n)
{
	int *product = malloc(sizeof(int)*n*2),tmp=0,i=0;
	if(n <=3)
	{
		tmp = simple_multiply(a,b,n);
		for(i=n*2-1;i>=0;i--)
		{
			product[i] = tmp%10;
			tmp = tmp/10;
		}
		return(product);
	}
	int *tmp1,*tmp2,*tmp3,*tmp4;
	
	int *x = malloc(sizeof(int)*n/2);
	int *y = malloc(sizeof(int)*n/2);
	int *z = malloc(sizeof(int)*n/2);
	int *w = malloc(sizeof(int)*n/2);
	
	divide_number_2(n,a,x,y);
	divide_number_2(n,b,w,z);
	
	tmp1 = large_integer_multiply2(x,w,n/2);
	tmp2 = large_integer_multiply2(x,z,n/2);
	tmp3 = large_integer_multiply2(w,y,n/2);
	tmp4 = large_integer_multiply2(y,z,n/2);
	
	/*
	printf("\nOriginal array\n");
	print_number_array(tmp1,n);
	print_number_array(tmp2,n);
	print_number_array(tmp3,n);
	print_number_array(tmp4,n);
	*/
	
	tmp1 = multiplyby10(tmp1,2*n,n);
	tmp2 = multiplyby10(tmp2,n+n/2,n);
	tmp3 = multiplyby10(tmp3,n+n/2,n);
	
	/*
	printf("\nMultiplied by 10 array: \n");
	print_number_array(tmp1,2*n);
	print_number_array(tmp2,n+n/2);
	print_number_array(tmp3,n+n/2);
	print_number_array(tmp4,n);
	*/
	
	int *product1=NULL;
	product = sum_mul2(tmp1,tmp2,tmp3,tmp4,n);
	/*
	printf("****************");
		print_number_array(a,n);
		print_number_array(b,n);
		print_number_array(product,n*2);
		printf("****************");
		printf("\nsimple multiply:    %d",simple_multiply(a,b,n));
	*/	
	return(product);	
}

int* sum_mul2(int* tmp1,int* tmp2,int* tmp3,int* tmp4,int n)
{
	int *sum = malloc(sizeof(int)*n*2),tmp=0,carry=0,i=0;
	for(i=1;i<=2*n;i++)
	{
		if(i<=n)
			tmp = tmp1[2*n-i]+tmp2[n+n/2-i]+tmp3[n+n/2-i]+tmp4[n-i];
		else if(i<=n+n/2)
			tmp = tmp1[2*n-i]+tmp2[n+n/2-i]+tmp3[n+n/2-i];
		else
			tmp =tmp1[2*n-i];
		sum[2*n-i] = (tmp+carry)%10;
		carry = ((tmp+carry)/10)%10;
	}
	return(sum);
}

void divide_number_3(int n,int *ptr, int *x, int *y, int *z)
{
	int i=0;
	for(i=0;i<(n/3);i++)
		x[i] = ptr[i];
	for(i=0;i<(n/3);i++)
		y[i] = ptr[i+(n/3)];
	for(i=0;i<n/3;i++)
		z[i] = ptr[i+((n/3)*2)];
}

void divide_number_2(int n,int *ptr, int *x, int *y)
{
	int i=0;
	for(i=0;i<n/2;i++)
		x[i] = ptr[i];
	for(i=0;i<n/2;i++)
		y[i] = ptr[i+(n/2)];
}