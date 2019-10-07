#include"uhead.h"
void urand(int* a,int n)
{
	int i;
	srand((int)time(0));
	for(i=0;i<n;i++)
	{
		
		a[i]=1+(int)(100.0*rand()/(RAND_MAX+1.0));
	}
}
int usum(int* a,int n)
{
	int sum=0,i;
	for(i=0;i<n;i++)
	{
		sum=sum+a[i];	
	}
	return sum;
}
void show(int* a,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("a[%d]=%d\n",i,a[i]);	
	}
}
void usort(int* a,int n)
{
	int i,j,temp;
	for(i=0;i<n-2;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])	
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;				
			}
		}
	}
}
int compar(const void*a,const void*b)
{
	int *aa=(int *)a,*bb=(int *)b;
	if(*aa>*bb) return 1;
	if(*aa==*bb) return 0;
	if(*aa<*bb) return -1;
}
void uqsort(int* a,int n)
{
	qsort(a,n,sizeof(int),compar);
}

