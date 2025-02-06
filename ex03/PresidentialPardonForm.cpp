#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
throw(AForm::GradeTooHighException, AForm::GradeTooLowException)
: AForm("Presidential Pardon", 25, 5), _target("unnamed") {

}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
throw(AForm::GradeTooHighException, AForm::GradeTooLowException)
: AForm("Presidential Pardon", 25, 5), _target(target) {

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
throw()
: AForm(other), _target(other._target) {

}

PresidentialPardonForm::~PresidentialPardonForm(void) throw() {

}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
throw() {
	if (this != &other) {
		_target = other._target;
		this->AForm::operator=(other);
	}
	return *this;
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
throw(AForm::GradeTooLowException, AForm::UnsignedFormExecution) {
	check(executor.getGrade());
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
}

const std::string	&PresidentialPardonForm::getTarget(void) const throw() {
	return _target;
}

PresidentialPardonForm	*PresidentialPardonForm::clone(const std::string &target) const throw(std::bad_alloc) {
	return new PresidentialPardonForm(target);
}
