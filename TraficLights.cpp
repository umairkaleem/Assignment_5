#include <iostream>
using namespace std;
int main()
{
 

    cout << "Welcome to Trafic Light Management System" << endl<<endl;
    while(1)
    {
    cout << "Select the color of the traffic light: " << endl;
    cout << "1-red------>Stop" << endl;
    cout << "2-yellow--->Ready" << endl;
    cout << "3-green---->Go" << endl;
    cout << "4-Exit" << endl;

    int colors;
    cout << "Enter the number of the color: ";
    cin >> colors;
    
    if (colors==4)
    {
        break;
    }

    switch(colors)
    {
        case 1:
        cout << "Stop" << endl;
        break;

        case 2:
        cout << "Ready" << endl;
        break;

        case 3:
        cout << "Go" << endl;
        break;

        default:
        cout << "Invalid color" << endl;
        break;
    }

    }
    cout<<"you have exited the system"<<endl;
    cout<<"Thank you for using Trafic Light Management System"<<endl;

}