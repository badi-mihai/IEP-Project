#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "ConferenceRoom.cpp"

class Mayor
{
	private:

	int age;
	std::string first_name;
	std::string last_name;

	public:
	std::shared_ptr<ConferenceRoom> conference_room;
	
	Mayor(int age, const std::string &first_name, const std::string &last_name, ConferenceRoom *conf)
	:age(age),
	 first_name(first_name),
	 last_name(last_name),
     conference_room(conf)
	{}

	// Mayor ( const Mayor& rhs ) 
	// :age ( rhs.age ),
	//  first_name( rhs.first_name ),
	//  last_name( rhs.last_name ) 
	//  {};
	
	// Mayor& operator = ( const Mayor& rhs )
    // {
    // 	age = rhs.age;
	// 	first_name = rhs.first_name;
	// 	last_name = rhs.last_name;

    // 	return *this;
    // }

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