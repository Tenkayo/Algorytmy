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
    int i, swaps, comparisonsTotal = 0;
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
        comparisonsTotal += i;
    } while (swaps!=0);
    return comparisonsTotal;
}

int BubbleSort2(int * tab, int length)
{
    int swaps, i, sorted = 0, comparisonsTotal = 0;
    do
    {
        swaps = 0;
        for (i = 0; i < length-1-sorted; i++)
        {
            if (tab[i]>tab[i+1])
            {
                swap(tab,tab[i],tab[i+1]);
                swaps++;
            }
        }
        sorted++;
        comparisonsTotal += i;
    } while (swaps!=0);
    return comparisonsTotal;
}

