#include <iostream>
using namespace std;
int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int *arr = new int[size];
    // taking input of array
    for (int i = 0; i < size; i++)
    {
        cout << "Enter number " << i + 1 << " of array: ";
        cin >> arr[i];
    }

    int max = arr[0];
    int min = arr[0];
    // finding min and max
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    int secondMax = arr[0];
    int secondMin = arr[0];

    // finding second min and max by comparing it with max; min
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > secondMax && arr[i] < max)
            secondMax = arr[i];
        if (arr[i] < secondMin && arr[i] > min)
            secondMin = arr[i];
    }

    delete[] arr;

    cout << "Second Lowest: " << secondMin << endl;
    cout << "Second Highest: " << secondMax << endl;

    return 0;
}