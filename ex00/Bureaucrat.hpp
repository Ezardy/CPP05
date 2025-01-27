#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
#include <string>

class Bureaucrat {
public:
	class GradeTooHighException : std::exception {
	public:
		virtual const char	*what() const throw() {
			return "The grade is too high";
		}
	};

	class GradeTooLowException : std::exception {
	public:
		virtual const char	*what() const throw() {
			return "The grade is too low";
		}
	};

	Bureaucrat(void) throw();
	Bureaucrat(const std::string name, unsigned short grade);
	Bureaucrat(const Bureaucrat &other) throw();
	~Bureaucrat(void) throw();

	Bureaucrat	&operator=(const Bureaucrat &other) throw();

	const std::string	&getName(void) const throw();
	unsigned short		getGrade(void) const throw();

	void	inc(void) const throw(GradeTooHighException);
};

#endif
