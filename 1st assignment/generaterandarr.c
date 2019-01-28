#include<stdio.h>
#include<stdlib.h>
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
		p=(int*)calloc(d*sizeof(int));
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
