#include "AForm.hpp"

AForm::AForm(const std::string &name, int gradeSign, int gradeExec)
	: name(name), isSigned(false), gradeRequiredToSign(gradeSign), gradeRequiredToExecute(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
	: name(other.name), isSigned(other.isSigned), gradeRequiredToSign(other.gradeRequiredToSign),
	  gradeRequiredToExecute(other.gradeRequiredToExecute) {}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const
{
	return name;
}

bool AForm::getIsSigned() const
{
	return isSigned;
}

int AForm::getGradeRequiredToSign() const
{
	return gradeRequiredToSign;
}

int AForm::getGradeRequiredToExecute() const
{
	return gradeRequiredToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeRequiredToSign)
		throw GradeTooLowException();
	isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "Form " << form.name << " (Sign Grade: " << form.gradeRequiredToSign
	   << ", Exec Grade: " << form.gradeRequiredToExecute
	   << ") is " << (form.isSigned ? "signed" : "not signed") << ".";
	return os;
}
