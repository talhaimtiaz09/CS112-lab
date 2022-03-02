#include <iostream>
#include <string>
#include <bitset>

using namespace std;
#define baseIn(b)           \
    cout << "Enter base: "; \
    cin >> b

#define numInput(x1, x2)        \
    cout << "Enter +ve num1: "; \
    getline(cin, (x1));         \
    cout << "Enter +ve num2: "; \
    getline(cin, (x2))

#define checkValid(b, baseCheck)                                           \
    if (b != 2 && b != 8 && b != 10 && b != 16)                            \
    {                                                                      \
        cout << "Invalid Base, you can enter only 2,8,10,16 base" << endl; \
        baseCheck = false;                                                 \
    }                                                                      \
    // space

#define Add(x1, x2)                   \
    {                                 \
        while (x2 != 0)               \
        {                             \
            int temp_carry = x1 & x2; \
            x1 = x1 ^ x2;             \
            x2 = temp_carry << 1;     \
        }                             \
        sum = x1;                     \
    }
// space

#define convert(a, to_in)           \
    {                               \
        if (a >= 65)                \
            to_in = (a - 'A' + 10); \
        else                        \
            to_in = (a - '0');      \
    }

#define z 5
int main()
{

    int base = 16, sum = 0, carry = 0, alen = 0, blen = 0, diffInLen, max;
    string b = "", a = "", total = "";
    bool baseCheck = true;

    // calling macros
    numInput(a, b);
    baseIn(base);
    checkValid(base, baseCheck);

    blen = b.length();
    alen = a.length();
    diffInLen = alen - blen;
    // Taking absolute difference value
    (diffInLen < 0) ? diffInLen *= -1 : diffInLen *= 1;
    bool numCheck = true;
    for (int i = 0; i < alen; i++)
    {
        if (((a[i] >= 65 && a[i] <= 90) || (a[i] >= 48 && a[i] <= 57)) && ((b[i] >= 65 && b[i] <= 90) || (b[i] >= 48 && b[i] <= 57)))
            continue;
        else
        {
            cout << "Please enter +ve number with capital Alphabets only allowed" << endl;
            numCheck = false;
            break;
        }
    }

    if (numCheck && baseCheck)
    {

        // filling the difference in no. of digits with 000's
        string s = "";
        for (int i = 0; i < diffInLen; i++)
        {
            s += '0';
        }
        // ternary operator to find max lenght
        if (alen < blen)
        {
            a = s + a;
            max = blen;
        }
        else
        {
            b = s + b;
            max = alen;
        }

        for (int i = max - 1; i >= 0; i--)
        { // converting char into their useable int values using ASCII

            int to_in_a = 0, to_in_b = 0;
            convert(a[i], to_in_a);
            convert(b[i], to_in_b);

            // adding each digit seperately from last and then adding carry to it from last digit
            // previous digit sum
            Add(to_in_a, to_in_b);
            Add(sum, carry);

            carry = sum / base;
            sum %= base;
            (sum >= 10) ? (total = char(sum + 'A' - 10) + total) : (total = char(sum + '0') + total);
        }
        // if there is still a carry value left at the end then adding it to total sum
        if (carry > 0)
            total = (char)(carry + '0') + total;
        cout << endl;
        cout << "( " << a << ") + ( " << b << " ) = ( " << total << " )" << endl;
    }
    else
        cout << "Invalid Input sum Cannot be calculated" << endl;

    return 0;
}
