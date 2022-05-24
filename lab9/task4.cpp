#include <iostream>
using namespace std;
void print(int *ptr)
{
    cout << "The value of ptr cast: " << *(ptr)*10 << endl;
}
int main()
{
    int n = 50;
    const int *ptr;
    ptr = &n;
    cout << "Number : " << *ptr << endl
         << endl;
    print(const_cast<int *>(ptr));

    return 0;
}