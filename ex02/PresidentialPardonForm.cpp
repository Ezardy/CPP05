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
: AForm("Presidential Pardon", 25, 5), _target(other._target) {

}

PresidentialPardonForm::~PresidentialPardonForm(void) throw() {

}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
throw() {
	if (this != &other)
		_target = other._target;
	return *this;
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
throw(AForm::GradeTooLowException) {
	check(executor.getGrade());
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
}
