#include<iostream>
using namespace std;

int numberOfCompare = 0;
int numberOfSwap = 0;

void selectionSort(int a[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min = i;
        for(int j=i+1; j<n; j++)
        {
            numberOfCompare++;
            if(a[min] > a[j])
            {
                min = j;
            }
        }
        if(min != i)
        {
            numberOfSwap++;
            swap(a[min], a[i]);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];

    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    selectionSort(a, n);
    cout << numberOfCompare << " " << numberOfSwap << endl;
    for(int i=0; i<n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}