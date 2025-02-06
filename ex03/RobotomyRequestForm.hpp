#ifndef EX03_ROBOTOMYREQUESTFORM_HPP
# define EX03_ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include "IClonable.hpp"

class RobotomyRequestForm : public AForm, public IClonable {
public:
	RobotomyRequestForm(void) throw(AForm::GradeTooHighException, AForm::GradeTooLowException);
	RobotomyRequestForm(const std::string &target) throw(AForm::GradeTooHighException, AForm::GradeTooLowException);
	RobotomyRequestForm(const RobotomyRequestForm &other) throw();
	~RobotomyRequestForm(void) throw();

	RobotomyRequestForm	&operator=(const RobotomyRequestForm &other) throw();

	const std::string	&getTarget(void) const throw();

	void				execute(const Bureaucrat &executor) const throw(AForm::GradeTooLowException, AForm::UnsignedFormExecution);
	RobotomyRequestForm	*clone(const std::string &target) const throw(std::bad_alloc);
private:
	std::string	_target;
};
#endif
