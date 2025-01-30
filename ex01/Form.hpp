#ifndef EX01_FORM_HPP
# define EX01_FORM_HPP

# include <exception>
# include <ostream>
# include <string>

class Bureaucrat;

class Form {
public:
	class GradeTooHighException : public std::exception {
	public:
		virtual const char	*what(void) const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char	*what(void) const throw();
	};

	Form(void) throw();
	Form(const std::string &name, unsigned short signGrade, unsigned short executeGrade) throw(GradeTooHighException, GradeTooLowException);
	Form(const Form &form) throw();
	~Form(void) throw();

	Form	&operator=(const Form &other) throw();

	const std::string	&getName(void) const throw();
	bool				getSigned(void) const throw();
	unsigned short		getSignGrade(void) const throw();
	unsigned short		getExecuteGrade(void) const throw();

	void	beSigned(const Bureaucrat &bureaucrat) throw(GradeTooLowException);
private:
	const std::string		_name;
	bool					_signed;
	const unsigned short	_signGrade;
	const unsigned short	_executeGrade;
};

std::ostream	&operator<<(std::ostream &os, const Form &form);
#endif
