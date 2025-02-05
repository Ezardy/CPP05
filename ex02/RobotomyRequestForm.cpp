#include <iostream>
#include <cstdlib>

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
throw(AForm::GradeTooHighException, AForm::GradeTooLowException)
: AForm("Robotomy Request", 72, 45), _target("unnamed") {

}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
throw(AForm::GradeTooHighException, AForm::GradeTooLowException)
: AForm("Robotomy Request", 72, 45), _target(target) {

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
throw()
: AForm(other), _target(other._target) {

}

RobotomyRequestForm::~RobotomyRequestForm(void) throw() {

}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
throw() {
	if (this != &other) {
		_target = other._target;
		this->AForm::operator=(other);
	}
	return *this;
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
throw(AForm::GradeTooLowException, AForm::UnsignedFormExecution) {
	check(executor.getGrade());
	std::cout << "VVZZZSSS-VVZZZSSS-VVZZZSSS-WWWRRRRM\n";
	if (rand() % 2 > 0)
		std::cout << _target << " has been robotomized\n";
	else
		std::cout << "Robotomy was failed\n";
}

const std::string	&RobotomyRequestForm::getTarget(void) const throw() {
	return _target;
}
