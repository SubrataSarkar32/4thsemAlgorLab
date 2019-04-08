#include<stdio.h>
#include<stdlib.h>
int hash(int re,int max)
{
	return re%max;
}
/*long long int gennum(long long int a, long long int b)
{
	/*
	Here a is the minimum value, b is the maximum value
	
	long long int i=0,g=0;
	//time_t t;
	//srand((unsigned)time(&t));
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
}*/
int main(void)
{
	time_t t;
	srand((unsigned)time(&t));
	long long int i,j,l,m,ra,ty,count=0,mcount=0,fcount=0,bcount=0,var=0,flag=0;
	long long int* arr;
	long long int* arr2;
	int arr3[7]={1000,2000,10000,60000/3,60000/2,50000,60000};
	arr2=(long long int*)calloc(60000,sizeof(long long int));
	//arr=(long long int*)calloc(10000,sizeof(long long int));
	long long int k=0;
	for (m=0;m<7;m++)
	{
		arr=(long long int*)calloc(60000,sizeof(long long int));
		for(k=0;k<60000;k++)
    	{
		    arr2[k]=-1;
	    	arr[k]=-1;
	    } 
	    count=0;
	    for(i=0;i<arr3[m];i++)
    	{
    		var=rand()%59999+1;
		    //printf("%lld\n",i);
    		flag=1;
    		l=hash(var,60000);
    		ty=l;
	    	for(ra=1;ra<60000-1;ra++)
		    {
		    	count+=2;
		    	if(arr[l]==-1)
		    	{
		     		arr[l]=var;
			    	flag=0;
			    	break;
		    	}
		    	else if(arr[l]==var)
		    	{
		    		count+=1;
		    		//printf("Value already present\n");
		    		//break;
				}
		    	l=(ty+ra)%60000;
	    	}
    	}
    	printf("no probes: %lld\n",count/arr3[m]);
    }
	
	return 0;
}

