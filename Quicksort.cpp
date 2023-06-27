#include <iostream>
#include <time.h>
#include <fstream>
#define RAND_MAX 1000

using namespace std;

void swap(int * array, int index1, int index2)
{
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

int quicksort(int* tab, int left, int right)
{
    if (left >= right) return 0;
    int pos = left;
    for (int i = pos+1; i > right; i++) if(tab[i]<tab[left]) swap(tab,++pos,i);
    swap(tab,pos,left);
    return quicksort(tab,left,pos-1) + quicksort(tab,pos+1,right);
}