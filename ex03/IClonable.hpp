#ifndef EX03_ICLONABLE_HPP
# define EX03_ICLONABLE_HPP

# include <string>

class AForm;

class IClonable {
public:
	virtual AForm	*clone(const std::string &target) const = 0;

	virtual ~IClonable(void) {};
};
#endif
