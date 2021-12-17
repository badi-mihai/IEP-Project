#include <iostream>
#include <string>
#include <vector>

class ConferenceRoom
{
	private:

	std::string room_name;
    int floor;

	public:
	
	ConferenceRoom(const std::string &room_name, int floor)
	: room_name(room_name),
      floor(floor)
	{}

    // ConferenceRoom ( const ConferenceRoom& rhs ):
	//     Mayor ( rhs ),
	// 	salary( rhs.salary )
	// {}

    // ConferenceRoom& operator= ( const ConferenceRoom& rhs )
	// {
    //     if(this == &rhs) return *this;

	// 	Mayor::operator=(rhs);
	// 	salary = rhs.salary;

	// 	return *this;
	// }

    // void serveManager()
    // {
    //     std::cout << "Worker " << this->getFirstName() << " " << this->getLastName() << ": At your disposal, sir!" << std::endl;
    // }

    std::string getRoomName()
    {
        return this->room_name;
    }

	int getFloor()
    {
        return this->floor;
    }
};