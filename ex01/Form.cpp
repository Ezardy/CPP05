#include "Form.hpp"
#include "Bureaucrat.hpp"

const char	*Form::GradeTooHighException::what(void) const throw() {
	return "The grade is too high for a form";
}

const char	*Form::GradeTooLowException::what(void) const throw() {
	return "The grade is too low for a form";
}

Form::Form(void)
throw()
: _name("Unnamed"), _signed(false), _signGrade(Bureaucrat::minGrade),
	_executeGrade(Bureaucrat::minGrade) {

}

Form::Form(const std::string &name, unsigned short signGrade, unsigned short executeGrade)
throw(GradeTooHighException, GradeTooLowException)
: _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade) {
	if (signGrade > Bureaucrat::minGrade || executeGrade > Bureaucrat::minGrade)
		throw GradeTooLowException();
	else if (signGrade < Bureaucrat::maxGrade || executeGrade < Bureaucrat::maxGrade)
		throw GradeTooHighException();
}

Form::Form(const Form &form)
throw()
: _name(form._name), _signed(false), _signGrade(form._signGrade), _executeGrade(form._executeGrade) {

}

Form::~Form(void) throw() {

}

Form	&Form::operator=(const Form &other) throw() {
	if (this != &other)
		_signed = other._signed;
	return *this;
}

const std::string	&Form::getName(void) const throw() {
	return _name;
}

bool	Form::getSigned(void) const throw() {
	return _signed;
}

unsigned short	Form::getSignGrade(void) const throw() {
	return _signGrade;
}

unsigned short	Form::getExecuteGrade(void) const throw() {
	return _executeGrade;
}

void	Form::beSigned(const Bureaucrat &bureaucrat) throw(GradeTooLowException) {
	if (bureaucrat.getGrade() <= _signGrade)
		_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &os, const Form &form) {
	if (form.getSigned())
		os << "S";
	else
		os << "Uns";
	os << "igned form " << form.getName() << ": level to sign - "
		<< form.getSignGrade() << "; level to execute - " << form.getExecuteGrade();
	return os;
}
