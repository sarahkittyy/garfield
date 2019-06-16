#include <cxxopts/cxxopts.hpp>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	cxxopts::Options program("garfield", "A customizable, easy-to-use garfield emulator.");
	// clang-format off
	program.add_options()
	("h,help", "Display this help message")
	("t,tuesday", "Tuesday mode")
	("j,jon", "Jon mode")
	;
	// clang-format on
	// Parse cli args
	cxxopts::ParseResult result = program.parse(argc, argv);
	// Print help if necessary.
	if (result.count("help") != 0)
	{
		std::cout << program.help();
		return 0;
	}

	std::string day_of_the_week = "Monday";
	//Check if it's tuesday mode.
	if (result.count("tuesday") != 0)
	{
		day_of_the_week = "Tuesday";
	}

	//Check if it's jon mode.
	std::string jon_append = "";
	if (result.count("jon") != 0)
	{
		jon_append = ", Jon";
	}

	//Output the result.
	std::cout << "I hate " << day_of_the_week << "s" << jon_append << ".\n";

	return 0;
}