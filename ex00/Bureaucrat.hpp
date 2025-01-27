#ifndef EX00_BUREAUCRAT_HPP
# define EX00_BUREAUCRAT_HPP

# include <exception>
# include <string>

class Bureaucrat {
public:
	class GradeTooHighException : public std::exception {
	public:
		virtual const char	*what(void) const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char	*what(void) const throw();
	};

	Bureaucrat(void) throw();
	Bureaucrat(const std::string &name, unsigned short grade) throw(GradeTooHighException, GradeTooLowException);
	Bureaucrat(const Bureaucrat &other) throw();
	~Bureaucrat(void) throw();

	Bureaucrat	&operator=(const Bureaucrat &other) throw();

	const std::string	&getName(void) const throw();
	unsigned short		getGrade(void) const throw();

	void	inc(void) throw(GradeTooHighException);
	void	dec(void) throw(GradeTooLowException);
private:
	static const unsigned short	_minGrade;
	static const unsigned short	_maxGrade;

	const std::string	_name;
	unsigned short		_grade;
};

#endif
