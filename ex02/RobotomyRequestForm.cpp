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
: AForm("Robotomy Request", 72, 45), _target(other._target) {

}

RobotomyRequestForm::~RobotomyRequestForm(void) throw() {

}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
throw() {
	if (this != &other)
		_target = other._target;
	return *this;
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
throw(AForm::GradeTooLowException) {
	check(executor.getGrade());
	std::cout << "VVZZZSSS-VVZZZSSS-VVZZZSSS-WWWRRRRM\n";
	if (rand() % 100 > 49)
		std::cout << _target << " has been robotomized\n";
	else
		std::cout << "Robotomy was failed\n";
}
