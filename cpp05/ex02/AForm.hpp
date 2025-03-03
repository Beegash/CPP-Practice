#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	AForm(const std::string &name, int gradeSign, int gradeExec);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();

	const std::string &getName() const;
	bool getIsSigned() const;
	int getGradeRequiredToSign() const;
	int getGradeRequiredToExecute() const;

	void beSigned(const Bureaucrat &bureaucrat);
	virtual void execute(const Bureaucrat &executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
