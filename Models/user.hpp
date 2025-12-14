#ifndef USER_HPP
#define USER_HPP

#include <string>

struct User
{
	size_t id;
	std::string email;
	std::string password;
};

enum class Gender { Male, Female };

struct FullName
{
	std::string firstName;
	std::string middleName;
	std::string lastName;
};

using BirthDate = std::chrono::year_month_day;

#endif // USER_HPP