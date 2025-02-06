#include <iostream>

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void) throw() {

}

Intern::Intern(const Intern &other) throw() {
	(void)other;
}

Intern::~Intern(void) throw() {

}

Intern	&Intern::operator=(const Intern &other) throw() {
	(void)other;
	return *this;
}

AForm	*Intern::makeForm(const std::string &name, const std::string &target) const throw() {
	static const ShrubberyCreationForm	shrubber;
	static const RobotomyRequestForm	robotomy;
	static const PresidentialPardonForm	pardon;
	static const IClonable * const		clonables[] = {&shrubber, &robotomy, &pardon};
	static const std::string			types[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm	*result = NULL;

	int i;
	for (i = 0; i < 3 && name != types[i]; i += 1);
	if (i < 3) {
		try {
			result = clonables[i]->clone(target);
			std::cout << "Intern creates " << *result << '\n';
		} catch (const std::exception &e) {
			std::cerr << "Failed to make " << name << " form: " << e.what() << '\n';
		}
	} else
		std::cerr << "There is no " << name << " form\n";
	return result;
}
