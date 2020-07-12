#include "HandleDates.h"
#include <iostream>
#include <sstream>

std::vector<int> HandleDates::Split(const std::string& s, char delim) // works good
{
	std::vector<int> result;
	std::stringstream ss(s);
	std::string item;

	while (getline(ss, item, delim))
	{
		result.push_back(std::stoi(item));
	}

	return result;
}

void HandleDates::DataSplit(const std::string& begin, const std::string& end) // works good
{
	std::vector<int> beginVector = Split(begin, '.');
	std::vector<int> endVector = Split(end, '.');

	bDays = beginVector[0];
	bMonths = beginVector[1];
	bYears = beginVector[2];

	eDays = endVector[0];
	eMonths = endVector[1];
	eYears = endVector[2];
}

HandleDates::HandleDates(const std::string& begin, const std::string& end) // works good
{
	DataSplit(begin, end);
}


int HandleDates::CalculateYears() // NOT works
{
	int difY = eYears - bYears;
	return difY;
}

int HandleDates::CalculateMonths() // NOT works
{
	int difM = eMonths - bMonths;

	if (difM < 0)
	{
		--difYears;
		difM = 12 + difM;
	}

	return difM;
}

int HandleDates::CalcultaeDays() // NOT works
{
	int difD = eDays - bDays;

	if (difD < 0)
	{
		if (difMonths > 0)
		{
			--difMonths;
			difD += getCoef();
		}
		else
		{
			--difYears;
			difMonths += 11;
			difD += getCoef();
		}
	}

	return difD;
}

void HandleDates::calcDates() // NOT works
{
	difYears = CalculateYears();
	difMonths = CalculateMonths();
	difDays = CalcultaeDays();
}

int HandleDates::getDifDays() const // NOT works
{
	return difDays;
}

int HandleDates::getDifMonths() const // NOT works
{
	return difMonths;
}

int HandleDates::getDifYears() const // NOT works
{
	return difYears;
}

int HandleDates::getCoef() // NOT works
{
	int k;

	int previosMonth = eMonths - 1;
	if (previosMonth == 0)
	{
		previosMonth = 12;
	}

	switch (previosMonth)
	{
	case 2:
		k = isLoopYear(eYears) ? 29 : 28;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		k = 31;
		break;
	default:
		k = 31;
	}
	return k;
}

int HandleDates::calcDays() // NOT works
{
	int answer;
	answer = yearsFunc() + monthFunc() + difDays;
	return answer;
}

int HandleDates::yearsFunc()
{
	int year = (bMonths > 2) ? bYears + 1 : bYears;
	int days = difYears * 365;

	for (int i = 0; i < difYears; ++i)
	{
		year += i;
		if (isLoopYear(year))
		{
			++days;
		}
	}
	return days;
}
bool HandleDates::devidesTo4(int year)
{
	return !static_cast<bool>(year % 4);
}
bool HandleDates::devidesTo100(int year)
{
	return !static_cast<bool>(year % 100);
}
bool HandleDates::devidesTo400(int year)
{
	return !static_cast<bool>(year % 400);
}

int HandleDates::monthFunc() // NOT works
{
	int days = 0;
	int currYear = bYears + difYears;
	bool nextYear =  false;

	for (int i = 0; i < difMonths; i++)
	{
		int month = bMonths + i;
		if (month > 12)
		{
			month -= 12;
			nextYear = true;
		}

		switch (month)
		{
		case 2: // February
			currYear += nextYear ? 1 : 0;
			days += isLoopYear(currYear) ? 29 : 28;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			days += 30;
			break;
		default:
			days += 31;
		}
	}

	return days;
}

bool HandleDates::isLoopYear(int year)
{
	if (devidesTo4(year))
	{
		if (devidesTo100(year))
		{
			if (devidesTo400(year))
			{
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}
