#include <iostream>// this is used for input and output
// This is a preprocessor directive that includes the contents of the iostream file in the program.
#include <fstream>// this is used for file handling
#include <string>// this is used for string handling
// string means a sequence of characters
// For example, "Hello, World!" is a string
#include <vector>// this is used for vector handling
// vector is a container that can store multiple values of the same type
// For example, you can store multiple integers in a vector
// or you can store multiple strings in a vector
#include <iomanip>// this is used for input and output manipulation
// Manipulation means changing the format of the output
// For example, if you want to display the output in a specific format
// like you want to display the output in a specific number of decimal places
// or you want to set the width of the output
// or you want to fill the empty space with a specific character

using namespace std;
// this is used to avoid writing std:: before cout, cin, endl, etc.
// For example, instead of writing std::cout, you can write cout

// Structures for vehicle and violation details
// this struct vehicle is used to store the details of the vehicle
struct Vehicle {
    // A structure is a user-defined data type in C++ that allows you to store multiple values of different data types in a single variable.
    // A structure is a collection of variables of different data types under a single name.
    // For example, you can create a structure called 'Person' that contains variables like 'name', 'age', and '
    string ownerName;
    string vehicleID;
    string vehicleType;
    string licensePlate;
    string registrationDate;
    // The 'string' data type is used to store a sequence of characters.
    // why we use string ownerName; instead of char ownerName[50]; because string is a class in C++ that represents a sequence of characters.
    // The 'string' class is part of the C++ Standard Library.
};
    //  struct violation is used to store the details of the violation
struct Violation {
    string violationID;
    string vehicleID;
    string type;
    string dateTime;
    double fineAmount;
    // The 'double' data type is used to store decimal numbers.
    //the string violationID; string vehicleID; string type; string dateTime; double fineAmount;
    // these are the variables of the struct Violation
};

// Traffic light management (example for 3 intersections)
// enum is used to define a set of named constants
// enum is a user-defined data type that consists of integral constants.
enum LightState { RED, YELLOW, GREEN };
LightState trafficLights[3];
// The 'enum' keyword is used to define a set of named constants.

// void manageTrafficLights() is a function that is used to manage the traffic lights
// this function is used to change the traffic lights from red to green and green to yellow and yellow to red
void manageTrafficLights() 
{   // this is a for loop that is used to change the traffic lights from red to green and green to yellow and yellow to red
    for (int i = 0; i < 3; i++)
     {// this is a if else statement that is used to change the traffic lights from red to green and green to yellow and yellow to red
        if (trafficLights[i] == RED) trafficLights[i] = GREEN;
        // if the traffic light is red then it will change to green
        else if (trafficLights[i] == GREEN) trafficLights[i] = YELLOW;
        // if the traffic light is green then it will change to yellow
        else trafficLights[i] = RED;
        // if the traffic light is yellow then it will change to red
        cout << "Intersection " << i + 1 << " Light: "
             << (trafficLights[i] == RED ? "RED" : trafficLights[i] == YELLOW ? "YELLOW" : "GREEN") << endl;
             // this is a cout statement that is used to display the traffic lights
    }
}

// vehicle registration and traffic violations (file handling)
// Vehicle registration
vector<Vehicle> vehicles;
// vector is a container that can store multiple values of the same type
// vector<vehicle> vehicles; this is a vector that is used to store the details of the vehicle
// vehicle is a struct that is used to store the details of the vehicle
// but why use in <vehicle> because we can store multiple values of the same type in a vector
// we used vector because we can store multiple values of the same type in a vector


// void registerVehicle() is a function that is used to register the vehicle
// this function is used to register the vehicle
void registerVehicle()
{  
    Vehicle v;
    // this is a struct vehicle that is used to store the details of the vehicle
    // vehicle v; this is a variable of the struct vehicle but where the use of struct vehicle is used to store the details of the vehicle
    // it is used to store the details of the vehicle
    cout << "Enter Vehicle ID: "; cin >> v.vehicleID;
    // this is a cout statement that is used to display the Enter Vehicle ID
    cout << "Enter Owner Name: "; cin.ignore(); getline(cin, v.ownerName);
    // this is a cout statement that is used to display the Enter Owner Name
    cout << "Enter Vehicle Type: "; cin >> v.vehicleType;
    // this is a cout statement that is used to display the Enter Vehicle Type
    cout << "Enter License Plate: "; cin >> v.licensePlate;
    // this is a cout statement that is used to display the Enter License Plate
    cout << "Enter Registration Date: "; cin >> v.registrationDate;
    // this is a cout statement that is used to display the Enter Registration Date
    vehicles.push_back(v);
    // this is a push_back function that is used to store the details of the vehicle
    //.push_back()is a fuction (v) is a variable of the struct vehicle
    


// ofstream file("vehicles.txt", ios::app); this is a file handling that is used to store the details of the vehicle
    ofstream file("vehicles.txt", ios::app);
    // ofstream is used to create and write to files
    // file is a variable of the ofstream
    // vehicles.txt is a file name
    // ios::app is a flag that is used to append the content of the file
    file << v.vehicleID << "," << v.ownerName << "," << v.vehicleType << ","
         << v.licensePlate << "," << v.registrationDate << endl;
         // this is a file handling that is used to store the details of the vehicle
         // file << v.vehicleID << "," << v.ownerName << "," << v.vehicleType << ","
         // << v.licensePlate << "," << v.registrationDate << endl; this is a file handling that is used to store the details of the vehicle
    file.close();
    // file.close(); this is a file handling that is used to close the file

    cout << "Vehicle registered successfully!\n";
    // this is a cout statement that is used to display the Vehicle registered successfully!
    
}


