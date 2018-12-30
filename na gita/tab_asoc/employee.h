#include <cstdlib>
#include <cstring>
// #AF
using namespace std;

    class Employee
    {
    public:
	string Name_of_author;
	string Position;
	unsigned int Age;
    
    Employee(string Name_of_author, string Position, unsigned int Age)
    {
	this->Name_of_author = Name_of_author ;
	this->Position = Position ;
	this->Age = Age ;
    }
    
    Employee()
    {
    	Name_of_author="";
    	Position = "";
    	Age = 0 ;
    }

    friend ostream& operator<< (ostream &out, const Employee &toWrite);
    };


    ostream& operator<< (ostream &out, const Employee &toWrite)
    {
	out << "\nName: " << toWrite.Name_of_author<< "\nPosition: " << toWrite.Position << "\nAge: " << toWrite.Age<<endl;
	return out;
    }
