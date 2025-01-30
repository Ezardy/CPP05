#include <iostream>

#include "Bureaucrat.hpp"

const char	*Bureaucrat::GradeTooHighException::what(void) const throw() {
	return "The grade is too high for a bureaucrat";
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw() {
	return "The grade is too low for a bureaucrat";
}

Bureaucrat::Bureaucrat(void) throw() : _name("Unnamed"), _grade(minGrade) {

}

Bureaucrat::Bureaucrat(const std::string &name, unsigned short grade) throw(GradeTooHighException, GradeTooLowException) : _name(name) {
	if (grade > minGrade)
		throw GradeTooLowException();
	else if (grade < maxGrade)
		throw GradeTooHighException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) throw() : _name(other._name), _grade(other._grade) {

}

Bureaucrat::~Bureaucrat(void) throw() {

}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other) throw() {
	if (this != &other)
		_grade = other._grade;
	return *this;
}

const std::string	&Bureaucrat::getName(void) const throw() {
	return _name;
}

unsigned short	Bureaucrat::getGrade(void) const throw() {
	return _grade;
}

void	Bureaucrat::inc(void) throw(GradeTooHighException) {
	if (_grade - 1 < maxGrade)
		throw GradeTooHighException();
	else
		_grade -= 1;
}

void	Bureaucrat::dec(void) throw(GradeTooLowException) {
	if (_grade + 1 > minGrade)
		throw GradeTooLowException();
	else
		_grade += 1;
}

void	Bureaucrat::signForm(Form &form) const throw() {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << '\n';
	} catch (const Form::GradeTooLowException &e) {
		std::cout << _name << " couldn't sign " << form.getName()
			<< " because '" << e.what() << "'\n";
	}
}

const unsigned short	Bureaucrat::minGrade = 150;
const unsigned short	Bureaucrat::maxGrade = 1;

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}
