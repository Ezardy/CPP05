#ifndef EX02_PRESIDENTIALPARDONFORM_HPP
# define EX02_PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm(void) throw(AForm::GradeTooHighException, AForm::GradeTooLowException);
	PresidentialPardonForm(const std::string &target) throw(AForm::GradeTooHighException, AForm::GradeTooLowException);
	PresidentialPardonForm(const PresidentialPardonForm &other) throw();
	~PresidentialPardonForm(void) throw();

	PresidentialPardonForm	&operator=(const PresidentialPardonForm &other) throw();

	const std::string	&getTarget(void) const throw();

	void	execute(const Bureaucrat &executor) const throw(AForm::GradeTooLowException, AForm::UnsignedFormExecution);
private:
	std::string	_target;
};
#endif
