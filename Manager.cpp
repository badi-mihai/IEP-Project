#include <iostream>
#include <string>
#include <vector>

class Manager
{
	private:

	int age;
    std::string first_name;
    std::string last_name;

	public:
	
	Manager(int age, const std::string &first_name, const std::string &last_name)
	: age(age),
      first_name(first_name),
      last_name(last_name)
	{}

    void swap(Manager &&obj) {
		std::swap(age, obj.age);
		std::swap(first_name, obj.first_name);
		std::swap(last_name, obj.last_name);
	}

    Manager& operator = (const Manager &obj)
    {
        Manager copy(obj);
		swap(std::move(copy));

        return *this;
    } 

    void shoutToWorker()
    {
        std::cout << "Manager " << this->getFirstName() << " " << this->getLastName() << ": GO TO WORK!" << std::endl;
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