#include <iostream>
using namespace std;

class twoDArray
{

private:
    const static int size = 5;
    int arr[size][size];
    int tempArr[size][size];

public:
    void Intialize()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Enter elememts of row no. " << i + 1 << " : ";
            for (int j = 0; j < size; j++)
            {
                cin >> arr[i][j];
            }
            cout << endl;
        }
    }
    void Print()
    {

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << arr[i][j] << "\t";
            }
            cout << endl;
        }
    }
    void Transpose()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {

                tempArr[i][j] = arr[j][i];
            }
        }
        cout << ">>>>>>>>Transpose<<<<<<<<<" << endl;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << tempArr[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void isSymmetric()
    {
        bool check = true;
        for (int i = 0; i < size && check; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (arr[i][j] != tempArr[i][j])
                {
                    check = false;
                    break;
                }
            }
        }

        if (check)
            cout << "The given array is symmetric" << endl;
        else
            cout << "The given array is not symmetric" << endl;
    }

    twoDArray multiply(twoDArray obj1, twoDArray obj2)
    {
        twoDArray temp;

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int t = 0;
                for (int k = 0; k < size; k++)
                {

                    t += (obj1.arr[i][k] * obj2.arr[k][j]);
                }
                temp.arr[i][j] = t;
            }
        }
        return temp;
    }
};
int main()
{
    twoDArray obj1, obj2, result, res;

    // int option;
    // cout << "1.Transpose: ";
    // cout << "2.Symmetric: ";
    // cout << "3.Multiply: ";
    // cout<<"4. print";
    // cin >> option;
    // switch (option)
    // {
    // case 1:
    //     a.Transpose;
    //     break;
    // case 2:
    //     a.isSymmetric();
    //     break;
    // case 3:
    //     res = res.multiply(obj1, obj2);
    //     res.Print();
    //     break;
    // }
    obj1.Intialize();
    obj2.Intialize();
    res = res.multiply(obj1, obj2);
    res.Print();

    cout << endl;
    a.Transpose();
    a.isSymmetric();

    return 0;
}