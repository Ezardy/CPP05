all: test

src=Bureaucrat AForm ShrubberyCreationForm RobotomyRequestForm PresidentialPardonForm main
obj=$(addsuffix .o, $(src))

test: $(obj)
	c++ -o $@ $(obj)

cflags=-Wall -Wextra -Werror -std=c++98 -pedantic
depflags = -MT $@ -MMD -MP -MF $*.d

%.o: %.cpp %.d Makefile
	c++ $(cflags) $(depflags) -o $@ -c $<

clean:
	rm -f $(obj) $(obj:.o=.d)

fclean: clean
	rm -f test

re: fclean test

debug: cflags+=-g
debug: test

$(obj:.o=.d):
-include $(obj:.o=.d)
