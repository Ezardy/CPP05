#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>

#include "../test.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static bool	bureaucrat_default_constructor(void);
static bool	bureaucrat_constructor(void);
static bool	bureaucrat_copy_constructor(void);
static bool	bureaucrat_copy_assignment(void);
static bool	bureaucrat_inc(void);
static bool	bureaucrat_dec(void);
static bool	print_bureaucrat(void);

static bool	ShrubberyCreationForm_default_constructor(void);
static bool	ShrubberyCreationForm_constructor(void);
static bool	ShrubberyCreationForm_copy_constructor(void);
static bool	form_beSigned(void);
static bool	ShrubberyCreationForm_copy_assignment(void);
static bool	print_form(void);
static bool	bureaucrat_signForm(void);

static bool	ShrubberyCreationForm_execute(void);
static bool	RobotomyRequestForm_default_constructor(void);
static bool	RobotomyRequestForm_constructor(void);
static bool	RobotomyRequestForm_copy_constructor(void);
static bool	RobotomyRequestForm_copy_assignment(void);
static bool	RobotomyRequestForm_execute(void);
static bool	PresidentialPardonForm_default_constructor(void);
static bool	PresidentialPardonForm_constructor(void);
static bool	PresidentialPardonForm_copy_constructor(void);
static bool	PresidentialPardonForm_copy_assignment(void);
static bool	PresidentialPardonForm_execute(void);
static bool	Bureaucrat_executeForm(void);

int	main() {
	bool	success = true;
	bool	(*tests[])(void) = {
		bureaucrat_default_constructor,
		bureaucrat_constructor,
		bureaucrat_copy_constructor,
		bureaucrat_copy_assignment,
		bureaucrat_inc,
		bureaucrat_dec,
		print_bureaucrat,
		ShrubberyCreationForm_default_constructor,
		ShrubberyCreationForm_constructor,
		ShrubberyCreationForm_copy_constructor,
		form_beSigned,
		ShrubberyCreationForm_copy_assignment,
		print_form,
		bureaucrat_signForm,
		ShrubberyCreationForm_execute,
		RobotomyRequestForm_default_constructor,
		RobotomyRequestForm_constructor,
		RobotomyRequestForm_copy_constructor,
		RobotomyRequestForm_copy_assignment,
		RobotomyRequestForm_execute,
		PresidentialPardonForm_default_constructor,
		PresidentialPardonForm_constructor,
		PresidentialPardonForm_copy_constructor,
		PresidentialPardonForm_copy_assignment,
		PresidentialPardonForm_execute,
		Bureaucrat_executeForm
	};
	size_t	tests_count = sizeof(tests) / sizeof(tests[0]);
	for (size_t i = 0; success && i < tests_count; i += 1) {
		success = tests[i]();
		std::cout << '\n';
	}
	if (success)
		std::cout << "OK\n";
	return success;
}

