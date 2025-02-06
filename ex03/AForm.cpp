#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char	*AForm::GradeTooHighException::what(void) const throw() {
	return "The grade is too high for the form";
}

const char	*AForm::GradeTooLowException::what(void) const throw() {
	return "The grade is too low for the form";
}

const char	*AForm::UnsignedFormExecution::what(void) const throw() {
	return "An unsigned form can't be executed";
}

AForm::AForm(void)
throw()
: _name("Unnamed"), _signed(false), _signGrade(Bureaucrat::minGrade),
	_executeGrade(Bureaucrat::minGrade) {

}

AForm::AForm(const std::string &name, unsigned short signGrade, unsigned short executeGrade)
throw(GradeTooHighException, GradeTooLowException)
: _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade) {
	if (signGrade > Bureaucrat::minGrade || executeGrade > Bureaucrat::minGrade)
		throw GradeTooLowException();
	else if (signGrade < Bureaucrat::maxGrade || executeGrade < Bureaucrat::maxGrade)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &form)
throw()
: _name(form._name), _signed(false), _signGrade(form._signGrade), _executeGrade(form._executeGrade) {

}

AForm::~AForm(void) throw() {

}

AForm	&AForm::operator=(const AForm &other) throw() {
	if (this != &other)
		_signed = other._signed;
	return *this;
}

const std::string	&AForm::getName(void) const throw() {
	return _name;
}

bool	AForm::getSigned(void) const throw() {
	return _signed;
}

unsigned short	AForm::getSignGrade(void) const throw() {
	return _signGrade;
}

unsigned short	AForm::getExecuteGrade(void) const throw() {
	return _executeGrade;
}

void	AForm::beSigned(const Bureaucrat &bureaucrat) throw(GradeTooLowException) {
	if (bureaucrat.getGrade() <= _signGrade)
		_signed = true;
	else
		throw GradeTooLowException();
}

void	AForm::check(unsigned short grade) const throw(GradeTooLowException, UnsignedFormExecution) {
	if (!_signed)
		throw UnsignedFormExecution();
	else if (grade > _executeGrade)
		throw GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &os, const AForm &form) {
	if (form.getSigned())
		os << "S";
	else
		os << "Uns";
	os << "igned form " << form.getName() << ": level to sign - "
		<< form.getSignGrade() << "; level to execute - " << form.getExecuteGrade();
	return os;
}
