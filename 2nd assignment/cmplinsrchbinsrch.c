#include<stdio.h>
#include<stdlib.h>
void mergesort(long long int a[],long long int i,long long int j);
void merge(long long int a[],long long int i1,long long int j1,long long int i2,long long int j2);
long long int* genarr(long long int a, long long int b, long long int d)
{
	/*
	Here a is the minimum value, b is the maximum value and d is the size of the array
	*/
	long long int i=0,g=0;
	time_t t;
	srand((unsigned)time(&t));
	long long int* p;
	if(b>a)
	{
		g=b-a;
		p=(long long int*)calloc(d,sizeof(long long int));
		for(i=0;i<d;i++)
		{
			p[i]=rand()%g+a;
		}
		return p;
	}
	else
	{
		return NULL;
	}
}
long long int gennum(long long int a, long long int b)
{
	/*
	Here a is the minimum value, b is the maximum value
	*/
	long long int i=0,g=0;
	time_t t;
	srand((unsigned)time(&t));
	long long int p;
	if(b>a)
	{
		g=b-a;
		p=rand()%g+a;
		return p;
	}
	else
	{
		return 0;
	}
}
unsigned long long int cmp1=0;
long long int mergecmp(long long int a[],long long int n)
{
	mergesort(a,0,n-1);
	return cmp1;
}
void mergesort(long long int a[],long long int i,long long int j)
{
    long long int mid;
	
    if(i<j)
    {
        mid=(i+j)/2;
        mergesort(a,i,mid);        //left recursion
        mergesort(a,mid+1,j);    //right recursion
        merge(a,i,mid,mid+1,j);    //merging of two sorted sub-arrays
    }
    cmp1++;
    //printf("cmp1= %ld\n",cmp1);
}

void merge(long long int a[],long long int i1,long long int j1,long long int i2,long long int j2)
{
    long long int temp[100000];    //array used for merging
    long long int i,j,k;
    i=i1;    //beginning of the first list
    j=i2;    //beginning of the second list
    k=0;

     while(i<=j1 && j<=j2)    //while elements in both lists
    {
    	cmp1=cmp1+2;
        cmp1++;
		if(a[i]<a[j])
        {
            temp[k++]=a[i++];
            //cmp1+=1.0;
        }
        
        else
            temp[k++]=a[j++];
    }
	cmp1=cmp1+1;
    while(i<=j1){    //copy remaining elements of the first list
        temp[k++]=a[i++];
        cmp1++;}
	cmp1++;
    while(j<=j2){    //copy remaining elements of the second list
        temp[k++]=a[j++];
		cmp1++;}
	cmp1++;
    //Transfer elements from temp[] back to a[]
    for(i=i1,j=0;i<=j2;i++,j++){
        a[i]=temp[j];
        cmp1++;}
    cmp1++;
}
long long int linearsearch(long long int arr[], long long int n, long long int x) 
{ 
    long long int i,cmp=0; 
    for (i = 0; i < n; i++) 
    {   cmp+=2;
        if (arr[i] == x) 
            return cmp;
    }
    return cmp; 
} 
long long int binarysearch(long long int arr[], long long int l, long long int r, long long int x) 
{ 
    long long int cmp =0;
    while (l <= r) { 
        long long int m = l + (r - l) / 2; 
        cmp+=2;
        // Check if x is present at mid 
        if (arr[m] == x) 
            return cmp; 
        cmp+=1;
        // If x greater, ignore left half 
        if (arr[m] < x) 
            l = m + 1; 
  
        // If x is smaller, ignore right half 
        else
            r = m - 1; 
    } 
  
    // if we reach here, then element was 
    // not present 
    return cmp; 
} 
int main(void)
{
	int i,j;
	long long int* arr;
	long long int* arr2;
	arr=(long long int*)calloc(100000,sizeof(long long int));
	arr2=(long long int*)calloc(100000,sizeof(long long int));
	arr=genarr(1,500000,100000);
	long long int k=0;
	for(k=0;k<100000;k++)
	{
		arr2[k]=arr[k];
	}
	mergesort(arr2,0,99999);
	int arr3[5]={1,3,5,50,70}
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			
		}
	}
	unsigned long long int u1=0,u2=0,u3=0,l=0,m=0,v=0;
	u1 = linearsearch(arr,100000,1);
	u2 = linearsearch(arr2,100000,1);
	u3 = binarysearch(arr2,0,99999,1);
	printf("for %lld x , linearsearch = %lld , sort linearsearch= %lld and binarysearch= %lld\n",1,u1,u2,u3);
	u1 = linearsearch(arr,100000,3);
	u2 = linearsearch(arr2,100000,3);
	u3 = binarysearch(arr2,0,99999,3);
	printf("for %lld x , linearsearch = %lld , sort linearsearch= %lld and binarysearch= %lld\n",3,u1,u2,u3);
	u1 = linearsearch(arr,100000,5);
	u2 = linearsearch(arr2,100000,5);
	u3 = binarysearch(arr2,0,99999,5);
	printf("for %lld x , linearsearch = %lld , sort linearsearch= %lld and binarysearch= %lld\n",5,u1,u2,u3);
	l=gennum(1,500000);
	//printf("%lld\n",l);
	u1 = linearsearch(arr,100000,20);
	u2 = linearsearch(arr2,100000,20);
	u3 = binarysearch(arr2,0,99999,20);
	printf("for %lld x , linearsearch = %lld , sort linearsearch= %lld and binarysearch= %lld\n",20,u1,u2,u3);
	m=gennum(1,500000);
	//printf("%lld\n",m);
	u1 = linearsearch(arr,100000,30);
	u2 = linearsearch(arr2,100000,30);
	u3 = binarysearch(arr2,0,99999,30);
	printf("for %lld x , linearsearch = %lld , sort linearsearch= %lld and binarysearch= %lld\n",30,u1,u2,u3);	
	free(arr);
	free(arr2);
	
}
