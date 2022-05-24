#include <iostream>
using namespace std;
int main()
{
    int a;
    float a2;
    int b;
    char c;
    char d;

    cout << "Enter the value of first variable: ";
    cin >> a;
    a2 = a;
    cout << "Enter the value of third variable: ";
    cin >> b;
    cout << "Enter the value of fourth variable: ";
    cin >> c;
    cout << "Enter the value of fifth variable: ";
    cin >> d;

    cout << "First variable: " << a << endl;
    cout << "Seconf variable: " << a2 << endl;
    cout << "Type casting char to int data type(Third+Fourth)= " << b + c << endl;
    cout << "Type casting from int to float type( Third + fifth): " << b + d << endl;

    return 0;
}