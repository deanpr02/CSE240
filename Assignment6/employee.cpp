// CSE240 Spring 2023 Assignment 06
// Dean Prach

#include "employee.h"
#include <iostream>
#include <string>

using namespace std;

// Q1 Employee constructor
// Employee() constructor assigns the following default values to class data members
// name: abc
// salary (monthly): 10000
// yearOfStartDate: 2000
// ID: 0
Employee::Employee()
{
    m_name = "abc";
    m_salary = 10000;
    m_yearOfStartDate = 2000;
    m_ID = 0;
}

// setName assigns 'name_input' to class data member 'name'
void Employee::setName(string name_input)
{
    m_name = name_input;
}

// setSalary assigns salary_input to class data member 'salary'
void Employee::setSalary(int salary_input)
{
    m_salary = salary_input;
}

// setYearOfStartDate assigns 'yearOfStartDate_input' to class data member 'yearOfStartDate'
void Employee::setYearOfStartDate(int yearOfStartDate_input)
{
    m_yearOfStartDate = yearOfStartDate_input;
}

// setID assigns 'ID_input' to class data member 'ID'
void Employee::setID(int ID_input)
{
    m_ID = ID_input;
}

// calculateBonus returns the class data member 'bonus'.
// Bonus is calculated as follows:
// If salary is less than or equal to 10000, bonus is 5% of the salary.
// If salary is between 10001 and 20000, bonus is 10% of the salary.
// If salary is greater than 20000, bonus is 15% of the salary.
float Employee::calculateBonus(int salary_input)
{
    float bonus = 0;
    if(salary_input <= 10000){
        bonus = salary_input *0.05;
    }
    else if(salary_input >= 10001 && salary_input <= 20000){
        bonus = salary_input*0.1;
    }
    else if(salary_input > 20000){
        bonus = salary_input *0.15;
    }
    return bonus;
}

// calculateTax returns the class data member 'tax'.
// Tax is calculated as follows:
// If salary is less than or equal to 10000, tax is 0%.
// If salary is greater than 10000 and less than or equal to 20000, tax is 10%.
// If salary is greater than 20000, tax is 20%.
float Employee::calculateTax(int salary_input)
{
    float tax = 0;
    if(salary_input <= 10000){
        tax = 0;
    }
    else if(salary_input > 10000 && salary_input <= 20000){
        tax = 0.1*salary_input;
    }
    else if(salary_input > 20000){
        tax = 0.2*salary_input;
    }
    return tax;
}

// displayEmployee displays the name, salary, Start Date Year, ID, Bonus and Tax of the employee
// See expected output in question file.
void Employee::displayEmployeeDetails()
{
    cout << "Name: " << m_name << endl;
    cout << "Salary: " << m_salary << endl;
    cout << "Start Date Year: " << m_yearOfStartDate << endl;
    cout << "ID: " << m_ID << endl;
    cout << "Bonus: " << calculateBonus(m_salary) << endl;
    cout << "Tax: " << calculateTax(m_salary) << endl;
    cout << "-----------------------------\n";
}

// getName returns the class data member 'name'.
string Employee::getName()
{
    return m_name;
}

// getSalary returns the class data member 'salary'.
int Employee::getSalary()
{
    return m_salary;
}

// getYearOfStartDate returns the class data member 'yearOfPublication'.
int Employee::getYearOfStartDate()
{
    return m_yearOfStartDate;
}

// getID returns the class data member 'ID'.
int Employee::getID()
{
    return m_ID;
}
