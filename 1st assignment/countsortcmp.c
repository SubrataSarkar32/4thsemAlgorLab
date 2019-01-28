#include<stdio.h>
#include<stdlib.h>
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
    printf("max=%ld\n",max);
    arr4=(int*)calloc(max,sizeof(int));
    for(i=0;i<n;i++)
    {
    	printf("Arr[i]-1=%d\n",arr[i]-1);
        arr4[arr[i]-1]+=1;
        cmp+=1;
    }
    cmp++;
    printf("cmp=%ld\n",cmp);
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
    printf("%ld\n",cmp);
    return cmp;
}
void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
    unsigned long long int hui=0;
  
    printf("Given array is \n"); 
    printArray(arr, arr_size); 
  
    hui=countsortcmp(arr,6); 
    printf("%lld\n",hui);
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
} 
