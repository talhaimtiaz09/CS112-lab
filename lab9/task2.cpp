#include <iostream>
using namespace std;
int main()
{
    int a;
    int b;
    cout << "Enter first value: ";
    cin >> a;
    cout << "Enter second value: ";
    cin >> b;

    cout << "\n\nImplicit Type casting\n";
    cout << "Result: " << a / b << endl;
    cout << "\nExplicit Type casting\n";
    cout << "The value of float(res): " << float(a) / b << endl;

    return 0;
}