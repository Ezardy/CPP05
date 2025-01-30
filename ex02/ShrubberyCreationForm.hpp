#ifndef EX02_SHRUBBERYCREATIONFORM_HPP
# define EX02_SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm(void) throw(AForm::GradeTooHighException, AForm::GradeTooLowException);
	ShrubberyCreationForm(const std::string &target) throw(AForm::GradeTooHighException, AForm::GradeTooLowException);
	ShrubberyCreationForm(const ShrubberyCreationForm &other) throw();
	~ShrubberyCreationForm(void) throw();

	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &other);

	void	execute(const Bureaucrat &executor) const throw(AForm::GradeTooLowException);
private:
	std::string	_target;
};
#endif
