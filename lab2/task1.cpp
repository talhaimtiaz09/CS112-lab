#include <iostream>

using namespace std;
#define input(x)                       \
    cout << "please enter a number: "; \
    cin >> x
#define powerOfTwo(n) ((n & (n - 1)) == 0 ? cout << "Yes, it can be expressed in power of 2\n" : cout << "No, It cannot be expressed in power of 2\n")
int main()

{

    int x;
    input(x);
    powerOfTwo(x);

    return 0;
}