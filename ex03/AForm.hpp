#ifndef EX03_AFORM_HPP
# define EX03_AFORM_HPP

# include <exception>
# include <ostream>
# include <string>

class Bureaucrat;

class AForm {
public:
	class GradeTooHighException : public std::exception {
	public:
		virtual const char	*what(void) const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char	*what(void) const throw();
	};

	class UnsignedFormExecution : public std::exception {
	public:
		virtual const char	*what(void) const throw();
	};

	virtual ~AForm(void) throw();

	AForm	&operator=(const AForm &other) throw();

	virtual void	execute(const Bureaucrat &executor) const = 0;

	const std::string	&getName(void) const throw();
	bool				getSigned(void) const throw();
	unsigned short		getSignGrade(void) const throw();
	unsigned short		getExecuteGrade(void) const throw();

	void	beSigned(const Bureaucrat &bureaucrat) throw(GradeTooLowException);
protected:
	AForm(void) throw();
	AForm(const std::string &name, unsigned short signGrade, unsigned short executeGrade) throw(GradeTooHighException, GradeTooLowException);
	AForm(const AForm &form) throw();

	void	check(unsigned short grade) const throw(GradeTooLowException, UnsignedFormExecution);
private:
	const std::string		_name;
	bool					_signed;
	const unsigned short	_signGrade;
	const unsigned short	_executeGrade;
};

std::ostream	&operator<<(std::ostream &os, const AForm &form);
#endif
