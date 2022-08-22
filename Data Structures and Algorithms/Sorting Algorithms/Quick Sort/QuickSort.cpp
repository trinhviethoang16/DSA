#include<iostream>
using namespace std;

int numberOfSwap = 0;

void quickSort(int array[], int left, int right)
{
    int mid = (left+right)/2;
    int value = array[mid];
    int i=left, j=right;
    while(i<=j)
    {
        while(array[i]<value)
        {
            i++;
        }
        while(array[j]>value)
        {
            j--;
        }
        if(i<=j)
        {
            if(i!=j)
            {
                numberOfSwap++;
                swap(array[i], array[j]);
            }
        }
        i++;
        j--;
    }
    if(left<j)
    {
        quickSort(array, left, j);
    }
    if(i<right)
    {
        quickSort(array, i, right);
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

    quickSort(array, 0, n-1);
    cout << numberOfSwap << endl;
    for(int i=0; i<n; i++)
    {
        cout << array[i] << " ";
    }     
    return 0;
}