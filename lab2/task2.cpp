#include <iostream>
#include <string>
#include <bitset>
using namespace std;

#define read(n1, n2)               \
    cout << "Please enter num1: "; \
    cin >> n1;                     \
    cout << "Please enter num2: "; \
    cin >> n2
#define fun(x1, x2) (cout << "The answer is: " << x1 * (2 << (x2 - 1)))

using namespace std;
int main()
{
    int num1, num2;
    read(num1, num2);
    fun(num1, num2);

    return 0;
}
