/* Justin L Casey
PRG/218 - Online
Week 5 - Datamax, Inc. Overtime Pay Program
Brian Rague
11/30/15
Ver 1.0
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
//
//CLASS DECLARATION SECTION
//
class EmployeeClass {
public:
	void ImplementCalculations(string EmployeeName, double hours, double wage);
	void DisplayEmployInformation(void);
	void Addsomethingup(EmployeeClass, EmployeeClass, EmployeeClass);
	string EmployeeName;
	int hours;
	float wage;
	float basepay;
	int overtime_hours;
	float overtime_pay;
	float overtime_extra;
	float iTotal_salaries;
	float iIndividualSalary;
	int iTotal_hours;
	int iTotal_OvertimeHours;
};
int main()
{
	cout << "Welcome to the Employee Pay Center\n\n";
	/*
	Use this section to define your objects.  You will have one object per employee.  You have only three employees.
	The format is your class name and your object name.
	*/
	EmployeeClass employee1;
	EmployeeClass employee2;
	EmployeeClass employee3;
	/*
	Here you will prompt for the first employee’s information.
	Prompt the employee name, hours worked, and the hourly wage.  For each piece of information, you will update the appropriate class member defined above.
	Example of Prompts
	Enter the employee name      =
	Enter the hours worked       =
	Enter his or her hourly wage =
	*/
	cout << "Enter the employee name      =";
	cin >> employee1.EmployeeName;
	cout << "Enter the hours worked       =";
	cin >> employee1.hours;
	cout << "Enter his or her hourly wage =";
	cin >> employee1.wage;
	/*
	Here you will prompt for the second employee’s information.
	Prompt the employee name, hours worked, and the hourly wage.  For each piece of information, you will update the appropriate class member defined above.
	Enter the employee name      =
	Enter the hours worked       =
	Enter his or her hourly wage =
	*/
	cout << "\n\nEnter the employee name      =";
	cin >> employee2.EmployeeName;
	cout << "Enter the hours worked       =";
	cin >> employee2.hours;
	cout << "Enter his or her hourly wage =";
	cin >> employee2.wage;
	/*
	Here you will prompt for the third employee’s information.
	Prompt the employee name, hours worked, and the hourly wage.  For each piece of information, you will update the appropriate class member defined above.
	Enter the employee name      =
	Enter the hours worked       =
	Enter his or her hourly wage =
	*/
	cout << "\n\nEnter the employee name      =";
	cin >> employee3.EmployeeName;
	cout << "Enter the hours worked       =";
	cin >> employee3.hours;
	cout << "Enter his or her hourly wage =";
	cin >> employee3.wage;
	cout << "\n\n";
	/*
	Here you will implement a function call to implement the employ calcuations for each object defined above.  You will do this for each of the three employees or objects.
	The format for this step is the following:
	[(object name.function name(objectname.name, objectname.hours, objectname.wage)] ;
	*/
	employee1.ImplementCalculations(employee1.EmployeeName, employee1.hours, employee1.wage);
	employee2.ImplementCalculations(employee2.EmployeeName, employee2.hours, employee2.wage);
	employee3.ImplementCalculations(employee3.EmployeeName, employee3.hours, employee3.wage);
	/*
	This section you will send all three objects to a function that will add up the the following information:
	- Total Employee Salaries
	- Total Employee Hours
	- Total Overtime Hours
	The format for this function is the following:
	-   Define a new object.
	-   Implement function call [objectname.functionname(object name 1, object name 2, object name 3)]
	*/
	EmployeeClass employeeTotal;
	employeeTotal.Addsomethingup(employee1, employee2, employee3);
	cin >> employee1.wage;
	return 0;
} //End of Main Function
void EmployeeClass::ImplementCalculations(string EmployeeName, double hours, double wage) {
	//Initialize overtime variables
	overtime_hours = 0;
	overtime_pay = 0;
	overtime_extra = 0;
	if (hours > 40)
	{
		/*
		This section is for the basic calculations for calculating overtime pay.
		-   base pay = 40 hours times the hourly wage
		-   overtime hours = hours worked – 40
		-   overtime extra pay over 40 = overtime hours * overtime pay
		-   salary = overtime money over 40 hours + your base pay
		*/
		basepay = 40 * wage;
		overtime_hours = hours - 40;
		overtime_pay = wage * 1.5;
		overtime_extra = overtime_hours * overtime_pay;
		iIndividualSalary = overtime_extra + basepay;
		/*
		Implement function call to output the employee information.  Function is defined below.
		*/
		DisplayEmployInformation();
	}   // if (hours > 40)
	else
	{

		/* Here you are going to calculate the hours less than 40 hours.
		-   Your base pay is = your hours worked times your wage
		-   Salary = your base pay
		*/
		basepay = hours * wage;
		iIndividualSalary = basepay;
		/*
		Implement function call to output the employee information.  Function is defined below.
		*/
		DisplayEmployInformation();
	} // End of the else
} //End of Primary Function
void EmployeeClass::DisplayEmployInformation() {
	// This function displays all the employee output information.
	/*
	This is your cout statements to display the employee information:
	Employee Name ............. =
	Base Pay .................. =
	Hours in Overtime ......... =
	Overtime Pay Amount........ =
	Total Pay ................. =
	*/
	cout << "Employee Name ............. =" << setw(15) << EmployeeName << endl;
	cout << "Base Pay .................. =" << setw(15) << basepay << endl;
	cout << "Hours in Overtime ......... =" << setw(15) << overtime_hours << endl;
	cout << "Overtime Pay Amount........ =" << setw(15) << overtime_extra << endl;
	cout << "Total Pay ................. =" << setw(15) << iIndividualSalary << endl;
	cout << endl;

} // END OF Display Employee Information

void EmployeeClass::Addsomethingup(EmployeeClass employee1, EmployeeClass  employee2, EmployeeClass employee3) {
	// Adds two objects of class Employee passed as
	// function arguments and saves them as the calling object's data member values.


	/*
	Add the total hours for objects 1, 2, and 3.
	Add the salaries for each object.
	Add the total overtime hours.
	*/
	iTotal_hours = 0;
	iTotal_salaries = 0;
	iTotal_OvertimeHours = 0;
	iTotal_hours = employee1.hours + employee2.hours + employee3.hours;
	iTotal_salaries = employee1.iIndividualSalary + employee2.iIndividualSalary + employee3.iIndividualSalary;
	iTotal_OvertimeHours = employee1.overtime_hours + employee2.overtime_hours + employee3.overtime_hours;

	/*
	Then display the information below.
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	%%%% EMPLOYEE SUMMARY DATA%%%%%%%%%%%%%%%%%%%%%%%
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	%%%% Total Employee Salaries ..... = 576.43
	%%%% Total Employee Hours ........ = 108
	%%%% Total Overtime Hours......... = 5
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	*/
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
	cout << "%%%% EMPLOYEE SUMMARY DATA %%%%%%%%%%%%%%%%%%%%%%" << endl;
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
	cout << "%%%% Total Employee Salaries ..... = " << iTotal_salaries << endl;
	cout << "%%%% Total Employee Hours ........ = " << iTotal_hours << endl;
	cout << "%%%% Total Overtime Hours......... = " << iTotal_OvertimeHours << endl;
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << "" << endl;
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << "" << endl;
	exit(0);
}// End of function