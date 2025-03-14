#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string name;
	bool isSigned;
	const int gradeRequiredToSign;
	const int gradeRequiredToExecute;

public:
	class GradeTooHighException : public std::exception
	{
	public:
		virtual ~GradeTooHighException() throw() {}
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual ~GradeTooLowException() throw() {}
		virtual const char *what() const throw();
	};

	Form(const std::string &name, int gradeSign, int gradeExec);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	const std::string &getName() const;
	bool getIsSigned() const;
	int getGradeRequiredToSign() const;
	int getGradeRequiredToExecute() const;

	void beSigned(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
