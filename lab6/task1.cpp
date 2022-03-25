#include <iostream>
#include <string>

using namespace std;
class Coordinator;

class Person
{

private:
    string name;
    int roomNo;

public:
    friend class Coordinator;
};
class Coordinator
{
private:
    int roomNo;

public:
    Person p1, p2;
    void setter()
    {
        cout << "Enter the competition and University name: ";
        getline(cin, p1.name);
        cout << "Enter the competition and University name: ";
        getline(cin, p2.name);
    }
    void check()
    {

        int l1, l2;
        string u1, u2;
        for (l1 = 0; p1.name[l1] != ' '; l1++)
        {
        }
        for (l2 = 0; p2.name[l2] != ' '; l2++)
        {
        }
        (l1 > l2) ? roomNo = l1 : roomNo = l2;
        l1++;
        l2++;
        for (; p1.name[l1] != '\0'; l1++)
        {
            u1 += p1.name[l1];
        }
        for (; p2.name[l2] != '\0'; l2++)
        {
            u2 += p2.name[l2];
        }

        if (u1 == u2)
            cout << "Message from coordinator, Person1 and Person2 are roomates, and the room number is " << roomNo << endl;
        else
            cout << "Message from coordinator,Person1 and Person2 are not roomates" << endl;
    }
};

int main()
{
    Coordinator obj;
    obj.setter();
    obj.check();
    return 0;
}