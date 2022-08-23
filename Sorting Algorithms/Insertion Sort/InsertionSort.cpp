#include<iostream>
using namespace std;

int numberOfCompare = 0;
int numberOfMove = 0;

void insertionSort(int array[], int n)
{
    for(int i=1; i<n; i++)
    {
        int value = array[i];
        int pos = i;
        while(pos>0)
        {
            numberOfCompare++;
            if(array[pos-1] > value)
            {
                pos--;
            }
            else
            {
                break;
            }
        }
        for(int j=i; j>pos; j--)
        {
            numberOfMove++;
            array[j] = array[j-1];
        }
        array[pos] = value;
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
    insertionSort(array, n);
    cout << numberOfCompare << " " << numberOfMove << endl;
    for(int i=0; i<n; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}