TEST_START(Bureaucrat_executeForm)
	AForm	*shrubber = NULL;
	AForm	*shrubberBadSoil = NULL;
	AForm	*robotomy = NULL;
	AForm	*pardon = NULL;
	TEST_LOGIC_START
		const Bureaucrat	doofy("Doofy", 150);
		const Bureaucrat	handy("Handy", 1);

		shrubber = new ShrubberyCreationForm("office");
		shrubberBadSoil = new ShrubberyCreationForm("/");
		robotomy = new RobotomyRequestForm("Bobby");
		pardon = new PresidentialPardonForm("Toriel");
		doofy.executeForm(*shrubber);
		doofy.executeForm(*robotomy);
		doofy.executeForm(*pardon);
		handy.signForm(*shrubber);
		handy.signForm(*shrubberBadSoil);
		handy.signForm(*robotomy);
		handy.signForm(*pardon);
		doofy.executeForm(*shrubber);
		doofy.executeForm(*robotomy);
		doofy.executeForm(*pardon);
		handy.executeForm(*shrubberBadSoil);
		handy.executeForm(*shrubber);
		handy.executeForm(*pardon);

		std::ostringstream	shrubberyStr;
		std::ifstream		file("office_shrubbery");

		TEST_ASSERT(file)
		shrubberyStr << file.rdbuf();
		TEST_ASSERT(shrubberyStr.str()
			== "                                  # #### ####\n"
			"                                ### \\/#|### |/####\n"
			"                               ##\\/#/ \\||/##/_/##/_#\n"
			"                             ###  \\/###|/ \\/ # ###\n"
			"                           ##_\\_#\\_\\## | #/###_/_####\n"
			"                          ## #### # \\ #| /  #### ##/##\n"
			"                           __#_--###`  |{,###---###-~\n"
			"                                     \\ }{\n"
			"                                      }}{\n"
			"                                      }}{\n"
			"                                 ejm  {{}\n"
			"                                , -=-~{ .-^- _\n"
			"                                      `}\n"
			"                                       {\n")
		cerrExpected = "An unsigned form can't be executed\n"
			"An unsigned form can't be executed\n"
			"An unsigned form can't be executed\n"
			"The grade is too low for the form\n"
			"The grade is too low for the form\n"
			"The grade is too low for the form\n"
			"Inappropriate soil for a shrubber\n";
		expected = "Handy signed Shrubbery Creation\n"
			"Handy signed Shrubbery Creation\n"
			"Handy signed Robotomy Request\n"
			"Handy signed Presidential Pardon\n"
			"Handy executed Shrubbery Creation\n"
			"Toriel has been pardoned by Zaphod Beeblebrox\n"
			"Handy executed Presidential Pardon\n"
			"VVZZZSSS-VVZZZSSS-VVZZZSSS-WWWRRRRM\n";

		std::streambuf * const	ob = std::cout.rdbuf();
		std::ostringstream		strStr;

		std::cout.rdbuf(strStr.rdbuf());
		handy.executeForm(*robotomy);
		if (strStr.str().rfind("robotomized") == strStr.str().npos)
			expected += "Robotomy was failed\n";
		else
			expected += "Bobby has been robotomized\nHandy executed Robotomy Request\n";
		std::cout.rdbuf(ob);
		std::cout << strStr.str();
	TEST_LOGIC_END
	TEST_EMERGENCY_START
		delete pardon;
		delete robotomy;
		delete shrubberBadSoil;
		delete shrubber;
	TEST_EMERGENCY_END
TEST_END

TEST_START(PresidentialPardonForm_execute)
	AForm	*form = NULL;
	TEST_LOGIC_START
		const Bureaucrat	kriss("Kriss", 25);
		const Bureaucrat	asgore("Asgore", 5);

		form = new PresidentialPardonForm("Toriel");
		try {
			form->execute(asgore);
		} catch (const AForm::UnsignedFormExecution &e) {
			std::cout << e.what() << '\n';
		}
		kriss.signForm(*form);
		try {
			form->execute(kriss);
		} catch (const AForm::GradeTooLowException &e) {
			std::cout << e.what() << '\n';
		}
		form->execute(asgore);

		expected = "An unsigned form can't be executed\n"
			"Kriss signed Presidential Pardon\n"
			"The grade is too low for the form\n"
			"Toriel has been pardoned by Zaphod Beeblebrox\n";
	TEST_LOGIC_END
	TEST_EMERGENCY_START
		delete form;
	TEST_EMERGENCY_END
TEST_END

