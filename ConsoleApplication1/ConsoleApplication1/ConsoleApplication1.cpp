/*Implement the "Car" structure (color, model, number). The car number can be a five-digit number or a word of up to 8 characters.
Create an instance of the "Machine" structure and implement the following functions for it:
Filling the machine;
Machine print.
Create an array of 10 instances of the "Machine" structure and implement the following functions for it:
Edit the car;
Printing of all machines;
Car search by number.*/

// Я написав програму для трьох машин тому що дуже довго вводити кожного разу інформацію для 10. Але, думаю, принцип той самий

#include <iostream>
#include <string>

using namespace std;

// Car structure
struct Car {

    string color;
    string model;
    string number;

    // Function to fill the car properties
    void Filling() {

        cout << "Enter color: ";
        cin >> color;
        cout << "Enter model: ";
        cin >> model;

        // Loop to check the car number to be a five-digit number or a word of up to 8 characters
        while (true) {

            cout << "Enter 5-digit number or word (up to 8 characters): ";
            cin >> number;

            // Using 'isdigit' and 'length' from <string> library to chek the input
            if ((number.length() <= 8 && !isdigit(number[0])) || (number.length() == 5 && isdigit(number[0]))) { 

                break;  // Valid input, exit the loop
            }
            else {

                cout << "Invalid input. Please enter a 5-digit number or word of up to 8 characters." << endl;
            }
        }
    }
    // Function to print properties of the car
    void Print() {

        cout << "Color: " << color << endl;
        cout << "Model: " << model << endl;
        cout << "Number: " << number << endl;
    }
};

void EditCar(Car cars[]);
void PrintAll(Car cars[]);
void Search(Car cars[]);

int main() {

    Car cars[3];

    // User enters properties for each car
    cout << "Car 1: " << endl;
    cars[0].Filling();
    cout << endl;
    cout << "Car 2: " << endl;
    cars[1].Filling();
    cout << endl;
    cout << "Car 3: " << endl;
    cars[2].Filling();
    cout << endl;

    // Loop to operate the menu
    while (true) {

        int choice = 0;

        cout << "\n\nEdit the car - 1\nPrinting of all machines - 2\nCar search by number - 3.\nExit - 4\nMake your choice: ";
        cin >> choice;

        if (choice == 1) {

            EditCar(cars); //Function call
        }
        else if (choice == 2) {

            PrintAll(cars); 
        }
        else if (choice == 3) {

            Search(cars);   
        }
        else if (choice == 4) { // Option to exit

            break;
            return 0;
        }
        else { // Exit if any other choice number is entered

            return 0;
        }
    }

    return 0;
}

// Function to edit the car
void EditCar(Car cars[]) {

    //Decide which car to edit
    string searchNum;
    cout << "\nEnter car number or word you want to edit: ";
    cin >> searchNum;

    // Loop to go through the array 
    for (int i = 0; i < 3; i++) {

        if (cars[i].number == searchNum) { // When find the car user can change it`s properties

            cout << "Enter new color: ";
            cin >> cars[i].color;
            cout << "Enter new model: ";
            cin >> cars[i].model;
            cout << "Enter new 5-digit number or word (up to 8 characters): ";
            cin >> cars[i].number;
            break; 
        }
    }
}

// Function to print all the cars
void PrintAll(Car cars[]) {

    // Using function Print from structure
    cout << "\nAll cars:\n" << endl;
    cout << "Car 1: " << endl;
    cars[0].Print();
    cout << endl;
    cout << "Car 2: " << endl;
    cars[1].Print();
    cout << endl;
    cout << "Car 3: " << endl;
    cars[2].Print();
}

// Function for search
void Search(Car cars[]) {

    string searchNum;
    cout << "Enter car number or word you want to search: ";
    cin >> searchNum;

    bool found = false;  // Track if a match is found

    // Loop to go through the array
    for (int i = 0; i < 3; i++) {

        if (cars[i].number == searchNum) {

            cout << "\nCar found:\n" << endl;
            cars[i].Print();
            found = true;  // Set found to true if a match is found
            break;
        }
    }

    if (!found) {
        cout << "Car not found." << endl;
    }
}
