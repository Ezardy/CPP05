#include <iostream>

#include "Bureaucrat.hpp"

const char	*Bureaucrat::GradeTooHighException::what(void) const throw() {
	return "The grade is too high";
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw() {
	return "The grade is too low";
}

Bureaucrat::Bureaucrat(void) throw() : _name("Unnamed"), _grade(_minGrade) {

}

Bureaucrat::Bureaucrat(const std::string &name, unsigned short grade) throw(GradeTooHighException, GradeTooLowException) : _name(name) {
	if (grade > _minGrade)
		throw GradeTooLowException();
	else if (grade < _maxGrade)
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
	if (_grade - 1 < _maxGrade)
		throw GradeTooHighException();
	else
		_grade -= 1;
}

void	Bureaucrat::dec(void) throw(GradeTooLowException) {
	if (_grade + 1 > _minGrade)
		throw GradeTooLowException();
	else
		_grade += 1;
}

const unsigned short	Bureaucrat::_minGrade = 150;
const unsigned short	Bureaucrat::_maxGrade = 1;

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}
