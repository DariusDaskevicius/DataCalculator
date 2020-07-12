#include <iostream>
#include "HandleDates.h"

int main()
{
	std::string begin; 
	std::string end;

	std::cout << "Enter begin data: ";
	std::cin >> begin; std::cin.ignore();
	std::cout << "Begin data: " << begin << std::endl;

	std::cout << "Enter end data: ";
	std::cin >> end; std::cin.ignore();
	std::cout << "End data: " << end << std::endl;

	HandleDates dates(begin, end);

	dates.calcDates();

	std::cout << dates.getDifYears() << " years, " << dates.getDifMonths() << " months, " << dates.getDifDays() << " days." << std::endl;

	std::cout << "Days: " << dates.calcDays() << std::endl;

	return 0;
}