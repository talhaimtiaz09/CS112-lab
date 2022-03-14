#include <iostream>
using namespace std;
class parity
{
private:
    int sz;
    int *arr = new int[sz];

public:
    parity()
    {
        sz = 0;
    }
    parity(int num)
    {
        sz = num;
    }
    ~parity()
    {
        delete[] arr;
    }
    void put(int);
    void print(void);
    void deletee();
    int test(void);
};

void parity::put(int num)
{
    sz++;
    int *tempArr = new int[sz];
    for (int i = 0; i < sz; i++)
    {
        tempArr[i] = arr[i];
    }
    tempArr[sz - 1] = num;
    arr = tempArr;
}
void parity::print(void)
{
    for (int i = 0; i < sz; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}
void parity::deletee()
{
    sz--;
    int *tempArr = new int[sz];
    for (int i = 0; i < sz; i++)
    {
        tempArr[i] = arr[i];
    }
    arr = tempArr;
}
int parity::test(void)
{
    if ((sz % 2) == 0)
        return 1;
    else
        return 0;
}

int main()
{
    parity p(0);
    bool loop = true;
    int option;
    while (loop)
    {
        system("clear");
        cout << "\n********************************\n";
        cout << "Press 0 to put a number\nPress 1 delete last element\nPress 2 print all elements\nPress 3 to test\nPress 4 to exit" << endl;
        cout << "Enter your option: ";
        cin >> option;
        switch (option)
        {
        case 0:
            int temp;
            cout << "Please enter a number: ";
            cin >> temp;
            p.put(temp);
            break;

        case 1:

            p.deletee();
            break;

        case 2:

            p.print();
            break;

        case 3:
            int test;
            test = p.test();
            if (test == 1)
            {
                cout << "True(1): Even inputs\n";
            }
            else
            {
                cout << "False(0): Odd inputs\n";
            }
            break;
        case 4:
            loop = false;
            break;

        default:
            cout << "PLease enter only valid input!" << endl;
        }
        char x;
        cout << "Press any key to continue...";
        cin >> x;
    }

    return 0;
}