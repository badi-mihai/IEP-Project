#include <iostream>
#include <string>
#include <vector>
#include "Manager.cpp"
#include "Worker.cpp"

int main(int argc, char** argv){

	Worker *worker1 = new Worker(24, "Vasile", "Apietroaiei", 3000);
	Worker *worker2 = new Worker(32, "Mircea", "Lucescu", 2000);
	Worker *worker3 = new Worker(40, "Gigel", "Frone", 1800);


	Manager *manager1 = new Manager(29, "Maria", "Popescu");
	Manager *manager2 = new Manager(53, "Ion", "Popescu");
	Manager *manager3 = new Manager(22, "Mihai", "Badi");

	
	/* Managers */

	std::cout << "Manager 1: " << manager1->getFirstName() << " " << manager1->getLastName() << std::endl;
	std::cout << "Age: " << manager1->getAge() << std::endl << std::endl;

	std::cout << "Manager 2: " << manager2->getFirstName() << " " << manager2->getLastName() << std::endl;
	std::cout << "Age: " << manager2->getAge() << std::endl << std::endl;

	std::cout << "Manager 3: " << manager3->getFirstName() << " " << manager3->getLastName() << std::endl;
	std::cout << "Age: " << manager3->getAge() << std::endl << std::endl;

	manager1 = manager2 = manager3;

	std::cout << "After chaining assignments:" << std::endl << std::endl;

	std::cout << "Manager 1: " << manager1->getFirstName() << " " << manager1->getLastName() << std::endl;
	std::cout << "Age: " << manager1->getAge() << std::endl << std::endl;

	std::cout << "Manager 2: " << manager2->getFirstName() << " " << manager2->getLastName() << std::endl;
	std::cout << "Age: " << manager2->getAge() << std::endl << std::endl;

	std::cout << "Manager 3: " << manager3->getFirstName() << " " << manager3->getLastName() << std::endl;
	std::cout << "Age: " << manager3->getAge() << std::endl << std::endl;



	/* Workers */

	std::cout << std::endl << "------------------------------------" << std::endl << "Workers" << std::endl << std::endl;

	std::cout << "Worker 1: " << worker1->getFirstName() << " " << worker1->getLastName() << std::endl;
	std::cout << "Age: " << worker1->getAge() << std::endl;
	std::cout << "Salary: " << worker1->getSalary() << std::endl << std::endl;

	std::cout << "Worker 2: " << worker2->getFirstName() << " " << worker2->getLastName() << std::endl;
	std::cout << "Age: " << worker2->getAge() << std::endl;
	std::cout << "Salary: " << worker2->getSalary() << std::endl << std::endl;

	std::cout << "Worker 3: " << worker3->getFirstName() << " " << worker3->getLastName() << std::endl;
	std::cout << "Age: " << worker3->getAge() << std::endl;
	std::cout << "Salary: " << worker3->getSalary() << std::endl << std::endl;

	worker2 = worker3 = worker3;

	std::cout << "After assignment:" << std::endl << std::endl;

	std::cout << "Worker 2: " << worker2->getFirstName() << " " << worker2->getLastName() << std::endl;
	std::cout << "Age: " << worker2->getAge() << std::endl;
	std::cout << "Salary: " << worker2->getSalary() << std::endl << std::endl;

	std::cout << "Worker 3: " << worker3->getFirstName() << " " << worker3->getLastName() << std::endl;
	std::cout << "Age: " << worker3->getAge() << std::endl;
	std::cout << "Salary: " << worker3->getSalary() << std::endl << std::endl;

	// worker2 = worker2;

	// std::cout << "Worker 2: " << worker2->getFirstName() << " " << worker2->getLastName() << std::endl;
	// std::cout << "Age: " << worker2->getAge() << std::endl;
	// std::cout << "Salary: " << worker2->getSalary() << std::endl << std::endl;

	return 0;
}