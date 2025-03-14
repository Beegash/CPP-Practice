#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Form;

class Bureaucrat
{
private:
    const std::string name;
    int grade;

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

    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();

    const std::string &getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();

    void signForm(Form &form) const;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif
