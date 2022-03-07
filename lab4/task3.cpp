#include <iostream>

using namespace std;

class small_set
{
public:
    int size;
    small_set()
    {
        size = 1;
    }

private:
    int *arr;

public:
    void set(int);
    void clear(int);
    int test(int);
};

int main()
{
    small_set s;

    s.set(3);
    s.set(5);
    s.set(5);
    cout << s.test(3) << endl;
    cout << s.test(7) << endl;
    s.clear(5);
    cout << s.test(5) << endl;

    return 0;
}

void small_set::set(int item)
{
    if (item >= 0 && item < 32 && size < 32)
    {
        int *temp = new int[++size];
        int index;
        bool found = true;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == item)
            {
                index = i;
                found = false;
                break;
            }
        }
        if (!found)
        {
            for (int i = 0; i < size; i++)
            {
                if (i != index)
                    temp[i] = arr[i];
                else
                    temp[index] = item;
            }
        }

        else
            temp[size - 1] = item;
        arr = temp;
        delete[] arr;

        arr = temp;
        // delete[] arr;
    }
}
void small_set::clear(int item)
{
    if (item >= 0 && item < 32 && size < 32)
    {
        int *temp = new int[--size];
        int index;
        bool found = true;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == item)
            {
                index = i;
                found = false;
                break;
            }
        }
        if (!found)
        {
            for (int i = 0; i < size; i++)
            {
                if (i != index)
                    temp[i] = arr[i];
                else
                    --i;
            }
        }

        else
            temp[size - 1] = item;
        arr = temp;
        // delete[] arr;
    }
}

int small_set::test(int item)
{
    bool found = true;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == item)
        {
            found = false;
            break;
        }
    }
    if (!found)
        return 1;
    else
        return 0;
}