TEST_START(PresidentialPardonForm_copy_assignment)
	TEST_LOGIC_START
		const Bureaucrat			kriss("Kriss", 25);
		PresidentialPardonForm		form1("Toriel");
		PresidentialPardonForm		form2("Charlie");

		form1.beSigned(kriss);
		TEST_ASSERT(form1.getSigned() == true)
		form2 = form1;
		TEST_ASSERT(form2.getName() == "Presidential Pardon")
		TEST_ASSERT(form2.getTarget() == "Toriel")
		TEST_ASSERT(form2.getSigned() == true)
		TEST_ASSERT(form2.getSignGrade() == 25)
		TEST_ASSERT(form2.getExecuteGrade() == 5)
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(PresidentialPardonForm_copy_constructor)
	TEST_LOGIC_START
		const PresidentialPardonForm	form1("Toriel");
		PresidentialPardonForm			form2 = form1;

		TEST_ASSERT(form2.getName() == form1.getName())
		TEST_ASSERT(form2.getTarget() == "Toriel")
		TEST_ASSERT(form2.getSigned() == false)
		TEST_ASSERT(form2.getSignGrade() == form1.getSignGrade())
		TEST_ASSERT(form2.getExecuteGrade() == form1.getExecuteGrade())
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(PresidentialPardonForm_constructor)
	TEST_LOGIC_START
		const PresidentialPardonForm	form("Toriel");

		TEST_ASSERT(form.getName() == "Presidential Pardon")
		TEST_ASSERT(form.getTarget() == "Toriel")
		TEST_ASSERT(form.getSigned() == false)
		TEST_ASSERT(form.getSignGrade() == 25)
		TEST_ASSERT(form.getExecuteGrade() == 5)
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(PresidentialPardonForm_default_constructor)
	TEST_LOGIC_START
		const PresidentialPardonForm	form;

		TEST_ASSERT(form.getName() == "Presidential Pardon")
		TEST_ASSERT(form.getTarget() == "unnamed")
		TEST_ASSERT(form.getSigned() == false)
		TEST_ASSERT(form.getSignGrade() == 25)
		TEST_ASSERT(form.getExecuteGrade() == 5)
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(RobotomyRequestForm_execute)
	AForm	*form1 = NULL;
	TEST_LOGIC_START
		const Bureaucrat	matt("Matt", 72);
		const Bureaucrat	sue("Sue", 45);

		form1 = new RobotomyRequestForm("Bobby");
		try {
			form1->execute(sue);
		} catch (const AForm::UnsignedFormExecution &e) {
			std::cout << e.what() << '\n';
		}
		matt.signForm(*form1);
		try {
			form1->execute(matt);
		} catch (const AForm::GradeTooLowException &e) {
			std::cout << e.what() << '\n';
		}
		expected = "An unsigned form can't be executed\n"
			"Matt signed Robotomy Request\n"
			"The grade is too low for the form\n";

		const float		tolerance = 5.0f;
		const int		eventCount = 100;
		int				successCount = 0;
		std::streambuf	*oldBuff = std::cout.rdbuf();

		for (int i = 0; i < eventCount; i += 1) {
			std::ostringstream	tmpStream;
			std::cout.rdbuf(tmpStream.rdbuf());
			form1->execute(sue);
			std::string	executionOutput = tmpStream.str();
			if (executionOutput.rfind("robotomized") != executionOutput.npos) {
				expected += "VVZZZSSS-VVZZZSSS-VVZZZSSS-WWWRRRRM\nBobby has been robotomized\n";
				successCount += 1;
			} else
				expected += "VVZZZSSS-VVZZZSSS-VVZZZSSS-WWWRRRRM\nRobotomy was failed\n";
			std::cout.rdbuf(oldBuff);
			std::cout << executionOutput;
		}
		TEST_ASSERT(std::abs((float)successCount / eventCount * 100 - 50) <= tolerance)
	TEST_LOGIC_END
	TEST_EMERGENCY_START
		delete form1;
	TEST_EMERGENCY_END
TEST_END

TEST_START(RobotomyRequestForm_copy_assignment)
	TEST_LOGIC_START
		const Bureaucrat		matt("Matt", 72);
		RobotomyRequestForm		form1("Bobby");
		RobotomyRequestForm		form2("Charlie");

		form1.beSigned(matt);
		TEST_ASSERT(form1.getSigned() == true)
		form2 = form1;
		TEST_ASSERT(form2.getName() == "Robotomy Request")
		TEST_ASSERT(form2.getTarget() == "Bobby")
		TEST_ASSERT(form2.getSigned() == true)
		TEST_ASSERT(form2.getSignGrade() == 72)
		TEST_ASSERT(form2.getExecuteGrade() == 45)
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(RobotomyRequestForm_copy_constructor)
	TEST_LOGIC_START
		const RobotomyRequestForm	form1("Bobby");
		RobotomyRequestForm			form2 = form1;

		TEST_ASSERT(form2.getName() == form1.getName())
		TEST_ASSERT(form2.getTarget() == "Bobby")
		TEST_ASSERT(form2.getSigned() == false)
		TEST_ASSERT(form2.getSignGrade() == form1.getSignGrade())
		TEST_ASSERT(form2.getExecuteGrade() == form1.getExecuteGrade())
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(RobotomyRequestForm_constructor)
	TEST_LOGIC_START
		const RobotomyRequestForm	form("Bobby");

		TEST_ASSERT(form.getName() == "Robotomy Request")
		TEST_ASSERT(form.getTarget() == "Bobby")
		TEST_ASSERT(form.getSigned() == false)
		TEST_ASSERT(form.getSignGrade() == 72)
		TEST_ASSERT(form.getExecuteGrade() == 45)
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(RobotomyRequestForm_default_constructor)
	TEST_LOGIC_START
		const RobotomyRequestForm	form;

		TEST_ASSERT(form.getName() == "Robotomy Request")
		TEST_ASSERT(form.getTarget() == "unnamed")
		TEST_ASSERT(form.getSigned() == false)
		TEST_ASSERT(form.getSignGrade() == 72)
		TEST_ASSERT(form.getExecuteGrade() == 45)
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(ShrubberyCreationForm_execute)
	AForm	*form = NULL;
	TEST_LOGIC_START
		const Bureaucrat		matt("Matt", 145);
		const Bureaucrat		sue("Sue", 137);
		ShrubberyCreationForm	form1("/");

		form = new ShrubberyCreationForm("home");
		try {
			form->execute(sue);
		} catch (const AForm::UnsignedFormExecution &e) {
			std::cout << e.what() << '\n';
		}
		matt.signForm(*form);
		try {
			form->execute(matt);
		} catch (const AForm::GradeTooLowException &e) {
			std::cout << e.what() << '\n';
		}
		form->execute(sue);
		std::ifstream		file("home_shrubbery");
		std::ostringstream	shrubberyStr;

		TEST_ASSERT(file)
		shrubberyStr << file.rdbuf();
		TEST_ASSERT(shrubberyStr.str()
			== "                                  # #### ####\n"
			"                                ### \\/#|### |/####\n"
			"                               ##\\/#/ \\||/##/_/##/_#\n"
			"                             ###  \\/###|/ \\/ # ###\n"
			"                           ##_\\_#\\_\\## | #/###_/_####\n"
			"                          ## #### # \\ #| /  #### ##/##\n"
			"                           __#_--###`  |{,###---###-~\n"
			"                                     \\ }{\n"
			"                                      }}{\n"
			"                                      }}{\n"
			"                                 ejm  {{}\n"
			"                                , -=-~{ .-^- _\n"
			"                                      `}\n"
			"                                       {\n")
		form1.beSigned(matt);
		try {
			form1.execute(sue);
		} catch (const ShrubberyCreationForm::BadSoil &e) {
			std::cout << e.what() << '\n';
		}

		expected = "An unsigned form can't be executed\n"
			"Matt signed Shrubbery Creation\n"
			"The grade is too low for the form\n"
			"Inappropriate soil for a shrubber\n";
	TEST_LOGIC_END
	TEST_EMERGENCY_START
		delete form;
	TEST_EMERGENCY_END
