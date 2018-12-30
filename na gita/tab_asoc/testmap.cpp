#include <iostream>
using namespace std;

#include "employee.h"			//defines class Employee
#include "map_template.h"		//defines template map_template<Key,Value>
#include "book.h"

void EmployeeTest()
{
	typedef unsigned int ID; 							//Identification number of Employee
	map_template<ID,Employee> Database;					//Database of employees

	Database.Add(761028073,Employee("Jan Kowalski","salesman",28)); 	//Add first employee: name: Jan Kowalski, position: salseman, age: 28,
	Database.Add(510212881,Employee("Adam Nowak","storekeeper",54)); 	//Add second employee: name: Adam Nowak, position: storekeeper, age: 54
	Database.Add(730505129,Employee("Anna Zaradna","secretary",32)); 	//Add third employee: name: Anna Zaradna, position: secretary, age: 32

	cout << Database << endl;							//Print databese

	map_template<ID,Employee> NewDatabase = Database;	//Make a copy of database
	
	Employee* pE;
	pE = NewDatabase.Find(510212881);					//Find employee using its ID
	if ( pE == NULL )
		cout<<"Tittle oesnt exist"<<endl;

	pE->Position = "salesman";							//Modify the position of employee
	pE = NewDatabase.Find(761028073);					//Find employee using its ID
	pE->Age = 29;										//Modify the age of employee

	Database = NewDatabase;								//Update original database
	
	cout << Database << endl;							//Print original databese

}

void BookTest()
{
	typedef string title;
	map_template<title, Book> Database;

	Database.Add("21 Lessons for the 21st Century",Book("Yuval Noah Harari", "21 Lessons for the 21st Century", "Philosophy", 456));
	Database.Add("American Pastoral", Book("Philip Roth", "American Pastoral", "Thriller", 608));
	Database.Add("Symfonia C++", Book("Paulo Orange", "Symfonia C++", "Science", 1530));
	Database.Add("50 twarzy Greya", Book("E. L. James", "50 twarzy Greya", "Romance", 1509));

	cout << Database << endl;

	map_template<title, Book> NewDatabase = Database;

	cout << "NewDatabase: vol.1 ##########################" << endl;
	cout << NewDatabase << endl;

	Book* pB;
	pB = NewDatabase.Find("Symfonia C++");
	cout << "############################ Find Symfonia" << endl;
	cout << *pB << endl;
	pB = NewDatabase.Find("50 twarzy Greya");
	(*NewDatabase.Find("21 Lessons for the 21st Century")).rent();

	//cout << "NewDatabase: vol.2 ########################## ( wypozyczenie 21 Lessosn )" << endl;
	//cout << NewDatabase << endl;
	
	cout << "############################ Find 50 twarzy" << endl;
	cout << *pB << endl;
}


int main(void)
{
	cout << "First ---- Employee test ####################################\n" << endl;
	EmployeeTest();

	cout << "Second ---- Book test ####################################\n" << endl;
	BookTest();
	return 0;
}
