#ifndef EX03_INTERN_HPP
# define EX03_INTERN_HPP

#include "AForm.hpp"

class Intern {
public:
	Intern(void) throw();
	Intern(const Intern &other) throw();
	~Intern(void) throw();

	Intern	&operator=(const Intern &other) throw();

	AForm	*makeForm(const std::string &name, const std::string &target) const throw();
};

#endif
