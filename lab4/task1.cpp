#include <iostream>
using namespace std;

class swap1
{
private:
    int a;
    int b;

public:
    void setter()
    {
        cout << "Enter two  values : ";
        cin >> a >> b;
    }
    void Swap()
    {
        a = a + b;
        b = a - b;
        a = a - b;
    }
    void getter()
    {
        cout << "A: " << a << " & B: " << b << endl;
    }
};
int main()
{
    swap1 s;
    s.setter();
    cout << "Before swapping: ";
    s.getter();
    s.Swap();
    cout << "After swapping: ";
    s.getter();
    return 0;
}