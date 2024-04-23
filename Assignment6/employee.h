#ifndef employee_h
#define employee_h
#include <string>
using namespace std;

class Employee
{
private:
    string m_name; // data members
    int m_salary, m_yearOfStartDate, m_ID;

public:
    Employee(); // constructor

    // member methods
    void setName(string name_input);
    void setSalary(int salary_input);
    void setYearOfStartDate(int yearOfStartDate_input);
    void setID(int ID_input);
    float calculateBonus(int salary_input);
    float calculateTax(int salary_input);
    void displayEmployeeDetails();
    string getName();
    int getSalary();
    int getYearOfStartDate();
    int getID();
};
#endif