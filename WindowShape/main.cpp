#include "GameManager.h"

std::string GetBasePath(const std::string&);

int main(int argc, char* argv[])
{
	auto basePath = GetBasePath(argv[0]);
	std::cout << basePath.c_str();
	auto g = GameManager("D:/Repos/Asteroids/");
	return EXIT_SUCCESS;
}

std::string GetBasePath(const std::string& exePath)
{
	size_t f = exePath.find_first_of("Asteroids\\/");
	return (exePath.substr(f)).c_str();
}