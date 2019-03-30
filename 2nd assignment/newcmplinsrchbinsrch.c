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
    {   cmp+=1;
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
	time_t ti=time(0);
	srand((unsigned int)ti);
	long long int i,j,bscount=0,mcount=0,count=0,bcount=0,var=0;
	long long int* arr;
	long long int* arr2;
	arr2=(long long int*)calloc(100000,sizeof(long long int));
	arr=genarr(1,100000,100000);
	long long int k=0;
	for(k=0;k<100000;k++)
	{
		arr2[k]=arr[k];
	}
	mcount=mergecmp(arr2,100000);
	int arr3[10]={1,3,5,50,60,70,80,100,1000,2000};
	for(i=0;i<10;i++)
	{
		count=0;
        bscount=mcount;
        for(j=0; j<arr3[i];j++)
        {
            //srand(time(NULL));
            var=rand()%100000 + 1;
            //var=-1;
            count=count+ linearsearch(arr2,100000,var);
            //printf("%lld\n",count);
            bcount=binarysearch(arr2,0,99999,var);
			bscount=bscount+bcount;
            bcount=0;
        }
        printf("Linear %lld ", count);
        printf("\t Binary %lld ", bscount);
        printf("\n");
	}
	return 0;
}

