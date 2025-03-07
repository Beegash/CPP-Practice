#include "Form.hpp"

Form::Form(const std::string &name, int gradeSign, int gradeExec)
	: name(name), isSigned(false), gradeRequiredToSign(gradeSign), gradeRequiredToExecute(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
	: name(other.name), isSigned(other.isSigned), gradeRequiredToSign(other.gradeRequiredToSign),
	  gradeRequiredToExecute(other.gradeRequiredToExecute) {}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	return *this;
}

Form::~Form() {}

const std::string &Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

int Form::getGradeRequiredToSign() const
{
	return gradeRequiredToSign;
}

int Form::getGradeRequiredToExecute() const
{
	return gradeRequiredToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeRequiredToSign)
		throw GradeTooLowException();
	isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Form grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form " << form.getName() << " (Required sign grade: " << form.getGradeRequiredToSign()
	   << ", Required exec grade: " << form.getGradeRequiredToExecute()
	   << ") is " << (form.getIsSigned() ? "signed" : "not signed") << ".";
	return os;
}
