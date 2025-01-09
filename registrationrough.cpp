#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

string CurrentTime() 
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int hour = ltm->tm_hour;
    int min = ltm->tm_min;
    int sec = ltm->tm_sec;
    
    // Format the time as a string in HH:MM:SS format
    stringstream timeStream;
    timeStream << setw(2) << setfill('0') << hour << ":"
               << setw(2) << setfill('0') << min << ":"
               << setw(2) << setfill('0') << sec;
    
    return timeStream.str(); // Return the formatted time as a string
}

int main()
{
    cout << "Welcome to the Traffic Light Management System" << endl;

    bool emergency = false;  // Flag to check if there's an emergency

    while (1)
    {
        // If there is an emergency, show red light immediately
        if (emergency)
        {
            string Time = CurrentTime();
            cout << "Emergency Mode: Red Light - Stop at " << Time << endl;
            this_thread::sleep_for(chrono::seconds(5));  // Keep red light on for 5 seconds
            cout << "You can clear the emergency to continue the cycle." << endl;

            // After the emergency mode is handled, ask the user if they want to continue or exit
            cout << "Do you want to exit after the emergency or continue the traffic light cycle? (e - exit, c - continue): ";
            char choice;
            cin >> choice;
            
            if (choice == 'e' || choice == 'E') {
                break; // Exit the program after the emergency
            } 
            else if (choice == 'c' || choice == 'C') {
                emergency = false; // Clear the emergency and continue with the regular cycle
                continue; // Go back to the regular traffic light cycle
            }
        }

        // Normal traffic light cycle
        string Time = CurrentTime();
        
        // Show the Green light for 5 seconds
        cout << "Green Light - Go at " << Time << endl;
        this_thread::sleep_for(chrono::seconds(5));  // Wait for 5 seconds

        // Get the current time after the green light
        Time = CurrentTime();
        
        // Show the Yellow light for 2 seconds
        cout << "Yellow Light - Ready at " << Time << endl;
        this_thread::sleep_for(chrono::seconds(2));  // Wait for 2 seconds

        // Get the current time after the yellow light
        Time = CurrentTime();
        
        // Show the Red light for 5 seconds
        cout << "Red Light - Stop at " << Time << endl;
        this_thread::sleep_for(chrono::seconds(5));  // Wait for 5 seconds

        // Option to exit or continue the cycle
        cout << "Do you want to continue the cycle or handle an emergency? (c - continue, e - emergency, n - exit): ";
        char choice;
        cin >> choice;
        
        if (choice == 'n' || choice == 'N') {
            break; // Exit the loop if the user enters 'n' or 'N'
        }
        else if (choice == 'e' || choice == 'E') {
            emergency = true;  // Trigger the emergency mode
            cout << "Emergency detected! Traffic light will stay red until cleared." << endl;
            continue; // Skip the normal cycle and wait for emergency
        }
        else if (choice == 'c' || choice == 'C') {
            emergency = false;  // Clear emergency and continue normal operation
        }
    }

    cout << "You have exited the system" << endl;
    cout << "Thank you for using the Traffic Light Management System" << endl;

    return 0;
}
