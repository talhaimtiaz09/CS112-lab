#include <iostream>
using namespace std;
int main()
{
    float length, width;
    cout << "Enter the lenght of rectangle : ";
    cin >> length;
    cout << "Enter the width of rectangle : ";
    cin >> width;

    cout << "\n\nInt\n";
    cout << "The area of rectangle is: " << static_cast<int>(length * width) << endl;
    cout << "\nFloat\n";
    cout << "The area of rectangle is: " << length * width << endl;

    return 0;
}