#include <iostream>
#include <fstream>
#include <time.h>
#define RAND_MAX 1000

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

int* RandomTable(int size)
{
    if (size<1) return NULL;    
    int* Table = new int[size];
    for (int i = 0; i < size; i++) Table[i] = rand();
    return Table;
}

void WriteData(int* Table, int size)
{
    if (Table == NULL || size <1) cout << "Data error!" << endl;
    else for (int i = 0; i < size; i++) cout << Table[i] << " ";        
}

int LosujIndeks(int length)
{
    int i;
    do i = rand(); while (i >= length);
    return i;
}

float BubbleSortStatistics1(int max, int length)
{
    srand(time(NULL));
    int *PointerToTable, SessionComparisons;
    float TotalComparisons = 0;
    for (int i = 0; i < max; i++)
    {
        PointerToTable = RandomTable(length);
        SessionComparisons = BubbleSort1(PointerToTable, length);
        cout << "Dla tablic o dlugosci " << length << " wykonano " << i+1 << " petli" << endl;
        cout << "Wartosc SessionComparisons: " << SessionComparisons << endl;
        TotalComparisons+=SessionComparisons;
        cout << "Wartosc TotalComparisons " << TotalComparisons << endl;
    }
    return TotalComparisons/max;
}

float BubbleSortStatistics2(int max, int length)
{
    srand(time(NULL));
    int *PointerToTable, SessionComparisons;
    float TotalComparisons = 0;
    for (int i = 0; i < max; i++)
    {
        PointerToTable = RandomTable(length);
        SessionComparisons = BubbleSort2(PointerToTable, length);
        cout << "Dla tablic o dlugosci " << length << " wykonano " << i+1 << " petli" << endl;
        cout << "Wartosc SessionComparisons: " << SessionComparisons << endl;
        TotalComparisons+=SessionComparisons;
        cout << "Wartosc TotalComparisons " << TotalComparisons << endl;
    }
    return TotalComparisons/max;
}

void TestBubbleSort1()
{
    ofstream DataFile;
    DataFile.open("bubblesort1.dat");
    float results;
    for (int i = 10; i <= 1000; i+=10)
    {
        results = BubbleSortStatistics1(100,i);
        DataFile << i << "   " << results << endl; 
        cout << "Progress: " << i << "/1000" << endl;
    }
    DataFile.close();
}

void TestBubbleSort2()
{
    ofstream DataFile;
    DataFile.open("bubblesort2.dat");
    float results;
    for (int i = 10; i <= 1000; i+=10)
    {
        results = BubbleSortStatistics2(100,i);
        DataFile << i << "   " << results << endl; 
        cout << "Progress: " << i << "/1000" << endl;
    }
    DataFile.close();
}

int main()
{
    TestBubbleSort1();
    TestBubbleSort2();
    return 0;
}