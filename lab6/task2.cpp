#include <iostream>
using namespace std;
class officer
{
private:
    static int count;
    int id;
    string name;
    string rank;

public:
    officer()
    {
    }
    bool palindrome()
    {
        int i = id, j = 0;
        while (i != 0)
        {
            j *= 10;
            j += i % 10;
            i /= 10;
        }
        if (j == id)
            return true;

        else
            return false;
    }
    void setter()
    {
        cout << "Enter your ID :";
        cin >> id;
        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter your rank: ";
        cin >> rank;
        bool reverseCheck = palindrome();
        if (reverseCheck)
            cout << "Officer is not allowed to enter the area" << endl;
        else
        {
            cout << "Officer is allowed to enter the area" << endl;
            count++;
        }
    }

    void counter()
    {
        cout << "Total number of officers: " << count << endl;
    }
};
int officer::count = 0;

int main()
{
    officer o;
    bool loop = true;
    int option;
    while (loop)
    {

        cout << "1. Enter the ID of officer" << endl;
        cout << "2. Get total number of officers" << endl;
        cout << "3. Exit" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            o.setter();
            break;
        case 2:
            o.counter();
            break;
        case 3:
            loop = false;
            break;
        default:
            cout << "Invalid option!" << endl;
        }
    }
    return 0;
}