#include <iostream>
#include "app/Application.h"

int main(int inArgCount, char* inArgs[])
{
	std::cout << "Hello, World!" << std::endl;

	int returnCode = 0;

	{
		lightfoot::Application app;
		returnCode = app.Run();
	}

	return returnCode;
}
