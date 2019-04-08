#include<stdio.h>
int insertsort(int arr[],int n){
	int i,j,temp;
	for(i=0;i<n;i++){
		j=i;
		temp=arr[j];
		while( j>0 && temp<arr[j-1]){
			arr[j]=arr[j-1];
			j--;
		}
		arr[j]=temp;
	}
}
int select(int arr[],int low,int high){
	if(high==1)
	return arr[low];
	int gr,rem,i,b[100],x;
	gr=(high-low)/5;
	rem=(high-low)%5;
	for(i=0;i<gr;i++){
		insertsort(arr+i*5+low,5);
		b[i]=arr[i*5+2+low];
	}
	insertsort(arr+i*5+low,rem);
	b[i]=arr[low+i*5+((rem-1)/2)];
	return select(b,0,gr+1);
	
}
int partition(int arr[],int low,int high,int x)
{
	int t,down=low,i,up=high-1;
	for(i=low;i<high;i++)
		if(arr[i]==x)
			break;
	t=arr[i];
	arr[i]=arr[low];
	arr[low]=t;
	while(down<up){
		while(down<high && arr[down]<=x){
			down++;
		}
		while(arr[up]>x){
			up--;
		}
		if(down<up){
			t=arr[up];
			arr[up]=arr[down];
			arr[down]=t;
		}
	}
	t=arr[up];
	arr[up]=arr[low];
	arr[low]=t;
	return up;
}
int main()
{
	int arr[100],k,n,x,i,gr,rem,index;
	printf("Enter the no of elements ");
	scanf("%d",&n);
	printf("Enter all the array elements\n");
	for(i=0;i<n;i++)scanf("%d",&arr[i]);
	printf("Enter the value of k (k th smallest element) ");
	scanf("%d",&k);
	if(k>n)
	return printf("Index out of range!!!"),0;
	int low=0;
	int high=n;
	while(42){
		x=select(arr,low,high);			
		index=partition(arr,low,high,x);
		if(index==k-1){
		printf("The k th smallest element is %d",arr[k-1]);break;}
		else if(index>k-1)
		high=index;
		else
		low=index+1;	
	}
}
