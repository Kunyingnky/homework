#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>


#define BUFFER_SIZE 128
#define SRC_FILE_NAME "SRC_sort.txt"
#define DEST_FILE_NAME "DEST_sort.txt"
#define OFFSET 0

#define MAXNUM 100

void urand(int *,int); //0-100 n ge suijishu
int usum(int *,int);//sum
void show(int *, int); //show randnum

void bsort(int *,int);//buble sort
void syssort(int * ,int);//use quicksort

typedef struct
{
    int sum;
    float ave;
}arg;

arg operator(int *,int);

//save array
void SaveSort(char *,int *);

int* ReadSort(char *);