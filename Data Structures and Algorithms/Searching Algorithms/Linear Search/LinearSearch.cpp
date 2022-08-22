#include<iostream>
using namespace std;

int linearSearch(int n, int value, int count)
{
    int array[n], position = -1;
    for(int i=0; i<n; i++)
    {
        count++;
        cin >> array[i];
        if(value == array[i])
        {
            position = i;
            break;
        }
    }
    cout << count << endl;
    return position;
}

int main()
{
    int n, value, count = 0;
    cin >> n >> value;
    int result = linearSearch(n, value, count);
    cout << result;
    return 0;
}