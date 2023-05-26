#include <iostream>

using namespace std;

void swap(int * array, int index1, int index2)
{
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

int BubbleSort1(int * tab, int length)
{
    int i, swaps, swapsTotal=0;
    do
    {
        swaps = 0;
        for (i = 0; i < length-1; i++)
        {
            if (tab[i]>tab[i+1])
            {
                swap(tab,i,i+1);
                swaps++;
            }
        }
        swapsTotal +=swaps;
    } while (swaps!=0);
    return swapsTotal;
}

