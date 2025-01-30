#include <fstream>

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
throw(AForm::GradeTooHighException, AForm::GradeTooLowException)
: AForm("Shrubbery Creation", 145, 137), _target("unnamed") {

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
throw(AForm::GradeTooHighException, AForm::GradeTooLowException)
: AForm("Shrubbery Creation", 145, 137), _target(target) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
throw()
: AForm("Shrubbery Creation", 145, 137), _target(other._target) {

}

ShrubberyCreationForm::~ShrubberyCreationForm(void) throw() {

}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other)
		_target = other._target;
	return *this;
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const throw(AForm::GradeTooLowException) {
	check(executor.getGrade());

}
