#include <iostream>
#include <string>
#include <vector>
#include "Mayor.cpp"
#include <memory>

class TownHall
{
	private:

    std::string city;
    std::string address;

	public:
    std::unique_ptr<Mayor> mayor;
    int fonduri = 0;
	
	TownHall(const std::string &city, const std::string &address, Mayor &mayor)
	: city(city),
      address(address)
	{
        this->mayor = std::make_unique<Mayor>(mayor);
    }

    // void swap(TownHall &&obj) {
	// 	std::swap(age, obj.age);
	// 	std::swap(city, obj.city);
	// 	std::swap(address, obj.address);
	// }

    // TownHall& operator = (const TownHall &obj)
    // {
    //     TownHall copy(obj);
	// 	swap(std::move(copy));

    //     return *this;
    // } 

    // void shoutToWorker()
    // {
    //     std::cout << "Manager " << this->getFirstName() << " " << this->getLastName() << ": GO TO WORK!" << std::endl;
    // }

    // std::unique_ptr<Mayor> getMayor()
    // {
    //     return this->mayor;
    // }

    std::string getCity()
    {
        return this->city;
    }

    std::string getAddress()
    {
        return this->address;
    }
};