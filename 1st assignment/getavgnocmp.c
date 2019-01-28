/*
Date of submission\r\nGroup A: 29/1/19\r\nGroup B: 30/1/19
\n\r\nCompare three sorting algorithms one of which is an O(n?) comparison sort, an O(nlogn) comparison\r\nsort and a non comparison sort. Generate random arrays of size 1000 to 10000 in steps of 1000. For\r\neach size find out the number of comparisons each sorting algorithms make by repeating the\r\nexperiment 100 times for each size and then finding the average. Plot a graph where the y-axis is the\r\nnumber of comparisons and x-axis is the array size for the 3 sorting algorithms on the same graph.\r\n\x0c
*/
#include<stdio.h>
#include<stdlib.h>
void mergesort(int a[],int i,int j);
void merge(int a[],int i1,int j1,int i2,int j2);
int* genarr(int a, int b, int d)
{
	/*
	Here a is the minimum value, b is the maximum value and d is the size of the array
	*/
	int i=0,c=0;
	time_t t;
	srand((unsigned)time(&t));
	int* p;
	if(b>a)
	{
		c=b-a;
		p=(int*)calloc(d,sizeof(int));
		for(i=0;i<d;i++)
		{
			p[i]=rand()%c+a;
		}
		return p;
	}
	else
	{
		return NULL;
	}
}
unsigned long long int insertionsortcmp(int arr[],int n) 
{ 
   int i, key, j;
   unsigned long long int cmp=0; 
   for (i = 1; i < n; i++) 
   { 
       key = arr[i]; 
       j = i-1; 
  
       /* Move elements of arr[0..i-1], that are 
          greater than key, to one position ahead 
          of their current position */
       while (j >= 0 && arr[j] > key) 
       { 
           arr[j+1] = arr[j]; 
           j = j-1; 
           cmp+=1;
       } 
       arr[j+1] = key; 
   } 
   return cmp;
} 
unsigned long int cmp1=0;
long int mergecmp(int a[],int n)
{
	mergesort(a,0,n-1);
	return cmp1;
}
void mergesort(int a[],int i,int j)
{
    int mid;
	
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

void merge(int a[],int i1,int j1,int i2,int j2)
{
    int temp[10000];    //array used for merging
    int i,j,k;
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
unsigned long long int countsortcmp(int arr[],int n)
{
	int a=0,i=0,k=0,max=0,j=0;
    int* arr4;
    int* arr3;
    unsigned long long int cmp=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
        cmp++;
    }
    cmp++;
    //printf("max=%ld\n",max);
    arr4=(int*)calloc(max,sizeof(int));
    for(i=0;i<n;i++)
    {
    	//printf("Arr[i]-1=%d\n",arr[i]-1);
        arr4[arr[i]-1]+=1;
        cmp+=1;
    }
    cmp++;
    //printf("cmp=%ld\n",cmp);
    arr3=(int*)calloc(n,sizeof(int));
    for(i=0;i<max;i++)
    {
        for(k=0;k<arr4[i];k++)
        {
            arr[j]=i+1;
            j++;
            cmp++;
        }
        cmp++;
    }
    cmp++;
    //printf("%ld\n",cmp);
    return cmp;
}
int main(void)
{
	int i=0,j=0,k=0;
	unsigned long long int c1=0,c2=0,c3=0,l=0,m=0,v=0;
	int* arr;
	int* arr2;
	for(i=1000;i<=10000;i=i+1000)
	{
		arr=(int*)calloc(i,sizeof(int));
		arr2=(int*)calloc(i,sizeof(int));
		c1=0,c2=0,c3=0;
		for(j=0;j<100;j++)
		{
			arr=genarr(1,50000,i);
			k=0;
			for(k=0;k<i;k++)
			{
				arr2[k]=arr[k];
			}
			l=insertionsortcmp(arr2,i);
			k=0;
			c1=c1+l;
			for(k=0;k<i;k++)
			{
				arr2[k]=arr[k];
			}
			m=mergecmp(arr2,i);
			c2=c2+m;
			//count sort is non-comparison sort so number of comparisons between elements is zero
			
			cmp1=0; //set global variable to zero for next loop	
			k=0;
			for(k=0;k<i;k++)
			{
				arr2[k]=arr[k];
			}	
			v=countsortcmp(arr2,i);
			c3=c3+v;
		}
		c1=c1/100;
		c2=c2/100;
		c3=c3/100;
		printf("for %d elements , n^2 = %ld , nlogn= %ld and countsort= %ld\n",i,c1,c2,c3);
		free(arr);
		free(arr2);
	}
}
