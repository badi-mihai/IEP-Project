#include <iostream>
#include <string>
#include <vector>

class Employee
{
	private:

	int age;
	std::string first_name;
	std::string last_name;

	public:
	
	Employee(int age, const std::string &first_name, const std::string &last_name)
	:age(age),
	 first_name(first_name),
	 last_name(last_name)
	{}

	Employee ( const Employee& rhs ) 
	:age ( rhs.age ),
	 first_name( rhs.first_name ),
	 last_name( rhs.last_name ) 
	 {};
	
	Employee& operator = ( const Employee& rhs )
    {
    	age = rhs.age;
		first_name = rhs.first_name;
		last_name = rhs.last_name;

    	return *this;
    }

	int getAge()
	{
		return this->age;
	}
	
	std::string getFirstName()
	{
		return this->first_name;
	}
	
	std::string getLastName()
	{
		return this->last_name;
	}
};