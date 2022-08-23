#include<iostream>
using namespace std;

int numberOfCompare = 0;
int numberOfMove = 0;

void binaryInsertionSort(int array[], int n)
{
    for(int i=1; i<n; i++)
    {
        int value = array[i];
        int left = 0, right = i-1;
        while(left<=right)
        {
            int mid = (left+right)/2;
            numberOfCompare++;
            if(value > array[mid])
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }
        
        for(int j=i; j>left; j--)
        {
            numberOfMove++;
            array[j] = array[j-1];
        }
        array[left] = value;
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
    binaryInsertionSort(array, n);
    cout << numberOfCompare << " " << numberOfMove << endl;
    for(int i=0; i<n; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}