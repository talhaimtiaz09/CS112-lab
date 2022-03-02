#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
struct student
{
    string name;
    string reg;
    string deg;
    int courses;
    float sgpa;
};
// fuction to calculate gpa according to marks out of 100
double gpa_func(int marks)
{
    double gp;
    if (marks > 86)
        gp = 4;
    else if (82 < marks && marks <= 86)
        gp = 3.67;
    else if (78 < marks && marks <= 82)
        gp = 3.33;
    else if (74 < marks && marks <= 78)
        gp = 3;
    else if (70 < marks && marks <= 74)
        gp = 2.67;
    else if (66 < marks && marks <= 70)
        gp = 2.33;
    else if (50 < marks && marks <= 66)
        gp = 2;
    else
        gp = 1.67;

    return gp;
}
// sorting the students
void sortGpa(student arr[3])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2 - i; j++)
        {
            if (arr[j].sgpa < arr[j + 1].sgpa)
                swap(arr[j], arr[j + 1]);
        }
    }
}

int main()
{
    student s[3];
    int courses;

    for (int i = 0; i < 3; i++)
    {
        double gpa = 0;
        cout << "Enter reocord of student " << i + 1 << endl;

        cout << "Enter your name: ";
        getline(cin, s[i].name);
        cout << "Enter your reg no : ";
        getline(cin, s[i].reg);
        cout << "Enter your degree program: ";
        getline(cin, s[i].deg);
        cout << "Enter your no. of courses: ";
        cin >> courses;

        int marks = 0;
        double g = 0;
        for (int j = 0; j < courses; j++)
        {
            cout << "Enter your marks of course no." << j + 1 << " : ";
            cin >> marks;
            // calculatin sum of gpa*credit hours of all courses registered
            g += (gpa_func(marks) * 3);
        }
        // calculating and saving sgpa of user
        s[i].sgpa = g / (courses * 3);
        cin.ignore();
    }

    cout << "S.No" << setw(10) << "Name" << setw(10) << "Reg. No" << setw(10) << "Degree Program" << setw(10) << "SGPA" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << setw(10) << s[i].name << setw(10) << s[i].reg << setw(10) << s[i].deg << setw(10) << s[i].sgpa << endl;
    }
    // Funtion to sort students according to their sgpa
    sortGpa(s);

    // printing sorted list of students
    cout << "______________________________________" << endl;
    cout << "S.No" << setw(10) << "Name" << setw(10) << "Reg. No" << setw(10) << "Degree Program" << setw(10) << "SGPA" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << setw(10) << s[i].name << setw(10) << s[i].reg << setw(10) << s[i].deg << setw(10) << s[i].sgpa << endl;
    }

    // printing best of them
    cout << endl
         << "______________________________________" << endl
         << "Best of students is: " << endl;
    cout << "1" << setw(10) << s[0].name << setw(10) << s[0].reg << setw(10) << s[0].deg << setw(10) << s[0].sgpa << endl;
    return 0;
}