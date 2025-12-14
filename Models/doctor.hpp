#ifndef DOCTOR_HPP
#define DOCTOR_HPP

#include <string>
#include "user.hpp"

// builder design pattern
struct Doctor : public User
{
	std::string name;
	std::string specialization;
	std::string hospital;
};

class IDoctorBuilder
{
public:
	virtual IDoctorBuilder& setId(size_t id) = 0;
	virtual IDoctorBuilder& setEmail(const std::string& email) = 0;
	virtual IDoctorBuilder& setPassword(const std::string& password) = 0;
	virtual IDoctorBuilder& setName(const std::string& name) = 0;
	virtual IDoctorBuilder& setSpecialization(const std::string& specialization) = 0;
	virtual IDoctorBuilder& setHospital(const std::string& hospital) = 0;
	virtual Doctor build() const = 0;

	virtual ~IDoctorBuilder() = default;
};

class DoctorBuilder : public IDoctorBuilder
{
public:
	virtual IDoctorBuilder& setId(size_t id) override
	{
		m_doctor.id = id;
		return *this;
	}

	virtual IDoctorBuilder& setEmail(const std::string& email) override
	{
		m_doctor.email = email;
		return *this;
	}

	virtual IDoctorBuilder& setPassword(const std::string& password) override
	{
		m_doctor.password = password;
		return *this;
	}

	virtual IDoctorBuilder& setName(const std::string& name) override
	{
		m_doctor.name = name;
		return *this;
	}

	virtual IDoctorBuilder& setSpecialization(const std::string& specialization) override
	{
		m_doctor.specialization = specialization;
		return *this;
	}

	virtual IDoctorBuilder& setHospital(const std::string& hospital) override
	{
		m_doctor.hospital = hospital;
		return *this;
	}

	virtual Doctor build() const override
	{
		return m_doctor;
	}

private:
	Doctor m_doctor;
};

#endif // DOCTOR_HPP