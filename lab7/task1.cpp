#include <iostream>
#include <vector>

using namespace std;
class person;
class date
{
private:
    int year;
    int day;
    int month;

public:
    date(int Year = 0, int Day = 0, int Month = 0)
    {
        this->year = Year;
        this->day = Day;
        this->month = Month;
    }

    bool operator<(date d)
    {
        if (year < d.year)
            return true;
        else if (month < d.month)
            return true;
        else if (day < d.day)
            return true;
        else
            return false;
    }
    bool operator>(date d)
    {
        if (year > d.year)
            return true;
        else if (month > d.month)
            return true;
        else if (day > d.day)
            return true;
        else
            return false;
    }
    friend ostream &operator<<(ostream &output, date d_obj)
    {
        output << d_obj.year << "-" << d_obj.month << "-" << d_obj.day;
        return output;
    }
    friend istream &operator>>(istream &input, date &d_obj)
    {
        cout << "Enter joining date (yyy mm dd): ";
        input >> d_obj.year >> d_obj.month >> d_obj.day;
        if (d_obj.year > 0 && d_obj.month > 0 && d_obj.month <= 12 && d_obj.day > 0 && d_obj.day <= 31)
            return input;
        else
        {
            cout << "---------------------------------\n";
            cout << "Date must follow given format: \n";
            cout << "Year greater than zero\n";
            cout << "Month between 1 to 12\n";
            cout << "Day between 1 to 31\n";
            cout << "---------------------------------\n";

            return input;
        }
    }
    friend class person;
};
class person
{
private:
    int id;
    string name;

public:
    date d;
    friend class date;
    static int count;
    person(int ID = 0, string Name = " ")
    {
        this->id = ID;
        this->name = Name;
        count++;
    }

    friend ostream &operator<<(ostream &output, const person &p_obj)
    {
        output << p_obj.name << " with ID " << p_obj.id;
        return output;
    }
    friend istream &operator>>(istream &input, person &p_obj)
    {
        cout << "Enter Name : ";
        input >> p_obj.name;
        cout << "Enter id: ";
        input >> p_obj.id;
        input >> p_obj.d;

        return input;
    }
};
int person::count = 0;

int main()
{
    /**
     * @brief
     * Two instances of person are given below and upon comparison
     * Number of people registered are printed below
     * We are comparing two people if we want to compare multiple we
     * can make array of persons
     *
     */
    person p1, p2;
    cin >> p1;
    cin.ignore();
    cin >> p2;
    if (p1.d < p2.d)

    {
        cout << p1;
        cout << " is senior to ";
        cout << p2 << "\nbecause " << p1.d << " is earlier than " << p2.d << endl;
    }
    else if(p1.d>p2.d)

    {
        cout << p2;
        cout << " is senior to ";
        cout << p1<< "\nbecause " << p2.d << " is earlier than " << p1.d << endl;
    }
    else
    cout<<"Both have same date of joining"<<endl;

    cout << "\n-----------Registered-People------------" << endl;
    cout << "The number of person are is " << p1.count<<endl;
    cout << "----------------------------------------" << endl;

    return 0;
}