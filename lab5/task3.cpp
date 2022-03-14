#include <iostream>
#include <string>

using namespace std;

class stringType
{
private:
    string first;
    string second;

public:
    // contructor
    stringType()
    {
        first = " ";
        second = " ";
    }
    // parametrized constructor
    stringType(string s1, string s2)
    {
        first = s1;
        second = s2;
    }
    // destructor
    ~stringType() {}

    // funciton to set the value of first and second string
    void setValue(string str1, string str2)
    {
        first = str1;
        second = str2;
    }
    // fucntion to print string
    void print()
    {

        cout << endl
             << "first string: ";
        for (int i = 0; first[i] != 0; i++)
        {
            cout << first[i];
        }
        cout << endl
             << "second string: ";
        for (int i = 0; second[i] != 0; i++)
        {
            cout << second[i];
        }
        cout << endl;
    }
    int MaxLength()
    {
        int len = 0;

        for (int i = 0; first[i] != '\0' || second[i] != '\0'; i++)
        {
            len += i;
        }
        return len;
    }

    int compare(string s1, string s2)
    {
        bool checkEquality = true;
        int junk;
        int sz = MaxLength();
        for (int i = 0; i < sz; i++)
        {
            if (s1[i] != s2[i])
            {
                checkEquality = false;
                break;
            }
        }
        if (checkEquality)
            return 0;
        else
            return junk;
    }

    void copy(string source, string destination)
    {
        for (int i = 0; source[i] != '\0'; i++)
        {
            destination[i] = source[i];
        }
    }

    int searchChar(char ch)
    {

        bool found = false;
        for (int i = 0; first[i] != 0; i++)
        {
            if (first[i] == ch)
            {
                found = true;

                break;
            }
        }

        if (found)
            return 1;
        else
            return 0;
    }
    // fucntion to concatenate two strings together
    string concatenate(string s1, string s2)
    {
        char temp[10000] = {' '};
        int count = 0;
        while (s1[count] != '\0')
        {
            temp[count] = s1[count];
            count++;
        }

        for (int i = 0; s2[i] != '\0'; i++)
        {
            temp[count + i] = s2[i];
        }

        return temp;
    }

    int searchWord(string word)
    {
        bool found = true;
        for (int j = 0; first[j] != '\0'; j++)
        {
            for (int i = 0; word[i] != '\0'; i++)
            {
                if (first[j + i] == word[i])
                {
                    found = true;
                }
                else
                {
                    found = false;
                    break;
                }
            }
            if (found)
                break;
        }
        if (found)
            return 1;
        else
            return 0;
    }
};
int main()

{
    stringType s;
    s.setValue("HelloWorld", "hi");
    cout << s.searchWord("llzo") << endl;
    cout << s.searchWord("World") << endl;
    cout << s.concatenate("hiTest", "hello") << endl;
    cout << s.searchChar('l') << endl;
    cout << s.searchChar('z') << endl;
    s.print();

    return 0;
}