// void displayVehicles() is a function that is used to display the details of the vehicle
void displayVehicles() 
{  
// cout << "\nRegistered Vehicles:\n"; this is a cout statement that is used to display the Registered Vehicles
    cout << "\nRegistered Vehicles:\n";
    for (const auto& v : vehicles) 
    {   // this is a for loop that is used to display the details of the vehicle
         //but why use it  the answer is in const auto& v : vehicles because we can store multiple values of the same type in a vector
        cout << "ID: " << v.vehicleID << " | Owner: " << v.ownerName
             << " | Type: " << v.vehicleType << " | Plate: " << v.licensePlate
             << " | Date: " << v.registrationDate << endl;
                // this is a cout statement that is used to display the details of the vehicle
                // cout << "ID: " << v.vehicleID << " | Owner: " << v.ownerName
    }

}



// Traffic violations
// ask this question from you sir that why we use vector<Violation> violations; instead of vector<vehicle> vehicles;
// the answer is that we use vector<Violation> violations; because we can store multiple values of the same type in a vector
vector<Violation> violations;
void recordViolation()
// void recordViolation() is a function that is used to record the violation
 {
    Violation v;
    // this is a struct violation that is used to store the details of the violation
    cout << "Enter Violation ID: "; cin >> v.violationID;
    // this is a cout statement that is used to display the Enter Violation ID
    cout << "Enter Vehicle ID: "; cin >> v.vehicleID;
    // this is a cout statement that is used to display the Enter Vehicle ID
    cout << "Enter Violation Type (Over-Speeding, Signal Jumping, etc.): ";
    // this is a cout statement that is used to display the Enter Violation Type (Over-Speeding, Signal Jumping, etc.)
    cin.ignore(); getline(cin, v.type);
    // this is a cin.ignore(); getline(cin, v.type); this is a cin statement that is used to get the input from the user
    // cin.ignore(); is used to ignore the newline character in the input buffer
    //buffer is a temporary storage area
    //getline(cin,v.type) which mean that the input is stored in the variable v.type and v.type means that the type of the violation
    cout << "Enter Date and Time: "; getline(cin, v.dateTime);
    // this is a cout statement that is used to display the Enter Date and Time
    // getline used to read line from the input stream the user enter date 01/01/2022 and time 12:00 PM read all the line
    // when we not used getline only read some part of the line like 01/01.
    cout << "Enter Fine Amount: "; cin >> v.fineAmount;
    // this is a cout statement that is used to display the Enter Fine Amount
    // but i ask the why we use cin >> v.fineAmount; the answer is that we use cin >> v.fineAmount; because we can get the input from the user
    // v.fineAmount is a variable of the struct violation that is used to store the fine amount
    violations.push_back(v);
    // this is a push_back function that is used to store the details of the violation

    ofstream file("violations.txt", ios::app);
    // ofstream is used to create and write to files
    // file is a variable of the ofstream
    // violations.txt is a file name
    // ios::app is a flag that is used to append the content of the file
    file << v.violationID << "," << v.vehicleID << "," << v.type << ","
         << v.dateTime << "," << v.fineAmount << endl;
         // this is a file handling that is used to store the details of the violation
    file.close();
    // file.close(); this is a file handling that is used to close the file

    cout << "Violation recorded successfully!\n";
    // this is a cout statement that is used to display the Violation recorded successfully!
}

// Display traffic violations it is a function that is used to display the details of the violation
void displayViolations()
 {  
    cout << "\nTraffic Violations:\n";
    // this is a cout statement that is used to display the Traffic Violations
    for (const auto& v : violations) 
    {
        cout << "Violation ID: " << v.violationID << " | Vehicle ID: " << v.vehicleID
             << " | Type: " << v.type << " | Date & Time: " << v.dateTime
             << " | Fine: " << v.fineAmount << endl;
             // this is a cout statement that is used to display the details of the violation
    }
}

