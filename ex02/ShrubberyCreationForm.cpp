#include <fstream>

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

const char	*ShrubberyCreationForm::BadSoil::what(void) const throw() {
	return "Inappropriate soil for a shrubber";
}

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
: AForm(other), _target(other._target) {

}

ShrubberyCreationForm::~ShrubberyCreationForm(void) throw() {

}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
throw() {
	if (this != &other) {
		_target = other._target;
		this->AForm::operator=(other);
	}
	return *this;
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
throw(AForm::GradeTooLowException, AForm::UnsignedFormExecution, BadSoil) {
	check(executor.getGrade());
	std::ofstream	file((_target + "_shrubbery").c_str());
	if (file) {
		file <<
			"                                  # #### ####\n"
			"                                ### \\/#|### |/####\n"
			"                               ##\\/#/ \\||/##/_/##/_#\n"
			"                             ###  \\/###|/ \\/ # ###\n"
			"                           ##_\\_#\\_\\## | #/###_/_####\n"
			"                          ## #### # \\ #| /  #### ##/##\n"
			"                           __#_--###`  |{,###---###-~\n"
			"                                     \\ }{\n"
			"                                      }}{\n"
			"                                      }}{\n"
			"                                 ejm  {{}\n"
			"                                , -=-~{ .-^- _\n"
			"                                      `}\n"
			"                                       {\n";
	} else
		throw BadSoil();
}

const std::string	&ShrubberyCreationForm::getTarget(void) const throw() {
	return _target;
}
