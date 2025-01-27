#ifndef TEST_HPP
# define TEST_HPP

# include <iostream>
# include <sstream>
# include <string>

# define TEST_START(func_name) static bool func_name() {\
		bool				success = true;\
		const std::string	_func_name = #func_name;\
		std::streambuf		*old = std::cout.rdbuf();\
		std::ostringstream	oss;\
		std::string			expected;\
		std::string			assertion;\
		std::cout << "[START " << _func_name << "]\n";\
		std::cout.rdbuf(oss.rdbuf());
# define TEST_LOGIC_START try {
# define TEST_LOGIC_END std::cout.rdbuf(old);\
			std::cout << oss.str();\
			if (!(success = success && expected == oss.str()))\
				std::cout << "EXPECTED:\n" << expected;\
		}
# define TEST_EMERGENCY_START catch (const std::exception &e) {\
			std::cout.rdbuf(old);\
			std::cerr << e.what() << '\n';\
			success = false;
# define TEST_EMERGENCY_END }
# define TEST_END\
		if (!success)\
			std::cout << '(' << _func_name << " failed)\n";\
		return success;\
	}

# define TEST_STRINGIFY(X) #X
# define TEST_EXPAND_AND_STRINGIFY(X) TEST_STRINGIFY(X)
# define TEST_ASSERT(cond) if (!(cond)) throw std::logic_error(#cond ":" TEST_EXPAND_AND_STRINGIFY(__LINE__));

#endif