// Real-time traffic monitoring
// Traffic density (example for 3x3 grid)
//what does it mean traffic density the answer is that the traffic density is the number of vehicles passing through a specific area in a specific amount of time.
//what does it mean 3x3 grid the answer is that the 3x3 grid is a grid that is used to store the traffic density
char trafficDensity[3][3]; // 3x3 grid for intersections
// why use char tafficDensity[3][3]; instead of int trafficDensity[3][3]; the answer is that we use char tafficDensity[3][3]; because we can store the traffic density in the form of L/M/H
void updateTrafficDensity()
// void updateTrafficDensity() is a function that is used to update the traffic density
 {
    cout << "\nUpdate Traffic Density:\n";
    // this is a cout statement that is used to display the Update Traffic Density
    for (int i = 0; i < 3; i++)
     {  // this is a for loop that is used to update the traffic density
        for (int j = 0; j < 3; j++)
         {//but also the above for loop is used to update the traffic density
         // answer is that the above for loop is used to update the traffic density but this one is used to get the input from the user
         // it is also called the nested for loop
            cout << "Enter density for Intersection (" << i + 1 << "," << j + 1 << ") (L/M/H): ";
            // this is a cout statement that is used to display the Enter density for Intersection
            cin >> trafficDensity[i][j];
            // this is a cin statement that is used to get the input from the user
            // but we use [i][j] because we can store the traffic density in the form of L/M/H
            // trafficDensity[i][j] is a variable of the char trafficDensity[3][3]; that is used to store the traffic density
            // but it is 2d arry because we can store the traffic density in the form of L/M/H
        }
    }
}


// void display traffic density() is a function that is used to display the traffic density
void displayTrafficDensity() 
{
    cout << "\nCurrent Traffic Density:\n";
    // this is a cout statement that is used to display the Current Traffic Density
    for (int i = 0; i < 3; i++) 
    {// this is a for loop that is used to display the traffic density
        for (int j = 0; j < 3; j++) 
        { // also above one same why we use it because we can store the traffic density in the form of L/M/H
            cout << trafficDensity[i][j] << " ";
            // this is a cout statement that is used to display the traffic density
            //[i][j] gave the output in the form of L/M/H because we can store the traffic density in the form of L/M/H matrix
        }
        cout << endl;
        //this is cout statement that is used to display the next line of the output
    }
}



// Admin dashboard
// void adminDashboard() is a function that is used to display the admin dashboard
void adminDashboard() 
{
    int choice;
    // this is a variable that is used to store the choice of the user
    do {
        // this is a do while loop that is used to display the admin dashboard
        cout << "\nAdmin Dashboard:\n";
        // this is a cout statement that is used to display the Admin Dashboard
        cout << "1. Manage Traffic Lights\n";
        // this is a cout statement that is used to display the Manage Traffic Lights
        cout << "2. Register Vehicle\n";
        // this is a cout statement that is used to display the Register Vehicle
        cout << "3. Display Vehicles\n";
        // this is a cout statement that is used to display the Display Vehicles
        cout << "4. Record Traffic Violation\n";
        // this is a cout statement that is used to display the Record Traffic Violation
        cout << "5. Display Violations\n";
        // this is a cout statement that is used to display the Display Violations
        cout << "6. Update Traffic Density\n";
        // this is a cout statement that is used to display the Update Traffic Density
        cout << "7. Display Traffic Density\n";
        // this is a cout statement that is used to display the Display Traffic Density
        cout << "8. Exit\n";
        // this is a cout statement that is used to display the Exit
        cout << "Enter your choice: "; cin >> choice;
        // this is a cin statement that is used to get the input from the user

// switch (choice) is a switch statement that is used to select the choice of the user
        switch (choice) 
        {
            case 1: manageTrafficLights(); break;
            // this is a case 1 that is used to manage the traffic lights
            // which we call the function manageTrafficLights() which is used to manage the traffic lights
            case 2: registerVehicle(); break;
            // this is a case 2 that is used to register the vehicle
            // which we call the function registerVehicle() which is used to register the vehicle
            // but why we use break; the answer is that we use break; because it is used to terminate the case
            case 3: displayVehicles(); break;
            // this is a case 3 that is used to display the details of the vehicle
            // which we call the function displayVehicles() which is used to display the details of the vehicle
            case 4: recordViolation(); break;
            // this is a case 4 that is used to record the violation
            // which we call the function recordViolation() which is used to record the violation
            case 5: displayViolations(); break;
            case 6: updateTrafficDensity(); break;
            case 7: displayTrafficDensity(); break;
            case 8: cout << "Exiting Admin Dashboard...\n"; break;
            // this is the case 8 when admin want to exit from the program the progream will be end 
            default: cout << "Invalid choice!\n"; break;
            // it is default statement when the admin enter Wrong choicethe programwill execute this message your choice is invalid
        }
    } while (choice != 8);
    // this is the while condaiton if this ture the enter progream will Execut ewhen the user enter8 the photogram will be indeed
}

int main() {
    // Initialize traffic lights to RED
    for (int i = 0; i < 3; i++) trafficLights[i] = RED;
    

    // Initialize traffic density to 'L'
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            trafficDensity[i][j] = 'L';

    adminDashboard();
    return 0;
}
