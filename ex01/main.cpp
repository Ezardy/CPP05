#include <iostream>

#include "../test.hpp"
#include "Bureaucrat.hpp"

static bool	bureaucrat_default_constructor(void);
static bool	bureaucrat_constructor(void);
static bool	bureaucrat_copy_constructor(void);
static bool	bureaucrat_copy_assignment(void);
static bool	bureaucrat_inc(void);
static bool	bureaucrat_dec(void);
static bool	print_bureaucrat(void);

static bool	form_default_constructor(void);
static bool	form_constructor(void);
static bool	form_copy_constructor(void);
static bool	form_beSigned(void);
static bool	form_copy_assignment(void);
static bool	print_form(void);
static bool	bureaucrat_signForm(void);

int	main() {
	bool	success = true;
	bool	(*tests[])(void) = {
		bureaucrat_default_constructor,
		form_constructor,
		bureaucrat_constructor,
		bureaucrat_copy_constructor,
		bureaucrat_copy_assignment,
		bureaucrat_inc,
		bureaucrat_dec,
		print_bureaucrat,
		form_default_constructor,
		form_copy_constructor,
		form_beSigned,
		form_copy_assignment,
		print_form,
		bureaucrat_signForm
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

TEST_START(bureaucrat_signForm)
	TEST_LOGIC_START
		Bureaucrat	matt("Matt", 4);
		Form		form("Form", 3, 4);
		matt.signForm(form);
		TEST_ASSERT(form.getSigned() == false)
		matt.inc();
		matt.signForm(form);
		TEST_ASSERT(form.getSigned() == true)

		expected = "Matt couldn't sign Form because 'The grade is too low for a form'\n"
			"Matt signed Form\n";
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(print_form)
	TEST_LOGIC_START
		Form				s("SignedForm", 32, 140);
		const Form			u("UnsignedForm", 39, 40);
		const Bureaucrat	matt("Matt", 1);

		s.beSigned(matt);
		std::cout << s << '\n' << u << '\n';

		expected = "Signed form SignedForm: level to sign - 32; level to execute - 140\n"
			"Unsigned form UnsignedForm: level to sign - 39; level to execute - 40\n";
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(form_copy_assignment)
	TEST_LOGIC_START
		const std::string	form1Name = "Form1";
		const std::string	form2Name = "Form2";
		Form				form1(form1Name, 20, 40);
		Form				form2(form2Name, 40, 60);
		const Bureaucrat	matt("Matt", 1);

		form1.beSigned(matt);
		TEST_ASSERT(form1.getSigned() == true)
		TEST_ASSERT(form2.getSigned() == false)
		form2 = form1;
		TEST_ASSERT(form2.getName() == form2Name)
		TEST_ASSERT(form2.getSigned() == form1.getSigned())
		TEST_ASSERT(form2.getSignGrade() == 40)
		TEST_ASSERT(form2.getExecuteGrade() == 60)
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(form_beSigned)
	TEST_LOGIC_START
		const std::string	formName = "Form";
		const std::string	mattName = "Matt";
		const std::string	sueName = "Sue";
		Form				form(formName, 23, 42);
		const Bureaucrat	matt(mattName, 23);
		const Bureaucrat	sue(sueName, 24);

		try {
			form.beSigned(sue);
		} catch (const std::exception &e) {
			std::cout << e.what() << '\n';
		}
		TEST_ASSERT(form.getSigned() == false)
		form.beSigned(matt);
		TEST_ASSERT(form.getSigned() == true)
		Form	copy = form;
		const Bureaucrat	dooDeeDoo("DooDeeDoo", 22);
		TEST_ASSERT(copy.getSigned() == false)
		copy.beSigned(dooDeeDoo);
		TEST_ASSERT(copy.getSigned() == true)

		expected = "The grade is too low for a form\n";
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(form_copy_constructor)
	TEST_LOGIC_START
		Form	form1("Form1", 43, 23);
		Form	form2 = form1;

		TEST_ASSERT(form2.getName() == form1.getName())
		TEST_ASSERT(form2.getSigned() == false)
		TEST_ASSERT(form2.getSignGrade() == form1.getSignGrade())
		TEST_ASSERT(form2.getExecuteGrade() == form1.getExecuteGrade())
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(form_constructor)
	TEST_LOGIC_START
		const std::string	formName = "Form";
		const Form			form(formName, 20, 40);

		TEST_ASSERT(form.getName() == formName)
		TEST_ASSERT(form.getSigned() == false)
		TEST_ASSERT(form.getSignGrade() == 20)
		TEST_ASSERT(form.getExecuteGrade() == 40)
		try {
			const Form	f(formName, 0, 40);
		} catch (const std::exception &e) {
			std::cout << e.what() << '\n';
		}
		try {
			const Form	f(formName, 151, 40);
		} catch (const std::exception &e) {
			std::cout << e.what() << '\n';
		}
		try {
			const Form	f(formName, 1, 0);
		} catch (const std::exception &e) {
			std::cout << e.what() << '\n';
		}
		try {
			const Form	f(formName, 150, 151);
		} catch (const std::exception &e) {
			std::cout << e.what() << '\n';
		}
		try {
			const Form	f(formName, 0, 0);
		} catch (const std::exception &e) {
			std::cout << e.what() << '\n';
		}
		try {
			const Form	f(formName, 151, 151);
		} catch (const std::exception &e) {
			std::cout << e.what() << '\n';
		}
		try {
			const Form	f(formName, 0, 151);
		} catch (const std::exception &e) {
			std::cout << e.what() << '\n';
		}
		try {
			const Form	f(formName, 151, 0);
		} catch (const std::exception &e) {
			std::cout << e.what() << '\n';
		}

		expected = "The grade is too high for a form\n"
			"The grade is too low for a form\n"
			"The grade is too high for a form\n"
			"The grade is too low for a form\n"
			"The grade is too high for a form\n"
			"The grade is too low for a form\n"
			"The grade is too low for a form\n"
			"The grade is too low for a form\n";
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(form_default_constructor)
	TEST_LOGIC_START
		Form	form;

		TEST_ASSERT(form.getName() == "Unnamed")
		TEST_ASSERT(form.getSigned() == false)
		TEST_ASSERT(form.getSignGrade() == 150)
		TEST_ASSERT(form.getExecuteGrade() == 150)
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
		expected = "The grade is too low for a bureaucrat\n";
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
		expected = "The grade is too high for a bureaucrat\n";
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
		expected = "The grade is too low for a bureaucrat\nThe grade is too high for a bureaucrat\n";
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
