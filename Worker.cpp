#include <iostream>
#include <string>
#include <vector>
#include "Employee.cpp"

class Worker : public Employee
{
	private:

	int salary;

	public:
	
	Worker(int age, const std::string &first_name, const std::string &last_name, int salary)
	: Employee(age, first_name, last_name),
      salary(salary)
	{}

    Worker ( const Worker& rhs ):
	    Employee ( rhs ),
		salary( rhs.salary )
	{}

    Worker& operator= ( const Worker& rhs )
	{
        if(this == &rhs) return *this;

		Employee::operator=(rhs);
		salary = rhs.salary;

		return *this;
	}

    void serveManager()
    {
        std::cout << "Worker " << this->getFirstName() << " " << this->getLastName() << ": At your disposal, sir!" << std::endl;
    }

    int getSalary()
    {
        return this->salary;
    }
};