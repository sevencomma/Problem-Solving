#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int compare_int(const void* p, const void* q);

int main(void)
{
    int Data[5];
    
    for(int i = 0; i < 5; i++)
        scanf("%d", &Data[i]);
    int mid;
    int sum = 0;
    
    qsort(Data, 5, sizeof(int), compare_int);
    
    for (int i = 0; i < 5; i++)
        sum += Data[i];
    mid = Data[2];
    
    printf("%d\n", sum / 5);
    printf("%d\n", mid);

    return 0;
}

int compare_int(const void* p, const void* q)
{
    return *(int*)p - *(int*)q;
}