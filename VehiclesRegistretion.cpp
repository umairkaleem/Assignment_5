#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

struct Vehicle
{
    string plate;
    string color;
    string model;
    string brand;
};

void displayVehicles(const vector<Vehicle>& vehicles) {
    cout << "\n--- Vehicle Information ---\n";
    for (size_t i = 0; i < vehicles.size(); ++i) {
        cout << "\nVehicle " << i + 1 << ":\n";
        cout << "Plate: " << vehicles[i].plate << endl;
        cout << "Color: " << vehicles[i].color << endl;
        cout << "Model: " << vehicles[i].model << endl;
        cout << "Brand: " << vehicles[i].brand << endl;
    }
}

void editVehicle(vector<Vehicle>& vehicles) {
    string plateToEdit;
    cout << "\nEnter the plate number of the vehicle to edit: ";
    cin.ignore();  // To clear the newline character left by previous input
    getline(cin, plateToEdit);

    bool found = false;
    for (size_t i = 0; i < vehicles.size(); ++i) {
        if (vehicles[i].plate == plateToEdit) {
            found = true;
            cout << "\nEditing vehicle with plate: " << plateToEdit << endl;

            // Allow the user to modify the vehicle's information
            cout << "Enter new color (current: " << vehicles[i].color << "): ";
            getline(cin, vehicles[i].color);
            cout << "Enter new model (current: " << vehicles[i].model << "): ";
            getline(cin, vehicles[i].model);
            cout << "Enter new brand (current: " << vehicles[i].brand << "): ";
            getline(cin, vehicles[i].brand);
            cout << "Vehicle details updated!" << endl;
            break;
        }
    }

    if (!found) {
        cout << "No vehicle found with the plate number " << plateToEdit << endl;
    }
}

int main()
{
    vector<Vehicle> vehicles;  // Vector to store multiple vehicles
    char choice;
    char editChoice;

    do {
        Vehicle v;

        // Input vehicle details from the user
        cout << "\nEnter vehicle details:" << endl;
        cout << "Enter vehicle plate: ";
        getline(cin, v.plate);
        
        cout << "Enter vehicle color: ";
        getline(cin, v.color);
        
        cout << "Enter vehicle model: ";
        getline(cin, v.model);
        
        cout << "Enter vehicle brand: ";
        getline(cin, v.brand);

        // Store the entered vehicle data in the vector
        vehicles.push_back(v);

        // Ask if the user wants to input data for another vehicle
        cout << "\nDo you want to enter another vehicle? (y/n): ";
        cin >> choice;
        cin.ignore();  // To clear the newline character left by cin

    } while (choice == 'y' || choice == 'Y');  // Repeat if user enters 'y' or 'Y'

    // Allow the user to edit an existing vehicle's details
    cout << "\nDo you want to edit a vehicle's details? (y/n): ";
    cin >> editChoice;
    cin.ignore();  // To clear the newline character left by cin

    if (editChoice == 'y' || editChoice == 'Y') {
        editVehicle(vehicles);  // Call function to edit a vehicle
    }

    // Display the entered vehicle information
    displayVehicles(vehicles);

    // Optionally, you can save the vehicle information to a file
    ofstream outFile("vehicle_info.txt");
    if(outFile.is_open())
    {
        outFile << "--- Vehicle Information ---\n";
        for (size_t i = 0; i < vehicles.size(); ++i) {
            outFile << "\nVehicle " << i + 1 << ":\n";
            outFile << "Plate: " << vehicles[i].plate << endl;
            outFile << "Color: " << vehicles[i].color << endl;
            outFile << "Model: " << vehicles[i].model << endl;
            outFile << "Brand: " << vehicles[i].brand << endl;
        }
        outFile.close();
        cout << "\nInformation saved to vehicle_info.txt" << endl;
    }
    else
    {
        cout << "\nUnable to open file to save information." << endl;
    }

    return 0;
}
