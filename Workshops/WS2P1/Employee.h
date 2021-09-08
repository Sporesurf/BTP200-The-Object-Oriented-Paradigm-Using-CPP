#ifndef SDDS_EMPLOYEE_H
#define SDDS_EMPLOYEE_H
#define DATAFILE "employees.csv"

namespace sdds 
{
    struct Employee 
    {
        char* m_name;
        int m_empNo;
        double m_salary;
    };

    // Sorts the dynamic array of employees based on the GPA of the employees.
    void sort();
    // Loads a employee structue with its values from the file
    bool load(Employee& employees);
    // Allocates the dyanmic array of employees and loads all the file
    bool load();
    // Displays a employee record on the screen:
    void display(const Employee& employees);
    // Dirst sorts the employees then displays all the employees on the screen
    void display();
    // Deallocates dynamic memory.
    void deallocateMemory();
}
#endif // SDDS_EMPLOYEE_H