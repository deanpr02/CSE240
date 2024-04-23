// CSE240 Spring 2023 Assignment 06
// Dean Prach

#include "employee.h"
#include <iostream>
#include <string>

#define MAX_EMPLOYEE 20

using namespace std;

// forward declaration of functions (already implemented)
void executeAction(char);
int addEmployee(string name_input, int salary_input, int yearOfPublication_input, int ID_input);
void displayEmployeesList(Employee e[], int currentCount);
void sortEmployeesBySalary(Employee e[], int currentCount,int lowerBound, int upperBound);
void updateEmployeeSalary(int ID_input);

Employee e[MAX_EMPLOYEE]; // array of objects
int currentCount = 0;     // number of employees in the list

int main()
{
    int addcondition = 0;
    addcondition = addEmployee("John", 10000, 2019, 101); // Expected Outcome: 1
    cout << "addcondition = " << addcondition << endl;
    addcondition = addEmployee("Emma", 9500, 2020, 102); // Expected Outcome: 1
    cout << "addcondition = " << addcondition << endl;
    addcondition = addEmployee("John", 15500, 2021, 102); // Expected Outcome: 0 (employee with ID 102 already exists)
    cout << "addcondition = " << addcondition << endl;
    addcondition = addEmployee("Michael", 17000, 2022, 103); // Expected Outcome: 1
    cout << "addcondition = " << addcondition << endl;
    addcondition = addEmployee("Sarah", 21000, 2018, 104); // Expected Outcome: 1
    cout << "addcondition = " << addcondition << endl;

    displayEmployeesList(e, currentCount); // should display the details of all employees added so far

    char choice = 'i'; // initialized to a dummy value
    do
    {
        cout << "\nCSE240 Assignment 06\n";
        cout << "Please select an action:\n";
        cout << "\t a: add a new employee\n";
        cout << "\t d: display employees list\n";
        cout << "\t s: sort the employees in descending order based on salary (within a range)\n";
        cout << "\t u: update the employee's salary respect to the employee's ID\n";
        cout << "\t q: quit\n";
        cin >> choice;
        cin.ignore(); // ignores the trailing \n
        executeAction(choice);
    } while (choice != 'q');

    return 0;
}

// Ask for details from user for the given selection and perform that action
// Read the function case by case
void executeAction(char c)
{
    string name_input;
    int upperBound;
    int lowerBound;
    int salary_input, yearOfStartDate_input, ID_input, result = 0;

    switch (c)
    {
    case 'a': // add an employee
              // input employee details from user
        cout << "Please enter employee name: ";
        getline(cin, name_input);
        cout << "Please enter salary of the employee: ";
        cin >> salary_input;
        cout << "Please enter the year of employee's start date: ";
        cin >> yearOfStartDate_input;
        cin.ignore();
        cout << "Please enter employee ID: ";
        cin >> ID_input;
        cin.ignore();

        // add the book to the list
        result = addEmployee(name_input, salary_input, yearOfStartDate_input, ID_input);
        if (result == 0)
            cout << "\nThat employee is already in the list or list is full! \n\n";
        else
            cout << "\nEmployee successfully added to the list! \n\n";
        break;

    case 'd': // display the list
        displayEmployeesList(e, currentCount);
        break;

    case 's': // sort the list
        cout << "Please enter the salary lower bound: ";
        cin >> lowerBound;
        cin.ignore();
        cout << "Please enter the salary upper bound: ";
        cin >> upperBound;
        cin.ignore();
        sortEmployeesBySalary(e, currentCount,lowerBound,upperBound);
        break;

    case 'u': // update the employee's salary respect to the ID
        cout << "Please enter employee ID: ";
        cin >> ID_input;
        cin.ignore();
        updateEmployeeSalary(ID_input);
        break;

    case 'q': // quit
        break;

    default:
        cout << c << " is invalid input!\n";
    }
}

// Add the employee in 'e' (array of objects) only if there is remaining capacity in the array and if the employee does not already exist in the list
// Check the id of the employee to check if the employee already exist in the list.
// This function returns 1 if the book is added successfully, else it returns 0 for the cases mentioned above.
int addEmployee(string name_input, int salary_input, int yearOfStartDate_input, int ID_input)
{
    // Checks if the list is at max capacity; if it is, return 0
    if(currentCount == MAX_EMPLOYEE){
        return 0;
    }
    //This checks if the list already has the ID_input the user is trying to add to the list; if the list already has this ID, return 0.
    for(int i =0; i<currentCount;i++){
        if(e[i].getID() == ID_input){
            return 0;
        }
    }
    //Creates an Employee object and sets its variables to the inputs the user input and increments current count.
    Employee employ;
    employ.setName(name_input);
    employ.setSalary(salary_input);
    employ.setYearOfStartDate(yearOfStartDate_input);
    employ.setID(ID_input);
    e[currentCount] = employ;
    ++currentCount;
    return 1; 
    
}

// Display the employees from array 'e' from index '0' to 'currentCount-1'. 
// You can call the class method 'displayEmployeeDetails()' here. Note that these are two different things.
// Employee::displayEmployeeDetails() displays details of one Employee object, while displayEmployeesList() should display all employees in the list.
void displayEmployeesList(Employee e[], int currentCount)
{
    //Goes through the entire list and uses the method implemented to print the details of all the employees.
    for(int i =0; i< currentCount;i++){
        e[i].displayEmployeeDetails();
    }
}

// This function sorts the employees in descending order respect to salary, and then display the employees within a given range of salary.
// You may use the 'tempEmployee' object for sorting logic, if needed.
void sortEmployeesBySalary(Employee e[], int currentCount,int lowerBoundSalary, int upperBoundSalary)
{
    Employee tempEmployee;
    //Goes through the entire list and checks each member of the list to put the list in increasing order; then if finds the salarys in the range
    //provided and prints only those objects.
    for(int i = 0; i<currentCount;i++){
        for(int j = i+1; j< currentCount;j++){
            if(e[j].getSalary() < e[i].getSalary()){
                tempEmployee = e[i];
                e[i] = e[j];
                e[j] = tempEmployee;
                j = i+1;
            }
        }
    }
    for(int k = 0;k<currentCount;k++){
        if(e[k].getSalary() >= lowerBoundSalary && e[k].getSalary() <= upperBoundSalary){
            e[k].displayEmployeeDetails();
        }
    }

}

// This functions updates the salary of an employee based on the employee ID.
// Note that the employee ID is unique for each employee.
// If the employee ID is not found in the list, display a message "Employee ID not found!".
// If the employee ID is found, ask the user for the new salary and update the salary of the employee.
// NOTE: By updating the salary, the value of 'tax' and 'bonus' will also change.
void updateEmployeeSalary(int ID_input)
{
    bool ans = false;
    int newSalary = 0;
    //This will have the user input the desired new salary for a specific ID and then it will change the salary.
    //IF the ID is not found in the list then it will print "Employee not found"
    for(int i = 0; i< currentCount; i++){
        if(e[i].getID() == ID_input){
            ans = true;
            cout << "Please enter the new salary: ";
            cin >> newSalary;
            cin.ignore();
            e[i].setSalary(newSalary);
        }
    }
    if(ans == false){
        cout<<"Employee ID not found!";
    }
}
