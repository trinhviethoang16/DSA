#include<iostream>
using namespace std;

int binarySearch(int array[], int n, int value, int &count)
{
    int left = 0;
    int right = n-1;
    while(left<=right)
    {
        count++;
        int mid = (right+left)/2;
        
        if(value == array[mid])
        {
            return mid;
        }
        else if(value < array[mid])
        {
            right = mid-1;
        }
        else if(value > array[mid])
        {
            left = mid+1;
        }
    }
    return -1;
}

int main()
{
    int n, value, count = 0;
    cin >> n >> value;
    int array[n];

    for(int i=0; i<n; i++)
    {
        cin >> array[i];
    }

    int result = binarySearch(array, n, value, count);
    cout << count << endl << result;
    return 0;
}