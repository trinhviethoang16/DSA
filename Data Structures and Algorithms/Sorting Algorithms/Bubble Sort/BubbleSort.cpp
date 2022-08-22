#include<iostream>
using namespace std;

int numberOfCompare = 0;
int numberOfSwap = 0;

void bubbleSort(int array[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=n-1; j>i; j--)
        {
            numberOfCompare++;
            if(array[j-1] > array[j])
            {
                numberOfSwap++;
                swap(array[j-1], array[j]);
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
    bubbleSort(array, n);
    cout << numberOfCompare << " " << numberOfSwap << endl;
    for(int i=0; i<n; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}