#include <iostream>
#include <string>
using namespace std;
int ain()
{
    string color;
    cout << "Enter the color of the traffic light: ";
    cin >> color;
    if (color == "red")
    {
        cout << "Stop" << endl;
    }
    else if (color == "yellow")
    {
        cout << "Slow down" << endl;
    }
    else if (color == "green")
    {
        cout << "Go" << endl;
    }
    else
    {
        cout << "Invalid color" << endl;
    }
    return 0;
}