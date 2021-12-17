#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>
#include "TownHall.cpp"

std::mutex counter_mutex;

void adauga_fonduri(TownHall *town_hall, Mayor *mayor)
{
	for(int i = 0; i<3; i++){
		counter_mutex.lock();
		town_hall->fonduri++;

		std::cout << "Updated from " << mayor->getFirstName() << " " << mayor->getLastName() << " thread" << std::endl;
		std::cout << "Fonduri: " << town_hall->fonduri << std::endl;
		
		std::this_thread::sleep_for(std::chrono::seconds(1));
		counter_mutex.unlock();
	}
}

int main(int argc, char** argv){

	ConferenceRoom *c1 = new ConferenceRoom("Sala 1", 3);
	ConferenceRoom *c2 = new ConferenceRoom("Sala 2", 5);
	ConferenceRoom *c3 = new ConferenceRoom("Sala 3", 1);

	Mayor *m1 = new Mayor(35, "First", "Mayor", c1);
	Mayor *m2 = new Mayor(35, "Second", "Mayor", c2);
	Mayor *m3 = new Mayor(35, "Third", "Mayor", c3);

	TownHall *p1 = new TownHall("Timisoara", "ceva adresa", *m1);
	TownHall *p2 = new TownHall("Bucuresti", "Strada Maritirlor", *m2);

	std::cout << "Mayor: " << m1->getFirstName() << " " << m1->getLastName() << std::endl;
	std::cout << "Age: " << m1->getAge() << std::endl;

	std::cout << std::endl;
	std::cout<< "Primaria din orasul " << p1->getCity() << " cu adresa " << p1->getAddress() << std::endl;

	std::cout << "Primarul  " << p1->mayor->getFirstName() << " " << p1->mayor->getLastName() << std::endl;
	std::cout << "Age: " << p1->mayor->getAge() << std::endl;

	std::cout << "Camera de conferinte:  " << p1->mayor->conference_room->getRoomName() << " este la etajul: " << p1->mayor->conference_room->getFloor() << std::endl;


	std::cout << std::endl; 
	std::cout << "---------------------------------------------------" << std::endl;


	std::cout << "Mayor: " << m1->getFirstName() << " " << m1->getLastName() << std::endl;
	std::cout << "Age: " << m1->getAge() << std::endl;

	std::cout << std::endl;
	std::cout<< "Primaria din orasul " << p2->getCity() << " cu adresa " << p2->getAddress() << std::endl;

	std::cout << "Primarul  " << p2->mayor->getFirstName() << " " << p2->mayor->getLastName() << std::endl;
	std::cout << "Age: " << p2->mayor->getAge() << std::endl;

	std::cout << "Camera de conferinte:  " << p2->mayor->conference_room->getRoomName() << " este la etajul: " << p2->mayor->conference_room->getFloor() << std::endl;

	// p1->mayor = p2->mayor;


	std::cout << "Mayor " << m1->getFirstName() << " " << m1->getLastName() << "----> Conference Room: " << m1->conference_room->getRoomName() << std::endl;
	std::cout << "Mayor " << m2->getFirstName() << " " << m2->getLastName() << "----> Conference Room: " << m2->conference_room->getRoomName() << std::endl;
	std::cout << "Mayor " << m3->getFirstName() << " " << m3->getLastName() << "----> Conference Room: " << m3->conference_room->getRoomName() << std::endl;

	m2->conference_room = m1->conference_room;
	m3->conference_room = m1->conference_room;

	std::cout << std::endl;
	std::cout << "Mayor " << m1->getFirstName() << " " << m1->getLastName() << "----> Conference Room: " << m1->conference_room->getRoomName() << std::endl;
	std::cout << "Mayor " << m2->getFirstName() << " " << m2->getLastName() << "----> Conference Room: " << m2->conference_room->getRoomName() << std::endl;
	std::cout << "Mayor " << m3->getFirstName() << " " << m3->getLastName() << "----> Conference Room: " << m3->conference_room->getRoomName() << std::endl;


	std::cout << "Starting firs thread" << std::endl;
    std::thread first_thread(adauga_fonduri, p1, m1);

    std::cout << "Starting second thread" << std::endl;
    std::thread second_thread(adauga_fonduri, p1, m2);

	std::cout << "Starting third thread" << std::endl;
    std::thread third_thread(adauga_fonduri, p1, m3);


    first_thread.join();
    std::cout << "First Thread is done." << std::endl;
    second_thread.join();
    std::cout << "Second Thread is done." << std::endl;
	third_thread.join();
    std::cout << "Third Thread is done." << std::endl;

	return 0;
}