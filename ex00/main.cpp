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

int	main() {
	bool	success = true;
	bool	(*tests[])(void) = {
		bureaucrat_default_constructor,
		bureaucrat_constructor,
		bureaucrat_copy_constructor,
		bureaucrat_copy_assignment,
		bureaucrat_inc,
		bureaucrat_dec,
		print_bureaucrat
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
		expected = "The grade is too low\n";
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
		expected = "The grade is too high\n";
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
		expected = "The grade is too low\nThe grade is too high\n";
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
