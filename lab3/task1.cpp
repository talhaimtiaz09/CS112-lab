#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    // declaring array of desired size and taking input
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter number " << i + 1 << " of array: ";
        cin >> arr[i];
    }

    // declaring a temparary array for holding the results of size-1
    int *temp = new int[size - 1];
    for (int i = 0; i < size - 1; i++)
    {
        *(temp + i) = arr[i + 1] - arr[i];
    }

    // delete the arr not in use;
    delete[] arr;

    cout << "Result: Array: [ ";
    for (int i = 0; i < size - 1; i++)
    {
        cout << temp[i] << " ";
    }
    cout << "]\n";
    delete[] temp;

    return 0;
}