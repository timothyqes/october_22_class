//This program prompts the user for their birthdate in month/day/year format, and prints their age.
#include <iostream>
#include <map> //Creates a data structure

//The line below is a user-defined function. A function takes an input and makes an output.
//First approximation. Does not account for months with different maximum days.
bool dateValidation(int day, int month, int year)
{
	if (month < 1 || month > 12)
	{
		std::cout << "The month " << month << "is not a valid entry (i.e., not between 1 and 12 " <<
			std::endl;
		return false;
	}

	int minimumPossibleDay = 1;
	int maximumPossibleDay = 31;

	if (day < 1 || day > 31)
	{
		std::cout << "The day " << day << " is not valid (i.e., not between 1 and 31) " <<
			minimumPossibleDay << " and " << maximumPossibleDay << std::endl;
		return false;
	}

	if ((year < 1909) || (year > 2026))
	{
		std::cout << "Year " << year << " is invalid (i.e., not between 1909 and 2026) " << std::endl;
		return false;
	}

	return true;

	//std::map<std::string, int> monthsToDays =
	//{
	//	{"January", 31 },
	//	{"February", 28},
	//	{"March", 31},
	//	{""}
	//};
}

int calculateAge(int birthDay, int birthMonth, int birthYear, int currentDay, int currentMonth, int currentYear)
{
	int age = 0;

	/*The first two if statements make sure that the months and days do not overlap and print an 
	incorrect age. */
	if (currentMonth > birthMonth && currentDay > birthDay) /*I.e., the birth month and birth day
		has come and went, and therefore the age has to be subtracted by one (1) to keep it current.*/
	{
		age = currentYear - birthYear -1;
	}
	else
	{
		age = currentYear - birthYear;
	}
	return age;
}

int main()
{
	//std::string birthdate = "January 2, 1999";
	int birthDay = 0;
	int birthMonth = 0;
	int birthYear = 0;
	while (dateValidation(birthDay, birthMonth, birthYear) == false)
	{
		std::cout << "Enter your birth day (e.g., if it is January 2, enter '2'): " << std::endl;
		std::cin >> birthDay;

		std::cout << "Enter your birth month (e.g., if it is January 2, enter '1'): " << std::endl;
		std::cin >> birthMonth;

		std::cout << "Enter your birth year (e.g., 1999): " << std::endl;
		std::cin >> birthYear;
	}
	//prompt the user to enter their birthdate until a valid date is entered.
	int currentDay = 22;
	int currentMonth = 10;
	int currentYear = 2026;

	//suppose someone was born on x/y/z/, then they should be 21
	//suppose someone was born on x2/y2/z2/, then they should be 22

	int age = calculateAge(birthDay, birthMonth, birthYear, currentDay, currentMonth, currentYear);
	std::cout << "Your age is " << age << std::endl;
	//Valid date has been obtained.
}