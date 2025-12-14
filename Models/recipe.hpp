#ifndef RECIPE_HPP
#define RECIPE_HPP

#include <chrono>

#include "patient.hpp"
#include "doctor.hpp"

struct Drug
{
	std::string name;
	enum class ReleaseForm { Capsule, Tablet };
};

using DateOfIssue = std::chrono::year_month_day;

struct Recipe
{
	size_t id;
	size_t doctorId;
	size_t patientId;
	DateOfIssue dataOfIssue;
	Drug drug;
	std::string dosage;
	std::string admissionProcedure;
	int courseDuration;
};

class IRecipeBuilder
{
	virtual IRecipeBuilder& setId(size_t id) = 0;
	virtual IRecipeBuilder& setDoctorId(size_t doctorId) = 0;
	virtual IRecipeBuilder& setDateOfIssue(DateOfIssue dateOfIssue) = 0;
	virtual IRecipeBuilder& setDrug(Drug drug) = 0;
	virtual IRecipeBuilder& setDosage(const std::string& dosage) = 0;
	virtual IRecipeBuilder& setAddmissionProcedure(const std::string& admissionProcedure) = 0;
	virtual IRecipeBuilder& setCourseDuration(int courseDuration) = 0;

	virtual Recipe build() const;

	virtual ~IRecipeBuilder() = default;
};

class RecipeBuilder : public IRecipeBuilder
{
public:
	IRecipeBuilder& setId(size_t id) override
	{
		m_recipe.id = id;
		return *this;
	}

	IRecipeBuilder& setDoctorId(size_t doctorId) override
	{
		m_recipe.doctorId = doctorId;
		return *this;
	}

	IRecipeBuilder& setDoctorId(size_t patientId) override
	{
		m_recipe.patientId = patientId;
		return *this;
	}

	IRecipeBuilder& setDateOfIssue(DateOfIssue dateOfIssue) override
	{
		m_recipe.dataOfIssue = dateOfIssue;
		return *this;
	}

	IRecipeBuilder& setDrug(Drug drug) override
	{
		m_recipe.drug = drug;
		return *this;
	}

	IRecipeBuilder& setDosage(const std::string& dosage) override
	{
		m_recipe.dosage = dosage;
		return *this;
	}

	IRecipeBuilder& setAddmissionProcedure(const std::string& admissionProcedure) override
	{
		m_recipe.admissionProcedure = admissionProcedure;
		return *this;
	}

	IRecipeBuilder& setCourseDuration(int courseDuration) override
	{
		m_recipe.courseDuration = courseDuration;
		return *this;
	}

	virtual Recipe build() const
	{
		return m_recipe;
	}

private:
	Recipe m_recipe;
};

#endif // RECIPE_HPP 