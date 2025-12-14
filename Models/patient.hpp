#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <string>
#include <chrono>

#include "user.hpp"

struct Patient : public User
{	
	FullName fullName;
	BirthDate birthDate;
	Gender gender;
	std::string address;
};

class IPatientBuilder
{
public:
	virtual IPatientBuilder& setId(size_t id) = 0;
	virtual IPatientBuilder& setEmail(const std::string& email) = 0;
	virtual IPatientBuilder& setPassword(const std::string& password) = 0;
	virtual IPatientBuilder& setName(const std::string& name) = 0;
	virtual IPatientBuilder& setBirthDate(const BirthDate& birthDate) = 0;
	virtual IPatientBuilder& setGender(Gender gender) = 0;
	virtual IPatientBuilder& setAddress(const std::string& address) = 0;
};

class DoctorBuilder : public IPatientBuilder
{
public:
	virtual IPatientBuilder& setId(size_t id)
	{
		m_patient.id = id;
		return *this;
	}

	virtual IPatientBuilder& setEmail(const std::string& email)
	{
		m_patient.email = email;
		return *this;
	}

	virtual IPatientBuilder& setPassword(const std::string& password)
	{
		m_patient.password = password;
		return *this;
	}

	virtual IPatientBuilder& setName(const FullName& name)
	{
		m_patient.fullName = name;
		return *this;
	}

	virtual IPatientBuilder& setBirthDate(const BirthDate& birthDate)
	{
		m_patient.birthDate = birthDate;
		return *this;
	}

	virtual IPatientBuilder& setGender(Gender gender)
	{
		m_patient.gender = gender;
		return *this;
	}

	virtual IPatientBuilder& setAddress(const std::string& address)
	{
		m_patient.address = address;
		return *this;
	}

private:
	Patient m_patient;
};

#endif // PATIENT_HPP