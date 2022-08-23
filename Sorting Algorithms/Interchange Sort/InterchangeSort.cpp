#include<iostream>
using namespace std;

int numberOfCompare = 0;
int numberOfSwap = 0;

void interchangeSort(int array[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            numberOfCompare++;
            if(array[i] > array[j])
            {
                numberOfSwap++;
                swap(array[i], array[j]);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int array[n];
    for(int i=0; i<n; i++)
    {
        cin >> array[i];
    }
    interchangeSort(array, n);
    cout << numberOfCompare << " " << numberOfSwap << endl;
    for(int i=0; i<n; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}