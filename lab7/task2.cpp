#include <iostream>
using namespace std;

class matrix
{
private:
    const int row;
    const int col;
    int **arr;

public:
    matrix(int r = 1, int c = 1) : row(r), col(c)
    {
        this->arr = new int *[row];
        for (int i = 0; i < row; i++)
        {
            this->arr[i] = new int[col];
        }
        for (int i = 0; i < this->row; i++)
            for (int j = 0; j < this->col; j++)
                this->arr[i][j] = 0;
    }
    
    matrix operator+(matrix m)
    {
        matrix res(row, col);
        if (this->row == m.row && this->col == m.col)
        {
            for (int i = 0; i < this->row; i++)
            {
                for (int j = 0; j < this->col; j++)
                {
                    res.arr[i][j] = this->arr[i][j] + m.arr[i][j];
                }
            }
        }
        else
        {
            cout << "For additiion rows and columns of both matrices should be same" << endl;
        }
        return res;
    }
    matrix operator-(matrix m)
    {
        matrix res(row, col);
        if (this->row == m.row && this->col == m.col)
        {
            for (int i = 0; i < this->row; i++)
            {
                for (int j = 0; j < this->col; j++)
                {
                    res.arr[i][j] = (this->arr[i][j] - m.arr[i][j]);
                }
            }
        }
        else
        {
            cout << "For additiion rows and columns of both matrices should be same" << endl;
        }
        return res;
    }
    matrix operator*(matrix m)
    {
        matrix res(row, m.col);
        if (this->col == m.row)
        {
            for (int i = 0; i < this->row; ++i)
                for (int j = 0; j < m.col; ++j)
                    for (int k = 0; k < this->col; ++k)
                    {
                        res.arr[i][j] += this->arr[i][k] * m.arr[k][j];
                    }
        }
        else
            cout << "Row of first and columns of second should be equal" << endl;
        return res;
    }
    friend ostream &operator<<(ostream &out, matrix m)
    {
        for (int i = 0; i < m.row; i++)
        {
            for (int j = 0; j < m.col; j++)
            {
                out << m.arr[i][j] << "\t";
            }
            out << endl;
        }
        return out;
    }
    void operator=(matrix m)
    {
        if (this->row == m.row && this->col == m.col)
        {
            for (int i = 0; i < m.row; i++)
                for (int j = 0; j < m.col; j++)
                    this->arr[i][j] = m.arr[i][j];
        }
        else
            cout << "Both objects must have same size!" << endl;
    }
    friend istream &operator>>(istream &in, matrix &m)
    {
        cout << "-------------------------" << endl;
        cout << "Enter elements separated by spaces: " << endl;
        for (int i = 0; i < m.row; i++)
        {
            cout << "Elements of row " << i + 1 << " : ";
            for (int j = 0; j < m.col; j++)
            {
                in >> m.arr[i][j];
            }
        }
        cout << "-------------------------" << endl;

        return in;
    }
};

int main()
{
    matrix m1(3, 3), m2(3, 3), m3(3, 3);
    /**
     * @brief
     * A sample is given below
       | 1 2 3 |      | 4 5 6 |
    m1=| 1 2 3 |   m2=| 4 5 6 |
       | 1 2 3 |      | 4 5 6 |

    m3=m2+m1
       | 5 7 9 |
    m3=| 5 7 9 |
       | 5 7 9 |
    m3=m1-m2;
       | -3 -3 -3 |
    m3=| -3 -3 -3 |
       | -3 -3 -3 |

    m_multiply=m4*m5
    
    m4=|1 2 3|      |10 11|
       |4 5 6|   m5=|20 21|
                    |30 31|
    
    
    m_multiply=|140 146|
               |320 321|

     */
    cin >> m1;
    cin >> m2;
    cout << "------Addition---------" << endl;
    m3 = m1 + m2;
    cout << m3;
    cout << "------Subtraction------" << endl;
    m3 = m1 - m2;
    cout << m3;
    cout << "------Multiplication---" << endl;
    matrix m4(2,3),m5(3,2),m_multiply(2,2);
    cin>>m4>>m5;
    m_multiply = m4 * m5;
    cout << m_multiply;
    cout << endl;

    return 0;
}