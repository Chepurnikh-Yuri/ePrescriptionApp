#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <string>
#include <chrono>

class User
{
public:
	User(size_t id, const std::string& password, const std::string& email) :
		m_id(id), m_email(email), m_password(password) {
	}

	// getters 
	size_t getId() const { return m_id; }
	std::string getMail() const { return m_email; }
	std::string getPassword() const { return m_password; }

private:
	size_t m_id;
	std::string m_email;
	std::string m_password;
};

class Patient : public User
{
public:
	using BirthDate = std::chrono::year_month_day;

	Patient(
		size_t id,
		const std::string& email,
		const std::string& password,
		const std::string& name,
		const BirthDate& birthDate
	) : User(id, email, password), m_name(name), m_birthDate(birthDate) 
	{

	} 

	std::string getName() const { return m_name; }
	BirthDate getBirthDate() const { return m_birthDate; }

private:
	std::string m_name;
	BirthDate m_birthDate;
};

#endif // PATIENT_HPP