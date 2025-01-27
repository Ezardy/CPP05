#include <iostream>

#include "../test.hpp"
#include "Bureaucrat.hpp"

static bool	bureaucrat_default_constructor(void);
static bool	bureaucrat_constructor(void);

int	main() {
	bool	success = true;
	bool	(*tests[])(void) = {
		bureaucrat_default_constructor,
		bureaucrat_constructor
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
