#ifndef EX03_SHRUBBERYCREATIONFORM_HPP
# define EX03_SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include "IClonable.hpp"

class ShrubberyCreationForm : public AForm, public IClonable {
public:
	class BadSoil : public std::exception {
	public:
		virtual const char	*what(void) const throw();
	};

	ShrubberyCreationForm(void) throw(AForm::GradeTooHighException, AForm::GradeTooLowException);
	ShrubberyCreationForm(const std::string &target) throw(AForm::GradeTooHighException, AForm::GradeTooLowException);
	ShrubberyCreationForm(const ShrubberyCreationForm &other) throw();
	~ShrubberyCreationForm(void) throw();

	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &other) throw();

	const std::string	&getTarget(void) const throw();

	void					execute(const Bureaucrat &executor) const throw(AForm::GradeTooLowException, AForm::UnsignedFormExecution, BadSoil);
	ShrubberyCreationForm	*clone(const std::string &target) const throw(std::bad_alloc);
private:
	std::string	_target;
};
#endif