TEST_END

TEST_START(bureaucrat_signForm)
	TEST_LOGIC_START
		Bureaucrat				kriss("Kriss", 26);
		PresidentialPardonForm	form("Toriel");
		kriss.signForm(form);
		TEST_ASSERT(form.getSigned() == false)
		kriss.inc();
		kriss.signForm(form);
		TEST_ASSERT(form.getSigned() == true)

		cerrExpected = "Kriss couldn't sign Presidential Pardon because 'The grade is too low for the form'\n";
		expected = "Kriss signed Presidential Pardon\n";
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(print_form)
	TEST_LOGIC_START
		const ShrubberyCreationForm	shr("home");
		RobotomyRequestForm			rob("Bobby");
		PresidentialPardonForm		pre("Toby");
		const Bureaucrat			matt("Matt", 1);

		rob.beSigned(matt);
		pre.beSigned(matt);
		std::cout << shr << '\n' << rob << '\n' << pre << '\n';

		expected = "Unsigned form Shrubbery Creation: level to sign - 145; level to execute - 137\n"
			"Signed form Robotomy Request: level to sign - 72; level to execute - 45\n"
			"Signed form Presidential Pardon: level to sign - 25; level to execute - 5\n";
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(ShrubberyCreationForm_copy_assignment)
	TEST_LOGIC_START
		const Bureaucrat		matt("Matt", 145);
		ShrubberyCreationForm	form1("home");
		ShrubberyCreationForm	form2("office");

		form1.beSigned(matt);
		TEST_ASSERT(form1.getSigned() == true)
		form2 = form1;
		TEST_ASSERT(form2.getName() == "Shrubbery Creation")
		TEST_ASSERT(form2.getTarget() == "home")
		TEST_ASSERT(form2.getSigned() == true)
		TEST_ASSERT(form2.getSignGrade() == 145)
		TEST_ASSERT(form2.getExecuteGrade() == 137)
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(form_beSigned)
	TEST_LOGIC_START
		const std::string		mattName = "Matt";
		const std::string		sueName = "Sue";
		ShrubberyCreationForm	form;
		const Bureaucrat		matt(mattName, 145);
		const Bureaucrat		sue(sueName, 146);

		try {
			form.beSigned(sue);
		} catch (const std::exception &e) {
			std::cout << e.what() << '\n';
		}
		TEST_ASSERT(form.getSigned() == false)
		form.beSigned(matt);
		TEST_ASSERT(form.getSigned() == true)
		ShrubberyCreationForm	copy = form;
		const Bureaucrat	dooDeeDoo("DooDeeDoo", 144);
		TEST_ASSERT(copy.getSigned() == false)
		copy.beSigned(dooDeeDoo);
		TEST_ASSERT(copy.getSigned() == true)

		expected = "The grade is too low for the form\n";
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(ShrubberyCreationForm_copy_constructor)
	TEST_LOGIC_START
		const ShrubberyCreationForm	form1("home");
		ShrubberyCreationForm		form2 = form1;

		TEST_ASSERT(form2.getName() == form1.getName())
		TEST_ASSERT(form2.getTarget() == "home")
		TEST_ASSERT(form2.getSigned() == false)
		TEST_ASSERT(form2.getSignGrade() == form1.getSignGrade())
		TEST_ASSERT(form2.getExecuteGrade() == form1.getExecuteGrade())
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(ShrubberyCreationForm_constructor)
	TEST_LOGIC_START
		const ShrubberyCreationForm	form("home");

		TEST_ASSERT(form.getName() == "Shrubbery Creation")
		TEST_ASSERT(form.getTarget() == "home")
		TEST_ASSERT(form.getSigned() == false)
		TEST_ASSERT(form.getSignGrade() == 145)
		TEST_ASSERT(form.getExecuteGrade() == 137)
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(ShrubberyCreationForm_default_constructor)
	TEST_LOGIC_START
		const ShrubberyCreationForm	form;

		TEST_ASSERT(form.getName() == "Shrubbery Creation")
		TEST_ASSERT(form.getTarget() == "unnamed")
		TEST_ASSERT(form.getSigned() == false)
		TEST_ASSERT(form.getSignGrade() == 145)
		TEST_ASSERT(form.getExecuteGrade() == 137)
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(print_bureaucrat)
	TEST_LOGIC_START
		Bureaucrat	matt("Matt", 52);
		Bureaucrat	sue("Sue", 43);
		std::cout << matt << '\n' << sue << '\n';

		expected = "Matt, bureaucrat grade 52\nSue, bureaucrat grade 43\n";
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(bureaucrat_dec)
	TEST_LOGIC_START
		Bureaucrat	matt("Matt", 149);

		TEST_ASSERT(matt.getGrade() == 149)
		matt.dec();
		TEST_ASSERT(matt.getGrade() == 150)
		try {
			matt.dec();
		} catch (const std::exception &e) {
			std::cout << e.what() << '\n';
		}
		expected = "The grade is too low for the bureaucrat\n";
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(bureaucrat_inc)
	TEST_LOGIC_START
		Bureaucrat	matt("Matt", 2);

		TEST_ASSERT(matt.getGrade() == 2)
		matt.inc();
		TEST_ASSERT(matt.getGrade() == 1)
		try {
			matt.inc();
		} catch (const std::exception &e) {
			std::cout << e.what() << '\n';
		}
		expected = "The grade is too high for the bureaucrat\n";
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(bureaucrat_copy_assignment)
	TEST_LOGIC_START
		const std::string	mattName = "Matt";
		const std::string	sueName = "Sue";

		Bureaucrat	matt(mattName, 1);
		Bureaucrat	sue(sueName, 150);
		TEST_ASSERT(matt.getName() == mattName && matt.getGrade() == 1)
		TEST_ASSERT(sue.getName() == sueName && sue.getGrade() == 150)
		sue = matt;
		TEST_ASSERT(sue.getName() == sueName && sue.getGrade() == 1)
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(bureaucrat_copy_constructor)
	TEST_LOGIC_START
		Bureaucrat	matt("Matt", 150);
		Bureaucrat	matt1(matt);
		TEST_ASSERT(matt1.getName() == "Matt" && matt1.getGrade() == 150)
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(bureaucrat_constructor)
	TEST_LOGIC_START
		const std::string	mattName = "Matt";
		const std::string	sueName = "Sue";
		Bureaucrat	matt(mattName, 45);
		TEST_ASSERT(matt.getGrade() == 45)
		TEST_ASSERT(matt.getName() == mattName)
		try {
			Bureaucrat	sue(sueName, 151);
		} catch (const std::exception &e) {
			std::cout << e.what() << '\n';
		}
		try {
			Bureaucrat	sue(sueName, 0);
		} catch (const std::exception &e) {
			std::cout << e.what() << '\n';
		}
		expected = "The grade is too low for the bureaucrat\nThe grade is too high for the bureaucrat\n";
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(bureaucrat_default_constructor)
	TEST_LOGIC_START
		Bureaucrat	b;
		TEST_ASSERT(b.getGrade() == 150)
		TEST_ASSERT(b.getName() == "Unnamed")
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END
