#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

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

int SequentialSearch(int* tab, int length, int s)
{
    if (length<1||tab==NULL) return -2;
    for (int i = 0; i < length; i++) if (tab[i]==s) return i+1;
    return -1;
}

int LosujIndeks(int length)
{
    int i;
    do i = rand(); while (i >= length);
    return i;
}

float SequentialSearchStatistics(int max, int length)
{
    srand(time(NULL));
    int *PointerToTable, SessionComparisons, SearchedNumber;
    float TotalComparisons = 0;
    for (int i = 0; i < max; i++)
    {
        PointerToTable = RandomTable(length);
        SearchedNumber = PointerToTable[LosujIndeks(length)];
        SessionComparisons = SequentialSearch(PointerToTable, length, SearchedNumber);
        cout << "Dla tablic o dlugosci " << length << " wykonano " << i+1 << " petli" << endl;
        cout << "Wartosc SessionComparisons: " << SessionComparisons << endl;
        TotalComparisons+=SessionComparisons;
        cout << "Wartosc TotalComparisons " << TotalComparisons << endl;
    }
    return TotalComparisons/max;
}

int TestSearch()
{
    ofstream DataFile;
    DataFile.open("wyszukiwanie.dat");
    float results;
    for (int i = 10; i <= 1000; i+=10)
    {
        results = SequentialSearchStatistics(100,i);
        DataFile << i << "   " << results << endl; 
        cout << "Progress: " << i << "/1000" << endl;
    }
    DataFile.close();
    return 0;
}

int main()
{
    TestSearch();
    return 0;
}