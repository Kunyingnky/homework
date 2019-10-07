#include "uhead.h"

void urand(int *a, int n) //0-100 n ge suijishu
{   
    int i = 0;
    srand((int)time(0));
    for ( i = 0; i < n; i++)
    {
        a[i] = 1+(int)(100.0*rand()/(RAND_MAX+1.0));
    }
    
    
}
int usum(int *j ,int n)//sum
{   
    int i;
    int sum = 0;
    for ( i = 0; i < n; i++)
    {
        sum += j[i];
    }
    return sum;
}
void show(int *j, int n) //show randnum
{
    int i;
    printf("randnum: ");
    for ( i = 0; i < n; i++)
    {
        printf("a[%d] %d\n",i,j[i]);
    }
}
/*boo sort*/
void bsort(int *a,int n){
    int i,j,flag;
    if (a == NULL)
    {
        printf("array error");
        return;
    }
    if (n == 1)
    {
        printf("don't need sort");
        return;
    }
    for ( i = 0; (i < n)&&flag; i++)
    {   flag = 0;
        for ( j = 0; j < n - 1 - i; j++)
        {
            if (a[j]>a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1;
            }
        }
        
    }

}

int compare(const void *a,const void *b){
    int *aa = (int *) a;
    int *bb = (int *) b;
    if (*aa > *bb)
    {
        return 1;
    }
    else if (*aa == *bb)
    {
        return 0;
    }
    else
    {
        return -1;
    }
    
    
    
}

void syssort(int *a,int n){
    qsort(a,n,sizeof(int),compare);
}